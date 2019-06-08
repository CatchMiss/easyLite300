package com.example.lolita.easylite;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.example.lolita.jni.MD5Utils;
import com.example.lolita.jni.ReFFTUtils;

public class MainActivity extends Activity implements View.OnClickListener {

    private static final String TAG = "MainActivity";

    private Context mComtext;
    private ReFFTUtils reFFTUtils;
    private MD5Utils md5sige;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mComtext = this;
        reFFTUtils = new ReFFTUtils();
        md5sige = new MD5Utils();

        findViewById(R.id.btn_fastMode).setOnClickListener(this);
        findViewById(R.id.btn_normalMode).setOnClickListener(this);
        findViewById(R.id.btn_standMode).setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.btn_fastMode:
                boolean ret = reFFTUtils.checkID("Java Key");
                Toast.makeText(mComtext, "chechKey: "+ret, Toast.LENGTH_LONG).show();
                break;
            case R.id.btn_normalMode:
                String md5key = md5sige.sign("my key1");
                Toast.makeText(mComtext, md5key, Toast.LENGTH_LONG).show();
                break;
            case R.id.btn_standMode:

                break;
            default:
                break;
        }
    }
}
