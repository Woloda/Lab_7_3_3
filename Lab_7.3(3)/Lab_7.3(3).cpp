//(Ітераційний спосіб)(2 Завдання)
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High);
void matriz_print(int** matriz, const int line, const int column);
void point_sidlova(int** matriz, const int line, const int column);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;

	const int line = 3;
	const int column = 3;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	int High = 97;
	int Low = 16;
	matriz_create(matriz, line, column, Low, High);
	cout << "Сформований масив: " << endl;
	matriz_print(matriz, line, column);

	point_sidlova(matriz, line, column);

	delete[] matriz;

	return 0;
}

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High)
{
	using std::cout;
	using std::endl;
	using std::cin;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
		{
			cout << "a[" << index << "][" << index_j << "] = ";
			cin >> matriz[index][index_j];
		}
		cout << endl;
	}
}

void matriz_print(int** matriz, const int line, const int column)
{
	using std::cout;
	using std::endl;
	cout << endl;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
			cout << std::setw(4) << matriz[index][index_j];
		cout << endl;
	}
	cout << endl;
}

void point_sidlova(int** matriz, int line, const int column)
{
	using std::cout;
	using std::endl;
	int* masuv_min = new int[line];
	int* masuv_max = new int[column];
	for (int index = 0; index < line; index++)
	{
		masuv_min[index] = matriz[index][0];
		for (int index_j = 1; index_j < column; index_j++)
		{
			int min = matriz[index][0];
			if (min > matriz[index][index_j])
			{
				min = matriz[index][index_j];
				masuv_min[index] = matriz[index][index_j];
			}
		}
	}
	for (int index_j = 0; index_j < column; index_j++)
	{
		masuv_max[index_j] = matriz[0][index_j];
		for (int index = 1; index < line; index++)
		{
			int max = matriz[0][index_j];
			if (max < matriz[index][index_j])
			{
				max = matriz[index][index_j];
				masuv_max[index_j] = matriz[index][index_j];
			}
		}
	}

	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < line; index_j++)
		{
			if (masuv_max[index] == masuv_min[index_j])
			{
				cout << "Осідла тоска: " << masuv_max[index] << endl;
				matriz[index_j][index] = 0;    //Для перевірки в юніт-тесті.
			}
			else;
		}
	}
	delete[] masuv_min;
	delete[] masuv_max;
}


