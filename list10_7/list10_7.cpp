#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main() {
    // キューを作成する
    queue<string> q;

    // キューにデータを格納する
    q.push("データ1");
    q.push("データ2");
    q.push("データ3");

    // キューからデータを取り出す
    cout << "***** キュー *****" << endl;
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    // スタックを作成する
    stack<string> s;

    // スタックにデータを格納する
    s.push("データ1");
    s.push("データ2");
    s.push("データ3");

    // スタックからデータを取り出す
    cout << "***** スタック *****" << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
