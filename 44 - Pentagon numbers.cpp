#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e4 + 10;

set<ll> table;
vector<ll> memo;

void precomp() {
    for(int i = 1; i < maxn; i++) {
        ll p = i * (3 * i - 1)/2;
        table.insert(p);
        memo.push_back(p);
    }
}

void solve() {
    ll ans = 1e15;
    for(int i = 0; i < memo.size(); i++) {
        for(int j = i+1; j < memo.size(); j++) {
            int sum = memo[j]+memo[i];
            int dif = memo[j]-memo[i];
            if(table.count(sum) && table.count(dif)) {
                ans = min(ans, abs(memo[j]-memo[i]));
                break;
            }
        }
    }

    cout << ans << endl;
}

int main() {
    precomp();
    solve();
    return 0;
}
