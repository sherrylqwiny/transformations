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

void drawLetterO() {
    glBegin(GL_QUADS);
    // Left part of O
    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.05f, 0.6f);
    glVertex2f(-0.05f, -0.6f);
    glVertex2f(-0.15f, -0.6f);

    // Right part of O
    glVertex2f(0.05f, 0.6f);
    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.15f, -0.6f);
    glVertex2f(0.05f, -0.6f);

    // Top part of O
    glVertex2f(-0.15f, 0.6f);
    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(-0.15f, 0.4f);

    // Bottom part of O
    glVertex2f(-0.15f, -0.6f);
    glVertex2f(0.15f, -0.6f);
    glVertex2f(0.15f, -0.4f);
    glVertex2f(-0.15f, -0.4f);
    glEnd();
}

void drawLetterT() {
    glBegin(GL_QUADS);
    // Top horizontal part of T
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.2f, 0.4f);
    glVertex2f(-0.2f, 0.4f);

    // Vertical part of T
    glVertex2f(-0.05f, 0.4f);
    glVertex2f(0.05f, 0.4f);
    glVertex2f(0.05f, -0.6f);
    glVertex2f(-0.05f, -0.6f);
    glEnd();
}

void drawLetterU() {
    glBegin(GL_QUADS);
    // Left side of U
    glVertex2f(-0.15f, 0.6f);
    glVertex2f(-0.05f, 0.6f);
    glVertex2f(-0.05f, -0.6f);
    glVertex2f(-0.15f, -0.6f);

    // Right side of U
    glVertex2f(0.05f, 0.6f);
    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.15f, -0.6f);
    glVertex2f(0.05f, -0.6f);

    // Bottom part of U
    glVertex2f(-0.15f, -0.6f);
    glVertex2f(0.15f, -0.6f);
    glVertex2f(0.15f, -0.8f);
    glVertex2f(-0.15f, -0.8f);
    glEnd();
}

void drawLetterI() {
    glBegin(GL_QUADS);
    // Left part of I
    glVertex2f(-0.05f, 0.6f);
    glVertex2f(0.05f, 0.6f);
    glVertex2f(0.05f, -0.6f);
    glVertex2f(-0.05f, -0.6f);

    // Top part of I
    glVertex2f(-0.15f, 0.6f);
    glVertex2f(0.15f, 0.6f);
    glVertex2f(0.15f, 0.4f);
    glVertex2f(-0.15f, 0.4f);

    // Bottom part of I
    glVertex2f(-0.15f, -0.6f);
    glVertex2f(0.15f, -0.6f);
    glVertex2f(0.15f, -0.8f);
    glVertex2f(-0.15f, -0.8f);
    glEnd();
}

void drawScene() {
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red

    // Draw "Y"
    drawLetterY();
    glTranslatef(0.4f, 0.0f, 0.0f); // Move to next letter position
    drawLetterO();
    glTranslatef(0.4f, 0.0f, 0.0f); // Move to next letter position
    drawLetterT();
    glTranslatef(0.4f, 0.0f, 0.0f); // Move to next letter position
    drawLetterU();
    glTranslatef(0.4f, 0.0f, 0.0f); // Move to next letter position
    drawLetterI();
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

