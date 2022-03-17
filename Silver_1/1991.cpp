#include <bits/stdc++.h>

using namespace std;

void input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

bool vis[26];
int leftChild[26], rightChild[26];

void preorder(int current) {
    if (current == -1) return;
    cout << (char) (current + 'A');
    preorder(leftChild[current]);
    preorder(rightChild[current]);
}

void inorder(int current) {
    if (current == -1) return;
    inorder(leftChild[current]);
    cout << (char) (current + 'A');
    inorder(rightChild[current]);
}

void postorder(int current) {
    if (current == -1) return;
    postorder(leftChild[current]);
    postorder(rightChild[current]);
    cout << (char) (current + 'A');
}

int main() {
    input();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        leftChild[a - 'A'] = (b == '.' ? -1 : b - 'A');
        rightChild[a - 'A'] = (c == '.' ? -1 : c - 'A');
    }

    fill(vis, vis + 26, 0);
    preorder(0);
    cout << "\n";
    fill(vis, vis + 26, 0);
    inorder(0);
    cout << "\n";
    fill(vis, vis + 26, 0);
    postorder(0);
}