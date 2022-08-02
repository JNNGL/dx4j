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

    glfwSetErrorCallback((errorCode, description) ->
        System.err.println("[GLFW ERROR TEST 1] " + errorCode + ": " + description));

    GLFWwindow window = glfwCreateWindow(0, 0, "", null, null);
    assert window.getAddress() == 0;

    glfwSetErrorCallback((errorCode, description) ->
        System.err.println("[GLFW ERROR TEST 2] " + errorCode + ": " + description))
        .invoke(0, "prev callback test");

    window = glfwCreateWindow(0, 0, "", null, null);
    assert window.getAddress() == 0;

    glfwSetErrorCallback(null).invoke(0, "test");
    assert glfwSetErrorCallback(null) == null;

    window = glfwCreateWindow(800, 600, "Test Window", null, null);

    while (!glfwWindowShouldClose(window)) {
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
  }

}
