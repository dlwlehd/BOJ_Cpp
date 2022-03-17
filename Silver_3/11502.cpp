#include <bits/stdc++.h>
using namespace std;

int n;
bool prime[1002];
vector<int> p;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main(void) {

    input();
    cin >> n;

    prime[1] = 1;
    for (int i = 2; i <= sqrt(1000); i++) {
        if (prime[i]) continue;
        for (int j = i + i; j <= 1000; j += i)
            prime[j] = 1;
    }

    for (int i = 2; i <= 1000; i++) {
        if (!prime[i]) p.push_back(i);
    }

    while (n--) {
        int x;
        cin >> x;
        bool flag = 0;

        for (int i = 0; i < p.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                for (int k = 0; k < p.size(); k++) {
                    if (p[i] + p[j] + p[k] == x) {
                        cout << p[i] << " " << p[j] << " " << p[k] << "\n";
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
    }
}