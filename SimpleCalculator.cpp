// SimpleCalculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<string>

using namespace std;


//проверка на оператор
bool IsOperator(char ch)
{
	char operators[] = { '+', '-', '*', '/' };
	int size = 4;

	for (int i = 0; i < size; i++)
		if (ch == operators[i])
			return true;

	return false;
}

//решение простого выражения
double solve(char op, double a, double b)
{
	if (op == '+')
		return(a + b);
	else if (op == '-')
		return(a - b);
	else if (op == '*')
		return(a * b);
	else return (a / b);
}

void main(int argc, char* argv[])
{
	string str = argv[1]; // преобразование символьного аргумента в строку

	double num1 = 0, num2 = 0;
	
	size_t ind; //счетчик для длины числа

	num1 = stod(&str[0], &ind); //преобразование строки в float-число

	for (int i = ind; i < str.length(); i++)
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			size_t ind;
			double num2 = stod(&str[i], &ind);
			i += ind - 1;
		}
		if (IsOperator(str[i]))
		{
			size_t ind;
			double num2 = stod(&str[i + 2], &ind);
			num1 = solve(str[i], num1, num2);
			i += ind + 1;
		}
	}
	cout << num1;
}