#include <bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (v).size()
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

struct Photo {
    int idx, name, rec;
};

int n, m;
vector<int> a;
vector<Photo> photo;

bool cmp(Photo a, Photo b) {
    if (a.rec == b.rec) {
        return a.idx < b.idx;
    }
    return a.rec < b.rec;
}

bool res(Photo a, Photo b) {
    return a.name < b.name;
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    input();
    cin >> n >> m;
    a.resize(m);
    for (int& i : a) cin >> i;

    for (int i = 0; i < m; i++) {
        bool flag = 1;
        for (auto& p : photo) {
            if (p.name == a[i]) {
                p.rec++;
                flag = 0;
                break;
            }
        }

        if (flag) {
            Photo x = {i, a[i], 1};
            if (photo.size() < n) {
                photo.push_back(x);
            } else {
                sort(all(photo), cmp);
                photo[0] = x;
            }
        }
    }

    sort(all(photo), res);
    for (auto i : photo) cout << i.name << " ";
}