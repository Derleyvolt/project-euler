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
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

vi digits(int n) {
    vi ans;
    while(n)
        ans.push_back(n%10), n/= 10;
    return ans;
}

bool is(array<int, 3> arr) {
    vector<vector<int>> aux;
    for(auto a:arr) {
        aux.push_back(digits(a));
        sort(aux.back().begin(), aux.back().end());
    }
    
    return aux[0] == aux[1] and aux[0] == aux[2];
}

void solve() {
    vi primes;
    for(int i = 1000; i < 10000; i++) {
        if(is_prime(i) and i != 1487 and i != 4817 and i != 8147)
        if(is_prime(i))
            primes.push_back(i);
    }
   
    int len = primes.size();

    for(int i = 0; i < len; i++) {
        for(int j = i+1; j < len; j++) {
            for(int k = j+1; k < len; k++) {
                // prume
                if(primes[k] - primes[j] > primes[j] - primes[i]) 
                    break;
                if(primes[k] - primes[j] == primes[j] - primes[i]) {
                    array<int, 3> aux = { primes[i], primes[j], primes[k] };
                    if(is(aux))
                        cout << aux[0] << aux[1] << aux[2] << endl, exit(0);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
