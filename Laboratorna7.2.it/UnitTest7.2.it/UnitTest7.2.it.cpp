#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna7.2.it/Laboratorna7.2.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72it
{
	TEST_CLASS(UnitTest72it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			int Sum = 3 + 6 + 9;

			int actualSum = findSumOfMaxInAllRows(a, rowCount, colCount);

			Assert::AreEqual (Sum, actualSum);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
