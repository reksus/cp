#include "stdc++.h"

using namespace std;

int main() {
    int n;
    // vector copy
    
    // create a new copy
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = v1;
    vector<int> v3(v1);
    vector<int> v4;
    v4.insert(v4.end(), v1.begin(), v1.end());
    
    // rep a val n time at the end of vector
    int rep_val = 5;
    int rep_cnt = 10;
    vector<int> v5;
    v5.insert(v5.end(), rep_cnt, rep_val);

    // remove last n elements from the end of a vector
    n = 2;
    v5.resize(v5.size()-n); 

    // incrementally fill a vector strarting from a val
    iota (begin(v1), end(v1), val); // Fill with val, val+1, val+2, ...

    return 0;
}
