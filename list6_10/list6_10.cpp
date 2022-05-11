#include <iostream>
#include <string>
using namespace std;
#include "Counter.h"
#include "CounterEx.h"

int main() {
  CounterEx cnt;
  cout << "カウンタの値 = " << cnt.getVal() << endl;

  cnt.upVal();
  cnt.upVal();
  cnt.upVal();
  cout << "カウンタの値 = " << cnt.getVal() << endl;

  cnt.downVal();
  cnt.downVal();
  cout << "カウンタの値 = " << cnt.getVal() << endl;

  Counter* cntAlias1 = &cnt;
  cntAlias1->upVal();
  //cntAlias->downVal(); //　Counterクラスとしてみているので存在しない
  
  CounterEx* cntAlias2 = &cnt;
  cntAlias2->upVal();
  cntAlias2->downVal(); //　CounterExクラスとしてみているので使える
  
  return 0;
}
