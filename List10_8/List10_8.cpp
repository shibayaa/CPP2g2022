#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // ベクトルを作成する
    vector<int> v;

    // ベクトルにデータを格納する
    v.push_back(5);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);

    // ソート前のベクトルの内容を表示する
    int length = v.size();
    cout << "ソート前：";
    for (int i = 0; i < length; i++) {
        cout << "[" << v[i] << "]";
    }
    cout << endl;

    // ベクトルを昇順にソートする
    sort(v.begin(), v.end());

    // ソート前のベクトルの内容を表示する
    cout << "ソート後：";
    for (int i = 0; i < length; i++) {
        cout << "[" << v[i] << "]";
    }
    cout << endl;
    return 0;
}
