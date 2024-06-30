#include<bits/stdc++.h>
using namespace std;
int main() {
    cout << "hello world!" << endl;
    set<int> S;
    int i;
    set<int>::iterator j;
    while (cin >> i) {
        S.insert(i);
    }
    for (j = S.begin(); j != S.end(); j++) {
        cout << *j << "\n";
    }
    return 0;
}
