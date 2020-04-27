#include "LZespolona.hh"

bool LZespolona::operator == (LZespolona  Skl2)
{
  if(re==Skl2.get_re() && im==Skl2.get_im())
  {
    return true;
  }
  return false;
}
bool LZespolona::operator != (LZespolona  Skl2)
{
  if(re!=Skl2.get_re() || im!=Skl2.get_im())
  {
    return true;
  }
  return false;
}

std::ostream & operator <<(std::ostream &wyj, LZespolona Skl1)
{
   wyj<<"("<<Skl1.get_re()<<showpos<<Skl1.get_im()<<noshowpos<<"i)";
   return wyj;
}

std::istream & operator >> (std::istream &wej, LZespolona & Skl1)
{
   char znak;
   wej>>znak;
   if(znak!='(')
   {
     wej.setstate(ios_base::badbit);
   }
        wej>>Skl1.set_re()>>Skl1.set_im();
        wej>>znak;
          if (znak!='i')
            {
              wej.setstate(ios_base::badbit);
            }
        wej>>znak;
          if (znak!=')')
            {
               wej.setstate(ios_base::badbit);
            }
	 return wej;
}
LZespolona  LZespolona::operator += ( LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re + Skl2.get_re();
  Wynik.set_im() = im + Skl2.get_im();
  return Wynik;
}
LZespolona  LZespolona::operator -= (  LZespolona  Skl2)
{
    LZespolona  Wynik;

  Wynik.set_re() = re - Skl2.get_re();
  Wynik.set_im() = im - Skl2.get_im();
  return Wynik;

}


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator + (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re + Skl2.get_re();
  Wynik.set_im() = im + Skl2.get_im();
  return Wynik;
}
/*!
 * Realizuje odejmowanie  dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator - (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re - Skl2.get_re();
  Wynik.set_im() = im - Skl2.get_im();
  return Wynik;
}
/*!
 * Realizuje mnozenie  dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  LZespolona::operator * (LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.set_re() = re*Skl2.get_re()-im*Skl2.get_im();
  Wynik.set_im() = re*Skl2.get_im()+im*Skl2.get_re();
  return Wynik;
}
/*!
 * Realizuje sprzezenie  dwoch liczb zespolonych.
 * Argumenty:
 *    Skl - skladnik sprzezenia,
 * Zwraca:
 *    Sprzezenie skladnika podanego jako parametr.
 */
LZespolona LZespolona::Sprzezenie()
{
  LZespolona Skl=*this;
  Skl.im=-Skl.im;
  return Skl;
}
/*!
 * Realizuje modul podniesiony do kwadratu.
 * Argumenty:
 *    Skl - skladnik tej funkcji,
 * Zwraca:
 *    Modul podniesiony do kwadratu skladnika podanego jako parametr.
 */
double LZespolona::Modul2()
{
  return im*im+re*re;
}

LZespolona  LZespolona::operator / ( double  Skl2)
{
    LZespolona  Wynik;
  assert(Skl2!=0);
  Wynik.set_re() = re/Skl2;
  Wynik.set_im() = im/Skl2;
  return Wynik;
}

LZespolona  LZespolona::operator / (LZespolona  Skl2)
{
  assert(Skl2.get_im()!=0 || Skl2.get_re()!=0 );
  return (*this*Skl2.Sprzezenie())/Skl2.Modul2();
}