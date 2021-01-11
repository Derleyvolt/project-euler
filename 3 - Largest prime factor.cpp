#include <bits/stdc++.h>

using namespace std; 

#define ll long long

ll factors(ll n) {
    ll ans = 0;
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ans = max((ll)i, ans);
            n /= i;
        }
    }
    
    return max(ans, n); // nesse ponto, ou n é o maior primo ou é 1.
}

int main() {
    cout << factors(600851475143) << endl;
    return 0;
}
