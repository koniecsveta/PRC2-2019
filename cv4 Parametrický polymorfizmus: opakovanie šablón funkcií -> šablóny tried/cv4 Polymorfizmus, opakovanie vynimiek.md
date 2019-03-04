
# Polymorfizmus

Polymorfizmus v zmysle používania odvodených tried od základných tried:

![alt text](polymorphic-cats.gif)

Polymorfne macky by [James Halliday](https://substack.net)

```c++ 
#include <iostream>

using namespace std;


class Felid {
public:
    virtual void meow() = 0;
};

class Cat : public Felid {
public:
    void meow() { std::cout << "Meowing like a regular cat! meow!\n"; }
};

class Tiger : public Felid {
public:
    void meow() { std::cout << "Meowing like a tiger! MREOWWW!\n"; }
};

class Ocelot : public Felid {
public:
    void meow() { std::cout << "Meowing like an ocelot! mews!\n"; }
};


void do_meowing(Felid *cat) {
    cat->meow();
}

int main(int argc, char ** argv) {
    Cat cat;
    Tiger tiger;
    Ocelot ocelot;

    do_meowing(&cat);
    do_meowing(&tiger);
    do_meowing(&ocelot);
}
```



## Parametrický polymorfizmus (genericita): šablóny funkcií, šablóny tried

Polymorfizmus = schopnosť použiť rovnakú operáciu na argumenty rôznych typov. 
Parametrický polymorfizmus je forma polymorfizmu, v ktorom parametrizujeme 
typy, primitívne operácie atď. Parametrizovaná abstrakcia (typ, operácia...) môže byť potom 
konkretizovaná špecifikáciou parametrov.

C ++ podporuje parametrický polymorfizmus prostredníctvom jeho šablón.

Napríklad, bolo by pekné, keby sme mali jednu funkciu Max a potom ju mohli parametrizovať 
podľa typu argumentu. Deklarácia

```c++ 
template <typename T>
T Max(T a, T b) {
  return (b < a) ? a : b;
}
```

znamená, že deklarujeme rodinu funkcií nazvanú Max, parametrizovaných na type T. Každá možná inštancia parametra typu T zodpovedá inej špecializácii šablóny Max.




Ak chceme funkciu použiť na typ int, píšeme:


```c++ 
Max<int>(3, 5)
```

funkcia sa dá zavolať aj na typ string:
```c++ 
max(string("abc"), string("def"))
```

pretože vstavaná trieda string má operátor "<" preťažený na porovnanie reťazcov. Nie je však vhodné vyvolať Max na c stringy, pretože operátor "<" na nich nie je definovaný na porovnávanie reťazcov. 
Podobne, ak mám nasledujúci typ:
```c++ 
struct Book {
  string author;
  string title;
};
```


volanie Max na inštancie Book spôsobí chybu. Aby Book spolupracovali s funkciou Max, 
musíme definovať pre Book operátor "<":
```c++ 
bool operator<(const Book& b1, const Book& b2) { ... }
```




Z príkladu vidno, že parametrizovaná funkcia nefunguje pre úplne všetky typy.
 Jej telo vytvára obmedzenia - napríklad v prípade Max, telo obsahuje volanie operátora <, 
 a preto musí typový parameter T podporovať takýto operátor. 
 
 
 + lepšia stratégia:
 ```c++ 
 template <typename T>
 const T& Max(const T& a, const T& b) {
   return (b < a) ? a : b;
 }
```

CV: Napíšte parametrizovanú verziu funkcie abs, ktorá vracia absolútnu hodnotu zadaného vstupu. (absolútna hodnota nezáporného čísla je číslo samotné, a záporného čísla n je -n)
 

### šablóny tried

Myšlienka parametrického polymorfizmu sa nevzťahuje iba na funkcie, ale aj na triedy.
Pomocou šablón tried môžeme implementovať generické dátové štruktúry:


uvažujme spojový zoznam:
 ```c++ 
#ifndef __LIST_H__
#define __LIST_H__

typedef int ItemType;

struct Node {
  ItemType datum;
  Node *next;
};

class List {
public:
  // Default constructor, copy constructor, assignment oerator,
  // and destructor

  List();
  List(const List& L);
  List& operator=(const List& L);
  ~List();

    // Check if a List instance is empty.
  bool empty() const;


    // Get the number of items in a List instance.
  unsigned length() const;


  // Insert an item into a List instance.
  void insert(ItemType x);


  // Remove an item from a List instance.
  void remove(ItemType x);


  // Test if an item is a member of a List instance.
  bool search(ItemType x) const;


  // Print the members of a List instance.
  void print() const;

private:

  Node *head;

};

#endif
```

 Trieda je použiteľná len na vytváranie zoznamov integerov. 
 Nič nám ale nebráni meniť typ elementov na iné typy. 
 Naivný spôsob ako to urobiť, je modifikovať typedef typu ItemType (napr na typedef string ItemType;). 
 Dômyselnejšie riešenie je premeniť triedu na šablónu triedy. Pri samotnom použití zoznamu potom špecializujem šablónu na akúkoľvek voľbu ItemType.
 
 
 Zmena štruktúry Node 
 ```c++ 
 typedef int ItemType;
 
 struct Node {
   ItemType datum;
   Node *next;
 };
 ```
 na šablónu:  
 ```c++ 
template <typename ItemType>
struct Node {
  ItemType datum;
  Node *next; //Node<ItemType> *next;  // We don't have to do this (we can but its redundant)
};
``` 
Potom môžeme šablónu špecializovať napríklad takto:
```c++ 
Node<int> N;     // a node of int item
Node<string> M;  // a node of string item
N.datum = 3;
M.datum = "hello";
``` 
Zovšeobecnenie triedy List:
```c++ 
template <typename ItemType>
class List {
public:
  //
  // Default constructor, copy constructor, assignment oerator,
  // and destructor
  //

  List();
  List(const List& L); //List<ItemType>(const List<ItemType>& L);  // nor this
  List& operator=(const List& L);
  ~List();


  // Check if a List instance is empty.
  bool empty() const;

  // Get the number of items in a List instance.
  unsigned length() const;

  // Insert an item into a List instance.
  void insert(ItemType x);

  // Remove an item from a List instance.
  void remove(ItemType x);

  // Test if an item is a member of a List instance.
  bool search(ItemType x) const;

  // Print the members of a List instance.
  void print() const;

private:

  Node<ItemType> *head;

};
```

Hlava zoznamu už nie je typu Node, ale typu  Node<ItemType>, pretože node je teraz šablóna štruktúry a nie štruktúra.

Vovnútri triedy a štruktúry nemusíme používať Node<ItemType> namiesto Node, pretože sa predpokladá, že
šablóna Node už bola špecializovaná. 

#### implementácia šablóny triedy

CV: Na implementáciu vyššie uvedenej triedy musíme definovať šablónu pre každú členskú funkciu


TIP 1: Vo vnútri List<ItemType> sa predpokladá, že šablóna je špecifikovaná, tj. výskyt 
List ako argumentu kopírovacieho konštruktora nepotrebuje kvantifikáciu (explicitná
kvantifikácia je validná ale redundantná).
```c++
template <typename ItemType>
List<ItemType>::List(const List& L) {
  head = duplicateList(L.head);
}
```

TIP 2: Mimo scope šablóny List<ItemType> musíme názov triedy List korektne kvantifikovať, tj. aj
výskyt List v návratovom type priraďovacieho operátora: 
```c++
template <typename ItemType>
List<ItemType>& List<ItemType>::operator=(const List& L) {
  if (&L != this) {
    Node<ItemType> *H = duplicateList(L.head);
    deleteList(head);
    head = H;
  }
  return *this;
}
```

TIP 3: Originálna formulácia zoznamu predpokladá, že ItemType je int,
 a preto sú všetky argumenty ItemType predávané hodnotou. 
 To nie je optimálne pre veľký ItemType, napr. reťazec. 
 Preto by sa členské funkcie mali prepísať tak, 
 aby boli argumenty ItemType predávané odkazom a nie hodnotou.



tj.
```c++
template <typename ItemType>
class List {
public:
  ...
  void insert(const ItemType& x);
  ...
  void remove(const ItemType& x);
  ...
  bool search(const ItemType& x) const;
  ...
};
```
a
```c++
template <typename ItemType>
static Node<ItemType> *searchList(const ItemType& x, Node<ItemType> *head) {
...
}

template <typename ItemType>
void List<ItemType>::insert(const ItemType& x) {
...
}

template <typename ItemType>
bool List<ItemType>::search(const ItemType& x) const {
...
}

template <typename ItemType>
void List<ItemType>::remove(const ItemType& x) {
...
}
```