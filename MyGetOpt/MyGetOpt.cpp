//--- PROBLEM ---
//Напишите простую реализацию функции для разбора параметров командной строки(getopt).
//Полагаем, что нам требуется структура данных, содержащая заранее известный допустимый набор параметров различного типа - 
//строки, целые, числа с плавающей точкой и т.д., а также признак, является ли этот параметр обязательным.
//Полагаем, что параметры могут передаваться только в "длинном" формате с обязательным "--" перед именем параметра
//(то есть "--my-option-name my-option-val", "--my-option-name=my-option-val", "--my-boolean-option").
//Параметров может быть несколько.
//Функция должна обязательно уметь обрабатывать параметр "--help" (если он указан в списке параметров при вызове функции),
//выводящий пример использования(необязательные параметры должны выводиться в квадратных скобках). 

#include <iostream>
#include <string>
//#include <cstdlib>
using namespace std;

const struct option
{
	char *name;
	bool required;
	int numArguments;
	int intArg1;
	int intArg2;
	float floatArg1;
	float floatArg2;
	char *string1;
	char *string2;
};

void helpHandler(const struct option optionList[], int size)
{
	cout << "--- Help ---\n"; // just a title
	cout << "[parameter] - these parameters are optional\n";
	for (int j = 0; j < size; j++) // iterate through option list
	{
		cout << "Argument " << j + 1 << ": ";
		if (!optionList[j].required) // add [] if option is not required
		{
			cout << '[';
		}
		cout << optionList[j].name; // display option's name
		if (!optionList[j].required)
		{
			cout << ']'; // add [] if option is not required
		}
		cout << " must have " << optionList[j].numArguments << " parameter(s)"; // display number of arguments
		if (optionList[j].numArguments) // if there are some arguments
		{
			if (optionList[j].name == "--float")
			{
				cout << ": " << optionList[j].floatArg1 << ", " << optionList[j].floatArg1 << '\n';
			}
			else if (optionList[j].name == "--int")
			{
				cout << ": " << optionList[j].intArg1 << '\n';
			}
			else if (optionList[j].name == "--string")
			{
				cout << ": " << optionList[j].string1 << ", " << optionList[j].string2 << '\n';
			}
			else if (optionList[j].name == "--answer")
			{
				cout << ": " << optionList[j].intArg1 << '\n';
			}
		}
		else
		{
			cout << '\n';
		}
	}
	cout << "--- End help ---" << endl;
}

void myGetOpt(int argc, char *argv[], const struct option optionList[], int size)
{
	cout << "The programm name: " << argv[0] << '\n'; // first argument always is a file name
	int counter; // counter for struct option members
	for (int i = 1, counter = 0; i < argc; counter++) // iterate through argv array
	{
		string arg = argv[i];
		if (arg == "--help") // handle help case
		{
			helpHandler(optionList, size);
			break;
		} // the end of help handler
		else if (arg == optionList[counter].name) // if argument match optionList
		{
			cout << "Argument " << arg;
			if (optionList[counter].numArguments) // if there are any values
			{
				cout << " has value(s): ";
				int tempArgNum = optionList[counter].numArguments;
				for (int j = 1; j <= tempArgNum; j++) // iterate next argv elements to get values
				{
					string argNext = argv[i + j];
					if (argNext[0] == '-') // check if there is already next command
					{
						cout << "too few parameters for " << arg << "!\n";
						helpHandler(optionList, size);
						break;
					}
					else
					{
						cout << argNext << ' ';
					}
				}
				i += tempArgNum + 1;
			} // end for parameter values
			else
			{
				cout << " doesn't have any values";
				i++;
			}
			cout << endl;
		}
		else if (!optionList[counter].required) // if current options not required then jump to next
		{
			continue;
		}
		else // in other case we have a wrong input
		{
			cout << arg << " - inadmissible parameter: " << optionList[counter].name
				<< " need " << optionList[counter].numArguments << " arguments!\n";
			helpHandler(optionList, size); // display help so we can try again with correct parameters
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	const struct option optionList[]
	{
		{"--float", true, 2, 0, 0, 3.14, 2.54, 0, 0},
		{"--int", true, 1, 100, 0, 0, 0, 0},
		{"--string", false, 2, 0, 0, 0, 0, "string", "string"},
		{"--answer", false, 1, 42, 0, 0, 0, 0, 0},
		{"--help", false, 0, 0, 0, 0, 0, 0, 0}
	};

	myGetOpt(argc, argv, optionList, 5);

	return 0;
}