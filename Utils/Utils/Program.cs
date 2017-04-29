using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Utils
{
    class Program
    {
        static void Main(string[] args)
        {/*
            int x;
            int y;
            Console.WriteLine("Введите первое число:");
            x = int.Parse(Console.ReadLine());
            Console.WriteLine("Введите второе число:");
            y = int.Parse(Console.ReadLine());

            int greater = Utils.Greater(x, y);

            Console.WriteLine("Большим из чисел {0} и {1} является {2} ", x, y, greater);

            Utils.Swap(ref x, ref y);

            Console.WriteLine("До swap: \t" + x + " " + y);
            Utils.Swap(ref x, ref y);
            Console.WriteLine("После swap: \t" + x + " " + y);

            int f;
            bool ok;

            Console.WriteLine("Number for factorial:");
            x = int.Parse(Console.ReadLine());

            ok = Utils.Factorial(x, out f);

            if (ok)
                Console.WriteLine("Factorial(" + x + ") = " + f);
            else
                Console.WriteLine("Cannot compute this factorial");

            Console.WriteLine("\n\n******\n\n Heron's formula \n");
            Console.WriteLine("Input three parameters for a function:");

            double ans = Operation.Heron(Double.Parse(Console.ReadLine()), Double.Parse(Console.ReadLine()), Double.Parse(Console.ReadLine()));
            Console.WriteLine("Result = {0}", ans);

            Console.WriteLine("\n\n******\n\n Results of the quadratic equation \n");
            */
            double r1, r2;

            Console.WriteLine("Input three parameters for a function:");
            int ans2 = Operation.resFunc(Double.Parse(Console.ReadLine()), Double.Parse(Console.ReadLine()), Double.Parse(Console.ReadLine()), out r1, out r2);
            switch (ans2) {
                case -1:
                    Console.WriteLine("Error: Discriminant < 0");
                    break;
                case 0:
                    Console.WriteLine("Result: {0}", r1);
                    break;
                case 1:
                    Console.WriteLine("Result: {0} \t {1}", r1, r2);
                    break;
                default:
                    Console.WriteLine("Fatal error!");
                    return;
            }

            Console.ReadKey();
        }
    }

    class Utils
    {
        public static int Greater(int a, int b)
        {
            if (a > b)
                return a;
            else
                return b;
        }
        public static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        public static bool Factorial(int n, out int answer)
        {
            int k; // Loop counter
            int f = 1; // Working value
            bool ok = true; // True if okay, false if not

            checked { for (k = 2; k <= n; ++k) { f = f * k; } }

            try
            { 
                checked
                {
                    for (k = 2; k <= n; ++k)
                        f *= k;
                }
            }
            catch (Exception)
            {
                f = 0;
                ok = false;
            }

            answer = f;
            return ok;
        }

    }
    class Operation
    {
        public static double Heron(double a, double b, double c)
        {
            double p = (a + b + c) / 2;
            if (check(a, b, c))
                return a = Math.Sqrt(p * (p - a) * (p - b) * (p - c));
            else
                return 0;
        }
        public static double Heron(double a)
        {
            if (check(a))
                return Math.Sqrt((3 * a / 2) * ((3 * a / 2) - a) * 3);
            else
                return 0;
        }
        private static bool check(double a, double b, double c)
        {
            if (a <= 0 || b <= 0 || c <= 0)
            {
                Console.WriteLine("Error: One side is less or equal than zero");
                return false;
            }

            if (a - b - c >= 0 || b - a - c >= 0 || c - a - b >= 0)
            {
                Console.WriteLine("Error: One side is more than two others");
                return false;
            }

            return true;
        }
        private static bool check(double a)
        {
            if (a <= 0)
            {
                Console.WriteLine("Error: Side is less or equal than zero");
                return false;
            }
            return true;
        }
        public static int resFunc(double a, double b, double c, out double res1, out double res2)
        {
            res1 = 0; res2 = 0;
            
            double disc = Math.Sqrt(b * b - 4 * a * c);
           
            if(Double.IsNaN(disc))
                return -1;

            res1 = (-b + disc) / (2 * a);
            if(disc == 0)
            {
                res2 = res1;
                return 0;
            }
            res2 = (-b - disc) / (2 * a);
            return 1;
        }
    }
}
