#include <bits/stdc++.h>
using namespace std;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int s (int n) {
    return n * (n - 1) / 2;
}

int main() {
    input();
    int t;
    bool prime[100002];
    vector<int> p;
    for (int i = 2; i * i <= 100000; i++) {
        if (prime[i]) continue;
        for (int j = i + i; j <= 100000; j += i) {
            prime[j] = 1;
        }
    }

    for (int i = 2; i <= 100000; i++) {
        if (!prime[i]) p.push_back(i);
    }

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < p.size(); i++) {
            int cnt = 0;
            if (n % p[i] == 0) {
                while (true) {
                    if (n % p[i] != 0) break;
                    n /= p[i];
                    cnt++;
                }

                cout << p[i] << " " << cnt << "\n";
            }
        }
    }


}