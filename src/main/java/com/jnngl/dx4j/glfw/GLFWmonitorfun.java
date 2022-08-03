package com.jnngl.dx4j.glfw;

public interface GLFWmonitorfun {

  void invoke(GLFWmonitor monitor, int event);

  default void invoke(long monitor, int event) {
    this.invoke(new GLFWmonitor(monitor), event);
  }

}
