//
// Created by Lolita on 2019/6/08/008.
//

#include "md5.h"
#include <jni.h>
#include <string.h>
#include <stdio.h>
#include <android/log.h>
#include <malloc.h>

#define LOG_TAG "md5-jx"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_lolita_jni_MD5Utils_getMd5(JNIEnv *env, jobject obj, jstring key) {

        char* c_key = (char*)env->GetStringUTFChars(key, JNI_FALSE);

        char *ptr = (char*)malloc(strlen(c_key) + strlen(MD5_KEY)+ 10);
        //拼接的待加密字符串，可以根据自身需求修改
        sprintf(ptr, "%s%s", c_key, MD5_KEY);
        //要把日志注掉
        //LOGD("待加密字符串: %s\n", ptr);

        MD5_CTX md5_ctx = { 0 };
        MD5Init(&md5_ctx);
        MD5Update(&md5_ctx, (unsigned char*)ptr, strlen(ptr));
        unsigned char dest[16] = { 0 };
        MD5Final(dest, &md5_ctx);
        env->ReleaseStringUTFChars(key, ptr);

        int i = 0;
        char szMd5[32] = { 0 };
        for (i = 0; i < 16; i++)
        {
            sprintf(szMd5, "%s%02x", szMd5, dest[i]);
        }

        return env->NewStringUTF(szMd5);

}