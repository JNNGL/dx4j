package com.jnngl.dx4j.glfw;

import static com.jnngl.dx4j.glfw.GLFW.GLFW_TRUE;

public interface GLFWcursorenterfun {

  void invoke(GLFWwindow window, boolean entered);

  default void invoke(long window, int entered) {
    this.invoke(new GLFWwindow(window), entered == GLFW_TRUE);
  }

}
