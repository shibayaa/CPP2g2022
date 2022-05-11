class AccountEx : public Account {
  protected:
    string name;	// 口座名義人を示すメンバ変数
  public:
    string getName();	// 口座名義人を返すメンバ関数
    // コンストラクタ
    AccountEx(string number, string name, int balance);
};
