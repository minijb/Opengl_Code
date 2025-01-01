#include "EBO.h"



EBO::EBO()
{
    EBOInit();
}

EBO::~EBO()
{
    UnBind();
    Deleted();
}

void EBO::EBOInit()
{
    glGenBuffers(1, &index);
}

void EBO::BufferData(unsigned int* indices, unsigned int length)
{
    this->indices = indices;
    this->length = length;
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(unsigned int), indices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
}

void EBO::UnBind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Deleted()
{
    glDeleteBuffers(1, &index);
}


