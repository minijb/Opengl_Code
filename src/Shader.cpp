#include "Shader.h"
#include <iostream>
#include <string>

Shader::Shader(ShaderType type){
    ShaderInit(type);
    this->type = type;
}

Shader::~Shader(){
    Deleted();
}

void Shader::ShaderInit(ShaderType type){
    switch (type)
    {
    case ShaderType::VERTEX_SHADER:
        shaderId = glCreateShader(GL_VERTEX_SHADER);
        break;
    case ShaderType::FRAGMENT_SHADER:
        shaderId = glCreateShader(GL_FRAGMENT_SHADER);
        break;
    default:
        std::cout << "ERROR::SHADER::TYPE_NOT_SPECIFIED" << std::endl;
        break;
    }
}


void Shader::Compile(const char* shaderSource){
    glShaderSource(shaderId, 1, &shaderSource, NULL);
    glCompileShader(shaderId);
    Debug();
}

void Shader::Compile(std::ifstream &&file){
    if(file.fail()){
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        return;
    }
    std::string shaderSource;
    std::stringstream shaderS;
    shaderS << file.rdbuf();
    shaderSource = shaderS.str();
    const char* shaderSourceChar = shaderSource.c_str();
    glShaderSource(shaderId, 1, &shaderSourceChar, NULL);
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


// TODO use 完美转发
void ShaderProgram::ShaderConfig(std::ifstream &&vStream, std::ifstream &&fStream){
    vertexShader.Compile(std::move(vStream));
    fragmentShader.Compile(std::move(fStream));
    AttachShader(vertexShader);
    AttachShader(fragmentShader);
}

void ShaderProgram::Use() const{
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

void ShaderProgram::set4f(const char* name, float v0, float v1, float v2, float v3) const{
    glUniform4f(glGetUniformLocation(programId, name), v0, v1, v2, v3);
}

void ShaderProgram::setInt(const char* name, int value) const{
    glUniform1i(glGetUniformLocation(programId, name), value);
}

void ShaderProgram::setFloat(const char* name, float value) const{
    glUniform1f(glGetUniformLocation(programId, name), value);
}

void ShaderProgram::setBool(const char* name, bool value) const{
    glUniform1i(glGetUniformLocation(programId, name), value);
}

void ShaderProgram::set3f(const char* name, float v0, float v1, float v2) const{
    glUniform3f(glGetUniformLocation(programId, name), v0, v1, v2);
}