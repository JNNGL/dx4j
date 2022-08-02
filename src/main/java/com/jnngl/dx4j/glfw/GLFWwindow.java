package com.jnngl.dx4j.glfw;

import com.jnngl.dx4j.common.Pointer;

public class GLFWwindow extends Pointer {

  public static final GLFWwindow NULL = new GLFWwindow(0);

  public GLFWwindow(long address) {
    super(address);
  }

  public GLFWwindow(Pointer pointer) {
    super(pointer.getAddress());
  }

}
