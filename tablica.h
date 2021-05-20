//
//  tablica.h
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#ifndef tablica_h
#define tablica_h


class new_arr
{
public:
    int rows;
    int colums;
    int **arr;

};
/**
 * Metoda zerująca tablicę
 * @param arr [in, out] - tablica dwuwymiarowa
 */
void zero_arr(new_arr &arr);

/**
 * Inicjalizacji tablicy w pamięci
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param rows [in] - ilość wierszy
 * @param colums [in] - ilość kolumny
 */
void open_arr(new_arr &arr, const int rows, const int colums);

/**
 * Metoda usunięcia tablicy z pamięci
 * @param arr [in, out] - tablica dwuwymiarowa
 */
void close_arr(new_arr &arr);
// Функція яка заповнює таблицю випадковими числами
void fillarr(new_arr& arr);


/**
 * Metoda wyświetlający tablicę na ekranie
 * @param arr [in] - Tablica dwuwymiarowa
 */
void showarr(new_arr &arr);


/**
 * Metoda zmniejszania ilości kolum
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param new_colums[in] - żądana ilość kolumny
 */
void lessx(new_arr &arr, const int new_colums);

/**
 * Metoda zmniejszania ilości wierszy
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param new_rows [in] - żądana ilość wierszy
 */
void lessy(new_arr &arr, const int new_rows);

/**
 * Metoda zwiększania ilości kolumny
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param new_colums [in] - żądana ilość kolumny
 */
void morex(new_arr &arr, const int new_colums);

/**
 * Metoda zwiększania ilości wierszy
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param new_rows [in] - żądana ilość wierszy
 */
void morey(new_arr &arr, const int new_rows);

/**
 * Metoda zmiany rozmiaru tablicy
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param new_rows [in] - żądana ilość wierszy
 * @param new_colums [in] - żądana ilość kolumny
 */
void edit_sizearr( new_arr &arr, const int new_rows, const int new_colums);

/**
 * Metoda zapisu dannych do komórki
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param x [in] - odcięta komórki
 * @param y [in] - rzędowa komórki
 * @param value [in] - znaczenie komórki
 */
void write_arr(new_arr &arr, int x, int y, int value);

/**
 * Funkcja wyświetlająca znaczenie komórki
 * @param arr [in, out] - tablica dwuwymiarowa
 * @param x [in] - odcięta komórki
 * @param y [in] - rzędowa komórki
 * @return - znaczenie komórki
 */
int showPointArr(new_arr &arr, const int x, const int y);
#endif /* tablica_h */

