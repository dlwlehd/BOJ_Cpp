#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int a, b, n;
int maxr = -1, maxb = -1;
queue<int> B;
queue<int> R;
queue<char> res;
vector<int> SM;
vector<int> JS;

int orderTime, orderQty;
char check;

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> n;

    for (int i = 0; i < n; i++) {

        cin >> orderTime >> check >> orderQty;
        int cnt = 0;

        if (check == 'B') {
            if (maxb > orderTime) orderTime = maxb;
            for (int j = orderTime; cnt < orderQty; j += a) {
                B.push(j);
                cnt++;
            }
            maxb = orderTime + orderQty * a;
        }

        else {
            if (maxr > orderTime) orderTime = maxr;
            for (int j = orderTime; cnt < orderQty; j += b) {
                R.push(j);
                cnt++;
            }
            maxr = orderTime + orderQty * b;
        }
    }

    while (!B.empty() || !R.empty()) {

        if (B.empty()) {
            while (!R.empty()) {
                res.push('R');
                R.pop();
            }
            break;
        }

        if (R.empty()) {
            while (!B.empty()) {
                res.push('B');
                B.pop();
            }
            break;
        }

        if (B.front() <= R.front()) {
            res.push('B');
            B.pop();
            continue;
        }

        if (R.front() < B.front()) {
            res.push('R');
            R.pop();
            continue;
        }
        
    }

    int i = 1;
    while (!res.empty()) {
        if (res.front() == 'B') {
            SM.push_back(i);
        }
        else JS.push_back(i);
        i++;
        res.pop();
    }

    cout << SM.size() << "\n";
    for (int i = 0; i < SM.size(); i++) {
        cout << SM[i] << " ";
    }
    cout << "\n";
    cout << JS.size() << "\n";
    for (int i = 0; i < JS.size(); i++) {
        cout << JS[i] << " ";
    }
}