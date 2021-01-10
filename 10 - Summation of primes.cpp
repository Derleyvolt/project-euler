#include <bits/stdc++.h>

using namespace std; 

#define ll long long

bool is_prime(ll n) {
    if(n < 2)
        return false;
    if(n == 2)
        return true;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int i = 0;
    vector<long long> ans;
    while(i < 2 * 1e6) {
        if(is_prime(i))
            ans.push_back(i);
        i++;
    }
    // se for colocado apenas 0 no último parâmetro da função accumulate a função vai retornar um int32 ao invés de um int64 que é
    // o inteiro que comporta a resposta.
    cout << std::accumulate(ans.begin(), ans.end(), 0LL) << endl;
    return 0;
}
