#include <iostream>
using namespace std;
#include "Point.h"

// コンストラクタの実装
Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

// x座標を返すゲッタの実装
double Point::getX() {
  return this->x;
}

// y座標を返すゲッタの実装
double Point::getY() {
  return this->y;
}

// + 演算子のオーバーロードの実装
Point Point::operator+(const Point &p) {
  Point ans(this->x + p.x, this->y + p.y);
  return ans;
}

// - 演算子のオーバーロードの実装
Point Point::operator-(const Point &p) {
  Point ans(this->x - p.x, this->y - p.y);
  return ans;
}

// == 演算子のオーバーロードの実装
bool Point::operator==(const Point &p) {
  return this->x == p.x && this->y == p.y;
}

// != 演算子のオーバーロードの実装
bool Point::operator!=(const Point &p) {
  return !(*this == p);
}

// >> 演算子のオーバーロードの実装
istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}

// << 演算子のオーバーロードの実装
ostream &operator<<(ostream &os, const Point &p) {
  os << "x = " << p.x << ", y = " << p.y;
  return os;
}
