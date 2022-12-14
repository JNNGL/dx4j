package com.jnngl.dx4j.glfw;

import com.jnngl.dx4j.common.Pointer;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

public class GLFW {

  public static final int GLFW_NO_ERROR = 0;
  public static final int GLFW_NOT_INITIALIZED = 0x00010001;
  public static final int GLFW_NO_CURRENT_CONTEXT = 0x00010002;
  public static final int GLFW_INVALID_ENUM = 0x00010003;
  public static final int GLFW_INVALID_VALUE = 0x00010004;
  public static final int GLFW_OUT_OF_MEMORY = 0x00010005;
  public static final int GLFW_API_UNAVAILABLE = 0x00010006;
  public static final int GLFW_VERSION_UNAVAILABLE = 0x00010007;
  public static final int GLFW_PLATFORM_ERROR = 0x00010008;
  public static final int GLFW_FORMAT_UNAVAILABLE = 0x00010009;
  public static final int GLFW_NO_WINDOW_CONTEXT = 0x0001000A;

  public static final int GLFW_VERSION_MAJOR = 3;
  public static final int GLFW_VERSION_MINOR = 3;
  public static final int GLFW_VERSION_REVISION = 8;
  public static final int GLFW_TRUE = 1;
  public static final int GLFW_FALSE = 0;
  public static final int GLFW_JOYSTICK_HAT_BUTTONS = 0x00050001;
  public static final int GLFW_COCOA_CHDIR_RESOURCES = 0x00051001;
  public static final int GLFW_COCOA_MENUBAR = 0x00051002;

  public static final int GLFW_FOCUSED = 0x00020001;
  public static final int GLFW_ICONIFIED = 0x00020002;
  public static final int GLFW_RESIZABLE = 0x00020003;
  public static final int GLFW_VISIBLE = 0x00020004;
  public static final int GLFW_DECORATED = 0x00020005;
  public static final int GLFW_AUTO_ICONIFY = 0x00020006;
  public static final int GLFW_FLOATING = 0x00020007;
  public static final int GLFW_MAXIMIZED = 0x00020008;
  public static final int GLFW_CENTER_CURSOR = 0x00020009;
  public static final int GLFW_TRANSPARENT_FRAMEBUFFER = 0x0002000A;
  public static final int GLFW_HOVERED = 0x0002000B;
  public static final int GLFW_FOCUS_ON_SHOW = 0x0002000C;
  public static final int GLFW_RED_BITS = 0x00021001;
  public static final int GLFW_GREEN_BITS = 0x00021002;
  public static final int GLFW_BLUE_BITS = 0x00021003;
  public static final int GLFW_ALPHA_BITS = 0x00021004;
  public static final int GLFW_DEPTH_BITS = 0x00021005;
  public static final int GLFW_STENCIL_BITS = 0x00021006;
  public static final int GLFW_ACCUM_RED_BITS = 0x00021007;
  public static final int GLFW_ACCUM_GREEN_BITS = 0x00021008;
  public static final int GLFW_ACCUM_BLUE_BITS = 0x00021009;
  public static final int GLFW_ACCUM_ALPHA_BITS = 0x0002100A;
  public static final int GLFW_AUX_BUFFERS = 0x0002100B;
  public static final int GLFW_STEREO = 0x0002100C;
  public static final int GLFW_SAMPLES = 0x0002100D;
  public static final int GLFW_SRGB_CAPABLE = 0x0002100E;
  public static final int GLFW_REFRESH_RATE = 0x0002100F;
  public static final int GLFW_DOUBLEBUFFER = 0x00021010;
  public static final int GLFW_CLIENT_API = 0x00022001;
  public static final int GLFW_CONTEXT_VERSION_MAJOR = 0x00022002;
  public static final int GLFW_CONTEXT_VERSION_MINOR = 0x00022003;
  public static final int GLFW_CONTEXT_REVISION = 0x00022004;
  public static final int GLFW_CONTEXT_ROBUSTNESS = 0x00022005;
  public static final int GLFW_OPENGL_FORWARD_COMPAT = 0x00022006;
  public static final int GLFW_OPENGL_DEBUG_CONTEXT = 0x00022007;
  public static final int GLFW_OPENGL_PROFILE = 0x00022008;
  public static final int GLFW_CONTEXT_RELEASE_BEHAVIOR = 0x00022009;
  public static final int GLFW_CONTEXT_NO_ERROR = 0x0002200A;
  public static final int GLFW_CONTEXT_CREATION_API = 0x0002200B;
  public static final int GLFW_SCALE_TO_MONITOR = 0x0002200C;
  public static final int GLFW_COCOA_RETINA_FRAMEBUFFER = 0x00023001;
  public static final int GLFW_COCOA_FRAME_NAME = 0x00023002;
  public static final int GLFW_COCOA_GRAPHICS_SWITCHING = 0x00023003;
  public static final int GLFW_X11_CLASS_NAME = 0x00024001;
  public static final int GLFW_X11_INSTANCE_NAME = 0x00024002;

