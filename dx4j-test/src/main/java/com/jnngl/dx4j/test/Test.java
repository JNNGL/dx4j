package com.jnngl.dx4j.test;

import com.jnngl.dx4j.Dx4j;

import static com.jnngl.dx4j.glfw.GLFW.*;

import com.jnngl.dx4j.glfw.GLFWgammaramp;
import com.jnngl.dx4j.glfw.GLFWmonitor;
import com.jnngl.dx4j.glfw.GLFWvidmode;
import com.jnngl.dx4j.glfw.GLFWwindow;
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

    glfwSetMonitorCallback((mon, event) -> System.out.println(glfwGetMonitorName(mon) + ": " + event));
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
