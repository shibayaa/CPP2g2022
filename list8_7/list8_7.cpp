#include <iostream>
using namespace std;

// PtrClassクラスの定義と実装
class PtrClass {
public:
    int* ptr;	// ポインタのメンバ変数

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

    // 独自の代入演算子のオーバーロード
    //PtrClass& operator=(const PtrClass& obj) {
    //    cout << "代入演算子のオーバーロードが呼び出されました。" << endl;
    //    this->ptr[0] = obj.ptr[0];
    //    this->ptr[1] = obj.ptr[1];
    //    this->ptr[2] = obj.ptr[2];
    //    return *this;
    //}
    // コピーコンストラクタ
    PtrClass(const PtrClass& obj) {
        cout << "コピーコンストラクタが呼び出されました。" << endl;
        this->ptr = new int[3];
        this->ptr[0] = obj.ptr[0];
        this->ptr[1] = obj.ptr[1];
        this->ptr[2] = obj.ptr[2];
    }
};

// main関数
int main() {
    // PtrClassクラスのオブジェクトobj1を生成する
    PtrClass obj1;
    obj1.ptr[0] = 123;
    obj1.ptr[1] = 456;
    obj1.ptr[2] = 789;

    // PtrClassクラスのオブジェクトobj2を生成する
    PtrClass obj2;
    obj2.ptr[0] = 111;
    obj2.ptr[1] = 222;
    obj2.ptr[2] = 333;
    cout << "----------------------------------------" << endl;
    cout << "obj2のメンバ変数ptrの値（代入前）：" << obj2.ptr << endl;
    cout << "obj2.ptr[0]の値：" << obj2.ptr[0] << endl;
    cout << "obj2.ptr[1]の値：" << obj2.ptr[1] << endl;
    cout << "obj2.ptr[2]の値：" << obj2.ptr[2] << endl;
    cout << "----------------------------------------" << endl;

    // obj2にobj1を代入する
    obj2 = obj1;

    // メンバ変数ptrの値とptrが指し示している配列の要素の値を表示する
    cout << "----------------------------------------" << endl;
    cout << "obj1のメンバ変数ptrの値：" << obj1.ptr << endl;
    cout << "obj1.ptr[0]の値：" << obj1.ptr[0] << endl;
    cout << "obj1.ptr[1]の値：" << obj1.ptr[1] << endl;
    cout << "obj1.ptr[2]の値：" << obj1.ptr[2] << endl;
    cout << "----------------------------------------" << endl;
    cout << "obj2のメンバ変数ptrの値（代入後）：" << obj2.ptr << endl;
    cout << "obj2.ptr[0]の値：" << obj2.ptr[0] << endl;
    cout << "obj2.ptr[1]の値：" << obj2.ptr[1] << endl;
    cout << "obj2.ptr[2]の値：" << obj2.ptr[2] << endl;
    cout << "----------------------------------------" << endl;
    // PtrClassクラスのオブジェクトobj3を生成する
    PtrClass obj3 = obj1;
    return 0;
}
