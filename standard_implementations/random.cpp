#include<iostream>
#include <sstream>
#include <random>

using namespace std;

int main() {
    // get random (0 to N-1)	
    int N = 100;
    cout << (rand() % N) << endl;

    // get random (lo to hi)	
    int lo = 10, hi = 20;
    cout << (rand() % ((hi-lo+1) + lo)) << endl;
    
    return 0;
}

