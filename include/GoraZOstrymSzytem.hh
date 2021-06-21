#ifndef GORAZOSTRYMSZCZYTEM_HH
#define GORAZOSTRYMSZCZYTEM_HH


#include <iostream>
#include "BrylaGeometryczna.hh"

/*!
 *  \file 
 *  \brief Ten plik zawiera diefinicje klasy Graniastoslup6
 *   
 *  Klasa dziedziczy klase BrylaGeometryczna. Jako dane prywatne
 *  mamy polozenie w formie wektora3D oraz konta orientacji w formie
 *  double.
 */
class Gorazostrszczyt:public BrylaGeometryczna{
  Wektor3D Polozenie;
  double KatOrientacji_stopnie;
  
  public:
  //Graniastoslup6(unsigned int ktory,Wektor3D polozenieD);
  Wektor3D TransfDoUklWspRodzica(const Wektor3D& Wierz)const;
  void TworzSzczytoGore();
  /*Wektor3D& polozenie(const Wektor3D polozenieD);
  double& kat(double kat);
  double kat()const;*/
};


#endif