#include <bits/stdc++.h>
using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

int main() {
    input();
    while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<string> a(n);
		for (auto& i : a) cin >> i;
		sort(a.begin(), a.end());
		int vis_x, vis_y;
		string x = "", y = "";
		for (int i = 0; i < n; i++) {
			if (a[i] != "0") {
				x = a[i];
				vis_x = i;
				break;
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (a[i] != "0" && i != vis_x) {
				y = a[i];
				vis_y = i;
				break;
			}
		}
		
		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (i == vis_x || i == vis_y) continue;
			if (idx % 2 == 0) {
				idx++;
				x += a[i];
			}
			else {
				idx++;
				y += a[i];
			}
		}
		cout << stoi(x) + stoi(y) << "\n";
	}
}
