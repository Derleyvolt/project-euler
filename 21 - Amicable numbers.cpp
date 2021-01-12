#include <bits/stdc++.h>

using namespace std; 

const int maxn = 1e4;

int sum_divisors(int n) {
    int ans = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ans += i;
            if(n/i != i)
                ans += n/i;
        }
    }
    return ans;
}

int main() {
    int ans = 0;
    for(int i = 1; i < maxn; i++) {
        int tp = sum_divisors(i);
        if(tp != i and i == sum_divisors(tp))
            ans += i;
    }
    cout << ans << endl;
}
