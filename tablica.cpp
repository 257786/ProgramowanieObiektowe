//
//  tablica.cpp
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#include <iostream>
using namespace std;

//Klasa tablicy
class new_arr
{
    public:
        int rows;
        int colums;
        int **arr;

};

//Metod, który zeruje tablicę
void zero_arr(new_arr &arr)
{
    for(int i = 0; i < arr.rows; i++)
        for(int j = 0; j < arr.colums; j++)
            arr.arr[i][j] = 0;
}

//Metod inicializujący tablicę
void open_arr(new_arr &arr, const int rows, const int colums)
{
    arr.rows = rows;
    arr.colums = colums;
    arr.arr = new int*[rows];
    for(int i = 0 ; i < rows; i++)
    {
        arr.arr[i] = new int[colums];
    }
    zero_arr(arr);
}

//Metod, który usuwa tablicę z pamięci operatywnej
void close_arr(new_arr &arr)
{
    for(int i = 0; i < arr.rows; i++)
    {
        delete[] arr.arr[i];
    }
    delete[] arr.arr;
}

// Metod, który wypęwnia tablicę losowymi liczbami
void fillarr(new_arr &arr)
{
    for (int i = 0; i < arr.rows; i++)
        for (int j = 0; j < arr.colums; j++)
            arr.arr[i][j] = rand() % 10;
}


//Metod, który wyświetla tablicę na ekran
void showarr(new_arr &arr)
{
    cout << endl;
    for (int i = 0; i < arr.rows; i++)
    {
        for(int j = 0; j < arr.colums; j++)
        {
            cout << arr.arr[i][j] << "\t";
        }
        cout << endl;
    }
}


// функція зменшення таблиці по осі х
//Metod zmniejszenia ilośći kolum
void lessx(new_arr &arr, const int new_colums)
{
    //  Ініціалізуємо додаткову таблицю

    new_arr new_arr;
    open_arr(new_arr, arr.rows, new_colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < arr.rows; i++)
        for (int j = 0; j < new_colums; j++)
            new_arr.arr[i][j] = arr.arr[i][j];
    
    
        //Очищуємо першу таблицю

    close_arr(arr);

    for (int i = 0; i < arr.rows; i++)
        arr.arr[i] = new_arr.arr[i];
    arr.arr = new_arr.arr;
    
    arr.colums = new_colums;
}


//Функція зменшення таблиці по осі y
//Metod zmniejszenia ilości wierszy
void lessy(new_arr &arr, const int new_rows)
{
    //  Ініціалізуємо додаткову таблицю

    new_arr new_arr;
    open_arr(new_arr, new_rows, arr.colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < new_rows; i++)
        for (int j = 0; j < arr.colums; j++)
            new_arr.arr[i][j] = arr.arr[i][j];
    
    //showarr(new_arr, rows, new_colums);
    
    
    
    //Очищуємо першу таблицю

    close_arr(arr);

    for (int i = 0; i < new_rows; i++)
        arr.arr[i] = new_arr.arr[i];
    arr.arr = new_arr.arr;
    
    arr.rows = new_rows;
}

//------

// Функція збільшення таблиці по осі x
//Metod, który zwiększa ilość kolum
void morex(new_arr &arr, const int new_colums)
{
    
    //  Ініціалізуємо додаткову таблицю

    new_arr new_arr;
    open_arr(new_arr, arr.rows, new_colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < arr.rows; i++)
        for (int j = 0; j < arr.colums; j++)
            new_arr.arr[i][j] = arr.arr[i][j];
    //Обнуляємо новостворенні комірки
    zero_arr(new_arr);
    
    //Очищуємо першу таблицю
    close_arr(arr);
    
    for (int i = 0; i < arr.rows; i++)
        arr.arr[i] = new_arr.arr[i];
    arr.arr = new_arr.arr;
    
    
    arr.colums = new_colums;
    
    
}
//-----

//Функція збільшення по осі y
//Metod, który zwiększa ilość wierszy
void morey(new_arr &arr, const int new_rows)
{

    new_arr new_arr;
    open_arr(new_arr, new_rows, arr.colums);
    //Переносимо дані зі старої таблиці на нову
    for (int i = 0; i < arr.rows; i++)
        for (int j = 0; j < arr.colums; j++)
            new_arr.arr[i][j] = arr.arr[i][j];
    
    //Обнуляємо новоутворенні комірки
    zero_arr(new_arr);
    
    //Очищуємо першу таблицю
    close_arr(arr);
    
    for (int i = 0; i < arr.rows; i++)
        arr.arr[i] = new_arr.arr[i];
    arr.arr = new_arr.arr;
    
    arr.rows = new_rows;
}

//Функція для зміни розміру таблиці
//Metod, który zmiana rozmiar tablicy
void edit_sizearr( new_arr &arr, const int new_rows, const int new_colums)
{
    if (new_rows <= arr.rows)
        lessy(arr,new_rows);
    else
        morey(arr, new_rows);
    if (new_colums <= arr.colums)
        lessx(arr, new_colums);
    else
        morex(arr, new_colums);
}



//Фунція для запису певного значення в певну комірку
//Metod, który zapisuje znaczenie do komórki
void write_arr(new_arr &arr, int x, int y, int value)
{
    arr.arr[y-1][x-1] = value;
}

//Funkcja, która wyświetla znaczenie komórki
int showPointArr(new_arr &arr, const int x, const int y)
{
    return arr.arr[y][x];
}

