#include "VBO.h"

void VBO::VBOInit()
{
    glGenBuffers(1, &index);
}

void VBO::BufferData(float *vertices, unsigned int length)
{
    this->vertices = vertices;
    this->length = length;
    glBufferData(GL_ARRAY_BUFFER, length * sizeof(float), vertices, GL_STATIC_DRAW);
}

void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, index);
}

void VBO::UnBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Deleted()
{
    glDeleteBuffers(1, &index);
}
VBO::VBO()
{
    VBOInit();
}

VBO::~VBO()
{
    UnBind();
    Deleted();
}
