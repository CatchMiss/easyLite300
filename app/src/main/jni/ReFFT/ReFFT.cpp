//
// Created by Lolita on 2019/6/07/007.
//
#include <jni.h>
#include <android/log.h>

#define LOG_TAG "refft-jx"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)


extern "C" JNIEXPORT jboolean JNICALL
Java_com_example_lolita_jni_ReFFTUtils_checkID(JNIEnv *env, jobject obj, jstring str)
{
    LOGD("%s", "hello from C++");
    LOGE("%s", "hello from C++");
    LOGI("%s", "hello from C++");

    const char* local_str = env->GetStringUTFChars(str, 0);
    LOGE("Lib Print from Java %s", local_str);

    jboolean ret = 1;
    return ret;
}