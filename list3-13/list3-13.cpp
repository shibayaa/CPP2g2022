#include <iostream>
using namespace std;

int main() {
    // 10人の学生のテストの得点を格納した配列（要素数省略）
    int point[] = { 85, 72, 63, 45, 100, 98, 52, 88, 74, 65 };

    // 配列の要素を順番に取り出して表示する
    for (auto data : point) {
        cout << data << ", ";
    }
    cout << endl;

    return 0;
}
