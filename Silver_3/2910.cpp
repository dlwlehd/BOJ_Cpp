#include <bits/stdc++.h>
using namespace std;

int n, c;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("src/input.txt", "r", stdin);
}

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b) {
    if (get<2>(a) == get<2>(b)) return get<1>(a) < get<1>(b);
    else return get<2>(a) > get<2>(b);
}

int main() {
    input();
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<tuple<int,int,int>> v; // 값, 등장 위치, 등장 횟수
    for (int i = 0; i < n; i++) {
        bool found = false;
        int idx = 0;
        for (int j = 0; j < v.size(); j++) {
            if (get<0>(v[j]) == a[i]) {
                found = true;
                idx = j;
                break;
            }
        }
        
        if (found) {
            get<2>(v[idx])++;
        }
        else {
            v.push_back(make_tuple(a[i], i, 1));
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < get<2>(v[i]); j++) {
            cout << get<0>(v[i]) << " ";
        }
    }
}