  public static final int GLFW_GAMEPAD_AXIS_LEFT_X = 0;
  public static final int GLFW_GAMEPAD_AXIS_LEFT_Y = 1;
  public static final int GLFW_GAMEPAD_AXIS_RIGHT_X = 2;
  public static final int GLFW_GAMEPAD_AXIS_RIGHT_Y = 3;
  public static final int GLFW_GAMEPAD_AXIS_LEFT_TRIGGER = 4;
  public static final int GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER = 5;
  public static final int GLFW_GAMEPAD_AXIS_LAST = GLFW_GAMEPAD_AXIS_RIGHT_TRIGGER;

  public static final int GLFW_GAMEPAD_BUTTON_A = 0;
  public static final int GLFW_GAMEPAD_BUTTON_B = 1;
  public static final int GLFW_GAMEPAD_BUTTON_X = 2;
  public static final int GLFW_GAMEPAD_BUTTON_Y = 3;
  public static final int GLFW_GAMEPAD_BUTTON_LEFT_BUMPER = 4;
  public static final int GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER = 5;
  public static final int GLFW_GAMEPAD_BUTTON_BACK = 6;
  public static final int GLFW_GAMEPAD_BUTTON_START = 7;
  public static final int GLFW_GAMEPAD_BUTTON_GUIDE = 8;
  public static final int GLFW_GAMEPAD_BUTTON_LEFT_THUMB = 9;
  public static final int GLFW_GAMEPAD_BUTTON_RIGHT_THUMB = 10;
  public static final int GLFW_GAMEPAD_BUTTON_DPAD_UP = 11;
  public static final int GLFW_GAMEPAD_BUTTON_DPAD_RIGHT = 12;
  public static final int GLFW_GAMEPAD_BUTTON_DPAD_DOWN = 13;
  public static final int GLFW_GAMEPAD_BUTTON_DPAD_LEFT = 14;
  public static final int GLFW_GAMEPAD_BUTTON_LAST = GLFW_GAMEPAD_BUTTON_DPAD_LEFT;
  public static final int GLFW_GAMEPAD_BUTTON_CROSS = GLFW_GAMEPAD_BUTTON_A;
  public static final int GLFW_GAMEPAD_BUTTON_CIRCLE = GLFW_GAMEPAD_BUTTON_B;
  public static final int GLFW_GAMEPAD_BUTTON_SQUARE = GLFW_GAMEPAD_BUTTON_X;
  public static final int GLFW_GAMEPAD_BUTTON_TRIANGLE = GLFW_GAMEPAD_BUTTON_Y;

  public static final int GLFW_HAT_CENTERED = 0;
  public static final int GLFW_HAT_UP = 1;
  public static final int GLFW_HAT_RIGHT = 2;
  public static final int GLFW_HAT_DOWN = 4;
  public static final int GLFW_HAT_LEFT = 8;
  public static final int GLFW_HAT_RIGHT_UP = GLFW_HAT_RIGHT | GLFW_HAT_UP;
  public static final int GLFW_HAT_RIGHT_DOWN = GLFW_HAT_RIGHT | GLFW_HAT_DOWN;
  public static final int GLFW_HAT_LEFT_UP = GLFW_HAT_LEFT | GLFW_HAT_UP;
  public static final int GLFW_HAT_LEFT_DOWN = GLFW_HAT_LEFT | GLFW_HAT_DOWN;

  public static final int GLFW_JOYSTICK_1 = 0;
  public static final int GLFW_JOYSTICK_2 = 1;
  public static final int GLFW_JOYSTICK_3 = 2;
  public static final int GLFW_JOYSTICK_4 = 3;
  public static final int GLFW_JOYSTICK_5 = 4;
  public static final int GLFW_JOYSTICK_6 = 5;
  public static final int GLFW_JOYSTICK_7 = 6;
  public static final int GLFW_JOYSTICK_8 = 7;
  public static final int GLFW_JOYSTICK_9 = 8;
  public static final int GLFW_JOYSTICK_10 = 9;
  public static final int GLFW_JOYSTICK_11 = 10;
  public static final int GLFW_JOYSTICK_12 = 11;
  public static final int GLFW_JOYSTICK_13 = 12;
  public static final int GLFW_JOYSTICK_14 = 13;
  public static final int GLFW_JOYSTICK_15 = 14;
  public static final int GLFW_JOYSTICK_16 = 15;
  public static final int GLFW_JOYSTICK_LAST = GLFW_JOYSTICK_16;


