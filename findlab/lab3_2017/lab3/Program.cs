using System;
using System.Collections.Generic;
using System.Text;

namespace lab3
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            //#1
            List<int> a = new List<int>(){88,112,6467,325,878,3,77,8,99};
            a.ForEach(delegate(int i) { Console.Write(i + " "); });
            Console.WriteLine();
            //#2
            a.Sort();
            a.ForEach(delegate(int i) { Console.Write(i + " "); });
            Console.WriteLine();
            Console.WriteLine("Найденный элемент: " + a.FindIndex(x => x == 77));
            //#3
            int[,] b = new int[2, 2];
            int[,] c = new int[2, 2];
            int[,] d = new int[2, 2];

            b[0, 0] = 1;
            b[0, 1] = 2;
            b[1, 0] = 3;
            b[1, 1] = 4;
            c[0, 0] = 1;
            c[0, 1] = 0;
            c[1, 0] = 0;
            c[1, 1] = 1;
            
            for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        d[i, j] += b[i, k] * c[k, j];
            Console.WriteLine(d[0,0] + " " + d[0,1] + "\n" + d[1,0] + " " + d[1,1]);
        }
    }
}