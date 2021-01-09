#include <bits/stdc++.h>

using namespace std;

vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void solve() {
    int cnt = 1;
    while (cnt < int(1e6)) {
        next_permutation(arr.begin(), arr.end()); // gera as permutações em ordem lexicográfica.
        cnt++;
    }   
    for (auto a : arr) cout << a;
}

int main() {
    solve();
}
