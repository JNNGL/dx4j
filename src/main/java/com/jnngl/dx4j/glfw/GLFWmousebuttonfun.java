package com.jnngl.dx4j.glfw;

public interface GLFWmousebuttonfun {

  void invoke(GLFWwindow window, int button, int action, int mods);

  default void invoke(long window, int button, int action, int mods) {
    this.invoke(new GLFWwindow(window), button, action, mods);
  }

}
