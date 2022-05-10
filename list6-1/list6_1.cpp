#include <iostream>
using namespace std;

// 10個のカウンタの値
int counterVal[10];

// 引数で指定されたカウンタの値を0にする関数
void resetCounterVal(int num) {
  counterVal[num] = 0;
}

// 引数で指定されたカウンタの値をアップする関数
void upCounterVal(int num) {
  counterVal[num]++;
}

// main関数
int main() {
  // 3番と5番のカウンタをリセットする
  resetCounterVal(3);
  resetCounterVal(5);

  // 3番を2回アップする
  upCounterVal(3);
  upCounterVal(3);

  // 5番を4回アップする
  upCounterVal(5);
  upCounterVal(5);
  upCounterVal(5);
  upCounterVal(5);

  // それぞれの値を画面に表示する
  cout << "3番のカウンタの値 = " << counterVal[3] << endl;
  cout << "5番のカウンタの値 = " << counterVal[5] << endl;

  return 0;
}
