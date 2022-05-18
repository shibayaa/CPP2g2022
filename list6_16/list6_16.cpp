#include <iostream>
#include <string>
using namespace std;

// 動物を表すクラスの定義
class Animal {
  protected:
    string name;		// 名前を保持するメンバ変数
  public:
    virtual void speak() = 0;	// 名前と鳴き声を表示するメンバ関数
    Animal(string name);	// コンストラクタ
};


// 犬を表すクラスの定義
class Dog : public Animal {
  public:
    void speak();	// 名前と鳴き声を表示するメンバ関数
    Dog(string name);	// コンストラクタ
};

// 猫を表すクラスの定義
class Cat : public Animal {
  public:
    void speak();	// 名前と鳴き声を表示するメンバ関数
    Cat(string name);	// コンストラクタ
};

// 動物を表すクラスのコンストラクタの実装
Animal::Animal(string name) {
  this->name = name;
}

// 犬を表すクラスの名前と鳴き声を表示するメンバ関数の実装
void Dog::speak() {
  cout << this->name << "：ワン！" << endl;
}

// 犬を表すクラスのコンストラクタの実装
Dog::Dog(string name) : Animal(name) {
}

// 猫を表すクラスの鳴き声を表示するメンバ関数の実装
void Cat::speak() {
  cout << this->name << "：ニャン！" << endl;
}

// 猫を表すクラスのコンストラクタの実装
Cat::Cat(string name) : Animal(name) {
}

// Animalクラスのポインタを引数としたsub関数
void sub(Animal *p) {
  p->speak();
}

// sub関数を使うmain関数
int main() {
  // 犬と猫のインスタンスを生成する
  Dog pochi("ポチ");
  Cat tama("タマ");

  // 犬と猫を鳴かせる
  sub(&pochi);
  sub(&tama);

  Animal* animal = &pochi;
  animal->speak();

  return 0;
}
