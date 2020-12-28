// lab11.1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Варіант 9.
//Сформувати файл даних, компонентами якого є дійсні числа.
//Переписати в інший файл даних ті компоненти, які можуть бути аргументами функції
//lg x.
//Вивести на екран вміст результуючого файлу.
  

//В lg x , x>0
//
#include <iostream>
#include<fstream>
#include <Windows.h>
#include <time.h>

using namespace std;

void Create(const char* File_Name);
void Process(const char* File_Name, const char* File_Result);
void Print(const char* File_Result);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Create("filef.dat");
    Print("filef.dat");

    Process("filef.dat", "fileg.dat");
    Print("fileg.dat");

    return 0;
}
void Create(const char* File_Name)
{
    ofstream First_File(File_Name, ios::binary);

    double x;

    for (int i = 0; i < 20; i++)
    {
        x = (2 * (20 * 1.)) * rand() / RAND_MAX - (20 * 1.);
        First_File.write((char*)&x, sizeof(x));
    }
}
void Process(const char* filef, const char* fileg)
{
    ifstream FirstFile(filef, ios::binary);
    ofstream SecondFile(fileg, ios::binary);

    double y;
    while (FirstFile.read((char*)&y, sizeof(y)))
        if (y > 0)
            SecondFile.write((char*)&y, sizeof(y));

}
void Print(const char* fileg)
{
    cout << "Вміст файлу: ";

    ifstream SecondFile(fileg, ios::binary);

    double y;
    while (SecondFile.read((char*)&y, sizeof(y)))
        cout << y << " ";
    cout << endl;
}