//
//  tablica.cpp
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#include <iostream>
#include "tablica.h"
using namespace std;




void sheet::open(const int new_rows, const int new_colums, const char new_type)
{
    rows = new_rows;
    colums = new_colums;
    arr = new point*[rows];
    type = new_type;
    for(int i = 0; i < rows; i++)
    {
        switch(new_type)
        {
            case 0:
                arr[i] = new pointInt[colums];
                break;

            case 1:
                arr[i] = new pointDbl[colums];
                break;

            case 2:
                arr[i] = new pointStr[colums];
                break;
        }
    }

}

void sheet::close()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}


void new_arr::zero_arr()
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < colums; j++)
            arr_int[i][j] = 0;
}
void new_arr::open(const int new_rows, const int new_colums)
{
    rows = new_rows;
    colums = new_colums;
    arr_int = new int*[rows];
    for(int i = 0 ; i < rows; i++)
    {
        arr_int[i] = new int[colums];
    }
    zero_arr();
}

//Metod, który usuwa tablicę z pamięci operatywnej
void new_arr::close()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] arr_int[i];
    }
    delete[] arr_int;
}

// Metod, który wypęwnia tablicę losowymi liczbami
void new_arr::fill()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < colums; j++)
            arr_int[i][j] = rand() % 10;
}


//Metod, który wyświetla tablicę na ekran
void new_arr::show()
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            cout << arr_int[i][j] << "\t";
        }
        cout << endl;
    }
}


// функція зменшення таблиці по осі х
//Metod zmniejszenia ilośći kolum
void new_arr::lessx(const int new_colums)
{
    //  Ініціалізуємо додаткову таблицю

    new_arr new_arr;
    new_arr.open(rows, new_colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < new_colums; j++)
            new_arr.arr_int[i][j] = arr_int[i][j];
    
    
        //Очищуємо першу таблицю

    close();

    for (int i = 0; i < rows; i++)
        arr_int[i] = new_arr.arr_int[i];
    arr_int = new_arr.arr_int;
    
    colums = new_colums;
}


//Функція зменшення таблиці по осі y
//Metod zmniejszenia ilości wierszy
void new_arr::lessy(const int new_rows)
{
    //  Ініціалізуємо додаткову таблицю

    new_arr new_arr;
    new_arr.open(new_rows, colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < new_rows; i++)
        for (int j = 0; j < colums; j++)
            new_arr.arr_int[i][j] = arr_int[i][j];
    
    //Очищуємо першу таблицю

    close();

    for (int i = 0; i < new_rows; i++)
        arr_int[i] = new_arr.arr_int[i];
    arr_int = new_arr.arr_int;
    
    rows = new_rows;
}

//------

// Функція збільшення таблиці по осі x
//Metod, który zwiększa ilość kolum
void new_arr::morex(const int new_colums)
{
    
    //  Ініціалізуємо додаткову таблицю

    new_arr new_arr;
    new_arr.open(rows, new_colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < colums; j++)
            new_arr.arr_int[i][j] = arr_int[i][j];
    //Обнуляємо новостворенні комірки

    
    //Очищуємо першу таблицю
    close();
    
    for (int i = 0; i < rows; i++)
        arr_int[i] = new_arr.arr_int[i];
    arr_int = new_arr.arr_int;
    
    
    colums = new_colums;
    
    
}
//-----

//Функція збільшення по осі y
//Metod, który zwiększa ilość wierszy
void new_arr::morey(const int new_rows)
{

    new_arr new_arr;
    new_arr.open(new_rows, colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < colums; j++)
            new_arr.arr_int[i][j] = arr_int[i][j];

    //Очищуємо першу таблицю
    close();
    
    for (int i = 0; i < rows; i++)
        arr_int[i] = new_arr.arr_int[i];
    arr_int = new_arr.arr_int;
    
    rows = new_rows;
}

//Функція для зміни розміру таблиці
//Metod, który zmiana rozmiar tablicy
void new_arr::edit_size(const int new_rows, const int new_colums)
{
    if (new_rows <= rows)
        lessy(new_rows);
    else
        morey(new_rows);
    if (new_colums <= colums)
        lessx(new_colums);
    else
        morex(new_colums);
}



//Фунція для запису певного значення в певну комірку
//Metod, który zapisuje znaczenie do komórki
void new_arr::write(const int x, const int y,const int value)
{
    arr_int[y-1][x-1] = value;
}

//Funkcja, która wyświetla znaczenie komórki
int new_arr::showPoint(const int x, const int y)
{
    return arr_int[y][x];
}

int new_arr::getColums()
{
    return colums;
}
int new_arr::getRows()
{
    return rows;
}


