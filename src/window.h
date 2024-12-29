#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window{
    public:
        GLFWwindow* window;
        Window();
        Window(int width, int height);
        ~Window();


    private:
        int Height;
        int Width;
        // glfw init
        void GlfwInit();
        GLFWwindow* CreateWindow();
        // glad init
        void GladInit();

};