
# Polymorfizmus

znamená využívanie základnej vlastnosti dedničnosti triedy: že ukazovateľ na odvodenú triedu je kompatibilný
s ukazovateľom na základnú triedu.

```c++ 
// pointers to base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
};

class Rectangle: public Polygon {
  public:
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    int area()
      { return width*height/2; }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;
}
```




Vo funkcii main deklarujeme dva ukazovatele na Polygon (pomenované ppoly1 a ppoly2). 
Týmto sú priradené adresy rect a trgl, ktoré sú objekty typu Rectangle a Triangle. 
Takéto priradenia sú platné, pretože Rectangle a Triangle sú triedy odvodené od Polygon.



Dereferencovanie ppoly1 a ppoly2 (pomocou * ppoly1 a * ppoly2) je platné a umožňuje prístup 
k členom objektov, na ktoré ukazujú. Napríklad, nasledujúce dva príkazy by boli v predchádzajúcom 
príklade ekvivalentné:
```c++
ppoly1->set_values (4,5);
rect.set_values (4,5);
```


Ale pretože typ ppoly1 a ppoly2 je pointer na Polygon (a nie ukazovateľ na Rectangle
 ani ukazovateľ na Triangle), je možné pristupovať len k členom zdedeným z Polygon, 
 a nie k členom odvodených tried Rectangle a Triangle. Preto vyššie uvedený program 
 pristupuje k členom area() oboch objektov priamo pomocou rect a trgl, namiesto pomocou ukazovateľov; 
 ukazovatele na základnú triedu nemôžu pristupovať k členom area().

Členská funkcia area() by mohla byť dostupná pomocou ukazovateľov na Polygon,
 ak by bola funkcia area() členom triedy Polygon namiesto členom od nej odvodených tried. Problémom je, že Rectangle a Triangle
  implementujú rôzne verzie funkcie area(), a preto neexistuje jedna spoločná verzia, 
  ktorá by mohla byť implementovaná v základnej triede.
  
  ## Virtuálne členy
  
  Virtuálny člen je členská funkcia, ktorú je možné predefinovať v odvodenej triede a 
  súčasne je možné ju volať zo základnej triedy. Virtuálnu funkciu vytvoríme tak
   že pred jej deklaráciu napíšeme kľúčové slovo virtual:
   
   
   ```c++
   // virtual members
   #include <iostream>
   using namespace std;
   
   class Polygon {
     protected:
       int width, height;
     public:
       void set_values (int a, int b)
         { width=a; height=b; }
       virtual int area ()
         { return 0; }
   };
   
   class Rectangle: public Polygon {
     public:
       int area ()
         { return width * height; }
   };
   
   class Triangle: public Polygon {
     public:
       int area ()
         { return (width * height / 2); }
   };
   
   int main () {
     Rectangle rect;
     Triangle trgl;
     Polygon poly;
     Polygon * ppoly1 = &rect;
     Polygon * ppoly2 = &trgl;
     Polygon * ppoly3 = &poly;
     ppoly1->set_values (4,5);
     ppoly2->set_values (4,5);
     ppoly3->set_values (4,5);
     cout << ppoly1->area() << '\n';
     cout << ppoly2->area() << '\n';
     cout << ppoly3->area() << '\n';
     return 0;
   }
```

V tomto príklade majú všetky tri triedy (Polygon, Rectangle a Triangle)
 rovnaké členy: width, height a funkcie set_values ​​a area.


Členská funkcia area() bola deklarovaná v základnej triede ako virtuálna, 
pretože neskôr bola definovaná v každej odvodenej triede. Nevirtuálne 
členy môžu byť tiež predefinované v odvodených triedach, ale nemožno na ne pristupovať prostredníctvom
 odkazu na základnú triedu: tj ak v príklade odstránime virtual z deklarácie area(),
  všetky tri volania area() by sa vrátili nulu, 
  pretože vo všetkých prípadoch by sa zavolala verzia základnej triedy.


