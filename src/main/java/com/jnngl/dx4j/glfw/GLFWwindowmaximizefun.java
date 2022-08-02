package com.jnngl.dx4j.glfw;

import static com.jnngl.dx4j.glfw.GLFW.GLFW_TRUE;

public interface GLFWwindowmaximizefun {

  void invoke(GLFWwindow window, boolean maximized);

  default void invoke(long window, int maximized) {
    this.invoke(new GLFWwindow(window), maximized == GLFW_TRUE);
  }

}
