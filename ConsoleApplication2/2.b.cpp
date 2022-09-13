#include <iostream>
#include <bitset>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Вводите числа от 0 до 63 (или -1, чтобы закончить ввод): ";
	int temp;
	unsigned long long bitmas = 0;
	unsigned long long maska = 1; // 0..(еще 62 нуля)..1
	cin >> temp;
	while (temp != -1)
	{
		bitmas = bitmas | (maska << (63 - temp)); // Установка бита в 1
		cin >> temp;
	}
	cout << "Битовый массив: " << bitset<64>(bitmas) << endl;
	for (int i = 0; i < 64; i++)
	{
		if (bitmas & (maska << (63 - i)))
		{
			cout << i << ' '; // Вывод чисел
		}
	}
	return 0;
}