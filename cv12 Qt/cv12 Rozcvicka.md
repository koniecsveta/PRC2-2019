Emma sa hra na telefone novu hru. Dostane postupne ocislovane oblaky. Niektore oblaky
 su burkove a niktore iba neskodne "kopy". Moze skocit na lubovolny kopovy oblak, 
 ktoreho cislo je rovne cislu aktualneho oblaku plus 1 alebo 2. Musi sa vyhnut burkovym oblakom.
Odhadnite minimalny pocet skokov, ktory je potrebny na preskakanie zo 
startovacej pozicie na posledny oblak. Hru je vzdy mozne vyhrat.

Kazdu hru Emma dostane pole oblakov. Napr. c = [0,1,0,0,0,1,0] indexovane od 0...6. Oblak
 cislo i je bezpecny, ak c[i]= 0, a nebezpecny ak c[i]=1. Cislo oblaku je jeho index v poli, 
takze sa musi vyhnut oblakom cislo (na indexoch) 1 a 5. Oblaky moze preskakat dvomi
 sposobmi: 0 -> 2 -> 4 -> 6 alebo 0 -> 2 -> 3 -> 4 -> 6. Prvym sposobom oblaky
  preskace 3 skokmi, druhym 4 skokmi.

Popis Funkcie:

Doplnte funkciu jumpingOnClouds, ktora ma vratit minimalny pocet skokov (integer). 
Ma jediny vstup c: pole binarnych integerov.

Format vstupu:

Prvy riadok obsahuje integer n: celkovy pocet oblakov.
Druhy riadok obsahuje n binarnych inegerov oddelenych medzerou, 
ktore popisuju oblaky c[i], kde 0 <= i < n.

Obmedzenia:

2 <= n <= 100

c[i] /in <0,1>

c[0] = c[n-1] = 0

Format vystupu

minimalny pocet skokov potrebny na prejdenie hry


Vzorovy vstup 0:
```c++  
7
0 0 1 0 0 1 0
```
Vzorovy vystup 0: 
```c++  
4
```
Vysvetlenie 0:

Emma sa musi vyhnut c[2] a c[5]. Hru moze prejst najmenej 4 skokmi.

![alt text](case0.png)


Vzorovy vstup 1:
```c++  
6
0 0 0 0 1 0
```
Vzorovy vystup 1:
```c++  
3
```
Vysvetlenie 0:

Emma sa musi vyhnut c[4]. Hru moze prejst najmenej 3 skokmi.

![alt text](case1.png)


```c++  
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Doplnte funkciu jumpingOnClouds 
int jumpingOnClouds(vector<int> c) {


}

int main()
{
        ofstream fout("output.txt",std::ofstream::out);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
```