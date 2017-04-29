using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Loop
{
    class Program
    {
        struct Shot
        {
            public double x;
            public double y;
        }

        static int getScoreV2(Shot shot)
        {
            //Random rnd = new Random(); 
            double length = Math.Sqrt(shot.x * shot.x + shot.y * shot.y);
            //length += Convert.ToDouble(rnd.Next(100))/10;
            if (length <= 1)
                return 10;
            else
                if (length <= 2)
                    return 5;
                else
                    if (length <= 3)
                        return 1;
            return 0;
        }
        static int getScoreV1(Shot shot)
        {
            Random rnd = new Random();
            double length = Math.Sqrt(shot.x * shot.x + shot.y * shot.y);
            double temp = Convert.ToDouble(rnd.Next(10)) / 10;
            Console.WriteLine("\nСмещение: {0}", temp);
            length += temp;
            if (length <= 1)
                return 10;
            else
                if (length <= 2)
                return 5;
            return 0;
        }
        static void Main(string[] args)
        {
            /*Console.Write("n = ");
            int n = int.Parse(Console.ReadLine());

            Console.Write("\nwhile: \t\t");
            int i = 1;

            while (i <= n)
            {
                Console.Write(" " + i);
                i += 2;
            }

            Console.Write("\ndo while: \t");
            i = 1;
            do
            {
                Console.Write(" " + i);
                i += 2;
            }
            while (i <= n);

            Console.Write("\nFor: \t\t");
            for (i = 1; i <= n; i += 2)
            {
                Console.Write(" " + i);
            }
            
            Console.Write("\n*****\nИспользуйте цикл с постусловиемn\n\nВведите x: ");
            double x = Double.Parse(Console.ReadLine());
            Console.Write("Введите левую границу интервала: ");
            double x1 = Double.Parse(Console.ReadLine());
            Console.Write("Введите правую границу интервала: ");
            double x2 = Double.Parse(Console.ReadLine());
            double y;

            Console.WriteLine("\n x\t\t y");

            x = x1;
            do
            {
                y = Math.Sin(x);
                Console.WriteLine("{0:f3}\t\t{1:f3}", x, y);
                x = x + 0.01;
            }
            while (x <= x2);

            Console.Write("\n*****\nИспользуйте цикл с предусловиемn\n\nВведите a: ");
            int a = Int32.Parse(Console.ReadLine());
            Console.Write("Введите b: ");
            int b = Int32.Parse(Console.ReadLine());

            int temp = a;
            while (temp != b)
            {
                a = temp;
                if (a < b)
                {
                    temp = a;
                    a = b;
                    b = temp;
                }
                temp = a - b;
            a = b;
            }

            Console.WriteLine("НОД = {0}", a);

            Console.Write("*****\nСравните типы циклаn\nВывод значений функции\n\nВведите a: ");

            x = Double.Parse(Console.ReadLine());
            Console.Write("Введите левую границу интервала: ");
            x1 = Double.Parse(Console.ReadLine());
            Console.Write("Введите правую границу интервала: ");
            x2 = Double.Parse(Console.ReadLine());
            
            Console.WriteLine("\n x\t\t y");

            x = x1;
            while (x <= x2)
            {
                y = Math.Sin(x);
                Console.WriteLine("{0:f3}\t\t{1:f3}", x, y);
                x = x + 0.01;
            }

            Console.Write("\nЕвклид\n\n");

            Console.Write("Введите a: ");
            a = Int32.Parse(Console.ReadLine());
            Console.Write("Введите b: ");
            b = Int32.Parse(Console.ReadLine());

            temp = a;
            do
            {
                a = temp;
                if (a < b)
                {
                    temp = a;
                    a = b;
                    b = temp;
                }
                temp = a - b;
                a = b;
            }
            while (temp != b);

            Console.Write("\n*****\nРасчет суммы, используя операторы перехода\n\nВведите k: ");
            int k = Int32.Parse(Console.ReadLine());
            Console.Write("\nВведите b: ");
            int m = Int32.Parse(Console.ReadLine());
            int s = 0;


            for (i = 1; i <= 100; i++)
            {
                if (i > k && i < m) continue;
                s += i;
            }

            Console.WriteLine("Сумма чисел равна {0}", s);
            */
            Console.Write("\n*****\nСтрельбище\n\n");

            List<Shot> shots_log = new List<Shot>();

            int variable, score = 0;
            Shot shot;
            while(true)
            {
                Console.Write("\nВыберите тип мишени [1/2]: ");
                variable = Int32.Parse(Console.ReadLine());
                while (variable != 1 && variable != 2)
                {
                    Console.Write("\nВы неправильно ввели тип мишени, попробуйте ещё раз: ");
                    variable = Int32.Parse(Console.ReadLine());
                }
                Console.Write("\nВведите x: ");
                shot.x = Double.Parse(Console.ReadLine());
                Console.Write("\nВведите y: ");
                shot.y = Double.Parse(Console.ReadLine());

                if (variable == 1)
                    score += getScoreV1(shot);
                else
                    if(variable == 2)
                        score += getScoreV2(shot);
                    else
                    {
                        Console.WriteLine("Ошибка...");
                        Console.ReadKey();
                        return;
                    }

                Console.WriteLine("\nСчёт: {0}", score);
            }
            
        }
    }
}
