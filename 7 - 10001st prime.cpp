#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

bool is_prime(int n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int cnt = 0, i = 0;
    while (cnt < 10001) {
        i++;
        cnt += is_prime(i);
    }
    cout << i << endl;
}
