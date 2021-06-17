#include <bits/stdc++.h>

using namespace std;

#define ll  unsigned long long
#define INF 1e17

map<map<ll, ll>, vector<ll>> mp;

void generate() {
    for(ll i = 1; i < int(10000); i++) {
        map<ll, ll> mpt;
        string digit = to_string(i*i*i);
        for(auto& s : digit) {
            mpt[s]++;
        }

        mp[mpt].push_back(i*i*i);
    }
}

int main() {
    generate();
    ll ans = INF;
    for(auto& [m, vet] : mp) {
        if(vet.size() == 5) {
            for(auto v : vet) {
                ans = min(ans, v);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
