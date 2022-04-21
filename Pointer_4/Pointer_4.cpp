#include <iostream>
#include<stdlib.h>
float Sum(float* d, int count) {
	float s = 0;
	for (int i = 0; i < count; i++) {
		s += *(d + i);
	}
	return s;
}

/// <summary>
/// 平均と合計
/// </summary>
/// <param name="d">配列の先頭アドレス</param>
/// <param name="count">要素数</param>
/// <param name="a">平均を格納するポインタ</param>
/// <param name="s">合計を格納するポインタ</param>
void AverageSum(float* d, int count, float* a, float* s) {
	*s = Sum(d, count);
	*a = *s / count;
}
int main() {
	float data[] = { 2,3,-1.8f,50,-20,10,0,8,500,20.5 };
	float sum;
	float average;
	AverageSum(data, _countof(data), &average, &sum);
	std::cout << "合計=" << sum << "平均＝" << average;
	return 0;
}
