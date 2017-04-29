using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S_triangle
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Введите значение периметра: ");
            double p = Math.Abs(Int32.Parse(Console.ReadLine()));

            Console.WriteLine("Площадь = {0:0.##}", Math.Sqrt((p/2) * (p/2 - p/3) * 3));
            Console.ReadKey();
        }
    }
}
