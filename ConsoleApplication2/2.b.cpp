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
	unsigned long long bitmas = 0;
	unsigned long long maska = 1; // 0..(��� 62 ����)..1
	cin >> temp;
	while (temp != -1)
	{
		bitmas = bitmas | (maska << (63 - temp)); // ��������� ���� � 1
		cin >> temp;
	}
	cout << "������� ������: " << bitset<64>(bitmas) << endl;
	for (int i = 0; i < 64; i++)
	{
		if (bitmas & (maska << (63 - i)))
		{
			cout << i << ' '; // ����� �����
		}
	}
	return 0;
}