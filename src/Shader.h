#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

enum class ShaderType{
    VERTEX_SHADER = GL_VERTEX_SHADER,
    FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
    NONE
};

class Shader{
private:
    void ShaderInit(ShaderType type);
    void Debug();
    ShaderType type = ShaderType::NONE;
public:
    unsigned int shaderId;
    Shader(ShaderType type);
    ~Shader();
    void Compile(const char*);
    void Compile(std::ifstream&&);
    void Deleted();
};

class ShaderProgram{
private:
    void ProgramInit();
    void Debug();
    Shader vertexShader{ShaderType::VERTEX_SHADER};
    Shader fragmentShader{ShaderType::FRAGMENT_SHADER};
public:
    unsigned int programId;
    ShaderProgram();
    ~ShaderProgram();
    void AttachShader(Shader&);
    void ShaderConfig(std::ifstream &&vStream, std::ifstream &&fStream);
    void Link();
    void Use() const;
    void Deleted();

    // uniform
    void set4f(const char*, float, float, float, float) const;
    void setInt(const char*, int) const;
    void setFloat(const char*, float) const;
    void setBool(const char*, bool) const;  
    void set3f(const char*, float, float, float) const;
};