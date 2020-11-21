#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3(3)/Lab_7.3(3).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab733
{
	TEST_CLASS(UnitTestLab733)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int const line = 3;
			int const column = 3;
			int** matriz = new int* [line];
			for (int index = 0; index < line; index++)
				matriz[index] = new int[column];
			matriz[0][0] = 1; matriz[0][1] = 2;matriz[0][2] = 3;matriz[1][0] = 4;matriz[1][1] = 5;matriz[1][2] = 6;matriz[2][0] = 7;matriz[2][1] = 8;matriz[2][2] = 9;
			point_sidlova(matriz, line, column);
			Assert::AreEqual(matriz[2][0], 0);
			delete[] matriz;
		}
	};
}
