using Microsoft.VisualStudio.TestTools.UnitTesting;
using Lab2;

namespace TestLab2
{
	[TestClass]
	public class TestMyClass
	{
		[TestMethod]
		public void Max_5_3_expected_5()
		{
			int expected = 5;
			int actual = MyClass.Max(5, 3);
			Assert.AreEqual(expected, actual);
		}
		[TestMethod]
		public void Max_3_5_expected_5()
		{
			int expected = 5;
			int actual = MyClass.Max(3, 5);
			Assert.AreEqual(expected, actual);
		}
	}
}
