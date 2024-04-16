#include<iostream>
#include <sstream>

using namespace std;

int main() {
    string s = "hello,world"; // given
    stringstream ss(s);
    string curr;
    while (getline(ss, curr, ',')) { // curr will have an individual token to be processed}
        cout << curr << endl;
    }
    return 0;
}
