#include <iostream>
using namespace std;
void HexadecimaFunction(int n, int a, int b)
{
	int mask0(0x000000ff);//для нулевого байта
	int mask1(0x0000ff00);//для первого байта
	int mask2(0x00ff0000);//для второго байта
	int mask3(0xff000000);//для третьего байта
	int digit((n >> 28) & 0xf);
	if ((a == 1 && b == 0) || (a == 0 && b == 1)) {
		//замена 1 и 0 байта
	}
	if ((a == 2 && b == 0) || (a == 0 && b == 2)) {
		//замена 2 и 0
	}
	if ((a == 3 && b == 0) || (a == 0 && b == 3)) {
		//замена 3 и 0
	}
	if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
		//замена 1 и 2
	}
	if ((a == 1 && b == 3) || (a == 3 && b == 1)) {
		//замена 1 и 3
	}
	if ((a == 2 && b == 3) || (a == 3 && b == 2)) {
		//замена 2 и 3
	}

	cout << (digit > 9 ? char(digit + 87)
		: char(digit + 48)); // 7
	for (int i = 0; i < 7; ++i, mask >>= 4)
	{
		digit = (n & mask) >> 24 - i * 4;
		cout << (digit > 9 ? char(digit + 87)
			: char(digit + 48)); // 6 - 0
	}
	cout << endl;
}
int main()
{
	int n;
	int a;
	int b;
	do
	{
		cout << "enter the value ";
		cin >> n;
		if (cin.good())
			break;
		else
		{
			cout << "Invalid data!\n";
			cin.clear();
			while (cin.get() != '\n');
		}
	} while (1);
	cout << "enter the number 1 ";//номер первого байта для сдвига 
	cin >> a;
	cout << "enter the number 2 ";//номер другого байта
	cin >> b;

	HexadecimaFunction(n, a, b);
	cout << hex << '\n' << n << endl;
	return 0;
}