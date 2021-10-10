#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

const int maxn = 1e7 + 10;

bitset<maxn> table;

int pr[maxn];
vi primes;

void sieve() {
    for(int i = 2; i < maxn; i++) {
        if(table[i]) continue;
        primes.push_back(i);
        pr[i] = 1;
        for(int j = i*2; j < maxn; j += i)
            table[j] = 1;
    }
}

void solve() {
    int aux = 0, cnt = 0;
    for(auto p : primes) {
        int f = 1;
        string num = to_string(p);
        while(num.size() > 0) {
            if(pr[stoi(num)] == 0) {
                f = 0;
                break;
            }
            num.erase(num.begin());
        }

        if(f == 0) {
            continue;
        }

        num = to_string(p);

        while(num.size() > 0) {
            if(pr[stoi(num)] == 0) {
                f = 0;
                break;
            }
            num.pop_back();
        }

        if(f && p > 7) {
            cnt++;
            aux += p;
            if(cnt == 11) {
                cout << "achou:" << aux << endl;
                return;
            }
        }
    }
}

int main() {
    sieve();
    solve();
    return 0;
}
