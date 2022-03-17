#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool deleted[50];
vector<int> graph[50];
int answer = 0;
int n;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\output.txt", "w", stdout);
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        deleted[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (deleted[next]) continue;
            q.push(next);
        }
    }
}


int main() {
    input();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == -1) {
            continue;
        }
        graph[num].push_back(i);
    }
    int delete_num;
    cin >> delete_num;

    bfs(delete_num);
    for (int i = 0; i < n; i++) {
        if (!deleted[i]) {
            int j = -1;
            for (j = 0; j < graph[i].size(); j++) {
                if (!deleted[graph[i][j]]) break;
            }
            if (j == graph[i].size()) answer++;
        }
    }
    cout << answer;
    return 0;

}