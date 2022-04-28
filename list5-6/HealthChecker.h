class HealthChecker {
private:
    static const int STD_BMI;		// 標準BMIを表すメンバ定数
    string name;			// 氏名を格納するメンバ変数
    double height;			// 身長を格納するメンバ変数
    double weight;			// 体重を格納するメンバ変数
    double bmi;				// BMIを格納するメンバ変数
public:
    static int getStdBmi();		// 標準BMIを返すメンバ関数
    double getStdWeight();		// 標準体重を返すメンバ関数
    double getBmi();			// BMIを返すメンバ関数
    string getName();			// 氏名を返すメンバ関数
    HealthChecker(string name, double height, double weight); // コンストラクタ
    ~HealthChecker();   //デストラクタ
};
