//
//  plik.cpp
//  ##5
//
//  Created by yaroslav on 01/05/2021.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "tablica.h"
using namespace std;

class outPlik
{
    public:
        ofstream plik;
        string path;
};

class inPlik
{
    public:
        ifstream plik;
        string path;
};

void open_out(outPlik &plik)
{
    plik.plik.open(plik.path);
}

void open_in(inPlik &plik)
{
    plik.plik.open(plik.path);
}


//Metod zapisujący tablicę do pliku

void writeFile(new_arr &arr, outPlik &plik)
{
    for (int i = 0; i < arr.getRows(); i++)
    {
        for(int j = 0; j < arr.getColums(); j++)
        {
            plik.plik << arr.showPoint(j, i) << "\t";
        }
        plik.plik << endl;
    }
    plik.plik << endl;
}


//Funkcja zwracająca ilość wierszy w pliku

int fileRowsBeta(inPlik &plik)
{

    char ch;
    int rows = 0;
    open_in(plik);
    plik.plik.seekg(plik.plik.beg);
    while(plik.plik.get(ch))
        if((ch == 0x0a) || (ch == 0x03) || (ch == 0x00) || (ch == 0x04))
            rows++;
    plik.plik.clear();
    plik.plik.seekg(0);
    plik.plik.close();
    return rows;
}


//Funkcja zwracająca ilość kolum w pliku
int fileColumsBeta(inPlik &plik)
{


    char ch;

    int colums = 1;

    open_in(plik);
    plik.plik.seekg(plik.plik.beg);
    while(plik.plik.get(ch) && ch != 0x0A)
        if(ch == 0x09)
            colums++;

    plik.plik.clear();
    plik.plik.seekg(plik.plik.beg);
    plik.plik.close();
    return colums;
}


//Funkcla zwracająca ilość kolum w pliku
int fileColums(inPlik &plik)
{
    fileColumsBeta(plik);
    return fileColumsBeta(plik);
}

//Funkcja zwracająca ilość wierszy w pliku
int fileRows(inPlik &plik)
{

    fileColumsBeta(plik);
    return fileRowsBeta(plik);
}

//Funkcja zwracająca danne konkretnej komurki w tablice z pliku
int showPointFile(inPlik &plik, const int x, const int y)
{
    open_in(plik);
    plik.plik.seekg(plik.plik.beg);
    plik.plik.clear();
    char ch;
    int p = (y - 1) * fileColums(plik) + x - 1;
    string val;

    plik.plik.close();
    open_in(plik);
    for (int i = 0; (i < p) && plik.plik.get(ch); i+0)
    {
        if (ch == 0x09 || ch == 0x0A)
            i++;
    }

    do
    {
        plik.plik.get(ch);
        val += ch;
    }
    while (ch != 0x09 && ch != 0x0A);

    plik.plik.close();
    return atoi(val.c_str());

}

//Metod, który dopasowuję rozmiar tablicy dynamicznej do rozmiaru tablicy w pliku
void sizeArrFile(new_arr &arr, inPlik &plik)
{
    arr.edit_size(fileRows(plik), fileColums(plik));
}

//Metod, który importuję tablicę z pliku
void importArr(new_arr &arr, inPlik &plik)
{
    sizeArrFile(arr, plik);
    for(int i = 1; i <= arr.getRows(); i++)
    {
        for(int j = 1; j <= arr.getColums(); j++)
        {
            //arr.arr_int[i][j] = showPointFile(plik, j+1, i+1);

            arr.write(j, i , showPointFile(plik, j+1, i+1));
        }

    }


}