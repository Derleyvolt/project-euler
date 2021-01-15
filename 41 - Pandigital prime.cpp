#include <bits/stdc++.h>

using namespace std;

#define ll long long

// o resultado deve ser alguma permutação desses números..

// Um detalhe simples e interessante que eu não saquei é que todo número contendo os números de 1 até 9, independente da ordem, é divisível por 3..
// o mesmo vale pros números de 1 até 8..
// esse detalhe eu vi no fórum do Project Euler após a submeter a minha solução.

vector<string> permut = {
                            {"1"},
                            {"21"},
                            {"321"},
                            {"4321"},
                            {"54321"},
                            {"654321"},
                            {"7654321"},
                            {"87654321"},
                            {"987654321"}
                        };

bool is_prime(ll n) {
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

ll solve() {
    reverse(permut.begin(), permut.end());
    for(auto num:permut) {
        for(;;) {
            if(is_prime(stoi(num)))
                return stoi(num);
            // gera uma sequência lexicográfica decrescente..
            if(not prev_permutation(num.begin(), num.end()))
                break;
        }
    }
    return int("O CÓDIGO NUNCA CHEGARÁ AQUI..");
}

int main() {
    cout << solve() << endl;
}
