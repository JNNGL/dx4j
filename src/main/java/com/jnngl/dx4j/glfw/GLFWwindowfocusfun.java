package com.jnngl.dx4j.glfw;

public interface GLFWwindowfocusfun {

  void invoke(GLFWwindow window, int focused);

  default void invoke(long window, int focused) {
    this.invoke(new GLFWwindow(window), focused);
  }

}
