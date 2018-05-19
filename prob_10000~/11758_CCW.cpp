/*
문제
2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 P1의 (x1, y1), 둘째 줄에 P2의 (x2, y2), 셋째 줄에 P3의 (x3, y3)가 주어진다.
(-10,000 ≤ x1, y1, x2, y2, x3, y3 ≤ 10,000) 모든 좌표는 정수이다. P1, P2, P3의 좌표는 서로 다르다.

출력
P1, P2, P3를 순서대로 이은 선분이 반시계 방향을 나타내면 1, 시계 방향이면 -1, 일직선이면 0을 출력한다.
*/

/*
solution:
외적의 결과에 따라
CCW, CW, 일직선을 판별할 수 있따
*/
#include <iostream>
using namespace std;


int main() {
	int x1, x2, x3, y1, y2, y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int val = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
	if (val > 0)
		cout << 1;
	else if (val < 0)
		cout << -1;
	else
		cout << 0;
}