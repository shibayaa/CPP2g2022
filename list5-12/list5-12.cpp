#include <iostream>
#include <string>
using namespace std;

// ConstDestクラスの定義
class ConstDest {
private:
    string name;		// インスタンスを識別する名前
public:
    ConstDest(string name);	// コンストラクタ
    ~ConstDest();		// デストラクタ
};

// ConstDestクラスのコンストラクタの実装
ConstDest::ConstDest(string name) {
    cout << name << "のコンストラクタが呼び出されました。" << endl;
    this->name = name;
}

// ConstDestクラスのデストラクタの実装
ConstDest::~ConstDest() {
    cout << this->name << "のデストラクタが呼び出されました。" << endl;
}

// グローバルオブジェクトを宣言する
ConstDest globalObj("グローバルオブジェクト");

// sub関数
void sub() {
    cout << "sub関数が呼び出されました。" << endl;

    // ローカルオブジェクトを宣言する
    ConstDest localObj("ローカルオブジェクト");

    cout << "sub関数を終了します。" << endl;
    return;
}
// sub関数
void subNew() {
    cout << "sub関数が呼び出されました。" << endl;

    // ローカルオブジェクトを宣言する
    ConstDest* testNew= new ConstDest("ローカルNewオブジェクト");
    cout << "sub関数を終了します。" << endl;
    delete(testNew);
    return;
}



// main関数
int main() {
    cout << "main関数が呼び出されました。" << endl;

    // sub関数を呼び出す（1回目）
    sub();

    // sub関数を呼び出す（2回目）
    sub();

    ConstDest* constDest = new ConstDest("Newで作った");
    subNew();

    cout << "main関数を終了します。" << endl;
    return 0;
}
