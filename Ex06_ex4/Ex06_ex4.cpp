#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
private:
	string* name;
public:
	Solid(string* name = NULL) {
		if (name != NULL) {
			this->name = name;
		}
		else {
			this->name = NULL;
		}
	}
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
	virtual double GetPackageLength() = 0;
	string* GetName() {
		return name;
	}
	~Solid() {
		if (name != NULL) {
			name->~basic_string();
		}
	}
};

/// <summary>
/// 箱型
/// </summary>
class Box :public Solid {
private:
	double width;
	double height;
	double depth;

public:
	Box(
		double width,   //幅
		double height,  //高さ
		double depth,    //奥行
		string* name = NULL	//名前
	) :Solid(name ) {
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetVolume() {
		return width * height * depth;
	}
	double GetSurface() {
		return (width * height + height * depth + depth * width) * 2;
	}
	double GetPackageLength() {
		return this->width + this->height + this->depth;
	}
	double GetWidth() {
		return this->width;
	}
	double GetHeight() {
		return this->height;
	}
	double GetDepth() {
		return this->depth;
	}
};

class Cylinder :public Solid {
private:
	double radius;
	double height;
public:
	Cylinder(
		double radius,  //　底面の半径
		double height,   // 高さ
		string* name = NULL	//名前
	) :Solid(name) {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume() {
		return radius * radius * M_PI * height;
	}
	double GetSurface() {
		return radius * M_PI * 2 * (radius + height);
	}
	double GetPackageLength() {
		return this->radius * 4 + this->height;
	}
	double GetRadius() {
		return this->radius;
	}
	double GetHeight() {
		return this->height;
	}
};

class Cone :public Solid {
private:
	double radius;
	double height;
public:
	Cone(
		double radius,  //　底面の半径
		double height,   // 高さ
		string* name = NULL	//名前
	) :Solid(name) {
		this->radius = radius;
		this->height = height;
	}
	double GetVolume() {
		return radius * radius * M_PI * height / 3.0;
	}
	double GetSurface() {
		return M_PI * radius * (radius + sqrt(radius * radius + height * height));
	}
	double GetPackageLength() {
		return this->radius * 4 + this->height;
	}
	double GetRadius() {
		return this->radius;
	}
	double GetHeight() {
		return this->height;
	}
};

class Sphere :public Solid {
private:
	double radius;
public:
	Sphere(
		double radius,  //　底面の半径
		string* name = NULL	//名前
	) :Solid(name) {
		this->radius = radius;
	}
	double GetVolume() {
		return  M_PI * radius * radius * radius * 4 / 3;
	}
	double GetSurface() {
		return M_PI * radius * radius * 4;
	}
	double GetPackageLength() {
		return this->radius * 6;
	}
	double GetRadius() {
		return this->radius;
	}
};

void DisplayVolumeSurface(Solid* solid) {
	cout << "体積=" << solid->GetVolume() << endl;
	cout << "表面積=" << solid->GetSurface() << endl;
}

int GetSolidKuronekoPackage(Solid& solid) {
	int kuronekoSize[] = { 60,80,100,120,140,160,180,200 };
	int i;
	int packageSize = 0;
	// 箱の宅急便のサイズを求める
	double length = solid.GetPackageLength();
	for (i = 0; i < _countof(kuronekoSize); i++) {
		if (length <= kuronekoSize[i]) {
			packageSize = kuronekoSize[i];
			break;
		}
	}
	return packageSize;
}

int main()
{
	std::string boxName = "箱";
	Box* box = new Box(80.0, 20, 5,&boxName);
	std::string cylinderName = "円柱";
	Cylinder* cylinder = new Cylinder( 30, 10,&cylinderName);
	std::string coneName = "円錐";
	Cone* cone= new Cone(30, 10,&coneName);
	std::string sphereName = "球";
	Sphere* sphere = new Sphere(20,&sphereName);
	const int N_TABLE = 4;
	Solid* solid[N_TABLE] = { box, cylinder,cone,sphere };

	int kuronekoSize[] = { 60,80,100,120,140,160,180,200 };
	int i;
	double length;
	int packageSize;

	for (int i = 0; i < N_TABLE; i++) {
		cout << "[" << i + 1 << "]" << *solid[i]->GetName() << endl;
		DisplayVolumeSurface(solid[i]);
		packageSize = GetSolidKuronekoPackage(*solid[i]);
		if (packageSize != 0) {
			cout << *solid[i]->GetName() << "のサイズは" << packageSize << "サイズです" << endl;
		}
		else {
			cout << "この" << *solid[i]->GetName() << "は宅急便では送れません" << endl;
		}
	}
/*
	// 箱の宅急便のサイズを求める
	packageSize = GetSolidKuronekoPackage(*solid[0]);
	if (packageSize != 0) {
		cout << *solid[0]->GetName()<<  "のサイズは" << packageSize << "サイズです" << endl;
	}
	else {
		cout << "この"<< *solid[0]->GetName()<<"箱は宅急便では送れません" << endl;
	}

	// 円柱の宅急便のサイズを求める
	packageSize = GetSolidKuronekoPackage(*solid[1]);
	if (packageSize != 0) {
		cout << "円柱のサイズは" << packageSize << "サイズです" << endl;
	}
	else {
		cout << "この円柱は宅急便では送れません" << endl;
	}

	// 円錐の宅急便のサイズを求める
	packageSize = GetSolidKuronekoPackage(*solid[2]);
	if (packageSize != 0) {
		cout << "円錐のサイズは" << packageSize << "サイズです" << endl;
	}
	else {
		cout << "この円錐は宅急便では送れません" << endl;
	}

	// 球の宅急便のサイズを求める
	packageSize = GetSolidKuronekoPackage(*solid[3]);
	if (packageSize != 0) {
		cout << "球のサイズは" << packageSize << "サイズです" << endl;
	}
	else {
		cout << "この球は宅急便では送れません" << endl;
	}
	*/
}