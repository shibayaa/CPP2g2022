#include <iostream>
using namespace std;

// 関数テンプレートで定義したgetMin関数
template <class T> T getMin(T a, T b) {
	return a < b ? a : b;
}

// main関数
int main() {
	// int型のgetMin関数を呼び出す
	int a, b, c;
	a = 123;
	b = 456;
	c = getMin(a, b);
	cout << c << endl;

	// double型のgetMin関数を呼び出す
	double x, y, z;
	x = 1.23;
	y = 4.56;
	z = getMin(x, y);
	cout << z << endl;

	// string型のgetMin関数を呼び出す
	string s1, s2, s3;
	s1 = "def";
	s2 = "abc";
	s3 = getMin(s1, s2);
	cout << s3 << endl;
	if (s1 < s2) {
		cout << "s1が小さい";
	}
	else {
		cout << "s2が小さい";
	}

	// char*型のgetMin関数を呼び出す
	char c1[] = "def";
	char c2[] = "abc";
	char* c3;
	c3 = getMin(c1, c2);
	cout << c3 << endl;

	return 0;
}
