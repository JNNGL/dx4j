package com.jnngl.dx4j.glfw;

public interface GLFWscrollfun {

  void invoke(GLFWwindow window, double xoffset, double yoffset);

  default void invoke(long window, double xoffset, double yoffset) {
    this.invoke(new GLFWwindow(window), xoffset, yoffset);
  }

}
