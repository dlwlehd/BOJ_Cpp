#include <bits/stdc++.h>
using namespace std;

int n;
int competitor1, competitor2;

int getRound() {
    int round = 1;

    while (n) {
        if ((competitor1 + 1) / 2 == (competitor2 + 1) / 2)
            break;

        competitor1 = (competitor1 + 1) / 2;
        competitor2 = (competitor2 + 1) / 2;
        round += 1;
        n /= 2;
    }

    if (!n) return -1;
    return round;
}

int main(void)

{
    cin >> n;
    cin >> competitor1 >> competitor2;

    cout << getRound();
    return 0;
}