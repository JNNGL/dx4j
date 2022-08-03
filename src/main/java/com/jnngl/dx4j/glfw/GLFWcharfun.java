package com.jnngl.dx4j.glfw;

public interface GLFWcharfun {

  void invoke(GLFWwindow window, int codepoint);

  default void invoke(long window, int codepoint) {
    this.invoke(new GLFWwindow(window), codepoint);
  }

}
