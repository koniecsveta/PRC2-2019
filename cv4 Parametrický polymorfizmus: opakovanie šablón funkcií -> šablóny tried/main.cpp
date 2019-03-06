#include <iostream>
#include "list.h"
using namespace std;

int main() {
    List<int> L;
    int temp;

    // read input
    cin >> temp;
    while (cin) {
        L.insert(temp);
        cin >> temp;
    }
    // discard 200
    while ( L.search(200) )
        L.remove(200);

    // output list in ascending order
    L.print();
    cout << endl;

    return 0;
}
