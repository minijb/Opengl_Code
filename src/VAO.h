#include <glad/glad.h>
#include <vector>


class VAO{
private:
    unsigned int index = 0;
    void VAOInit();

    
public:
    VAO();
    ~VAO();
    void Bind();
    void UnBind();
    void Deleted();
};