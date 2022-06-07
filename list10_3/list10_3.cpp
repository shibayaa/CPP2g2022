#include <iostream>
using namespace std;

// 関数テンプレートで定義したgetMin関数
template <class T> T getMin(T a, T b) {
	return a < b ? a : b;
}
// 関数テンプレートで定義したgetMin関数
template <class T1, class T2> T1* getMin(
	T1 a[], T2 aLength,
	T1 b[], T2 bLength) {
	T1* result = a;
	for (int i = 0; i < aLength || i < bLength; i++) {
		if (i < aLength && i < bLength) {
			if (a[i] == b[i]) {
				continue;
			}
			else {
				if (a[i] < b[i]) {
					result = a;
				}
				else {
					result = b;
				}
				break;
			}
		}
		if (aLength < bLength) {
			result = a;
			break;
		}
		else {
			result = b;
			break;
		}
	}
	return result;
}



// 関数テンプレートで定義したgetMin関数（配列の要素の最小値を返す）

template <class T1, class T2> T1 getMin(T1 a[], T2 length) {
	T1 ans = a[0];
	for (T2 i = 1; i < length; i++) {
		if (ans > a[i]) {
			ans = a[i];
		}
	}
	return ans;
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

	// char型のgetMin関数（配列用）を呼び出す
	char cArray[] = { 'c', 'b', 'f', 'a', 'e' };
	int cLength = 5;
	char cAns = getMin(cArray, cLength);
	cout << cAns << endl;

	// float型のgetMin関数（配列用）を呼び出す
	float fArray[] = { 2.22F, 3.33F, 1.11F, 5.55F, 4.44F };
	int fLength = 5;
	float fAns = getMin(fArray, fLength);
	cout << fAns << endl;

	// float型のgetMin関数（配列用）を呼び出す
	int iArray[] = { 2, 3, 1, 5, 4 };
	int iLength = 5;
	int iAns = getMin(iArray, iLength);
	cout << iAns << endl;

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
	char c1[] = "abxd";
	char c2[] = "abcd";
	char* c3;
	c3 = getMin(c1, _countof(c1), c2, _countof(c2));
	cout << c3 << endl;

	// char*型のgetMin関数を呼び出す
	float f1[] = { 1,7,8,-1 };
	float f2[] = { 1,7,10 };
	float* f3;
	f3 = getMin(f1, _countof(f1), f2, _countof(f2));
	cout << f3 << endl;


	return 0;
}
