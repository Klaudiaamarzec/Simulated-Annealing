#include "Graf.h"

// konstruktor grafu

    Graf::Graf(int w)
    {
        this->rozmiarw = w;

        // Stworzenie tablicy dynamicznej dlawierzcholków
        this->wierzcholki = new int[w];

        build();
    }

    // Uzupelnienie tablic

    void Graf::completeWierzcholki()
    {
        for(int i=0; i<rozmiarw; i++)
        {
            wierzcholki[i] = i;
        }
    }

    int Graf::matrixValue(int i, int j)
    {
        return macierz.matrixValue(i, j);
    }

    void Graf::completeMacierz(int droga, int i, int j)
    {
        macierz.completeMacierz(droga, i, j);
    }

    // Wyswietlenie tablicy wierzcholkow

    void Graf::displayWierzcholki()
    {
        for(int i=0; i<rozmiarw; i++)
            cout << wierzcholki[i] << " ";

        cout << endl;
    }

    void Graf::choice()
    {
        int wybor, wierzcholek=0;

        //cout <<"Podaj indeks wierzcholka startowego: ";
        //cin >> wierzcholek;

        macierz.displayMacierz();
        cout << endl;

        do
        {
            menu();
            cin >> wybor;
            system("cls");

            switch(wybor)
            {
                case 1:
                    {
                        // Brute Force

                        cout << endl << "ALGORYTM BRUTE FORCE" << endl;

                        macierz.displayMacierz();

                        int blad;

                        do
                        {
                            blad=0;

                            if(wierzcholek>=rozmiarw || wierzcholek<0)
                                blad=1;

                        }while(blad==1);

                        int *wynik = macierz.bruteForce(wierzcholek);

                        cout << endl << "NAJLEPSZE ROZWIAZANIE: ";
                        for (int i = 0; i < rozmiarw; i++)
                            cout << wynik[i] << " -> ";

                        cout << wynik[rozmiarw] << endl;

                        int wynik2 = macierz.returnCost();

                        cout << "Koszt: " << wynik2 << endl << endl;

                        break;
                    }
                case 2:
                    {
                        // Symulowane Wyzarzanie

                        cout << endl << "ALGORYTM SYMULOWANEGO WYZARZANIA" << endl;

                        //macierz.displayMacierz();

                        int blad;

                        do
                        {
                            blad=0;

                            if(wierzcholek>=rozmiarw || wierzcholek<0)
                                blad=1;

                        }while(blad==1);

                        Travel best = macierz.simulatedAnnealing(startingTemp, iterations, alpha, wierzcholek);

                        cout << "NAJLEPSZE ROZWIAZANIE" << endl;
                        best.display();

                        int wynik2 = macierz.bestDist();

                        cout << "Najlepszy koszt: " << wynik2 << endl << endl;

                        break;
                    }
                case 3:
                    {
                        macierz.displayMacierz();
                        cout << endl;
                        break;
                    }
            }
        }
        while(wybor!=0);
    }

    void Graf::build()
    {
        macierz.stworz(rozmiarw);
    }

    // POMIARY

    void Graf::pomiary(int rozmiar)
    {
        ofstream plik("pomiary.txt", std::ios::app);
        srand(time(NULL));

        if(plik.is_open())
        {
            // 2. Algorytm Simulated Annealing

            // Losowanie wierzcholka startowego

            wierzcholek = rand()%rozmiarw;

            //pomiar czasu przed wykonaniem operacji
            LARGE_INTEGER start;
            QueryPerformanceCounter(&start);

            macierz.simulatedAnnealing(startingTemp, iterations, alpha, wierzcholek);

            //pomiar czasu po wykonaniu operacji
            LARGE_INTEGER koniec;
            QueryPerformanceCounter(&koniec);

            //obliczenie czasu
            LARGE_INTEGER frequency;
            QueryPerformanceFrequency(&frequency);
            double czas = (koniec.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

            plik << czas << "   ";

            plik << endl;
        }
        else
            cout << "Nie udalo sie otworzyc pliku" << endl;

        plik.close();
    }

    void Graf::menu()
    {
        cout << "1. Algorytm Brute Force\n";
        cout << "2. Algorytm Symulowanego Wyzarzania\n";
        cout << "3. Wyswietlenie macierzy\n";
        cout << "0. EXIT\n";
    }
