/*
����
������ <br>, <hr> �±׿� �� �� �����θ� �־����� HTML ������ ���� ��, �� ����� �����ִ� �ڵ带 �ۼ��Ͻÿ�.
�� �ٿ��� 80�ں��� ���� ���ڰ� ��µǾ�� �� �ȴ�.

�Է�
������ HTML ������ �Է����� �־�����. �� �ؽ�Ʈ�� �ܾ�� HTML �±׵�� �̷���� ������, �±״� �� �� �̻��� ���鹮�ڳ� ��, ���� ���� ������ ���еȴ�.
�ܾ�� ���ӵ� ���ĺ�, ����, �Ǵ� ���� ��ȣ���̴�. ���� ���, "abc,123"�� �ϳ��� �ܾ�������, "abc, 123"�� "abc,", "123" �� �ܾ��̴�. �ܾ�� �׻� 80���� �����̸�, '<'�� '>'�� �������� �ʴ´�. �Է¿� �����ϴ� �±״� <br>�� <hr> �ܿ��� ����.

���
������ ���� ��Ģ�� �°� ����ؾ� �Ѵ�.

�̹��� ����� �ܾ ����ϰ� ������ ���� ���� 80���ڸ� ���� ������ ���� �ٿ� ����ص� ����. ��, 80���ڸ� �Ѿ�� �ȴٸ� ���ο� �ٿ� ����ؾ� �Ѵ�.
<br> �±׸� �а� �Ǹ�, �� ���� �����Ѵ�.
<hr> �±׸� �а� �Ǹ�, �̹� ���� ù �κ��� �ƴ϶�� �� ���� ������ ��, '-'�� �� �ٿ� 80���ڸ� �Է��Ѵ�. �� �� �ٽ� �� ���� �����Ѵ�.
������ ���� ���� ���ڷ� ������.

���� ���� ���ӵ� ���� ����, ���� ����, �� ���ڴ� �ϳ��� ���鹮�ڷ� ����Ѵ�.
*/
#include <iostream>
#include <string>
using namespace std;

string word, pre;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> word) {
		if (word[0] == '<') {
			if (word[1] == 'b')
				cout << '\n';
			else {
				if (!(pre == "" || pre[0] == '<'))
					cout << '\n';
				for (int i = 0; i < 80; i++)
					cout << '-';
				cout << '\n';
			}
		}
		else
			cout << word << ' ';
		pre = word;
	}
}