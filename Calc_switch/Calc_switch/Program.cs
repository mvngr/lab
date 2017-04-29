using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calc_switch
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("A = ");
            double a = double.Parse(Console.ReadLine());
            Console.Write("OP = ");
            char op = char.Parse(Console.ReadLine());
            Console.Write("B = ");
            double b = double.Parse(Console.ReadLine());

            bool ok = true;
            double res = 0;

            switch (op)
            {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/':
                case ':':
                    res = a / b; break;
                default: ok = false; break;
            }

            if (ok)
                Console.WriteLine("{0} {1} {2} = {3}", a, op, b, res);
            else
                Console.WriteLine("Операция не определена");

            Console.Write("\n******\nОпределение високосного года\n\nВведите год:");

            int year = Int32.Parse(Console.ReadLine());

            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                Console.WriteLine("Год високосный");
            else
                Console.WriteLine("Год не високосный");

            Console.ReadKey();
        }
    }
}
