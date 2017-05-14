using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S_triangle
{
    class Game
    {
        /*
         * is_odd = 0 - четный
         * is_odd = 1 - нечетный
         */

        public Game() { }
        
        private bool checkIsOdd(int is_odd) //проверка на положительное число в кратности
        {
            if (is_odd >= 0 && is_odd <= 1)
                return true;
            else
                return false;
        }
        private bool checkBet(User u, int bet)
        {
            if (u.Coins < bet)
                return false;
            if (bet <= 0)
                return false;
            return true;
        }
        public bool play(User u, int is_odd, int bet, out bool win)
        {
            win = false;
            if (!checkIsOdd(is_odd) || !checkBet(u, bet))
                return false;

            win = decide(is_odd);
            u.Coins = win ? u.Coins + bet : u.Coins - bet;

            return true;
        }
        private bool decide(int is_odd)
        {
            Random r = new Random();
            if (r.Next() % 2 == is_odd)
                return true;
            else
                return false;
        }
    }
}
