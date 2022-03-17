#include <bits/stdc++.h>
using namespace std;

int arr[10] = { 0, };
int Page_Start = 1;
long long temp = 1;

void Cal_count(int num) {
    while (num != 0) {
        arr[num % 10] += temp;
        num /= 10;
    }
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
}

int main(void) {
    input();

	int Page_Final;
	cin >> Page_Final;

	while (Page_Start <= Page_Final) {
		while (Page_Start % 10 != 0 && Page_Start <= Page_Final) {
			Cal_count(Page_Start);
			Page_Start++;
		}
		if (Page_Start > Page_Final) break;
		while (Page_Final % 10 != 9 && Page_Start <= Page_Final) {
			Cal_count(Page_Final);
			Page_Final--;
		}
		Page_Start /= 10;
		Page_Final /= 10;

		for (int i = 0; i < 10; i++)
			arr[i] += (Page_Final - Page_Start + 1) * temp;
		temp *= 10;
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
}