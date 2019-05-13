
# Lambda výrazy (v C++11)

Základnou myšlienkou lambda výrazu v C++ je, že dokáže elegantne nahradiť
jednoduché funkcie - obvykle operácie ako porovnanie prvkov, určitá matematická 
operácia etc.

lambda výraz tvoríme pomocou syntaxe:
```c++
[](input_paramter_declaration)->returned_type {body_of_the_lambda_expression}(parameters)
```
napríklad:
```c++
[](int a,int b)->int{return a+b;}(2,4);
```
```c++
[](int a)->int{return 2*a;}(10);
```

tj. hranaté zátvorky ostanú vždy bez zmeny. 
Nasleduje guľatá zátvorka, v ktorej sú deklarované vstupné hodnoty 
pre lambda výraz (v tomto příklade 2 int hodnoty). Nasleduje šípka
 a deklarácia typu návratové hodnoty (int). V zložených zátvorkach 
 je telo lambda výrazu (niečo ako telo funkcie/metódy). 
 Na konci v guľatých zátvorkach sú vždy vstupné hodnoty. 
 Tento lambda výraz má teda hodnotu 6.


Zasadiť do výrazu ho môžme napr takto:
```c++
int result = [](int a,int b)->int{return a+b;}(2,4);
std::cout << result << std::endl;
```

Ak chceme lmbda výraz používať opakovane, môžeme naň vytvoriť ukazateľ a ten opakovane
volať:
```c++
auto func = [](int a,int b)->int{return a+b;}(2,4);
std::cout<<func(2,3)<<std::endl;
```

#Využitie
tam, kde sme nútení vytvárať funkcie/funkčné objekty:
```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i,int j){
  return (i<j);
}

int main(){
  int n=10;
  vector<int> v(n);
  // inicializace
  for(int i=n, j=0; i>=0; i--, j++)
    v[j]=i;
  // vypis
  for(int i=0; i<n; i++)
    cout << v[i] << " ";
  cout << endl;

  //razeni
  sort(v.begin(), v.end(), compare);

  for(int i=0; i<n; i++)
    cout << v[i] << " ";
  cout << endl;

  return(0);
}
```
funkciu compare môžeme nahradiť vložením lambda výrazu priamo do príkazu sort:


```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n=10;
  vector<int> v(n);
  // inicializace
  for(int i=n, j=0; i>=0; i--, j++)
    v[j]=i;
  // vypis
  for(int i=0; i<n; i++)
    cout << v[i] << " ";
  cout << endl;

  //razeni
  sort(v.begin(), v.end(), [](int i,int j)->bool{return (i<j);});

  for(int i=0; i<n; i++)
    cout << v[i] << " ";
  cout << endl;

  return(0);
}
```
sort vždy vyberie dvojice hodnôt z vektoru a dosadí ich do lambda výrazu.

ďalšie príklady:

aplikácia lambda výrazu na algoritmus generate (naplnenie vektoru číslami):
```c++
vector<int> vec(10);
int index = 0;

generate(vec.begin(), vec.end(), [&index]{return ++index;});
```
for_each (vypísanie):
```c++
vector<int> vec(10);
int index = 0;

for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});
```
count_if (vracia počet prvkov, ktoré spĺňajú zadané kritérium)
for_each (vypísanie):
```c++
vector<int> vec = {1,2,3,4,5,6,7,8,9};
int value = 3;
int cnt = count_if(vec.cbegin(),vec.cend(), [=](int i){return i>value;});

std::cout << cnt << " values > " << value << "found" << endl;
```
Lambda výraz s prázdnymi hranatými zátvorkami môže pristupovať iba na svoje
lokálne premenné.


[=] znamená že value predávame hodnotou.

prehľad spôsobov predávania hodnôt:

[=] – prevzatie hodnotou
[&] – prevzatie odkazom
[&x] – prevzatie x odkazom
[x] – prevzatie x hodnotou
[=, &x, &y] – prevzatie hodnotou všetkých okrem x a y, které sú odkazom
[&, x] – prevzatie všetkých odkazom okrem x, ktoré je hodnotou
[&x, &x] – nekorektné použitie, nie je validné opakovať hodnotu


# Raw stringy
= stringy, ktoré nespracúvajú "escapovacie" znaky ako \n, \t, \...

syntax pre raw string: R"(string)"
príklad:
```c++
#include <iostream> 
  
int main() 
{ 
    // a normal string 
    string string1 = "bla.\nblabla.\nbla.\n" ;  
  
    // a raw string 
    string string2 = R"(bla.\nblabla.\nbla.\n)";  
  
    std::cout << string1 << std::endl; 
  
    std::cout << string2 << std::endl; 
      
    return 0; 
} 
```

