#include <iostream>

using namespace std;

int main()
{
    unsigned char x = 255; //8-��������� �������� ����� 11111111
    unsigned char maska = 1; //1 = 00000001 - 8-��������� �����
    x = x & (~(maska << 4)); //��������� x=239
    cout << (int)x;
    return 0;
}