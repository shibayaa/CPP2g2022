#include <iostream>
#include "getVolumeSurface.h"
using namespace std;
int main() {
	double x, y, z;
	cout << "幅を入力:";
	cin >> x;
	cout << "高さを入力:";
	cin >> y;
	cout << "奥行を入力:";
	cin >> z;
	double volume, suraface;
	volume = getVolumeSurface(x, y, z, suraface);
	cout << "体積は" << volume << endl << "表面積は" << suraface << endl;
	return 0;
}