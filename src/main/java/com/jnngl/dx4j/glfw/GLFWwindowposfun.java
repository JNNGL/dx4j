package com.jnngl.dx4j.glfw;

public interface GLFWwindowposfun {

  void invoke(GLFWwindow window, int xpos, int ypos);

  default void invoke(long window, int xpos, int ypos) {
    this.invoke(new GLFWwindow(window), xpos, ypos);
  }

}
