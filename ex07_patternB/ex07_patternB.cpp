#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;

class FreightTable {
private:
	const int* freight;
	int length;
public:
	FreightTable(const int freight[],int length) {
		this->freight = freight;
		this->length = length;
	}
	int GetFreight(int index) {
		return freight[index];
	}
	int GetPackageSize(double packLength) {
		int i;
		int packageSize = 0;
		// 箱の宅急便のサイズを求める
		for (i = 0; i < length; i++) {
			if (packLength <= *(freight + i)) {
				packageSize = *(freight + i);
				break;
			}
		}
		return packageSize;
	}
};

class Solid {
private:
	string* name;
public:
	Solid(const char* name = NULL) {
		if (name != NULL) {
			this->name = new string(name);
		}
		else {
			this->name = NULL;
		}
	}
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
	virtual double GetPackageLength() = 0;
	const char* GetName() {
		return name->data();
	}
	~Solid() {
		if (name != NULL) {
			name->~basic_string();
		}
	}
};

class Package {
private:
	FreightTable* freightTable;
	Solid* solid; //外部を参照
public:
	Package(
		FreightTable* freightTable,
		Solid* solid
	)
	{
		this->freightTable = freightTable;
		this->solid = solid;
	}
	int GetPackageSize() {
		return freightTable->GetPackageSize(solid->GetPackageLength());
	}
	Solid& GetSolid() {
		return *solid;
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
		const char* name = NULL	//名前
	) :Solid(name)
	{
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
		const char* name = NULL	//名前
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
		const char* name = NULL	//名前
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
		const char* name = NULL	//名前
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
void DisplayVolumeSurface(Package* package) {
	cout << "体積=" << package->GetSolid().GetVolume() << endl;
	cout << "表面積=" << package->GetSolid().GetSurface() << endl;
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
	// 料金表
	const int kuronekoSize[] = { 60,80,100,120,140,160,180,200 };
	const int yupackSize[] = { 60,80,100,120,140,160,170 };
	const int sagawaSize[] = { 60,80,100,140,160 };
	// 料金算出をするクラス
	FreightTable kuronekoFreight(kuronekoSize,_countof(kuronekoSize));
	FreightTable yupackFreight(kuronekoSize, _countof(kuronekoSize));
	FreightTable sagawaFreight(kuronekoSize, _countof(kuronekoSize));
	Box gunpla = Box(80.0, 20.0, 5.0, "MGガンダム1/144");
	Cylinder canJuice = Cylinder(30, 10, "Qoo");
	Cone cone = Cone(30, 10, "コーン");
	Sphere succerBall = Sphere(20, "FIFA公認サッカーボール");
	const int N_TABLE = 6;
	Package* package[N_TABLE] =
	{
		new Package(&kuronekoFreight, &gunpla),
		new Package(&yupackFreight, &gunpla),
		new Package(&sagawaFreight, &gunpla),
		new Package(&kuronekoFreight,&canJuice),
		new Package(&kuronekoFreight,&cone),
		new Package(&kuronekoFreight,&succerBall)
	};

	double length;
	int packageSize;

	for (int i = 0; i < N_TABLE; i++) {
		cout << "[" << i + 1 << "]" << package[i]->GetSolid().GetName() << endl;
		DisplayVolumeSurface(package[i]);
		int packageSize = package[i]->GetPackageSize();
		if (packageSize != 0) {
			cout << package[i]->GetSolid().GetName() << "のサイズは" << packageSize << "サイズです" << endl;
		}
		else {
			cout << "この" << package[i]->GetSolid().GetName() << "は宅急便では送れません" << endl;
		}
	}

	/*
	for (int i = 0; i < N_TABLE; i++) {
		cout << "[" << i + 1 << "]" << solid[i]->GetName() << endl;
		DisplayVolumeSurface(solid[i]);
		packageSize = GetSolidKuronekoPackage(*solid[i]);
		if (packageSize != 0) {
			cout << solid[i]->GetName() << "のサイズは" << packageSize << "サイズです" << endl;
		}
		else {
			cout << "この" << solid[i]->GetName() << "は宅急便では送れません" << endl;
		}
	}
	*/
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