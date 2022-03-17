#include <bits/stdc++.h>
using namespace std;

int n, w, l, res = 0;
deque<pair<int, int>> bridge;
deque<int> truck;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

void passing() {
    for (int i = 0; i < bridge.size(); i++) {
        bridge[i].first--;
        if (bridge[i].first == 0) {
            bridge.erase(bridge.begin() + i);
            i--;
        }
    }
}

int bridge_size() {
    int tot = 0;
    for (int i = 0; i < bridge.size(); i++)
        tot += bridge[i].second;
    return tot;
}

int main(void) {
    input();
    cin >> n >> w >> l;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        truck.push_back(x);
    }

    while (true) {
        int tot = bridge_size();

        if (truck.empty()) {
            if (bridge.empty()) break;
            passing();
            res++;
        }
        else {
            tot += truck.front();
            if (bridge.size() == w || tot > l) {
                passing();
                int c = bridge_size();
                c += truck.front();
                if (bridge.size() == w || c > l) {
                    res++;
                    continue;
                }
                bridge.push_back({ w, truck[0] });
                truck.pop_front();
                res++;
            }
            else {
                passing();
                bridge.push_back({ w, truck[0] });
                truck.pop_front();
                res++;
            }
        }
    }
    cout << res;
}