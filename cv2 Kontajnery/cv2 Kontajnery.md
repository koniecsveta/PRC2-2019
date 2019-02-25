# Kontajnery

Kontajnery sú triedy, ktorých inštancie obsahujú dáta.
STL poskytuje rôzne kontajnery pre rôzne potreby.

#### 1. sekvenčné kontajnery
sú kontajnery u ktorých má zmysel hovoriť o poradí prvkov - tj jednotlyvých uložených údajov/objektov


  | kontajner  |  popis |  
  |  ------  | ------    |
  |  vector<T, A> |  vektor / súvislý úsek pamäte obsahujúci hodnoty typu T| 
  |  list<T, A>|  obojstranne zreťazený zoznam hodnôt typu T   | 
  | forward_list<T,A> | jednosmerne zreťazený zoznam hodnôt typu T  |        
  | deque<T, A> |  dvjojstranná frona prvkov typu T |

T- typ ukladaných hodnôt
A -typ alokátoru (=objekt, ktorý riadi pridelovanie pamäte prvkom kontajneru, pre každý kontajner je pre tento parameter definovaná implicitná hodnota, takže sa ním nemusíme zaoberať)



#### 2. asociatívne kontajnery 
obsahujú dvojice kľúč-hodnota, pričom hodnotu možno z kontajneru získať po zadaní kľúča.
Asociatívne kontajnery ďalej delíme na usporiadané a neusporiadané.

##### usporiadané asociatívne kontajnery:

  | kontajner  |  popis |  
  |  ------  | ------    |
  |  map<K, H, P, A> |  mapa, tj binárny vyhľadávací strom obsahujúci dvojice kľúč (typu K) - hodnota(typu H)| 
  |  multimap<K, H, P, A>| mapa, v ktorej sa môžu opakovať kľúče  | 
  | set<K, P, A>| množina, tj binárny vyhľadávací strom obsahujúci hodnoty typu K |        
  | multiset<K, P, A>|  množina, v ktorej sa môžu opakovať hodnoty|

K - typ kľúča
H - typ hodnoty
P - typ komparátoru (= objekt alebo funkcia s preťaženým operátorom volania funkcie, ktorá porovnáva dvojice kľúčov a podľa toho určuje umiestnenie v strome)
A - typ alokátoru (podobne ako v sekvenčných kontajneroch)

##### neusporiadané asociatívne kontajnery:

  | kontajner  |  popis |  
  |  ------  | ------    |
  |  unordered_map<K, H, HF, R, A> | hešová tabuľka obsahujúca dvojice kľúč (typu K)-hodnota (typu H)| 
  |  unordered_multimap<K, H, HF, R, A>| hešová tabuľka, v ktorej sa môžu opakovať kľúče  | 
  | unordered_set<K, HF, R, A>| hešová tabuľka obsahujúca iba kľúče typu K|        
  | unordered_multiset<K, HF, R, A>|  hešová tabuľka, v ktorej sa môžu opakovať hodnoty|

K - typ kľúča
H- typ hodnoty
HF - hešovacia funkcia (=typ volatelného objektu / ukazateľ na funkciu alebo objekt s preťaženým operátorom volania funkcie, pre väčšinu bežných dátových typov sa dá využiť implicitná hodnota tohto parametra, čo je hash<K> s parametrom K)
R - nástoj pre zistenie rovnosti dvoch kľúčov (implicitná hodnota tohto parametru je equal<K>)

### vektor

Vektor spravuje svoje prvky v dynamickom poli. Umožnuje náhodný prístup, čo znamená, že môžeme pristupovať ku každému prvku priamo pomocou indexu.

Pripojenie a odstránenie prvkov z konca
 poľa je veľmi rýchle. 
 Vloženie prvku do stredu alebo na začiatok
  trvá, pretože všetky nasledujúce prvky 
  sa musia presunúť, aby sa vytvoril priestor pre nový prvok pri zachovaní poradia.
  
  ### deque (obojstranná fronta)
  (Double-ended-queue) je dynamické pole, 
  ktoré je implementované tak, aby mohlo
   rásť v oboch smeroch. Takže vloženie 
   prvku na konci a na začiatku je rýchle. 
   Vkladanie prvku v strede však trvá, 
   pretože element sa musí popresúvať.
   
   ### zoznam
   Zoznam je implementovaný ako 
    obojstranný. Inými slovami, každý 
    prvok v zozname má svoj vlastný 
    segment pamäte a odkazuje na svojho 
    predchodcu a svojho nástupcu. 
    Zoznamy neposkytujú náhodný prístup. 
    Všeobecný prístup k ľubovoľnému prvku 
    trvá lineárny čas a to je oveľa horšie 
    ako to trvá vektoru a fronte.
   
   
   Výhodou zoznamu je, že vloženie 
   alebo odstránenie prvku je rýchle z
    akejkoľvek pozície (musia sa zmeniť iba prepojenia). 
   To znamená, že presunutie prvku uprostred zoznamu je veľmi rýchle
    v porovnaní s presunutím prvku vo vektore alebo fronte.
    
    
   ## Inicializácia vektora
    
