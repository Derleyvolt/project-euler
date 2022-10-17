#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int square(int num) {
	int v = sqrt(num) + 1;

	int l = 1, r = v;

	while(l <= r) {
		int m = (l+r)/2;

		if(m * m == num) {
			return m;
		}
		
		if(m*m > num) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}

	return 0;
}

int main() {
  	map<int, int> table;
  	for (int i = 1; i < 1000; i++) {
		for (int j = i+1; j < 1000; j++) {
			int c_pw = i*i + j*j;
			
			int c = square(c_pw);
			
			if(i+j+c > 1000) {
				break;
			}
			
			if(c) {
				table[i+j+c]++;
			}
		}
  	}	

	for(auto a : table) {
		cout << a.first << "   " << a.second << endl;
	}
	
 	return 0;
}
