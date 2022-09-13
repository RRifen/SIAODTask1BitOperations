#include <iostream>
#include <bitset>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������� ����� �� 0 �� 63 (��� -1, ����� ��������� ����): ";
	int temp;
	unsigned char maska = 1;
	unsigned char mas[8]{0};
	cin >> temp;
	while (temp != -1)
	{
		// ��������� ����� � 1
		mas[temp / 8] = mas[temp / 8] | (maska << (7 - (temp % 8) ) ); 
		cin >> temp;
	}
	cout << "������� ������: ";
	for (int i = 0; i < 8; i++)
	{
		cout << bitset<8>(mas[i]); // ����� �������� �������
	}
	cout << endl;
	for (int i = 0; i < 64; i++)
	{
		if (mas[i / 8] & (maska << (7 - (i % 8))))
		{
			cout << i << ' '; // ����� �����
		}
	}
	return 0;
}