```c++  
#include <vector>

int main ()
{
  std::vector<int> vec0;                                 // empty vector of ints
  std::vector<int> vec1 (3);                             // 3 ints
  std::vector<int> vec2 (3,10);                          // 3 ints with value 10
  std::vector<int> vec3 (vec2.begin(),vec2.end());       // iterating via vec2
  std::vector<int> vec4 (vec3);                          // a copy of vec3
  int myInt[] = {1,2,3};                                 // construct from arrays:
  std::vector<int> vec5 (myInt, myInt + sizeof(myInt) / sizeof(int) );

  return 0;
}
```
    
    
  # členské funkcie push_back()/pop_back()/size()/clear()/empty()
  ```c++  
  #include <vector>
  #include <iostream>
  #include <string>
  
  int main()
  {
  	std::vector<std::string> Scientist;
  
  	Scientist.push_back("James Maxwell");
  	Scientist.push_back("Edwin Hubble");
  	Scientist.push_back("Charles Augustin de Coulomb");
  	Scientist.push_back("Louis Pasteur");
  
  	std::cout << "Now, we have " << Scientist.size() << " scientists.\n";
  	Scientist.pop_back();
  	std::cout << "Now, we have " << Scientist.size() << " scientists.\n";
  
  	std::vector<std::string>::iterator iter; 
  	for (iter = Scientist.begin(); iter != Scientist.end(); ++iter)
  		std::cout << *iter << std::endl;
  
  	Scientist.clear();
  	if(Scientist.empty()) 
  		std::cout << "Nothing in the list\n";
  	else
  		std::cout << "You have something in the list\n";
  
  	return 0;
  }
  ```
  
  Push_back () pridáva nový prvok na koniec vektora. 
  
  Pop_back () odstraňuje posledný prvok vektora a znižuje veľkosť vektora o jeden.
  
  Funkcia clear () člena odstráni všetky prvky vektora a nastaví jeho veľkosť na hodnotu 0.
  
  Prázdny () vracia "true", ak je vektor prázdny, inak vráti "false".
  
  ## Vektor - pamäťová náročnosť
  
  #### capacity()
   vracia kapacitu vektora (počet prvkov,
    ktoré môže vektor držať pred tým,
     ako preň program musí alokovať viac 
   pamäte). Kapacita vektora teda nie 
   je tá istá vec ako jeho veľkosť size(), 
   čo je počet prvkov, ktoré v súčasnosti 
   drží vektor. Stručne povedané, 
   capacity() je veľkosť kontajnera 
   a size() je aktuálne naplnená úroveň.
    capacity() je vždy rovnaká alebo 
    väčšia ako size(). Rozdiel medzi 
    nimi je počet prvkov, ktoré môžeme 
    pridať k vektoru pred tým, ako je 
    pole pod kapotou potrebné realokovať.
    
    
   #### reserve()
   Než sa pozrieme na reserve(), potrebujeme 
   vedieť, čo sa deje vždy, keď vektor 
   potrebuje viac miesta. Deje sa niečo podobné
    ako pri operácií realloc. 
    Nová alokácia pamäte, 
    kopírovanie zo starého do nového, 
    zničenie starých objektov, 
    dealokácia starých pamätí, 
    invalidácia iterátorov...čo je výpočtovo drahé.
    
    
   reserve() zvyšuje kapacitu vektora
    na číslo dodané ako argument. Dáva nám
