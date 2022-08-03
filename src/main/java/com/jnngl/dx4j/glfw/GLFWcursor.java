package com.jnngl.dx4j.glfw;

import com.jnngl.dx4j.common.Pointer;

public class GLFWcursor extends Pointer {

  public GLFWcursor(long address) {
    super(address);
  }

  public GLFWcursor(Pointer pointer) {
    super(pointer.getAddress());
  }

}