  public static final int GLFW_KEY_UNKNOWN = -1;
  public static final int GLFW_KEY_SPACE = 32;
  public static final int GLFW_KEY_APOSTROPHE = 39 /* ' */;
  public static final int GLFW_KEY_COMMA = 44 /* , */;
  public static final int GLFW_KEY_MINUS = 45 /* - */;
  public static final int GLFW_KEY_PERIOD = 46 /* . */;
  public static final int GLFW_KEY_SLASH = 47 /* / */;
  public static final int GLFW_KEY_0 = 48;
  public static final int GLFW_KEY_1 = 49;
  public static final int GLFW_KEY_2 = 50;
  public static final int GLFW_KEY_3 = 51;
  public static final int GLFW_KEY_4 = 52;
  public static final int GLFW_KEY_5 = 53;
  public static final int GLFW_KEY_6 = 54;
  public static final int GLFW_KEY_7 = 55;
  public static final int GLFW_KEY_8 = 56;
  public static final int GLFW_KEY_9 = 57;
  public static final int GLFW_KEY_SEMICOLON = 59 /* ; */;
  public static final int GLFW_KEY_EQUAL = 61 /* = */;
  public static final int GLFW_KEY_A = 65;
  public static final int GLFW_KEY_B = 66;
  public static final int GLFW_KEY_C = 67;
  public static final int GLFW_KEY_D = 68;
  public static final int GLFW_KEY_E = 69;
  public static final int GLFW_KEY_F = 70;
  public static final int GLFW_KEY_G = 71;
  public static final int GLFW_KEY_H = 72;
  public static final int GLFW_KEY_I = 73;
  public static final int GLFW_KEY_J = 74;
  public static final int GLFW_KEY_K = 75;
  public static final int GLFW_KEY_L = 76;
  public static final int GLFW_KEY_M = 77;
  public static final int GLFW_KEY_N = 78;
  public static final int GLFW_KEY_O = 79;
  public static final int GLFW_KEY_P = 80;
  public static final int GLFW_KEY_Q = 81;
  public static final int GLFW_KEY_R = 82;
  public static final int GLFW_KEY_S = 83;
  public static final int GLFW_KEY_T = 84;
  public static final int GLFW_KEY_U = 85;
  public static final int GLFW_KEY_V = 86;
  public static final int GLFW_KEY_W = 87;
  public static final int GLFW_KEY_X = 88;
  public static final int GLFW_KEY_Y = 89;
  public static final int GLFW_KEY_Z = 90;
  public static final int GLFW_KEY_LEFT_BRACKET = 91 /* [ */;
  public static final int GLFW_KEY_BACKSLASH = 92 /* \ */;
  public static final int GLFW_KEY_RIGHT_BRACKET = 93 /* ] */;
  public static final int GLFW_KEY_GRAVE_ACCENT = 96 /* ` */;
  public static final int GLFW_KEY_WORLD_1 = 161 /* non-US #1 */;
  public static final int GLFW_KEY_WORLD_2 = 162 /* non-US #2 */;
  public static final int GLFW_KEY_ESCAPE = 256;
  public static final int GLFW_KEY_ENTER = 257;
  public static final int GLFW_KEY_TAB = 258;
  public static final int GLFW_KEY_BACKSPACE = 259;
  public static final int GLFW_KEY_INSERT = 260;
  public static final int GLFW_KEY_DELETE = 261;
  public static final int GLFW_KEY_RIGHT = 262;
  public static final int GLFW_KEY_LEFT = 263;
  public static final int GLFW_KEY_DOWN = 264;
  public static final int GLFW_KEY_UP = 265;
  public static final int GLFW_KEY_PAGE_UP = 266;
  public static final int GLFW_KEY_PAGE_DOWN = 267;
  public static final int GLFW_KEY_HOME = 268;
  public static final int GLFW_KEY_END = 269;
  public static final int GLFW_KEY_CAPS_LOCK = 280;
  public static final int GLFW_KEY_SCROLL_LOCK = 281;
  public static final int GLFW_KEY_NUM_LOCK = 282;
  public static final int GLFW_KEY_PRINT_SCREEN = 283;
  public static final int GLFW_KEY_PAUSE = 284;
  public static final int GLFW_KEY_F1 = 290;
  public static final int GLFW_KEY_F2 = 291;
  public static final int GLFW_KEY_F3 = 292;
  public static final int GLFW_KEY_F4 = 293;
  public static final int GLFW_KEY_F5 = 294;
  public static final int GLFW_KEY_F6 = 295;
  public static final int GLFW_KEY_F7 = 296;
  public static final int GLFW_KEY_F8 = 297;
  public static final int GLFW_KEY_F9 = 298;
  public static final int GLFW_KEY_F10 = 299;
  public static final int GLFW_KEY_F11 = 300;
  public static final int GLFW_KEY_F12 = 301;
  public static final int GLFW_KEY_F13 = 302;
  public static final int GLFW_KEY_F14 = 303;
  public static final int GLFW_KEY_F15 = 304;
  public static final int GLFW_KEY_F16 = 305;
  public static final int GLFW_KEY_F17 = 306;
  public static final int GLFW_KEY_F18 = 307;
  public static final int GLFW_KEY_F19 = 308;
  public static final int GLFW_KEY_F20 = 309;
  public static final int GLFW_KEY_F21 = 310;
  public static final int GLFW_KEY_F22 = 311;
  public static final int GLFW_KEY_F23 = 312;
  public static final int GLFW_KEY_F24 = 313;
  public static final int GLFW_KEY_F25 = 314;
  public static final int GLFW_KEY_KP_0 = 320;
  public static final int GLFW_KEY_KP_1 = 321;
  public static final int GLFW_KEY_KP_2 = 322;
  public static final int GLFW_KEY_KP_3 = 323;
  public static final int GLFW_KEY_KP_4 = 324;
  public static final int GLFW_KEY_KP_5 = 325;
  public static final int GLFW_KEY_KP_6 = 326;
  public static final int GLFW_KEY_KP_7 = 327;
  public static final int GLFW_KEY_KP_8 = 328;
  public static final int GLFW_KEY_KP_9 = 329;
  public static final int GLFW_KEY_KP_DECIMAL = 330;
  public static final int GLFW_KEY_KP_DIVIDE = 331;
  public static final int GLFW_KEY_KP_MULTIPLY = 332;
  public static final int GLFW_KEY_KP_SUBTRACT = 333;
  public static final int GLFW_KEY_KP_ADD = 334;
  public static final int GLFW_KEY_KP_ENTER = 335;
  public static final int GLFW_KEY_KP_EQUAL = 336;
  public static final int GLFW_KEY_LEFT_SHIFT = 340;
  public static final int GLFW_KEY_LEFT_CONTROL = 341;
  public static final int GLFW_KEY_LEFT_ALT = 342;
  public static final int GLFW_KEY_LEFT_SUPER = 343;
  public static final int GLFW_KEY_RIGHT_SHIFT = 344;
  public static final int GLFW_KEY_RIGHT_CONTROL = 345;
  public static final int GLFW_KEY_RIGHT_ALT = 346;
  public static final int GLFW_KEY_RIGHT_SUPER = 347;
  public static final int GLFW_KEY_MENU = 348;
  public static final int GLFW_KEY_LAST = GLFW_KEY_MENU;

