using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Distance
{
    public struct Distance_Struct
    {
        public int foot;
        public int inch;
    }
    class Distance
    {
        static private int changeInch(ref int inch) 
        {
            int res = inch / 12;
            inch %= 12;
            return res;
        }
        static void Main(string[] args)
        {
            Distance_Struct a, b, c;
            
            Console.Write("Введите значение foot 1-ой переменной: ");
            a.foot = Int32.Parse(Console.ReadLine());
            Console.Write("Введите значение inch 1-ой переменной: ");
            a.inch = Int32.Parse(Console.ReadLine());

            Console.Write("Введите значение foot 2-ой переменной: ");
            b.foot = Int32.Parse(Console.ReadLine());
            Console.Write("Введите значение inch 2-ой переменной: ");
            b.inch = Int32.Parse(Console.ReadLine());

            a.foot += changeInch(ref a.inch);
            b.foot += changeInch(ref b.inch);

            c.foot = a.foot + b.foot;
            c.inch = a.inch + b.inch;

            c.foot += changeInch(ref c.inch);

            Console.WriteLine("Результат: {0}' - {1}''", c.foot, c.inch);

            Console.ReadKey();
        }
    }
}
