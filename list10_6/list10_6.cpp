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

    cout << "K001に対応する商品名：" << m["K001"] << endl;

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
        Knife, ShotGun, Sword, gun
    };
    // マップを作成する
    map<WeaponSocket, Weapon> playerWeapons;
    playerWeapons.insert(RightHand, gun);




    return 0;
}
