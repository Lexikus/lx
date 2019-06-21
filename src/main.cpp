#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

#include <iostream>

// Header
void framebufferSizeCallback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void bind(unsigned int VBO, unsigned int IBO,
          glm::vec3 vertices[], unsigned int verticesSize,
          glm::uvec3 indicies[], unsigned int indicesSize);
void setTransform(Shader shader);

// settings
const short WIDTH = 800;
const short HEIGHT = 800;

// Shapes
glm::vec3 vertices_triangle[] = {
    {0.0f, 1.0f, 0.0f},
    {1.0f, -1.0f, 0.0f},
    {-1.0f, -1.0f, 0.0f}};
glm::uvec3 index_triangle[] = {{0, 1, 2}};

glm::vec3 vertices_rectangle[] = {
    {-0.5f, 0.5f, 0.0f},
    {-0.5f, -0.5f, 0.0f},
    {0.5f, -0.5f, 0.0f},
    {0.5f, 0.5f, 0.0f}};
glm::uvec3 index_rectangle[] = {{0, 1, 2}, {2, 3, 0}};

glm::vec3 vertices_cube[] = {
    // front up left 0
    {-0.5f, 0.5f, 0.5f},
    // front down left 1
    {-0.5f, -0.5f, 0.5f},
    // front down right 2
    {0.5f, -0.5f, 0.5f},
    // front up right 3
    {0.5f, 0.5f, 0.5f},

    // back up left 4
    {-0.5f, 0.5f, -0.5f},
    // back down left 5
    {-0.5f, -0.5f, -0.5f},
    // back down right 6
    {0.5f, -0.5f, -0.5f},
    // back up right 7
    {0.5f, 0.5f, -0.5f},
};
glm::uvec3 index_cube[] = {
    // front face
    {0, 1, 2},
    {2, 3, 0},
    // back face
    {7, 6, 5},
    {5, 4, 6},
    // left face
    {4, 5, 1},
    {1, 0, 4},
    // right face
    {3, 2, 6},
    {6, 7, 3},
};

// float pyramide
glm::vec3 vertices_pyramide[] = {
    // corner
    {0.0f, 0.5f, 0.0f},
    // front left
    {0.5f, -0.5f, 0.0f},
    // front right
    {-0.5f, -0.5f, 0.0f},
    // back
    {0.0f, -0.5f, 0.5f},

};

glm::uvec3 index_pyramide[] = {
    {0, 1, 2},
    {0, 2, 3},
    {0, 3, 1},
};

int main()
{
    //-------------------------------
    // Initialize and configure
    // ------------------------------
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // ------------------------------
    // GLFW Window creation
    // ------------------------------

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "SAE OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "FAILED to create a window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // ------------------------------
    // GLAD: load all OpenGL function pointers
    // ------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Register Window Callbacks
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    Shader shader("assets/shaders/vert.vs", "assets/shaders/frag.fs");

    // Triangle
    unsigned int vao;
    unsigned int vbo;
    unsigned int ibo;

    // create buffers
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    // draw lines instead full triangle
    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);

    // bind triangle
    // bind(vbo, ibo, vertices_triangle, sizeof(vertices_triangle), index_triangle, sizeof(index_triangle));

    // bind rectangle
    // bind(vbo, ibo, vertices_rectangle, sizeof(vertices_rectangle), index_rectangle, sizeof(index_rectangle));

    // bind cube
    // bind(vbo, ibo, vertices_cube, sizeof(vertices_cube), index_cube, sizeof(index_cube));

    // bind pyramide
    bind(vbo, ibo, vertices_pyramide, sizeof(vertices_pyramide), index_pyramide, sizeof(index_pyramide));

    // ------------------------------
    // Render Loop
    // ------------------------------
    while (!glfwWindowShouldClose(window))
    {
        //------------------------------
        // Input
        //------------------------------
        processInput(window);

        //------------------------------
        // Render
        //------------------------------
        double deltaTime = glfwGetTime();

        glClearColor(0, 0, 0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        setTransform(shader);
        shader.use();

        glBindVertexArray(vao);

        // i do not care yet if i overdraw stuff :)
        glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);

        //------------------------------
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        //------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //------------------------------
    // glfw: terminate, clearing all previously allocated GLFW resources.
    //------------------------------
    glfwTerminate();
    return 0;
}

//------------------------------
// Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
//------------------------------
// glfw: whenever the window size changed (by OS or user resize input) this callback function executes
//------------------------------
void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void bind(unsigned int VBO, unsigned int IBO,
          glm::vec3 vertices[], unsigned int verticesSize,
          glm::uvec3 indicies[], unsigned int indicesSize)
{

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indicies, GL_STATIC_DRAW);
}

void setTransform(Shader shader)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(0, 0, 3));
    model = glm::scale(model, glm::vec3(100, 100, 100));
    view = glm::translate(view, glm::vec3(0, 0, -10));
    projection = glm::ortho(-(float)WIDTH / 2, (float)WIDTH / 2, -(float)HEIGHT / 2, (float)HEIGHT / 2, 0.1f, 100.0f);

    unsigned int modelLoc = glGetUniformLocation(shader.ID, "model");
    unsigned int viewLoc = glGetUniformLocation(shader.ID, "view");

    glUniformMatrix4fv(modelLoc, 1, false, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, false, &view[0][0]);

    shader.setMat4("projection", projection);
}