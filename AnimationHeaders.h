#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#define MAX_BONE_INFLUENCE 4

namespace Animation
{
    class Shader
    {
    public:
        unsigned int ID;
        Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
        void bind() const;
        void unbind() const;
        void setBool(const std::string& name, bool value) const;
        void setInt(const std::string& name, int value) const;
        void setFloat(const std::string& name, float value) const;
        void setVec2(const std::string& name, const glm::vec2& value) const;
        void setVec2(const std::string& name, float x, float y) const;
        void setVec3(const std::string& name, const glm::vec3& value) const;
        void setVec3(const std::string& name, float x, float y, float z) const;
        void setVec4(const std::string& name, const glm::vec4& value) const;
        void setVec4(const std::string& name, float x, float y, float z, float w);
        void setMat2(const std::string& name, const glm::mat2& mat) const;
        void setMat3(const std::string& name, const glm::mat3& mat) const;
        void setMat4(const std::string& name, const glm::mat4& mat) const;
    private:
        void checkCompileErrors(GLuint shader, std::string type);
    };

    struct Vertex 
    {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords;
        /*glm::vec3 Tangent;
        glm::vec3 Bitangent;
        int m_BoneIDs[MAX_BONE_INFLUENCE];
        float m_Weights[MAX_BONE_INFLUENCE];*/

        glm::mat4 NodeModelMatrix;
    };

    struct Texture 
    {
        unsigned int id;
        std::string type;
        std::string path;
    };

    class Mesh 
    {
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;
        unsigned int VAO;
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void Draw(Shader& shader);
    private:
        unsigned int VBO, EBO;
        void setupMesh();
    };

    class Model
    {
    public:
        Model(const char* path);
        void Draw(Shader& shader);
    private:
        std::vector<Mesh> meshes;
        std::string directory;

        void loadModel(std::string path);
        void processRootNode(aiNode* node, const aiScene* scene);
        void processNode(aiNode* node, const aiScene* scene, const aiMatrix4x4& parentNodeModelMatrix);
        Mesh processMesh(aiNode* node, aiMesh* mesh, const aiScene* scene, aiMatrix4x4& parentNodeModelMatrix);
        std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
        glm::vec3 toVector(aiVector3D& ai_vector);
        glm::mat4 toMat4(aiMatrix4x4& ai_Mat4, bool inverse);
        unsigned int textureFromFile(const char* path);
    };
}