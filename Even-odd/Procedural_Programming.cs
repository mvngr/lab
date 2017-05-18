using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S_triangle
{
    class Procedural_Programming
    {
        private const string LINE = "************";

        string name;
        int coins;
        int startCoins;
        bool keyMethod;
        int key_def_bet;
        string err;

        List<string> log;

        public Procedural_Programming() { }
        void print_header()
        {
            Console.WriteLine(LINE);
            Console.WriteLine("Имя: {0}", name);
            if (coins <= startCoins / 2)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                if (coins == 0)
                    Console.ForegroundColor = ConsoleColor.DarkRed;
            }
            if (coins >= startCoins * 2)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                if (coins >= startCoins * 3)
                    Console.ForegroundColor = ConsoleColor.DarkGreen;
            }
            Console.WriteLine("Монеток: {0}", coins);
            Console.ResetColor();
            Console.WriteLine(LINE);
            return;
        }
        void read_header()
        {
            Console.WriteLine(LINE);
            Console.Write("Имя: ");
            name = Console.ReadLine();
            Console.Write("Монеток: ");
            try
            {
                coins = Int32.Parse(Console.ReadLine());
                startCoins = coins;
            }
            catch (Exception)
            {
                coins = 0;
                startCoins = coins;
            }
        }
        void addLog(string s)
        {
            log.Add(s);
            if (log.Count > 10)
                log.RemoveAt(0);
        }
        string getLog()
        {
            if (log.Count == 0)
                return "";
            string res = "";
            foreach (string i in log)
                res = res + i + '\n';
            res += LINE;
            return res;
        }
        int convertToIsOdd(string s)
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
        bool checkIsOdd(int is_odd)
        {
            if (is_odd >= 0 && is_odd <= 1)
                return true;
            else
                return false;
        }
        bool checkBet(int bet)
        {
            if (coins < bet)
                return false;
            if (bet <= 0)
                return false;
            return true;
        }
        bool play(int is_odd, int bet, out bool win)
        {
            win = false;
            if (!checkIsOdd(is_odd) || !checkBet(bet))
                return false;

            win = decide(is_odd);
            coins = win ? coins + bet : coins - bet;

            return true;
        }
        bool decide(int is_odd)
        {
            Random r = new Random();
            if (r.Next() % 2 == is_odd)
                return true;
            else
                return false;
        }

        public void main()
        {
            keyMethod = false;
            key_def_bet = -1;
            err = "";
            log = new List<string>();

            read_header();


            while (true)
            {
                Console.Clear();

                print_header();
                Console.WriteLine(getLog());
                Console.WriteLine(err);
                err = "";

                string[] str_arr;

                if (!keyMethod)
                {
                    str_arr = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                }
                else
                {
                    
                    if (key_def_bet == -1)
                    {
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
                        print_header();
                        break;
                    }
                    err = "Некорректные данные";
                    continue;
                }


                bool res = play(convertToIsOdd(str_arr[0]), Int32.Parse(str_arr[1]), out bool win);
                if (!res)
                {
                    err = "Ошибка: ставка не может быть меньше нуля и не может привышать вас баланс";
                    continue;
                }

                string temp = (win) ? "Выйграл " + str_arr[1] : "Проиграл " + str_arr[1];
                addLog(temp);
            }
        }
    }
}
