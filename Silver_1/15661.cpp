#include <bits/stdc++.h>
using namespace std;

int s[20][20];
int n;

int go(int index, vector<int> &first, vector<int> &second) {

    if (index == n) {
        if (first.size() == 0) return -1;
        if (second.size() == 0) return -1;
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < first.size(); i++) {
            for (int j = 0; j<  first.size(); j++) {
                if (i == j) continue;
                t1 += s[first[i]][first[j]];
            }
        }
        for (int i = 0; i < second.size(); i++) {
            for (int j =0 ; j < second.size(); j++) {
                if (i == j) continue;
                t2 += s[second[i]][second[j]];
            }
        }
        int diff = abs(t1 - t2);
        return diff;
    }
    int ans = -1;
    first.push_back(index);
    int t1 = go(index + 1, first, second);
    if (ans == -1 || (t1 != -1 && ans > t1)) {
        ans = t1;
    }
    first.pop_back();
    second.push_back(index);
    int t2 = go(index + 1, first, second);
    if (ans == -1 || (t2 != -1 && ans > t2)) {
        ans = t2;
    }
    second.pop_back();
    return ans;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> first, second;
    cout << go(0, first, second) << '\n';
} 
