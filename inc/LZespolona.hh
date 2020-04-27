#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cassert>
using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */
/*!Modeluje pojecie liczby zespolonej*/
class  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  public:
 explicit LZespolona(double re=0, double im=0):re(re),im(im){
    
  }
LZespolona Sprzezenie( );
double get_re()const{return re;}
double get_im()const{return im;}
double &set_re(){return re;}
double &set_im(){return im;}
double Modul2( );
bool operator == (LZespolona  Skl2);
bool operator != ( LZespolona  Skl2);
LZespolona  operator += ( LZespolona  Skl2);
LZespolona  operator -= (  LZespolona  Skl2);
LZespolona  operator + (  LZespolona  Skl2);
LZespolona  operator - (  LZespolona  Skl2);
LZespolona  operator * (  LZespolona  Skl2);
LZespolona  operator / (  LZespolona  Skl2);
LZespolona  operator / (  double  Skl2);
};




/*Zapowiedzi definicji przeciazen operatorow*/
std::ostream & operator <<(std::ostream &wyj, LZespolona Skl1);
std::istream & operator >> (std::istream &wej, LZespolona & Skl1);

#endif
