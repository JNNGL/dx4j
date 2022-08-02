package com.jnngl.dx4j.glfw;

public interface GLFWwindowcontentscalefun {

  void invoke(GLFWwindow window, float xscale, float yscale);

  default void invoke(long window, float xscale, float yscale) {
    this.invoke(new GLFWwindow(window), xscale, yscale);
  }

}
