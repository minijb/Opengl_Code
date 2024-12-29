#include "window.h"


int main(){
    Window window(800, 600);

    while(!glfwWindowShouldClose(window.window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window.window);
        glfwPollEvents();
    }

    return 0;
}