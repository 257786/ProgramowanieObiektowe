//
//  main.cpp
//  ##5
//
//  Created by yaroslav on 30/04/2021.
//

#include <iostream>
#include <fstream>
#include "tablica.h"
#include "menu.h"
#include "plik.h"
#include "colors.h"
using namespace std;
int main(/*int argc, const char * argv[]*/)
{
    //Utworzenie tablicy
    sheet arr;




    //Tworzenie plików wyjściowych i wejściowych
    outPlik plikOut;
    inPlik plikIn;

    //Wykonanie programu
    while(choice)
    {
        homePage();
        cin >> choice;

        switch (choice) {
            case 1:
                arr.show();
                break;
            case 2:
                sizePage(arr);
                break;
            case 3:
                writePage(arr);
                break;
            case 4:
                typePage(arr);
                break;
            case 5:
                writeFilePage(arr,  plikOut);
                break;
            case 6:
                openFilePage(plikIn, arr);
                break;
            case 0: break;
            default:
                cout << "Nie ma tagiego polecenia" << endl;
                break;
        }
    }

    arr.close();
    return 0;
}
