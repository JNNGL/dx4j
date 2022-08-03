package com.jnngl.dx4j.glfw;

import com.jnngl.dx4j.common.Memory;

public class GLFWvidmode {

  private int width;
  private int height;
  private int redBits;
  private int greenBits;
  private int blueBits;
  private int refreshRate;

  public GLFWvidmode(int width, int height, int redBits, int greenBits, int blueBits, int refreshRate) {
    this.width = width;
    this.height = height;
    this.redBits = redBits;
    this.greenBits = greenBits;
    this.blueBits = blueBits;
    this.refreshRate = refreshRate;
  }

  public static GLFWvidmode fromAddress(long address) {
    if (address == 0) {
      return null;
    }

    return new GLFWvidmode(
        Memory.getUnsafe().getInt(address),
        Memory.getUnsafe().getInt(address + 4),
        Memory.getUnsafe().getInt(address + 8),
        Memory.getUnsafe().getInt(address + 12),
        Memory.getUnsafe().getInt(address + 16),
        Memory.getUnsafe().getInt(address + 20)
      );
  }

  public static GLFWvidmode[] fromAddress(long address, int count) {
    if (address == 0) {
      return null;
    }

    GLFWvidmode[] vidmodes = new GLFWvidmode[count];
    for (int i = 0; i < count; i++) {
      vidmodes[i] = fromAddress(address);
      address += 24;
    }
    return vidmodes;
  }

  public GLFWvidmode() {
    this(0, 0, 0, 0, 0, 0);
  }

  public int getBlueBits() {
    return this.blueBits;
  }

  public int getGreenBits() {
    return this.greenBits;
  }

  public int getHeight() {
    return this.height;
  }

  public int getRedBits() {
    return this.redBits;
  }

  public int getRefreshRate() {
    return this.refreshRate;
  }

  public int getWidth() {
    return this.width;
  }

  public void setBlueBits(int blueBits) {
    this.blueBits = blueBits;
  }

  public void setGreenBits(int greenBits) {
    this.greenBits = greenBits;
  }

  public void setHeight(int height) {
    this.height = height;
  }

  public void setRedBits(int redBits) {
    this.redBits = redBits;
  }

  public void setRefreshRate(int refreshRate) {
    this.refreshRate = refreshRate;
  }

  public void setWidth(int width) {
    this.width = width;
  }
}
