using System;
using System.Collections.Generic;

namespace findlab
{
    public class Search <T>
    {
        public List<T> a;
        Comparer<T> comparer;
        
        public Search(List<T> arr)
        {
            comparer = Comparer<T>.Default;
            a = arr;
        }

        public int linearSearch(T elem)
        {
            for (int i = 0; i < a.Count; i++)
                if (comparer.Compare(a[i], elem) == 0)
                    return i;
            return -1;

        }

        public int binarySearch(T elem)
        {
            int mid, left = 0, right = a.Count;
            while (true)
            {
                mid = (left + right) / 2;
                if (comparer.Compare(elem, a[mid]) < 0)
                    right = mid - 1; 
                else if (comparer.Compare(elem, a[mid]) > 0)
                    left = mid + 1; 
                else 
                    return mid;
                if (left > right) 
                    return -1;
            }
        }

        public List<int> erythropheneSieve(List<int> list)
        {
            for (int i = 2; i * i < list.Count; i++)
                if (list[i] != 0)
                    for (int j = i*i; j < list.Count; j += i)
                        list[j] = 0;
            
            List<int> res = new List<int>();
            list.ForEach(delegate(int i) { if(i != 0) res.Add(i); });
            return res;
        }
    }
}