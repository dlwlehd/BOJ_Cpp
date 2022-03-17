#include <bits/stdc++.h>
using namespace std;

set<string> a;
string x;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

int main() {
    input();
    cin >> x;
    
    for(int i = 1; i <= x.size(); i++) {
        for (int j = 0; j < x.size() - i + 1; j++) {
            if (x.substr(j,i) == "") continue;
            a.insert(x.substr(j,i));
        }
    }
    
    cout << a.size();
}