Preto to, čo v podstate kľúcové slovo virtuál robí je, že umožňuje členovi odvodenej triedy s 
rovnakým názvom ako názov člena v základnej triede, aby bol zavolaný z ukazovateľa. 
 
 
 
 Trieda, ktorá deklaruje alebo zdedí virtuálnu funkciu, sa nazýva polymorfná trieda.
 
 
 Všimnite si, že napriek virtuálnosti jedného z jeho členov je Polygon bežná trieda. Bola z nej 
 vytvorená inštancia poly, s vlastnou definíciou členskej funkcie area, ktorá vždy vráti 0.
 
 
 
 ## Abstraktné základné triedy
 
 Abstraktné základné triedy sú niečo podobné ako trieda Polygon v predchádzajúcom príklade. 
 Sú to triedy, ktoré sa dajú použiť len ako základné triedy, a teda majú povolené mať virtuálne
  členské funkcie bez definície (známe ako čisto virtuálne funkcie). Syntax nahrádza ich 
  definíciu pomocou =0 (znamienko rovnosti a nula):
 
 ```c++
// abstract class CPolygon
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area () =0;
};
```


Všimnite si, že funkcia area() nemá definíciu; bola nahradená = 0, čo z nej robí čisto virtuálnu funkciu. 
Triedy, ktoré obsahujú aspoň jednu čisto virtuálnu funkciu, sú známe ako abstraktné základné triedy.


Od abstraktných základné tried nemožno vytvoriť inštancie objektov. 
Preto táto posledná abstraktná verzia základnej triedy Polygon by nemohla byť použitá na 
deklarovanie objektov ako:

```c++
Polygon mypolygon;   // not working if Polygon is abstract base class 
```


Abstraktná základná trieda však nie je zbytočná. Používa sa na tvorbu ukazovateľov, pričom
 umožňuje využitie všetkých jeho polymorfných vlastností. 
 Napríklad by boli platné nasledujúce deklarácie ukazovateľov:
 ```c++
 Polygon * ppoly1;
 Polygon * ppoly2;
```


ktoré by mohli byť dereferencované, keď by ukazovali na objekty odvodených (neabstraktných) tried.
 
príklad:

 ```c++
/// abstract base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (void) =0;
};

class Rectangle: public Polygon {
  public:
    int area (void)
      { return (width * height); }
};

class Triangle: public Polygon {
  public:
    int area (void)
      { return (width * height / 2); }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  return 0;
}
```



V tomto príklade sa objekty s rôznymi ale súvisiacimi typmi odkazujú na jeden typ ukazovateľa
 (Polygon *) a zakaždým sa volá správna členská funkcia, pretože sú virtuálne. 
 Toto môže byť za určitých okolností užitočné, napr. je možné, aby člen abstraktnej 
 základnej triedy Polygon použil špeciálny ukazovateľ this na prístup k správnym virtuálnym členom,
  hoci samotný Polygon nemá pre danú funkciu žiadnu implementáciu:
  
  
  ```c++
  // pure virtual members can be called
  // from the abstract base class
  #include <iostream>
  using namespace std;
  
  class Polygon {
    protected:
      int width, height;
    public:
      void set_values (int a, int b)
        { width=a; height=b; }
      virtual int area() =0;
      void printarea()
        { cout << this->area() << '\n'; }
  };
  
  class Rectangle: public Polygon {
    public:
      int area (void)
        { return (width * height); }
  };
  
  class Triangle: public Polygon {
    public:
      int area (void)
        { return (width * height / 2); }
  };
  
  int main () {
    Rectangle rect;
    Triangle trgl;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
    ppoly1->printarea();
    ppoly2->printarea();
    return 0;
  }
```


# Výnimky


Výnimky poskytujú spôsob, ako reagovať na mimoriadne okolnosti (chyby počas behu)
 v programoch prenosom kontroly na špeciálne funkcie nazývané handlery.



Na chytanie výnimiek je časť kódu umiestnená pod špeciálnu kontrolu. 
Výnimky v časti kódu zachytávame tak, že túto časť umiestňujeme do try bloku. Ak v rámci tohto bloku 
vzniknú výnimočné okolnosti, vyhodí sa výnimka, ktorá prevedie kontrolu na handler výnimky. 
Ak nie je vyhodená žiadna výnimka, kód pokračuje normálne a všetky handlere sa ignorujú.


