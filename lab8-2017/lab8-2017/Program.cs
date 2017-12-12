using System;
using System.Collections.Generic;

namespace lab8_2017
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var list = new List<List<int>>
            {
                new List<int>() {5, 6, 2, 6},
                new List<int>() {3, 6, 7, 7},
                new List<int>() {4, 5, 8, 1},
                new List<int>() {4, 6, 9, 2}
            };
            var a = new Alghoritm(list);
            a.Print();
            Console.WriteLine("Servege: " + a.Sevidge());
            Console.WriteLine("Input factor for Hurwitz method [0 .. 1]: ");
            Console.WriteLine("Hurwitz: " + a.Hurwitz(double.Parse(Console.ReadLine())));
            Console.WriteLine("Wald: " + a.Wald());
            Console.WriteLine("ExtremeOptimism: " + a.ExtremeOptimism());
        }
    }
}