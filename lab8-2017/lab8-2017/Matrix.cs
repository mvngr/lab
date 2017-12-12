using System;
using System.Collections.Generic;

namespace lab8_2017
{
    public class Matrix
    {
        protected List<List<int>> A;
        
        public Matrix()
        {
            var r = new Random();
            A = new List<List<int>>();
            for (var i = 0; i < 4; i++)
            {
                A.Add(new List<int>());
                for (var j = 0; j < 4; j++)
                    A[i].Add(r.Next() % 9 + 1);
            }
        }

        public Matrix(List<List<int>> inputArray)
        {
            A = inputArray;
        }

        public void Print()
        {
            if (A.Count > 0)
                foreach(var ints in A){
                    foreach (var t in ints)
                        Console.Write(t + " ");
                    Console.WriteLine();
                }
            else
                Console.WriteLine("Array length = 0");
        }
    }
}