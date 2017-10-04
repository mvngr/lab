using System;
using System.Collections.Generic;

namespace findlab
{
    internal class Program
    {
        private static List<int> list;
        public static void Main(string[] args)
        {
            Timer timer = new Timer();
            list = new List<int>();
            addRN();
            list.Add(300000);
            
            timer.startTimer();
            list.Sort();       
            Console.WriteLine("Sort: " + timer.stopTimer());
            
            Search<int> search = new Search<int>(list);
            

            int ind;
            string timestamp;
            
            timer.startTimer();
            ind = search.linearSearch(300000);
            timestamp = timer.stopTimer();
            Console.WriteLine(ind + " | " + timestamp);
            
            timer.startTimer();
            ind = search.binarySearch(300000);
            timestamp = timer.stopTimer();
            Console.WriteLine(ind + " | " + timestamp);
            
            List<int> intList = new List<int>();
            for (int i = 0; i < 100; i++)
                intList.Add(i);
            
            timer.startTimer();
            search.erythropheneSieve(intList).ForEach(delegate(int i){ Console.Write(i + " "); });
            Console.WriteLine("\nErythrophene time: " + timer.stopTimer());
        }

        private static void addRN()
        {
            Random r = new Random();
            for(int i = 0; i < 1000000; i++)
                list.Add(r.Next(500000));
            return;
        }
    }
}