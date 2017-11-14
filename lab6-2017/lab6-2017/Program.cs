using System;
using System.Collections.Generic;

namespace lab6_2017
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Random r = new Random();
            List<List<int>> arr = new List<List<int>>();
            arr.Add(new List<int>(){0,11,49,32});
            arr.Add(new List<int>(){49,0,47,23});
            arr.Add(new List<int>(){94,87,0,99});
            arr.Add(new List<int>(){74,67,32,0});
            /*for (int i = 0; i < 4; i++)
            {
                arr.Add(new List<int>());
                for (int j = 3; j >= 0; j--)
                {
                    if(i != 3 - j)
                        arr[i].Add(j+2);
                    else
                        arr[i].Add(0);
                }
            }*/
            Algorithm alg = new Algorithm();
            alg.a.AddRange(arr);
            alg.StartFullTrip();
            Console.WriteLine("MS: " + alg.MinSum);
            alg.MinH.ForEach(delegate(int i) { Console.Write(i + " -> "); });
            

        }
    }
}