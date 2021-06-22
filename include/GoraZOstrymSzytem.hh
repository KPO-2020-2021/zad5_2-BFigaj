#ifndef GORAZOSTRYMSZCZYTEM_HH
#define GORAZOSTRYMSZCZYTEM_HH


#include <iostream>
#include "BrylaGeometryczna.hh"
#define PLIK_WLASCIWY__SZCZYTOGORA  "dat/PlikWlasciwy_Szczytogora0.dat"
/*!
 *  \file 
 *  \brief Ten plik zawiera diefinicje klasy Szczytogora
 *   
 *  Klasa dziedziczy klase BrylaGeometryczna. Jako dane prywatne
 *  mamy polozenie w formie wektora3D oraz konta orientacji w formie
 *  double a takze unsigned int ile czyli ktora to szczytogora.
 */
class Szczytogora:public BrylaGeometryczna{
  Wektor3D Polozenie;
  double KatOrientacji_stopnie;
  unsigned int ile;

  public:
  //Graniastoslup6(unsigned int ktory,Wektor3D polozenieD);
  Wektor3D TransfDoUklWspRodzica(const Wektor3D& Wierz)const;
  bool TworzSzczytoGore(Wektor3D polozenie,Wektor3D skala);
  /*Wektor3D& polozenie(const Wektor3D polozenieD);
  double& kat(double kat);
  double kat()const;*/
};


#endif