package com.jnngl.dx4j.test;

import com.jnngl.dx4j.Dx4j;

import static com.jnngl.dx4j.glfw.GLFW.*;

import com.jnngl.dx4j.glfw.GLFWwindow;

class Test {

  public static void main(String[] args) {
    Dx4j.loadLibrary();

    glfwInit();
    GLFWwindow window = glfwCreateWindow(800, 600, "Test Window", null, null);

    while (!glfwWindowShouldClose(window)) {
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
  }

}
