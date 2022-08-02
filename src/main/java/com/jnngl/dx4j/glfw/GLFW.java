package com.jnngl.dx4j.glfw;

import com.jnngl.dx4j.common.Pointer;
import com.jnngl.dx4j.common.Validations;
import java.util.Objects;

public class GLFW {

  public static final int GLFW_VERSION_MAJOR         = 3;
  public static final int GLFW_VERSION_MINOR         = 3;
  public static final int GLFW_VERSION_REVISION      = 8;
  public static final int GLFW_TRUE                  = 1;
  public static final int GLFW_FALSE                 = 0;
  public static final int GLFW_JOYSTICK_HAT_BUTTONS  = 0x00050001;
  public static final int GLFW_COCOA_CHDIR_RESOURCES = 0x00051001;
  public static final int GLFW_COCOA_MENUBAR         = 0x00051002;

  public static final int GLFW_FOCUSED                  = 0x00020001;
  public static final int GLFW_ICONIFIED                = 0x00020002;
  public static final int GLFW_RESIZABLE                = 0x00020003;
  public static final int GLFW_VISIBLE                  = 0x00020004;
  public static final int GLFW_DECORATED                = 0x00020005;
  public static final int GLFW_AUTO_ICONIFY             = 0x00020006;
  public static final int GLFW_FLOATING                 = 0x00020007;
  public static final int GLFW_MAXIMIZED                = 0x00020008;
  public static final int GLFW_CENTER_CURSOR            = 0x00020009;
  public static final int GLFW_TRANSPARENT_FRAMEBUFFER  = 0x0002000A;
  public static final int GLFW_HOVERED                  = 0x0002000B;
  public static final int GLFW_FOCUS_ON_SHOW            = 0x0002000C;
  public static final int GLFW_RED_BITS                 = 0x00021001;
  public static final int GLFW_GREEN_BITS               = 0x00021002;
  public static final int GLFW_BLUE_BITS                = 0x00021003;
  public static final int GLFW_ALPHA_BITS               = 0x00021004;
  public static final int GLFW_DEPTH_BITS               = 0x00021005;
  public static final int GLFW_STENCIL_BITS             = 0x00021006;
  public static final int GLFW_ACCUM_RED_BITS           = 0x00021007;
  public static final int GLFW_ACCUM_GREEN_BITS         = 0x00021008;
  public static final int GLFW_ACCUM_BLUE_BITS          = 0x00021009;
  public static final int GLFW_ACCUM_ALPHA_BITS         = 0x0002100A;
  public static final int GLFW_AUX_BUFFERS              = 0x0002100B;
  public static final int GLFW_STEREO                   = 0x0002100C;
  public static final int GLFW_SAMPLES                  = 0x0002100D;
  public static final int GLFW_SRGB_CAPABLE             = 0x0002100E;
  public static final int GLFW_REFRESH_RATE             = 0x0002100F;
  public static final int GLFW_DOUBLEBUFFER             = 0x00021010;
  public static final int GLFW_CLIENT_API               = 0x00022001;
  public static final int GLFW_CONTEXT_VERSION_MAJOR    = 0x00022002;
  public static final int GLFW_CONTEXT_VERSION_MINOR    = 0x00022003;
  public static final int GLFW_CONTEXT_REVISION         = 0x00022004;
  public static final int GLFW_CONTEXT_ROBUSTNESS       = 0x00022005;
  public static final int GLFW_OPENGL_FORWARD_COMPAT    = 0x00022006;
  public static final int GLFW_OPENGL_DEBUG_CONTEXT     = 0x00022007;
  public static final int GLFW_OPENGL_PROFILE           = 0x00022008;
  public static final int GLFW_CONTEXT_RELEASE_BEHAVIOR = 0x00022009;
  public static final int GLFW_CONTEXT_NO_ERROR         = 0x0002200A;
  public static final int GLFW_CONTEXT_CREATION_API     = 0x0002200B;
  public static final int GLFW_SCALE_TO_MONITOR         = 0x0002200C;
  public static final int GLFW_COCOA_RETINA_FRAMEBUFFER = 0x00023001;
  public static final int GLFW_COCOA_FRAME_NAME         = 0x00023002;
  public static final int GLFW_COCOA_GRAPHICS_SWITCHING = 0x00023003;
  public static final int GLFW_X11_CLASS_NAME           = 0x00024001;
  public static final int GLFW_X11_INSTANCE_NAME        = 0x00024002;

