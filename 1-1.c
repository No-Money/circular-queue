#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 7 // 원형 큐
#define MAX_NAME_SIZE 30 // 환자 이름의 최대크기

typedef struct {
	char name[MAX_NAME_SIZE];
}patient;

int rear = 0, front = 0;

int main(void)
{
	patient queue[MAX_QUEUE_SIZE]; // 원형 큐 생성
	int select; // 사용자의 입력을 받을 변수

	// 서비스 종료 입력까지 반복
	while (1) {
		printf("\n입력대기\n1. 병원 도착\n2. 병원 퇴장\n3. 서비스 종료\n");
		scanf("%d", &select);

		if (select == 1) {
			rear = (rear + 1) % MAX_QUEUE_SIZE;

			if (rear == front) { // 포화상태
				printf("Service is not available\n");
				
				if (rear == 0) // (rear + 1) % MAX_QUEUE_SIZE 연산 후 큐가 포화상태가 되었다면,
					rear = 6;  // rear를 연산 전으로 돌려놔야 환자 등록을 할 수 없는데도 rear가 증가하는 경우를 방지할 수 있음
				else
					rear--;
			}

			else { // 포화상태 아님
				printf("\n1.대기자 등록\n2.취소\n");
				scanf("%d", &select);
				
				if (select == 1) { // 환자 이름을 입력하여 Enqueue
					printf("이름 입력: ");
					scanf("%s", queue[rear].name);
				}

				else if (select == 2) { // 환자 등록을 취소했으므로 rear에 증가된 1을 다시 빼고 반복
					rear--;
					continue;
				}

				else { // 입력 오류 처리
					printf("입력 오류\n");
					return -1;
				}
			}
		}

		else if (select == 2) {
			if (rear == front) // 큐가 비어있음
				printf("There is no patient waiting.\n");

			else {
				front = (front + 1) % MAX_QUEUE_SIZE; // 큐가 비어있지 않을때만 front가 1 증가함
				printf("환자: %s\n", queue[front].name); // 환자의 이름을 반환(출력)하는 Dequeue
			}
		}

		else if (select == 3) { // 서비스 종료 처리
			printf("종료\n");
			return 0;
		}

		else { // 입력 오류 처리
			printf("입력 오류\n");
			return 0;
		}
	}

	return 0;
}