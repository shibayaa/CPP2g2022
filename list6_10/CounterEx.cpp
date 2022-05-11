#include "Counter.h"
#include "CounterEx.h"

// カウンタの値をダウンするメンバ関数の実装
void CounterEx::downVal() {
  this->val--;
}

// コンストラクタの実装
CounterEx::CounterEx() : Counter() {
}
