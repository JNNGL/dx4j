package com.jnngl.dx4j.glfw;

public interface GLFWwindowsizefun {

  void invoke(GLFWwindow window, int width, int height);

  default void invoke(long window, int width, int height) {
    this.invoke(new GLFWwindow(window), width, height);
  }

}
