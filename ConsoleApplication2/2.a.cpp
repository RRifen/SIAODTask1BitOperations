#include <iostream>
#include <bitset>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Вводите числа от 0 до 7 (или -1, чтобы закончить ввод): ";
	int temp;
	unsigned char bitmas = 0;
	unsigned char maska = 1; // 0000 0001
	cin >> temp;
	while (temp != -1)
	{
		bitmas = bitmas | (maska << (7 - temp)); // Установка бита в 1
		cin >> temp;
	}
	cout << "Битовый массив: " << bitset<8>(bitmas) << endl;
	for (int i = 0; i < 8; i++)
	{
		if (bitmas & (maska << (7 - i)))
		{
			cout << i << ' '; // Вывод чисел
		}
	}
	return 0;
}