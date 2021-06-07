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

int choice = 10;

//Główna strona
void homePage();


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
void writeFilePage(sheet &arr, outPlik &plik);


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
void openFilePage(inPlik &plik, sheet &arr);




#endif /* menu_h */