  public static final int GLFW_MOD_SHIFT = 0x0001;
  public static final int GLFW_MOD_CONTROL = 0x0002;
  public static final int GLFW_MOD_ALT = 0x0004;
  public static final int GLFW_MOD_SUPER = 0x0008;
  public static final int GLFW_MOD_CAPS_LOCK = 0x0010;
  public static final int GLFW_MOD_NUM_LOCK = 0x0020;

  public static final int GLFW_MOUSE_BUTTON_1 = 0;
  public static final int GLFW_MOUSE_BUTTON_2 = 1;
  public static final int GLFW_MOUSE_BUTTON_3 = 2;
  public static final int GLFW_MOUSE_BUTTON_4 = 3;
  public static final int GLFW_MOUSE_BUTTON_5 = 4;
  public static final int GLFW_MOUSE_BUTTON_6 = 5;
  public static final int GLFW_MOUSE_BUTTON_7 = 6;
  public static final int GLFW_MOUSE_BUTTON_8 = 7;
  public static final int GLFW_MOUSE_BUTTON_LAST = GLFW_MOUSE_BUTTON_8;
  public static final int GLFW_MOUSE_BUTTON_LEFT = GLFW_MOUSE_BUTTON_1;
  public static final int GLFW_MOUSE_BUTTON_RIGHT = GLFW_MOUSE_BUTTON_2;
  public static final int GLFW_MOUSE_BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_3;

  public static final int GLFW_ARROW_CURSOR = 0x00036001;
  public static final int GLFW_IBEAM_CURSOR = 0x00036002;
  public static final int GLFW_CROSSHAIR_CURSOR = 0x00036003;
  public static final int GLFW_HAND_CURSOR = 0x00036004;
  public static final int GLFW_HRESIZE_CURSOR = 0x00036005;
  public static final int GLFW_VRESIZE_CURSOR = 0x00036006;

  public static final int GLFW_NO_API = 0;
  public static final int GLFW_OPENGL_API = 0x00030001;
  public static final int GLFW_OPENGL_ES_API = 0x00030002;
  public static final int GLFW_NO_ROBUSTNESS = 0;
  public static final int GLFW_NO_RESET_NOTIFICATION = 0x00031001;
  public static final int GLFW_LOSE_CONTEXT_ON_RESET = 0x00031002;
  public static final int GLFW_OPENGL_ANY_PROFILE = 0;
  public static final int GLFW_OPENGL_CORE_PROFILE = 0x00032001;
  public static final int GLFW_OPENGL_COMPAT_PROFILE = 0x00032002;
  public static final int GLFW_CURSOR = 0x00033001;
  public static final int GLFW_STICKY_KEYS = 0x00033002;
  public static final int GLFW_STICKY_MOUSE_BUTTONS = 0x00033003;
  public static final int GLFW_LOCK_KEY_MODS = 0x00033004;
  public static final int GLFW_RAW_MOUSE_MOTION = 0x00033005;
  public static final int GLFW_CURSOR_NORMAL = 0x00034001;
  public static final int GLFW_CURSOR_HIDDEN = 0x00034002;
  public static final int GLFW_CURSOR_DISABLED = 0x00034003;
  public static final int GLFW_ANY_RELEASE_BEHAVIOR = 0;
  public static final int GLFW_RELEASE_BEHAVIOR_FLUSH = 0x00035001;
  public static final int GLFW_RELEASE_BEHAVIOR_NONE = 0x00035002;
  public static final int GLFW_NATIVE_CONTEXT_API = 0x00036001;
  public static final int GLFW_EGL_CONTEXT_API = 0x00036002;
  public static final int GLFW_OSMESA_CONTEXT_API = 0x00036003;
  public static final int GLFW_CONNECTED = 0x00040001;
  public static final int GLFW_DISCONNECTED = 0x00040002;
  public static final int GLFW_DONT_CARE = -1;

  public static final int GLFW_RELEASE = 0;
  public static final int GLFW_PRESS = 1;
  public static final int GLFW_REPEAT = 2;

  private static native long nglfwCreateWindow(int width, int height, String title, long monitor, long share);

