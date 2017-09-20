using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace temp
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> arr = new List<int>() { 1, 4, 0, 2 };
            MyArray<int> a = new MyArray<int>(arr);
            a.bubbleSort();
            a.print();

            Console.ReadKey();
        }
    }
}
