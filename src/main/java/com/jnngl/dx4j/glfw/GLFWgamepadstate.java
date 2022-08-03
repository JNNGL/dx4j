package com.jnngl.dx4j.glfw;

public class GLFWgamepadstate {

  private final boolean[] buttons = new boolean[15];
  private final float[] axes = new float[6];

  public boolean[] getButtons() {
    return buttons;
  }

  public float[] getAxes() {
    return axes;
  }
}
