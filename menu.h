//
//  menu.h
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//


#ifndef menu_h
#define menu_h
#include "plik.h"
#include "tablica.h"
using namespace std;




void show(sheet &arr);
/**
 * Głowna strona
 */
void homePage(arkuszy arr);


/**
 * Strona do zmiany rozmiaru tablicy
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void sizePage(sheet &arr);


/**
 * Strona do zapisu dannych do komórki
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void writePage(sheet &arr);

/**
 * Lista dostępnych typów
 */

void types();

/**
 * Strona do zmiany typu komórki
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void typePointPage(sheet &arr);

/**
 * Strona do zmiany typu wiersza
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void typeRowPage(sheet &arr);

/**
 * Strona do zmiany typo kolumny
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void typeColumPage(sheet &arr);

/**
 * Strona do zmiany typu arkuszu
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void typeSheetPage(sheet &arr);

/**
 * Strona do zmiany typu komórek tablicy
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void typePage(sheet &arr);

/**
 * Strona do zapisu tablicy w pliku
 * @param[in,out] arr - tablica dwuwymiarowa
 * @param[out] - plik wyjśćiowy
 */
void writeFilePage(sheet &arr);


/**
 * Strona wyświetlająca status otwarcia pliku
 * @param[in] - plik wejściowy
 */
void statusFilePage(inPlik &plik);


/**
 * Strona otwierająca plik
 * @param plik[in] - plik wejściowy
 * @param arr [in, out] - tablica dwuwymiarowa
 */
void openFilePage(sheet &arr);

/**
 * Strona menu wyznaczjąca sumę kolum
 * @param arr —— tablica dwuwymiarowa
 */
void getColumPage(sheet &arr);

/**
 * Strona menu wyznaczająca sumę wierszy
 * @param arr —— tablica dwuwymiarowa
 */
void getRowPage(sheet &arr);

/**
 * Strona wyznaczająca sumę elementów wierszu lub kolumny
 * @param arr —— tablica dwuwymiarowa;
 */
void getSumPage(sheet &arr);

void showArkuszy(arkuszy arr);

void setArkusz(arkuszy arr);

void delPage(arkuszy arr);

void newPage(arkuszy arr);

void changeName(arkuszy arr);



#endif /* menu_h */
