#include <bits/stdc++.h>

using namespace std; 

#define ll long long

// É ainda possível fazer várias podas nesse código e no próprio problema..

vector<int> num = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

ll ans;

bool is_prime(ll n) {
    if(n < 2)
        return false;
    if(n == 2)
        return true; 
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

ll biggest_prime(string& s) {
    for(auto a:s)
        if((a-'0') > s.length())
            return 0;
    
    ll ans = 0;
    while(not ans) {
        ll n = stoll(s);
        if(is_prime(n))
            ans = max(ans, n);
        if(::ans > n or not prev_permutation(s.begin(), s.end()))
            break;
    }
    return ans;
}

void solve() {
    int maxn = (1<<9) - 1;
    for(int i = maxn; i > 0 ; i--) {
        string str;
        for(int j = 0; j < 9; j++) {
            if(i & (1 << j))
                // o número de n dígitos obtido aqui é o maior, lexicograficamente,
                // então eu uso apenas prev_permutation.. portanto, o primeiro
                // primo que eu encontrar será o maior possível naquele subconjunto.
                str.push_back('0' + num[j]);
        }
        ans = max(ans, biggest_prime(str));
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
