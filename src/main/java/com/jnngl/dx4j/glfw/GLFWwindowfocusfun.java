package com.jnngl.dx4j.glfw;

import static com.jnngl.dx4j.glfw.GLFW.GLFW_TRUE;

public interface GLFWwindowfocusfun {

  void invoke(GLFWwindow window, boolean focused);

  default void invoke(long window, int focused) {
    this.invoke(new GLFWwindow(window), focused == GLFW_TRUE);
  }

}
