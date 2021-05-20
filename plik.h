//
//  plik.h
//  ##5
//
//  Created by yaroslav on 01/05/2021.
//

#ifndef plik_h
#define plik_h

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
/**
 * Metoda otwierający plik wyjściowy
 * @param plik[in, out] - plik wyjściowy
 */
void open_out(outPlik &plik);
/**
 * Metoda otwierająca plik wejściowy
 * @param plik[in, out] - plik wejściowy
 */
void open_in(inPlik &plik);



/**
 * Metoda zapisujący tablicę do pliku
 * @param arr[in, out] - tablica dwuwymiarowa
 * @param plik [out] - plik wyjściowy
 */
void writeFile(new_arr &arr, outPlik &plik);


/**
 * Funkcja zwracająca ilość wierszy w pliku
 * @param plik [in] - plik wejsciowy
 * @param path
 * @return - ilość wierszy w pliku
 */
int fileRowsBeta(inPlik &plik);


/**
 * Funkcja zwracająca ilość kolum w pliku
 * @param plik[in] - plik wejściowy
 * @return - ilość wierszy w pliku
 */
int fileColumsBeta(inPlik &plik);


/**
 * Funkcla zwracająca ilość wierszy w pliku
 * @param plik[in] - plik wejściowy
 * @return - ilość kolum w pliku
 */
int fileRows(inPlik &plik);


/**
 * Funkcja zwracająca ilość kolum w pliku
 * @param plik[in] - plik wejściowy
 * @return - ilość wierzy w pliku
 */
int fileColums(inPlik &plik);


/**
 * Funkcja zwracająca danne konkretnej komurki w tablice z pliku
 * @param plik[in] - plik wyjściowy
 * @param x[in] - odcięta komówki
 * @param y[in] - rzędna komórki
 * @return - znaczenie komórki
 */
int showPointFile(inPlik &plik, const int x, const int y);


/**
 * Metod, który dopasowuję rozmiar tablicy dynamicznej do rozmiaru tablicy w pliku
 * @param arr[in, out] - tablica dwuwymiarowa
 * @param plik [in] - plik wejściowy
 */
void sizeArrFile(new_arr &arr, inPlik &plik);


/**
 * Metod, który importuję tablicę z pliku
 * @param arr[in, out] - tablica dwuwymiarowa
 * @param plik[in] - plik wejściowy
 */
void importArr(new_arr &arr, inPlik &plik);
#endif /* plik_h */

