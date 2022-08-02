#include <jni/com_jnngl_dx4j_glfw_GLFW.h>
#include <GLFW/glfw3.h>
#include <callback_utils.h>

#define CHECK_JARRAY_LENGTH(x) x && env->GetArrayLength(x) > 0

DECL_CALLBACK(GLFWerrorfun_cb)
DECL_CALLBACK_GROUP(GLFWwindow*, GLFWwindowposfun_cb)

JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwCreateWindow
        (JNIEnv *env, jclass, jint width, jint height, jstring jtitle, jlong monitor, jlong share) {
    const char *title = env->GetStringUTFChars(jtitle, nullptr);
    GLFWwindow *window = glfwCreateWindow(width, height, title, (GLFWmonitor *) monitor, (GLFWwindow *) share);
    env->ReleaseStringUTFChars(jtitle, title);
    return (jlong) window;
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwDestroyWindow
        (JNIEnv *, jclass, jlong window) {
    glfwDestroyWindow((GLFWwindow *) window);
}

JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwWindowShouldClose
        (JNIEnv *, jclass, jlong window) {
    return glfwWindowShouldClose((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowShouldClose
        (JNIEnv *, jclass, jlong window, jint value) {
    glfwSetWindowShouldClose((GLFWwindow *) window, value);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowTitle
        (JNIEnv *env, jclass, jlong window, jstring jtitle) {
    const char *title = env->GetStringUTFChars(jtitle, nullptr);
    glfwSetWindowTitle((GLFWwindow *) window, title);
    env->ReleaseStringUTFChars(jtitle, title);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowPos
        (JNIEnv *env, jclass, jlong window, jintArray jxposArr, jintArray jyposArr) {
    int xpos, ypos;
    glfwGetWindowPos((GLFWwindow *) window, &xpos, &ypos);
    jint jxpos = xpos, jypos = ypos;
    if (CHECK_JARRAY_LENGTH(jxposArr)) { env->SetIntArrayRegion(jxposArr, 0, 1, &jxpos); }
    if (CHECK_JARRAY_LENGTH(jyposArr)) { env->SetIntArrayRegion(jyposArr, 0, 1, &jypos); }
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowPos
        (JNIEnv *, jclass, jlong window, jint xpos, jint ypos) {
    glfwSetWindowPos((GLFWwindow *) window, xpos, ypos);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowSize
        (JNIEnv *env, jclass, jlong window, jintArray jwidthArr, jintArray jheightArr) {
    int width, height;
    glfwGetWindowSize((GLFWwindow *) window, &width, &height);
    jint jwidth = width, jheight = height;
    if (CHECK_JARRAY_LENGTH(jwidthArr)) { env->SetIntArrayRegion(jwidthArr, 0, 1, &jwidth); }
    if (CHECK_JARRAY_LENGTH(jheightArr)) { env->SetIntArrayRegion(jheightArr, 0, 1, &jheight); }
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowSizeLimits
        (JNIEnv *, jclass, jlong window, jint minwidth, jint minheight, jint maxwidth, jint maxheight) {
    glfwSetWindowSizeLimits((GLFWwindow *) window, minwidth, minheight, maxwidth, maxheight);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowAspectRatio
        (JNIEnv *, jclass, jlong window, jint numer, jint denom) {
    glfwSetWindowAspectRatio((GLFWwindow *) window, numer, denom);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowSize
        (JNIEnv *, jclass, jlong window, jint width, jint height) {
    glfwSetWindowSize((GLFWwindow *) window, width, height);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetFramebufferSize
        (JNIEnv *env, jclass, jlong window, jintArray jwidthArr, jintArray jheightArr) {
    int width, height;
    glfwGetFramebufferSize((GLFWwindow *) window, &width, &height);
    jint jwidth = width, jheight = height;
    if (CHECK_JARRAY_LENGTH(jwidthArr)) { env->SetIntArrayRegion(jwidthArr, 0, 1, &jwidth); }
    if (CHECK_JARRAY_LENGTH(jheightArr)) { env->SetIntArrayRegion(jheightArr, 0, 1, &jheight); }
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowFrameSize
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

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowContentScale
        (JNIEnv *env, jclass, jlong window, jfloatArray jxscaleArr, jfloatArray jyscaleArr) {
    float xscale, yscale;
    glfwGetWindowContentScale((GLFWwindow *) window, &xscale, &yscale);
    if (CHECK_JARRAY_LENGTH(jxscaleArr)) { env->SetFloatArrayRegion(jxscaleArr, 0, 1, &xscale); }
    if (CHECK_JARRAY_LENGTH(jyscaleArr)) { env->SetFloatArrayRegion(jyscaleArr, 0, 1, &yscale); }
}

JNIEXPORT jfloat JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowOpacity
        (JNIEnv *, jclass, jlong window) {
    return glfwGetWindowOpacity((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowOpacity
        (JNIEnv *, jclass, jlong window, jfloat opacity) {
    glfwSetWindowOpacity((GLFWwindow *) window, opacity);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwIconifyWindow
        (JNIEnv *, jclass, jlong window) {
    glfwIconifyWindow((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwRestoreWindow
        (JNIEnv *, jclass, jlong window) {
    glfwRestoreWindow((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwMaximizeWindow
        (JNIEnv *, jclass, jlong window) {
    glfwMaximizeWindow((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwShowWindow
        (JNIEnv *, jclass, jlong window) {
    glfwShowWindow((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwHideWindow
        (JNIEnv *, jclass, jlong window) {
    glfwHideWindow((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwFocusWindow
        (JNIEnv *, jclass, jlong window) {
    glfwFocusWindow((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwRequestWindowAttention
        (JNIEnv *, jclass, jlong window) {
    glfwRequestWindowAttention((GLFWwindow *) window);
}

JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowMonitor
        (JNIEnv *, jclass, jlong window) {
    return (jlong) glfwGetWindowMonitor((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowMonitor
        (JNIEnv *, jclass, jlong window, jlong monitor, jint xpos, jint ypos, jint width, jint height,
         jint refreshRate) {
    glfwSetWindowMonitor((GLFWwindow *) window, (GLFWmonitor *) monitor, xpos, ypos, width, height, refreshRate);
}

JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowAttrib
        (JNIEnv *, jclass, jlong window, jint attrib) {
    return glfwGetWindowAttrib((GLFWwindow *) window, attrib);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowAttrib
        (JNIEnv *, jclass, jlong window, jint attrib, jint value) {
    glfwSetWindowAttrib((GLFWwindow *) window, attrib, value);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowUserPointer
        (JNIEnv *, jclass, jlong window, jlong pointer) {
    glfwSetWindowUserPointer((GLFWwindow *) window, (void *) pointer);
}

JNIEXPORT jlong JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwGetWindowUserPointer
        (JNIEnv *, jclass, jlong window) {
    return (jlong) glfwGetWindowUserPointer((GLFWwindow *) window);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSwapBuffers
        (JNIEnv *, jclass, jlong window) {
    glfwSwapBuffers((GLFWwindow *) window);
}

JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwInit
        (JNIEnv *, jclass) {
    return glfwInit();
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwTerminate
        (JNIEnv *, jclass) {
    glfwTerminate();
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwInitHint
        (JNIEnv *, jclass, jint hint, jint value) {
    glfwInitHint(hint, value);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetVersion
        (JNIEnv *env, jclass, jintArray jmajorArr, jintArray jminorArr, jintArray jrevArr) {
    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);
    jint jmajor = major, jminor = minor, jrev = rev;
    if (CHECK_JARRAY_LENGTH(jmajorArr)) { env->SetIntArrayRegion(jmajorArr, 0, 1, &jmajor); }
    if (CHECK_JARRAY_LENGTH(jminorArr)) { env->SetIntArrayRegion(jminorArr, 0, 1, &jminor); }
    if (CHECK_JARRAY_LENGTH(jrevArr)) { env->SetIntArrayRegion(jrevArr, 0, 1, &jrev); }
}

JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetVersionString
        (JNIEnv *env, jclass) {
    return env->NewStringUTF(glfwGetVersionString());
}

JNIEXPORT jint JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwGetError
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

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwDefaultWindowHints
        (JNIEnv *, jclass) {
    glfwDefaultWindowHints();
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWindowHint
        (JNIEnv *, jclass, jint hint, jint value) {
    glfwWindowHint(hint, value);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWindowHintString
        (JNIEnv *env, jclass, jint hint, jstring jvalue) {
    const char *value = env->GetStringUTFChars(jvalue, nullptr);
    glfwWindowHintString(hint, value);
    env->ReleaseStringUTFChars(jvalue, value);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwPollEvents
        (JNIEnv *, jclass) {
    glfwPollEvents();
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWaitEvents
        (JNIEnv *, jclass) {
    glfwWaitEvents();
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwWaitEventsTimeout
        (JNIEnv *, jclass, jdouble timeout) {
    glfwWaitEventsTimeout(timeout);
}

JNIEXPORT void JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwPostEmptyEvent
        (JNIEnv *, jclass) {
    glfwPostEmptyEvent();
}

//// JAVA CALLBACKS ////

JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_glfwSetErrorCallback
        (JNIEnv *env, jclass, jobject callback) {
    callback = env->NewGlobalRef(callback);
    LOCK_CALLBACK(GLFWerrorfun_cb)
    CallbackDataPair &pair = CALLBACK_DATA(GLFWerrorfun_cb);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(ILjava/lang/String;)V"))
        UNLOCK_CALLBACK(GLFWerrorfun_cb)
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
        UNLOCK_CALLBACK(GLFWerrorfun_cb)
        result = (jlong) glfwSetErrorCallback(nullptr);
    }
    if (!result) {
        return nullptr;
    }
    return pair.old;
}

JNIEXPORT jobject JNICALL Java_com_jnngl_dx4j_glfw_GLFW_nglfwSetWindowPosCallback
        (JNIEnv *env, jclass, jlong address, jobject callback) {
    callback = env->NewGlobalRef(callback);
    auto *window = (GLFWwindow *) address;
    LOCK_CALLBACK(GLFWwindowposfun_cb)
    CallbackDataPair &pair = CALLBACK_GROUP_DATA(GLFWwindowposfun_cb, window);
    jlong result;
    if (callback) {
        CALLBACK_SET(pair, INIT_CALLBACK_DATA(callback, "invoke", "(JII)V"))
        UNLOCK_CALLBACK(GLFWwindowposfun_cb)
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
        UNLOCK_CALLBACK(GLFWwindowposfun_cb)
        result = (jlong) glfwSetWindowPosCallback(window, nullptr);
    }
    if (!result) {
        return nullptr;
    }
    return pair.old;
}