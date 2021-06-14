//
//  plik.h
//  ##5
//
//  Created by yaroslav on 01/05/2021.
//

#ifndef plik_h
#define plik_h
#include <fstream>
#include "tablica.h"
using namespace std;

class outPlik
{
private:
    ofstream plik;
    string path;

public:
    /**
     * konstruktor inicjalizujący plik wyjściowy
     * @param path[in] —— adres lub nazwa pliku
     */
    outPlik(string path);

    /**
     * Metoda zapisująca arkusz do pliku
     * @param arr [in] —— tablica dwuwymiarowa
     */
    void save(sheet arr);

    /**
     * metoda inicjalizująca plik wyjściowy
     */
    void open();

    /**
     * Metoda zamykająca plik wyjściowy
     */
    void close();


};

class inPlik
{
private:
    /**
     * Funkcją, która zwraca ilość wierszy w pliku wejśćiowym, która działa nie dokładnie
     * @return —— ilość wierszy
     */
    int getRows1();

    /**
     * Funkcją, która zwraca ilość kolumny w pliku wejśćiowym, która działa nie dokładnie
     * @return —— ilość kolumny
     */
    int getColums1();
    ifstream plik;
    string path;

public:
    /**
     * konstruktor inicjalizujący plik wejściowy
     */
    inPlik();
    /**
     * konstruktor inicjalizujący plik wejściowy
     * @param path [in] —— adres lub nazwa pliku
     */
    inPlik(string path);

    /**
     * metoda inicjalizująca plik wejściowy
     */
    void open();
    /**
     * metoda inicjalizująca plik wejściowy
     * @param path [in] —— adres lub nazwa pliku
     */
    void open(string path);

    /**
     * Funkcja zwracająca ilość koumny w pliku
     * @return —— ilość kolumny w pliku
     */
    int getColums();

    /**
     * Funkcja zwracająca ilość wierszy w pliku
     * @return —— ilość wierszy w pliku
     */
    int getRows();

    /**
     * Metota zamykająca plik wejśćiowy
     */
    void close();


    /**
     * Funkcja zwracająca dane komórki w pliku
     * @param x [in] —— nr kolumny
     * @param y [in] —— nr wierszu
     * @return treść komórki
     */
    string showPoint(const int x, const int y);

    /**
     * Metoda dopasująca rozmiar arkuszu do rozmiaru arkuszu w pliku
     * @param arr [out] —— arkusz
     */
    void goSize(sheet &arr);

    /**
     * Metoda importująca arkusz z pliku
     * @param arr [out] —— arkusz
     */
    void import(sheet &arr);

    /**
     * Funkcja sprawdzająca stan obencości pliku wejściowego.
     * @return —— stan obecnośći pliku wejściowego
     */
    bool is();


};



#endif /* plik_h */

