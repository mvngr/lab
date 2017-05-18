using System;
using System.Linq;

namespace S_triangle
{
    class Program
    {
        private const string LINE = "************";

        static int convertToIsOdd(string s) // все варианты ввода ставки на чёт/нечёт
        {
            switch (s)
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
        static void keyMethod()
        {

        }
        static void Main(string[] args)
        {
            Procedural_Programming p = new Procedural_Programming();
            p.main();
            /*
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

            //метод считывания нажатий
            bool keyMethod = false;
            int key_def_bet = -1; //стандартная ставка для нажатий

            string err = "";
            while (true)
            { //игра до того момента, пока не наберу stop/стоп
                Console.Clear();

                ur.printInfo();
                Console.WriteLine(h.Log);
                Console.WriteLine(err);
                err = "";

                string[] str_arr;

                if (!keyMethod)
                {
                    str_arr = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                }
                else
                {
                    if (key_def_bet == -1){
                        Console.Write("Введите стандартную ставку: ");
                        while (key_def_bet < 1)
                        {
                            try
                            {
                                key_def_bet = Int32.Parse(Console.ReadLine());
                            }
                            catch (Exception)
                            {
                                key_def_bet = -1;
                            }
                        }
                    }
                    str_arr = new string[2];
                    str_arr[0] = Console.ReadKey().KeyChar.ToString();
                    str_arr[1] = key_def_bet.ToString();
                }
                if (str_arr.Length != 2 || convertToIsOdd(str_arr[0]) == -1)
                {
                    if (str_arr.Length == 0)
                        continue;
                    if (str_arr[0] == "key")
                    {
                        keyMethod = true;
                        err = "Включена игра при помощи клавиш";
                        continue;
                    }
                    if(str_arr[0] == "s")
                    {
                        keyMethod = false;
                        key_def_bet = -1;
                        err = "Отменена игра клавишами";
                        continue;
                    }
                    if (str_arr[0] == "stop" || str_arr[0] == "стоп")
                    {
                        Console.WriteLine("Игра завершена!");
                        ur.printInfo();
                        break;
                    }
                    err = "Некорректные данные";
                    continue;
                }


                bool res = g.play(ur, convertToIsOdd(str_arr[0]), Int32.Parse(str_arr[1]), out bool win);
                if (!res)
                {
                    err = "Ошибка: ставка не может быть меньше нуля и не может привышать вас баланс";
                    continue;
                }

                string temp = (win) ? "Выйграл " + str_arr[1] : "Проиграл " + str_arr[1];
                h.Log = temp;
                
            }
            */
            Console.ReadKey();

        }
        
    }
}
