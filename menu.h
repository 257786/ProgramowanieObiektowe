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
void sizePage(new_arr &arr);


/**
 * Strona do zapisu dannych do komórki
 * @param[in,out] arr - tablica dwuwymiarowa
 */
void writePage(new_arr &arr);


/**
 * Strona do zapisu tablicy w pliku
 * @param[in,out] arr - tablica dwuwymiarowa
 * @param[out] - plik wyjśćiowy
 */
void writeFilePage(new_arr &arr, outPlik &plik);


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
void openFilePage(inPlik &plik, new_arr &arr);


#endif /* menu_h */
