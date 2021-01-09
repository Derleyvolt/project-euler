#include <bits/stdc++.h>

using namespace std; 

#define ll long long

const int maxn = 1e7 + 10;

ll table[maxn];

int collatz(ll n) {
    ll ans = 1, v = n;
    while(n != 1) {
        if(n < maxn and table[n])
            return table[v] = table[n] + ans;
        if(n & 1)
            n = n * 3 + 1;
        else
            n = n / 2;
        ans++;
    }
    return table[v] = ans;
}

int main() {
    array<int, 2> ans = {};
    for(int i = 1; i < 1000000; i++) {
        if(collatz(i) > ans[0])
            ans = { collatz(i), i }; // O(1), o resultado já foi memorizado..
    }
    cout << ans[1] << endl;
    return 0;
}
