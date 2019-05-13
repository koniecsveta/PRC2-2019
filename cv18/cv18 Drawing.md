

__Popis ulohy__

Vasou ulohou je napisat jednoduchu konzolovu verziu programu na kreslenie.
Program by mal fungovat nasledovne: 
 1. Vytvori ciste platno.
 2. Pokresli platno prostrednictvom zadavania roznych prikazov. 
 3. Program sa ukonci.

```c++  
Prikaz		Popis
C w h           Vytvori platno sirky w a dlzky h. 

L x1 y1 x2 y2   Vytvori ciaru z bodu (x1,y1) do bodu (x2,y2). Podporovane musia byt 
                horizontalne a vertikalne ciary. Ciary sa budu vykreslovat pomocou znaku 'x'.
        
R x1 y1 x2 y2   Vytvori obdlznik s hornzm lavym rohom (x1,y1) a dolnzm pravzm rohom (x2,y2). 
                Ciary sa budu vykreslovat pomocou znaku 'x'.
               
B x y c         Vyplni priestor ktory obsahuje bod (x,y) "farbou" c. Funkcia tohto prikazu
                ma byt analogicka nastroju "bucket fill" z programu paint.
                
Q               Ukonci program.
```

__Vzor I/O__

Ukazka vzoroveho behu programu: 


```c++ 
zadany prikaz: C 20 4
----------------------
|                    |
|                    |
|                    |
|                    |
----------------------

zadany prikaz: L 1 2 6 2
----------------------
|                    |
|xxxxxx              |
|                    |
|                    |
----------------------

zadany prikaz: L 6 3 6 4
----------------------
|                    |
|xxxxxx              |
|     x              |
|     x              |
----------------------

zadany prikaz: R 14 1 18 3
----------------------
|             xxxxx  |
|xxxxxx       x   x  |
|     x       xxxxx  |
|     x              |
----------------------

zadany prikaz: B 10 3 o
----------------------
|oooooooooooooxxxxxoo|
|xxxxxxooooooox   xoo|
|     xoooooooxxxxxoo|
|     xoooooooooooooo|
----------------------

zadany prikaz: Q
```