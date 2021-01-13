#include <bits/stdc++.h>

using namespace std; 

#define vi vector<int>

const int maxn = 1e6 + 10;

bitset<maxn> table;

vector<int> primes;

// preprocessando os primos pra encontrar os fatores mais rapidamente
void sieve(int n = maxn) {
    for(int i = 2; i <= n; i++) {
        if(table[i]) continue;
        primes.push_back(i);
        for(int j = 2 * i; j <= n; j += i)
            table[j] = 1;
    }
}

vi factors(int n) {
    vi ans;
    int it = 0;
    while(n > 1) {
        bool insert = 1;
        while(n % primes[it] == 0) {
            if(insert) // guardar apenas um fator por primo
                ans.push_back(primes[it]);
            n /= primes[it];
            insert = 0;
        }
        it++;
    }
    return ans;
}

// true se não tiverem nada em comum
bool has_common(vi a, vi b) {
    vi ans;
    // função lenta mas faz o que eu preciso em poucas linhas
    set_intersection(a.begin(), a.end(), 
                     b.begin(), b.end(), back_inserter(ans));
    return ans.size() == 0;
}

void solve() {
    for(int i = 1; i < maxn; i++) {
        vi a = factors(i);
        vi b = factors(i+1);
        vi c = factors(i+2);
        vi d = factors(i+3);
        
        if(a.size() < 4 or b.size() < 4 or c.size() < 4 or d.size() < 4)
            continue;

        bool ans = has_common(a, b) and has_common(b, c) and has_common(c, d);
        if(ans) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    sieve();
    solve();
    return 0;
}
