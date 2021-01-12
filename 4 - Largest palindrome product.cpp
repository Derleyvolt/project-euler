#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> digits(int n) {
    vector<int> digits;
    while (n) {
        int r = n % 10;
        n /= 10;
        digits.push_back(r);
    }
    return digits;
}

bool is_palindrome(vector<int> arr) {
    int a = 0, b = arr.size() - 1;
    while (a < b) {
        if (arr[a++] != arr[b--])
            return false;
    }
    return true;
}


// usando string, mais simples..
bool is_palindrome_s(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

int solve() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (is_palindrome(digits(i * j))) // is_palindrome_s(to_string(i * j))
                ans = max(ans, i * j);
        }
    }
    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}