# Regulárne výrazy

uľahčujú prácu s textom/vstupom všeobecne. Možno pomocou nich kontrolovať, či má daný
vstup požadovaný formát (či ide o číslo, či slovo má konkrétnu predponu etc.). Okrem toho
sa pomocou regulárnych výrazov dá efektívne modifikovať text.

PRÍKLAD:
predpokladajme, že potrebujeme skontrolovať, či uživateľ zadal na vstup celé
číslo: 0012, 12, +0012 alebo napr. -0012, -12, -012.

1.Najprv potrebujeme vytvoriť regulárny výraz, ktorý popisuje celé číslo.
Jedna číslica je podľa štandardu ECMAScript definovaná výrazom [:digit:] alebo
[:d:]. Regulárny výraz, ktorý by zodpovedal jednej ľubovoľnej číslici bude:
```c++
regex cislica("[[:digit:]]");
```

Tento výraz zodpovedá hodnotám 0..9. Ak by mal zodpovedať viacero čísliciam (12,
123 ...) musel by byť upravený takto:

```c++
regex cislo("[[:digit:]]+");
```

Znamienko + v tomto kontexte znamená, že sa pred týmto symbolom definovaný 
výraz môže ľubovoľnekrát opakovaŤ.


2.Ďalej potrebujeme vyriešiť problém so znamienkom -, ktoré sa môže pred číslom
nachádzať. Ak je nutné označiť určitú časť výrazu ako nepovinnú, použije sa
špeciálny symbol ? :

```c++
regex integer("-?[[:digit:]]+");
```

3.Posledným krokom je umožniť, aby sa pred zapísaným číslom mohlo nachádzať
znamienko +. To má v regulárnych výrazoch špeciálny význam opakovanie výrazu, a preto ho nie je
možné normálne zapísať. Aby sme znegovali špeciálny význam, je nutné pred + vložiť
spätné lomítko. V bežnom regulárno výraze teda symbol + vo význame znamienka píšeme
ako \+. V c++  má však spätné lomítko špeciálny význam (\t je tabulátor, \n je 
skok na nový riadok etc.), preto je nutné najprv pomocou spätného lomítka znegovať význam
spätného lomítla. Výsledok bude nasledovný:


```c++
regex r("\\+?[[:digit:]]+");
```

Ak  dáme celý problém dokopy, výsledný výraz umožňujúci kladné aj záporné
znamienko bude vyzerať takto:

```c++
regex r("(\\+|-)?[[:digit:]]+"); 
```
Ak má byť symbol ? aplikovaný na dlhší výraz, musí byť tento výraz v zátvorke, inak
sa aplikuje iba na posledný prvok výrazu. Ak sa na určitej ozícii vo výraze nachádzajú
potencionálne 2 různe prvky, oddelia sa v regulárnom výraze symbolom alebo |.

celý príklad:

```c++
#include <iostream>
#include <regex>
#include <string>

int main(){
  std::string input;
  std::regex integer("(\\+|-)?[[:digit:]]+");

  std::cout << "Gimme number:";
  std::cin >> input;

  if(regex_match(input, integer))
    std::cout << "it's integer" << std::endl;
  else
    std::cout << "it's not integer" << std::endl;

  return 0;
}
```

Na samotné porovnanie vstupu a regulárneho výrazu sme použili príkaz regex_match().



Ďalej si môžeme rozobrať regulárny výraz umožňujúci detekciu reálneho čísla"
```c++
regex rr("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
```

Prvá časť výrazu 
```c++
(\\+|-)?[[:digit:]]+) 
```
je totožná s detekciou celého čísla. Pridaná bola časť 
```c++
(\\.(([[:digit:]]+)?))
```
Symbol ? za celým týmto výrazom hovorí, že celá táto časť je voliteľná.
Nová časŤ sa začína desatinnou bodkou. Bodka . má v regulárnych výrazoch tiež
špeciálny význam, a preto musí byť jej význam negovaný lomítkom (ktoré je tiež negované
ako v predošlom príklade). Za touto bodkou sa môžu nepovinne nachádzať ďalšie číslice.


Ak by sme chceli akceptovať čísla vo vedeckom formáte (-1.23e+06, 0.245e10, 1E5), je možné
použiť výraz:

```c++
regex rr("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
```

ÚLOHA:

majme nasledujúci text plný medzier:
```c++
  Lukas rychlo beha 
   C++ ma novu verziu 
  Vonku padaju kvapky 
   Slnko vecer svieti 
  David tu dnes nie je
```

Napíšte program, ktorý odstráni medzery na začiatku riadkov.











