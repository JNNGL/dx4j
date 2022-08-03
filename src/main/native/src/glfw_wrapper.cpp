#include <jni/com_jnngl_dx4j_glfw_GLFW.h>
#include <GLFW/glfw3.h>

#define GLFW_EXPOSE_NATIVE_WIN32

#include <GLFW/glfw3native.h>
#include <callback_utils.h>
#include <vector>

#define CHECK_JARRAY_LENGTH(x) x && env->GetArrayLength(x) > 0

DECL_CALLBACK(GLFWerrorfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowposfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowsizefun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowclosefun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowrefreshfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowfocusfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowiconifyfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowmaximizefun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWframebuffersizefun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowcontentscalefun_cb)
DECL_CALLBACK(GLFWmonitorfun_cb)
DECL_CALLBACK(GLFWjoystickfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWkeyfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWcharfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWcharmodsfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWmousebuttonfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWcursorposfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWcursorenterfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWscrollfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWdropfun_cb)

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwCreateWindow
        (JNIEnv *env, jclass, jint width, jint height, jstring jtitle, jlong monitor, jlong share) {
    const char *title = env->GetStringUTFChars(jtitle, nullptr);
    GLFWwindow *window = glfwCreateWindow(width, height, title, (GLFWmonitor *) monitor, (GLFWwindow *) share);
    env->ReleaseStringUTFChars(jtitle, title);
    return (jlong) window;
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwDestroyWindow
        (JNIEnv *, jclass, jlong window) {
    glfwDestroyWindow((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwWindowShouldClose
        (JNIEnv *, jclass, jlong window) {
    return glfwWindowShouldClose((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowShouldClose
        (JNIEnv *, jclass, jlong window, jint value) {
    glfwSetWindowShouldClose((GLFWwindow *) window, value);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowTitle
        (JNIEnv *env, jclass, jlong window, jstring jtitle) {
    const char *title = env->GetStringUTFChars(jtitle, nullptr);
    glfwSetWindowTitle((GLFWwindow *) window, title);
    env->ReleaseStringUTFChars(jtitle, title);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowPos
        (JNIEnv *env, jclass, jlong window, jintArray jxposArr, jintArray jyposArr) {
    int xpos, ypos;
    glfwGetWindowPos((GLFWwindow *) window, &xpos, &ypos);
    jint jxpos = xpos, jypos = ypos;
    if (CHECK_JARRAY_LENGTH(jxposArr)) { env->SetIntArrayRegion(jxposArr, 0, 1, &jxpos); }
    if (CHECK_JARRAY_LENGTH(jyposArr)) { env->SetIntArrayRegion(jyposArr, 0, 1, &jypos); }
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowPos
        (JNIEnv *, jclass, jlong window, jint xpos, jint ypos) {
    glfwSetWindowPos((GLFWwindow *) window, xpos, ypos);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowSize
        (JNIEnv *env, jclass, jlong window, jintArray jwidthArr, jintArray jheightArr) {
    int width, height;
    glfwGetWindowSize((GLFWwindow *) window, &width, &height);
    jint jwidth = width, jheight = height;
    if (CHECK_JARRAY_LENGTH(jwidthArr)) { env->SetIntArrayRegion(jwidthArr, 0, 1, &jwidth); }
    if (CHECK_JARRAY_LENGTH(jheightArr)) { env->SetIntArrayRegion(jheightArr, 0, 1, &jheight); }
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowSizeLimits
        (JNIEnv *, jclass, jlong window, jint minwidth, jint minheight, jint maxwidth, jint maxheight) {
    glfwSetWindowSizeLimits((GLFWwindow *) window, minwidth, minheight, maxwidth, maxheight);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowAspectRatio
        (JNIEnv *, jclass, jlong window, jint numer, jint denom) {
    glfwSetWindowAspectRatio((GLFWwindow *) window, numer, denom);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowSize
        (JNIEnv *, jclass, jlong window, jint width, jint height) {
    glfwSetWindowSize((GLFWwindow *) window, width, height);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetFramebufferSize
        (JNIEnv *env, jclass, jlong window, jintArray jwidthArr, jintArray jheightArr) {
    int width, height;
    glfwGetFramebufferSize((GLFWwindow *) window, &width, &height);
    jint jwidth = width, jheight = height;
    if (CHECK_JARRAY_LENGTH(jwidthArr)) { env->SetIntArrayRegion(jwidthArr, 0, 1, &jwidth); }
    if (CHECK_JARRAY_LENGTH(jheightArr)) { env->SetIntArrayRegion(jheightArr, 0, 1, &jheight); }
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowFrameSize
        (JNIEnv *env, jclass, jlong window, jintArray jleftArr, jintArray jtopArr, jintArray jrightArr,
         jintArray jbottomArr) {
    int left, top, right, bottom;
    glfwGetWindowFrameSize((GLFWwindow *) window, &left, &top, &right, &bottom);
    jint jleft = left, jtop = top, jright = right, jbottom = bottom;
    if (CHECK_JARRAY_LENGTH(jleftArr)) { env->SetIntArrayRegion(jleftArr, 0, 1, &jleft); }
    if (CHECK_JARRAY_LENGTH(jtopArr)) { env->SetIntArrayRegion(jtopArr, 0, 1, &jtop); }
    if (CHECK_JARRAY_LENGTH(jrightArr)) { env->SetIntArrayRegion(jrightArr, 0, 1, &jright); }
    if (CHECK_JARRAY_LENGTH(jbottomArr)) { env->SetIntArrayRegion(jbottomArr, 0, 1, &jbottom); }
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowContentScale
        (JNIEnv *env, jclass, jlong window, jfloatArray jxscaleArr, jfloatArray jyscaleArr) {
    float xscale, yscale;
    glfwGetWindowContentScale((GLFWwindow *) window, &xscale, &yscale);
    if (CHECK_JARRAY_LENGTH(jxscaleArr)) { env->SetFloatArrayRegion(jxscaleArr, 0, 1, &xscale); }
    if (CHECK_JARRAY_LENGTH(jyscaleArr)) { env->SetFloatArrayRegion(jyscaleArr, 0, 1, &yscale); }
}

[[maybe_unused]] JNIEXPORT jfloat JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowOpacity
        (JNIEnv *, jclass, jlong window) {
    return glfwGetWindowOpacity((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowOpacity
        (JNIEnv *, jclass, jlong window, jfloat opacity) {
    glfwSetWindowOpacity((GLFWwindow *) window, opacity);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwIconifyWindow
        (JNIEnv *, jclass, jlong window) {
    glfwIconifyWindow((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwRestoreWindow
        (JNIEnv *, jclass, jlong window) {
    glfwRestoreWindow((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwMaximizeWindow
        (JNIEnv *, jclass, jlong window) {
    glfwMaximizeWindow((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwShowWindow
        (JNIEnv *, jclass, jlong window) {
    glfwShowWindow((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwHideWindow
        (JNIEnv *, jclass, jlong window) {
    glfwHideWindow((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwFocusWindow
        (JNIEnv *, jclass, jlong window) {
    glfwFocusWindow((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwRequestWindowAttention
        (JNIEnv *, jclass, jlong window) {
    glfwRequestWindowAttention((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowMonitor
        (JNIEnv *, jclass, jlong window) {
    return (jlong) glfwGetWindowMonitor((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowMonitor
        (JNIEnv *, jclass, jlong window, jlong monitor, jint xpos, jint ypos, jint width, jint height,
         jint refreshRate) {
    glfwSetWindowMonitor((GLFWwindow *) window, (GLFWmonitor *) monitor, xpos, ypos, width, height, refreshRate);
}

[[maybe_unused]] JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowAttrib
        (JNIEnv *, jclass, jlong window, jint attrib) {
    return glfwGetWindowAttrib((GLFWwindow *) window, attrib);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowAttrib
        (JNIEnv *, jclass, jlong window, jint attrib, jint value) {
    glfwSetWindowAttrib((GLFWwindow *) window, attrib, value);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowUserPointer
        (JNIEnv *, jclass, jlong window, jlong pointer) {
    glfwSetWindowUserPointer((GLFWwindow *) window, (void *) pointer);
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowUserPointer
        (JNIEnv *, jclass, jlong window) {
    return (jlong) glfwGetWindowUserPointer((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSwapBuffers
        (JNIEnv *, jclass, jlong window) {
    glfwSwapBuffers((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwInit
        (JNIEnv *, jclass) {
    return glfwInit();
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwTerminate
        (JNIEnv *, jclass) {
    glfwTerminate();
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwInitHint
        (JNIEnv *, jclass, jint hint, jint value) {
    glfwInitHint(hint, value);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetVersion
        (JNIEnv *env, jclass, jintArray jmajorArr, jintArray jminorArr, jintArray jrevArr) {
    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);
    jint jmajor = major, jminor = minor, jrev = rev;
    if (CHECK_JARRAY_LENGTH(jmajorArr)) { env->SetIntArrayRegion(jmajorArr, 0, 1, &jmajor); }
    if (CHECK_JARRAY_LENGTH(jminorArr)) { env->SetIntArrayRegion(jminorArr, 0, 1, &jminor); }
    if (CHECK_JARRAY_LENGTH(jrevArr)) { env->SetIntArrayRegion(jrevArr, 0, 1, &jrev); }
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetVersionString
        (JNIEnv *env, jclass) {
    return env->NewStringUTF(glfwGetVersionString());
}

[[maybe_unused]] JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetError
        (JNIEnv *env, jclass, jobjectArray jdescArr) {
    if (CHECK_JARRAY_LENGTH(jdescArr)) {
        const char *description;
        int code = glfwGetError(&description);
        if (description) {
            env->SetObjectArrayElement(jdescArr, 0, env->NewStringUTF(description));
        } else {
            env->SetObjectArrayElement(jdescArr, 0, nullptr);
        }
        return code;
    } else {
        return glfwGetError(nullptr);
    }
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwDefaultWindowHints
        (JNIEnv *, jclass) {
    glfwDefaultWindowHints();
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWindowHint
        (JNIEnv *, jclass, jint hint, jint value) {
    glfwWindowHint(hint, value);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWindowHintString
        (JNIEnv *env, jclass, jint hint, jstring jvalue) {
    const char *value = env->GetStringUTFChars(jvalue, nullptr);
    glfwWindowHintString(hint, value);
    env->ReleaseStringUTFChars(jvalue, value);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwPollEvents
        (JNIEnv *, jclass) {
    glfwPollEvents();
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWaitEvents
        (JNIEnv *, jclass) {
    glfwWaitEvents();
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWaitEventsTimeout
        (JNIEnv *, jclass, jdouble timeout) {
    glfwWaitEventsTimeout(timeout);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwPostEmptyEvent
        (JNIEnv *, jclass) {
    glfwPostEmptyEvent();
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWin32Adapter
        (JNIEnv *env, jclass, jlong monitor) {
    return env->NewStringUTF(glfwGetWin32Adapter((GLFWmonitor *) monitor));
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWin32Monitor
        (JNIEnv *env, jclass, jlong monitor) {
    return env->NewStringUTF(glfwGetWin32Monitor((GLFWmonitor *) monitor));
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWin32Window
        (JNIEnv *, jclass, jlong window) {
    return (jlong) glfwGetWin32Window((GLFWwindow *) window);
}

[[maybe_unused]] JNIEXPORT jlongArray JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMonitors
        (JNIEnv *env, jclass) {
    int count;
    GLFWmonitor **monitors = glfwGetMonitors(&count);
    if (!monitors || count <= 0) {
        return nullptr;
    }
    jlongArray pointers = env->NewLongArray((jsize) count);
    env->SetLongArrayRegion(pointers, 0, count, (jlong *) monitors);
    return pointers;
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetPrimaryMonitor
        (JNIEnv *, jclass) {
    return (jlong) glfwGetPrimaryMonitor();
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMonitorPos
        (JNIEnv *env, jclass, jlong monitor, jintArray jxposArr, jintArray jyposArr) {
    int xpos, ypos;
    glfwGetMonitorPos((GLFWmonitor *) monitor, &xpos, &ypos);
    jint jxpos = xpos, jypos = ypos;
    if (CHECK_JARRAY_LENGTH(jxposArr)) env->SetIntArrayRegion(jxposArr, 0, 1, &jxpos);
    if (CHECK_JARRAY_LENGTH(jyposArr)) env->SetIntArrayRegion(jyposArr, 0, 1, &jypos);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMonitorWorkarea
        (JNIEnv *env, jclass, jlong monitor, jintArray jxposArr, jintArray jyposArr, jintArray jwidthArr,
         jintArray jheightArr) {
    int xpos, ypos, width, height;
    glfwGetMonitorWorkarea((GLFWmonitor *) monitor, &xpos, &ypos, &width, &height);
    jint jxpos = xpos, jypos = ypos, jwidth = width, jheight = height;
    if (CHECK_JARRAY_LENGTH(jxposArr)) { env->SetIntArrayRegion(jxposArr, 0, 1, &jxpos); }
    if (CHECK_JARRAY_LENGTH(jyposArr)) { env->SetIntArrayRegion(jyposArr, 0, 1, &jypos); }
    if (CHECK_JARRAY_LENGTH(jwidthArr)) { env->SetIntArrayRegion(jwidthArr, 0, 1, &jwidth); }
    if (CHECK_JARRAY_LENGTH(jheightArr)) { env->SetIntArrayRegion(jheightArr, 0, 1, &jheight); }
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMonitorPhysicalSize
        (JNIEnv *env, jclass, jlong monitor, jintArray jwidthMMarr, jintArray jheightMMarr) {
    int widthMM, heightMM;
    glfwGetMonitorPhysicalSize((GLFWmonitor *) monitor, &widthMM, &heightMM);
    jint jwidthMM = widthMM, jheightMM = heightMM;
    if (CHECK_JARRAY_LENGTH(jwidthMMarr)) env->SetIntArrayRegion(jwidthMMarr, 0, 1, &jwidthMM);
    if (CHECK_JARRAY_LENGTH(jheightMMarr)) env->SetIntArrayRegion(jheightMMarr, 0, 1, &jheightMM);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMonitorContentScale
        (JNIEnv *env, jclass, jlong monitor, jfloatArray jxscale, jfloatArray jyscale) {
    float xscale, yscale;
    glfwGetMonitorContentScale((GLFWmonitor *) monitor, &xscale, &yscale);
    if (CHECK_JARRAY_LENGTH(jxscale)) env->SetFloatArrayRegion(jxscale, 0, 1, &xscale);
    if (CHECK_JARRAY_LENGTH(jyscale)) env->SetFloatArrayRegion(jyscale, 0, 1, &yscale);
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMonitorName
        (JNIEnv *env, jclass, jlong monitor) {
    return env->NewStringUTF(glfwGetMonitorName((GLFWmonitor *) monitor));
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetMonitorUserPointer
        (JNIEnv *, jclass, jlong monitor, jlong pointer) {
    glfwSetMonitorUserPointer((GLFWmonitor *) monitor, (void *) pointer);
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMonitorUserPointer
        (JNIEnv *, jclass, jlong monitor) {
    return (jlong) glfwGetMonitorUserPointer((GLFWmonitor *) monitor);
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetVideoModes
        (JNIEnv *env, jclass, jlong monitor, jintArray jcountArr) {
    int count;
    const GLFWvidmode *vidmodes = glfwGetVideoModes((GLFWmonitor *) monitor, &count);
    if (!vidmodes || count <= 0) {
        return 0;
    }
    jint jcount = count;
    if (CHECK_JARRAY_LENGTH(jcountArr)) env->SetIntArrayRegion(jcountArr, 0, 1, &jcount);
    return (jlong) vidmodes;
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetVideoMode
        (JNIEnv *, jclass, jlong monitor) {
    return (jlong) glfwGetVideoMode((GLFWmonitor *) monitor);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetGamma
        (JNIEnv *, jclass, jlong monitor, jfloat gamma) {
    glfwSetGamma((GLFWmonitor *) monitor, gamma);
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetGammaRamp
        (JNIEnv *, jclass, jlong monitor) {
    return (jlong) glfwGetGammaRamp((GLFWmonitor *) monitor);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetGammaRamp
        (JNIEnv *env, jclass, jlong monitor, jshortArray red, jshortArray green, jshortArray blue) {
    size_t size = env->GetArrayLength(red);
    GLFWgammaramp gammaramp{};
    gammaramp.size = (unsigned) size;
    gammaramp.red = (unsigned short *) env->GetShortArrayElements(red, nullptr);
    gammaramp.green = (unsigned short *) env->GetShortArrayElements(green, nullptr);
    gammaramp.blue = (unsigned short *) env->GetShortArrayElements(blue, nullptr);
    glfwSetGammaRamp((GLFWmonitor *) monitor, &gammaramp);
    env->ReleaseShortArrayElements(red, (short *) gammaramp.red, 0);
    env->ReleaseShortArrayElements(green, (short *) gammaramp.green, 0);
    env->ReleaseShortArrayElements(blue, (short *) gammaramp.blue, 0);
}

[[maybe_unused]] JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetInputMode
        (JNIEnv *, jclass, jlong window, jint mode) {
    return glfwGetInputMode((GLFWwindow *) window, mode);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetInputMode
        (JNIEnv *, jclass, jlong window, jint mode, jint value) {
    glfwSetInputMode((GLFWwindow *) window, mode, value);
}

[[maybe_unused]] JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetKey
        (JNIEnv *, jclass, jlong window, jint key) {
    return glfwGetKey((GLFWwindow *) window, key);
}

[[maybe_unused]] JNIEXPORT jboolean JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetMouseButton
        (JNIEnv *, jclass, jlong window, jint button) {
    return glfwGetMouseButton((GLFWwindow *) window, button);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetCursorPos
        (JNIEnv *env, jclass, jlong window, jdoubleArray jxpos, jdoubleArray jypos) {
    double xpos, ypos;
    glfwGetCursorPos((GLFWwindow *) window, &xpos, &ypos);
    if (CHECK_JARRAY_LENGTH(jxpos)) env->SetDoubleArrayRegion(jxpos, 0, 1, &xpos);
    if (CHECK_JARRAY_LENGTH(jypos)) env->SetDoubleArrayRegion(jypos, 0, 1, &ypos);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetCursorPos
        (JNIEnv *, jclass, jlong window, jdouble xpos, jdouble ypos) {
    glfwSetCursorPos((GLFWwindow *) window, xpos, ypos);
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwCreateCursor
        (JNIEnv *env, jclass, jint width, jint height, jbyteArray jpixels, jint xhot, jint yhot) {
    GLFWimage image{};
    image.width = width;
    image.height = height;
    jbyte *pixels = env->GetByteArrayElements(jpixels, nullptr);
    image.pixels = (unsigned char *) pixels;
    GLFWcursor *cursor = glfwCreateCursor(&image, xhot, yhot);
    env->ReleaseByteArrayElements(jpixels, pixels, 0);
    return (jlong) cursor;
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwCreateStandardCursor
        (JNIEnv *, jclass, jint shape) {
    return (jlong) glfwCreateStandardCursor(shape);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwDestroyCursor
        (JNIEnv *, jclass, jlong cursor) {
    glfwDestroyCursor((GLFWcursor *) cursor);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetCursor
        (JNIEnv *, jclass, jlong window, jlong cursor) {
    glfwSetCursor((GLFWwindow *) window, (GLFWcursor *) cursor);
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetJoystickUserPointer
        (JNIEnv *, jclass, jint jid, jlong pointer) {
    glfwSetJoystickUserPointer(jid, (void *) pointer);
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetJoystickUserPointer
        (JNIEnv *, jclass, jint jid) {
    return (jlong) glfwGetJoystickUserPointer(jid);
}

[[maybe_unused]] JNIEXPORT jboolean JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetGamepadState
        (JNIEnv *env, jclass, jint jid, jbooleanArray buttons, jfloatArray axes) {
    GLFWgamepadstate gamepad;
    int result = glfwGetGamepadState(jid, &gamepad);
    if (!result) {
        return false;
    }
    env->SetBooleanArrayRegion(buttons, 0, 15, gamepad.buttons);
    env->SetFloatArrayRegion(axes, 0, 6, gamepad.axes);
    return true;
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetClipboardString
        (JNIEnv *env, jclass, jlong window, jstring jstring) {
    const char *string = env->GetStringUTFChars(jstring, nullptr);
    glfwSetClipboardString((GLFWwindow *) window, string);
    env->ReleaseStringUTFChars(jstring, string);
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetClipboardString
        (JNIEnv *env, jclass, jlong window) {
    return env->NewStringUTF(glfwGetClipboardString((GLFWwindow *) window));
}

[[maybe_unused]] JNIEXPORT jboolean JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwRawMouseMotionSupported
        (JNIEnv *, jclass) {
    return glfwRawMouseMotionSupported();
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetKeyName
        (JNIEnv *env, jclass, jint key, jint scancode) {
    return env->NewStringUTF(glfwGetKeyName(key, scancode));
}

[[maybe_unused]] JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetKeyScancode
        (JNIEnv *, jclass, jint key) {
    return glfwGetKeyScancode(key);
}

[[maybe_unused]] JNIEXPORT jboolean JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwJoystickPresent
        (JNIEnv *, jclass, jint jid) {
    return glfwJoystickPresent(jid);
}

[[maybe_unused]] JNIEXPORT jfloatArray JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetJoystickAxes
        (JNIEnv *env, jclass, jint jid) {
    int count;
    const float *axes = glfwGetJoystickAxes(jid, &count);
    if (!axes) {
        return nullptr;
    }
    jfloatArray axesArr = env->NewFloatArray(count);
    env->SetFloatArrayRegion(axesArr, 0, count, axes);
    return axesArr;
}

[[maybe_unused]] JNIEXPORT jbyteArray JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetJoystickButtons
        (JNIEnv *env, jclass, jint jid) {
    int count;
    const unsigned char *buttons = glfwGetJoystickButtons(jid, &count);
    if (!buttons) {
        return nullptr;
    }
    jbyteArray buttonsArr = env->NewByteArray(count);
    env->SetByteArrayRegion(buttonsArr, 0, count, (const jbyte *) buttons);
    return buttonsArr;
}

[[maybe_unused]] JNIEXPORT jbyteArray JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetJoystickHats
        (JNIEnv *env, jclass, jint jid) {
    int count;
    const unsigned char *hats = glfwGetJoystickHats(jid, &count);
    if (!hats) {
        return nullptr;
    }
    jbyteArray hatsArr = env->NewByteArray(count);
    env->SetByteArrayRegion(hatsArr, 0, count, (const jbyte *) hats);
    return hatsArr;
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetJoystickName
        (JNIEnv *env, jclass, jint jid) {
    return env->NewStringUTF(glfwGetJoystickName(jid));
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetJoystickGUID
        (JNIEnv *env, jclass, jint jid) {
    return env->NewStringUTF(glfwGetJoystickGUID(jid));
}

[[maybe_unused]] JNIEXPORT jboolean JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwJoystickIsGamepad
        (JNIEnv *, jclass, jint jid) {
    return glfwJoystickIsGamepad(jid);
}

[[maybe_unused]] JNIEXPORT jboolean JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwUpdateGamepadMappings
        (JNIEnv *env, jclass, jstring jstring) {
    const char *string = env->GetStringUTFChars(jstring, nullptr);
    jboolean result = glfwUpdateGamepadMappings(string);
    env->ReleaseStringUTFChars(jstring, string);
    return result;
}

[[maybe_unused]] JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetGamepadName
        (JNIEnv *env, jclass, jint jid) {
    return env->NewStringUTF(glfwGetGamepadName(jid));
}

[[maybe_unused]] JNIEXPORT jdouble JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetTime
        (JNIEnv *, jclass) {
    return glfwGetTime();
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetTimerValue
        (JNIEnv *, jclass) {
    return (jlong) glfwGetTimerValue();
}

[[maybe_unused]] JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetTimerFrequency
        (JNIEnv *, jclass) {
    return (jlong) glfwGetTimerFrequency();
}

[[maybe_unused]] JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowIcon
        (JNIEnv *env, jclass, jlong window, jintArray jwidthsArr, jintArray jheightsArr, jobjectArray jpixelsArr) {
    int count = (int) env->GetArrayLength(jwidthsArr);
    jint *widths = env->GetIntArrayElements(jwidthsArr, nullptr);
    jint *heights = env->GetIntArrayElements(jheightsArr, nullptr);
    std::vector<jbyteArray> pixelArrays(count);
    std::vector<GLFWimage> icons(count);
    for (int i = 0; i < count; i++) {
        GLFWimage icon;
        icon.width = widths[i];
        icon.height = heights[i];
        auto pixels = (jbyteArray) env->GetObjectArrayElement(jpixelsArr, i);
        icon.pixels = (unsigned char *) env->GetByteArrayElements(pixels, nullptr);
        icons[i] = icon;
        pixelArrays[i] = pixels;
    }
    glfwSetWindowIcon((GLFWwindow *) window, count, icons.data());
    env->ReleaseIntArrayElements(jwidthsArr, widths, 0);
    env->ReleaseIntArrayElements(jheightsArr, heights, 0);
    for (int i = 0; i < count; i++) {
        env->ReleaseByteArrayElements(pixelArrays[i], (jbyte *) icons[i].pixels, 0);
    }
}

//// JAVA CALLBACKS ////

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwSetJoystickCallback
        (JNIEnv *env, jclass, jobject callback) {
    callback = env->NewGlobalRef(callback);
    LOCK_CALLBACK(GLFWjoystickfun_cb)
    CallbackDataPair &pair = CALLBACK_DATA(GLFWjoystickfun_cb);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(II)V"))
        result = (jlong) glfwSetJoystickCallback([](int jid, int event) {
            LOCK_CALLBACK(GLFWjoystickfun_cb)
            CallbackData callback = CALLBACK_DATA(GLFWjoystickfun_cb).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jint) jid, (jint) event);
            }
            UNLOCK_CALLBACK(GLFWjoystickfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetJoystickCallback(nullptr);
    }
    UNLOCK_CALLBACK(GLFWjoystickfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwSetMonitorCallback
        (JNIEnv *env, jclass, jobject callback) {
    callback = env->NewGlobalRef(callback);
    LOCK_CALLBACK(GLFWmonitorfun_cb)
    CallbackDataPair &pair = CALLBACK_DATA(GLFWmonitorfun_cb);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JI)V"))
        result = (jlong) glfwSetMonitorCallback([](GLFWmonitor *monitor, int event) {
            LOCK_CALLBACK(GLFWmonitorfun_cb)
            CallbackData callback = CALLBACK_DATA(GLFWmonitorfun_cb).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) monitor, (jint) event);
            }
            UNLOCK_CALLBACK(GLFWmonitorfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetMonitorCallback(nullptr);
    }
    UNLOCK_CALLBACK(GLFWmonitorfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwSetErrorCallback
        (JNIEnv *env, jclass, jobject callback) {
    callback = env->NewGlobalRef(callback);
    LOCK_CALLBACK(GLFWerrorfun_cb)
    CallbackDataPair &pair = CALLBACK_DATA(GLFWerrorfun_cb);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(ILjava/lang/String;)V"))
        result = (jlong) glfwSetErrorCallback([](int errorCode, const char *description) {
            LOCK_CALLBACK(GLFWerrorfun_cb)
            CallbackData callback = CALLBACK_DATA(GLFWerrorfun_cb).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jint) errorCode, callback.env->NewStringUTF(description));
            }
            UNLOCK_CALLBACK(GLFWerrorfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetErrorCallback(nullptr);
    }
    UNLOCK_CALLBACK(GLFWerrorfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowPosCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowposfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowposfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JII)V"))
        result = (jlong) glfwSetWindowPosCallback(window, [](GLFWwindow *window, int xpos, int ypos) {
            LOCK_CALLBACK(GLFWwindowposfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowposfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) xpos, (jint) ypos);
            }
            UNLOCK_CALLBACK(GLFWwindowposfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowPosCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowposfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowSizeCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowsizefun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowsizefun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JII)V"))
        result = (jlong) glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int width, int height) {
            LOCK_CALLBACK(GLFWwindowsizefun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowsizefun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) width, (jint) height);
            }
            UNLOCK_CALLBACK(GLFWwindowsizefun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowSizeCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowsizefun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowCloseCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowclosefun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowclosefun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(J)V"))
        result = (jlong) glfwSetWindowCloseCallback(window, [](GLFWwindow *window) {
            LOCK_CALLBACK(GLFWwindowclosefun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowclosefun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window);
            }
            UNLOCK_CALLBACK(GLFWwindowclosefun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowCloseCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowclosefun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowRefreshCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowrefreshfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowrefreshfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(J)V"))
        result = (jlong) glfwSetWindowRefreshCallback(window, [](GLFWwindow *window) {
            LOCK_CALLBACK(GLFWwindowrefreshfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowrefreshfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window);
            }
            UNLOCK_CALLBACK(GLFWwindowrefreshfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowRefreshCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowrefreshfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowFocusCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowfocusfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowfocusfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JI)V"))
        result = (jlong) glfwSetWindowFocusCallback(window, [](GLFWwindow *window, int focused) {
            LOCK_CALLBACK(GLFWwindowfocusfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowfocusfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) focused);
            }
            UNLOCK_CALLBACK(GLFWwindowfocusfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowFocusCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowfocusfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowIconifyCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowiconifyfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowiconifyfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JI)V"))
        result = (jlong) glfwSetWindowIconifyCallback(window, [](GLFWwindow *window, int iconified) {
            LOCK_CALLBACK(GLFWwindowiconifyfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowiconifyfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) iconified);
            }
            UNLOCK_CALLBACK(GLFWwindowiconifyfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowIconifyCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowiconifyfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowMaximizeCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowmaximizefun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowmaximizefun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JI)V"))
        result = (jlong) glfwSetWindowMaximizeCallback(window, [](GLFWwindow *window, int maximized) {
            LOCK_CALLBACK(GLFWwindowmaximizefun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowmaximizefun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) maximized);
            }
            UNLOCK_CALLBACK(GLFWwindowmaximizefun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowMaximizeCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowmaximizefun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetFramebufferSizeCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWframebuffersizefun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWframebuffersizefun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JII)V"))
        result = (jlong) glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int width, int height) {
            LOCK_CALLBACK(GLFWframebuffersizefun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWframebuffersizefun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) width, (jint) height);
            }
            UNLOCK_CALLBACK(GLFWframebuffersizefun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetFramebufferSizeCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWframebuffersizefun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowContentScaleCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowcontentscalefun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowcontentscalefun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JFF)V"))
        result = (jlong) glfwSetWindowContentScaleCallback(window, [](GLFWwindow *window, float xscale, float yscale) {
            LOCK_CALLBACK(GLFWwindowcontentscalefun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWwindowcontentscalefun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jfloat) xscale, (jfloat) yscale);
            }
            UNLOCK_CALLBACK(GLFWwindowcontentscalefun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetWindowContentScaleCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWwindowcontentscalefun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetKeyCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWkeyfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWkeyfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JIIII)V"))
        result = (jlong) glfwSetKeyCallback(window,
                                            [](GLFWwindow *window, int key, int scancode, int action, int mods) {
                                                LOCK_CALLBACK(GLFWkeyfun_cb)
                                                CallbackData callback = CALLBACK_GROUP_DATA(GLFWkeyfun_cb,
                                                                                            window).current;
                                                if (callback.isValid()) {
                                                    callback.env->CallVoidMethod(
                                                            callback.instance, callback.callback,
                                                            (jlong) window, (jint) key, (jint) scancode, (jint) action,
                                                            (jint) mods);
                                                }
                                                UNLOCK_CALLBACK(GLFWkeyfun_cb)
                                            });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetKeyCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWkeyfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetCharCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWcharfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWcharfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JI)V"))
        result = (jlong) glfwSetCharCallback(window, [](GLFWwindow *window, unsigned int codepoint) {
            LOCK_CALLBACK(GLFWcharfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWcharfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) codepoint);
            }
            UNLOCK_CALLBACK(GLFWcharfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetCharCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWcharfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetCharModsCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWcharmodsfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWcharmodsfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JII)V"))
        result = (jlong) glfwSetCharModsCallback(window, [](GLFWwindow *window, unsigned int codepoint, int mods) {
            LOCK_CALLBACK(GLFWcharmodsfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWcharmodsfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) codepoint, (jint) mods);
            }
            UNLOCK_CALLBACK(GLFWcharmodsfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetCharModsCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWcharmodsfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetMouseButtonCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWmousebuttonfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWmousebuttonfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JIII)V"))
        result = (jlong) glfwSetMouseButtonCallback(window, [](GLFWwindow *window, int button, int action, int mods) {
            LOCK_CALLBACK(GLFWmousebuttonfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWmousebuttonfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) button, (jint) action, (jint) mods);
            }
            UNLOCK_CALLBACK(GLFWmousebuttonfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetMouseButtonCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWmousebuttonfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetCursorPosCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWcursorposfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWcursorposfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JDD)V"))
        result = (jlong) glfwSetCursorPosCallback(window, [](GLFWwindow *window, double xpos, double ypos) {
            LOCK_CALLBACK(GLFWcursorposfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWcursorposfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jdouble) xpos, (jdouble) ypos);
            }
            UNLOCK_CALLBACK(GLFWcursorposfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetCursorPosCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWcursorposfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetCursorEnterCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWcursorenterfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWcursorenterfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JI)V"))
        result = (jlong) glfwSetCursorEnterCallback(window, [](GLFWwindow *window, int entered) {
            LOCK_CALLBACK(GLFWcursorenterfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWcursorenterfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jint) entered);
            }
            UNLOCK_CALLBACK(GLFWcursorenterfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetCursorEnterCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWcursorenterfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetScrollCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWscrollfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWscrollfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JDD)V"))
        result = (jlong) glfwSetScrollCallback(window, [](GLFWwindow *window, double xoffset, double yoffset) {
            LOCK_CALLBACK(GLFWscrollfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWscrollfun_cb, window).current;
            if (callback.isValid()) {
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, (jdouble) xoffset, (jdouble) yoffset);
            }
            UNLOCK_CALLBACK(GLFWscrollfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetScrollCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWscrollfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

[[maybe_unused]] JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetDropCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWdropfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWdropfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(J[Ljava/lang/String;)V"))
        result = (jlong) glfwSetDropCallback(window, [](GLFWwindow *window, int pathCount, const char *paths[]) {
            LOCK_CALLBACK(GLFWdropfun_cb)
            CallbackData callback = CALLBACK_GROUP_DATA(GLFWdropfun_cb, window).current;
            if (callback.isValid()) {
                jobjectArray jpaths = callback.env->NewObjectArray(pathCount,
                                                                   callback.env->FindClass("java/lang/String"),
                                                                   nullptr);
                for (int i = 0; i < pathCount; i++) {
                    callback.env->SetObjectArrayElement(jpaths, i, callback.env->NewStringUTF(paths[i]));
                }
                callback.env->CallVoidMethod(
                        callback.instance, callback.callback,
                        (jlong) window, jpaths);
                callback.env->DeleteLocalRef(jpaths);
            }
            UNLOCK_CALLBACK(GLFWdropfun_cb)
        });
    } else {
        CALLBACK_SET(pair, {})
        result = (jlong) glfwSetDropCallback(window, nullptr);
    }
    UNLOCK_CALLBACK(GLFWdropfun_cb)
    if (!result) {
        return nullptr;
    }
    return pair.old;
}