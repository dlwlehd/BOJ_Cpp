#include <bits/stdc++.h>
using namespace std;

int n, q, cache;
int c[2001];
int totalsize, cur, presize, sufsize;
vector<int> suf;
deque<int> pre;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main(void) {
    input();
    cin >> n >> q >> cache;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < q; i++) {
        char action;
        cin >> action;
        if (action == 'B') {
            if (pre.size() == 0) continue;
            suf.push_back(cur);
            sufsize += c[cur];
            cur = pre.back();
            pre.pop_back();
            presize -= c[cur];
        } else if (action == 'F') {
            if(suf.size() == 0) continue;
            pre.push_back(cur);
            presize += c[cur];
            cur = suf.back();
            suf.pop_back();
            sufsize -= c[cur];
        } else if (action == 'A') {
            totalsize -= sufsize;
            sufsize = 0;
            suf.clear();
            if (cur > 0) {
                presize += c[cur];
                pre.push_back(cur);
            }
            int v;
            cin >> v;
            cur = v;
            totalsize += c[v];
            while (totalsize > cache) {
                int x = pre.front();
                totalsize -= c[x];
                presize -= c[x];
                pre.pop_front();
            }
        } else {
            deque<int> newpre;
            int t = 0;
            while (pre.size() > 0) {
                int v = pre.front();
                pre.pop_front();
                if(newpre.size() == 0 || newpre.back() != v) {
                    newpre.push_back(v);
                    t += c[v];
                }
            }
            pre = move(newpre);
            presize = t;
            totalsize = presize + sufsize + c[cur];
        }
    }
    cout << cur << "\n";
    if (pre.size() == 0) cout << "-1\n";
    else {
        while (pre.size() > 0) {
            cout << pre.back() << " ";
            pre.pop_back();
        }
        cout << "\n";
    }
    if (suf.size() == 0) cout << "-1\n";
    else {
        for (int i = suf.size() - 1; i >= 0; i--) {
            cout << suf[i] << " ";
        }
        cout << "\n";
    }
}