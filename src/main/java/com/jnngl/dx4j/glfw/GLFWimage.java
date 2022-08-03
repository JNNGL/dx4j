package com.jnngl.dx4j.glfw;

import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;

public class GLFWimage {

  private final int width;
  private final int height;
  private final byte[] pixels;

  public GLFWimage(int width, int height, byte[] pixels) {
    this.width = width;
    this.height = height;
    this.pixels = pixels;
  }

  public BufferedImage toBufferedImage(int format) {
    assert format >= BufferedImage.TYPE_3BYTE_BGR && format <= BufferedImage.TYPE_4BYTE_ABGR_PRE;
    BufferedImage image = new BufferedImage(width, height, format);
    System.arraycopy(pixels, 0, ((DataBufferByte) image.getRaster().getDataBuffer()).getData(), 0, pixels.length);
    return image;
  }

  public int getWidth() {
    return width;
  }

  public int getHeight() {
    return height;
  }

  public byte[] getPixels() {
    return pixels;
  }
}
