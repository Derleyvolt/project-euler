#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

set<ll> mp1, mp2;

// modo porco de fazer.. dps tento fazer uma análise matemática nisso

void precomp() {
    for(ll i = 1; i <= 100000; i++) {
        mp1.insert(i*(3*i-1)/2);
        mp2.insert(i*(2*i-1));
    }
}

int main() {
    precomp();
    for(ll i = 286; i <= 100000; i++) {
        ll t = i*(i+1)/2;
        if(mp1.count(t) and mp2.count(t)) {
            cout << t << endl;
        }
    }
    return 0;
}
