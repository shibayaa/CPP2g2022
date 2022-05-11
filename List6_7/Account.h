class Account {
  protected:
    string number;	// 口座番号を表すメンバ変数
    int balance;	// 残高を表すメンバ変数
  public:
    string getNumber();			 // 口座番号を返すメンバ関数
    int getBalance();			 // 残高を返すメンバ関数
    void setBalance(int balance);	 // 残高を設定するメンバ関数
    Account(string number, int balance); // コンストラクタ
};
