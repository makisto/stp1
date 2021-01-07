using Microsoft.VisualStudio.TestTools.UnitTesting;
using ClassLibrary1;

namespace UnitTestLibrary1
{
	[TestClass]
	public class TestMyClass
	{
		[TestMethod]
		public void Max_3_5_expected_5()
		{
			int expected = 5;
			int actual = MaxOfTwoElements.Max(3, 5);
			Assert.AreEqual(expected, actual);
		}
		[TestMethod]
		public void Max_5_3_expected_7()
		{
			int expected = 5;
			int actual = MaxOfTwoElements.Max(5, 3);
			Assert.AreEqual(expected, actual);
		}
		[TestMethod]
		public void Count_max_index_expected_20()
		{
			const int n = 5;
			const int m = 5;
			double[,] mas = new double[n, m]
			{
				{1.0, 2.0, 3.0, 4.0, 5.0},
				{2.0, 3.0, 4.0, 5.0, 6.0},
				{3.0, 4.0, 5.0, 6.0, 7.0},
				{4.0, 5.0, 6.0, 7.0, 8.0},
				{5.0, 6.0, 7.0, 8.0, 9.0}
			};
			double expected = 25.0;
			double actual = CountMaxIndex.Count_max_index(mas, n, m);
			Assert.AreEqual(expected, actual);
		}
		[TestMethod]
		public void Count_lower_diag_expected_10()
		{
			const int n = 5;
			const int m = 5;
			double[,] mas = new double[n, m]
			{
				{1.0, 2.0, 3.0, 4.0, 5.0},
				{2.0, 3.0, 4.0, 5.0, 6.0},
				{3.0, 4.0, 5.0, 6.0, 7.0},
				{4.0, 5.0, 6.0, 7.0, 8.0},
				{5.0, 6.0, 7.0, 8.0, 9.0}
			};
			double expected = 55.0;
			double actual = LowerDiag.Count_up_diag(mas, n, m);
			Assert.AreEqual(expected, actual);
		}
	}
}
