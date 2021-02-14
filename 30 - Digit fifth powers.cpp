#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define vi  vector<int>
#define ii  array<int,2>

// é fácil encontrar um upper-bound, mesmo que não muito preciso.. por ex, o número 399999 geraria isso ( 3^5 + 5 * 9^5 ==  295488 ), ou seja,
// qualquer número acima de 3 * 1e5 não terá essa propriedade.

bool is(int n) {
    int aux = n;
    while (n) {
        aux -= pow(n % 10, 5);
        n /= 10;
    }
    return aux == 0;
}

void solve() {
    ll ans = 0;
    for (int i = 2; i < 1e5 * 3; i++) {
        if (is(i))
            ans += i;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
