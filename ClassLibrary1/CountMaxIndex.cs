using System;
using System.Collections.Generic;
using System.Text;

namespace ClassLibrary1
{
	public class CountMaxIndex
	{
		public static double Count_max_index(double [,]a, int n, int m)
		{
            double sum = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if ((i + j) == m - 1)
                    {
                        sum += a[i, j];
                    }
                }
            }

            return sum;
        }
	}
}
