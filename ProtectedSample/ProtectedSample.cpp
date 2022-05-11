#include <iostream>

class ClassA {
private:
    int pri;
protected:
    int pro;
public:
    int pub;
    int GetPri() {
        return pri;
    }
    int GetPro() {
        return pri+pro;
    }
    int GetPub() {
        return pub = pri + pro;
    }
    ClassA(int p1, int p2, int p3) {
        this->pri = p1;
        this->pro = p2;
        this->pub = p3;
    }
};
class ClassB :ClassA {
private:
    int b_pri;
protected:
    int b_pro;
public:
    int b_pub;
    ClassB(int p1, int p2, int p3):ClassA(p1,p2,p3) {
        this->b_pri = p1;
        this->b_pro = p2;
        this->b_pub = p3;
        //pri = 100;  //　親のprivateはアクセスできない
        pro = 100;  //  親のprotectedはアクセスできる
        pub = 100;//  親のpublicはアクセスできる
    }
};
class ClassC :public ClassA {
private:
    int c_pri;
protected:
    int c_pro;
public:
    int c_pub;
    ClassC(int p1, int p2, int p3) :ClassA(p1, p2, p3) {
        this->c_pri = p1;
        this->c_pro = p2;
        this->c_pub = p3;
        //pri = 100;  //　親のprivateはアクセスできない
        pro = 100;  //  親のprotectedはアクセスできる
        pub = 100;//  親のpublicはアクセスできる
    }
};


int main()
{
    ClassA instA =ClassA(1,2,3);
    int x;
    //x = instA.pri;  //アクセスできません
    //x = instA.pro;  //アクセスできません
    x = instA.pub;
    ClassB instB = ClassB(-1, -2, -3);
    //x = instB.pri;  //アクセスできません
    //x = instB.pro;  //アクセスできません
    //x = instB.pub;//アクセスできません
    x = instB.b_pub;    //これだけ可能
    ClassC instC = ClassC(-1, -2, -3);
    //x = instC.pri;  //アクセスできません
    //x = instC.pro;  //アクセスできません
    x = instC.pub;
    x = instC.c_pub;



}
