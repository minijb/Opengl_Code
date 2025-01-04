#include "Op.h"

void Rendering();
void Rendering(const ShaderProgram &sp, const VAO &vao);

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";


int main(){
    Window window(1000, 800);


    float vertices[] = {
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f   // 左上角
    };
    unsigned int indices1[] = {
        0, 1, 3 // 第一个三角形
    };
    unsigned int indices2[] = {
        1, 2, 3  // 第二个三角形
    };

    Shader v_shader(VERTEX_SHADER);
    v_shader.Compile(vertexShaderSource);
    Shader f_shader(FRAGMENT_SHADER);
    f_shader.Compile(fragmentShaderSource);

    ShaderProgram shaderProgram;
    shaderProgram.AttachShader(v_shader);
    shaderProgram.AttachShader(f_shader);
    shaderProgram.Link();

    VBO vbo;
    vbo.Bind();
    vbo.BufferData(vertices, sizeof(vbo));
    vbo.UnBind();

    EBO ebo1;
    ebo1.Bind();
    ebo1.BufferData(indices1, sizeof(indices1));
    ebo1.UnBind();
    
    EBO ebo2;
    ebo2.Bind();
    ebo2.BufferData(indices2, sizeof(indices2));
    ebo2.UnBind();

    VAO vao;
    vao.Bind();
    
    // in vao bind buffer
    vbo.Bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    vbo.UnBind();

    // in vao bind ebo1
    ebo1.Bind();
    ebo2.Bind();

    vao.UnBind();
    ebo1.UnBind();
    ebo2.UnBind();

    

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
    sp.Use();
    vao.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
