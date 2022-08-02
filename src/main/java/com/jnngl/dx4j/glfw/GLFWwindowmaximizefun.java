package com.jnngl.dx4j.glfw;

public interface GLFWwindowmaximizefun {

  void invoke(GLFWwindow window, int maximized);

  default void invoke(long window, int maximized) {
    this.invoke(new GLFWwindow(window), maximized);
  }

}
