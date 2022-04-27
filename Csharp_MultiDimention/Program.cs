using System;

namespace MultiDimention
{
    class MultiDilentionMain
    {
        const int MATRIX_HEIGHT = 5;
        const int MATRIX_WIDTH = 3;

        static void Main(string[] args)
        {
            int[,] matrix = new int[MATRIX_HEIGHT, MATRIX_WIDTH]
            {
                {1,2,3},
                {4,5,6},
                {7,8,9},
                {10,11,12},
                {13,14,15}
            };
            int s = 0;
            #region multiIndex
            /* 
             for (int i = 0; i < MATRIX_HEIGHT; i++)
                        {
                            for (int j = 0; j < MATRIX_WIDTH; j++)
                            {
                                s += matrix[i, j];
                            }
                        }
            */
            #endregion
            for (int i = 0; i < MATRIX_HEIGHT* MATRIX_WIDTH; i++)
            {
                s += matrix[0,i];   //例外になり処理できない
            }
            Console.WriteLine(s);
        }
    }
}

