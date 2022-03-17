#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
typedef long long ll;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    string s, minx = "", maxx = "";
    int cnt = 0, mloc = 0, kloc = -1;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M'){
            if (cnt == 0) {
                minx += '1'; maxx += '5'; mloc = i;
            }
            else {
                minx += '0'; maxx += '0';
            }
            cnt++;
        }
        else {
            kloc = i;
            minx += '5';
            maxx += cnt == 0 ? '5' : '0';
            cnt = 0;
        }
    }
    if (mloc > kloc) {
        for(int i = mloc; i < n; i++){
            maxx[i] = '1';
        }
    }
    
    cout << maxx << "\n" << minx;
}