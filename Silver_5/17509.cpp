#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> problem(11);

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("C:\\Users\\CKIRUser\\CLionProjects\\untitled\\input.txt", "r", stdin);
}

bool cmp(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else return a.first < b.first;
};

int main() {

    input();
    for (int i = 0; i < 11; i++) {
        cin >> problem[i].first >> problem[i].second;
    }

    sort(problem.begin(), problem.end(), cmp);
    int times = problem[0].first;
    int penalty = times + problem[0].second * 20;

    for (int i = 1; i < 11; i++) {
        times += problem[i].first;
        penalty += times + 20 * problem[i].second;
    }
    cout << penalty;
}