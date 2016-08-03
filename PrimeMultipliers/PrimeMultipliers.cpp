//--- PROBLEM ---
//Напишите функцию, которая перебирает натуральные числа от 1 до N включительно и раскладывает каждое число на простые множители.
//Результат можно выводить на экран либо копить в любой структуре данных. 

#include <iostream>
#include <vector>
using namespace std;

void simpleMultipliers(int& N)
{
	//vector<int> primes;
	vector<int> primes = { 1 }; // initilize vectore with first prime number
	for (int i = 2; i <= N; i++) // find prime numbers from 2 to N
	{
		for (int j = 2; j <= i; j++)
		{
			if (j == i) //  add him to vector
			{
				primes.push_back(i);
			}
			else if (i%j == 0) // if not prime, then jump to next
			{
				break;
			}
		}
	}
	int remainder;
	for (int i = 1; i <= N; i++) // iterate 1 .. N
	{
		cout << "number " << i;
		vector<int>::iterator check = find(primes.begin(), primes.end(), i); // find i in primes
		if (check != primes.end()) // if i belongs primes, then print it
		{
			cout << " is a prime number";
		}
		else // if it's not a prime then looking for multipliers
		{
			cout << " has prime multipliers: ";
			remainder = i;
			for (vector<int>::iterator itr = ++primes.begin(); itr != primes.end(); itr++) // iterate trough primes vector
			{
				if (remainder%*itr == 0) // if multiplier was found then...
				{
					cout << *itr << ", "; // print him...
					remainder /= *itr; // take remainder...
					itr = primes.begin(); // and return iterator to beginning
				}
			}
		}
		cout << endl;
	}
}

int main()
{
	int N;
	while (1)
	{
		cout << "Enter number (1 .. N) or 0 to exit: ";
		cin >> N;
		if (N == 0)
		{
			break;
		}
		else
		{
			simpleMultipliers(N);
		}
	}

	return 0;
}