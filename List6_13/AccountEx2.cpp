#include <iostream>
#include <string>
using namespace std;
#include "Account.h"
#include "AccountEx2.h"

// 口座名義人を返すメンバ関数の実装
string AccountEx2::getName() {
  return this->name;
}

// コンストラクタの実装
AccountEx2::AccountEx2(string number, string name, int balance) 
  {
	this->name = name;
	this->account = new Account(number,balance);
}
