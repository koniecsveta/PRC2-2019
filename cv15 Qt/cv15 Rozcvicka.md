

Dostali ste na starost narodeninovu tortu svojej sestry a rozhodoli ste sa, ze na torte bude tolko sviecok, kolko rokov ide oslavovat. Pri sfukovani sa jej vzdy podari sfuknut iba tie najvyssie sviecky. Vasou ulohou je zistit, kolko sviecok sfukne.

Napriklad, ak ide oslavovat 4. narodeniny a narodeninova torta bude mat 4 sviecky dlzok 4, 4, 1 a 3, sestra sfukne 2 sviecky, pretoze najdlhsie sviecky maju dlzku 4 a na torte su 2 take sviecky.

Popis funkcie:

Doplnte funkciu birthdayCakeCandles, ktora ma vracat integer reprezentujuci pocet sviecok, ktore vasa vie sestra sestra sfuknut. Funkcia ma parameter ar - pole integerov reprezentujuce vysky sviecok.

## Format vstupu:

Prvy riadok obsahuje integer n, ktory reprezentuje pocet sviecok na torte.

Druhy riadok obsahuje n medzerou oddelenych integerov, kde kazdy integer i popisuje dlzku itej sviecky.

## Obmedzenia:


1 <= n <= 10^5

1 <= ar[i] <= 10^7

## Format vystupu:

Vypis poctu sviecok, ktore sestra sfukne.

## Vzorovy vstup:


4

3 2 1 3

## Vzorovy vystup:

2

## Vysvetlenie

Mame jednu sviecku dlzky 1, jednu sviecku dlzky 2 a dve sviecky dlzky 3. Vasa sestra sfukuje iba tie najvyssie sviecky, tj. tie dlzky 3. Sviecky dlzky 3 su na torte 2 a preto vypiseme 2.


    
```c++  

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Doplnte funkciu birthdayCakeCandles 
int birthdayCakeCandles(vector<int> ar) {


}

int main()
{
    ofstream fout("output.txt",std::ofstream::out);

    int ar_count;
    cin >> ar_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = birthdayCakeCandles(ar);

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
