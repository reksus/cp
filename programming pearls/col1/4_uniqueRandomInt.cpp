#include <bits/stdc++.h>

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


vector<int> uniqueRandom(int k, int n) {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        nums.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        int j = rand() % (n - i);
        swap(nums[i], nums[i + j]);
    }
    return vector<int>(nums.begin(), nums.begin() + k);
    
}

int main() {
    vector<int> r = uniqueRandom(10, 100);
    inspect<vector<int>>(r);
    return 0;
}