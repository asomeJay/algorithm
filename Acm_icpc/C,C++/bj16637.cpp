/* ��ȣ �߰��ϱ� */
#include <iostream>
#include <climits>

#define MAX_EXPRESSION 25
#define ARRAY_END 100

using namespace std;

void b_tracking(int index, long long int[],int);
long long int bracket_calculation(long long int operand[], int operators, int index);
long long int total_calculation(long long int operand[]);
void insert_new_value(long long int operand[], int index, long long int sum);

long long int maxi;
long long int stri[MAX_EXPRESSION];

int main(void) {
	int i, j, n_of_string;
	maxi = LLONG_MIN;
	
	scanf("%d", &n_of_string); 
	getchar(); // �� ������ �ϳ� �޾��ݽô�.
	/* ���� �ϳ��� �޾Ƽ� ���ڸ��� ���ڷ� �ٲ㼭 ����ְ�
	  �����ڸ� ���� ����ִ´�. */
	for (i = 0; i < n_of_string; i++) {
		j = getchar();
		if (j != '+' && j != '-' && j != '*') {
			stri[i] = j - '0';
		}
		else {
			stri[i] = j;
		}
	}

	stri[i] = ARRAY_END;

	/*�����ڰ� �ϳ��� �� ������ ���̽� */
	maxi = total_calculation(stri);
	/* �����ڰ� ���Դٸ� ��Ʈ��ŷ�� Ȱ���ؼ� ��� ���̽� �����ϱ� */
	
	for (i = 1; i < n_of_string; i += 2)
		b_tracking(i, stri, n_of_string);
	
	printf("%lld", maxi);

	return 0;
}

void b_tracking(int index, long long int s[], int size) {
	if (size <= 0) return;

	int i;
	long long int now_array[MAX_EXPRESSION];
	long long int bracket_sum, operators, total_sum;

	/* �����ϱ� */
	for (i = 0; i < MAX_EXPRESSION; i++)
		now_array[i] = s[i];

	operators = now_array[index];

	// 1. ��ȣ �ֺ��� �ϳ��� ����Ѵ�.
	bracket_sum = bracket_calculation(now_array, operators, index);

	// 2 ��ȣ ����� �� ����ִ´�. 
	insert_new_value(now_array, index, bracket_sum);

	// 3. ��ü ������ �����Ѵ�.
	total_sum = total_calculation(now_array);

	// 4. ��ü ������ ������ ����� ���� �ְ�� maxi�� �����Ѵ�.
	if (total_sum > maxi) {
		maxi = total_sum;
	}

	// 5. �ٽ� �� Ʈ��ŷ
	for (i = index + 2; i < size - 2; i += 2) {
		b_tracking(i, now_array, size - 2);
	}
}

/* ���� �迭�� operator�� �޾Ƽ� operator �� ���� ����Ѵ�. (��ȣ �Ի��̶� �����ϸ��)*/
long long int bracket_calculation(long long int operand[], int operators, int index) {
	switch (operators) {
	case '+':
		return operand[index - 1] + operand[index + 1];
	case '-':
		return operand[index - 1] - operand[index + 1];
	case '*':
		return (operand[index - 1]) * (operand[index + 1]);
	}
}

long long int total_calculation(long long int operand[]){
	int i;
	long long int finals = operand[0];

	for (i = 1; operand[i] != ARRAY_END; i += 2) {
		switch (operand[i]) {
		case '+':
			finals += operand[i + 1];
			break;
		case '-':
			finals -= operand[i + 1];
			break;
		case '*':
			finals *= operand[i + 1];
			break;
		default:
			break;
		}
	}
	return finals;
}

void insert_new_value(long long int operand[], int index, long long int sum) {
	int i;
	
	for (i = index; operand[i + 2] != ARRAY_END; i++)
		operand[i] = operand[i + 2];

	operand[i] = ARRAY_END;
	operand[index - 1] = sum;
}