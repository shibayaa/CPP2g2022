#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ベクトルの内容を表示する関数
void showVector(string title, const vector<int>& v) {
    cout << title << endl;
    cout << "ベクトルの内容：";
    int length = v.size();
    for (int i = 0; i < length; i++) {
        cout << "[" << v[i] << "] ";
    }
    cout << endl;
}

// main関数
int main() {
    // ベクトルを作成する
    vector<int> v;

    // ベクトルにデータを格納する
    v.push_back(111);
    v.push_back(111);
    v.push_back(111);
    v.push_back(222);
    v.push_back(222);
    showVector("***** 初期状態 *****", v);

    // count関数で要素数を得る
    int num = count(v.begin(), v.end(), 111);
    cout << "***** 111の要素数 *****" << endl;
    cout << num << endl;

    // reverse関数で逆順にする
    reverse(v.begin(), v.end());
    showVector("***** 逆順にする *****", v);

    // replace関数で置き換える
    replace(v.begin(), v.end(), 111, 222);
    showVector("***** 置き換える *****", v);

    return 0;
}
