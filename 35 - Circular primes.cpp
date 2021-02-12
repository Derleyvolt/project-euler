#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
     if(n < 2)
          return false;
     if(n == 2)
          return true;
     for(int i = 2; i * i <= n; i++)
          if(n % i == 0) return false;
     return true;
}

// usando arimética modular
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

// usando string insert
bool rotate_ex(int n) {
     string aux = to_string(n);
     for(int i = 1; i < aux.size(); i++) {
          aux.insert(0, 1, aux.back()), aux.pop_back();
          if(not is_prime(stoi(aux.c_str())))
               return false;
     }
     return true;
}

int main() {
     int ans = 0;
     for(int i = 0; i <= 1e6; i++) {
          if(is_prime(i)) {
               if(rotate_ex(i))
                    ans++;
          }
     }
     cout << ans << endl;
     return 0;
}
