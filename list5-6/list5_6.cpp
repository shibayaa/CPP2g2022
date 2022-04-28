#include <iostream>
#include <string>
using namespace std;
#include "HealthChecker.h"

int main() {
	// HealthCheckerクラスのインスタンスを生成する
	const int DATA_NUM = 3;			// 配列の要素数
// HealthCheckerクラスをデータ型とした配列
	HealthChecker people[DATA_NUM] = {
	  HealthChecker("山田一郎", 170, 67.5),	// 山田さん
	  HealthChecker("佐藤花子", 160, 54.5),	// 佐藤さん
	  HealthChecker("鈴木次郎", 180, 85.5)	// 鈴木さん
	};
	cout << "標準のBMIは" << HealthChecker::getStdBmi() << "です。" << endl;

	HealthChecker yamada("山田一郎", 170, 67.5);
	cout << yamada.getName() << "さんのBMIは" << yamada.getBmi() << "です。" << endl;
	cout<< yamada.getName() << "さんの標準体重は" << yamada.getStdWeight() << "です。" << endl;
	HealthChecker* shimura = new HealthChecker("志村淳", 168, 60.5);
	cout << shimura->getName() << "さんのBMIは" << shimura->getBmi() << "です。" << endl;
	cout << shimura->getName() << "さんの標準体重は" << shimura->getStdWeight() << "です。" << endl;

	// BMIの値を表示する
	for (int i = 0; i < DATA_NUM; i++) {
		std::cout << people[i].getName() << "さんのBMIは、" << people[i].getBmi() << "です。" << std::endl;
		cout << people[i].getName() << "さんの標準体重は" << people[i].getStdWeight() << "です。" << endl;
	}
	return 0;
}
