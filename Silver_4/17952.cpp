#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int t, hw, score, m;
int sum = 0;
stack <pair<int, int>> s; // m, score

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> hw;
        if (hw == 0) {
            if (!s.empty()) {
                auto cur = s.top();

                cur.X--;
                if (cur.X == 0) {
                    sum += cur.Y;
                    s.pop();
                }
                else {
                    s.pop();
                    s.push({ cur.X,cur.Y });
                }
            }
            continue;
        }

        cin >> score >> m;
        if (m == 1) {
            sum += score;
            continue;
        }

        s.push({ m - 1,score });
    }

    cout << sum;
}