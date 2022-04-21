using System;

namespace ex11
{
    class ex11
    {
        static void Main(string[] args)
        {
            //参照型
            TestClassA testClassA = new TestClassA(5, 2);
            testClassA.TestFunc();
            var temp = testClassA;  // 参照先を指定する
            temp.a = 1;
            testClassA.TestFunc();
            //値型
            TestStructB testStructB = new TestStructB(10,5);
            testStructB.TestFunc();
            var temp2 = testStructB;    // temp2に同じものが再現されて作られる
            temp2.a = 2;
            testStructB.TestFunc(); //　10,5を持っている
            temp2.TestFunc();   //2,5を持っている

        }
    }
    class TestClassA
    {
        public int a;
        public int b;
        public TestClassA(int a,int b)
        {
            this.a = a;
            this.b = b;
        }
        public void TestFunc()
        {
            Console.WriteLine($"{a},{b}");
        }
    }
    struct TestStructB
    {
        public int a;
        public int b;
        public TestStructB(int a, int b)
        {
            this.a = a;
            this.b = b;
        }
        public void TestFunc()
        {
            Console.WriteLine($"{a},{b}");
        }
    }
}

