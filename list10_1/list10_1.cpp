#include <iostream>
using namespace std;

// int型を引数とするgetMin関数
int getMin(int a, int b) {
	return a < b ? a : b;
}

// double型を引数とするgetMin関数
double getMin(double a, double b) {
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

	return 0;
}
