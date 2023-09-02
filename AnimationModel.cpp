#include "AnimationHeaders.h"
#include "stb/stb_image.h"

namespace Animation
{
    Model::Model(const char* path) { loadModel(path); }

    void Model::Draw(Shader& shader)
    {
        for (unsigned int i = 0; i < meshes.size(); i++)
            meshes[i].Draw(shader);
    }

    void Model::loadModel(std::string path)
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            std::cout << "ERROR :: ASSIMP::" << importer.GetErrorString() << std::endl;
            return;
        }
        directory = path.substr(0, path.find_last_of('/'));
        directory = directory.append("/");
        processRootNode(scene->mRootNode, scene);
    }

    void Model::processRootNode(aiNode* node, const aiScene* scene)
    {
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(node, mesh, scene, node->mTransformation));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++)
            processNode(node->mChildren[i], scene, node->mTransformation);
    }

    void Model::processNode(aiNode* node, const aiScene* scene, const aiMatrix4x4& parentNodeModelMatrix)
    {
        aiMatrix4x4 nodeModelMatrix = parentNodeModelMatrix * node->mTransformation;
        for (unsigned int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(node, mesh, scene, nodeModelMatrix));
        }
        for (unsigned int i = 0; i < node->mNumChildren; i++)
            processNode(node->mChildren[i], scene, nodeModelMatrix);
    }

    Mesh Model::processMesh(aiNode* node, aiMesh* mesh, const aiScene* scene, aiMatrix4x4& nodeModelMatrix)
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        for (unsigned int i = 0; i < mesh->mNumVertices; i++)
        {     
            Vertex vertex{};
            vertex.Position = toVector(mesh->mVertices[i]);
            vertex.Normal = (mesh->mNormals) ? toVector(mesh->mNormals[i]) : glm::vec3(0.0f, 0.0f, 0.0f);
            vertex.TexCoords = (mesh->mTextureCoords[0]) ? toVector(mesh->mTextureCoords[0][i]) : glm::vec2(0.0f, 0.0f);
            vertex.NodeModelMatrix = toMat4(nodeModelMatrix, false);
            vertices.push_back(vertex);
        }
        for (unsigned int i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++)
                indices.push_back(face.mIndices[j]);
        }
        if (mesh->mMaterialIndex >= 0)
        {
            aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
            std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
            textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
            /*std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_specular");
            textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());*/
        }
        return Mesh(vertices, indices, textures);
    }

    std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
    {
        std::vector<Texture> textures;
        std::string path = "D:/Projects/C++/OpenGLExercise/Assets/tex/rp_nathan_animated_003_dif.jpg";
        /*for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
        {
            aiString str;
            mat->GetTexture(type, i, &str);
            std::cout << "loadMaterialTextures/ Texture path :: " << str.C_Str() << std::endl;

            Texture texture;
            texture.id = textureFromFile(str.C_Str());
            texture.type = typeName;
            texture.path = str.C_Str();
            textures.push_back(texture);
        }*/
        Texture texture;
        texture.id = textureFromFile(path.c_str());
        texture.type = typeName;
        texture.path = path.c_str();
        textures.push_back(texture);
        return textures;
    }

    glm::vec3 Model::toVector(aiVector3D& ai_vector)
    {
        return glm::vec3(ai_vector.x, ai_vector.y, ai_vector.z);
    }

    glm::mat4 Model::toMat4(aiMatrix4x4& ai_Mat4, bool inverse)
    {
        if (inverse)
        {
            aiMatrix4x4 inv = ai_Mat4.Inverse();
            return glm::mat4(inv.a1, inv.b1, inv.c1, inv.d1,
                             inv.a2, inv.b2, inv.c2, inv.d2,
                             inv.a3, inv.b3, inv.c3, inv.d3,
                             inv.a4, inv.b4, inv.c4, inv.d4);
        }
        return glm::mat4(ai_Mat4.a1, ai_Mat4.b1, ai_Mat4.c1, ai_Mat4.d1,
                         ai_Mat4.a2, ai_Mat4.b2, ai_Mat4.c2, ai_Mat4.d2,
                         ai_Mat4.a3, ai_Mat4.b3, ai_Mat4.c3, ai_Mat4.d3,
                         ai_Mat4.a4, ai_Mat4.b4, ai_Mat4.c4, ai_Mat4.d4);
    }

    unsigned int Model::textureFromFile(const char* path)
    {
        std::string filename = std::string(path);
        //filename = directory + filename;

        unsigned int textureID;
        glGenTextures(1, &textureID);

        int width, height, nrComponents;
        unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
        if (data)
        {
            GLenum format;
            if (nrComponents == 1)
                format = GL_RED;
            else if (nrComponents == 3)
                format = GL_RGB;
            else if (nrComponents == 4)
                format = GL_RGBA;

            glBindTexture(GL_TEXTURE_2D, textureID);
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            stbi_image_free(data);
        }
        else
        {
            std::cout << "Texture failed to load at path: " << filename << std::endl;
            stbi_image_free(data);
        }
        return textureID;
        /*std::string actual_path = directory.append(path);
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        int width, height, color_channels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(actual_path.c_str(), &width, &height, &color_channels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            stbi_image_free(data);
        }
        else
            std::cout << "Error locating texture in path :: " << actual_path << std::endl;
        return texture;*/
    }
}