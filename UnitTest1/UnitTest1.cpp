#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Project_7.1_it\Project_7.1_it\lab_7.1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// Задаємо тестову матрицю
			int rowCount = 2;
			int colCount = 3;
			int** testMatrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				testMatrix[i] = new int[colCount];

			// Заповнюємо матрицю
			testMatrix[0][0] = -3;
			testMatrix[0][1] = 5;
			testMatrix[0][2] = -9;
			testMatrix[1][0] = -8;
			testMatrix[1][1] = 6;
			testMatrix[1][2] = -12;

			// Змінні для результату
			int sum = 0;
			int count = 0;

			// Викликаємо функцію для обчислення
			CalcSumAndCount(testMatrix, rowCount, colCount, sum, count);

			// Тестуємо очікувані результати
			Assert::AreEqual(-12, sum);  // Сума (-3 + -9 = -12)
			Assert::AreEqual(2, count);  // Кількість елементів (-3, -9)
			Assert::AreEqual(0, testMatrix[0][0]);  // Тестуємо, що -3 замінилося на 0
			Assert::AreEqual(5, testMatrix[0][1]);  // 5 повинно залишитися без змін
			Assert::AreEqual(0, testMatrix[0][2]);  // -9 замінилося на 0
			Assert::AreEqual(-8, testMatrix[1][0]);  // -8 не підпадає під умови заміни
			Assert::AreEqual(6, testMatrix[1][1]);   // 6 не змінюється
			Assert::AreEqual(-12, testMatrix[1][2]); // -12 не замінюється, оскільки ділиться на 4

			// Звільняємо пам'ять
			for (int i = 0; i < rowCount; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}
