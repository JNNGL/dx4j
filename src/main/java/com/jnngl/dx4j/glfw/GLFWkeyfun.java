package com.jnngl.dx4j.glfw;

public interface GLFWkeyfun {

  void invoke(GLFWwindow window, int key, int scancode, int action, int mods);

  default void invoke(long window, int key, int scancode, int action, int mods) {
    this.invoke(new GLFWwindow(window), key, scancode, action, mods);
  }

}
