
Student sa zapisal na n workshopov a chce sa 
zucastnit maximalneho poctu workshopov tak, aby sa ziadne dva neprekryvali.

## Implementujte 2 struktury:

1. strukt Workshop obsahujucu nasledujuce cleny:
    - cas startu workshopu
    - cas trvania workshopu
    - cas konca workshopu
2. struct Available_Workshops obsahujucu nasledujuce cleny:
    - integer n (pocet workshopov, na ktore sa student zapisal)
    - pole typu Workshop velkosti n

## Implementujre 2 funkcie:

1. Available_Workshops* initialize(int start_time[], int duration[], int n)
    - Vytvori objekt typu Available_Workshops a inicializuje jeho prvky pomocou prvkov v parametroch start_time[] a duration[] (oba velkosti n). start_time[i] a duration[i] predstavuju cas startu a cas trvania iteho workshopu. Tato funkcia musi vratit ukazatel na objekt typu Available_Workshops
2. int CalculateMaxWorkshops(Available_Workshops* ptr)
    - Vrati maximalny pocet workshopov, ktorych sa student moze zucastnit - bez prekryvania. Nasledujuci workshop nemoze byt navstiveny, kym sa predosly neskonci.

poznamka: pole neznamej velkosti n mozno deklarovat takto:
```c++  
DataType* arrayName = new DataType[n];
```
## Format vstupu:

Vstup je za vas spracovany kodom nizsie, vasou ulohou je iba napisat funkcie tak, aby splnali zadanu specifikaciu.

## Obmedzenia:

1 <= N <= 10^5

0 <= start_time_i <= 10^3

0 <= duration_i <= 10^3

## Format vystupu:
Vystup je za vas spracovany.

Vasa funkcia initialize musi vratit ukazatek na objekt typu Available_Workshops.
Vasa funkcia CalculateMaxWorkshops musi vratit maximalny pocet neprekrzvajucich sa workshopov, ktorych sa student moze zucastnit.

## Vzorovy vstup:
```c++
6
1 3 0 5 5 8
1 1 6 2 4 1
```

## Vzorovy vystup:

CalculateMaxWorkshops by mala vratit 4.

## Vysvetlenie

Prvy riadok obsahuje n - pocet workshopov.

Druhy riadok obsahuje n medzerou oddelenych integerov, kde ity integer predstavuje cas zaciatku iteho workshopu.

Treti riadok obsahuje n medzerou oddelenuch integerov, kde ity integer predstavuje dobu trvania iteho workshopu.

Student sa moze zucastnit bez prekryvania workshopov 0, 1, 3 a 5, takze CalculateMaxWorkshops vrati 4.



    
```c++  
#include <bits/stdc++.h>

using namespace std;


//Definujte structs Workshops a Available_Workshops.
//Implementujte funkcie initialize a CalculateMaxWorkshops

int main(int argc, char *argv[]) {
    int n; // pocet workshopov
    cin >> n;

    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}


```
