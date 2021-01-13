#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e6 + 10;

bitset<maxn> table;

vector<int> primes;

void sieve(int n = 1e6) {
    for(int i = 2; i < n; i++) {
        if(table[i]) continue;
        primes.push_back(i);
        for(int j = 2 * i; j < n; j += i)
            table[j] = 1;
    }
}

void solve() {
    int length = primes.size();
    array<int, 2> ans = {0,0};
    for(int i = 0; i < length; i++) {
        int cnt = 0;
        int sum = 0;
        for(int j = i; j < length; j++) {
            sum += primes[j];
            cnt++;
            if(sum >= 1e6)
                break;
            if(table[sum] == 0) {
                if(ans[0] < cnt) {
                    ans[0] = cnt;
                    ans[1] = sum;
                }
            }
        }
    }

    cout << ans[1] << endl;
}

int main() {
    sieve();
    solve();
    return 0;
}
