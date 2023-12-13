#ifndef TABLICA_H_INCLUDED
#define TABLICA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <windows.h>

using namespace std;

/// a) Tablica

class Tablica
{

 private:
    int* head;        //wska�nik na pocz�tek tablicy
    int rozmiar;      //liczba element�w w tablicy
    HANDLE hOut;

 public:

     //konstruktor tablicy
     Tablica(int rozmiar, HANDLE h);

     //Menu dla tablicy

     void menu();

     void choice();

     //Uzupe�nienie tablicy wartosciami z pliku tekstowego

     void complete(int indeks, int liczba);

     //Wyswietlenie tablicy

     void display();

     void displayColor(int index);

     //dodawanie element�w na poczatek tablicy

     void addFirst(int dane);

     //dodawanie element�w na ko�cu tablicy

     void addLast(int dane);

     //dodawanie element�w w dowolnym miejscu tablicy

     int addAnywhere(int indeks, int dane);

     //Wyszukiwanie elementu w tablicy

     int findElem(int value);

     //usuwanie elementu w dowolnym miejscu tablicy

     int deleteElemAny(int indeks);

     //Usuniecie pierwszego elementu z tablicy

     int deleteElemFirst();

     //Usuniecie ostatniego elementu z tablicy

     int deleteElemLast();

     //destruktor
     ~Tablica();
};

#endif // TABLICA_H_INCLUDED
