using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatrixMultiply
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            int[,] a = inp();

            int[,] b = inp();
            int[,] result = Multiply(a, b);

            printArray(result);
            */
            Console.Write("Введите количество элементов в массиве: ");
            int n = Int32.Parse(Console.ReadLine());
            
            int[] a = new int[n];

            int sum = 0, negativeSum = 0, positiveSum = 0, evenSum = 0, oddSum = 0;
            for(int i = 0; i < a.Length; i++)
            {
                Console.Write("a[{0}] = ", i);
                a[i] = Int32.Parse(Console.ReadLine());
                sum += a[i];
                if (a[i] > 0)
                    positiveSum += a[i];
                if (a[i] < 0)
                    negativeSum += a[i];
                if (i % 2 == 0)
                    evenSum += a[i];
                else
                    oddSum += a[i];
            }
            
            Console.WriteLine("Сумма всех элементов: {0}", sum);
            Console.WriteLine("Среднее значение: {0}", (double)sum/a.Length);
            Console.WriteLine("Сумма четных элементов: {0}", evenSum);
            Console.WriteLine("Сумма нечетных элементов: {0}", oddSum);
            Console.WriteLine("Сумма отрицательных элементов: {0}", negativeSum);
            Console.WriteLine("Сумма положительных элементов: {0}", positiveSum);

            int maxIndex = a.ToList().IndexOf(a.Max());
            int minIndex = a.ToList().IndexOf(a.Min());
            Console.WriteLine("Индекс максимального числа: {0}", maxIndex);
            Console.WriteLine("Индекс минимального числа: {0}", minIndex);

            int res = 1;
            if (maxIndex > minIndex)
                for (int i = minIndex; i < maxIndex; i++)
                    res *= a[i];
            else
                for (int i = maxIndex; i < minIndex; i++)
                    res *= a[i];


            Console.ReadKey();
        }

        private static int[,] inp()
        {
            int[,] a = new int[2, 2];
            for (int r = 0; r < a.GetLength(0); r++)
                for (int c = 0; c < a.GetLength(1); c++)
                {
                    Console.Write("Enter value for [{0},{1}] : ", r, c);
                    string s = System.Console.ReadLine();
                    a[r, c] = int.Parse(s);
                }
            Console.WriteLine();
            return a;
        }
        private static int[,] Multiply(int[,] a, int[,] b)
        {
            int[,] result = new int[2, 2];
            for (int r = 0; r < result.GetLength(0); r++)
                for (int c = 0; c < result.GetLength(1); c++)
                    result[r, c] += a[r, 0] * b[0, c] + a[r, 1] * b[1, c];
            return result;
        }
        private static void printArray(int[,] result)
        {
            for (int r = 0; r < result.GetLength(0); r++)
            {
                for (int c = 0; c < result.GetLength(1); c++)
                    Console.Write("{0} ", result[r, c]);
                Console.WriteLine();
            }
        }
    }
}
