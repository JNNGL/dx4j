package com.jnngl.dx4j.test;

import com.jnngl.dx4j.Dx4j;

import static com.jnngl.dx4j.glfw.GLFW.*;

import com.jnngl.dx4j.glfw.GLFWwindow;

class Test {

  public static void main(String[] args) {
    Dx4j.loadLibrary();

    int[] major = new int[1];
    int[] minor = new int[1];
    int[] rev = new int[1];
    glfwGetVersion(major, minor, rev);

    System.out.println(major[0] + "." + minor[0] + "." + rev[0]);

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
