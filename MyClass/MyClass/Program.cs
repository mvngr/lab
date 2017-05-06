﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyClass
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
            Book b1 = new Book();
            b1.SetBook("Пушкин А.С.", "Капитанская дочка", "Вильямс", 123, 2012);

            Book.SetPrice(12);
            b1.Show();
            Console.WriteLine("\n Итоговая стоимость аренды: {0} p.", b1.PriceBook(3));

            Book b2 = new Book("Толстой Л.Н.", "Война и мир", "Наука и жизнь", 1234, 2013);
            b2.Show();

            Book b3 = new Book("Лермонтов М.Ю.", "Мцыри");
            b3.Show();
            */

            Triangle t = new Triangle(Double.Parse(Console.ReadLine()),
                                      Double.Parse(Console.ReadLine()),
                                      Double.Parse(Console.ReadLine()));
            t.print();
            Console.WriteLine("Периметр: {0}", t.getPerimeter());
            Console.WriteLine("Площадь: {0}", t.getArea());



            Console.ReadKey();
        }
    }

    class Book
    {
        private String author; // автор
        private String title; // название
        private String publisher; // издательство
        private int pages; // кол-во страниц
        private int year; // год издания

        private static double price = 9;

        public Book(String author, String title, String publisher, int pages, int year)
        {
            this.author = author;
            this.title = title;
            this.publisher = publisher;
            this.pages = pages;
            this.year = year;
        }
        public Book(String author, String title)
        {
            this.author = author;
            this.title = title;
        }
        public Book()
        { }
        static Book() //статический конструктор
        {
            price = 10;
        }
        public void SetBook(String author, String title, String publisher, int pages, int year)
        {
            this.author = author;
            this.title = title;
            this.publisher = publisher;
            this.pages = pages;
            this.year = year;
        }

        public static void SetPrice(double price)
        {
            Book.price = price;
        }

        public void Show()
        {
            Console.WriteLine("\nКнига:\n Автор: {0}\n Название: {1}\n Год издания: {2}\n {3} стр.\n Стоимость аренды: {4}", author, title, year, pages, Book.price);
        }

        public double PriceBook(int s)
        {
            double cust = s * price;
            return cust;
        }

    }

    class Triangle
    {
        double[] sides;

        public Triangle(double a, double b, double c)
        {
            sides = new double[3];
            sides[0] = a;
            sides[1] = b;
            sides[2] = c;
            if (!check())
            {
                Console.WriteLine("Error!");
                sides = null;
            }
        }

        public void print()
        {
            if (!lightCheck())
                return;
            Console.WriteLine("Стороны треугольника:");
            foreach (double v in sides)
                Console.Write("{0} ", v);
            Console.Write('\n');
            return;
        }
        public double getPerimeter()
        {
            if (!lightCheck())
                return -1;
            double res = 0;
            foreach (double v in sides)
                res += v;
            return res;
        }
        public double getArea()
        {
            if (!lightCheck())
                return -1;
            double pp = getPerimeter() / 2;
            return Math.Sqrt(pp * (pp - sides[0]) * (pp - sides[1]) * (pp - sides[2]));
        }
        private bool lightCheck()
        {
            if (sides == null)
                return false;
            else
                return true;
        }
        private bool check()
        {
            for (int i = 0; i < 3; i++)
                sides[i] = Math.Abs(sides[i]);
            if (sides[0] >= sides[1] + sides[2] || sides[1] >= sides[0] + sides[2] || sides[2] >= sides[0] + sides[1])
                return false;
            return true;
            
        }
    }
}
