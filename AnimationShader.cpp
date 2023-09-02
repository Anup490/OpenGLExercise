#include "AnimationHeaders.h"

namespace Animation
{
    Shader::Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
    {
        std::string vertexCode;
        std::string fragmentCode;
        std::string geometryCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        std::ifstream gShaderFile;

        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            vShaderFile.close();
            fShaderFile.close();
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
            if (geometryPath != nullptr)
            {
                gShaderFile.open(geometryPath);
                std::stringstream gShaderStream;
                gShaderStream << gShaderFile.rdbuf();
                gShaderFile.close();
                geometryCode = gShaderStream.str();
            }
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();
        unsigned int vertex, fragment;
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        unsigned int geometry;
        if (geometryPath != nullptr)
        {
            const char* gShaderCode = geometryCode.c_str();
            geometry = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(geometry, 1, &gShaderCode, NULL);
            glCompileShader(geometry);
            checkCompileErrors(geometry, "GEOMETRY");
        }
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        if (geometryPath != nullptr)
            glAttachShader(ID, geometry);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        if (geometryPath != nullptr)
            glDeleteShader(geometry);

    }

    void Shader::bind() const { glUseProgram(ID); }

    void Shader::unbind() const { glUseProgram(0); }

    void Shader::setBool(const std::string& name, bool value) const 
    { 
        bind();
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
        unbind();
    }

    void Shader::setInt(const std::string& name, int value) const
    {
        bind();
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
        unbind();
    }

    void Shader::setFloat(const std::string& name, float value) const
    {
        bind();
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
        unbind();
    }

    void Shader::setVec2(const std::string& name, const glm::vec2& value) const
    {
        bind();
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
        unbind();
    }

    void Shader::setVec2(const std::string& name, float x, float y) const
    {
        bind();
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
        unbind();
    }

    void Shader::setVec3(const std::string& name, const glm::vec3& value) const
    {
        bind();
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
        unbind();
    }

    void Shader::setVec3(const std::string& name, float x, float y, float z) const
    {
        bind();
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
        unbind();
    }

    void Shader::setVec4(const std::string& name, const glm::vec4& value) const
    {
        bind();
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
        unbind();
    }

    void Shader::setVec4(const std::string& name, float x, float y, float z, float w)
    {
        bind();
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
        unbind();
    }

    void Shader::setMat2(const std::string& name, const glm::mat2& mat) const
    {
        bind();
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        unbind();
    }

    void Shader::setMat3(const std::string& name, const glm::mat3& mat) const
    {
        bind();
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        unbind();
    }

    void Shader::setMat4(const std::string& name, const glm::mat4& mat) const
    {
        bind();
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        unbind();
    }

    void Shader::checkCompileErrors(GLuint shader, std::string type)
    {
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
}