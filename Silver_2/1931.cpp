#include <bits/stdc++.h>
using namespace std;

int n;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
};

int main() {

    input();
    cin >> n;
    vector<pair<int,int>> meeting(n);
    for (int i = 0; i < n; i++) {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting.begin(), meeting.end(), cmp);
    int cnt = 1;
    int end_time = meeting[0].second;

    for (int i = 1; i < n; i++) {
        if (meeting[i].first >= end_time) {
            end_time = meeting[i].second;
            cnt++;
        }
    }

    cout << cnt;
}