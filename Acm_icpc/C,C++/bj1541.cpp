/* �Ҿ���� ��ȣ */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

queue<int> i_q;	//���⿡ ������ �κ����� �־��� ���Դϴ�. 

void take_sub_sum(string);	// �κ��� ���ϴ� function�Դϴ�. 

int	main(void) {
	string in, sub_in;
	size_t start_point, t;
	int sum = 0, minus_point; 

	start_point = minus_point = 0;
	cin >> in;	// input�� �޴� �����Դϴ�. 

	while (1) {
		// find �Լ��� �̿��ؼ� minus�� ��ġ�� ����ϴ�.
		while (minus_point != in.size() && in[minus_point] != '-')
			minus_point++;

		// ���� -�� ��ġ�� npos��� ���� ���� �� ���� -�� ���ٴ� �ǹ��̹Ƿ�
		// �κ����� �����ִ� take_sub_sum()�� Ȱ���մϴ�. 
		if (minus_point == in.size()) {
			sub_in = in.substr(start_point);
//			cout << sub_in << endl;

			take_sub_sum(sub_in);
			break;
		}

		// ���� -�� ��ġ�� �� ���ߴٸ� �� - ��ġ �ձ��� ���ڸ� �����ϰ�
		// �� ���� string�� integer�� ��ȯ�մϴ�.
		sub_in = in.substr(start_point, minus_point-start_point);
//		cout << sub_in << endl;
		minus_point++;
		start_point = minus_point;
		take_sub_sum(sub_in);
	}
	
	/* q�� �ִ� ���ڸ� ���ʴ�� �����鼭 ���� �ּ����� �ϼ��� �� �ֽ��ϴ�. */

	if (!i_q.empty()) {
		sum = i_q.front();
		i_q.pop();
	}

	while (!i_q.empty()) {
		sum -= i_q.front();
		i_q.pop();
	}

	cout << sum << endl;

	return 0;
}

/* �Է¹��� ���ڿ��� '+'�� �������� ������ ��, stoi �Լ��� �̿��ؼ� 
  ������ �ٲ��ݴϴ�. �׸��� �ٲ��� ���� ��� ���ؼ� i_q�� push�մϴ�. */

void take_sub_sum(string expression) {
	int sub_total;
	string parsed_expression, t;
	size_t start_point, plus_position;
	start_point = sub_total = 0;
	parsed_expression = expression;

	while (1) {
		// 1. find �Լ��� ���ؼ� '+'�� ��ġ�� ã���ϴ�.
		plus_position = parsed_expression.find("+", start_point);

		// 2. find()�� npos�� return �ߴٸ� ���� ���� ���Դϴ�. 
		// �׷��� ���� string�� ��� integer�� �ٲ㼭 ���ݱ��� ������ sub_total��
		// ���ϰ�, �̸� i_q�� push�մϴ�. �׸��� return �մϴ�.

		if (plus_position == string::npos) {
			t = parsed_expression.substr(start_point);
			sub_total += stoi(t);
			i_q.push(abs(sub_total));
			return;
		}

		// substr()�� �̿��ؼ� '+'�� �������� ���� ���� string�� ����ϴ�.
		// �� �� stoi()�� �̿��ؼ� �� ���� integer�� �ٲ��ݴϴ�.
		t = parsed_expression.substr(start_point, plus_position);
		start_point = plus_position + 1;
		sub_total += stoi(t);
	}
}