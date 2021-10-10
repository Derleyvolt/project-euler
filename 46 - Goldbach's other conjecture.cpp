#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

bitset<maxn> table;

vector<int> primes;
int         pr[maxn];

void sieve() {
    for(int i = 2; i < maxn; i++) {
        if(table[i]) continue;
        primes.push_back(i);
        pr[i] = 1;
        for(int j =i*2; j < maxn; j += i)
            table[j] = 1;
    }
}

void solve() {
    pr[1] = 1;
    for(int i = 1; i < maxn; i += 2) {
        int f = 0;
        for(auto p : primes) {
            for(int j = 1; j < 1000; j++) {
                if(i == p + 2*j*j) {
                    f = 1;
                    break;
                }
            }

            if(f) {
                break;
            }
        }

        if(f == 0 && pr[i] == 0) {
            cout << "achou: " << i << endl;
            return;
        }
    }
}

int main() {
    sieve();
    solve();
    return 0;
}
