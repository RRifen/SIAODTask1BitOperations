#include <iostream>

using namespace std;

int main()
{
    unsigned char x = 0; //8-��������� �������� ����� 00000000
    unsigned char maska = 1; //1 = 00000001 - 8-��������� �����
    x = x | (maska << 6); //��������� x=64
    cout << (int)x;
    return 0;
}