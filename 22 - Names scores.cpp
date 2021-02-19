#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define vi  vector<int>
#define ii  array<int,2>

int main() {
     vector<string> arr(1);
     while(getline(cin, arr.back(), ',')) {
          arr.back().erase(0, 1), arr.back().pop_back();
          arr.push_back("");
     }

     arr.pop_back();
     arr.back().pop_back();
     sort(arr.begin(), arr.end());

     ll ans = 0;

     for(int i = 0; i < arr.size(); i++)
          for(auto str : arr[i])
               ans += ((str+('a'-'A'))-'a'+1) * (i+1);

     cout << ans << endl;
     return 0;
}
