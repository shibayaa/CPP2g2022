#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // ベクトルを作成する
    vector<string> v;

    // ベクトルにデータを格納する
    v.push_back("apple");
    v.push_back("orange");
    v.push_back("melon");
    v.push_back("banana");
    v.push_back("lemon");

    // 探索するデータをキー入力する
    string s;
    cout << "探索するデータ：";
    cin >> s;

    // ベクトルからデータを探索する
    vector<string>::iterator it = find(v.begin(), v.end(), s);
    if (it != v.end()) {
        cout << *it << "が見つかりました！" << endl;
    }
    else {
        cout << "見つかりません！" << endl;
    }

    return 0;
}