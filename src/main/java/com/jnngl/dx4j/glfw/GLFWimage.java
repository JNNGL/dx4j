package com.jnngl.dx4j.glfw;

import java.awt.AlphaComposite;
import java.awt.Graphics2D;
import java.awt.Transparency;
import java.awt.color.ColorSpace;
import java.awt.image.BufferedImage;
import java.awt.image.ComponentColorModel;
import java.awt.image.DataBuffer;
import java.awt.image.DataBufferByte;
import java.awt.image.Raster;
import java.awt.image.WritableRaster;

public class GLFWimage {

  private final int width;
  private final int height;
  private final byte[] pixels;

  public GLFWimage(int width, int height, byte[] pixels) {
    this.width = width;
    this.height = height;
    this.pixels = pixels;
  }

  public GLFWimage(int width, int height) {
    this(width, height, new byte[width * height * 4]);
  }

  public GLFWimage(BufferedImage image) {
    this.width = image.getWidth();
    this.height = image.getHeight();
    BufferedImage rgba4 = createImage();
    this.pixels = ((DataBufferByte) rgba4.getRaster().getDataBuffer()).getData();
    Graphics2D graphics = rgba4.createGraphics();
    graphics.setComposite(AlphaComposite.Src);
    graphics.drawImage(image, 0, 0, null);
    graphics.dispose();
  }

  private BufferedImage createImage() {
    ComponentColorModel colorModel = new ComponentColorModel(
        ColorSpace.getInstance(ColorSpace.CS_sRGB), true, false, Transparency.TRANSLUCENT, DataBuffer.TYPE_BYTE);
    WritableRaster raster = Raster.createInterleavedRaster(
        DataBuffer.TYPE_BYTE, this.width, this.height, this.width * 4, 4, new int[] {0, 1, 2, 3}, null);
    return new BufferedImage(colorModel, raster, colorModel.isAlphaPremultiplied(), null);
  }

  public BufferedImage toBufferedImage() {
    BufferedImage image = createImage();
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
