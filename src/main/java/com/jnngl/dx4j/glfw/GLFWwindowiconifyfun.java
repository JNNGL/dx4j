package com.jnngl.dx4j.glfw;

import static com.jnngl.dx4j.glfw.GLFW.GLFW_TRUE;

public interface GLFWwindowiconifyfun {

  void invoke(GLFWwindow window, boolean iconified);

  default void invoke(long window, int iconified) {
    this.invoke(new GLFWwindow(window), iconified == GLFW_TRUE);
  }

}
