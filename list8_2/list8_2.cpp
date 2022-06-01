#include <iostream>
using namespace std;

// MyClassクラスの定義と実装
class MyClass {
  private:
    int data;	// メンバ変数
  public:
    // メンバ変数dataの値を返すメンバ関数
    int getData() {
      return this->data;
    }

    // コンストラクタ
    MyClass(int data) {
      cout << "コンストラクタが呼び出されました。" << endl;
      this->data = data;
    }

    // デストラクタ
    ~MyClass() {
      cout << "デストラクタが呼び出されました。" << endl;
    }

    // コピーコンストラクタ
    MyClass(const MyClass &obj) {
      cout << "コピーコンストラクタが呼び出されました。" << endl;
      this->data = obj.data;
    }
};

// main関数
int main() {
  // MyClassクラスのオブジェクトobj1を生成する
  MyClass obj1(123);

  // obj1をコピーしてobj2を生成する
  MyClass obj2 = obj1;

  // メンバ変数の値を表示する
  cout << "obj1のメンバ変数dataの値：" << obj1.getData() << endl;
  cout << "obj2のメンバ変数dataの値：" << obj2.getData() << endl;

  return 0;
}
