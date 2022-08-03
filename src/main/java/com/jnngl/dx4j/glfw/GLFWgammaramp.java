package com.jnngl.dx4j.glfw;

import com.jnngl.dx4j.common.Memory;

public class GLFWgammaramp {

  private final short[] red;
  private final short[] green;
  private final short[] blue;

  public GLFWgammaramp(short[] red, short[] green, short[] blue) {
    this.red = red;
    this.green = green;
    this.blue = blue;
  }

  public GLFWgammaramp(int size) {
    this(new short[size], new short[size], new short[size]);
  }

  public GLFWgammaramp() {
    this(256);
  }

  public static GLFWgammaramp fromAddress(long address) {
    long redPointer = Memory.getUnsafe().getLong(address);
    long greenPointer = Memory.getUnsafe().getLong(address + 8);
    long bluePointer = Memory.getUnsafe().getLong(address + 16);
    int count = Memory.getUnsafe().getInt(address + 24);
    return new GLFWgammaramp(
        Memory.readShortArray(redPointer, count),
        Memory.readShortArray(greenPointer, count),
        Memory.readShortArray(bluePointer, count)
    );
  }

  public short[] getBlue() {
    return this.blue;
  }

  public short[] getGreen() {
    return this.green;
  }

  public short[] getRed() {
    return this.red;
  }

  private static int[] toUnsigned(short[] arr) {
    int[] dst = new int[arr.length];
    for (int i = 0; i < arr.length; i++) {
      dst[i] = Short.toUnsignedInt(arr[i]);
    }
    return dst;
  }

  public int[] getUnsignedBlue() {
    return toUnsigned(this.blue);
  }

  public int[] getUnsignedGreen() {
    return toUnsigned(this.green);
  }

  public int[] getUnsignedRed() {
    return toUnsigned(this.red);
  }

  public int getSize() {
    return this.red.length;
  }
}
