# <cstdio>

Štadndardný vstup a výstup sa považuje za súbor (s tým rozdielom, že "naozajstný súbor" má meno a je niekde uložený etc.). Na rozdiel od
ostatných súborov (textových/binárnych/...) sú štandardný vstup a výstup otvorené a programu prístupné automaticky.

Deklarácia štandardného vstupu, výstupu a chybového výstupu:


    
```c++  
FILE *stdin; //standardny vstup - typicky klavesnica
FILE *stdout; //standardny vystup - typicky obrazovka
FILE *stderr; //standardny chybovy vystup - typicky obrazovka
```

Všetko sú to ukazovatele na štruktúru FILE, ktorá je deklarovaná v <cstdio> a je určená na prácu so súbormi. Táto štruktúra je argumentov
mnohých funkcií z <cstdio>.



Funkcie, ktoré pracujú s týmito vstupmi a výstupmi sú printf() (zapisuje do standardneho vystupu) a scanf().

    
```c++  
int printf(const char *format, [, arg, ...]);
```
vracia počet znakov zapísaných do výstupu alebo EOF (=koniec súboru alebo tiež koniec štandardného vstupu a výstupu)
 v prípade chyby zápisu.
 
 Prvý argument prontf() je konštantný reťazec, ktorý sa vypisuje do stdout. Ten môže obsahovať špeciálne sekvencie začínajúce znakom %,
 za ktoré sa dosadzujú ďalšie argumenty. Tj koľko máme špeciálnych sekvencií v reťazci, toľko máme ďalších argumentov funkcie fprint().
 
 formát špeciálnej sekvencie:
 ```c++  
%[flags][width][.prec][h|l|L]type
 ```
  to čo je v [] je voliteľné, | znamená alebo.
  
  sekvencia začína znakom % a končí znakom, ktorý určuje typ argumentu, ktorý sa má vypísať (= jediné 2 povinné časti), napr. %i vypisuje
  celé číslo so znamienkom.
  
  
    | type|  význam |   
    |  ------  | ------    |
    |  d, i|  celé číslo so znamienkom | 
    |  u |  celé číslo bez znamienka |  
    | o| celé číslo v osmičkovej sústave |      
    | x, X|  číslo v šestnástkovej sústave. ABCDEF sa budú vypisovať ako malé s x, ako veľké s X|   
      | p|  ukazovateľ|  
      |f|  racionálne číslo (float, double) bez exponentu | 
      | a, A | šestnástkové racionálne Číslo| 
      | e, E | racionálne číslo s exponentom, implicitne jedna pozícia pred desatinnou bodkou, šesť za ňou. Exponent e alebo E|  
    | g, G|  racionálne číslo s exponentom alebo  bez neho. Neobsahuje desatinnú bodku ak nemá desatinnú časť | 
    |c|  jeden znak | 
    |s|  reťazec| 
  
  podrobnejšie http://www.cplusplus.com/reference/cstdio/printf/
  
   ```c++  
  #include <stdio.h>
  int main ()
  {
      const char *string = "bzz";
      const int year = 2019;
  
      printf("%i %u %o %x %X %f %e %G\n", -5, -5, 200, 200, 200, 10.0,
             10.0, 10.0);
      printf("%s %i\n", string, year);
  
      return 0;
  }
 ```  
 
 položky width a prec určujú dĺžku výstupu. width = minimálny počet znakov výstupu, prec = maxinmálny počet znakov pre reťazce, minimum
 zobrazených znakov pre celé čísla, počet miest za desatinnou čiarkou ofd racionálne čísla.
 
 hodnoty width:
 
    |  n |  vypíše najmenej n znakov doplnených medzerami |  
    | 0n| vypíše sa najmenej n znakov doplnených nulami |      
    | *|  vypíše sa najmenej n znakov, kde n je ďalší argument funkcie printf()|  
    
 hodnoty prec:
 
    |  .0 |  e,E,f: nezobrazí sa desatinná bodka; d,i,o,u,x: nastaví štandardné hodnoty|  
    | .n| d,i,o,u,x: min počet číslic, e.E.f: počet desatinných číslic, g,G: počet platných miest, s: max počet znakov |      
    | .*|  ako presnosť sa použije nasledujúci parameter funkcie printf()|  
    
    
      
   ```c++  
      #include <stdio.h>
       
      int main(void)
      {
         printf("%i %u %o %x %X %f %e %G\n", -5, -5, 200, 200, 200, 10.0, 10.0, 10.0);
     
     
         printf("%06i %06u %06x %6x %06f %06E %06G\n\n", -5, -5, 200, 200, 10.0, 10.0, 10.0);
     
         printf("%*s %1s %6s %%06.2G\n", 10, "%*i", "%06.2f", "%06.0E");
     
         printf("%*i %06.2f %06.0E %06.2G\n", 10, -5, 10.0 / 3, 10.0 / 3, 10.0 / 3);
         
         printf("\n%.8s %0*.*f\n", "Posledni vystup:", 10, 4, 10.0 / 3);
         
          return 0;
      }
   ```
       
       
  hodnoty flags:
  
     | - |  zarovnanie zlava|  
      | +| pri čísle sa vždy zobrazí znamieko |      
      | medzera|  pri kladných číslach bude namiesto znamienka + medzera|  
      
  Znaky h l a L označujú typ čísla. Znak h typ short, l dlouhé celé číslo, L long double.
        ```c++ 
          long int x = -25l; 
          long double y = 25.0L;
          printf("%10s <%+5i> <% 5ld> <%x>\n", "Cisla:", 25, x, -25);
       ```
