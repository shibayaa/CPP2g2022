#include <iostream>
using namespace std;
#include "Counter.h"

int main() {
  // 10個のカウンタを生成する
  Counter cnt[10];

  // 3番を2回アップする
  cnt[3].upVal();
  cnt[3].upVal();

  // 5番を4回アップする
  cnt[5].upVal();
  cnt[5].upVal();
  cnt[5].upVal();
  cnt[5].upVal();

  // それぞれの値を画面に表示する
  cout << "3番のカウンタの値 = " << cnt[3].getVal() << endl;
  cout << "5番のカウンタの値 = " << cnt[5].getVal() << endl;

  return 0;
}
