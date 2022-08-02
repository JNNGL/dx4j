#pragma once

#include <jni.h>

#include <map>
#include <mutex>

struct CallbackData {
    jmethodID callback = nullptr;
    jobject instance = nullptr;
    JNIEnv* env = nullptr;

    [[nodiscard]] bool isValid() const {
        return callback && instance && env;
    }
};

struct CallbackDataPair {
    jobject old;
    CallbackData current;
};

template<typename Kt_>
struct CallbackGroup {
    std::mutex mutex;
    std::map<Kt_, CallbackDataPair> data;
};

struct Callback  {
    std::mutex mutex;
    CallbackDataPair data;
};

#define DECL_CALLBACK(Cb_) static Callback Cb_;
#define DECL_CALLBACK_GROUP(Kt_, Cb_) static CallbackGroup<Kt_> Cb_;
#define CALLBACK_GROUP_DATA(Cb_, Kval_) Cb_.data[Kval_]
#define CALLBACK_DATA(Cb_) Cb_.data
#define CALLBACK_SET(Dat_, Val_) if(Dat_.old) { env->DeleteGlobalRef(Dat_.old); } Dat_.old = Dat_.current.instance; Dat_.current = Val_;
#define LOCK_CALLBACK(Cb_) Cb_.mutex.lock();
#define UNLOCK_CALLBACK(Cb_) Cb_.mutex.unlock();
#define DELETE_CALLBACK(Cb_, Kval_) LOCK_CALLBACK(Cb_, Kval_) Cb_.data.erase(Kval_); UNLOCK_CALLBACK(Cb_, Kval_)
#define INIT_CALLBACK_DATA(Inst_, Name_, Sig_) CallbackData { env->GetMethodID(env->GetObjectClass(Inst_), Name_, Sig_), Inst_, env }
