#include <jni/com_jnngl_dx4j_glfw_GLFW.h>
#include <GLFW/glfw3.h>
#include <callback_utils.h>

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

//// JAVA CALLBACKS ////

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