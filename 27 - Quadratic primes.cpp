#include <bits/stdc++.h>

using namespace std; 

#define ll long long

ll func(ll n, ll a, ll b) {
    return n * n + a * n + b;
}

ll is_prime(ll n) {
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n; i += 2) { // testando só pros ímpares.. O(sqrt(n) / 2)
        if(n % i == 0)
            return false;
    }
    return true;
}

void solve() {
    array<ll, 3> ans = {0, 0, 0};
    for(int i = -999; i < 1000; i++) {
        for(int j = -999; j <= 1000; j++) {
            ll cnt = 0;
            for(int n = 0; n < 1000; n++) { // suponho não haver nenhuma sequência de primos, com a = [-999, 1000) e b = [-999, 1000], maior que 1000..
                ll e = func(n, i, j);
                if(is_prime(e)) {
                    cnt++;
                    if(ans[0] < cnt) {
                        ans[0] = cnt;
                        ans[1] = i; // a
                        ans[2] = j; // b
                    }
                } else 
                    break;
            }
        }
    }
    cout << "numero maximo de primos \"consecutivos\": " << ans[0] << endl;
    cout << "n^2 + " << ans[1] << "n + " << ans[2] << endl;
}

int main() {
    solve();
    return 0;
}
