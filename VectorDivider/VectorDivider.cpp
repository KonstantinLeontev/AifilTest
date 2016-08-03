//--- PROBLEM ---
//Имеется вектор размера N.Необходимо разделить его на M < N равных частей
//(то есть чтобы количество элементов в каждой части было одинаковым).
//Части не должны пересекаться и должны покрывать весь вектор
//(исключение - допускаются промежутки от начала вектора до начала первой части и от конда последней части до конца вектора,
//но в этом случае необходимо добиться, чтобы разница в величине этих промежутков была минимальной).
//Результатом должны являться индексы начала и конца каждой части(либо вывод на экран, либо сохранение в любую структуру данных). 

#include <iostream>
#include <vector>
using namespace std;

void vectorDivider(int& N, int& M)
{
	cout << "Vector N = " << N << " / M = " << M << ": " << endl;
	int remainder = N%M; // check for remainder
	if (remainder == 0) // if all parts are equal
	{
		int part = N / M;
		int counter = 1;
		for (int i = 0; i < N; i += part)
		{
			cout << "Part " << counter << ": " << i << ", " << i + part - 1 << endl;
			counter++;
		}
	}
	else // if parts are not equal
	{
		int part = (N - remainder) / M;
		int first{ 0 }, last{ 0 };
		if (remainder > 1) // then there are two parts
		{
			first = remainder / 2;
			cout << "First part length: " << first << endl; // test line
			last = remainder - first;
			cout << "Last part length: " << last << endl; // test line
		}
		else // then there is only one part
		{
			first = 1;
		}		
		cout << "Part first: " << 0;
		if (first > 1)
		{
			cout << ", " << first;
		}
		cout << endl;
		int counter = 1;
		for (int i = first; i < N - last; i += part) // iterate through equals
		{
			cout << "Part " << counter << ": " << i << ", " << i + part - 1 << endl;
			counter++;
		}
		if (last == 1) // if last exist and it's 0
		{
			cout << "Part last: " << N - last << endl;;
		}
		else if (last > 1) // if last exist and greater than 1
		{
			cout << "Part last: " << N - last << ", " << N - 1  << endl;
		}		
	}
}

int main()
{
	while (1)
	{
		int N, M;
		cout << "Enter the size of vector (4 .. N) or 0 to exit: ";
		cin >> N;
		if (N == 0)
		{
			break;
		}
		cout << "Enter the number of parts (2 .. M) or 0 to exit: ";
		cin >> M;
		if (M == 0)
		{
			break;
		}
		vectorDivider(N, M);
	}

	return 0;
}