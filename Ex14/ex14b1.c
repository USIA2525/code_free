#include <stdio.h>
#include <stdlib.h>

#define MAX 12

int bmi_hantei(double);

int main(){
    int j, p, count_s = 0, count_all = 0, tag;
    double data_cm[MAX];
    double data_kg[MAX];
    double bmi[MAX];
    double cm, kg;

    printf("身長(cm)と体重(kg)を空白で区切って入力してください。\n入力可能な最大の人数は 12 人です。\n");

    for(j = 0; j < MAX; j++){
        if (scanf("%lf %lf", &cm, &kg) != 2) {
            break;
        }
        data_cm[j] = cm;
        data_kg[j] = kg;
        bmi[j] = data_kg[j] / ((data_cm[j] / 100.0) * (data_cm[j] / 100.0));
        count_all++;
    }
  
    if (count_all == 0) {
        return 0;
    }

    printf("\tBMI  肥満度分類\n");
    for(j = 0; j < count_all; j++){
        tag = bmi_hantei(bmi[j]);
        if(tag == -1){
            printf("%2d 人目 %0.1f 低体重\n", j + 1, bmi[j]);
        }
        else if(tag == 0){
            printf("%2d 人目 %0.1f 普通体重\n", j + 1, bmi[j]);
            count_s++;
        }
        else if(tag == 1){
            printf("%2d 人目 %0.1f 肥満（1度）\n", j + 1, bmi[j]);
        }
        else if(tag == 2){
            printf("%2d 人目 %0.1f 肥満（2度）\n", j + 1, bmi[j]);
        }
        else if(tag == 3){
            printf("%2d 人目 %0.1f 肥満（3度）\n", j + 1, bmi[j]);
        }
        else if(tag == 4){
            printf("%2d 人目 %0.1f 肥満（4度）\n", j + 1, bmi[j]);
        }
    }
  
    p = (count_s * 200 + count_all) / (count_all * 2);
 
    printf("肥満度分類が普通体重である人の割合は %d パーセントです。\n", p);

    return 0;
}

int bmi_hantei(double bmi_c){
    int tag;
    if(bmi_c < 18.5){
        tag = -1;
    }
    else if(18.5 <= bmi_c && bmi_c < 25){
        tag = 0;
    }
    else if(25 <= bmi_c && bmi_c < 30){
        tag = 1;
    }
    else if(30 <= bmi_c && bmi_c < 35){
        tag = 2;
    }
    else if(35 <= bmi_c && bmi_c < 40){
        tag = 3;
    }
    else{
        tag = 4;
    }
    return tag;
}
