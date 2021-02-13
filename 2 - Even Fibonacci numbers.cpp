#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define vi  vector<int>
#define ii  array<int,2>

const int maxn = 1e6;

int table[maxn];

void solve() {
     ll ans = 0;
     table[0] = 1;
     table[1] = 1;
     for(int i = 2; i < maxn; i++) {
          table[i] = table[i-1] + table[i-2];
          if(table[i] > 4 * 1e6) break;
          if(table[i] % 2 == 0) 
               ans += table[i];
     }
     cout << ans << endl;
}

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     solve();
     return 0;
}
