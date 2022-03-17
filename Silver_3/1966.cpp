#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int func(queue<pair<int, int>> q, priority_queue<int> pq, int m) {
	int count = 0;
	// priority_queue는 우선 순위가 제일 높은게 위에 있음
	while (!q.empty()) { 
		int idx = q.front().first; // 현재 제일 앞에 있는 인덱스
		int val = q.front().second; // 현재 제일 앞에 있는 중요도
		q.pop(); // 중요도가 제일 높지 않으면 다음거 비교해야하니깐 일단 pop
		if (pq.top() == val) { // 우선순위 제일 높은거 먼저 출력해야함
			pq.pop(); // 우선순위 제일 높은거니깐 pop
			count++; // 인쇄 순서
			if (idx == m) { // 인쇄 된게 내가 궁금한 문서 m번째 있는거니깐 반복문 종료
				break;
			}
		}
		else {
			q.push(make_pair(idx, val)); // 우선도가 제일 높은게 아니니깐 다시 큐 맨 뒤로 넣어줌
		}
	}

	return count;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	vector<int> result;
	
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			q.push(make_pair(j, x));
			pq.push(x);
		}

		result.push_back(func(q, pq, m));
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result.at(i) << "\n";
	}
}