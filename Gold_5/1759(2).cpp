#include <bits/stdc++.h>
using namespace std;

int l, c;

bool check(string &password) {
    int ja = 0;
    int mo = 0;
    for (char x : password) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            mo += 1;
        }
        else {
            ja += 1;
        }
    }
    return ja >= 2 && mo >= 1;
}

void func(int n, vector<char> &alpha, string password, int i) {
    if (password.length() == n) {
        if (check(password)) {
            cout << password << "\n";
        }
        return;
    }
    if (i == alpha.size()) return;

    func(n, alpha, password + alpha[i], i + 1);
    func(n, alpha, password, i + 1);
}

void input() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
}

int main() {
	input();
	cin >> l >> c;
    vector<char> v(c);
    for (int i = 0; i < c; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    func(l, v, "", 0);
}