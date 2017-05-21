#include<iosteram>
cell * ZapisOnp(char *input);
{
    char stos[20];
    cell kolejka[20];
    int flaga, i=0, j=0,  priorytet;
    char * znak;
    char *znakZwierzcholka;
    int *liczba;
    while(flaga)
    {
        flaga=pobierzSymbol(input, liczba);//rozne od -1
        switch(flaga)
        {
        case 0:
            odczytStosu(stos, kolejka, 5);

        case 1:
            kolejka[i].liczba=*liczba;
            i++;
            break;
       case 2:
            kolejka[i].znak='x';
            i++;
            break;
        case 3:
                stos[j]='(';
                j-odczytStosu(stos, kolejka, 4);
                break;
        case 4:
                stos[j]=')';
                j++;
                break;
 case 5:
               if(1>wierzcholek(znakZwierzcholka,stos))
               {
                   stos[j]='+';
                   j++;
               }
               else
               {
                   j-odczytStosu(stos, kolejka, 1);//cofanie
                   stos[j]='+';//j zalezne od funkcji
               }

        case 6:
                if(1>wierzcholek(znakZwierzcholka, stos))
               {
                   stos[j]='-';
                   j++;
               }
               else
               {
                   j-odczytStosu(stos, kolejka, 1);//cofanie
                   stos[j]='-';//j zalezne od funkcji
                }
           case 7:
                if(2>wierzcholek(znakZwierzcholka, stos))
               {
                   stos[j]='*';
                   j++;
               }
               else
               {
                   j-odczytStosu(stos, kolejka, 2);//cofanie
                   stos[j]='*';//j zalezne od funkcji
                }
          case 8:
                if(2>wierzcholek(znakZwierzcholka, stos))
               {
                   stos[j]='/';
                   j++;
               }
               else
               {
                   j-odczytStosu(stos, kolejka, 2);//cofanie
                   stos[j]='/';//j zalezne od funkcji
                }
            case 9:
                if(3>wierzcholek(znakZwierzcholka, stos))
               {
                   stos[j]='/';
                   j++;
               }
               else
               {
                   j-odczytStosu(stos, kolejka, 3);//cofanie
                   stos[j]='^';//j zalezne od funkcji
                }
            }
            else
                return NULL;
        }
        return NULL;
    }
    return kolejka;
}
