#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<int>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

string pand = "0123456789";

ll test(string s) {
    int div[] = { 2, 3, 5, 7, 11, 13, 17 };
    for(int i = 0; i < 7; i++) {
        string str = s.substr(i+1, 3);
        if(stoll(str) % div[i] != 0) {
            return 0;
        }
    }

    return stoll(s);
}

void solve() {
    ll ans = 0;
    while(1) {
        ans += test(pand);
        if(!next_permutation(pand.begin(), pand.end())) {
            cout << ans << endl;
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}
