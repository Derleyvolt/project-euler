#include <bits/stdc++.h>

using namespace std; 

#define ll long long

int num_div(ll n) {
    int ans = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(n/i == i)
                ans++;
            else
                ans += 2;
        }
    }
    return ans;
}

void gen() {
    ll temp = 0;
    for(int i = 1;; i++) {
        temp += i;
        if(num_div(temp) >= 500) {
            cout << temp << endl;
            return;
        }
    }
}

int main() {
    gen();
    return 0;
}