  // TODO: glfwSetErrorCallback
  private static native long nglfwCreateWindow(int width, int height, String title, long monitor, long share);
  private static native void nglfwDestroyWindow(long window);
  private static native int nglfwWindowShouldClose(long window);
  private static native void nglfwSetWindowShouldClose(long window, int value);
  private static native void nglfwSetWindowTitle(long window, String title);
  // TODO: glfwSetWindowIcon
  private static native void nglfwGetWindowPos(long window, int[] xpos, int[] ypos);
  private static native void nglfwSetWindowPos(long window, int xpos, int ypos);
  private static native void nglfwGetWindowSize(long window, int[] width, int[] height);
  private static native void nglfwSetWindowSizeLimits(long window, int minwindth, int minheight, int maxwidth, int maxheight);
  private static native void nglfwSetWindowAspectRatio(long window, int numer, int denom);
  private static native void nglfwSetWindowSize(long window, int width, int height);
  private static native void nglfwGetFramebufferSize(long window, int[] width, int[] height);
  private static native void nglfwGetWindowFrameSize(long window, int[] left, int[] top, int[] right, int[] bottom);
  private static native void nglfwGetWindowContentScale(long window, float[] xscale, float[] yscale);
  private static native float nglfwGetWindowOpacity(long window);
  private static native void nglfwSetWindowOpacity(long window, float opacity);
  private static native void nglfwIconifyWindow(long window);
  private static native void nglfwRestoreWindow(long window);
  private static native void nglfwMaximizeWindow(long window);
  private static native void nglfwShowWindow(long window);
  private static native void nglfwHideWindow(long window);
  private static native void nglfwFocusWindow(long window);
  private static native void nglfwRequestWindowAttention(long window);
  private static native long nglfwGetWindowMonitor(long window);
  private static native void nglfwSetWindowMonitor(long window, long monitor, int xpos, int ypos, int width, int height, int refreshRate);
  private static native int nglfwGetWindowAttrib(long window, int attrib);
  private static native void nglfwSetWindowAttrib(long window, int attrib, int value);
  private static native void nglfwSetWindowUserPointer(long window, long pointer);
  private static native long nglfwGetWindowUserPointer(long window);
  // TODO: glfwSetWindowPosCallback
  // TODO: glfwSetWindowSizeCallback
  // TODO: glfwSetWindowCloseCallback
  // TODO: glfwSetWindowRefreshCallback
  // TODO: glfwSetWindowFocusCallback
  // TODO: glfwSetWindowIconifyCallback
  // TODO: glfwSetWindowMaximizeCallback
  // TODO: glfwSetFramebufferSizeCallback
  // TODO: glfwSetWindowContentScaleCallback
  private static native void nglfwSwapBuffers(long window);

  public static native int glfwInit();
  public static native void glfwTerminate();
  public static native void glfwInitHint(int hint, int value);
  public static native void glfwGetVersion(int[] major, int[] minor, int[] rev);
  public static native String glfwGetVersionString();
  public static native int glfwGetError(String[] description);
  public static native void glfwDefaultWindowHints();
  public static native void glfwWindowHint(int hint, int value);
  public static native void glfwWindowHintString(int hint, String value);
  public static native void glfwPollEvents();
  public static native void glfwWaitEvents();
  public static native void glfwWaitEventsTimeout(double timeout);
  public static native void glfwPostEmptyEvent();

  public static GLFWwindow glfwCreateWindow(int width, int height, String title, GLFWmonitor monitor, GLFWwindow share) {
    title = Objects.requireNonNullElse(title, "");
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    share = Objects.requireNonNullElse(share, GLFWwindow.NULL);
    return new GLFWwindow(nglfwCreateWindow(width, height, title, monitor.getAddress(), share.getAddress()));
  }

  public static void glfwDestroyWindow(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwDestroyWindow(window.getAddress());
  }

  public static boolean glfwWindowShouldClose(GLFWwindow window) {
    Validations.validateNotNull(window);
    return nglfwWindowShouldClose(window.getAddress()) != 0;
  }

  public static void glfwSetWindowShouldClose(GLFWwindow window, int value) {
    Validations.validateNotNull(window);
    nglfwSetWindowShouldClose(window.getAddress(), value);
  }

  public static void glfwSetWindowShouldClose(GLFWwindow window, boolean value) {
    glfwSetWindowShouldClose(window, value ? GLFW_TRUE : GLFW_FALSE);
  }

  public static void glfwSetWindowTitle(GLFWwindow window, String title) {
    Validations.validateNotNull(window);
    nglfwSetWindowTitle(window.getAddress(), title);
  }

  public static void glfwGetWindowPos(GLFWwindow window, int[] xpos, int[] ypos) {
    Validations.validateNotNull(window);
    Validations.validateArrayLength(xpos, 1);
    Validations.validateArrayLength(ypos, 1);
    nglfwGetWindowPos(window.getAddress(), xpos, ypos);
  }

  public static void glfwSetWindowPos(GLFWwindow window, int xpos, int ypos) {
    Validations.validateNotNull(window);
    nglfwSetWindowPos(window.getAddress(), xpos, ypos);
  }

