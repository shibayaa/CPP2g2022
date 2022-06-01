#include <iostream>
using namespace std;

// PtrClassクラスの定義と実装
class PtrClass {
  public:
    int *ptr;	// ポインタのメンバ変数

    // コンストラクタ
    PtrClass() {
      cout << "コンストラクタが呼び出されました。" << endl;
      this->ptr = new int[3];
    }

    // デストラクタ
    ~PtrClass() {
      cout << "デストラクタが呼び出されました。" << endl;
      delete[] ptr;
    }
};

// main関数
int main() {
  // PtrClassクラスのオブジェクトobj1を生成する
  PtrClass obj1;
  obj1.ptr[0] = 123;
  obj1.ptr[1] = 456;
  obj1.ptr[2] = 789;

  // obj1をコピーしてobj2を生成する
  PtrClass obj2 = obj1;

  // メンバ変数ptrの値とptrが指し示している配列の要素の値を表示する
  cout << "----------------------------------------" << endl;
  cout << "obj1のメンバ変数ptrの値：" << obj1.ptr << endl;
  cout << "obj1.ptr[0]の値：" << obj1.ptr[0] << endl;
  cout << "obj1.ptr[1]の値：" << obj1.ptr[1] << endl;
  cout << "obj1.ptr[2]の値：" << obj1.ptr[2] << endl;
  cout << "----------------------------------------" << endl;
  cout << "obj2のメンバ変数ptrの値：" << obj2.ptr << endl;
  cout << "obj2.ptr[0]の値：" << obj2.ptr[0] << endl;
  cout << "obj2.ptr[1]の値：" << obj2.ptr[1] << endl;
  cout << "obj2.ptr[2]の値：" << obj2.ptr[2] << endl;
  cout << "----------------------------------------" << endl;

  return 0;
}
