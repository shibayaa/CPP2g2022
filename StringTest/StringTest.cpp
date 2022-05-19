#define __STDC_WANT_LIB_EXT1__ 1
#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;

class StringTest1 {
private:
    char* s;
public:
    StringTest1(char* s) {
        this->s = s;
        *(s + 1) = '$';
    }
    char* getS() {
        return s;
    }
};
class StringTest2 {
private:
    const char* s;  //　こちら側でポインタの指す先を変えられないが外からは変えられる
public:
    StringTest2(const char* s) {
        this->s = s;
        //*(s + 1) = '$'; //元のデータの書き換えはできない
    }
    const char* getS() {
        return s;
    }
};
class StringTest3 {
private:
    char s[20];  //　こちら側でポインタの指す先を変えられないが外からは変えられる
public:
    StringTest3(const char* s) {
        strcpy_s(this->s,s);
    }
    const char* getS() {
        return s;
    }
};
class StringTest4 {
private:
    string s;  //　stringクラス
public:
    StringTest4(const char* s) {
        this->s=string(s);
    }
    const char* getS() {
        return s.data();
    }
};



int main()
{
    char c1 = 'A';  //　1文字だけの宣言
    const char c2[] = "ABCあいうえお"; //文字列をcharの配列で表す
    const char* c3 = "XYZかきくけこ"; //文字列をcharの配列で表す
#pragma region ConstTest
    //char* c4 = "XYZかきくけこ"; //constが無いとエラーになる
    //c2[2] = 'a';          //Error
    //*(c3+1) = 'a';    //Error
    //c3 = nullptr;   //　コンパイルは通り動作可能だが例外で落ちる
#pragma endregion
    char c5[10] = { 'a','b','c',NULL };
    char* c6 = c5;  //　ポインタの指す先はc5
    *(c6 + 1) = '@';    //　constではないので書き換え可能
    string s = "IJKさしすせそ";
    StringTest1 stringTest1{ c5 };
    StringTest2 stringTest2{ c5 };
    StringTest3 stringTest3{ c5 };
    StringTest4 stringTest4{ c5 };
    *(c6 + 1) = '*';    //　constではないので書き換え可能
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << stringTest1.getS() << endl;
    cout << stringTest2.getS() << endl;
    cout << stringTest3.getS() << endl;
    cout << stringTest4.getS() << endl;
}

