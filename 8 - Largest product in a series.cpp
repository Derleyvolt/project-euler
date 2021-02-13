#include <bits/stdc++.h>

using namespace std;

#define ll  unsigned long long
#define vi  vector<int>
#define ii  array<int,2>

// dps coloco aqui a versão com sliding window

int main() {
     string s, t;
     while(cin >> t) s.append(t);
     ll ans = 0;
     for(int i = 0; i < s.size()-12; i++) {
          ll aux = 1;
          for(int j = i; j < i+13; j++)
               aux = aux * (s[j] - '0');
          ans = max(ans, aux);
     }
     cout << ans << endl;
     return 0;
}