  public static void glfwGetWindowSize(GLFWwindow window, int[] width, int[] height) {
    Validations.validateNotNull(window);
    Validations.validateArrayLength(width, 1);
    Validations.validateArrayLength(height, 1);
    nglfwGetWindowSize(window.getAddress(), width, height);
  }

  public static void glfwSetWindowSizeLimits(GLFWwindow window, int minwidth, int minheight, int maxwidth, int maxheight) {
    Validations.validateNotNull(window);
    nglfwSetWindowSizeLimits(window.getAddress(), minwidth, minheight, maxwidth, maxheight);
  }

  public static void glfwSetWindowAspectRatio(GLFWwindow window, int numer, int denom) {
    Validations.validateNotNull(window);
    nglfwSetWindowAspectRatio(window.getAddress(), numer, denom);
  }

  public static void glfwSetWindowSize(GLFWwindow window, int width, int height) {
    Validations.validateNotNull(window);
    nglfwSetWindowSize(window.getAddress(), width, height);
  }

  public static void glfwGetFramebufferSize(GLFWwindow window, int[] width, int[] height) {
    Validations.validateNotNull(window);
    Validations.validateArrayLength(width, 1);
    Validations.validateArrayLength(height, 1);
    nglfwGetFramebufferSize(window.getAddress(), width, height);
  }

  public static void glfwGetWindowFrameSize(GLFWwindow window, int[] left, int[] top, int[] right, int[] bottom) {
    Validations.validateNotNull(window);
    Validations.validateArrayLength(left, 1);
    Validations.validateArrayLength(top, 1);
    Validations.validateArrayLength(right, 1);
    Validations.validateArrayLength(bottom, 1);
    nglfwGetWindowFrameSize(window.getAddress(), left, top, right, bottom);
  }

  public static void glfwGetWindowContentScale(GLFWwindow window, float[] xscale, float[] yscale) {
    Validations.validateNotNull(window);
    Validations.validateArrayLength(xscale, 1);
    Validations.validateArrayLength(yscale, 1);
    nglfwGetWindowContentScale(window.getAddress(), xscale, yscale);
  }

  public static float glfwGetWindowOpacity(GLFWwindow window) {
    Validations.validateNotNull(window);
    return nglfwGetWindowOpacity(window.getAddress());
  }

  public static void glfwSetWindowOpacity(GLFWwindow window, float opacity) {
    Validations.validateNotNull(window);
    nglfwSetWindowOpacity(window.getAddress(), opacity);
  }

  public static void glfwIconifyWindow(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwIconifyWindow(window.getAddress());
  }

  public static void glfwRestoreWindow(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwRestoreWindow(window.getAddress());
  }

  public static void glfwMaximizeWindow(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwMaximizeWindow(window.getAddress());
  }

  public static void glfwShowWindow(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwShowWindow(window.getAddress());
  }

  public static void glfwHideWindow(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwHideWindow(window.getAddress());
  }

  public static void glfwFocusWindow(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwFocusWindow(window.getAddress());
  }

  public static void glfwRequestWindowAttention(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwRequestWindowAttention(window.getAddress());
  }

  public static GLFWmonitor glfwGetWindowMonitor(GLFWwindow window) {
    Validations.validateNotNull(window);
    return new GLFWmonitor(nglfwGetWindowMonitor(window.getAddress()));
  }

  public static void glfwSetWindowMonitor(GLFWwindow window, GLFWmonitor monitor, int xpos, int ypos, int width, int height, int refreshRate) {
    Validations.validateNotNull(window);
    nglfwSetWindowMonitor(window.getAddress(), monitor.getAddress(), xpos, ypos, width, height, refreshRate);
  }

  public static int glfwGetWindowAttrib(GLFWwindow window, int attrib) {
    Validations.validateNotNull(window);
    return nglfwGetWindowAttrib(window.getAddress(), attrib);
  }

  public static void glfwSetWindowAttrib(GLFWwindow window, int attrib, int value) {
    Validations.validateNotNull(window);
    nglfwSetWindowAttrib(window.getAddress(), attrib, value);
  }

  public static void glfwSetWindowUserPointer(GLFWwindow window, Pointer pointer) {
    Validations.validateNotNull(window);
    nglfwSetWindowUserPointer(window.getAddress(), pointer.getAddress());
  }

  public static Pointer glfwGetWindowUserPointer(GLFWwindow window) {
    Validations.validateNotNull(window);
    return new Pointer(nglfwGetWindowUserPointer(window.getAddress()));
  }

  public static void glfwSwapBuffers(GLFWwindow window) {
    Validations.validateNotNull(window);
    nglfwSwapBuffers(window.getAddress());
  }

}
