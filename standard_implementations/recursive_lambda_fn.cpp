#include <iostream>
using namespace std;

int main() {
    auto factorial = [](int n, auto&& factorial) {
        if (n == 0) return 1;
        return n * factorial(n - 1, factorial);
    };
    cout << factorial(5, factorial) << endl;
    return 0;
}