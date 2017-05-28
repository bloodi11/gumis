#include<iostream>
#include <string>
#include <vector>
#include <cstdlib>
void KonwerterONP(AnsiString tab, int* okz, AnsiString* str)
{
  TStos* wierzcholek;
  Stos stos(wierzcholek);
  AnsiString s;
  float* liczba;
  float zmp;
  liczba = &zmp;
  char zn; char* st;
  TDane element;

    do
    {
      PobierzSymbolONP(liczba, tab, okz, str);
      if ((*str >= '0' && *str <= "9999999999") || *str == 'x')
      {
        s = s + *str + ' ';
      }
      else
      {
        zn = *str->c_str();
        if (zn == ')')
        {
 do
            {
              stos.Pop(wierzcholek, element);
              if (element != '(')
              {
                s = s + element + ' ';
              }
            }
            while (element != '(');
        }
        else
        {
          if (stos.IsEmpty(wierzcholek)) {stos.Push(wierzcholek, zn);}
          else
          {
            if (stos.Pobierz(wierzcholek) == '(')
            {
              stos.Push(wierzcholek, zn);
            }
            else
            {
              if ((zn == '*' || zn == '/' || zn == 'N') && (stos.Pobierz(wierzcholek) == '+' || stos.Pobierz(wierzcholek) == '-'))
              {
                stos.Push(wierzcholek, zn);
              }
              else
              {
                if ((zn == '+' || zn =='-') && (stos.Pobierz(wierzcholek) == '+' || stos.Pobierz(wierzcholek) == '-' || stos.Pobierz(wierzcholek) == '*' || stos.Pobierz(wierzcholek) == '/' || stos.Pobierz(wierzcholek) == 'N'))
                {
                    stos.Pop(wierzcholek, element);
                    s = s + element + ' ';
                    if (!stos.IsEmpty(wierzcholek))
                    {
if (stos.Pobierz(wierzcholek) == '+' || stos.Pobierz(wierzcholek) == '-')
                      {
                        stos.Pop(wierzcholek, element);
                        s = s + element + ' ';
                      };
                    };
                    stos.Push(wierzcholek, zn);
                }
                else
                {
                  if ((zn == '*' || zn == '/' || zn == 'N') && (stos.Pobierz(wierzcholek) == '*' || stos.Pobierz(wierzcholek) == '/' || stos.Pobierz(wierzcholek) == 'N'))
                  {
                    stos.Pop(wierzcholek, element);
                    s = s + element + ' ';
                    stos.Push(wierzcholek, zn);
                  }
                  else
                  {
                    if ((zn == '('))
                    {
                      stos.Push(wierzcholek, zn);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    while (*str != "");

    element = stos.PobierzZnak(wierzcholek);
    if (!(element == '\0'))
    {
      do
      {
        stos.Pop(wierzcholek, element);
        s = s + element + ' ';
        if (wierzcholek == NULL) {element = '\0';}
      } while(element != '\0');
    };

  *str = s;
  stos.KoniecS(wierzcholek);
};

bool Parzysta(int liczbaminusow);

//Jest to zmieniona funkcja w stosunku do tej uzytej w analizatorze skladniowym,
//ta funkcja zaklada ze wyrazenie z ktorego sa pobierane znaki jest poprawne (czyli poddane zostalo dzialaniu analizatora skladniowego);
bool PobierzSymbolONP(float* liczba, AnsiString tab, int* okz, AnsiString* str)
{
  bool zmp2 = true;
  char znak;
  bool zmp = true;
  int liczbaprzecinkow = 0;
  AnsiString string;
  *str = "";
  if (*okz <= tab.Length())
  {
