class AccountEx2  {
  protected:
    string name;	// 口座名義人を示すメンバ変数
  public:
      Account*   account;
      string getName();	// 口座名義人を返すメンバ関数
    // コンストラクタ
    AccountEx2(string number, string name, int balance);
};
