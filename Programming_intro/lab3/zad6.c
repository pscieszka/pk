#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<float.h>
int main()
{
printf("Short_max=%hi\n",SHRT_MAX);
printf("Int_max=%d\n",INT_MAX);
printf("Float_max=%f\n",FLT_MAX);
float f=pow(2,-149);
printf("Float_min wiekszy od zera=%.50f\n",f);
}
