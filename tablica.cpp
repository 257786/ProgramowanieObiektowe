//
//  tablica.cpp
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#include <iostream>
#include <sstream>
#include "tablica.h"
#include "colors.h"
using namespace std;


int point::get_type()
{
    return type;
}
void pointInt::write(string inf)
{
    stringstream str;
    str << inf;
    str >> value;
}

void pointDbl::write(string inf)
{
    stringstream str;
    str << inf;
    str >> value;
}

void pointStr::write(string inf)
{
    value = inf;
}
string pointInt::read()
{
    stringstream str;
    string s;
    str << value;
    str >> s;
    return s;
}

string pointDbl::read()
{
    stringstream str;
    string s;
    str << value;
    str >> s;
    return s;
}

string pointStr::read()
{
    return value;
}

void sheet::zero()
{

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < colums; j++)
           arr[i][j]->write("0");

}

void sheet::open(const int rows, const int colums, const char type)
{
    this->rows = rows;
    this->colums = colums;
    arr = new point**[rows];
    for(int i = 0; i < rows; i++)
    {
        arr[i] = new point*[colums];
        for(int j = 0; j < colums; j++)
        {
            switch (type)
            {
                case 0:
                    arr[i][j] = new pointInt;
                    break;
                case 1:
                    arr[i][j] = new pointStr;
                    break;
                case 2:
                    arr[i][j] = new pointDbl;
            }
        }
    }
    zero();
}

void sheet::close()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}


void sheet::show()
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            switch(arr[i][j]->get_type())
            {
                case 0:
                    cout << green << arr[i][j]->read() << reset << "\t";
                    break;
                case 1:
                    cout << magenta << arr[i][j]->read() << reset << "\t";
                    break;
                case 2:
                    cout << cyan << arr[i][j]->read() << reset << "\t";
            }

        }
        cout << endl;
    }
}



void sheet::changePointType(const int type, const int x, const int y)
{
    delete[] arr[y][x];
    switch (type)
    {
        case 0:
            arr[y][x] = new pointInt;
            break;
        case 1:
            arr[y][x] = new pointStr;
            break;
        case 2:
            arr[y][x] = new pointDbl;
            break;
    }
}

void sheet::changeColumType(const int type, const int x)
{
    for(int y = 0; y < getRows(); y++)
    {
        changePointType(type, x, y);
    }
}

void sheet::changeRowType(const int type, const int y)
{
    for(int x = 0; x < getColums(); x++)
    {
        changePointType(type, x, y);
    }
}

void sheet::change_type(const int type)
{
    for(int i = 0; i < getRows(); i++)
    {
        for(int j = 0; j < getColums(); j++)
        {
            changePointType(type, j, i);
        }
    }
}


void sheet::move(sheet &new_sheet, const int new_rows, const int new_colums)
{

    for(int i = 0; i < new_rows; i++)
        for(int j = 0; i < new_colums; j++)
            new_sheet.writePoint(j+1, i+1, showPoint(j, i));


   /* for(int i = 0; i < new_rows; i++)
        for(int j = 0; j < new_colums; j++)
            new_sheet.arr[i][j] = arr[i][j];*/
    close();
    for (int i = 0; i < rows; i++)
        arr[i] = new_sheet.arr[i];

    arr = new_sheet.arr;
    rows = new_rows;
    colums = new_colums;
}


void sheet::lessx(const int new_colums)
{
    //  Ініціалізуємо додаткову таблицю

    sheet new_sheet;
    new_sheet.open(rows, new_colums, 1);
    //Переносимо дані зі старої таблиці на нову
    move(new_sheet, rows, new_colums);

}

void sheet::lessy(const int new_rows)
{
    //  Ініціалізуємо додаткову таблицю

    sheet new_sheet;
    new_sheet.open(new_rows, colums, 1);
    move(new_sheet, new_rows, colums);

}


void sheet::morex(const int new_colums)
{

    //  Ініціалізуємо додаткову таблицю

    sheet new_sheet;
    new_sheet.open(rows, new_colums, 1);
    move(new_sheet, rows, colums);


}

void sheet::morey(const int new_rows)
{

    sheet new_sheet;
    new_sheet.open(new_rows, colums, 1);
    //Переносимо дані зі старої таблиці на нову
    move(new_sheet, rows, colums);

}

void sheet::edit_size(const int new_rows, const int new_colums)
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


void sheet::writePoint(const int x, const int y,const string value)
{
    arr[y-1][x-1]->write(value);
}

//Funkcja, która wyświetla znaczenie komórki
string sheet::showPoint(const int x, const int y)
{
    return arr[y][x]->read();
}

int sheet::getColums()
{
    return colums;
}
int sheet::getRows()
{
    return rows;
}
///////////////////////////////////////////////////////////////////////////



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


