#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ベクトルを作成する
    vector<string> v;

    // 任意の行数の文字列を入力する
    string s;
    do {
        cout << "文字列の入力：";
        cin >> s;
        v.push_back(s);
    } while (s != "..");

    // ベクトルの末尾の要素を（".."）を削除する
    v.pop_back();

    //std::reverse(v.begin(), v.end());
    std::sort(v.begin(), v.end());
    // ベクトルに格納された文字列を表示する
    int length = v.size();
    for (int i = 0; i < length; i++) {
        cout << "ベクトルの内容：" << v[i] << endl;
    }

    return 0;
}
