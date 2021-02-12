#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define vi  vector<int>
#define ii  array<int,2>

bool is_prime(int n) {
     if(n < 2)
          return false;
     if(n == 2)
          return true;
     for(int i = 2; i * i <= n; i++)
          if(n % i == 0) return false;
     return true;
}

bool rotate(int n) {
     string aux = to_string(n);
     string s(aux);
     for(int i = 1; i < aux.size(); i++) {
          for(int j = 0; j < aux.size(); j++)
               s[(j+i) % aux.size()] = aux[j];
          if(not is_prime(atoi(s.c_str())))
               return false;
     }
     return true;
}

int main() {
     int ans = 0;
     for(int i = 0; i <= 1e6; i++) {
          if(is_prime(i) and rotate(i))
              ans++;
     }
     cout << ans << endl;
     return 0;
}
