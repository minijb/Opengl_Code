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
    unsigned int indices[] = {
        // 注意索引从0开始! 
        // 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
        // 这样可以由下标代表顶点组合成矩形

        0, 1, 3, // 第一个三角形
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

    EBO ebo;

    

    VAO vao;
    vao.Bind();
    
    // in vao bind buffer
    vbo.Bind();
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    vbo.UnBind();

    // in vao bind ebo
    ebo.Bind();
    ebo.BufferData(indices, sizeof(indices));

    vao.UnBind();
    ebo.UnBind();

    

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
