#include <iostream>
class ClassX {
private:
	int pri;
protected:
	int pro;
public:
	int pub;
	ClassX(int a, int b, int c) :pri(a), pro(b), pub(c) {
	}
};

class ClassA :ClassX{
private:
	int pri;
protected:
	int pro;
public:
	int pub;
	ClassA(int a, int b, int c) :pri(a), pro(b), pub(c),ClassX(a,b,c) {
	}
};
class ClassB :ClassX {
private:
	int pri;
protected:
	int pro;
public:
	int pub;
	ClassB(int a, int b, int c) :pri(a), pro(b), pub(c), ClassX(a, b, c) {
	}
};
class ClassC :public ClassA, public ClassB {
public: 
	ClassC(int p1, int p2, int p3):ClassA(p1,p2,p3),ClassB(-p1,-p2,-p3) {
	}
};


int main()
{
	//ClassA classA = { 1, 2, 3 };
	//ClassB classB = { 4, 5, 6 };
	ClassC classC = { 10,20,30 };
	classC.ClassA::pub = 100;
	classC.ClassB::pub = 200;
}
