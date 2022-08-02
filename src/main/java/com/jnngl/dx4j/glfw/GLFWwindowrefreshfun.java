package com.jnngl.dx4j.glfw;

public interface GLFWwindowrefreshfun {

  void invoke(GLFWwindow window);

  default void invoke(long window) {
    this.invoke(new GLFWwindow(window));
  }

}
