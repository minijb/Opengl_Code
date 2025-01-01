#include "Op.h"

void Rendering();

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
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };  

    Shader v_shader(VERTEX_SHADER);
    v_shader.Compile(vertexShaderSource);
    Shader f_shader(FRAGMENT_SHADER);
    f_shader.Compile(fragmentShaderSource);

    ShaderProgram shaderProgram;
    shaderProgram.AttachShader(v_shader);
    shaderProgram.AttachShader(f_shader);
    shaderProgram.Link();

    

    while(!glfwWindowShouldClose(window.window)){

        window.ProcessInput();

        Rendering();

        glfwPollEvents();
        glfwSwapBuffers(window.window);
    }

    return 0;
}

void Rendering(){
    // rendering code
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
