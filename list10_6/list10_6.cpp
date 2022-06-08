#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    // マップを作成する
    map<string, string> m;

    // マップにキーと値を格納する
    m.insert(make_pair("K001", "apple"));
    m.insert(make_pair("K005", "orange"));
    m.insert(make_pair("K003", "melon"));
    m.insert(make_pair("K002", "banana"));
    m.insert(make_pair("K004", "lemon"));
    //m.insert_or_assign("K004", "strawberry");
    m["K004"] = "strawberry";
    m["K099"] = "mango";
 
    cout << "K099に対応する商品名：" << m["K099"] << endl;

    // キーに対応する値を表示する
    string num;
    do {
        cout << "商品番号：";
        cin >> num;
        if (m.count(num) != 0) {
            cout << "対応する商品名：" << m[num] << endl;
        }
    } while (num != "..");

    enum WeaponSocket {
        RightHand,LeftHand,Head,LeftFoot,RightFoot
    };
    enum Weapon {
        Knife=10, ShotGun, Sword, Gun
    };
    // マップを作成する
    map<WeaponSocket, Weapon> playerWeapons;
    playerWeapons.insert(make_pair( RightHand, Gun));
    playerWeapons.insert(make_pair(LeftHand, Knife));
    cout << "RightHandに対応する武器：" << playerWeapons[RightHand] << endl;
    return 0;
}
