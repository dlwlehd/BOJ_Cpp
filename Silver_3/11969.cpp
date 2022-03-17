#include <bits/stdc++.h>

using namespace std;
int n, q;
int aCnt[100002] = {0}, bCnt[100002] = {0}, cCnt[100002] = {0};

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

int main() {
    input();
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int a = 0, b = 0, c = 0;
        if (x == 1) a++;
        if (x == 2) b++;
        if (x == 3) c++;

        aCnt[i + 1] = a + aCnt[i];
        bCnt[i + 1] = b + bCnt[i];
        cCnt[i + 1] = c + cCnt[i];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << aCnt[b] - aCnt[a - 1] << " " << bCnt[b] - bCnt[a - 1] << " " << cCnt[b] - cCnt[a - 1] << "\n";
    }
}