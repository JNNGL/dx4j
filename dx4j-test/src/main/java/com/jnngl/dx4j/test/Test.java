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
        System.err.println("[GLFW ERROR] " + errorCode + ": " + description));

    GLFWwindow window = glfwCreateWindow(800, 600, "Test Window", null, null);

    glfwSetWindowPosCallback(window, (wnd, xpos, ypos) -> System.out.println("Move: " + xpos + " " + ypos));
    glfwSetWindowSizeCallback(window, (wnd, width, height) -> System.out.println("Resize: " + width + " " + height));
    glfwSetWindowCloseCallback(window, (wnd) -> System.out.println("Close window"));
    glfwSetWindowRefreshCallback(window, (wnd) -> System.out.println("Refresh window"));
    glfwSetWindowFocusCallback(window, (wnd, focused) -> System.out.println("Focus window: " + focused));
    glfwSetWindowIconifyCallback(window, (wnd, iconified) -> System.out.println("Iconify window: " + iconified));

    while (!glfwWindowShouldClose(window)) {
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
  }

}
