using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace _CommonUtility
{
    public class ListUtility
    {
        public static List<T> Shuffle<T>(List<T> list)
        {
            List<T> shuffled
           = new List<T>(list)
               .OrderBy(a => Guid.NewGuid())
               .ToList();
            return shuffled;
        }

        public static List<List<T>> DivideList<T>(List<T> list, int div)
        {
            List<T> shuffledList = Shuffle(new List<T>(list));
            List<List<T>> result = new List<List<T>>();
            for (int i = 0; i < div; i++)
            {
                result.Add(new List<T>() { shuffledList[i] });
            }
            Random rand = new Random();
            for (int i = div; i < list.Count; i++)
            {
                result[rand.Next(div)].Add(shuffledList[i]);
            }
            return result;
        }
        public class RandomSequence<T>
        {
            private Queue<T> queue = new Queue<T>();
            private List<T> baseList;
            public RandomSequence(List<T> list)
            {
                baseList = new List<T>(list);
            }
            public T Next()
            {
                if (queue.Count == 0)
                {
                    List<T> s = new List<T>(Shuffle(baseList));
                    s.ForEach(t => queue.Enqueue(t));
                }
                return queue.Dequeue();
            }
        }
    }
}