#include <iostream>
#include <string>
using namespace std;
#include "Account.h"

int main() {
  // 新たな口座を開設する
  Account act("12345678", 10000);

  // 口座番号と残高を表示する
  cout << "口座番号：" << act.getNumber();
  cout << ", 残高 " << act.getBalance() << endl;

  // 残高を更新する
  act.setBalance(30000);

  // 口座番号と残高を表示する
  cout << "口座番号：" << act.getNumber();
  cout << ", 残高 " << act.getBalance() << endl;

  // マイナスの値で残高を更新する
  act.setBalance(-20000);

  // 口座番号と残高を表示する
  cout << "口座番号：" << act.getNumber();
  cout << ", 残高 " << act.getBalance() << endl;

  return 0;
}
