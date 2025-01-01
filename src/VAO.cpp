#include "VAO.h"



VAO::VAO()
{
    VAOInit();
}

VAO::~VAO()
{
    UnBind();
    Deleted();
}

void VAO::VAOInit()
{
    glGenVertexArrays(1, &index);
}

void VAO::Bind()
{
    glBindVertexArray(index);
}

void VAO::UnBind()
{
    glBindVertexArray(0);
}

void VAO::Deleted()
{
    glDeleteVertexArrays(1, &index);
}

