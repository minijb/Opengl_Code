#include <glad/glad.h>


class VBO
{
private:
    unsigned int index = 0;
    void VBOInit();
    float* vertices;
    unsigned int length;
public:
    VBO();
    ~VBO();
    void BufferData(float* vertices, unsigned int length);
    void Bind();
    void UnBind();
    void Deleted();

};

