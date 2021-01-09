#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

vi arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void solve() {
    int cnt = 1;
    while (cnt < int(1e6)) {
        next_permutation(arr.begin(), arr.end());
        cnt++;
    }   
    for (auto a : arr) cout << a;
}

int main() {
    solve();
}
