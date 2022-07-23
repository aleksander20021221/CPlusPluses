//реализация программного продукта, выполняющего упаковку восьмеричного дампа некоторого целого числа
//в символьный массив с последующей его распаковкой в исходное целое число (архитектура 32-разрядная)
#include <iostream>

using namespace std;

template <typename T>
void OctalDump(T n, char* p)
{
T mask;
int size = 8 * sizeof(T) / 3 + bool(8 * sizeof(T) % 3) - 1;
int bitSize = sizeof(T) * 8;
int offset = 0;

switch (sizeof(T))
{
case 1: // char
mask = 070;
offset = 2;
p[size] = char(((n » bitSize - 2) & 03) + 48);
break;
case 2: // short int
mask = 070000;
offset = 1;
p[size] = char(((n » bitSize - 1) & 01) + 48);
break;
case 4: // int or long int
mask = 07000000000;
offset = 2;
p[size] = char(((n » bitSize - 2) & 03) + 48);
break;
}
for (int i = 1; i <= size; ++i, mask »= 3)
p[size - i] = char(((n & mask) » bitSize - offset - i * 3) + 48);
}

template <typename T>
void print(char* p)
{
int size(8 * sizeof(T) / 3 + bool(8 * sizeof(T) % 3));
for (int i = 0; i < size; ++i)
cout « p[size - i - 1];
cout « endl;
}

template <typename T>
T OctalDumpToNumber(char* p)
{
int size(8 * sizeof(T) / 3 + bool(8 * sizeof(T) % 3));
T number = 0;
for (int i = 0; i < size; i++)
{
int tmp = p[i] - 48;
tmp «= i * 3;
number |= tmp;
}
return number;
}

template<typename T>
void check(T n, char* p)
{
OctalDump<T>(n, p);
print<T>(p);
}

int main()
{
int n;
char pInt[11];
char pShort[6];
char pChar[3];
do
{
cout « "? ";
cin » n;
if (cin.good())
break;
else
{
cout « "Invalid data!\n";
cin.clear();
while (cin.get() != '\n');
}
} while (1);

cout « "Dump from int: \t\t";
check<int>(n, pInt);
cout « "Dump from short: \t";
check<short>(n, pShort);
cout « "Dump from char: \t";
check<char>(n, pChar);

cout « '\n';

cout « "Num from int dump: \t";
cout « OctalDumpToNumber<int>(pInt) « endl;
cout « "Num from short dump: \t";
cout « OctalDumpToNumber<short>(pShort) « endl;
cout « "Num from char dump: \t";
cout « static_cast<int>(OctalDumpToNumber<char>(pChar)) « endl;

cout « '\n';

cout « "Dump from int (dynamic): \t";
char* p = new char[8 * sizeof(int) / 3 + bool(8 * sizeof(int) % 3)];
check(n, p);
cout « "Num from int dump (dynamic): \t";
cout « OctalDumpToNumber<int>(p) « endl;

return 0;
}