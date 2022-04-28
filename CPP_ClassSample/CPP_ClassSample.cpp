#include <iostream>
#include<string>
using namespace std;

void chapter5_3() {
	// 文字列オブジェクト
	string s1, s2, s3;

	// 文字列オブジェクトに文字列を格納する
	s1 = "apple";
	s2 = "banana";

	// 文字列を比較する
	if (s1 > s2) {
		cout << "大きい。" << endl;
	}
	else if (s1 < s2) {
		cout << "小さい。" << endl;
	}
	else {
		cout << "等しい。" << endl;
	}

	// 文字列を連結する
	s3 = s1 + s2;
	cout << s3 << endl;

	// 長さを求める
	cout << s3.length() << endl;

	// 5番目から3文字の部分文字列を取り出す
	cout << s3.substr(5, 3) << endl;

	// 5文字目だけを取り出す
	cout << s3[5] << endl;

	// "na" という文字列を見つける
	cout << s3.find("na") << endl;

	// 文字列を空にする
	s3.clear();

	// 文字列が空であることを確認する
	if (s3.empty()) {
		cout << "空です。" << endl;
	}
	else {
		cout << "空ではありません。" << endl;
	}

}
int main()
{
	int ans;
	//char s[20];
	//cin >> s;
	//ans = strlen(s);
	string s;
//	s = "Hello, world";
	cin >> s;
	ans = s.length();
	cout << ans << endl;
	string t;
	cin >> t;
	cout << (t < s) << endl;
	//// The first member function initializing with a C-string
	//const char* cstr1a = "Hello Out There.";
	//basic_string <char> str1a(cstr1a, 8);
	//cout << "The string initialized by C-string cstr1a is: "
	//	<< str1a << "." << endl;
	chapter5_3();
	return 0;
}