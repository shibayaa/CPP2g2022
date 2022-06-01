using System;

namespace CopyConstructor
{
    struct TestStructA
    {
        private int i;
        public TestStructA(int i) {
            this.i = i;
        }
        public int I { set { this.i=value; } }
    }
    class TestClassB
    {
        private int i;
        public TestClassB(int i)
        {
            this.i = i;
        }
        public TestClassB(in TestClassB testClassB)
        {
            this.i = testClassB.i;
        }
    }
    class TestClassA
    {
        private int i;
        private TestClassB testClassB;
            
        public TestClassA(int i)
        {
            this.i = i;
            testClassB = new TestClassB(i);
        }
        // コピーコンストラクタ
        public TestClassA(in TestClassA testClass)
        {
            this.i = testClass.i;
            testClassB = testClass.testClassB;  //同じものを指す
            testClassB = new TestClassB(testClass.testClassB);  //同じものを複製する
        }
        public int i_out
        {
            get { return this.i; }
        }
    }
    class CopyConstructorSample
    {
        static void Main(string[] args)
        {
            TestClassA testClass1 = new TestClassA(1);
            TestClassA testClass2 = testClass1;   // 参照の代入になるので複製されない
            TestClassA testClass3 = new TestClassA(testClass1);
            TestStructA testStruct1 = new TestStructA(5);
            TestStructA testStruct2 = testStruct1;
            testStruct1.I = -1;
        }
    }
}


