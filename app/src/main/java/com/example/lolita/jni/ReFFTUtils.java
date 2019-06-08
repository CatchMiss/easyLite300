package com.example.lolita.jni;

public class ReFFTUtils {
    static {
        System.loadLibrary("ReFFT");
    }

    public native boolean checkID(String key);

}
