#include <glad/glad.h>


class EBO{
private:
    unsigned int index = 0;
    void EBOInit();
    unsigned int* indices;
    unsigned int length;
public:
    EBO();
    ~EBO();
    void BufferData(unsigned int* indices, unsigned int length);
    void Bind();
    void UnBind();
    void Deleted();
};