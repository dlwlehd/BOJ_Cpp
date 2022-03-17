#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> price;
vector<int> deliver;
int res = -1;
int p;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        price.push_back(x);
        deliver.push_back(y);
    }
}

int main(void) {

    input();

    int mx = *max_element(price.begin(),price.end());

    for (int i = mx; i >= 0; i--) {
        int sell = i;
        int money = 0;

        for (int j = 0; j < n; j++) {
            if (sell <= price[j] && sell - deliver[j] >= 0) money += sell - deliver[j];
        }

        if (res <= money) {
            res = money;
            p = i;
        }
    }

    res <= 0 ? cout << 0 : cout << p;
}