  private static native void nglfwDestroyWindow(long window);

  private static native int nglfwWindowShouldClose(long window);

  private static native void nglfwSetWindowShouldClose(long window, int value);

  private static native void nglfwSetWindowTitle(long window, String title);

  private static native void nglfwSetWindowIcon(long window, int[] widths, int[] heights, byte[][] pixels);

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

  private static native GLFWwindowposfun nglfwSetWindowPosCallback(long window, GLFWwindowposfun callback);

  private static native GLFWwindowsizefun nglfwSetWindowSizeCallback(long window, GLFWwindowsizefun callback);

  private static native GLFWwindowclosefun nglfwSetWindowCloseCallback(long window, GLFWwindowclosefun callback);

  private static native GLFWwindowrefreshfun nglfwSetWindowRefreshCallback(long window, GLFWwindowrefreshfun callback);

  private static native GLFWwindowfocusfun nglfwSetWindowFocusCallback(long window, GLFWwindowfocusfun callback);

  private static native GLFWwindowiconifyfun nglfwSetWindowIconifyCallback(long window, GLFWwindowiconifyfun callback);

  private static native GLFWwindowmaximizefun nglfwSetWindowMaximizeCallback(long window, GLFWwindowmaximizefun callback);

  private static native GLFWframebuffersizefun nglfwSetFramebufferSizeCallback(long window, GLFWframebuffersizefun callback);

  private static native GLFWwindowcontentscalefun nglfwSetWindowContentScaleCallback(long window, GLFWwindowcontentscalefun callback);

  private static native void nglfwSwapBuffers(long window);

  private static native String nglfwGetWin32Adapter(long monitor);

  private static native String nglfwGetWin32Monitor(long monitor);

  private static native long nglfwGetWin32Window(long window);

  private static native long[] nglfwGetMonitors();

  private static native long nglfwGetPrimaryMonitor();

  private static native void nglfwGetMonitorPos(long monitor, int[] xpos, int[] ypos);

  private static native void nglfwGetMonitorWorkarea(long monitor, int[] xpos, int[] ypos, int[] width, int[] height);

  private static native void nglfwGetMonitorPhysicalSize(long monitor, int[] widthMM, int[] heightMM);

  private static native void nglfwGetMonitorContentScale(long monitor, float[] xscale, float[] yscale);

  private static native String nglfwGetMonitorName(long monitor);

  private static native void nglfwSetMonitorUserPointer(long monitor, long pointer);

  private static native long nglfwGetMonitorUserPointer(long monitor);

  private static native long nglfwGetVideoModes(long monitor, int[] count);

  private static native long nglfwGetVideoMode(long monitor);

  private static native void nglfwSetGamma(long monitor, float gamma);

  private static native long nglfwGetGammaRamp(long monitor);

  private static native void nglfwSetGammaRamp(long monitor, short[] red, short[] green, short[] blue);

  private static native int nglfwGetInputMode(long window, int mode);

  private static native void nglfwSetInputMode(long window, int mode, int value);

  private static native int nglfwGetKey(long window, int key);

  private static native boolean nglfwGetMouseButton(long window, int button);

  private static native void nglfwGetCursorPos(long window, double[] xpos, double[] ypos);

  private static native void nglfwSetCursorPos(long window, double xpos, double ypos);

  private static native long nglfwCreateCursor(int width, int height, byte[] pixels, int xhot, int yhot);

  private static native long nglfwCreateStandardCursor(int shape);

  private static native void nglfwDestroyCursor(long cursor);

  private static native void nglfwSetCursor(long window, long cursor);

  private static native GLFWkeyfun nglfwSetKeyCallback(long window, GLFWkeyfun callback);

  private static native GLFWcharfun nglfwSetCharCallback(long window, GLFWcharfun callback);

  private static native GLFWcharmodsfun nglfwSetCharModsCallback(long window, GLFWcharmodsfun callback);

  private static native GLFWmousebuttonfun nglfwSetMouseButtonCallback(long window, GLFWmousebuttonfun callback);

  private static native GLFWcursorposfun nglfwSetCursorPosCallback(long window, GLFWcursorposfun callback);

  private static native GLFWcursorenterfun nglfwSetCursorEnterCallback(long window, GLFWcursorenterfun callback);

  private static native GLFWscrollfun nglfwSetScrollCallback(long window, GLFWscrollfun callback);

  private static native GLFWdropfun nglfwSetDropCallback(long window, GLFWdropfun callback);

  private static native void nglfwSetJoystickUserPointer(int jid, long pointer);

  private static native long nglfwGetJoystickUserPointer(int jid);

  private static native boolean nglfwGetGamepadState(int jid, boolean[] buttons, float[] axes);

  private static native void nglfwSetClipboardString(long window, String string);

  private static native String nglfwGetClipboardString(long window);


  public static native int glfwInit();

  public static native void glfwTerminate();

  public static native void glfwInitHint(int hint, int value);

  public static native void glfwGetVersion(int[] major, int[] minor, int[] rev);

  public static native String glfwGetVersionString();

  public static native int glfwGetError(String[] description);

