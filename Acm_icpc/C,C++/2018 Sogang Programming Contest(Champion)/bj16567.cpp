#include <iostream>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#define DIRTY 1
#define CLEAN 0
#define SHOUT 0
#define MAKEDIRT 1
using namespace std;

int main(void) {
	int numKan, numSi, start, flag, i, numInitial;
	cin >> numKan >> numSi;

	int* arrKan = (int*)malloc(sizeof(int) * numKan);

	// ĭ�� ä��� ����
	flag = 0;
	for (i = 0; i < numKan; i++) {
		scanf("%d", arrKan + i);
	}

	//��� û���ؾ��ϴ� �� üũ�ϴ� ����
	flag = 0; numInitial = 0; start = 0;
	for (i = 0; i < numKan; i++) {
		if ((arrKan[i] == DIRTY) && (flag == 0)) {
			numInitial++;
			flag = 1;
		}
		if (arrKan[i] == CLEAN) {
			flag = 0;
		}
	}
		
	//��ɾ� �޾Ƶ��̴� ���� SHOUT �� MAKEDIRT
	int inst, inst__;
	for (i = 0; i < numSi; i++) {
		scanf("%d", &inst);
		if (inst == SHOUT)
			printf("result : %d\n", numInitial);

		if (inst == MAKEDIRT) {
			scanf("%d", &inst__);
			inst__--;

			if (arrKan[inst__] == DIRTY)
				continue;

			arrKan[inst__] = DIRTY;

			if (inst__ - 1 < 0) {
				if (arrKan[inst__ + 1] != DIRTY)
					numInitial++;
				continue;
			}
		

		else if ((inst__ + 1) >= numKan) {
			if (arrKan[inst__ - 1] != DIRTY) {
				numInitial--;
				continue;
			}
		}
		else {
				if ((arrKan[inst__ - 1] == DIRTY) && (arrKan[inst__ + 1] == DIRTY))
					numInitial--;

				else if ((arrKan[inst__ - 1] == DIRTY) || (arrKan[inst__ + 1] == DIRTY))
					continue;

				else
					numInitial++;
			}
		}
	}
	return 0;
}