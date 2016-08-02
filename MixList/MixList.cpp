// --- PROBLEM ---
//Имеется простой односвязный список размера N.
//Необходимо реализовать алгоритм, который перепаковывает список так, чтобы за первым элеметом следовал последний, затем второй, затем предпоследний и т.д.
//Пример работы алгоритма :
//исходный список : 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8
//перепакованный список : 1 - 8 - 2 - 7 - 3 - 6 - 4 - 5.
//Оценить сложность предложенного алгоритма.

#include <iostream>
#include <vector>

using namespace std;

void fillList(vector<int>& list, int& N)
{
	for (int i = 0; i < N; i++)
	{
		list[i] = i + 1;
	}
}

void printList(vector<int>& list, int& N)
{
	cout << "--- Start list ---" << '\n';
	for (int i = 0; i < N; i++)
	{
		cout << list[i];
		if (i != N - 1)
		{
			cout << " - ";
		}
		else
		{
			cout << '.';
		}
	}
	cout << "\n--- End list ---" << endl;
}

void mixList(vector<int>& list, int& N)
{
	int last; // last element value
	vector<int>::iterator itr = ++list.begin(); // iterator starts from second element
	for (int i = 0; i < N - 2; i += 2, itr = list.begin() + i + 1) // iterate through half of the list
	{
		last = list.back(); // copy value from last element
		list.insert(itr, last); // insert last value after each second
		list.pop_back(); // remove last element
	}
}

int main()
{
	while (1)
	{
		int N;
		cout << "Please enter a length N (2 - 1000) or 0 for exit: ";
		cin >> N;
		if (N == 0)
		{
			break;
		}
		else if (N < 0 || N > 1000 || N == 1)
		{
			cout << "Incorrect input. Please try again!" << endl;
			continue;
		}
		else
		{
			vector<int> list(N);
			fillList(list, N); // fill list 0 .. N numbers
			printList(list, N); // display list
			mixList(list, N); // insert last numbers after each second
			printList(list, N); // display changed list
		}
	}
	return 0;
}