#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

vector<int> a(5);

void print() {
    for (int &i: a) cout << i << " ";
    cout << "\n";
}

void debug() {
    freopen("E:\\BOJ_Cpp\\input.txt", "r", stdin);
    freopen("E:\\BOJ_Cpp\\output.txt", "w", stdout);
    freopen("E:\\BOJ_Cpp\\debug.txt", "w", stderr);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    debug();
}

bool isSorted() {
    for (int i = 1; i <= 5; i++) {
        if (a[i - 1] != i) return false;
    }
    return true;
}

int main() {
    input();
    for (int &i: a) cin >> i;
    if (isSorted()) {
        print();
        return 0;
    }
    while (!isSorted()) {
        if (a[0] > a[1]) {
            swap(a[0], a[1]);
            print();
        }

        if (a[1] > a[2]) {
            swap(a[1], a[2]);
            print();
        }

        if (a[2] > a[3]) {
            swap(a[2], a[3]);
            print();
        }

        if (a[3] > a[4]) {
            swap(a[3], a[4]);
            print();
        }
    }
}