package com.jnngl.dx4j.glfw;

public interface GLFWcharmodsfun {

  void invoke(GLFWwindow window, int codepoint, int mods);

  default void invoke(long window, int codepoint, int mods) {
    this.invoke(new GLFWwindow(window), codepoint, mods);
  }

}
