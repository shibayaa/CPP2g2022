// list3-3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int channel;		// チャンネルの番号
    string stationName;	// テレビ局名
    string s1 = "test_test";
    string stationNametable[] = {
       "割り当てなし",
       "NHK総合",
       "NHK教育",
       "割り当てなし",
       "日本テレビ",
       "割り当てなし",
       "TBSテレビ",
       "割り当てなし",
       "フジテレビ",
       "割り当てなし"
       "テレビ朝日",
        "割り当てなし"
        "テレビ東京" };
    string s2 = "TEST_TEST";

    // キー入力をchannelに格納する
    cout << "チャンネル番号を入力してください：";
    cin >> channel;
    cout << stationNametable[channel];

    return 0;
}
