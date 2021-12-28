#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 7 // ���� ť
#define MAX_NAME_SIZE 30 // ȯ�� �̸��� �ִ�ũ��

typedef struct {
	char name[MAX_NAME_SIZE];
}patient;

int rear = 0, front = 0;

int main(void)
{
	patient queue[MAX_QUEUE_SIZE]; // ���� ť ����
	int select; // ������� �Է��� ���� ����

	// ���� ���� �Է±��� �ݺ�
	while (1) {
		printf("\n�Է´��\n1. ���� ����\n2. ���� ����\n3. ���� ����\n");
		scanf("%d", &select);

		if (select == 1) {
			rear = (rear + 1) % MAX_QUEUE_SIZE;

			if (rear == front) { // ��ȭ����
				printf("Service is not available\n");
				
				if (rear == 0) // (rear + 1) % MAX_QUEUE_SIZE ���� �� ť�� ��ȭ���°� �Ǿ��ٸ�,
					rear = 6;  // rear�� ���� ������ �������� ȯ�� ����� �� �� ���µ��� rear�� �����ϴ� ��츦 ������ �� ����
				else
					rear--;
			}

			else { // ��ȭ���� �ƴ�
				printf("\n1.����� ���\n2.���\n");
				scanf("%d", &select);
				
				if (select == 1) { // ȯ�� �̸��� �Է��Ͽ� Enqueue
					printf("�̸� �Է�: ");
					scanf("%s", queue[rear].name);
				}

				else if (select == 2) { // ȯ�� ����� ��������Ƿ� rear�� ������ 1�� �ٽ� ���� �ݺ�
					rear--;
					continue;
				}

				else { // �Է� ���� ó��
					printf("�Է� ����\n");
					return -1;
				}
			}
		}

		else if (select == 2) {
			if (rear == front) // ť�� �������
				printf("There is no patient waiting.\n");

			else {
				front = (front + 1) % MAX_QUEUE_SIZE; // ť�� ������� �������� front�� 1 ������
				printf("ȯ��: %s\n", queue[front].name); // ȯ���� �̸��� ��ȯ(���)�ϴ� Dequeue
			}
		}

		else if (select == 3) { // ���� ���� ó��
			printf("����\n");
			return 0;
		}

		else { // �Է� ���� ó��
			printf("�Է� ����\n");
			return 0;
		}
	}

	return 0;
}