#include <bits/stdc++.h>

using namespace std;

#define vi  vector<int>

const int maxn = 3 * 1e4;

int abudant[maxn];

vi abudant_arr;

int div(int n) {
    int ans = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ans += i;
            if(n/i != i)
                ans += n/i;
        }
    }
    return ans - n; // apenas os "proper divisors"
}

int solve() {
    int ans = 0;
    for(int i = 1; i < maxn; i++) {
        int can = 1;
        for(auto num : abudant_arr) {
            if(num >= i) break;
            int aux = i - num;
            if(abudant[aux]) {
                can = 0;
                break;
            }
        }
        if(can)
            ans += i;
    }
    return ans;
}

int main() {
    for(int i = 1; i < maxn; i++) {
        if(div(i) > i) {
            abudant[i] = 1;
            abudant_arr.push_back(i);
        }
    }
    cout << solve() << "\n";
    return 0;
}
