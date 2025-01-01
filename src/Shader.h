#include <glad/glad.h>
#include <iostream>

enum ShaderType{
    VERTEX_SHADER = GL_VERTEX_SHADER,
    FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

class Shader{
private:
    void ShaderInit(ShaderType type);
    void Debug();
public:
    unsigned int shaderId;
    Shader(ShaderType type);
    ~Shader();
    void Compile(const char*);
    void Deleted();
};

class ShaderProgram{
private:
    void ProgramInit();
    void Debug();
public:
    unsigned int programId;
    ShaderProgram();
    ~ShaderProgram();
    void AttachShader(Shader&);
    void Link();
    void Use();
    void Deleted();
};