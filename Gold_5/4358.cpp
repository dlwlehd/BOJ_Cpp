#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt","r",stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt","w",stdout);
}

int main() {
    input();
    map<string, double> m;
    string x;
    double cnt = 0;
    while (getline(cin, x)) {
        cnt++;
            if (m.find(x) != m.end()) m[x]++;
        else m[x] = 1;
    }

    cout << fixed;
    cout.precision(4);

    for (auto i: m) {
        cout << i.first << " ";
        cout << i.second * 100 / cnt << "\n";
    }
}