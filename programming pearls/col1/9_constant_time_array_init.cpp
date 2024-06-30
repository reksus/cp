/*
“One problem with trading more space to use less time is
that initializing the space can itself take a great deal of
time. Show how to circumvent this problem by designing a
technique to initialize an entry of a vector to zero the
first time it is accessed. Your scheme should use constant
time for initialization and for each vector access, and use
extra space proportional to the size of the vector. Because
this method reduces initialization time by using even more space,
it should be considered only when space is cheap, time is dear and
the vector is sparse.”
*/
#include<bits/stdc++.h>
typedef long long ll;
template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

using namespace std;

struct defaultArray {
    defaultArray(const int& sz, const int& default_value) 
        :   default_value(default_value),
            top(0),
            size_(sz),
            data(new int[sz]),
            from(new int[sz]),
            to(new int[sz]) {}

    int& operator[](const size_t& i) {
        cout << i << ' ' << top << endl;
        if (from[i] < top && to[from[i]] == i) {
            return data[i];
        } else {
            from[i] = top;
            to[from[i]] = i;
            data[i] = default_value;
            top++;
            return data[i];
        }
    }

    int size() const { return size_; }

    ~defaultArray() {
        delete[] data;
        delete[] from;
        delete[] to;
    }
    private:
        int default_value;
        int top;
        int size_;
        int *data;
        int *from;
        int *to;
        
};

int main() {
    defaultArray da(10000000, 5);
    for (int i = 0; i < 10; i += 3) {
        da[i] = 20190101;
    }
    cout << da[0] << endl;
    cout << da[3] << endl;
    cout << da[6] << endl;
    cout << da[9] << endl;
    return 0;
}