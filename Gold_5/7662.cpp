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
    int t;
    cin >> t;
    while (t--) {
        multiset<int> s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char o;
            int x;
            cin >> o >> x;
            if (o == 'D') {
                if (s.empty()) continue;
                if (x == 1) s.erase(prev(s.end()));
                else s.erase(s.begin());
            } else s.insert(x);
        }

        if (s.empty()) cout << "EMPTY\n";
        else cout << *prev(s.end()) << " " << *s.begin() << "\n";
    }
}