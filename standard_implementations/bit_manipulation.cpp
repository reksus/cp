#include<iostream>
using namespace std;

// negative of x
int neg(int x) {
    return ~x + 1;
}

// count number of set bits
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= n-1;
        count++;
    }
    return count;
}

// count number of unset bits
int countUnsetBits(int n) {
    int count = 0;
    while (n) {
        n &= n+1;
        count++;
    }
    return count;
}

// rightmost set bit
int rightMostSetBit(int n) {
    return n & ~(n-1);
}

// get nearest power 2 >= n
int getNearestPower2(int n) {
    int p = 1;
    // runs 32 times
    while (p < n) {
        p <<= 1;
    }
    return p;
}

int getNearestPower2Optimized(int n) {
    n -= 1; // (handle case: if n is already pow of 2)
    // runs 5 times
    n |= n>>1;
    n |= n>>2;
    n |= n>>4;
    n |= n>>8;
    n |= n>>16;
    return n+1;
}

int add_without_plus(int a, int b) {
    // check the neetcode soln as well, that is more intuitive
    return (a^b) + (a&b << 1);
}



int main() {

    cout << getNearestPower2(3) << endl; // 4
    cout << getNearestPower2Optimized(5) << endl; // 8
    cout << getNearestPower2(4) << endl; // 8
    cout << getNearestPower2Optimized(4) << endl; // 8

    return 0;
}