

#include "Scena.hh"


using namespace std;
/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasa Scena
 */
/*!
 * \brief Funkcja zwracajaca aktywnego drona
 * 
 *  Funkcja zwraca aktywnego drona
 *  \param[in] i zmienna int do wyboru drona
 *  \param[out] TabDronow[i] referencja do zmiennej typu Dron
 */
Dron& Scena::WezAktywnegoDrona(int i)
{
    return TabDronow[i];
}

/*!
 * \brief Funkcja uzycia drona
 * 
 *  Funkcja animuje caly lot drona w sekwencji. Zakancza sie jezeli uzytkownik
 *  wpisze "N".
 *  \param[in] i zmienna int do wyboru drona
 *  \param[out] true jezeli wszystko zadzialalo poprawnie
 */
bool Scena::UzyjAktynegoDrona(int i)
{
    Wektor3D przemieszczenie;
    Dron AktywnyDron;
    std::vector<Wektor3D> wierz_trasy;
    double kat=0,dlugosclotu=40;
    AktywnyDron=WezAktywnegoDrona(i);
    AktywnyDron.KtoryDron(i);
    if(!AktywnyDron.Oblicz_i_Zapisz_WspGlbDrona()) return false;
    //AktywnyDron.TworzDrona();
    Lacze.Rysuj();
    char wybor[2]=" ";
    while(wybor[0]!='N')
    {
        cout << "Podaj wektor o jaki ma sie przesunac dron (na koniec wpisz 0)";
        cin >> przemieszczenie;
        cout << "Nacisnij ENTER, aby pokazac sciezke przelotu drona " << flush;
        cin.ignore(10000,'\n');
        AktywnyDron.PlanujPoczatkowaSciezke(kat,dlugosclotu,przemieszczenie,wierz_trasy,Lacze);
        Lacze.Rysuj();
        cout << "Nacisnij ENTER, aby wykonac ruch drona " << flush;
        cin.ignore(10000,'\n');
        
        
        if(!AktywnyDron.WykonajPionowyLot(dlugosclotu,Lacze)) return false;
        if(!AktywnyDron.WykonajPoziomyLot(dlugosclotu,przemieszczenie,Lacze)) return false;
        if(!AktywnyDron.WykonajPionowyLot(dlugosclotu,Lacze)) return false;
        
        Lacze.Rysuj();
        cout << "Jezeli nie chcesz kontynuowac wpisz N";
        cin >> wybor;
    }
    TabDronow[i]=AktywnyDron;
    return true;
}
/*!
 * \brief Funkcja ustawia zeminna Lacze
 * 
 *  Funkcja ustawia Lacze do gnuplota
 *  \param[in] Lacze referencja do PzG::LaczeDoGNUPlota
 */
void Scena::UstawLacze(PzG::LaczeDoGNUPlota& Lacze)
{
    this->Lacze=Lacze;
}
/*!
 * \brief Funkcja inicjuje stan poczatkowy na scenie
 * 
 *  Funkcja ustawia parametry poczatkowe dronow oraz je wyswietla.
 */
void Scena::Poczatek()
{
    Dron AktywnyDron;
    Wektor3D pol,skal;
    unsigned int n=0;
    //const char* cos=TabPlask[0].WezNazwePliku_BrylaFinalna();
    for(unsigned int index;index<2;++index)
    {
        AktywnyDron=WezAktywnegoDrona(index);
        AktywnyDron.KtoryDron(index);
        AktywnyDron.Oblicz_i_Zapisz_WspGlbDrona();
        Lacze.Rysuj();
    }

    



    Lst.push_back(new Plaskowyz());
    Lst.push_back(new Szczytogora());
    Lst.push_back(new Graniogora());
    for(BrylaGeometryczna *wsk : Lst)
    {
        n+=1;
        if(n==1)
        {
            pol[0]=150;
            pol[1]=105;
            pol[2]=0;
            skal[0]=50;
            skal[1]=60;
            skal[2]=15;
        }
        else if(n==2)
        {
            pol[0]=60;
            pol[1]=120;
            pol[2]=0;
            skal[0]=20;
            skal[1]=45;
            skal[2]=35;
        }
        else
        {
            pol[0]=100;
            pol[1]=90;
            pol[2]=0;
            skal[0]=20;
            skal[1]=80;
            skal[2]=30;
        }
        if(!wsk->Tworz(pol,skal))
            cout << "dizasta" << endl;
    }

    
    Lacze.Rysuj();
}