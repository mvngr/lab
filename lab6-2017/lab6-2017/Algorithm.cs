using System;
using System.Collections.Generic;
using System.Linq;

namespace lab6_2017
{
	public class Algorithm
	{
		public Algorithm()
		{
			a = new List<List<int>>();
			minH = new List<int>();
		}

		public List<List<int>> a;
		
		private int minSum;
		public int MinSum
		{
			get { return minSum; }
			set {}
		}

		private List<int> minH; 
		public List<int> MinH
		{
			get { return minH; }
			set {}
		}

		private int FullTrip(List<int> h, int sum)
		{
			for(int i = 0; i < a.Count; i++)
				if (h.IndexOf(i) == -1)
					if (a[h.Last()][i] != Int32.MaxValue)
					{
						List<int> copyH = new List<int>();
						copyH.AddRange(h);
						copyH.Add(i);
						if (copyH.Count == a.Count && a[copyH.Last()][copyH.First()] != Int32.MaxValue)
						{
							sum += a[h.Last()][copyH.Last()];
							sum += a[copyH.Last()][copyH.First()];
							if (sum < minSum)
							{
								minSum = sum;
								minH.Clear();
								minH.AddRange(copyH);
							}
							return -1;
						}
						else
						{
							FullTrip(copyH, (sum + a[h.Last()][i]));
							continue;
						}
							
					}
			return -1;
		}

		public void StartFullTrip()
		{
			minSum = Int32.MaxValue;
			FullTrip(new List<int>() {0}, 0);
		}
	}
}