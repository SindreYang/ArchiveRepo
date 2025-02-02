
#include "audio_tools.h"
#include <math.h>
#define TINY 1.0e-23
#include "QDebug"
//dpm表函数
float getDbVal(float val)
{
  float db=20.0f * log10f(val);
  //qDebug()<<"db:"<<db;
  return db;
}

float multiplier_to_dB(float multiplier)
{
    if (multiplier == 0.) return  -1000.;//直接调到最小值
    else if (multiplier < 0.) return multiplier_to_dB(-multiplier);
    float dB = 10 * log10f(multiplier);
    return dB;
}
float  dB_to_multiplier(float  dB)
{
    if (dB == -1000.) return 0.;
    double m = pow(10., dB / 10.);
    return m;
}

float getDbPercent(float db)  {
         float def = 0.0f; /* Meter deflection %age */

//         if (db < -70.0f) {
//                 def = 0.0f;
//         } else if (db < -60.0f) {
//                 def = (db + 70.0f) * 0.25f;
//         } else if (db < -50.0f) {
//                 def = (db + 60.0f) * 0.5f + 2.5f;
//         } else if (db < -40.0f) {
//                 def = (db + 50.0f) * 0.75f + 7.5f;
//         } else if (db < -30.0f) {
//                 def = (db + 40.0f) * 1.5f + 15.0f;
//         } else if (db < -20.0f) {
//                 def = (db + 30.0f) * 2.0f + 30.0f;
//         } else {
//                 def = (db + 20.0f) * 2.5f + 50.0f;
//         }

            if (db < -70.0f) {
                def = 0.0f;//最低界
            } else if (db < -60.0f) {
                def = (db + 70.0f) * 0.25f;
            } else if (db < -50.0f) {
                def = (db + 60.0f) * 0.5f + 2.5f;
            } else if (db < -44.0f) {
                def = (db + 50.0f) * 0.75f + 7.5f;
            } else if(db < 0.0f){
                def = (db + 17.0f) * 2.0f + 66.0f;
            } else{
                def = 100.0f;//最高界
            }

         return def/100*70;
}
float hard_clip(float val, float min, float max)
{
  if (val > max)
    return max;
  if (val < min)
    return min;
  return val;
}

//dpm表函数


//jf表函数

float tau(float *x, float *y, unsigned int n)
{
       	unsigned int n2=0,n1=0,i,j;
        long is=0;
        float aa, a2, a1;

        for (i=0; i<n; i++) {
            for (j=i; j<n; j++) {
                a1 = x[i] - x[j];
                a2 = y[i] - y[j];
                aa = a1*a2;
                if (aa) {
                    ++n1;
                    ++n2;
                    aa > 0.0 ? ++is : --is;
                } else {
                    if (a1) ++n1;
                    if (a2) ++n2;
                }
            }
        }
        return is / (sqrtf((float)n1 * (float)n2) + TINY);
}

//水母表xy坐标
void trace(int columns ,int  &x, int &y){
        float bias=1.0f;
        float lp[2];
        float ring_buf[2][1024];
        for (int i=0;i<columns;i++){
                for (int j=0; j<1024;j++){
                        lp[i*2] = lp[i*2] * 0.9f + ring_buf[i*2][j] *bias * 0.1f;
                        lp[i*2+1] = lp[i*2+1] * 0.9f +ring_buf[i*2+1][j] * bias * 0.1f;

                        x = lp[i*2+1] * 80.0f * 0.707f -
                        lp[i*2] * 80.0f * 0.707f;
                        if (x > 100) {
                        x = 100;
                        } else if (x < -100) {
                        x = -100;
                        }

                        y = lp[i*2+1] * -80.0f * 0.707f +
                        lp[i*2] * -80.0f * 0.707f;
                        if (y > 99) {
                        y = 99;
                        } else if (y < -96) {
                        y = -96;
                        }
                }
        }
}
#include<stdio.h>
#include<iostream>
//水母表下的测角表
void  tay_lp(int columns,int &w,char &c ) {
        int i=columns;
        float ring_buf[columns][1024];
        float tau_lp[columns/2];
        printf("%f\n",tau_lp[columns/2]);
        tau_lp[i] = tau_lp[i] * 0.8f + tau((float *)ring_buf[i*2], (float *)ring_buf[i*2+1], 1024) * 0.2f;

        if (tau_lp[i] > 0.0f) {
                //绿色部分
                w=(int)(tau_lp[i] * 92.0f);
                c='g';
        }else {
                w = (int)(tau_lp[i] * -92.0f) + 1;
                c='r';
        }
}
// 
// audio_tools.cpp ends here
