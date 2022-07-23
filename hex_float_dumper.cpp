//упаковка шестнадцатеричного дампа вещественного числа в одномерный массив символов
//с последующей распаковкой его для получения исходного числа
//в 32-разрядной архитектуре
#include <iostream>
using namespace std;

int hexToInt(char ch)
{
	return ch - '0' > 9 ? ch - 'A' + 10 : ch - '0';
}

char intToHex(int num)
{
	static char hexAlphabet[] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
	};
	return hexAlphabet[num];
}

template<typename T>
void hexDump(T num, char* ptr)
{
	int hexMask = 0b1111;
	int size = sizeof(T) * 8 / 4;
	long long castedNum = *reinterpret_cast<long long*>(&num);

	for (int i = 0; i < size; i++, castedNum >>= 4)
		ptr[size - 1 - i] = intToHex(castedNum & hexMask);
}

template<typename T>
T hexUndump(char* ptr)
{
	long long result = 0;
	int size = sizeof(T) * 8 / 4;

	for (int i = 0; i < size; i++)
	{
		result <<= 4;
		result |= hexToInt(ptr[i]);
	}

	return *reinterpret_cast<T*>(&result);
}

template<typename T>
void printHexDump(char* p)
{
	int size = sizeof(T) * 8 / 4;
	for (int i = 0; i < size; i++)
		cout << p[i];
	cout << '\n';
}

int main()
{
	double number = 0.;
	cout.precision(6); // count of decimal places
	cout << fixed;

	do
	{
		cout << "Enter number: ";
		cin >> number;
		if (cin.good())
			break;
		else
		{
			cout << "Invalid data!\n";
			cin.clear();
			while (cin.get() != '\n');
		}
	} while (1);

	char* p = new char[8];
	hexDump<float>(number, p);
	cout << "Dumped float:\t\t"; printHexDump<float>(p);
	cout << "Undumped float:\t\t" << hexUndump<float>(p) << '\n';
	delete[] p;

	cout << endl;

	return 0;
}