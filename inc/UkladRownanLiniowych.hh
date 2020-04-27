#ifndef UkladRownanLiniowychHH
#define UkladRownanLiniowych_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename Typ, int ROZMIAR>
class UkladRownanLiniowych{
 SWektor<Typ,ROZMIAR> Wek;
 SMacierz<Typ,ROZMIAR> Mac;
 SWektor<Typ,ROZMIAR> Wynik;
 SWektor<Typ,ROZMIAR> Bledu;
  public:
  SWektor<Typ,ROZMIAR> get_Wek() const;
  SMacierz<Typ,ROZMIAR> get_Mac() const;
  SWektor<Typ,ROZMIAR> &set_Wek() ;
  SMacierz<Typ,ROZMIAR> &set_Mac() ;
  SWektor<Typ,ROZMIAR> get_Wynik()const; 
  void Bledy();
  int oblicz();   
};
template <typename Typ, int ROZMIAR>
 SWektor<Typ,ROZMIAR> UkladRownanLiniowych<Typ,ROZMIAR>::get_Wek() const
   {return Wek;}
   template <typename Typ, int ROZMIAR>
   SMacierz<Typ,ROZMIAR> UkladRownanLiniowych<Typ,ROZMIAR>::get_Mac() const
      {return Mac;}
      template <typename Typ, int ROZMIAR>
    SWektor<Typ,ROZMIAR> &UkladRownanLiniowych<Typ,ROZMIAR>::set_Wek() 
       {return Wek;}
       template <typename Typ, int ROZMIAR>
   SMacierz<Typ,ROZMIAR> &UkladRownanLiniowych<Typ,ROZMIAR>::set_Mac() 
      {return Mac;}
template <typename Typ, int ROZMIAR>
   int UkladRownanLiniowych<Typ,ROZMIAR>::oblicz()
   {
       SMacierz<Typ,ROZMIAR> Kop;
       Typ Wyz;
      Wyz= Mac.wyznacznik();
        std::cout<<"////////////////////"<<std::endl;
     std::cout<<Wyz<<std::endl;
      std::cout<<"////////////////////"<<std::endl;
      if(Wyz==0)
      {
          for(int i=0; i<ROZMIAR; i++)
          {
              Kop=Mac;
              Kop[i]=Wek;
              if(Kop.wyznacznik()==0)
                return 0;
          }
          return 1;
      }

            for(int i=0; i<ROZMIAR; i++)
          {
              Kop=Mac;
              Kop[i]=Wek;
            Wynik[i]=Kop.wyznacznik()/Wyz;

          }
          return 0;


   }
   template <typename Typ, int ROZMIAR>
   void UkladRownanLiniowych<Typ,ROZMIAR>::Bledy()
   {
       Bledu=Mac*Wynik-Wek;
       std::cout<<"SWektor<Typ,ROZMIAR> bledu :"<<Bledu<<std::endl;
       std::cout<<"Dlugosc SWektor<Typ,ROZMIAR>a bledu :"<<Bledu.dlugosc()<<std::endl;

   }
   template <typename Typ, int ROZMIAR>
 SWektor<Typ,ROZMIAR> UkladRownanLiniowych<Typ,ROZMIAR>::get_Wynik()const
 {
     return Wynik;
 }
 template <typename Typ, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Typ,ROZMIAR> &UklRown)
      {
            Strm>>UklRown.set_Mac()>>UklRown.set_Wek();
            return Strm;
      }
      template <typename Typ, int ROZMIAR>
std::ostream& operator << ( std::ostream                  &Strm, 
                            const UkladRownanLiniowych<Typ,ROZMIAR>    &UklRown
                          )
      {
          Strm<<"A^T:"<<std::endl;
            Strm<<UklRown.get_Mac();
 Strm<<"Wektro wyrazow wolnych:"<<std::endl;
            Strm<<UklRown.get_Wek()<<std::endl;
            return Strm;
      }

#endif
