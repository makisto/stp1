using System;
using System.Collections.Generic;
using System.Text;

namespace ClassLibrary1
{
	public class LowerDiag
	{
		public static double Count_up_diag(double[,] a, int n, int m)
        {
            double sum = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if ((i + j) <= n - 1)
                    {
                        sum += a[i, j];
                    }
                }
            }

            return sum;
        }
    }
}
