#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include "GoraZDlugaGran.hh"

#define PLIK_WLASCIWY__GRANIOGORA  "dat/PlikWlasciwy_Graniogora0.dat"

using namespace std;
/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa Graniogora
 */

/*!
 * \brief Funkcja transformujaca wspolrzedne do ukladu rodzica
 * 
 *  Funkcja transformuje wspolrzedne wierzcholkow do ukladu rodzica
 *  \param[in] Wierz wektor3D ktory chcemy transformowac
 *  \param[out] Nowy_polozenie wektor3D przetranformowany
 */
Wektor3D Graniogora::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    mtx=rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}

bool Graniogora::TworzGranioGore(Wektor3D polozenie,Wektor3D skala)
{
    Wektor3D vec;
    ofstream  Strumien_plikowy_wy;
    ifstream Strumien_plikowy_wej;
    std::string Nazwa=PLIK_WLASCIWY__GRANIOGORA;
    int LicznikWierzcholkow;
    StworzSkale(skala);
    Polozenie=polozenie;
    NazwaplikuW(0,0);
    Strumien_plikowy_wej.open(WezNazwePliku_BrylaWzorcowa());
    if (!Strumien_plikowy_wej.is_open())  {
        cerr << ":(  Operacja otwarcia do wczytania korupusu \"" <<  WezNazwePliku_BrylaWzorcowa()
        << "\"" << endl << ":(  nie powiodla sie." << endl;
        return false;
    }
    //26 lub 27
    Nazwa[27]=ile;
    Strumien_plikowy_wy.open(Nazwa);
    if (!Strumien_plikowy_wy.is_open())  {
        cerr << ":(  Operacja otwarcia do zapisu " <<  Nazwa
        << "" << endl << ":(  nie powiodla sie." << endl;
        return false;
    }

    Strumien_plikowy_wej >> vec;
    while (!Strumien_plikowy_wej.fail()) 
    {
        LicznikWierzcholkow=0;
        for(;LicznikWierzcholkow<4;++LicznikWierzcholkow)
        {
            if (vec[2] > 0.5) 
            { // Tutaj realizowana jest deformacja
	            if (vec[0] < 0) 
                    vec[0] = fabs(vec[0]);
            }
            //std::cout << vec << endl;
            vec=Skaluj(vec);
            vec=TransfDoUklWspRodzica(vec);
            Strumien_plikowy_wy << vec << endl;
            Strumien_plikowy_wej >> vec;
        }
        Strumien_plikowy_wy << endl;
    }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  ile+=1;
  return true;
    
}