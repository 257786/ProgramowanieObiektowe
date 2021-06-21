//
//  plik.cpp
//  ##5
//
//  Created by yaroslav on 01/05/2021.
//

#include <iostream>
#include "plik.h"

#include "tablica.h"
using namespace std;



outPlik::outPlik(string path)
{
    this->path = path;
    open();
}

void outPlik::open()
{
    plik.open(path);
}

void outPlik::close()
{
    plik.close();
}
inPlik::inPlik(string path)
{
    this->path = path;
    open();
}
void inPlik::open()
{

    plik.open(this->path);
}

void inPlik::open(string path)
{
    this->path = path;
    open();
}

//Metod zapisujący tablicę do pliku

void outPlik::save( sheet arr)
{
    for (int i = 0; i < arr.getRows(); i++)
    {
        for(int j = 0; j < arr.getColums(); j++)
        {
            plik << arr.showPoint(j, i) << "\t";
        }
        plik << endl;
    }

}


void inPlik::close()
{
    plik.close();
}

//Funkcja zwracająca ilość wierszy w pliku

int inPlik::getRows1()
{

    char ch;
    int rows = 0;
    open();
    plik.seekg(plik.beg);
    while(plik.get(ch))
        if((ch == 0x0a) || (ch == 0x03) || (ch == 0x00) || (ch == 0x04))
            rows++;
    plik.clear();
    plik.seekg(0);
    close();
    return rows;
}


//Funkcja zwracająca ilość kolum w pliku
int inPlik::getColums1()
{
    char ch;
    int colums = 0;
    open();
    plik.seekg(plik.beg);
    while(plik.get(ch) && ch != 0x0A)
        if(ch == 0x09)
            colums++;

    plik.clear();
    plik.seekg(plik.beg);
    close();
    return colums;
}


//Funkcla zwracająca ilość kolum w pliku
int inPlik::getColums()
{
    getColums1();
    return getColums1()+1;
}

//Funkcja zwracająca ilość wierszy w pliku
int inPlik::getRows()
{

    getColums1();
    return getRows1();
}

//Funkcja zwracająca danne konkretnej komurki w tablice z pliku
string inPlik::showPoint(const int x, const int y)
{
    open();
    plik.seekg(plik.beg);
    plik.clear();
    char ch;
    int p = (y - 1) * getColums() + x - 1;
    string val;

    close();

    open();
    for (int i = 0; (i < p) && plik.get(ch); i+0)
    {
        if (ch == 0x09 || ch == 0x0A)
            i++;
    }

    do
    {
        plik.get(ch);
        if(ch != 0x09 && ch != 0x0A)
            val += ch;
    }
    while (ch != 0x09 && ch != 0x0A);

    close();
    return val;

}

//Metod, który dopasowuję rozmiar tablicy dynamicznej do rozmiaru tablicy w pliku
void inPlik::goSize(sheet &arr)
{
    arr.edit_size(getRows(), getColums());
}

//Metod, który importuję tablicę z pliku
void inPlik::import(sheet &arr)
{
    goSize(arr);
    for(int i = 0; i < arr.getRows(); i++)
    {
        for(int j = 0; j < arr.getColums(); j++)
        {
            arr.writePoint(i, j , showPoint(j+1, i+1));
        }
    }
}

bool inPlik::is()
{
    return plik.is_open();
}