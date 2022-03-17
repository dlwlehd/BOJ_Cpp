#include <bits/stdc++.h>
using namespace std;

string a;
deque<int> q;
vector<pair<int,int>> close;
bool vis[201];
bool ch[201];
set<string> ans;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

void func(int idx, int cnt) {
    if (cnt >= 1) {
		string s = "";
		for (int i = 0; i < a.size(); i++) {
			if (ch[i]) continue;
			s += a[i];
		}
		ans.insert(s);
	}   
	for (int i = idx; i < close.size(); i++) {
		if (vis[i]) continue;
		vis[i] = true;
		ch[close[i].first] = true;
		ch[close[i].second] = true;
		func(cnt + 1, idx + 1);
		vis[i] = false;
		ch[close[i].first] = false;
		ch[close[i].second] = false;
	}
}

int main() {
    input();
    
    cin >> a;
    int cnt = 1;
    stack<int> s;

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(') q.push_back(i);
        else if (a[i] == ')') {
            int P = q.back();
            q.pop_back();
            close.push_back(make_pair(P, i));
        }
    }

    func(0,0);
    for (auto x : ans) cout << x << "\n";
}
