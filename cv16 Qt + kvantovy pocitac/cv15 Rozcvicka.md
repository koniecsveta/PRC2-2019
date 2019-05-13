Maria zostrojila stroj casu a chce ho otestovat. Chce navstivit Rusko v “Den programatorov” ( 256. den roku, https://en.wikipedia.org/wiki/Day_of_the_Programmer), a to v rozpati rokov 1700 az 2700 vratane.

Od 1700 do 1917 v Rusku pouzivali juliansky kalendar (https://en.wikipedia.org/wiki/Julian_calendar) a od 1919 pouzivali gregoriansky kalendar (https://en.wikipedia.org/wiki/Gregorian_calendar). Prechod z julianskeho na gregoriansky kalendar sa uskutocnil v roku 1918 tak, ze nasledujuci den po 31. januari bol 14. februar. Tj. v 1918 bol v Rusku 14. februar 32. dnom roku.

V oboch systemoch je februar jediny mesiac s premenlivym poctom dni - ma 29 dni v prestupnom roku a 28 dni v inych rokoch. V julianskom kalendari su prechodne roky delitelne 4. V gregorianskom kalendari je prechodny rok bud 
- delitelny 400 alebo
- delitelny 4 a zaroven nedelitelny 100.

 Ak mame rok r, najdite datum 256. dna roku r podla oficialneho kalendara Ruska v roku r.
Nasledne ho vypiste vo formate dd.mm.yyyy, kde yy je dvojciferny den, mm dvojciferny mesiac a yyyy je r. 

Napriklad ak mame zadany rok r = 1984:
1984 je delitelny 4, takze ide o prechodny rok. 256. den prechodneho roku po 1918 je 12. september, takze odpoved je 12.09.1084.

## Popis funkcie

doplnte funkciu dayOfProgrammer, ktora ma vracat string repreyentujuci 256. den zadaneho roku.
Funkcia ma jeden vstupny parameter: int year.

## Obmedzenia

1700 <= r <= 2700

## Vzorovy vstup 0

2017

## Vzorovy vystup 0

13.09.2017

## Vysvetlenie

V roku r=2017 ma januar 31 dni, februar 28 dni, marec 31 dni, april 30 dni, maj 31 dni, jun 30 dni, jul 31 dni a august 31 dni. Ked spocitame sucet dni prvych 8 mesiacov, dostaneme 31 + 28 + 31 + 30 + 31 + 30+ 31 + 31 = 243. Den programatorov je 256. den, takze vzratame 256 - 243 = 13, z coho vypliva ze ide o 13.09.2017.

## Vzorovy vstup 1

2016

## Vzorovy vystup 1

12.09.2016

## Vysvetlenie

2016 je prechodny rok, takze februar ma 29 dni ale vsetky ostatne mesiace maju rovnakz pocet dni ako v 2017. Sucet prvzch 8 mesiacov je potom 244. Analogicky 256 - 244 = 12, cize den programatorov bol 12.09.2016.

## Vzorovy vstup 2

1800

## Vzorovy vystup 2

12.09.2016

## Vysvetlenie
1800 je prechodny, preto sviatok pripada na 12. septembra.




    
```c++  
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// doplnte funkciu dayOfProgrammer
string dayOfProgrammer(int year) {


}

int main()
{
    ofstream fout("output.txt",std::ofstream::out);

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


```
