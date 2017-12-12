using System.Collections.Generic;
using System.Linq;

namespace lab8_2017
{
    public class Alghoritm : Matrix
    {
        public Alghoritm(List<List<int>> array) : base(array){}
        
        public int Sevidge()
        {
            var riskMatrix = new List<List<int>>();
            var maxCol = new List<int>();
            
            for (int i = 0; i < A[0].Count; i++)
                maxCol.Add(int.MinValue);
            
            foreach (var v in A)
                for (int i = 0; i < v.Count; i++)
                    if (v[i] > maxCol[i])
                        maxCol[i] = v[i];

            for (int i = 0; i < A.Count; i++)
            {
                riskMatrix.Add(new List<int>());
                for (int j = 0; j < A[0].Count; j++)
                    riskMatrix[i].Add(maxCol[j] - A[i][j]);
            }
            
            maxCol.Clear(); // maxCol will be result MAX for row
            maxCol.AddRange(riskMatrix.Select(v => v.Max()));
            return maxCol.IndexOf(maxCol.Min()) + 1; //if index begin with 1
            //bad code :C
        }

        public int Hurwitz(double factor)
        {
            var temp = A.Select(v => factor * v.Min() + (1 - factor) * v.Max()).ToList();
            return temp.IndexOf(temp.Max()) + 1; //if index begin with 1
        }

        public int Wald()
        {
            var temp = A.Select(v => v.Min()).ToList();
            return temp.IndexOf(temp.Max()) + 1;
        }

        public int ExtremeOptimism()
        {
            var temp = A.Select(v => v.Max()).ToList();
            return temp.IndexOf(temp.Max()) + 1;
        }
    }
}