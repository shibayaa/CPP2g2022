#include <iostream>
#include <string>
using namespace std;
#include "Account.h"
#include "AccountEx.h"

// 口座名義人を返すメンバ関数の実装
string AccountEx::getName() {
  return this->name;
}

// コンストラクタの実装
AccountEx::AccountEx(string number, string name, int balance) 
  : Account(number, balance) ,name(name) {
  //this->name = name;
}