kontrolu nad tým, kedy dôjde k realokácii
 dodatočnej pamäte.
 ```c++ 
 Scientist.reserve(20);  // reserve memory for 20 additional elements
  ```
 tj. použitím reserve() na udržanie dostatočne veľkej kapacity vektora môžeme oddialiť realokáciu vektora.
 
 #### insert() a erase()
 Pridanie alebo odstránenie prvku 
  konca vektora pomocou push_back() 
  alebo pop_back() je veľmi efektívne. 
  Pridanie alebo odstránenie prvku na 
  ľubovoľnom inom prvku vo vektore však môže
   vyžadovať viac práce, pretože možno bude 
   potrebné presunúť viacero prvkov. 
   Pri veľkých vektoroch to môže byť výpočtovo náročné.
   
   
   
   ### Vektor - inicializácia matice 3x2
 ```c++ 
    #include <iostream>
    #include <vector>
    
    using namespace std;
    
    #define ROW 3
    #define COL 2
    
    int main()
    {
            // vector with ROW rows, each row has COL columns with initial value of 99
    	vector<vector<int> > v2D(ROW, vector<int>(COL,99)); 
    	
    	for(int i = 0; i < ROW; ++i) {
    		for(int j = 0; j < COL; ++j) {
    			cout << v2D[i][j] << " ";
    		}
    		cout << endl;
    	}
    	return 0;
    }
 ```
alebo
```c++ 
#include <iostream>
#include <vector>

int main()
{
	// 3 x 2 matrix

	std::vector<std::vector<int> > myVecA(3,std::vector<int>(2) ) ;
	myVecA[0][0] = 0;
	myVecA[0][1] = 1;
	myVecA[1][0] = 10;
	myVecA[1][1] = 11;
	myVecA[2][0] = 20;
	myVecA[2][1] = 21;

	for(int i = 0;i < 3 ; i++) {
		for(int j = 0; j < 2; j++) {
		 std::cout << myVecA[i][j] << " " ;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::vector<std::vector<int> > myVecB;
	for (int i = 0; i < 3; i++) {
		std::vector<int> row; // Create an empty row
		for(int j = 0; j < 2; j++) {
			row.push_back(i+j); // Add an element (column) to the row
		}
		 myVecB.push_back(row); // Add the row to the main vector
      }
	for(int i = 0;i < 3 ; i++) {
		for(int j = 0; j < 2; j++) {
		 std::cout << myVecB[i][j] << " " ;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	
	std::vector<std::vector<int> > myVecC;
	for (int i = 0; i < 3; i++) {
		myVecC.push_back(std::vector<int>()); // Add an empty row
	}
	int dummy = 0;
	for (int i = 0; i < 3; i++) {
		for (std::vector<std::vector<int> >::iterator it = myVecC.begin(); it != myVecC.end(); ++it) {
			it->push_back(i*100 + dummy++); // Add column to all rows
		}
      }
	for(int i = 0;i < 3 ; i++) {
		for(int j = 0; j < 2; j++) {
		 std::cout << myVecC[i][j] << " " ;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
```

ÚLOHA: využite multidimenzionálne vektory na výpočet maticového násobenia. 

### Vektor vs zoznam

#### vektor:
1. Kontinuálna pamäť
2. Predbežne alokuje priestor pre budúce prvky, takže môže byť potrebný ďalší priestor.
3. Na rozdiel od zoznamu, kde je potrebný ďalší priestor pre ukazovateľ, každý prvok vyžaduje len priestor pre samotný typ prvku.
4. Môže realokovať pamäť pre celý vektor kedykoľvek keď pridávame nový prvok.
5. Vkladanie na konci je O(1), ale vkladanie inde je nákladné O(n)
6. Mazanie na konci j O(1), ale pre ostatné miesta O(n)
7. Môžeme náhodne pristupovať k jeho prvkom.
8. Môžeme sa jednoducho dostať do podkladového poľa, ak ho potrebujeme:
  ```c++ 
  std::vector<int> v;
        for(int i = 0; i < 10; ++i) v.push_back(i);
        int *a = &v[0];
```
#### zoznam:
1. Nekontinuálna pamäť
2. Žiadna prealokovaná pamäť. 
3. Každý prvok vyžaduje väčší priestor pre uzol, ktorý obsahuje element, vrátane ukazovateľov na ďalší a predchádzajúci prvok v zozname.
4. Nikdy netreba realokovať pamäť 
pre celý zoznam len preto, že pridáme prvok.
5. Vkladania a mazania sú lacné bez ohľadu na to, kde sa v zozname vyskytujú.
6. Nemôžeme náhodne pristupovať k prvkom, takže dostať sa na určitý prvok v zozname môže byť drahé.
7. Ak budeme potrebovať rad elementov, budeme musieť vytvoriť nový a pridať ich všetky, pretože neexistuje žiadne podkladové pole.


