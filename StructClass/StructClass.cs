using System;
namespace StructClassN {
    class StructClass
    {
        struct TestStruct
        {
            public int a, b;
        }
        class TestClass
        {
            public int a, b;
        }
        static void Main(string[] args)
        {
            TestStruct testStruct1 = new TestStruct();
            testStruct1.a = 1;
            testStruct1.b = 2;
            TestStruct testStruct2 = testStruct1;
            testStruct2.a = 3;
            testStruct2.b = 4;
            Console.WriteLine($"1のaは{ testStruct1.a},bは{ testStruct1.b}");
            Console.WriteLine($"2のaは{ testStruct2.a},bは{ testStruct2.b}");
            TestClass testClass1 = new TestClass();
            testClass1.a= 1;
            testClass1.b= 2;
            TestClass testClass2 = testClass1;
            testClass2.a= 3;
            testClass2.b= 4;
            TestClass testClass3 = new TestClass();
            testClass3 = testClass1;
            testClass3.a = 5;
            testClass3.b = 6;
            Console.WriteLine($"1のaは{ testClass1.a},bは{ testClass1.b}");
            Console.WriteLine($"2のaは{ testClass2.a},bは{ testClass2.b}");
            Console.WriteLine($"3のaは{ testClass3.a},bは{ testClass3.b}");
        }
    }
}