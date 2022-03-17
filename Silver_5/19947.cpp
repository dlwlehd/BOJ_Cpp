#include <bits/stdc++.h>
using namespace std;

int n, y;
int res = 0;

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

void func(int idx, int tot) {
    
    if (idx > y) {
        return;
    }

    res = max(tot,res);

    func(idx + 1, tot * 1.05);
    func(idx + 3, tot * 1.2);
    func(idx + 5, tot * 1.35);
}

int main(void) {

	input();
    cin >> n >> y;

    func(0,n);
    cout << res;
}