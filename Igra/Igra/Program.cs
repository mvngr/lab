using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Igra
{
    class Program
    {
        static void Main(string[] args)
        {/*
            Gamer g1 = new Gamer("Niko");
            for (int i = 1; i <= 6; i++)
                Console.WriteLine("Выпало количество очков {0} для игрока {1}", g1.SeansGame(), g1.ToString());
    */
            ArithmeticProgression ap = new ArithmeticProgression();

            Console.WriteLine("{0}", ap.GetElement(3));
            Console.WriteLine("{0}", ap.GetElement(3, 2, 2));

            GeometricProgression gp = new GeometricProgression();

            Console.WriteLine("{0}", gp.GetElement(8));
            Console.WriteLine("{0}", gp.GetElement(1, 10, 2));

            Console.ReadKey();
        }

        class IgralnayaKost
        {
            Random r;

            public IgralnayaKost()
            {
                r = new Random();
            }
            public int random()
            {
                int res = r.Next(6) + 1;
                return res;
            }

        }
        class Gamer
        {
            string Name;
            IgralnayaKost seans;

            public Gamer(string name)
            {
                Name = name;
                seans = new IgralnayaKost();
            }
            public int SeansGame()
            {
                return seans.random();
            }
            public override string ToString()
            {
                return Name;
            }
        }
        abstract class Progression
        {
            public abstract int GetElement(int k);
        }

        class ArithmeticProgression : Progression
        {
            public ArithmeticProgression() { }
            private int calc(int start, int k, int d)
            {
                return start + (k - 1) * d;
            }
            public override int GetElement(int k)
            {
                return calc(0, k, 1);
            }
            public int GetElement(int start, int k, int d)
            {
                return calc(start, k, d);
            }
        }
        class GeometricProgression : Progression
        {
            public GeometricProgression() { }

            private int calc(int start, int k, int d)
            {
                return start * (int) Math.Pow((double)d, (double)(k - 1));
            }
            public override int GetElement(int k)
            {
                return calc(1, k, 2);
            }
            public int GetElement(int start, int k, int d)
            {
                return calc(start, k, d);
            }
        }
    }
}
