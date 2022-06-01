class Point {
  private:
    double x;	// x座標を格納するメンバ変数
    double y;	// y座標を格納するメンバ変数
  public:
    Point(double x = 0, double y = 0);	// コンストラクタ
    double getX();			// x座標を返すゲッタ
    double getY();			// y座標を返すゲッタ
    Point operator+(const Point &p);	// + 演算子のオーバーロード
    Point operator-(const Point &p);	// - 演算子のオーバーロード
    bool operator==(const Point &p);	// == 演算子のオーバーロード
    bool operator!=(const Point &p);	// != 演算子のオーバーロード
    // >> 演算子のオーバーロード
    friend istream &operator>>(istream &is, Point &p);
    // << 演算子のオーバーロード
    friend ostream &operator<<(ostream &os, const Point &p);
};
