//
//  tablica.h
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#ifndef tablica_h
#define tablica_h

using namespace std;

class point
{
public:
    /**
     * Metoda wypełniająca komurkę
     * @param inf [in] —— dane do wypełnienia
     */
    virtual void write(string inf) = 0;

    /**
     * Funkcja odczytująca treść komórki
     * @return —— treść komórki
     */
    virtual string read() = 0;

    /**
     * Funkcja zwracająca typ komórki
     * @return —— typ komórki
     */
    int get_type();

protected:
    int type;
};

class pointInt: public point
{
public:
    pointInt()
    {
        type = 0;
        value = 0;
    }

    /**
     * Metoda wypełniająca komurkę
     * @param inf [in] —— dane do wypełnienia
     */
    void write(string inf) override;

    /**
     * Funkcja zwracająca typ komórki
     * @return —— typ komórki
     */
    string read() override;
private:
    int value;
};

class pointStr: public point
{
public:
    pointStr()
    {
        type = 1;
        value = "0";
    }

    /**
     * Metoda wypełniająca komurkę
     * @param inf [in] —— dane do wypełnienia
     */
    void write(string inf) override;

    /**
     * Funkcja zwracająca typ komórki
     * @return —— typ komórki
     */
    string read() override;
private:
    string value;
};

class pointDbl: public point
{
public:
    pointDbl()
    {
        type = 2;
        value = 0;
    }

    /**
     * Metoda wypełniająca komurkę
     * @param inf [in] —— dane do wypełnienia
     */
    void write(string inf) override;

    /**
     * Funkcja zwracająca typ komórki
     * @return —— typ komórki
     */
    string read() override;
private:
    double value;
};

class sheet
{
public:

    sheet()
    {
        open(10, 10, 1);
    }
    /**
     * Konstruktor inicjalizacji arkuszu
     * @param new_rows [in] —— Ilość wierszy
     * @param new_colums [in]—— Ilość kolumny
     * @param type [in] —— typ wszystkich komórek
     */
    sheet(const int new_rows, const int new_colums, const char type)
    {
        open(new_rows, new_colums, type);
    }

    /**
     * Metoda inicjalizacji arkuszu
     * @param new_rows [in] —— Ilość wierszy
     * @param new_colums [in]—— Ilość kolumny
     * @param type [in] —— typ wszystkich komórek
     */
    void open(const int new_rows, const int new_colums, const char type);

    /**
     * Metoda usuwająca arkusz z pamięci
     */
    void close();

    /**
     * Metoda zerująca wszystkie komórki arkuszu
     */
    void zero();

    /**
     * Metoda wyświetlająca arkusz
     */
    void show();

    /**
     * Metoda kopijująca arkuszy
     * @param new_sheet [out] —— nowy arkusz
     * @param rows [in] -— ilość wierszy
     * @param colums [in] —— ilość kolumny
     */
    void move(sheet &new_sheet, const int new_rows, const int new_colums);

    /**
     * Metoda zmieniająca typ komórki
     * @param type [in] —— żądany typ komórki
     * @param x [in] —— nr kolumnu
     * @param y [in] —— nr wierszu
     */
    void changePointType(const int type, const int x, const int y);

    /**
     * Metoda zmieniająca typ kolumny
     * @param type [in] —— żądany typ kolumny
     * @param x [in] —— nr kolumny
     */
    void changeColumType(const int type, const int x);

    /**
     * Metoda zmieniającą typ wierszy
     * @param type [in] —— żądany typ
     * @param y [in] —— nr wierszu
     */
    void changeRowType(const int type, const int y);

    /**
     * Metoda zmieniająca typ arkuszu
     * @param type [in] —— żądany typ arkuszu
     */
    void change_type(const int type);

    /**
    * Metoda zmniejszająca ilość kolumny
    * @param new_colums [in] - żądana ilość kolumny
    */
    void lessx(const int new_colums);

    /**
    * Metoda zwiększająca ilość kolumny
    * @param new_colums [in] - żądana ilość kolumny
    */
    void lessy(const int new_rows);

    /**
   * Metoda zwiększająca ilość kolumny
   * @param new_colums [in] - żądana ilość kolumny
   */
    void morex(const int new_colums);

    /**
    * Metoda zmieniająca rozmiaru tablicy
    * @param new_rows [in] - żądana ilość wierszy
    * @param new_colums [in] - żądana ilość kolumny
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
    void writePoint(const int x, const int y,const string value);

    /**
    * Funkcja zwracająca znaczenie komórki
    * @param x [in] - numer kolumny
    * @param y [in] - numer wiersza
    * @return - znaczenie komórki
    */
    string showPoint(const int x, const int y);

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

    int rows;
    int colums;
    point ***arr;
};



class new_arr
{
public:


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
    int **arr_int;      //Tablica dwuwymiarowa int
    string **arr_str;   //Tablica dwuwymiarowa string
    double **arr_dbl;   //Tablica dwuwymiarowa double
    char type;          //Typ tablicy
    int rows;           //Ilość wierszy
    int colums;         //Ilość kolumny


};


#endif /* tablica_h */

