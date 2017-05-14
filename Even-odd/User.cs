using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S_triangle
{
    class User
    {
        private const string LINE = "************";

        public string name;
        int coins;
        int startCoins;

        public User()
        {
            name = "Безымянный";
            coins = 1000;
            startCoins = coins;
        }
        public User(string name, int money)
        {
            this.name = name;
            Coins = money;
            startCoins = coins;
        }
        public User(int money)
        {
            name = "Безымянный";
            coins = money;
            startCoins = coins;
        }
        public int Coins
        {
            set
            {
                if (value >= 0)
                    coins = value;
                else
                    coins = 0;
            }
            get
            {
                return coins;
            }
        }
        public void printInfo()
        {
            Console.WriteLine(LINE);
            Console.WriteLine("Имя: {0}", name);
            if (coins <= startCoins / 2)
                Console.ForegroundColor = ConsoleColor.Red;
            if (coins == 0)
                Console.ForegroundColor = ConsoleColor.DarkRed;
            if (coins >= startCoins * 2)
                Console.ForegroundColor = ConsoleColor.Green;
            if (coins >= startCoins * 3)
                Console.ForegroundColor = ConsoleColor.DarkGreen;
            Console.WriteLine("Монеток: {0}", coins);
            Console.ResetColor();
            Console.WriteLine(LINE);
        }
    }
}
