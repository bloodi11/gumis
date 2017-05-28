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
znak = tab[*okz];
  }
  else
  {
    znak = '\0';
  }
  if (znak == ',') {return (false);};
  while (znak == '0' || znak == '1' || znak == '2' || znak == '3' || znak == '4' || znak == '5' || znak == '6' || znak == '7' || znak == '8' || znak == '9' || znak == ',')
  {
    if (znak == ',')
    {
      liczbaprzecinkow++;
    };
    if (liczbaprzecinkow == 2)
    {
      return (false);
    };
    zmp2 = false;
    string = string + znak;
    *okz = *okz + 1;
    if (*okz <= tab.Length()) {znak = tab[*okz];};
    if (*okz == tab.Length() && *okz > 1 && (znak == '0' || znak == '1' || znak == '2' || znak == '3' || znak == '4' || znak == '5' || znak == '6' || znak == '7' || znak == '8' || znak == '9'))
    {
      if ((tab[tab.Length() - 1] >= '0' && tab[tab.Length() - 1] <= '9') || tab[tab.Length() - 1] == ',')
      {
        string = string + znak;
        *okz = *okz + 1;
      }
    };
    if (*okz >= tab.Length()) {break;};
    if (zmp == true) {zmp = false;};
  };
  if (zmp == true && zmp2 == true)
  {
    if (znak == 'x')
    {
      *str = znak;
      *okz = *okz + 1;
      return (true);
    };
//----------------tu nastepuje zmiana--------------------
    if (znak == '+' || znak == '-' || znak == '*' || znak == '/' || znak == '(' || znak == ')')
    {
      if (znak == '+' || znak == '-')
      {
        bool poczatek = false; //poczatek znaku minus;
        if (*okz == 1) {poczatek = true;};
        if (*okz != 1)
        {
          if (tab[*okz - 1] == '(')
          {
            poczatek = true;
          };
        };
        int liczbaminusow = 0;
        if (znak == '-') {liczbaminusow++;};
        *okz = *okz + 1;
        if ((tab[*okz] >= '0' && tab[*okz] <= '9') || (tab[*okz] == 'x') || (tab[*okz] == '(') || (tab[*okz] == ')') || (tab[*okz] == '*') || (tab[*okz] == '/'))
        {
          if (*str == '+')
          {
            *str = '+';
            return (true);
          }
          else
          {
            if (poczatek)
            {
              *str = 'N';
              return (true);
            };
            *str = znak;
            return (true);
          }
        };
        while (tab[*okz] == '+' || tab[*okz] == '-')
        {
          if (tab[*okz] == '-')
          {
            liczbaminusow++;
          };
          *okz = *okz + 1;
        };
        if (Parzysta(liczbaminusow))
        {
          if (poczatek)
          {
            *str = '+';
            return (true);
          };
          *str = '+';
        }
        else
        {
          if (poczatek)
          {
            *str = 'N';
            return (true);
          };
*str = '-';
        }
        return (true);
      }
      else
      {
        *str = znak;
        *okz = *okz + 1;
        return (true);
      };
    };
  };
//----------------tu konczy sie zmiana-------------------
  if (string != "")
  {
    if (string[string.Length()] == ',') {return (false);};
    *liczba = StrToFloat(string);
    *str = string;
    return (true);
  }
  else
    {
      *okz = *okz + 1;
      if (*okz >= tab.Length())
      {
        return (true);
      }
      else
      {
        return (false);
      }
    }
}

bool Parzysta(int liczbaminusow)
{
  int zmp;
  zmp = liczbaminusow % 2;
  if (zmp == 0)
  {
    return (true);
  }
  else
  {
    return (false);
  }
}
