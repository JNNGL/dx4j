package com.jnngl.dx4j.glfw;

import com.jnngl.dx4j.common.Pointer;

public class GLFWmonitor extends Pointer {

  public static final GLFWmonitor NULL = new GLFWmonitor(0);

  public GLFWmonitor(long address) {
    super(address);
  }

  public GLFWmonitor(Pointer pointer) {
    super(pointer.getAddress());
  }

}
