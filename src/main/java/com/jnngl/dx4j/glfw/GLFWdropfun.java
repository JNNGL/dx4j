package com.jnngl.dx4j.glfw;

public interface GLFWdropfun {

  void invoke(GLFWwindow window, String[] paths);

  default void invoke(long window, String[] paths) {
    this.invoke(new GLFWwindow(window), paths);
  }

}
