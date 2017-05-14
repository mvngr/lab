using System;
using System.Linq;

namespace S_triangle
{
    class Program
    {
        private const string LINE = "************";

        static int convertToIsOdd(string s) // все варианты ввода ставки на чёт/нечёт
        {
            switch(s)
            {
                case "четный":
                case "чет":
                case "0":
                case "2":
                case "ч":
                    return 0;
                case "нечетный":
                case "нечет":
                case "1":
                case "н":
                    return 1;
                default:
                    return -1;
            }
        }
        static void Main(string[] args)
        {
            Console.WriteLine(LINE);
            Console.Write("Имя: ");
            string name = Console.ReadLine();
            Console.Write("Монеток: ");
            int coins;
            try
            {
                coins = Int32.Parse(Console.ReadLine());
            }
            catch (Exception)
            {
                coins = 0;
            }

            User ur = new User(name, coins);
            ur.printInfo();

            Game g = new Game();
            History h = new History();

            string err = "";
            while (true) { //игра до того момента, пока не наберу stop/стоп
                Console.Clear();

                ur.printInfo();
                Console.WriteLine(h.Log);
                Console.WriteLine(err);
                err = "";

                string[] mass = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                
                if (mass.Length != 2 || convertToIsOdd(mass[0]) == -1)
                {
                    if (mass[0] == "stop" || mass[0] == "стоп")
                    {
                        Console.WriteLine("Игра завершена!");
                        ur.printInfo();
                        break;
                    }
                    err = "Некорректные данные";
                    continue;
                }

                bool res = g.play(ur, convertToIsOdd(mass[0]), Int32.Parse(mass[1]), out bool win);
                if (!res)
                {
                    err = "Ошибка: ставка не может быть меньше нуля и не может привышать вас баланс";
                    continue;
                }
                
                string temp = (win) ? "Выйграл " + mass[1] : "Проиграл " + mass[1];
                h.Log = temp;

                ur.printInfo();

                Console.WriteLine("{0}", h.Log);
            }

            Console.ReadKey();
        }
    }
}