Výnimka sa vyhodí pomocou kľúčového slova throw z vnútra try bloku.
 Handler výnimky sa deklaruje kľúčovým slovom catch, ktoré musí byť umiestnené hneď po bloku try:
 
```c++  
// exceptions
#include <iostream>
using namespace std;

int main () {
  try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }
  return 0;
}
```

Kód ktorý testujeme na výnimku je vloŽený do try bloku. V tomto príklade kód jednoducho vyhadzuje výnimku:


 ```c++  
throw 20;
```

Výraz throw akceptuje jeden parameter 
(v tomto prípade integer hodnotu 20), ktorý sa odovzdáva ako argument handleru výnimiky.

Handler výnimky sa deklaruje kľúčovým slovom catch hneď po uzatváracej zátvorke try bloku. 
Syntax pre catch je podobná bežnej funkcii s jedným parametrom. 
Typ tohto parametra je veľmi dôležitý, pretože typ argumentu, ktorý prešiel výrazom catch, 
je kontrolovaný proti nemu a len v prípade, že sa zhoduje, je výnimka zachytená.

Handlery môžeme reťaziť, každý s iným typom parametrov. 
Spustí sa iba ten handler, ktorého typ argumentu zodpovedá typu vyhodenej výnimky.

Ak sa ako parameter handleru použijú tri bodky (...), tak takýto handler zachytí akúkoľvek výnimku, 
bez ohľadu na jej typ. Môže sa použiť ako handler zachytávajúci všetky ostatné výnimky, ktoré neboli
zachytené inými handlermi:
 ```c++  
try {
  // code here
}
catch (int param) { cout << "int exception"; }
catch (char param) { cout << "char exception"; }
catch (...) { cout << "default exception"; }
 ```
 V tomto prípade by posledný handler zachytil akúkoľvek výnimku, ktorá nie je ani int, ani char.
 
 
 Po vykonaní výnimky sa program obnoví po bloku try-catch.
 
 Try-catch bloky je možné do seba vnorovať - vnútorný catch blok môže preposlať výnimku vonkajšiemu. To je možné
 urobiť pomocou výrazu throw nasledujúcim spôsobom:
 
  ```c++  
try {
  try {
      // code here
  }
  catch (int n) {
      throw;
  }
}
catch (...) {
  cout << "Exception occurred";
}
  ```
 
 ### Štandardné výnimky
 
 
 Štandardná knižnica C ++ poskytuje základnú triedu špeciálne určenú na deklarovanie objektov, 
 ktoré sa majú vyhadzovať ako výnimky. Volá sa std::exception a je definovaná v hlavičke <exception>. 
 
 Táto trieda má virtuálnu členskú funkciu, ktorá sa nazýva what, a ktorá vracia postupnosť znakov 
 ukončených nullom (typu char *), a ktorá môže byť prepísaná v odvodených triedach tak, 
 aby obsahovala popis výnimky.
 
```c++  
// using standard exceptions
#include <iostream>
#include <exception>
using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

int main () {
  try
  {
    throw myex;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }
  return 0;
}
```

V príklade používame handler, ktorý zachytáva výnimky pomocou odkazu (ampersand & po type),
 a preto zachytáva aj triedy odvodené od exception, napríklad objekt myex typu myexception.

Všetky výnimky, ktoré vyhdzujú komponenty štandardnej knižnice C++ sú výnimky 
odvodené z triedy exception. Ich zoznam je možné nájsť na http://www.cplusplus.com/reference/exception/exception/

Typický príklad, kde je potrebné kontrolovať štandardné výnimky, je pri prideľovaní pamäte:


 
```c++  
// bad_alloc standard exception
#include <iostream>
#include <exception>
using namespace std;

int main () {
  try
  {
    int* myarray= new int[1000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}

```


Výnimka, ktorú môže v tomto príklade handler zachytiť je bad_alloc
(bad_alloc je odvodený zo základnej triedy exception, handler zachytáva výnimku odkazom -> zachytáva všetky súvisiace triedy)

ÚLOHA: doplňte výnimky do kódu programu z cvičenia 1
 
 
