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
