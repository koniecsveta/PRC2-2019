
Profesor diskretnej matematiky je frustrovany nedostatocnou disciplinou svojich studentov a rozhodne sa zrusit prednasku,
ak na nu nacas pride menej nez isty pocet studentov. Cas prichodu sa pohybuje od "nacas" (arrivalTime<=0) do "neskoro" (arrivalTime>0).

Rozhodnite, ci sa prednaska zrusi, ak dostanete cas prichodu kazdeho studenta a hranicny pocet studentov.

Format vstupu:

Prvy riadok vstupu obsahuje cislo t, pocet pripadov.
Kazdy pripad sa sklada z dvoch riadkov.
Prvy riadok obsahuje dva integery oddelene medzerou, pocet studentov n (size[a]) a hranicny pocet studentov pre zrusenie prednasky k
Druhy riadok obsahuje n medzerou oddelenych integerov (a[1], a[2], ..., a[n]), ktore predstavuju casy prichodu studentov.

Poznamka: 

zaporny cas prichodu a[i]<= 0 indikuje vcasny prichod, kladny cas prichodu (a[i]> 0) indikuje ze studen zmeskal a[i] minut


napriklad ak mame n=6 studentov, ktori prisli v casoch a = [-1,-1,0,0,1,1], tak 4 prisli nacas a 2 neskoro. Ak je na hodine treba
aspon k = 4 studentov na to, aby sa prednaska konala, tak by sa v tomto pripade konala. Ak by bolo k=5, tak by sa prednaska zrusila.

Popis funkcie:

Doplne funkciu angryProfessor. Musi vracat YES ak sa prenaska ma zrusit, NO inak.
angryProfessor ma nasledujuce vstupne parametre:
 k: hranicna hodnota poctu studentov 
 a: pole integerov reprezentujuce casy prichodov


Obmedzenia: 

 1 <= t <= 10
 
 1 <= n <= 1000
 
 1 <= k <= n
 
 -100 <= a[i] <= 100, kde i /in [1,...n] 

Format vystupu:

pre kazdy test case funkcia vrati YES ak sa ma prednaska zrusit alebo NO ak nie.

Vzorovy vstup:

2

4 3

-1 -3 4 2

4 2

0 -1 2 1

Vzorovy vystup:
YES
NO

Vysvetlenie:

1.: k=3, tj profesor chce mat na prednaske najmenej 3 pritomnych studentov, ale iba 2
prisli nacas (-1, -3), takze prednaska sa zrusila
2.: k=2, profesor chce mat na prednaske najmenej 2 pritomnych studentov, a 2 prisli nacas (0, -1), takze
prednaska sa nezrusi


    
```c++  
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Doplnte funkciu angryProfessor
string angryProfessor(int k, vector<int> a) {



}

int main()
{
    ofstream fout("output.txt",std::ofstream::out);

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string result = angryProfessor(k, a);

        fout << result << "\n";
    }

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
