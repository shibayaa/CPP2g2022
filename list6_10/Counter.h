class Counter {
  protected:
    int val;		// カウンタの値を格納するメンバ変数
  public:
    void resetVal();	// カウンタの値を0にするメンバ関数
    void upVal();	// カウンタの値をアップするメンバ関数
    int getVal();	// カウンタの値を返すメンバ関数
    Counter();		// コンストラクタ
};
