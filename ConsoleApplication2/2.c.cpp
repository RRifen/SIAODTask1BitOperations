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
	unsigned char maska = 1;
	unsigned char mas[8]{0};
	cin >> temp;
	while (temp != -1)
	{
		// Установка битов в 1
		mas[temp / 8] = mas[temp / 8] | (maska << (7 - (temp % 8) ) ); 
		cin >> temp;
	}
	cout << "Битовый массив: ";
	for (int i = 0; i < 8; i++)
	{
		cout << bitset<8>(mas[i]); // Вывод битового массива
	}
	cout << endl;
	for (int i = 0; i < 64; i++)
	{
		if (mas[i / 8] & (maska << (7 - (i % 8))))
		{
			cout << i << ' '; // Вывод чисел
		}
	}
	return 0;
}