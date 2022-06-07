using System;

namespace List10_4Csharp
{

    class List10_4CsharpClass
    {
        // MyTriangleクラスの定義と実装
        class MyTriangle<T> where T : System.ValueType
        {
            private T bottom;      // 底辺
            private T height;       // 高さ
            public MyTriangle(T bottom, T height)
            {
                this.bottom = bottom;
                this.height = height;
            }
            // 面積を返すメンバ関数
            public T getArea()
            {
                return bottom * height / 2;
            }
        }
    }
}
