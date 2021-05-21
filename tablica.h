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

        int **arr;  //Tablica dwuwymiarowa
        /**
        * Metoda zerująca teblicę
        */
        void zero_arr();

        /**
        * Metoda zapisująca tablicę w pamięci komputera
        * @param new_rows [in] - żądana ilość wierszy
        * @param new_colums [in] - żądana ilość kolumny
        */
        void open(const int new_rows, const int new_colums);

        /**
        * Metoda usunięcia tablicy z pamięci komputera
        */
        void close();

        /**
        * Metoda wypełniająca tablicę losowymi liczbami w zakresie 10
        */
        void fill();

        /**
        * Metoda wyświetlająca tablicę
        */
        void show();

        /**
        * Metoda zmniejszająca ilość kolumny
        * @param new_colums [in] - żądana ilość kolumny
        */
        void lessx(const int new_colums);

        /**
        * Metoda zmniejszająca ilość wierszy
        * @param new_rows [in] - żądana ilość wierszy
        */
        void lessy(const int new_rows);

        /**
        * Metoda zwiększająca ilość kolumny
        * @param new_colums [in] - żądana ilość kolumny
        */
        void morex(const int new_colums);

        /**
        * Metoda zwiększająca ilość wierszy
        * @param new_rows [in] - żądana ilość wierszy
        */
        void morey(const int new_rows);

        /**
        * Metoda zmieniająca rozmiaru tablicy
        * @param new_rows [in] - żądana ilość wierszy
        * @param new_colums [in] - żądana ilość kolumny
        */
        void edit_size(const int new_rows, const int new_colums);

        /**
        * Metoda wypełniająca komurkę
        * @param x [in] - numer kolumny
        * @param y [in] - numer wiersza
        * @param value [in] - znaczenie komórki
        */
        void write(const int x, const int y, const int value);

        /**
        * Funkcja zwracająca znaczenie komórki
        * @param x [in] - numer kolumny
        * @param y [in] - numer wiersza
        * @return - znaczenie komórki
        */
        int showPoint(const int x, const int y);

        /**
         * Funkcja zwracająca ilość kolumny w tablice
         * @return - ilość kolumny
         */
        int getColums();

        /**
         * Funkcja zwracająca ilość wierszy w tablice
         * @return - ilość wierszy
         */
        int getRows();





    private:
        int rows;   //Ilość wierszy
        int colums; //Ilość kolumny


};

#endif /* tablica_h */

