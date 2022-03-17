#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> s(14);

int main() {
    while (true) {
        cin >> n;
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            cin >> s[i];

        vector<int> v(6, 1);

        for (int i = 0; i < n - 6; i++)
            v.push_back(0);

        do {
            for (int i = 0; i < v.size(); i++)
                if (v[i] == 1)
                    cout << s[i] << ' ';
            cout << endl;
        } while (prev_permutation(v.begin(), v.end()));

        cout << endl;
    }

    return 0;
}