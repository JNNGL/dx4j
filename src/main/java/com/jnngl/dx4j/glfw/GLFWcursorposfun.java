package com.jnngl.dx4j.glfw;

public interface GLFWcursorposfun {

  void invoke(GLFWwindow window, double xpos, double ypos);

  default void invoke(long window, double xpos, double ypos) {
    this.invoke(new GLFWwindow(window), xpos, ypos);
  }

}
