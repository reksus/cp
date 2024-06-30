#include<bits/stdc++.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F // 0x1f is 111111 == 31
#define N 10000000

typedef long long ll;

using namespace std;

template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        cout << *i1 << '\n';
        i1++;
    }
    cout << "\n";
}

struct bitVector {
    int *a;
    size_t size;
    
    bitVector(const size_t sz): size(1 + sz/BITSPERWORD) {
        a = new int[size];
        memset(a, 0, sz);
    }

    void set(const size_t& i) {
        // cout << (i >> SHIFT) << ' ' << (i & MASK) << ' ' << (1 << (i & MASK)) << endl;
        a[i >> SHIFT] |= (1 << (i & MASK));
    }
    void clr(const size_t& i) {
        a[i >> SHIFT] &= ~(1 << (i & MASK));
    }
    int test(const size_t& i) {
        return a[i >> SHIFT] & (1 << (i & MASK));
    }
    void show() {
        for (size_t i = 0; i < 5; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    
    ~bitVector() {
        // cout << "removing bitVector...\n";
        delete a;
    }
};

int main() {
    bitVector bv(N);
    bv.set(33);
    bv.show();
    cout << bv.test(33) << '\n';


    // cout << bv.test(32) << '\n';

    // bitset<10> b(63);
    // cout << b << '\n';
    // bitset<10> b2(63 & 0x1F);
    // cout << b2 << '\n';
    return 0;
}