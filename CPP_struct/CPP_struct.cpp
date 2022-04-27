#include <iostream>
using namespace std;

struct BOX {	//箱の定義
	double x;	//幅
	double y;	//高さ
	double z;	//奥行
	double volume;	//体積
	double surface; //表面積
};

void getVolumeSurface(double x, double y, double z, double* volume, double* surface) {
	*volume = x * y * z;
	*surface = 2 * (x * y + x * z + y * z);
	return;
}
void getVolumeSurface(BOX* box) {
	getVolumeSurface(box->x, box->y, box->z, &box->volume, &box->surface);
	return;
}

int main()
{
	const int BoxCount = 3;
	BOX boxes[BoxCount];
	for (int i = 0; i < BoxCount; i++) {
		cout << "幅を入力：";
		cin >> boxes[i].x;
		cout << "高さを入力：";
		cin >> boxes[i].y;
		cout << "奥行を入力：";
		cin >> boxes[i].z;
		//getVolumeSurface(boxes[i].x, boxes[i].y, boxes[i].z,
		//	&boxes[i].volume, &boxes[i].surface);
		getVolumeSurface(&boxes[i]);
		cout << "体積は" << boxes[i].volume << endl;
		cout << "表面積は" << boxes[i].surface << endl;
	}
	return 0;
}
