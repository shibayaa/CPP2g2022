#include <iostream>
#include<iomanip>
#include <stdlib.h>
#include"getBmi.h"
#include"getObesity.h"
using namespace std;

string obesityMessage[] =
{
    "低体重",        //[0] -1
    "普通体重",     //[1] 0
    "肥満(1度)",   //[2] 1
    "肥満(2度)",   //[3] 2
    "肥満(3度)",   //[4] 3
    "肥満(4度)",   //[5] 4
};

void testGetObesity() {
    double testBmi[] = { 18.4,18.5,18.6,24,25,26,29,30,31,34,35,36,39,40,41 };
    for (int i = 0; i < _countof(testBmi); i++) {
        cout << "BMI=" << testBmi[i] << ",肥満度=" << obesityMessage[getObesity(testBmi[i])+1] << endl;
    }
}

int main()
{
    const int STD_BMI = 22; // 標準BMI
    double height;  // 身長
    double weight;  // 体重
    double bmi = 0;    // bmi
    double stdWeight;   // 標準体重

    //キー入力をheightに格納する
    cout << "身長(cm)を入力してください";
    cin >> height;

    //キー入力をweightに格納する
    cout << "体重(kg)を入力してください";
    cin >> weight;

    // 標準体重を計算する
    stdWeight = STD_BMI * (height / 100) * (height / 100);
    bmi = getBmi(height, weight);
    int obesity = getObesity(bmi);
    // bmiを画面に表示する
    cout << "あなたのBMIは、" << fixed << setprecision(1) << bmi << "です。" << endl;
    cout << "あなたの肥満度は、" << obesityMessage[ obesity+1] << "です。" << endl;
    // 標準体重を画面に表示する
    cout << "あなたの標準体重は、" << stdWeight << "です" << endl;
    return 0;
}
