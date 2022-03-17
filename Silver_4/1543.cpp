#include <bits/stdc++.h>
using namespace std;

string s, f;
int cnt = 0;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {

    input();
    getline(cin,s);
    getline(cin,f);
    
    int t = s.find(f, 0);

    while (s.find(f) != string::npos) {
        int t = s.find(f);
        cnt++;
        s = s.substr(t + f.length(), s.length());
    }

    cout << cnt;
}