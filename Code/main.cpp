#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// callback function for window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

// key input
void processInput(GLFWwindow *window)
{
    // checks if escape key in being pressed, if it is set the window to be closed
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    glfwInit();
    // set version to core 3.3, there are many window hints that we can set 
    // https://www.glfw.org/docs/latest/window.html#window_hints
     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // this peice is needed for macOs
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // create the window object

    //arguments (width, height, name, monitor to use for fullscreen / null for window, window to share context with / null to not share)
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    
    //check if window was created, throw error if it wasn't
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //sets the window as the current context on the running thread
    glfwMakeContextCurrent(window);

    // initialize glad and check if it worked
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // set size of viewport and location of bottom left corner and register the callback to resize it if needed
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // render loop
    while(!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // rendering commands here
        
        // clear the screen with a color every frame
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // check and call events and swap the buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
  
    // exit normally
    glfwTerminate();
    return 0;
}