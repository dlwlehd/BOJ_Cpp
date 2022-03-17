#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int res = -1;
bool a[1000002];

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {

    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        a[x] = 1;
    }

    int mx = *max_element(v.begin(), v.end());

    for (int i = mx; i > 0; i--) {
        if (!a[i]) continue;
        int seq = 0;
        int cur = v[0];

        for (int j = 0; j < v.size(); j++) {
            if (i == v[j]) continue;
            
            if (cur == v[j]) seq++;
            else {
                cur = v[j];
                seq = 1;
            }
            res = max(res, seq);
        }
    }

    cout << res;
}