using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace temp
{
    class MyArray<T>
    {
        private List<T> a;
        Comparer<T> comparer;

        public MyArray(List<T> arr){
            comparer = Comparer<T>.Default;
            a = arr;
        }
        public void bubbleSort()
        {
            for(int i = a.Count()-1; i >= 0; i--)
                for(int j = 0; j < i; j++)
                    if(comparer.Compare(a[j], a[j+1]) > 0)
                    {
                        T temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
            return;
        }

        public void insertSort()
        {
            int j;
            for (int i = 1; i < a.Count(); i++)
            {
                T val = a[i];
                for (j = i - 1; j >= 0 && comparer.Compare(a[j], val) > 0; j--)
                    a[j + 1] = a[j];
                a[j + 1] = val;
            }
            return;
        }

        public void selectSort()
        {
            for (int i = 0; i < a.Count(); i++)
            {
                int min_ind = i;
                for (int j = i + 1; j < a.Count(); j++)
                    if (comparer.Compare(a[j], a[min_ind]) < 0)
                        min_ind = j;

                T temp = a[i];
                a[i] = a[min_ind];
                a[min_ind] = temp;
            }
            return;
        }

        public void print()
        {
            a.ForEach(delegate (T elem) { Console.Write(elem.ToString() + ' '); });
        }
    }
}
