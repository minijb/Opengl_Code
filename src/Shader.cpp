#include "Shader.h"

Shader::Shader(ShaderType type){
    ShaderInit(type);
}

Shader::~Shader(){
    Deleted();
}

void Shader::ShaderInit(ShaderType type){
    shaderId = glCreateShader(type);
}


void Shader::Compile(const char* shaderSource){
    glShaderSource(shaderId, 1, &shaderSource, NULL);
    glCompileShader(shaderId);
    Debug();
}

void Shader::Debug(){
    int success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void Shader::Deleted(){
    glDeleteShader(shaderId);
}


ShaderProgram::ShaderProgram(){
    ProgramInit();
}

ShaderProgram::~ShaderProgram(){
    Deleted();
}

void ShaderProgram::ProgramInit(){
    programId = glCreateProgram();
}

void ShaderProgram::AttachShader(Shader& shader){
    glAttachShader(programId, shader.shaderId);
}

void ShaderProgram::Link(){
    glLinkProgram(programId);
    Debug();
}

void ShaderProgram::Use(){
    glUseProgram(programId);
}

void ShaderProgram::Debug(){
    int success;
    char infoLog[512];
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(programId, 512, NULL, infoLog);
        std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
    }
}

void ShaderProgram::Deleted(){
    glDeleteProgram(programId);
}

