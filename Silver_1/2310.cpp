#include <bits/stdc++.h>

using namespace std;

vector<int> rooms;
vector<vector<int>> doors;
vector<int> temp;
vector<bool> visited;

bool reach_n = false;
int n;
void dfs(int now, int money){
	if(rooms[now]>=0){
		if(rooms[now]>money){
			money = rooms[now];
		}
	}
	else{
		money = rooms[now]+money;
		if(money<0){
			return;
		}
	}
	visited[now] = true;
	if(now == n){
		cout<< "Yes\n";
		reach_n = true;
	}
	else {
		for(int i = 0; i < doors[now].size(); i++) {
			if(visited[doors[now][i]]==false)
				dfs(doors[now][i],money);
		}
	}
	return;
}

int main() {
	while(1){
		int now, money;
		now = 1; money = 0;
		cin >> n;
		if(n == 0) break;
		rooms.clear();
		rooms.push_back(0);
		doors.clear();
		temp.clear();
		doors.push_back(temp);
		
		char kind; 
		int reward = 0; 
		for(int i = 1; i<=n; i++){
			cin >> kind;
			if(kind == 'E' || kind == 'L') {
				cin >> reward;
				rooms.push_back(reward);
				int next_room = 1;
				temp.clear();
				while(1){
					cin >> next_room;
					if(next_room == 0)
						break;
					temp.push_back(next_room);
				}
				doors.push_back(temp);
			}
			else {
				cin >> reward;
				rooms.push_back(reward * (-1));
				int next_room = 1;
				temp.clear();
				while(1) {
					cin >> next_room;
					if(next_room == 0) break;
					temp.push_back(next_room);
				}
				doors.push_back(temp);
			}
		}
        
		visited.clear();
		for(int i = 0; i <= n; i++){
			visited.push_back(false);
		}
		reach_n = false;
		dfs(now, money);
		if(reach_n == false){
			cout << "No\n";
		}
	}
	return 0;
}
