//
//  menu.cpp
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#include <iostream>
#include <fstream>
#include "tablica.h"
#include "plik.h"
using namespace std;


//Główna strona
void homePage()
{
    cout << "1. Wyświetlić tablicę" << endl
         << "2. Zmienić rozmiar tablicy" << endl
         << "3. Wypełnić komurkę" << endl
         << "4. Zapisać tablicę w pliku" << endl
         << "5. Odczytać tablicę z pliku" << endl
    << "0. Zakoncz program" << endl;
}

//Strona do zmiany rozmiaru tablicy



void sizePage(new_arr &arr)
{
    int newcolums, newrows;
    cout << "Proszę podać żądaną szerokość tablicy:" << endl;
   cin >> newcolums;
    cout << "Proszę podać żądaną wysokość tablicy:" <<
        endl;
    cin >> newrows;
    edit_sizearr(arr, newrows, newcolums);
}

//Strona do zapisu dannych do komórki

void writePage(new_arr &arr)
{
    int x,y,val;

    do
    {
        cout << "Proszę podać poziomą współrzędną komórki" << endl;
        cin >> x;
        if (x > arr.colums)
            cout << "Niema takiej poziomej współrzędnej!!" << endl;
    }
    while(x > arr.colums);

    do
    {
        cout << "Proszę podać pionową współrzędną komórki"
             << endl;
        cin >> y;
        if(y > arr.rows)
            cout << "Niema takiej pionowej współrzędnej!!" << endl;
    }
    while(y > arr.rows);
    cout << "Proszę wypęłnić komórkę" << endl;
    cin >> val;
    write_arr(arr, x, y, val);
}

//Strona do zapisu tablicy w pliku

void writeFilePage(new_arr &arr, outPlik &plik)
{
    string path;
    cout << "Proszę podać nazwę pliku, lub adres: " << endl;
    cin >> path;
    plik.path = path;
    open_out(plik);
    writeFile(arr, plik);
    cout << "Tablica została zaspisana do pliku." << endl;
    plik.plik.close();

}

//Strona wyświetlająca status otwarcia pliku

void statusFilePage(inPlik &plik)
{
    if(!plik.plik.is_open())
        cout << "Błąd wczytywania pliku. :(" << endl;
    else
        cout << "Plik został otwarty. :)" << endl;
}

//Strona otwierająca plik

void openFilePage(inPlik &plik, new_arr &arr)
{
    string path;
    do
    {

        cout << "Proszę podać nazwę pliku lub jego adres (Jeśli nie chcesz otwierać plik wpisz 0) : ";
        cin >> path;
        plik.path = path;
        open_in(plik);
        statusFilePage(plik);

    }
    while (!plik.plik.is_open() && !(path == "0"));
    plik.plik.close();

    importArr(arr, plik);
}


