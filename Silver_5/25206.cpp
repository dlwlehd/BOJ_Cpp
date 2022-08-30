#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

vector<string> grade = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
vector<double> score = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0};

void debug() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    debug();
}

int main() {
    input();
    double finalScore = 0, credit = 0;
    int cnt = 0;

    for (int i = 0; i < 20; i++) {
        string a, c;
        double b;
        cin >> a >> b >> c;

        if (c == "P") continue;

        double converted = score[find(all(grade), c) - grade.begin()];
        finalScore += b * converted;
        credit += b;
        cnt++;
    }

    finalScore /= credit;

    cout << fixed;
    cout.precision(6);
    cout << finalScore;
}