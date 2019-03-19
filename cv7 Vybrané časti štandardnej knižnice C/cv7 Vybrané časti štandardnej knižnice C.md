
#cmath
http://www.cplusplus.com/reference/cmath/

pomocou headera <cmath> deklarujemebežné matematické operácie:

## Trigonometrické funkcie
cos, sin, tan, acos, asin, atan, atan2

## Hyperbolické funkcie
cosh, sinh, tanh, acosh, asinh, atanh

## Exponenciálne a logaritmické funkcie
exp, frexp, ldexp, log, log10...

## Funkcie na mocnenie
pow, sqrt, cbrt, hypot

## Chybové a gamma funkcie
erf, erfc, tgamma, lgamma

## Zaokrúhľovacie funkcie
ceil, floor, fmod, trunc, round, lround, llrou nd, rint, lrint...

## Maximum, minimum, rozdiel
fdim, fmax, fmin

## iné
fabs, abs, fma

## klasifikačné funkcie
fpclassify, isfinite, isinf, isnan, isnormal, signbit

## porovnávacie funkcie
isgreater, isgreaterequal, isless, islessequal, islessgreater, isunordered

## konštanty
math_errhandling, INFINITY, NAN, HUGE_VAL, HUGE_VALF, HUGE_VALL

##typy
double_t, float_t

ÚLOHA:
napíšte funkciu, ktorá vypočíta hodnotu sin x pomocou prvých N členov
Maclaurinovej rady pre sin x (N bude parameter funkcie). Koľko
členov potrebujeme, aby sa riešenie zhodovalo so vstavanou funkciou sin?
Vypíšte hodnoty oboch funkcií vedľa seba pre hodnoty 0, pi/6, pi/4, pi/2, 2pi/3 a pi



# cstring
= header, ktorý definuje funkcie pre manipuláciu s cstringami a poliami

## Kopírovanie
memcpy, memmove, strcpy, strncpy

## Spájanie
strcat, strncat

## Porovnávanie
memcmp, strcmp, strcoll, strncmp, strxfrm

## Prehľadávanie
memchr, strchr, strcspn, strpbrk, ...


## a iné


Príklad použitia funkcií z tejto knižnice:
```c++
#include <stdio.h>
#include <string.h>

int main(void)
{
    char c, *ch, pole1[81], pole2[81];
    int x;

    printf("Zadaj 1 znak: ");
    scanf("%c", &c);
    printf("Zadaj prvy retazec: ");
    scanf("%80s", pole1);
    printf("Zadaj druhy retazec: ");
    scanf("%80s", pole2);

    x = strcmp(pole1, pole2);
    if (x < 0)
        printf("pole1 < pole2\n");
    else if (x == 0)
        printf("pole1 = pole2\n");
    else
        printf("pole1 > pole2\n");

    printf("Prvych %i znakov sa %s\n", 5,
           !strncmp(pole1, pole2, 5) ? "zhoduje" : "nezhoduje");
    printf("Prvych %u znakov pole1 je v pole2\n", strspn(pole1, pole2));

    ch = strchr(pole1, c);
    if (ch == NULL)
        printf("Znak %c sa v retazci \"%s\" nenachadza\n", c, pole1);
    else
        printf("pole1 od znaku %c: %s\n", c, ch);

    x = strlen(pole1);
    printf("Delzka prvehoi retezca: %u\n", x);
    strncat(pole1, pole2, sizeof(pole1) - x - 1);
    printf("Spojenie: %s\n", pole1);

    return 0;
}

```


# climits
  obsahuje konštanty rozsahu hodnôt celočíselných dátových 
  typov (v rôznych implementáciách prekladačov se líšia (inak by ani nemali význam). 
  Napr INT_MAX je pre 16bitové prekladače 32767 a 
  pre 32bitové 2147483647. 
  
  http://www.cplusplus.com/reference/climits/

 



# cstdlib
http://www.cplusplus.com/reference/cstdlib/

=header, ktorý definuje funkcie pre generovanie náhodných čísel,
aritmetiku s integermi, dynamickú správu pamäte, vyhľadávanie, triedenie, konvertovanie

## Konverzia reťazcov
atof, atoi, atol, atoll, strtod, strtof, strtol, strtold, strtoll, strtoul, strtoull

## Generovanie pseudonáhodných čísel
rend, srand

## Dynamická správa pamäte
calloc, free, malloc, realloc

## Prehľadávanie a triedenie
bsearch, qsort

## Aritmetika s integermi
abs, div, labs, ldiv, llabs, lldiv

...

## Konštanty 
NULL, RAND_MAX, EXIT_FAILURE, EXIT_SUCCESS...


### DOMÁCA ÚLOHA:
Uvažujme 3  rôzne generátory náhodných čísel

1. 'defaultnú' c++ rand() funkciu

2. IBM RANDU generátor, kt. postupnosť je popísaná ako

x_{n+1} = (65539 x_n) mod 2^(31)

kde a mod b = celočíselný zvyšok b po delení a, tj a%b


napríklad:

x0 = 1

x1 = (65539 * 1) mod 2^(31) = 65539

x2 = (65539 * 65539) mod 2^(31) = 4295360521 mod 2^31 = 393225

...

3. MVC (multiply wit carry) generátor 

x_{n+1} = (36969 x_n + c_n ) mod 2^(16)

c_{n+1} = floor( (36969 x_n + c_n)/2^(16) )

kde floor(x) je spodná celá časť x



každý generátor potrebuje "seed", tj počiatočnú hodnotu x_0, ktorú
obvykle získavame zo systémového času

- Aké najväčšie číslo je možné vygenerovať pomocou generátorov 1.-3.?

- Napíšte program, ktorý implementuje tieto generátory ako tri rôzne
triedy. Každá trieda by mala byť zdedená z nasledujúcej triedy RNG:


```c++
#include <time.h>
#include <cstdlib>
#include <cmath>

class RNG
{
protected:
//maximalne kladne cislo pseudo nahodnej postupnosti 
unsigned long Max;
public:
//rydzo virtualna funkcia, ktora vracia nasledujuci clen pseudo-nahodnej postupnosti
virtual unsigned long X()=0;
};
```
PRÍKLAD (implementácia generátoru 1)

```c++
class C_Rand : public RNG
        {
         public:
         C_Rand()
{
//nastavenie maximalnej hodnoty 
Max = RAND_MAX;
//nastavenie seedu zo systemoveho casu
srand(static_cast<unsigned>(time(NULL)));
}
//X() vracia nasledujúci integer postupnosti generatora 
unsigned long X() {return rand();} };

```

- Pomocou každého generátora vypíšte 100 náhodných čísel.








