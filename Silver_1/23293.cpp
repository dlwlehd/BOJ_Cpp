#include <bits/stdc++.h>
using namespace std;

int t, n;
int item[100002][54];
int pos[100002];
vector<int> Log;
vector<int> block;

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    input();
    cin >> t >> n;
    fill(pos, pos + n + 1, 1);
    for (int i = 1; i <= n; i++) fill(item[i], item[i] + 54, 0);
    
    for (int i = 0; i < t; i++) {
        int num, player, factor;
        char action;
        cin >> num >> player >> action >> factor;
        if (action == 'M') {
            pos[player] = factor;    
        }
        if (action == 'F') {
            if (pos[player] != factor) Log.push_back(num);
            item[player][factor]++;
        }
        if (action == 'C') {
            int factor_a;
            cin >> factor_a;
            if (item[player][factor] == 0 || item[player][factor_a] == 0) Log.push_back(num);
            if (item[player][factor] > 0) item[player][factor]--;
            if (item[player][factor_a] > 0) item[player][factor_a]--;
        }
        if (action == 'A') {
            if (pos[player] != pos[factor]) {
                Log.push_back(num);
                block.push_back(player);
            }
        }
    }
    
    sort(block.begin(), block.end());
    block.erase(unique(block.begin(), block.end()), block.end());
    
    cout << Log.size() << "\n";
    for (int i: Log) cout << i << " ";
    if (Log.size() != 0) cout << "\n";
    cout << block.size();
    if (block.size() != 0) cout << "\n";
    for (int i: block) cout << i << " ";
}