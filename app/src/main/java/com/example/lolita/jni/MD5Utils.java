package com.example.lolita.jni;

import android.util.Log;

public class MD5Utils {
    static {
        System.loadLibrary("MD5");
    }

    public static String sign(String str){
        try {
            return getMd5(str);
        }catch (UnsatisfiedLinkError e){
            Log.d("md5jni签名失败", e.toString());
            return "sign error";
        }
    }

    private static native String getMd5(String key);
}
