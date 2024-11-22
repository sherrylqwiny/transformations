//
//  main.cpp
//  TRANSFORMATION
//
//  Created by Sherryl Ochieng on 22/11/2024.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

// Function to draw a block letter using GL_QUADS
void drawLetterY() {
    glBegin(GL_QUADS);
    // Top left part of Y
    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.05f, 0.6f);
    glVertex2f(-0.05f, 0.4f);
    glVertex2f(-0.15f, 0.4f);

    // Top right part of Y
    glVertex2f(0.05f, 0.6f);
    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(0.05f, 0.4f);

    // Bottom vertical part of Y
    glVertex2f(-0.05f, 0.4f);
    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.05f, -0.6f);
    glVertex2f(-0.05f, -0.6f);
    glEnd();
}

// Function to draw other letters similarly...

void drawScene() {
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    // Draw "Y"
    drawLetterY();
    // Use glTranslatef and other transformations to position other letters
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Render YOTUI", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, WIDTH, HEIGHT);

    // Set the background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the scene
        drawScene();

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

