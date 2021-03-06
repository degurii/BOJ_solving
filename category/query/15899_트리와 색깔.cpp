/*
문제
1부터 N까지의 번호가 부여된 N개의 정점과 N-1개의 간선으로 구성된 트리가 있다. 이 트리의 루트는 1번 정점이며, 임의의 한 정점과 다른 정점 사이의 경로가 반드시 한 개 존재한다.
트리의 각 정점은 특정 색깔을 가지고 있다. 편의상 색깔은 1 이상 C 이하의 자연수로 표현된다. 이때, 질의 f(v,c)를 다음과 같이 정의하자.
f(v, c) : 정점 v가 루트인 부트리(sub-tree)에서 색깔이 c 이하인 정점의 개수
M개의 질의 f(vi, ci)가 주어질 때, 각 질의에 대한 답을 계산하는 프로그램을 작성하시오.

입력
첫 번째 줄에 정점의 수를 나타내는 N(1 ≤ N ≤ 2×105), 질의의 개수를 나타내는 M(1 ≤ M ≤ 2×105),
정점의 색깔 종류를 나타내는 C(1 ≤ C ≤ N)가 공백 하나를 사이에 두고 차례로 주어진다.
두 번째 줄에는 각 정점의 색깔을 나타내는 N개의 정수가 공백으로 구분되어 순서대로 주어진다.
첫 번째 수는 1번 정점의 색깔이며, ..., N 번째 수는 N번 정점의 색깔이다.
세 번째 줄부터 N-1개의 줄에 걸쳐서 트리를 이루는 각 간선의 정보가 주어진다.
각 간선의 정보는 해당 간선을 이루는 서로 다른 두 정점의 번호로 구성된다. 각 정점의 번호는 1 이상 N 이하의 자연수이다.
이후, 이어서 M개의 줄에 걸쳐서 i번째 줄에 i번째 질의의 정보 vi, ci가 공백으로 구분되어 주어진다. 
vi는 1 이상 N 이하의 정점 번호를 나타낸다. ci는 1 이상 C 이하의 색깔 정보를 나타낸다.  
출력
M개의 질의에 대한 정답을 모두 더한 뒤, 1,000,000,007로 나눈 나머지를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

struct Node {
	int v = 0;
	Node *left = 0, *right = 0;
} *tree[200001];
int n, m, c;
int colors[300000], numChild[300000], numbering[300000];
vector<int> order;
bool check[300000];
vector<vector<int>> p;

int dfs(int now) {
	if (check[now]) return 0;
	check[now] = true;

	int num = 0;
	for (int next : p[now]) {
		num += dfs(next);
	}
	order.push_back(colors[now]);
	numbering[now] = order.size();
	numChild[now] = num;

	return num + 1;
}
Node* init(Node *prev, int s, int e, int v) {
	if (v < s || e < v) return prev;
	Node *now = new Node;
	if (s == e) {
		now->v = prev->v + 1;
		return now;
	}
	int m = (s + e) / 2;
	if (!prev->left) prev->left = new Node;
	if (!prev->right) prev->right = new Node;
	now->left = init(prev->left, s, m, v);
	now->right = init(prev->right, m + 1, e, v);
	now->v = now->left->v + now->right->v;
	return now;
}
int query(Node *now, int s, int e, int v) {
	if (!now || v < s) return 0;
	if (e <= v)return now->v;
	int m = (s + e) / 2;
	return (query(now->left, s, m, v) % MOD + query(now->right, m + 1, e, v) % MOD) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> c;
	tree[0] = new Node;
	p.resize(n + 1);
	int x;
	for (int i = 1; i < n + 1; i++) {
		cin >> colors[i];
	}
	int y;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1);
	for (int i = 1; i < n + 1; i++) {
		x = order[i - 1];
		tree[i] = init(tree[i - 1], 1, c, x);
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		int b = numbering[x];
		int a = numbering[x] - numChild[x];
		ans += query(tree[b], 1, c, y) - query(tree[a - 1], 1, c, y);
		ans %= MOD;
	}
	cout << ans;
}