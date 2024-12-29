#include "window.h"

#pragma region callback

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

#pragma endregion


#pragma region Window
Window::Window(){
    Height = 600;
    Width = 800;
    GlfwInit();
    window = CreateWindow();
    GladInit();
}

Window::Window(int width, int height):Width(width), Height(height){  
    GlfwInit();
    window = CreateWindow();
    GladInit();
}

void Window::GlfwInit(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}


GLFWwindow* Window::CreateWindow(){
    GLFWwindow* window = glfwCreateWindow(Width, Height, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);
    return window;
}

void Window::GladInit(){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }    
    glViewport(0, 0, Width, Height);


    // callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  
}



Window::~Window(){
    glfwTerminate();
}
#pragma endregion