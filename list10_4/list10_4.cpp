#include <iostream>
using namespace std;

// MyTriangleクラスの定義と実装
template <class T> class MyTriangle {
private:
    T bottom;	// 底辺
    T height;	// 高さ
public:
    // コンストラクタ
    MyTriangle(T bottom, T height) {
        this->bottom = bottom;
        this->height = height;
    }

    // 面積を返すメンバ関数
    T getArea() {
        return this->bottom * this->height / 2;
    }
};

// main関数
int main() {
    // int型でMyTriangleクラスを使う
    MyTriangle<int> iObj(10, 20);
    cout << "int型の三角形の面積：" << iObj.getArea() << endl;

    // double型でMyTriangleクラスを使う
    MyTriangle<double> dObj(30.0, 40.0);
    cout << "double型の三角形の面積：" << dObj.getArea() << endl;

    MyTriangle<string> sObj("ABC", "DEF");
    cout << "string型の三角形の面積：" << sObj.getArea() << endl;

    return 0;
}
