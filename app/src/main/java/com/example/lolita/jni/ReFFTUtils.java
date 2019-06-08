package com.example.lolita.jni;

public class JNI {
    static {
        System.loadLibrary("ReFFT");
    }

    public native boolean checkID(String key);

}
