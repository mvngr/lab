using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shape
{
    class Program
    {
        const double PI = 3.14;
        static void Main(string[] args)
        {
            Triangle t = new Triangle(22.5);
            Circle c = new Circle(4);
            Square s = new Square(6);

            t.print();
            c.print();
            s.print();

            Console.WriteLine("Периметр t = {0}", t.p());
            Console.WriteLine("Периметр c = {0}", c.p());
            Console.WriteLine("Периметр s = {0}", s.p());

            Console.WriteLine("Площадь t = {0}", t.s());
            Console.WriteLine("Площадь c = {0}", c.s());
            Console.WriteLine("Площадь s = {0}", s.s());

            Console.ReadKey();
        }
        interface IRotation
        {
            void rotation();
        }
        abstract class Shape
        {
            public abstract double s();
            public abstract double p();
            public abstract void print();
        }

        class Triangle : Shape, IRotation
        {
            private double a;
            public Triangle(double a)
            {
                this.a = a;
            }
            public override double p()
            {
                return a * 3;
            }

            public override void print()
            {
                Console.WriteLine("Длина стороны треугольника: {0}", a);
                return;
            }

            public void rotation()
            {
                
            }

            public override double s()
            {
                double pp = p() / 2;
                return Math.Sqrt(pp * (pp - a) * 3);
            }
        }
        class Circle : Shape
        {
            private double r;
            public Circle(double r)
            {
                this.r = r;
            }
            public override double p()
            {
                return 2 * PI * r;
            }

            public override void print()
            {
                Console.WriteLine("Радиус: {0}", r);
                return;
            }

            public override double s()
            {
                return PI * r * r;
            }
        }
        class Square : Shape, IRotation
        {
            private double a;
            public Square(double a)
            {
                this.a = a;
            }
            public override double p()
            {
                return a * 4;
            }

            public override void print()
            {
                Console.WriteLine("Длина стороны: {0}", a);
                return;
            }

            public void rotation()
            {
                
            }

            public override double s()
            {
                return a * a;
            }
        }
    }
}
