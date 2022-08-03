package com.jnngl.dx4j.test;

import com.jnngl.dx4j.Dx4j;

import static com.jnngl.dx4j.glfw.GLFW.*;

import com.jnngl.dx4j.glfw.GLFWimage;
import com.jnngl.dx4j.glfw.GLFWmonitor;
import com.jnngl.dx4j.glfw.GLFWvidmode;
import com.jnngl.dx4j.glfw.GLFWwindow;
import java.awt.Color;
import java.awt.image.BufferedImage;
import java.util.Arrays;
import java.util.Objects;

class Test {

  public static void main(String[] args) {
    Dx4j.loadLibrary();

    int[] major = new int[1];
    int[] minor = new int[1];
    int[] rev = new int[1];
    glfwGetVersion(major, minor, rev);
    System.out.println(major[0] + "." + minor[0] + "." + rev[0]);

    glfwInit();
    glfwSetErrorCallback((errorCode, description) ->
        System.err.println("[GLFW ERROR] " + errorCode + ": " + description));

    GLFWwindow window = glfwCreateWindow(800, 600, "Test Window", null, null);

    GLFWmonitor primaryMonitor = glfwGetPrimaryMonitor();
    System.out.println("Primary monitor: " + glfwGetMonitorName(primaryMonitor));
    System.out.println();

    for (GLFWmonitor monitor : Objects.requireNonNull(glfwGetMonitors())) {
      System.out.println("Monitor: " + glfwGetMonitorName(monitor));
      System.out.println("Total video modes: " + glfwGetVideoModes(monitor).length);
      System.out.println("Current video mode:");
      GLFWvidmode vidmode = glfwGetVideoMode(monitor);
      System.out.println(" - Width: " + vidmode.getWidth());
      System.out.println(" - Height: " + vidmode.getHeight());
      System.out.println(" - Red bits: " + vidmode.getRedBits());
      System.out.println(" - Green bits: " + vidmode.getGreenBits());
      System.out.println(" - Blue bits: " + vidmode.getBlueBits());
      System.out.println(" - Refresh rate: " + vidmode.getRefreshRate());
      System.out.println();
    }

    GLFWimage[] icons = new GLFWimage[3];

    for (int i = 0; i < icons.length; i++) {
      int dim = 16 * (i + 1);
      BufferedImage icon = new BufferedImage(dim, dim, i % 2 == 0? BufferedImage.TYPE_INT_ARGB : BufferedImage.TYPE_4BYTE_ABGR);
      for (int y = 0; y < dim; y++) {
        for (int x = 0; x < dim; x++) {
          icon.setRGB(x, y, new Color((float) x / dim, (float) y / dim, 0.f, 1.f).getRGB());
        }
      }
      icons[i] = new GLFWimage(icon);
      icons[i] = new GLFWimage(icons[i].toBufferedImage());
    }

    glfwSetWindowIcon(window, icons);

    glfwSetMonitorCallback((mon, event) -> System.out.println(glfwGetMonitorName(mon) + ": " + event));

    glfwSetKeyCallback(window, (wnd, key, scancode, action, mods) ->
        System.out.println("key: key=" + key + " (" + glfwGetKeyName(key, scancode) + "), scancode=" + scancode + ", action=" + action + ", mods=" + mods));
    glfwSetCharCallback(window, (wnd, codepoint) -> System.out.println("char: codepoint=" + codepoint + " (" + (char) codepoint + ")"));
    glfwSetCharModsCallback(window, (wnd, codepoint, mods) ->
        System.out.println("char mods: codepoint=" + codepoint + " (" + (char) codepoint + "), mods=" + mods));
    glfwSetMouseButtonCallback(window, (wnd, button, action, mods) ->
        System.out.println("mouse button: button=" + button + ", action=" + action + ", mods=" + mods));
    glfwSetCursorPosCallback(window, (wnd, xpos, ypos) -> System.out.println("cursor pos: x=" + xpos + ", y=" + ypos));
    glfwSetCursorEnterCallback(window, (wnd, entered) -> System.out.println("cursor enter: entered=" + entered));
    glfwSetScrollCallback(window, (wnd, xoffset, yoffset) -> System.out.println("scroll: x=" + xoffset + ", y=" + yoffset));
    glfwSetDropCallback(window, (wnd, paths) -> System.out.println("drop: paths=" + Arrays.toString(paths)));

    glfwSetWindowPosCallback(window, (wnd, xpos, ypos) -> System.out.println("Move: " + xpos + " " + ypos));
    glfwSetWindowSizeCallback(window, (wnd, width, height) -> System.out.println("Resize: " + width + " " + height));
    glfwSetWindowCloseCallback(window, (wnd) -> System.out.println("Close window"));
    glfwSetWindowRefreshCallback(window, (wnd) -> System.out.println("Refresh window"));
    glfwSetWindowFocusCallback(window, (wnd, focused) -> System.out.println("Focus window: " + focused));
    glfwSetWindowIconifyCallback(window, (wnd, iconified) -> System.out.println("Iconify window: " + iconified));
    glfwSetWindowMaximizeCallback(window, (wnd, maximized) -> System.out.println("Maximize window: " + maximized));
    glfwSetFramebufferSizeCallback(window, (wnd, width, height) -> System.out.println("Framebuffer size: " + width + " " + height));
    glfwSetWindowContentScaleCallback(window, (wnd, xscale, yscale) -> System.out.println("Content scale: " + xscale + " " + yscale));

    while (!glfwWindowShouldClose(window)) {
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
  }

}
