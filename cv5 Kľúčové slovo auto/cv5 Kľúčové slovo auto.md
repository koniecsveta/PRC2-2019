
# Kľúčové slovo auto (v C++11)


 Kľúčové slovo auto hovorí kompilátoru aby typ deklarovanej premennej odvodil od
 jeho inicializačného výrazu, tj. ide o analógiu kľúčového slova var v c#.
 ```c++
 auto page_no=0;
 auto coeff=3.6666667;
 auto error_message="unit malfunction"; 
 auto dirty=false;
 auto str=std::string("hello");
 ...
 ```
 
Hodí sa v prípadoch ako napr.

 ```c++
    std::map<std::string, std::map<std::string, int>> StudentGrades;

    StudentGrades["Deb"]["Physics"] = 96;
    StudentGrades["Deb"]["Chemistry"] = 92;
    StudentGrades["Deb"]["Math"] = 82;
    StudentGrades["Vik"]["Physics"] = 92;
    StudentGrades["Vik"]["Chemistry"] = 88;
    StudentGrades["Vik"]["Math"] = 91;


    for (std::map<std::string, std::map<std::string, int>>::iterator outerMap_Iter = StudentGrades.begin(); outerMap_Iter != StudentGrades.end(); ++outerMap_Iter)
    {
        std::cout << outerMap_Iter->first << std::endl;
        for (std::map<std::string, int>::iterator innerMap_Iter = outerMap_Iter->second.begin(); innerMap_Iter != outerMap_Iter->second.end(); ++innerMap_Iter)
        {
            std::cout << innerMap_Iter->first << " : " << innerMap_Iter->second << std::endl;
        }
        std::cout << std::endl;
    }

    //auto keyword usage I
    for (auto outerMap_Iter = StudentGrades.begin(); outerMap_Iter != StudentGrades.end(); ++outerMap_Iter)
    {
        std::cout << outerMap_Iter->first << std::endl;
        for (auto innerMap_Iter = outerMap_Iter->second.begin(); innerMap_Iter != outerMap_Iter->second.end(); ++innerMap_Iter)
        {
            std::cout << innerMap_Iter->first << " : " << innerMap_Iter->second << std::endl;
        }
        std::cout << std::endl;
    }
    
        //auto keyword usage II
        for (auto const &outer_iter : StudentGrades)
        {
            std::cout << outer_iter.first << std::endl;
    
            for (auto const &inner_iter : outer_iter.second)
            {
                std::cout << inner_iter.first << " : " << inner_iter.second << std::endl;
            }
        }
   ```
   
   
   vo všeobecnosti:
   ```c++
   a_long_variable_declaration myVar = value;
   ```
   môžeme nahradiť
   ```c++
   auto myVar = value;
   ```
   
   Auto si vynucuje inicializáciu premennej (čoho vedľajší efekt je prevencia takýchto bugov):
  ```c++
   auto x1; //nok
   
   int x1; //ok
  ``` 
   ### Použitie na ukazatele a referencie:
   ```c++
    double var = 10.0;
    double &varRef = var;
    auto varAuto = varRef;
   ```
   varAuto bude typu double 
   
   ```c++
   double var = 10.0;
   double *varPtr  = &var;
   auto varAuto    = varPtr;
  ```
  varAuto bude ukazatel na double 
  
  Aký je medzi nimi rozdiel?
  
  Podľa špecifikácie [C++11](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf)
  sa auto vyodnocuje rovnako ako pri deklarovaní  šablóny funkcie
  ```c++
  template <class U> void f(U u);
  ```
  
  Tj pre referenciu a "konštantnosť" musíme explicitne písať & U alebo const & U. 
  V opačnom prípade dôjde k strate referencie alebo konštantnosti.
  
  
  Viac o týchto pravidlách sa dá nájsť napr. v [Effective Modern C++](https://www.amazon.com/gp/product/1491903996/ref=as_li_tl?ie=UTF8&camp=1789&creative=390957&creativeASIN=1491903996&linkCode=as2&tag=bfilipek-20&linkId=JBVRVBT6H7MJSOQV)
  
  ďalšie príklady:
  ```c++
  const float myFloat = 0.0f;
  auto f = myFloat; // float
  f = 2.0f;         // ok
  
  const auto fc = myFloat; // ok
  fc = 2.0f;  // nok 
  ```
  ```c++
  int b = 10;
  const int *pb = &b;
  auto ppb      = pb;  // const int*
  *pb  = 100;          // nok
  *ppb = 101;          // nok
 ```
 ```c++
 int b = 10;
 int *const pb = &b;
 auto ppb      = pb;  // int*
 *pb  = 100;          // ok
 *ppb = 101;          // ok
 ```
     
  ### Nevhodné použitie auto:
   - akékoľvek použitie, ktoré znižuje čitateľnosť kódu, napr.
   ```c++
    auto a = ConjureMagic();
    SetMagic(a);
   ``` 
   ```c++
    auto a = ConjureMagic() ; // worst
    	
    auto a = ConjureMagicInteger() ; // better
    	
    int a = ConjureMagicInteger(); // best
   ``` 
   
   
   * k auto sa viaže decltype - viac informácií [tu](http://thbecker.net/articles/auto_and_decltype/section_01.html)