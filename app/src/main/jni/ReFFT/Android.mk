LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ReFFT
LOCAL_SRC_FILES := ReFFT.cpp
LOCAL_LDLIBS := -lm -llog

include $(BUILD_SHARED_LIBRARY)