#include "Op.h"
#include <math.h>

void Rendering();
void Rendering(const ShaderProgram &sp, const VAO &vao);


int main(){
    Window window(1000, 800);


    float vertices[] = {
        // 位置              // 颜色
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
    };
    unsigned int indices1[] = {
        0, 1, 2 // 第一个三角形
    };


    ShaderProgram shaderProgram;
    shaderProgram.ShaderConfig(std::ifstream("./shader/v1.glsl"), std::ifstream("./shader/f1.glsl"));
    shaderProgram.Link();

    VBO vbo;
    vbo.Bind();
    vbo.BufferData(vertices, sizeof(vbo));
    vbo.UnBind();

    EBO ebo1;
    ebo1.Bind();
    ebo1.BufferData(indices1, sizeof(indices1));
    ebo1.UnBind();
    


    VAO vao;
    vao.Bind();
    
    // in vao bind buffer
    vbo.Bind();
    // 位置属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // 颜色属性
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    vbo.UnBind();

    // in vao bind ebo1
    ebo1.Bind();

    vao.UnBind();
    ebo1.UnBind();

    

    while(!glfwWindowShouldClose(window.window)){

        window.ProcessInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Rendering(shaderProgram, vao);

        glfwPollEvents();
        glfwSwapBuffers(window.window);
    }

    return 0;
}

void Rendering(const ShaderProgram &sp, const VAO &vao){
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    sp.set4f("ourColor", 0.0f, greenValue, 0.0f, 1.0f);
    sp.Use();
    vao.Bind();
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}
