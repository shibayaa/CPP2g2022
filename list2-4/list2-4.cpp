// list2-4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    double height;  // 身長
    double weight;  // 体重
    double bmi;    // bmi

    //キー入力をheightに格納する
    cout << "身長(m)を入力してください";
    cin >> height;

    //キー入力をweightに格納する
    cout << "体重(kg)を入力してください";
    cin >> weight;

    // 身長と体重からBMIを産出する
    bmi = weight / height / height;

    // bmiを画面に表示する
    cout << "あなたのBMIは、" << fixed << setprecision(1) << bmi << "です。" << endl;

    return 0;
}

