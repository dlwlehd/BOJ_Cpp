#include <bits/stdc++.h>
using namespace std;

int n;
int result = 1, dc = 0, inc = 0, s = 0;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main(void) {

	input();
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

	for(int e = 1; e < n; e++){
		if (a[e-1] == a[e]) { 
            inc++; 
            dc++;
        }
		else if (a[e-1] < a[e]) { 
            inc++; 
            dc=0;
        }
		else { 
            dc++; 
            inc=0; 
        }

		if (inc >= 2 || dc >= 2) s = e-1;
		result = max(e-s+1, result);
	}
	
    cout << result;
}