#### scanf()
používa sa na formátovaný štandardný vstup
```c++ 
int scanf (const char *format [, address, ...]);
```
vracia počet načítaných a uložených položiek alebo EOF pri pokuse čítať zo zatvoreného vstupu.

prvý argument = špeciálna sekvencia, ktorá určuje, čo sa má načítať.

formát sekvencie:
```c++ 
%[*][width][h|l|L]type
```

význam položiek sekvencie:

    | * |  preskočí popísaný vstup (načíta, ale nikam nezapíše)|  
    | width | maximálny počet vstupných znakov |      
    | h l L |  modifikácia typu ako v printf()| 
    | type | typ konverzie|   
    
možné typy konverzií:

      | type|  význam |   
        |  ------  | ------    |
        |  d|  celé číslo v desiatkovej sústave | 
        |  u |  celé číslo bez znamienka |  
        | o| celé číslo v osmičkovej sústave |      
        | x| celé číslo v šestnástkovej sústave|  
          | i|  celé číslo defaultne desiatkové, prefix 0 znamená osmičkové a 0x šestnástkové|  
          | n| počet doteraz preČítaných znakov v aktuálnom volaní scanf()| 
          | e, f, g|  racionálne čísla typu float, možno modifikovať pomocou l a L|  
          |s|  reťazec, úvodné biele znaky sa preskočia, na konci sa pridá znak '\0'| 
          | c| znak, ak je zadaná šírka, tak sa číta reťazec bez preskočenia bielych znakov|  
    

```c++ 
int x;
scanf("%i", &x);
```

alebo

```c++ 
int x;
int *ui = &x;  
scanf("%i", ui);
```


```c++ 
        int x = -1;

        printf("Zadaj cislo napr. 10 0x0a alebo 012: ");
        scanf("%i", &x);
        printf("Zadal jsi cislo %i\n", x);
        return 0;
```




## Prístup k súborom
Knižnica <cstdio> deklaruje prístup k súborom pomocou súborového prúdu. K súborovému prúdu sa pristupuje pomocou štruktúry FILE. Súborové
prúdy majú obvykle vyrovnávaciu pamäť (buffer) - pri otvorení sa z diku načíta niekoľko stoviek bajtov do bufferu a keď chceme niečo prečítať, tak
čítame rovno z buffera. Keď sa dostaneme na koniec buffera, tak sa doň z disku načíta ďalší veľký kus pamäte. Pri zápise sa sapisované dáta
nezapisujú znak po znaku, ale tiež sa najprv zhromaždia v bufferi - všetko sa zapíše naraz, keď sa naplní, pretože tak je to rýchlejšie.

### Textový a binárny prístup
Prístup k súborom delíme na textový a binárny. Textový súbor = súbor, v ktorom je uložený iba text. Niektoré súborové operácie
 sa na textovom súbore dajú zjednodušiť a sú potom kompatibilné medzi rôznymi OS.
 
 Problém spočíva, okrem kódovania, v znaku '\n'. Vo Windowse je koniec riadku daný dvomi bajtami 13 a 10, v Linuxe jedným 10 a v iOS jedným ale 13. 
 Pri textovom prístupe k súboru môžeme načítať a zapisovať textové reťazce a nemusíme sa pritom starať o to, ako je znak '\n' interpretovaný.
 Nový riadok je vnútorne reprezentovaný znakom '\n' (dochádza k automatickej konverzii).
 
 Pri binárnom prístupe k súboru dáta zapisujeme/čítame bajt po bajte. Ak chceme zapísať textový súbor, musíme znak  '\n' zapísať podľa
 toho, na akom OS ho budeme chcieť čítať. Tj. pri binárnom prístupe máme väčšiu kontrolu nad spracovávanými dátami, ale práca s nimi môže
 byť o niečo náročnejšia.
 
 ## Limity
 
 V <cstdio> sú konštanty 
 
 FOPEN_MAX = limit pre počet simultánne otvorených súborových streamov
 
 FILENAME_MAX = limit pre dĺžku názvu súboru
 
 ## Otvorenie dátového prúdu
 Pomocou funkcie fopen():
 ```c++  
 FILE *fopen(const char *path, const char *mode);
 ```

fopen() vracia ukazateľ na štruktúru FILE. Ak sa súbor nepodarí otvoriť, vracia NULL. 

