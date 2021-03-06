/*
문제
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.
어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 가입한 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다.
각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.

출력
친구 관계가 생길 때마다, 가입한 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
*/


/*
solution:
string을 숫자로 해싱한 다음
유니온 파인드 이용
*/
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int par[300001], clsrn[300001];
int find(int x) {
	if (par[x] == -1) return x;
	return par[x] = find(par[x]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		unordered_map<string, int> hash;
		int m = 1;
		memset(par, -1, sizeof(par));
		fill(clsrn, clsrn + 300001, 1);
		int f;
		cin >> f;
		while (f--) {
			string a, b;
			cin >> a >> b;
			if (!hash[a]) hash[a] = m++;
			if (!hash[b]) hash[b] = m++;
			int u = find(hash[a]);
			int v = find(hash[b]);
			
			if (u != v) {
				par[u] = v;
				clsrn[v] += clsrn[u];
				clsrn[u] = 0;
			}
			cout << clsrn[v] << '\n';
		}
	}
}