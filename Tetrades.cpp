
/*Реализация программы по перестановке в введенном пользователем целом числе двух его битовых
* тетрад, номера которых также вводит пользователь
* Визуализация промежуточных результатов в форме двоичного кода с 32 разрядами- действие вспомогательное
* Использование двоичного дампа для представления исходных и результирующих данных
*/
#include <iostream>
#include <bitset>


void BinaryDump(int n)
{
	int mask(010000000000);

	std::cout << (n < 0 ? '1' : '0');
	for (int i = 0; i < 31; ++i, mask >>= 1)
		std::cout << (n & mask ? '1' : '0');
	std::cout << std::endl;
}
int swapTetrades(int n, short int p1, short int p2)
{
	std::cout << "init:   " ;
	BinaryDump(n);

	unsigned int tet1 = (n >> (p1 * 4)) & 0xf;
	std::cout << "tet1:   " << std::bitset<32>(tet1) << "\n";
	unsigned int tet2 = (n >> (p2 * 4)) & 0xf;
	std::cout << "tet2:   " << std::bitset<32>(tet2) << "\n" << std::endl;

	int mask(0xf);

	int mask1 = mask << (p1 * 4);
	int mask2 = mask << (p2 * 4);
	int mask3 = ~(mask2 | mask1);

	int result = ((mask3 & n) | ((tet1 & mask) << (p2 * 4)) | ((tet2 & mask) << (p1 * 4)));
	std::cout << "result: " ;

	BinaryDump(result);
	return result;
}


int main()
{

	int n, a, b;
	do
	{
		std::cout << "Enter an integer number: ";
		std::cin >> n;
		if (std::cin.good())
			break;
		else
		{
			std::cout << "Invalid data!\n";
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
	} while (1);


	do
	{
		std::cout << "Enter numbers of tetrades 0-7: ";
		std::cin >> a;
		std::cin >> b;
		if ((0 <= b) && (7 >= b) && (0 <= a) && (7 >= a))
			break;
		else
		{
			std::cout << "Invalid data!\n";
			std::cin.clear();
			while (std::cin.get() != '\n');
		}
	} while (1);

	int res = swapTetrades(n, a, b);

	std::cout << "Result = " << res << '\n' << std::endl;
	return 0;

}