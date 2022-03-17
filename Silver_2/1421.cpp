#include <bits/stdc++.h>
using namespace std;

int n, c, w;
long long res = -1;
vector<int> tree;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

int main(void) {

    input();
    cin >> n >> c >> w;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree.push_back(x);
    }
    int mx = *max_element(tree.begin(), tree.end());

    for (int i = 1; i <= mx; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            if (tree[j] >= i) {
                long long piece, div;
                piece = tree[j] / i;
                if (tree[j] % i == 0) div = tree[j] / i - 1;
                else div = tree[j] / i;

                if (piece * w * i - div * c > 0) sum += piece * w * i - div * c;
            }
        }
        res = max(sum, res);
    }
    cout << res;
}