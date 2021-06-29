#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[21][10][10][4];

ll solve(int i, int a, int b, char f) {
    if(i >= 20)
        return 1;

    if(dp[i][a][b][f] != -1)
        return dp[i][a][b][f];

    ll ans = 0;
    for(int j = int(i == 0); j+a+b <= 9; j++) {
        if(f == 1) {
            ans += solve(i+1, a, j, 2);
        } else if(f == 2) {
            ans += solve(i+1, b, j, 2);
        } else {
            ans += solve(i+1, j, b, 1);
        }
    }

    return dp[i][a][b][f] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0, 0) << endl;
    return 0;
}