  public static native GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun callback);

  public static native void glfwDefaultWindowHints();

  public static native void glfwWindowHint(int hint, int value);

  public static native void glfwWindowHintString(int hint, String value);

  public static native void glfwPollEvents();

  public static native void glfwWaitEvents();

  public static native void glfwWaitEventsTimeout(double timeout);

  public static native void glfwPostEmptyEvent();

  public static native GLFWmonitorfun glfwSetMonitorCallback(GLFWmonitorfun callback);

  public static native boolean glfwRawMouseMotionSupported();

  public static native String glfwGetKeyName(int key, int scancode);

  public static native int glfwGetKeyScancode(int key);

  public static native boolean glfwJoystickPresent(int jid);

  public static native float[] glfwGetJoystickAxes(int jid);

  public static native byte[] glfwGetJoystickButtons(int jid);

  public static native byte[] glfwGetJoystickHats(int jid);

  public static native String glfwGetJoystickName(int jid);

  public static native String glfwGetJoystickGUID(int jid);

  public static native boolean glfwJoystickIsGamepad(int jid);

  public static native GLFWjoystickfun glfwSetJoystickCallback(GLFWjoystickfun callback);

  public static native boolean glfwUpdateGamepadMappings(String string);

  public static native String glfwGetGamepadName(int jid);

  public static native double glfwGetTime();

  public static native long glfwGetTimerValue();

  public static native long glfwGetTimerFrequency();


  public static GLFWwindow glfwCreateWindow(int width, int height, String title, GLFWmonitor monitor, GLFWwindow share) {
    title = Objects.requireNonNullElse(title, "");
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    share = Objects.requireNonNullElse(share, GLFWwindow.NULL);
    return new GLFWwindow(nglfwCreateWindow(width, height, title, monitor.getAddress(), share.getAddress()));
  }

  public static void glfwDestroyWindow(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwDestroyWindow(window.getAddress());
  }

  public static boolean glfwWindowShouldClose(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwWindowShouldClose(window.getAddress()) != 0;
  }

  public static void glfwSetWindowShouldClose(GLFWwindow window, int value) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowShouldClose(window.getAddress(), value);
  }

  public static void glfwSetWindowShouldClose(GLFWwindow window, boolean value) {
    glfwSetWindowShouldClose(window, value ? GLFW_TRUE : GLFW_FALSE);
  }

  public static void glfwSetWindowTitle(GLFWwindow window, String title) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowTitle(window.getAddress(), title);
  }

  public static void glfwGetWindowPos(GLFWwindow window, int[] xpos, int[] ypos) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwGetWindowPos(window.getAddress(), xpos, ypos);
  }

  public static void glfwSetWindowPos(GLFWwindow window, int xpos, int ypos) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowPos(window.getAddress(), xpos, ypos);
  }

  public static void glfwGetWindowSize(GLFWwindow window, int[] width, int[] height) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwGetWindowSize(window.getAddress(), width, height);
  }

  public static void glfwSetWindowSizeLimits(GLFWwindow window, int minwidth, int minheight, int maxwidth, int maxheight) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowSizeLimits(window.getAddress(), minwidth, minheight, maxwidth, maxheight);
  }

  public static void glfwSetWindowAspectRatio(GLFWwindow window, int numer, int denom) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowAspectRatio(window.getAddress(), numer, denom);
  }

  public static void glfwSetWindowSize(GLFWwindow window, int width, int height) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowSize(window.getAddress(), width, height);
  }

  public static void glfwGetFramebufferSize(GLFWwindow window, int[] width, int[] height) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwGetFramebufferSize(window.getAddress(), width, height);
  }

  public static void glfwGetWindowFrameSize(GLFWwindow window, int[] left, int[] top, int[] right, int[] bottom) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwGetWindowFrameSize(window.getAddress(), left, top, right, bottom);
  }

  public static void glfwGetWindowContentScale(GLFWwindow window, float[] xscale, float[] yscale) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwGetWindowContentScale(window.getAddress(), xscale, yscale);
  }

  public static float glfwGetWindowOpacity(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwGetWindowOpacity(window.getAddress());
  }

  public static void glfwSetWindowOpacity(GLFWwindow window, float opacity) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowOpacity(window.getAddress(), opacity);
  }

  public static void glfwIconifyWindow(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwIconifyWindow(window.getAddress());
  }

  public static void glfwRestoreWindow(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwRestoreWindow(window.getAddress());
  }

  public static void glfwMaximizeWindow(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwMaximizeWindow(window.getAddress());
  }

  public static void glfwShowWindow(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwShowWindow(window.getAddress());
  }

  public static void glfwHideWindow(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwHideWindow(window.getAddress());
  }

  public static void glfwFocusWindow(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwFocusWindow(window.getAddress());
  }

  public static void glfwRequestWindowAttention(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwRequestWindowAttention(window.getAddress());
  }

  public static GLFWmonitor glfwGetWindowMonitor(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return new GLFWmonitor(nglfwGetWindowMonitor(window.getAddress()));
  }

  public static void glfwSetWindowMonitor(GLFWwindow window, GLFWmonitor monitor, int xpos, int ypos, int width, int height, int refreshRate) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    nglfwSetWindowMonitor(window.getAddress(), monitor.getAddress(), xpos, ypos, width, height, refreshRate);
  }

  public static int glfwGetWindowAttrib(GLFWwindow window, int attrib) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwGetWindowAttrib(window.getAddress(), attrib);
  }

  public static void glfwSetWindowAttrib(GLFWwindow window, int attrib, int value) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetWindowAttrib(window.getAddress(), attrib, value);
  }

  public static void glfwSetWindowUserPointer(GLFWwindow window, Pointer pointer) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    pointer = Objects.requireNonNullElseGet(pointer, () -> new Pointer(0));
    nglfwSetWindowUserPointer(window.getAddress(), pointer.getAddress());
  }

  public static Pointer glfwGetWindowUserPointer(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return new Pointer(nglfwGetWindowUserPointer(window.getAddress()));
  }

  public static void glfwSwapBuffers(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSwapBuffers(window.getAddress());
  }

  public static GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow window, GLFWwindowposfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowPosCallback(window.getAddress(), callback);
  }

  public static GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow window, GLFWwindowsizefun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowSizeCallback(window.getAddress(), callback);
  }

  public static GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow window, GLFWwindowclosefun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowCloseCallback(window.getAddress(), callback);
  }

  public static GLFWwindowrefreshfun glfwSetWindowRefreshCallback(GLFWwindow window, GLFWwindowrefreshfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowRefreshCallback(window.getAddress(), callback);
  }

  public static GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow window, GLFWwindowfocusfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowFocusCallback(window.getAddress(), callback);
  }

  public static GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow window, GLFWwindowiconifyfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowIconifyCallback(window.getAddress(), callback);
  }

  public static GLFWwindowmaximizefun glfwSetWindowMaximizeCallback(GLFWwindow window, GLFWwindowmaximizefun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowMaximizeCallback(window.getAddress(), callback);
  }

  public static GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow window, GLFWframebuffersizefun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetFramebufferSizeCallback(window.getAddress(), callback);
  }

  public static GLFWwindowcontentscalefun glfwSetWindowContentScaleCallback(GLFWwindow window, GLFWwindowcontentscalefun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetWindowContentScaleCallback(window.getAddress(), callback);
  }

  public static String glfwGetWin32Adapter(GLFWmonitor monitor) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    return nglfwGetWin32Adapter(monitor.getAddress());
  }

  public static String glfwGetWin32Monitor(GLFWmonitor monitor) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    return nglfwGetWin32Monitor(monitor.getAddress());
  }

  // TODO:
  // public static HWND glfwGetWin32Window(GLFWwindow window) {
  //   window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
  //   return new HWND(nglfwGetWin32Window(window.getAddress()));
  // }

  public static GLFWmonitor[] glfwGetMonitors() {
    long[] monitors = nglfwGetMonitors();
    if (monitors == null) {
      return null;
    }
    return Arrays.stream(monitors).mapToObj(GLFWmonitor::new).toArray(GLFWmonitor[]::new);
  }

  public static GLFWmonitor glfwGetPrimaryMonitor() {
    return new GLFWmonitor(nglfwGetPrimaryMonitor());
  }

  public static void glfwGetMonitorPos(GLFWmonitor monitor, int[] xpos, int[] ypos) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    nglfwGetMonitorPos(monitor.getAddress(), xpos, ypos);
  }

  public static void glfwGetMonitorWorkarea(GLFWmonitor monitor, int[] xpos, int[] ypos, int[] width, int[] height) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    nglfwGetMonitorWorkarea(monitor.getAddress(), xpos, ypos, width, height);
  }

  public static void glfwGetMonitorPhysicalSize(GLFWmonitor monitor, int[] widthMM, int[] heightMM) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    nglfwGetMonitorPhysicalSize(monitor.getAddress(), widthMM, heightMM);
  }

  public static void glfwGetMonitorContentScale(GLFWmonitor monitor, float[] xscale, float[] yscale) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    nglfwGetMonitorContentScale(monitor.getAddress(), xscale, yscale);
  }

  public static String glfwGetMonitorName(GLFWmonitor monitor) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    return nglfwGetMonitorName(monitor.getAddress());
  }

  public static void glfwSetMonitorUserPointer(GLFWmonitor monitor, Pointer pointer) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    pointer = Objects.requireNonNullElseGet(pointer, () -> new Pointer(0));
    nglfwSetMonitorUserPointer(monitor.getAddress(), pointer.getAddress());
  }

  public static Pointer glfwGetMonitorUserPointer(GLFWmonitor monitor) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    return new Pointer(nglfwGetMonitorUserPointer(monitor.getAddress()));
  }

  public static GLFWvidmode[] glfwGetVideoModes(GLFWmonitor monitor) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    int[] count = new int[1];
    return GLFWvidmode.fromAddress(nglfwGetVideoModes(monitor.getAddress(), count), count[0]);
  }

  public static GLFWvidmode glfwGetVideoMode(GLFWmonitor monitor) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    return GLFWvidmode.fromAddress(nglfwGetVideoMode(monitor.getAddress()));
  }

  public static void glfwSetGamma(GLFWmonitor monitor, float gamma) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    nglfwSetGamma(monitor.getAddress(), gamma);
  }

  public static GLFWgammaramp glfwGetGammaRamp(GLFWmonitor monitor) {
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    return GLFWgammaramp.fromAddress(nglfwGetGammaRamp(monitor.getAddress()));
  }

  public static void glfwSetGammaRamp(GLFWmonitor monitor, GLFWgammaramp gammaRamp) {
    Objects.requireNonNull(gammaRamp);
    monitor = Objects.requireNonNullElse(monitor, GLFWmonitor.NULL);
    nglfwSetGammaRamp(monitor.getAddress(), gammaRamp.getRed(), gammaRamp.getGreen(), gammaRamp.getBlue());
  }

  public static int glfwGetInputMode(GLFWwindow window, int mode) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwGetInputMode(window.getAddress(), mode);
  }

  public static void glfwSetInputMode(GLFWwindow window, int mode, int value) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetInputMode(window.getAddress(), mode, value);
  }

  public static int glfwGetKey(GLFWwindow window, int key) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwGetKey(window.getAddress(), key);
  }

  public static boolean glfwGetMouseButton(GLFWwindow window, int button) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwGetMouseButton(window.getAddress(), button);
  }

  public static void glfwGetCursorPos(GLFWwindow window, double[] xpos, double[] ypos) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwGetCursorPos(window.getAddress(), xpos, ypos);
  }

  public static void glfwSetCursorPos(GLFWwindow window, double xpos, double ypos) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetCursorPos(window.getAddress(), xpos, ypos);
  }

  public static GLFWcursor glfwCreateCursor(GLFWimage image, int xhot, int yhot) {
    Objects.requireNonNull(image);
    return new GLFWcursor(nglfwCreateCursor(image.getWidth(), image.getHeight(), image.getPixels(), xhot, yhot));
  }

  public static GLFWcursor glfwCreateStandardCursor(int shape) {
    return new GLFWcursor(nglfwCreateStandardCursor(shape));
  }

  public static void glfwDestroyCursor(GLFWcursor cursor) {
    cursor = Objects.requireNonNullElseGet(cursor, () -> new GLFWcursor(0));
    nglfwDestroyCursor(cursor.getAddress());
  }

  public static void glfwSetCursor(GLFWwindow window, GLFWcursor cursor) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    cursor = Objects.requireNonNullElseGet(cursor, () -> new GLFWcursor(0));
    nglfwSetCursor(window.getAddress(), cursor.getAddress());
  }

  public static GLFWkeyfun glfwSetKeyCallback(GLFWwindow window, GLFWkeyfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetKeyCallback(window.getAddress(), callback);
  }

  public static GLFWcharfun glfwSetCharCallback(GLFWwindow window, GLFWcharfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetCharCallback(window.getAddress(), callback);
  }

  public static GLFWcharmodsfun glfwSetCharModsCallback(GLFWwindow window, GLFWcharmodsfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetCharModsCallback(window.getAddress(), callback);
  }

  public static GLFWmousebuttonfun glfwSetMouseButtonCallback(GLFWwindow window, GLFWmousebuttonfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetMouseButtonCallback(window.getAddress(), callback);
  }

  public static GLFWcursorposfun glfwSetCursorPosCallback(GLFWwindow window, GLFWcursorposfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetCursorPosCallback(window.getAddress(), callback);
  }

  public static GLFWcursorenterfun glfwSetCursorEnterCallback(GLFWwindow window, GLFWcursorenterfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetCursorEnterCallback(window.getAddress(), callback);
  }

  public static GLFWscrollfun glfwSetScrollCallback(GLFWwindow window, GLFWscrollfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetScrollCallback(window.getAddress(), callback);
  }

  public static GLFWdropfun glfwSetDropCallback(GLFWwindow window, GLFWdropfun callback) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwSetDropCallback(window.getAddress(), callback);
  }

  public static void glfwSetJoystickUserPointer(int jid, Pointer pointer) {
    pointer = Objects.requireNonNullElseGet(pointer, () -> new Pointer(0));
    nglfwSetJoystickUserPointer(jid, pointer.getAddress());
  }

  public static Pointer glfwGetJoystickUserPointer(int jid) {
    return new Pointer(nglfwGetJoystickUserPointer(jid));
  }

  public static boolean glfwGetGamepadState(int jid, GLFWgamepadstate gamepad) {
    gamepad = Objects.requireNonNullElse(gamepad, new GLFWgamepadstate());
    return nglfwGetGamepadState(jid, gamepad.getButtons(), gamepad.getAxes());
  }

  public static void glfwSetClipboardString(GLFWwindow window, String string) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    nglfwSetClipboardString(window.getAddress(), string);
  }

  public static String glfwGetClipboardString(GLFWwindow window) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    return nglfwGetClipboardString(window.getAddress());
  }

  public static void glfwSetWindowIcon(GLFWwindow window, GLFWimage[] images) {
    window = Objects.requireNonNullElse(window, GLFWwindow.NULL);
    images = Objects.requireNonNullElseGet(images, () -> new GLFWimage[0]);
    List<GLFWimage> icons = Arrays.stream(images).filter(Objects::nonNull).collect(Collectors.toList());
    nglfwSetWindowIcon(window.getAddress(),
        icons.stream().mapToInt(GLFWimage::getWidth).toArray(),
        icons.stream().mapToInt(GLFWimage::getHeight).toArray(),
        icons.stream().map(GLFWimage::getPixels).toArray(byte[][]::new));
  }

}
