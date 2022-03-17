#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main(void) {

	input();
    cin >> n;
    int idx, mx = -1;
    for (int i = n; i >= 0; i--) {
        v.clear();
        v.push_back(n);
        v.push_back(i);
        
        int j = 2;
        while(true) {
            int t = v[j-2] - v[j-1];
            if (t < 0) break;
            v.push_back(t);
            j++;
        }
        int s = v.size();
        mx = max(mx, s);
        if (v.size() == mx) {
            idx = i;
        }
    }
    
    cout << mx << "\n";
    v.clear();
    v.push_back(n);
    v.push_back(idx);
        
    int j = 2;
    while(true) {
        int t = v[j-2] - v[j-1];
        if (t < 0) break;
        v.push_back(t);
        j++;
    }
    
    for (int i : v) cout << i << " ";
}