#include <jni/com_jnngl_dx4j_Dx4j.h>

JNIEXPORT jstring JNICALL Java_com_jnngl_dx4j_Dx4j_helloWorld
        (JNIEnv* env, jclass) {
    return env->NewStringUTF("Hello, world!");
}