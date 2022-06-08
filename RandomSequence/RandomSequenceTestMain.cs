using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using _CommonUtility;

namespace RandomSequenceTest
{
    class RandomSequenceTestMain
    {
        static char[] t = new char[7] { 'I', 'O', 'T', 'J', 'L', 'S', 'Z' };

        static void Main()
        {
            ListUtility.RandomSequence<char> randomSequence
                = new ListUtility.RandomSequence<char>(new List<char>(t));
            for (int j = 0; j < 20; j++)
            {
                string s = string.Empty;
                for (int i = 0; i < 7; i++)
                {
                    s += randomSequence.Next();
                }
                Console.WriteLine(s);
            }
        }
    }
}