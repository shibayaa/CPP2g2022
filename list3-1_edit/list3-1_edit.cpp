#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
	const int DATA_NUM = 10;	// 配列の要素数

	// 10人の学生のテストの得点を格納した配列
	int point[DATA_NUM] = { 85, 72, 63, 45, 100, 98, 52, 88, 74, 65 };
	int sum;		// 合計点
	double average;	// 平均点
	int i;		// 配列の要素番号（ループカウンタ）

	double x[] = { 2.2f,0,-3.4f,5.5f };
	unsigned int xLength = sizeof(x);
	cout << "サイズは" << xLength << endl;  //バイト数なので16になる
	cout << "要素数は" << sizeof(x) / sizeof(x[0]) << endl;  //要素数に変換
	cout << "要素数は" << _countof(x) << endl;  //stdlibのマクロを使う



	// 合計点を求める
	sum = 0;
	//for (i = 0; i < DATA_NUM; i++) {
	//	// 配列の要素の値を集計する
	//	sum += point[i];
	//}
	for (auto data : point) {
		sum += data;
	}



	// 平均点を求める
	average = (double)sum / DATA_NUM;

	// 平均点を表示する
	cout << "平均点：" << average << endl;

	return 0;
}
