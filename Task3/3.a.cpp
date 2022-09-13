#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

#define SIZE 1048576

using namespace std;

// Генерация файла с SIZE * 8 уникальных чисел в случайном порядке
bool generate_file_random(long long number_count);

int main()
{
    long long number_count;
    int answer;
    cout << "Enter the number of values to sort: ";
    cin >> number_count;
    while (number_count > (SIZE << 3)) //Пока не введено число, меньшее чем максимум
    {
        cout << "The number exceeds the maximum value (" << (SIZE << 3) << endl;
        cout << "Please enter another one" << endl;
        cin >> number_count;
    }
    cout << "Enter 1 to generate random numbers or 2 to enter numbers manually" << endl;
    cout << "-> ";
    cin >> answer;
    if (answer == 1) //Случайная генерация
    {
        generate_file_random(number_count);
    }
    else //Ввод с клавиатуры
    {
        int temporary;
        ofstream out("input.txt");
        cout << "Enter numbers" << endl;
        for (int i = 0; i < number_count; i++)
        {
            cout << "-> ";
            cin >> temporary;
            out << temporary << endl;
        }
    }
    unsigned char* mas = new unsigned char[number_count];
    int maska = 1;
    int temp, full;
    clock_t start, end, real_time;
    for (int i = 0; i < number_count; i++) //Предварительное заполнение битового массива нулями
    {
        mas[i] = 0;
    }
    ifstream inp("input.txt");
    ofstream out("output.txt");
    cout << "Start sorting" << endl;
    start = clock();
    while (inp >> temp)
    {
        temp = temp;
        full = temp / 8;
        mas[full] = mas[full] | (maska << (7 - (temp % 8))); //Установка битов в 1
    }
    for (int i = 0; i < number_count * 8; i++)
    {
        if (mas[i / 8] & (maska << (7 - (i % 8)))) //Считывание битов, установленных в 1
        {
            out << i << "\n";
        }
    }
    end = clock();
    real_time = double(end - start) / CLOCKS_PER_SEC; //Расчет времени работы алгоритма
    cout << "Time (in seconds): " << real_time << endl;
    delete[] mas;
    return 0;
}

bool generate_file_random(long long number_count)
{
    ofstream out("input.txt");
    int numbers_amount = number_count;
    if (number_count > numbers_amount)
    {
        return false;
    }
    int* mas = new int[number_count];
    for (int i = 0; i < numbers_amount; i++)
    {
        mas[i] = i;
    }
    random_shuffle(mas, mas + numbers_amount); // Перемешивание массива
    for (int i = 0; i < numbers_amount; i++)
    {
        out << mas[i] << "\n";
    }
    delete[] mas;
    return true;
}