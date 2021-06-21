//
//  tablica.h
//  Step3
//
//  Created by yaroslav on 26/04/2021.
//

#ifndef tablica_h
#define tablica_h
#include <vector>
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
    virtual int get_type() = 0;

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
     * Funkcja wyświetlająca treść komórki
     * @return —— treść
     */
    string read() override;
    /**
     * Funkcja która zwraca typ komórki
     * @return —— typ komórki
     */
    int get_type() override;
private:
    int value;
    int type;
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

    int get_type() override;
private:
    string value;
    int type;
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
    int get_type() override;
private:
    double value;
    int type;
};

class sheet
{
public:

    /**
     * Konstruktor, który zazwyczaj tworzy arkusz o rozmiaru 10x10 w typie string
     */
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
     * Destruktor który usuwa z pamięci wsystkie komórki
     */
//    ~sheet()
//    {
//        close();
//    }

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


    point* getPoint(const int i, const int j);



    /**
     * Metoda zmieniająca typ komórki
     * @param type [in] —— żądany typ komórki
     * @param x [in] —— nr kolumnu
     * @param y [in] —— nr wierszu
     */
    void changePointType(const int type, const int i, const int j);

    /**
     * Metoda zmieniająca typ kolumny
     * @param type [in] —— żądany typ kolumny
     * @param x [in] —— nr kolumny
     */
    void changeColumType(const int type, const int j);

    /**
     * Metoda zmieniającą typ wierszy
     * @param type [in] —— żądany typ
     * @param y [in] —— nr wierszu
     */
    void changeRowType(const int type, const int i);

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

    /**
     * Funkcja zwracająca wskaźnik elementu;
     * @return wskaźnik komórki;
     */
    point*** getArr();



    /**
     * Funkcja zwracająca typ komórki:
     * @param i —— nr wierszu;
     * @param j —— nr kolumny;
     * @return —— typ komórki;
     */
    int getPointType(const int i, const int j);

    /**
     * Metoda kopijująca dane z jednego arkuszu do drugiego
     * @param new_arr —— nowy arkusz
     * @param p —— wskaźnik na komórkę pierwszego arkuszu
     * @param i —— nr wierszu
     * @param j —— nr kolumny
     */
    void copy(sheet &new_arr, point* p, const int i, const int j);

    /**
     * Metoda losowo wypełniająca arkusz;
     */
    void fill();

    /**
     * Funkcja zwracająca sumę komórek wierszu
     * @param i —— nr wierszu
     * @return —— suma komórek
     */
    string getRowSum(const int i);

    /**
     * Funkcja zwracająca sumę komórek kolumny
     * @param j —— nr kolumny
     * @return —— suma komórek
     */
    string getColumSum(const int j);

    /**
     * odzyskiwanie imienia arkuszu
     * @return imię
     */
    string getName();

    /**
     * nadanie imienia arkuszu
     * @param name [in] —— nowe imię.
     */
    void setName(const string name);

private:

    int rows;
    int colums;
    point*** arr;
    string name;


};


class arkuszy
{
private:
    int size;
public:
    /**
     * Konstruktor
     */
    arkuszy();

    /**
     * dodawanie arkuszu
     */
    void add();
    /**
     * usuwanie arkuszu
     * @param nr (numer arkuszu, który chcemy usunąć)
     */
    void del(const int nr);

    /**
     * Uzyskiwanie rozmiaru
     * @return rozmiar tablicy arkuszów
     */
    int getSize();
    sheet* arr;

    int current;

    void close();
};



//////////////////////////////////////////////

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