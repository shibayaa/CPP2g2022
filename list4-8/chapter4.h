// 健康診断のデータを格納する構造体の定義
struct HealthCheck {
  string name;		// 氏名
  double height;	// 身長
  double weight;	// 体重
  double bmi;		// BMI
};

// BMIを求める関数のプロトタイプ宣言
double getBmi(double height, double weight);
double getBmi(const HealthCheck *phc);

// 2次方程式を解く関数のプロトタイプ宣言
bool quadEq(double a, double b, double c, double *px1, double *px2);

// 配列の平均値を返す関数のプロトタイプ宣言
double getAverage(const int *a, int length);
