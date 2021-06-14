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
         << "4. Zmiana typu" << endl
         << "5. Zapisać tablicę w pliku" << endl
         << "6. Odczytać tablicę z pliku" << endl
         << "7. Uzyskanie sumy elementów wierszy lub kolumny" << endl
    << "0. Zakoncz program" << endl;
}

//Strona do zmiany rozmiaru tablicy



void sizePage(sheet &arr)
{
    int newcolums, newrows;
    cout << "Proszę podać żądaną szerokość tablicy:" << endl;
   cin >> newcolums;
    cout << "Proszę podać żądaną wysokość tablicy:" <<
        endl;
    cin >> newrows;
    arr.edit_size(newrows, newcolums);
}

//Strona do zapisu dannych do komórki

void writePage(sheet &arr)
{
    int x,y;
    string val;

    do
    {
        cout << "Proszę podać poziomą współrzędną komórki" << endl;
        cin >> x;
        if (x > arr.getColums())
            cout << "Niema takiej poziomej współrzędnej!!" << endl;
    }
    while(x > arr.getColums());

    do
    {
        cout << "Proszę podać pionową współrzędną komórki"
             << endl;
        cin >> y;
        if(y > arr.getRows())
            cout << "Niema takiej pionowej współrzędnej!!" << endl;
    }
    while(y > arr.getRows());
    cout << "Proszę wypęłnić komórkę" << endl;
    cin >> val;
    arr.writePoint(x, y, val);
}

void types()
{
    cout << "Proszę wybrać żądany typ:\n0. —— int \n1. —— string\n2. —— double\n";
}

void typePointPage(sheet &arr)
{
    int x,y;
    int val;

    do
    {
        cout << "Proszę podać poziomą współrzędną komórki" << endl;
        cin >> x;
        if (x > arr.getColums())
            cout << "Niema takiej poziomej współrzędnej!!" << endl;
    }
    while(x > arr.getColums());

    do
    {
        cout << "Proszę podać pionową współrzędną komórki"
             << endl;
        cin >> y;
        if(y > arr.getRows())
            cout << "Niema takiej pionowej współrzędnej!!" << endl;
    }
    while(y > arr.getRows());
    types();
    cin >> val;
    arr.changePointType(val, x-1, y-1);

}

void typeRowPage(sheet &arr)
{
    int y;
    int type;
    cout << "Proszę podać nr wierszu:\n";
    cin >> y;
    types();
    cin >> type;
    arr.changeRowType(type, y-1);
}

void typeColumPage(sheet &arr)
{
    int x;
    int type;
    cout << "Proszę podać nr kolumny:\n";
    cin >> x;
    types();
    cin >> type;
    arr.changeColumType(type, x);
}

void typeSheetPage(sheet &arr)
{
    int type;
    types();
    cin >> type;
    arr.change_type(type);
}

void typePage(sheet &arr)
{
    cout << "Zmiana typy:" << endl
    <<"0. Anuluj\n1. Komórki\n 2. Wierszu\n 3.Kolumny\n 4. Całego arkuszu\n";
    int choice;
    cin >> choice;
    do
    {
        switch (choice)
        {
            case 1:
                typePointPage(arr);
                break;
            case 2:
                typeRowPage(arr);
                break;
            case 3:
                typeColumPage(arr);
                break;
            case 4:
                typeSheetPage(arr);
                break;
            case 0:
                break;
            default:
                cout << "Nie ma takiego polecenia!\n";
                break;
        }

    }
    while(choice>4);
}

//////////////////////////////////
//Strona do zapisu tablicy w pliku

void writeFilePage(sheet &arr)
{
    string path;
    cout << "Proszę podać nazwę pliku, lub adres: " << endl;
    cin >> path;
    outPlik plik(path);
    plik.save(arr);
    cout << "Tablica została zaspisana do pliku." << endl;


}

//Strona wyświetlająca status otwarcia pliku

void statusFilePage(inPlik &plik)
{
    if(!plik.is())
        cout << "Błąd wczytywania pliku. :(" << endl;
    else
        cout << "Plik został otwarty. :)" << endl;
}

//Strona otwierająca plik

/*void openFilePage(sheet &arr)
{
    string path;
    inPlik plik;
    do
    {
        cout << "Proszę podać nazwę pliku lub jego adres (Jeśli nie chcesz otwierać plik wpisz 0) : ";
        cin >> path;
        plik.open(path);

    }
    while (!plik.is() && !(path == "0"));
    plik.close();

    plik.import(arr);
}
*/
void getColumPage(sheet &arr)
{
    int nr;
    cout << "proszę podać nr kolumny: ";
    cin >> nr;
    string sum;
    sum = arr.getColumSum(nr-1);
    cout << sum <<"\nCzy chciałbyś wypełnić komurkę uzyskanym znaczeniem?\n1.—— TAK:)\t2.—— NIE:(\n";
    int wybor;
    cin >> wybor;
    if(wybor == 1)
    {
        int x,y;
        do
        {
            cout << "Proszę podać poziomą współrzędną komórki" << endl;
            cin >> x;
            if (x > arr.getColums())
                cout << "Niema takiej poziomej współrzędnej!!" << endl;
        }
        while(x > arr.getColums());

        do
        {
            cout << "Proszę podać pionową współrzędną komórki"
                 << endl;
            cin >> y;
            if(y > arr.getRows())
                cout << "Niema takiej pionowej współrzędnej!!" << endl;
        }
        while(y > arr.getRows());
        arr.writePoint(x,y, sum);
    }

}

void getRowPage(sheet &arr)
{
    int nr;
    cout << "proszę podać nr wierszu: ";
    cin >> nr;
    string sum;
    sum = arr.getRowSum(nr-1);
    cout << sum <<"\nCzy chciałbyś wypełnić komurkę uzyskanym znaczeniem?\n1.—— TAK:)\t2.—— NIE:(\n";
    int wybor;
    cin >> wybor;
    if(wybor == 1)
    {
        int x, y;
        do {
            cout << "Proszę podać poziomą współrzędną komórki" << endl;
            cin >> x;
            if (x > arr.getColums())
                cout << "Niema takiej poziomej współrzędnej!!" << endl;
        } while (x > arr.getColums());

        do {
            cout << "Proszę podać pionową współrzędną komórki"
                 << endl;
            cin >> y;
            if (y > arr.getRows())
                cout << "Niema takiej pionowej współrzędnej!!" << endl;
        } while (y > arr.getRows());
        arr.writePoint(x, y, sum);
    }
}

void getSumPage(sheet &arr)
{

    int choice;

    do
    {
        cout << "Wyznaczenie sumy elementów:\n\t1. —— Wierszu\n\t2. —— Kolumny\n\t 0. —— Anuluj\n";
        cin >> choice;
        switch(choice)
        {
            case 1:
                getRowPage(arr);
                break;
            case 2:
                getColumPage(arr);
                break;
            case 0:
                break;
            default:
                cout << "Nie ma takiego polecenia!! 0 - główna strona.\n";
        }
    }
    while(choice > 2 || choice < 0);

}


