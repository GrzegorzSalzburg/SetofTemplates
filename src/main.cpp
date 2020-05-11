#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  char znak;
  cin>>znak;
  if(znak=='z')
  {
   UkladRownanLiniowych<LZespolona,5>   UklRown;   // To tylko przykladowe definicje zmiennej
   cin>>UklRown;
   cout<<UklRown;
   UklRown.oblicz();
   cout<<UklRown.get_Wynik()<<endl;
   UklRown.Bledy();
   cout << endl << " Koniec programu " << endl << endl;
  }
  else if(znak=='r')
  {
   UkladRownanLiniowych<double,5>   UklRown;   // To tylko przykladowe definicje zmiennej
   cin>>UklRown;
   cout<<UklRown;
   UklRown.oblicz();
   cout<<UklRown.get_Wynik()<<endl;
   UklRown.Bledy();
   cout << endl << " Koniec programu " << endl << endl;
  }
  else
  {
   cout<<"zla nazwa"<<endl;
  }
  
}
