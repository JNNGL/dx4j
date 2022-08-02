package com.jnngl.dx4j.glfw;

public interface GLFWwindowiconifyfun {

  void invoke(GLFWwindow window, int iconified);

  default void invoke(long window, int iconified) {
    this.invoke(new GLFWwindow(window), iconified);
  }

}