Prvý argument je názov súboru, druhý argument je textový reťazec, ktorý môže obsahovať nasledovné:

| reťazec |  význam |   pozícia v súbore |  
  |  ------  | ------    | ------    |
  |  r |  otvorí súbor pre čítanie| začiatok    |
  |  r+ |  otvorí súbor pre čítanie a zápis  |  začiatok   |
  | w | existujúci súbor oreže na nulovú dĺžku, inak vytvorí nový a otvorí stream pre zápis |  začiatok   |       
  | w+|  ako w ale stream otvorí aj pre čítanie|začiatok   |   
    | a|  otvorí súbor pre čítanie, ak neexistuje, tak ho vytvorí |  koniec   |  
    | a+|  otvorí súbor pre čítanie aj zápis, ak neexistuje, tak ho vytvorí | koniec   | 
    | t |  textový režim|  | 
| b|  binárny režim| | 

Vždy by sme mali zadať, či pristupujeme k súboru v textovom alebo binárnom móde, tj napr "rt", "rb" alebo "rwt". V Linuxe nie je
rozdiel medzi textovými a binárnymi súbormi, ale kvôli kompatibilite s inými OS je dobré
spôsob prístupu určiť aj v Linuxe. Ak orístup neurčíme, tak sa defaultne nastaví na textový režim.

 ```c++  
 FILE *myfile;
  if ((myfile = fopen("name.txt, "rt")) == NULL){
  printf("subor sa neda otvorit");
  exit(1);
  }
 ```
 
 ## Zatvorenie a vyprazdnenie dátového prúdu
 pomocou funkcie fclose()
  ```c++  
  int *fclose(FILE *stream);
  ```
  vracia 0 v prípade úspechu, inak EOF.
  
Dôvody na zatváranie súboru:
- počet simultánne otvorených súborov je obmedzený
- v prípade ukončenia programu pre volaním fclose() sa môže stať, že  zmeny v súbore prídeme
- keď otvoríme súbor pre zápis, tak OS zakáže ostatným programom do tohto súboru pristupovať (2 programy nemôžu naraz zapisovať do jedného súboru)

a pomocou funkcie fflush():
  ```c++  
  int fflush(FILE *stream);
  ```
  ak má stream hodnotu NULL, tak sa vyprázdnia všetky dátové streamy, ktoré sú v programe otvorené. vracia 0 v prípadne úspechu, inak EOF.
  
   ```c++  
 #include <stdio.h>
 #define FILENAME "myfile.txt"
 int main ()
 {
     FILE * pFile;
     if ((pFile = fopen (FILENAME,"w"))!=NULL)
     {
         printf("%s was succesfully opened", FILENAME);
         fclose (pFile);
     }
     return 0;
 }
   ```
   
   ## Zápis do txt súboru
   pomocou funkcie 
     ```c++ 
   int  fprintf(FILE *stream, const char *format, ...);
      ```
      = rovnaká funkcia ako printf(), iba má parameter navyše stream, do ktorého sa bude zapisovať (ak je ním stdout, tak <=> printf()).
      
 ```c++      
#include <stdio.h>
#include <cstring>

#define FILENAME "myfile.txt"
int main ()
{
        FILE *subor;
        char text[255];

        soubor = fopen(FILENAME, "a+"); /* soubor se otevre pro aktualizaci,
                                    neexistujici soubor se vytvori */
        do {
            fprintf("Zadejte slovo, ktere chcete zapsat do souboru\n"
                  "a stisknete ENTER, nebo \"q\" pro ukonceni: ", stdout);
            scanf("%254s", text);
            if (!strcmp(text, "q"))
                break;
            printf("Zapisuji >> %s <<\n", text);
            fprintf(subor, ">> %s <<\n", text);
        } while (1);

        fclose(subor);

        return 0;

}
```



## Čítanie z txt súboru
 ```c++ 
int fscanf(FILE *stream, const char *format, ...);
 ```
=rovnaká funkcia ako scanf(), iba má argument navyše - stream, ktorým určujeme, odkiaľ chceme čítať


   ```c++ 
#include <stdio.h>

int main ()
{
  char str [80];
  float f;
  FILE * pFile;

  pFile = fopen ("myfile.txt","w+");
  fprintf (pFile, "%f %s", 3.1416, "PI");
  rewind (pFile);
  fscanf (pFile, "%f", &f);
  fscanf (pFile, "%s", str);
  fclose (pFile);
  printf ("I have read: %f and %s \n",f,str);
  return 0;
}
 ```

ÚLOHA: napíšte program, ktorý načíta zo súboru myfile.txt 10 hexadecimálnych čísel a do iného súboru zapíše ich maximum,
 minimum, priemer a medián v desiatkovej sústave s presnosťou na 4 desatinné miesta v tvare:

   ```c++ 
maximum : ...
minimum : ...
priemer : ...
median : ...
 ```

