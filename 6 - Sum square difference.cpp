#include <bits/stdc++.h>

using namespace std;

#define ll  unsigned long long
#define vi  vector<int>
#define ii  array<int,2>

void solve() {
     ll a = 0, b = 0;
     for(ll i = 0; i <= 100; i++) {
          a += i;
          b += i * i;
     }
     cout << a * a - b << endl;
}

int main() {
     solve();
     return 0;
}
