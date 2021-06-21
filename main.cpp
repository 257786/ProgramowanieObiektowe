//
//  main.cpp
//  ##5
//
//  Created by yaroslav on 30/04/2021.
//

#define this_arr _arr.arr[_arr.current]
#include <iostream>
#include "tablica.h"
#include "menu.h"
using namespace std;


int main1()
{
    inPlik plik("plik.txt");
    cout<< plik.getColums()<< endl;
    cout << plik.showPoint(9,1)<<"k\n";
    return 0;
}
int main(int argc, const char * argv[])
{

    arkuszy _arr;
    int choice = 10;
    //Utworzenie tablicy




    //Wykonanie programu


    while(choice)
    {
        homePage(_arr);
        cin >> choice;

        switch (choice) {
            case 1:
                show(this_arr);
                break;
            case 2:
                sizePage(this_arr);
                break;
            case 3:
                writePage(this_arr);
                break;
            case 4:
                typePage(this_arr);
                break;
            case 5:
                writeFilePage(this_arr);
                break;
            case 6:
                openFilePage(this_arr);
                break;
            case 7:
                getSumPage(this_arr);
                break;
            case 8:
                showArkuszy(_arr);
                newPage(_arr);
                setArkusz(_arr);
                break;
            case 9:
                delPage(_arr);
                break;
            case 10:
                changeName(_arr);
                break;
            case 555:
                this_arr.fill();
                break;
            case 0: break;
            default:
                cout << "Nie ma tagiego polecenia" << endl;
                break;
        }
    }
    _arr.close();
    return 0;
}

