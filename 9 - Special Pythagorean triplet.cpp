#include <bits/stdc++.h>

using namespace std; 

int solve() {
    for(int a = 1; a <= 1000; a++) {
        for(int b = 1; b <= 1000; b++) {
            if(a+b < 1000) {
                int c = 1000 - (a+b);
                if(a * a + b * b == c * c)
                    return a * b * c;
            }
        }
    }

    return int("A FUNÇÃO NUNCA EXECUTARÁ ESSA INSTRUÇÃO..");
}

int main() {
    cout << solve() << endl;
    return 0;
}
