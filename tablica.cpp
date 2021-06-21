//
//  tablica.cpp
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#include <iostream>
#include <sstream>
#include "tablica.h"

using namespace std;



void pointInt::write(string inf)
{
    stringstream str;
    str << inf;
    str >> value;
}

int pointInt::get_type()
{
    return type;
}

void pointDbl::write(string inf)
{
    stringstream str;
    str << inf;
    str >> value;
}

int pointDbl::get_type()
{
    return type;
}

void pointStr::write(string inf)
{
    value = inf;
}

int pointStr::get_type()
{
    return type;
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
    name = "Nowy arkusz";
    this->rows = rows;
    this->colums = colums;
    arr = new point**[this->rows];
    for(int i = 0; i < rows; i++)
    {
        arr[i] = new point*[this->colums];
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
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            delete arr[i][j];
        }
    }

    for(int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}




point* sheet::getPoint(const int i, const int j)
{
    return arr[i][j];
}


void sheet::changePointType(const int type, const int i, const int j)
{
    delete arr[i][j];
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
            break;
    }
}

void sheet::changeColumType(const int type, const int j)
{
    for(int i = 0; i < getRows(); i++)
    {
        changePointType(type, i, j);
    }
}

void sheet::changeRowType(const int type, const int i)
{
    for(int j = 0; j < getColums(); j++)
    {
        changePointType(type, i, j);
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


void sheet::morex(const int new_colums)
{
    sheet new_arr(rows, new_colums, 1);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            copy(new_arr, arr[i][j], i, j);
        }
    }
    close();
    arr = new_arr.getArr();
    colums = new_colums;
}

void sheet::morey(const int new_rows)
{
    sheet new_arr(new_rows, colums, 1);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            copy(new_arr, arr[i][j], i, j);
        }
    }
    close();

    arr = new_arr.getArr();
    rows = new_rows;

}

void sheet::lessx(const int new_colums)
{
    sheet new_arr(rows, new_colums, 1);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < new_colums; j++)
        {
            copy(new_arr, arr[i][j], i, j);
        }
    }
    close();
    arr = new_arr.getArr();
    colums = new_colums;
}
void sheet::lessy(const int new_rows)
{
    sheet new_arr(new_rows, colums, 1);
    for(int i = 0; i < new_rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            copy(new_arr, arr[i][j], i, j);
        }
    }
    close();
    arr = new_arr.getArr();
    rows = new_rows;
}
void sheet::edit_size(const int new_rows, const int new_colums) {
    if (new_rows <= rows)
        lessy(new_rows);
    else
    {
        morey(new_rows);

    }

    if (new_colums <= colums)
        lessx(new_colums);
    else
        morex(new_colums);


}

void sheet::writePoint(const int i, const int j,const string value)
{
    arr[i][j]->write(value);
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

int sheet::getPointType(const int i, const int j)
{
    return arr[i][j]->get_type();
}
point*** sheet::getArr()
{
    return arr;
}
void sheet::copy(sheet &new_arr, point* p, const int i, const int j)
{
    new_arr.changePointType(p->get_type(), i, j);
    new_arr.writePoint(i, j, p->read());

}


void sheet::fill()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            changePointType(rand() % 3, i, j );
            stringstream s;
            s << rand() % 100;
            string s2;
            s >> s2;
            writePoint(i, j, s2);
        }

    }

}

string sheet::getRowSum(const int i)
{
    double sum = 0;
    for(int j = 0; j < colums; j++)
    {
        stringstream p;
        double val;
        p << arr[i][j]->read();
        p >> val;
        sum += val;
    }
    stringstream p;
    string ssum;
    p << sum;
    p >> ssum;
    return ssum;
}

string sheet::getColumSum(const int j)
{
    double sum = 0;
    for(int i = 0; i < rows; i++)
    {
        stringstream p;
        double val;
        p << arr[i][j]->read();
        p >> val;
        sum += val;
    }
    stringstream p;
    string ssum;
    p << sum;
    p >> ssum;
    return ssum;
}

string sheet::getName()
{
    return name;
}

void sheet::setName(const string name)
{
    this->name = name;
}

void pushback(sheet* arr)
{
    sheet* new_arr = new sheet[sizeof(arr)+1];

}

arkuszy::arkuszy()
{
    size = 1;
    arr = new sheet[1];
}

void arkuszy::add()
{

    sheet* new_sheet = new sheet[size+1];
    for(int i = 0; i < size; i++)
        new_sheet[i] = arr[i];
    delete[] arr;
    arr = new_sheet;
    size++;

}

void arkuszy::del(const int nr)
{
    if (nr<=size)
    {
        size--;
        sheet* new_sheet = new sheet[size];
        for(int i = 0; i < size;i++)
        {
            if(i < nr)
            {
                new_sheet[i] = arr[i];
            }
            else
            {
                new_sheet[i] = arr[i+1];
            }
        }
        delete[] arr;
        arr = new_sheet;
    }
}

int arkuszy::getSize()
{
    return size;
}



void arkuszy::close()
{
    delete[] arr;
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

//Metod, który wypęwnia tablicę losowymi liczbami
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
    {
        morey(new_rows);

    }
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