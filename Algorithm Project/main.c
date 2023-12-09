#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택(엔터키)
#define DELETE 5 // 전 화면 이동
#define red SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
#define blue SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
#define black SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#define SWAP(x, y) { int temp = x; x = y; y = temp; }
HANDLE hConsole;


/* 함수 선언 */
void init();
void titleDraw();
void CursorView(int);
void gotoxy(int, int);
int menuDraw();
int keyControl();
int ChooseDraw();
void Bubble_Sort();
void BubbleSwap(int, int);
void Selection_Sort();
void SelectionSwap(int, int);
void block_show(int, int);
void Insertion_Sort();
void swapAndShow(int*, int, int);
void number_show(int, int, int);
void merge(int*, int, int, int);
void merge_sort(int*, int, int, int);
void merge_swap(int*, int, int);
void Merge_Sort();
void quick_sort(int, int, int, int);
void Quick_Sort();
void shell_Sort(int, int);
void Shell_Sort();
void heapify(int, int, int);
void heapSort(int, int);
void Heap_Sort();
int findMax(int, int);
void radixSort(int, int);
void Radix_Sort();
void Depth_First_Search();
void Breadth_first_search();
void Kruskal_Algorithm();
void Prims_Algorithm();
void Topological_sort();
void AStar_Algorithm();
void Genetic_Algorithm();
void State_Space_Search();

# define MAX_SIZE 20
int sorted[MAX_SIZE];
#define MAX_VERTICES 100
#define MAX_EDGES 100
#define INF INT_MAX


/* 함수 구현 */

int previoustitleScreen() {
	system("cls"); // 화면 지우기
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// 정복하기
			int ChooseNum = ChooseDraw();
			int x = ChooseNum / 100;
			int y = ChooseNum % 100;
			if (x == 10) {
				if (y == 0) {
					Bubble_Sort();
				}
			}
			else if (x == 45) {
				if (y == 0) {
					Depth_First_Search();
				}
			}

			if (x == 10) {
				if (y == 2) {
					Selection_Sort();
				}
			}
			else if (x == 45) {
				if (y == 2) {
					Breadth_first_search();
				}
			}

			if (x == 10) {
				if (y == 4) {
					Insertion_Sort();
				}
			}
			else if (x == 45) {
				if (y == 4) {
					Kruskal_Algorithm();
				}
			}

			if (x == 10) {
				if (y == 6) {
					Merge_Sort();
				}
			}
			else if (x == 45) {
				if (y == 6) {
					Prims_Algorithm();
				}
			}

			if (x == 10) {
				if (y == 8) {
					Quick_Sort();
				}
			}
			else if (x == 45) {
				if (y == 8) {
					Topological_sort();
				}
			}

			if (x == 10) {
				if (y == 10) {
					Shell_Sort();
				}
			}
			else if (x == 45) {
				if (y == 10) {
					AStar_Algorithm();
				}
			}


			if (x == 10) {
				if (y == 12) {
					Heap_Sort();
				}
			}
			else if (x == 45) {
				if (y == 12) {
					Genetic_Algorithm();
				}
			}


			if (x == 10) {
				if (y == 14) {
					Radix_Sort();
				}
			}
			else if (x == 45) {
				if (y == 14) {
					State_Space_Search();
				}
			}



		}
		else if (menuCode == 20) {
			// 나가기
			exit(0);

		}
	}
}


void previousmenuScreen() {

	while (1) {
		CursorView(0);
		int ChooseNum = ChooseDraw();
		int x = ChooseNum / 100;
		int y = ChooseNum % 100;
		if (x == 10) {
			if (y == 0) {
				Bubble_Sort();
			}
		}
		else if (x == 45) {
			if (y == 0) {
				Depth_First_Search();
			}
		}

		if (x == 10) {
			if (y == 2) {
				Selection_Sort();
			}
		}
		else if (x == 45) {
			if (y == 2) {
				Breadth_first_search();
			}
		}

		if (x == 10) {
			if (y == 4) {
				Insertion_Sort();
			}
		}
		else if (x == 45) {
			if (y == 4) {
				Kruskal_Algorithm();
			}
		}

		if (x == 10) {
			if (y == 6) {
				Merge_Sort();
			}
		}
		else if (x == 45) {
			if (y == 6) {
				Prims_Algorithm();
			}
		}

		if (x == 10) {
			if (y == 8) {
				Quick_Sort();
			}
		}
		else if (x == 45) {
			if (y == 8) {
				Topological_sort();
			}
		}

		if (x == 10) {
			if (y == 10) {
				Shell_Sort();
			}
		}
		else if (x == 45) {
			if (y == 10) {
				AStar_Algorithm();
			}
		}


		if (x == 10) {
			if (y == 12) {
				Heap_Sort();
			}
		}
		else if (x == 45) {
			if (y == 12) {
				Genetic_Algorithm();
			}
		}


		if (x == 10) {
			if (y == 14) {
				Radix_Sort();
			}
		}
		else if (x == 45) {
			if (y == 14) {
				State_Space_Search();
			}
		}
		system("cls");
	}

	ChooseDraw();

}

void sidebar() {
	int x = 0, y = 0;
	gotoxy(x + 100, y + 47);
	printf("    진행: ENTER \n");
	gotoxy(x + 100, y + 48);
	printf("뒤로가기: DELETE");
}

void gsidebar() {
	int x = 0, y = 0;
	gotoxy(x + 134, y + 47);
	printf("    진행: ENTER \n");
	gotoxy(x + 134, y + 48);
	printf("뒤로가기: DELETE");
}
void number_show(int x, int y, int arr) {
	gotoxy(x + 3, y + 2);
	printf("%d", arr);
}

void block_show(int x, int y) {
	gotoxy(x, y);
	printf("-------\n");
	gotoxy(x, y + 1);
	printf("|     |\n");
	gotoxy(x, y + 2);
	printf("|     |\n");
	gotoxy(x, y + 3);
	printf("-------\n");
	printf("\n\n\n\n");

}

void init() { //첫 화면 창 크기 조절
	system("mode con cols=120 lines=30 | title ALGORITHM");
	CursorView(0);
}

void titleDraw() { //타이틀 글자 출력
	printf("\n\n\n\n\n");
	printf("\t\t           A      L       GGG      OOO     RRRR    III   TTTTT   H   H    M     M\n");
	printf("\t\t          A A     L      G        O   O    R   R    I      T     H   H    MM   MM\n");
	printf("\t\t         AAAAA    L      G  GG    O   O    RRRR     I      T     HHHHH    M M M M\n");
	printf("\t\t         A   A    L      G   G    O   O    R  R     I      T     H   H    M  M  M\n");
	printf("\t\t        A     A   LLLLL   GGGG     OOO     R   R   III     T     H   H    M     M\n");
	printf("\n\n\n\n\n\n\n\n\n");

	puts("                                     ■■■■■■■■■■■■■■■■■■■■■■■■");
	puts("                                     ■■                                        ■■");
	puts("                                     ■■                                        ■■");
	puts("                                     ■■                                        ■■");
	puts("                                     ■■                                        ■■");
	puts("                                     ■■                                        ■■");
	printf("                                     ■■■■■■■■■■■■■■■■■■■■■■■■");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t이동: ◀▲▼▶");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t선택: Enter");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void CursorView(int visible) //커서 숨기기
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y) { //커서 위치 이동함수
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int menuDraw() {
	int x = 46; // 초기 x 좌표
	int y = 22; // 초기 y 좌표
	gotoxy(x, y); printf("▶ 정복하기"); // 초기 메뉴 항목 1 출력
									// 정보 추가할지 고민해보기
	gotoxy(x + 22, y); printf(" 나가기"); // 초기 메뉴 항목 2 출력

	while (1) {
		int key = keyControl(); // 키보드 입력 받기
		switch (key) {
		case LEFT: {
			if (x == 66 || x == 67) {
				gotoxy(x, y);
				printf("  "); // 화면을 지우고
				x -= 20; // x 좌표를 왼쪽으로 이동
				gotoxy(x, y);
				printf("▶"); // 새로운 위치에 ▶을 표시
			}
			break;
		}
		case RIGHT: {
			if (x == 46 || x == 47) {
				gotoxy(x, y);
				printf("  "); // 화면을 지우고
				x += 20; // x 좌표를 오른쪽으로 이동
				gotoxy(x, y);
				printf("▶"); // 새로운 위치에 ▶을 표시
			}
			break;
		}
		case SUBMIT: {
			return  x - 46; // 엔터를 누르면 메뉴 선택 완료를 나타내는 값 반환 후 함수 종료
		}
		}
		if (key == SUBMIT) {
			break; // 메뉴 선택이 완료되면 루프를 빠져나가도록 추가
		}
	}
}

int keyControl() {
	int key = _getch();
	if (key == 13) { return SUBMIT; }
	else if (key == 72) { //위
		return UP;
	}
	else if (key == 80) { //아래
		return DOWN;
	}
	else if (key == 75) { //좌
		return LEFT;
	}
	else if (key == 77) { //우
		return RIGHT;
	}
	else if (key == 83) {
		return DELETE;
	}

	return -1; // 잘못된 입력을 처리하기 위한 값
}

int ChooseDraw() {
	system("mode con cols=120 lines=30 | title ChooseSort");
	system("cls");

	int x = 10, y = 5;
	gotoxy(x, y); printf("▶ 버블 정렬");
	gotoxy(x, y + 2); printf("   선택 정렬");
	gotoxy(x, y + 4); printf("   삽입 정렬");
	gotoxy(x, y + 6); printf("   병합 정렬");
	gotoxy(x, y + 8); printf("   퀵 정렬");
	gotoxy(x, y + 10); printf("   쉘 정렬");
	gotoxy(x, y + 12); printf("   힙 정렬");
	gotoxy(x, y + 14); printf("   기수 정렬");
	gotoxy(x + 35, y); printf("   깊이 우선 탐색");
	gotoxy(x + 35, y + 2); printf("   너비 우선 탐색");
	gotoxy(x + 35, y + 4); printf("   크루스칼 알고리즘");
	gotoxy(x + 35, y + 6); printf("   프림 알고리즘");
	gotoxy(x + 35, y + 8); printf("   위상 알고리즘");
	gotoxy(x + 35, y + 10); printf("   에이스타 알고리즘");
	gotoxy(x + 35, y + 12); printf("   유전자 알고리즘");
	gotoxy(x + 35, y + 14); printf("   상태공간 알고리즘");
	gotoxy(x + 92, y + 22); printf("    이동: ◀▲▼▶");
	gotoxy(x + 91, y + 23); printf("     선택: ENTER");
	gotoxy(x + 90, y + 24); printf("  뒤로가기: DELETE");

	while (1) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int key = keyControl();// 키보드 입력 받기
		switch (key) {
		case DOWN: {
			if ((x == 44 || x == 45) && y < 19) {
				gotoxy(x, y);
				printf("  "); // 화면을 지우고
				y += 2; // y 좌표를 아래로 이동
				gotoxy(x, y);
				printf("▶"); // 새로운 위치에 ▶을 표시

			}
			else if (x != 45 && y < 19) {
				gotoxy(x, y);
				printf("  "); // 화면을 지우고
				y += 2; // y 좌표를 아래로 이동
				gotoxy(x, y);
				printf("▶"); // 새로운 위치에 ▶을 표시

			}
			break;

		}
		case UP: {
			if (5 < y) {
				gotoxy(x, y);
				printf("  "); // 화면을 지우고
				y -= 2; // y 좌표를 위로 이동
				gotoxy(x, y);
				printf("▶"); // 새로운 위치에 ▶을 표시
			}
			break;
		}
		case RIGHT: {
			if (y == 15 || y == 17 || y == 19) {

				gotoxy(x, y);
				x = 45; y = 13;
				printf("   ");
				gotoxy(x, y);
				printf("▶");

			}
			else if (x < 45) {
				gotoxy(x, y);
				printf("   ");
				x += 35;
				gotoxy(x, y);
				printf("▶");
			}

			break;
		}
		case LEFT: {
			if (x > 10) {
				gotoxy(x, y);
				printf("   ");
				x -= 35;
				gotoxy(x, y);
				printf("▶");
			}
			break;
		}
		case DELETE: {

			previoustitleScreen();
			break;
		}
		case SUBMIT: {
			return 100 * x + y - 5; // 엔터를 누르면 메뉴 선택 완료를 나타내는 값 반환 후 함수 종료
		}
		}
	}
}

void Bubble_Sort() {
	system("mode con cols=120 lines=50 | title Bubble_Sort");
	system("cls");

	printf("\n\n\n");
	puts("\t   BBBB     U    U   BBBB     BBBB     L        EEEEE             SSSSS     OOO    RRRR    TTTTT     ");
	puts("\t   B   B    U    U   B   B    B   B    L        E                S         O   O   R   R     T       ");
	puts("\t   BBBBB    U    U   BBBBB    BBBBB    L        EEEEE             SSSSS    O   O   RRRR      T       ");
	puts("\t   B   B    U    U   B   B    B   B    L        E                      S   O   O   R  R      T       ");
	puts("\t   BBBB      UUUU    BBBB     BBBB     LLLLL    EEEEE             SSSSS     OOO    R   R     T       ");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 1);
	printf("<설명 - 버블정렬>\n");
	gotoxy(x + 30, y + 1);
	printf("서로 인접한 두 원소를 검사하여 자리를 교환하며 정렬하는 알고리즘");
	gotoxy(x + 30, y + 2);
	printf("인접한 처음 두 개의 원소부터 마지막 원소까지 비교하며 자리교환");
	gotoxy(x + 42, y + 3);
	printf("가장 큰 원소가 마지막 자리에 정렬");


	gotoxy(x + 70, y + 10);
	printf("<코드>");
	gotoxy(x + 70, y + 12);
	printf("void bubbleSort(int arr[], int n) {");
	gotoxy(x + 70, y + 13);
	printf("    int temp; ");
	gotoxy(x + 70, y + 14);
	printf("    for (int i = 0; i < n - 1; i++) {");
	gotoxy(x + 70, y + 15);
	printf("        for (int j = 0; j < n - i - 1; j++) {");
	gotoxy(x + 70, y + 16);
	printf("            if (arr[j] > arr[j + 1]) {");
	gotoxy(x + 70, y + 17);
	printf("                temp = arr[j];");
	gotoxy(x + 70, y + 18);
	printf("                arr[j] = arr[j + 1];");
	gotoxy(x + 70, y + 19);
	printf("                arr[j + 1] = temp;");
	gotoxy(x + 70, y + 20);
	printf("            }");
	gotoxy(x + 70, y + 21);
	printf("        }");
	gotoxy(x + 70, y + 22);
	printf("    }");
	gotoxy(x + 70, y + 23);
	printf("}");




	gotoxy(x + 6, y + 10);
	printf("<입력>\n");
	gotoxy(x + 6, y + 12);
	printf("정렬할 개수를 입력하시오 (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // 이전 입력을 지움
		gotoxy(x + 6, y + 12);
		printf("정렬할 개수를 입력하시오 (2~5) : ");
		scanf_s("%d", &n, sizeof(n));
	}
	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 14);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 16);
		scanf_s("%d", &arr[i]);
		x += 6;
	}


	x = 0;
	_getch();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(x + 70, y + 12);
	_getch();
	red;
	printf("void bubbleSort(int arr[], int n) {");
	black;
	Sleep(300);
	gotoxy(x + 70, y + 12);
	printf("void bubbleSort(int arr[], int n) {");
	//
	gotoxy(x + 70, y + 13);
	int temp;
	red;
	printf("    int temp; ");
	black;
	Sleep(300);
	gotoxy(x + 70, y + 13);
	printf("    int temp; ");
	//
	for (int i = 0; i < n - 1; i++) {
		gotoxy(x + 70, y + 14);
		red;
		printf("    for (int i = 0; i < n - 1; i++) {");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 14);
		printf("    for (int i = 0; i < n - 1; i++) {");
		//
		for (int j = 0; j < n - i - 1; j++) {
			gotoxy(x + 70, y + 15);
			red;
			printf("        for (int j = 0; j < n - i - 1; j++) {");
			black;
			Sleep(300);
			gotoxy(x + 70, y + 15);
			printf("        for (int j = 0; j < n - i - 1; j++) {");
			//
			gotoxy(x + 70, y + 16);
			red;
			printf("        if (arr[j] > arr[j + 1]) {");
			black;
			Sleep(300);
			gotoxy(x + 70, y + 16);
			printf("        if (arr[j] > arr[j + 1]) {");
			//
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				gotoxy(x + 70, y + 17);
				red;
				printf("                temp = arr[j];");
				black;
				Sleep(300);
				gotoxy(x + 70, y + 17);
				printf("                temp = arr[j];");
				//
				arr[j] = arr[j + 1];
				gotoxy(x + 70, y + 18);
				red;
				printf("                arr[j] = arr[j + 1];");
				black;
				Sleep(300);
				gotoxy(x + 70, y + 18);
				printf("                arr[j] = arr[j + 1];");
				//
				arr[j + 1] = temp;
				gotoxy(x + 70, y + 19);
				red;
				printf("                arr[j + 1] = temp;");
				black;
				Sleep(300);
				gotoxy(x + 70, y + 19);
				printf("                arr[j + 1] = temp;");
				_getch();
				for (int k = 0; k < n; k++) {
					gotoxy(x + 9, y + 16);
					printf("%d", arr[k]);
					x += 6;
				}
				x = 0;
				BubbleSwap(j, j + 1);


			}
		}
	}
	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}// 더 이상 반복하지 않도록 루프 종료
}

void BubbleSwap(int a, int b) {
	int x = 9;
	int y = 33;
	gotoxy(x, y);
	printf("                                            ");
	gotoxy(x, y + 1);
	printf("                                            ");
	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
	if (a != b) {
		if (a == 0) {
			gotoxy(x, y);
			printf("↑");
			gotoxy(x, y + 1);
			printf(" _____");
			if (b == 1) {
				gotoxy(x + 6, y);
				printf("↑");
				gotoxy(x + 6, y + 1);
				printf("_");
			}
			else if (b == 2) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y);
				printf("↑");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("↑");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 22, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 1) {
			gotoxy(x + 6, y);
			printf("↑");
			gotoxy(x + 6, y + 1);
			printf(" ______");
			if (b == 2) {
				gotoxy(x + 12, y);
				printf("↑");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("↑");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 2) {
			gotoxy(x + 12, y);
			printf("↑");
			gotoxy(x + 12, y + 1);
			printf(" ______");
			if (b == 3) {
				gotoxy(x + 18, y);
				printf("↑");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 3) {
			gotoxy(x + 18, y);
			printf("↑");
			gotoxy(x + 18, y + 1);
			printf(" ______");
			if (b == 4) {
				gotoxy(x + 24, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
	}
}

void Selection_Sort() {
	system("mode con cols=120 lines=50 | title Selection_Sort");
	system("cls");
	printf("\n\n\n");
	puts("   SSSSS    EEEEE   L       EEEEE     CCC   TTTTT  IIIII     OOO     N       N           SSSSS     OOO    RRRR    TTTTT");
	puts("  S         E       L       E        C        T      I      O   O    N N     N          S         O   O   R   R     T");
	puts("   SSSSS    EEEEE   L       EEEEE   C         T      I      O   O   N   N   N           SSSSS     O   O   RRRR      T");
	puts("        S   E       L       E        C        T      I      O   O    N     N N                S   O   O   R  R      T");
	puts("   SSSSS    EEEEE   LLLLL   EEEEE     CCC     T    IIIII     OOO     N       N           SSSSS     OOO    R   R     T");
	printf("                                                                                    ");
	printf("");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 1);
	printf("<설명 - 선택정렬>\n");
	gotoxy(x + 30, y + 1);
	printf("전체 원소 중 기준 위치에 맞는 원소를 선택해 교환하는 알고리즘");
	gotoxy(x + 20, y + 2);
	printf("전체 원소 중 가장 작은 원소를 찾은 다음 자리 교환, 둘째로 작은 원소 찾고 자리교환");
	gotoxy(x + 32, y + 3);
	printf("같은 방식으로 정렬 후 가장 큰 원소가 마지막 자리에 정렬");


	gotoxy(x + 70, y + 10);
	printf("<코드>");
	gotoxy(x + 70, y + 12);
	printf("void selectionSort(int arr[], int n) {");
	gotoxy(x + 70, y + 13);
	printf("   int i, j, min, minIdx, temp;");
	gotoxy(x + 70, y + 14);
	printf("   for (i = 0; i < n-1; i++) {");
	gotoxy(x + 70, y + 15);
	printf("   min = 99;");
	gotoxy(x + 70, y + 16);
	printf("   for (j = i; j < n-1; j++) {");
	gotoxy(x + 70, y + 17);
	printf("       if (arr[j] < min) {");
	gotoxy(x + 70, y + 18);
	printf("            min = arr[j];");
	gotoxy(x + 70, y + 19);
	printf("            minIdx = j;");
	gotoxy(x + 70, y + 20);
	printf("        }");
	gotoxy(x + 70, y + 21);
	printf("    }");
	gotoxy(x + 70, y + 22);
	printf("    temp = arr[minIdx];");
	gotoxy(x + 70, y + 23);
	printf("    arr[minIdx] = arr[i];");
	gotoxy(x + 70, y + 24);
	printf("     arr[i] = temp;");
	gotoxy(x + 70, y + 25);
	printf("}");



	gotoxy(x + 6, y + 10);
	printf("<입력>\n");
	gotoxy(x + 6, y + 12);
	printf("정렬할 개수를 입력하시오 (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // 이전 입력을 지움
		gotoxy(x + 6, y + 12);
		printf("정렬할 개수를 입력하시오 (2~5) : ");
		scanf_s("%d", &n, sizeof(n));
	}
	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 14);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 16);
		scanf_s("%d", &arr[i]);
		x += 6;
	}

	x = 0;
	gotoxy(x + 70, y + 12);
	_getch();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int i, j, min, minIdx, temp;
	gotoxy(x + 70, y + 13);
	red;
	printf("   int i, j, min, minIdx, temp;");
	black;
	Sleep(300);
	gotoxy(x + 70, y + 13);
	printf("   int i, j, min, minIdx, temp;");
	for (i = 0; i < n - 1; i++) {
		gotoxy(x + 70, y + 14);
		red;
		printf("   for (i = 0; i < n-1; i++) {");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 14);
		printf("   for (i = 0; i < n-1; i++) {");

		min = 99;
		gotoxy(x + 70, y + 15);
		red;
		printf("   min = 99;");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 15);
		printf("   min = 99;");

		for (j = i; j < n; j++) {

			gotoxy(x + 70, y + 16);
			red;
			printf("   for (j = i; j < n-1; j++) {");
			black;
			Sleep(300);
			gotoxy(x + 70, y + 16);
			printf("   for (j = i; j < n-1; j++) {");
			if (arr[j] < min) {
				gotoxy(x + 70, y + 17);
				red;
				printf("       if (arr[j] < min) {");
				black;
				Sleep(300);
				gotoxy(x + 70, y + 17);
				printf("       if (arr[j] < min) {");

				min = arr[j];
				gotoxy(x + 70, y + 18);
				red;
				printf("            min = arr[j];");
				black;
				Sleep(300);
				gotoxy(x + 70, y + 18);
				printf("            min = arr[j];");

				minIdx = j;
				gotoxy(x + 70, y + 19);
				red;
				printf("            minIdx = j;");
				black;
				Sleep(300);
				gotoxy(x + 70, y + 19);
				printf("            minIdx = j;");
			}
			gotoxy(x + 70, y + 20);
			red;
			printf("        }");
			black;
			Sleep(300);
			gotoxy(x + 70, y + 20);
			printf("        }");

		}
		gotoxy(x + 70, y + 21);
		red;
		printf("    }");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 21);
		printf("    }");



		temp = arr[minIdx];
		gotoxy(x + 70, y + 22);
		red;
		printf("    temp = arr[minIdx];");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 22);
		printf("    temp = arr[minIdx];");

		arr[minIdx] = arr[i];
		gotoxy(x + 70, y + 23);
		red;
		printf("    arr[minIdx] = arr[i];");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 23);
		printf("    arr[minIdx] = arr[i];");

		arr[i] = temp;
		gotoxy(x + 70, y + 24);
		red;
		printf("    arr[i] = temp;");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 24);
		printf("    arr[i] = temp;");
		for (int i = 0; i < n; i++) {
			gotoxy(x + 9, y + 16);
			printf("%d", arr[i]);
			x += 6;
		}
		x = 0;
		SelectionSwap(minIdx, i);

		Sleep(300);
		_getch();

	}
	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}
}

void SelectionSwap(int a, int b) { // 여기서부터 시작
	int x = 9;
	int y = 33;
	gotoxy(x, y);
	printf("                                            ");//초기화
	gotoxy(x, y + 1);
	printf("                                            ");//초기화
	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
	if (a != b) {
		if (a == 0) {
			gotoxy(x, y);
			printf("↑");
			gotoxy(x, y + 1);
			printf(" _____");
			if (b == 1) {
				gotoxy(x + 6, y);
				printf("↑");
				gotoxy(x + 6, y + 1);
				printf("_");
			}
			else if (b == 2) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y);
				printf("↑");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("↑");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 22, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 1) {
			gotoxy(x + 6, y);
			printf("↑");
			gotoxy(x + 6, y + 1);
			printf(" ______");
			if (b == 2) {
				gotoxy(x + 12, y);
				printf("↑");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("↑");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 2) {
			gotoxy(x + 12, y);
			printf("↑");
			gotoxy(x + 12, y + 1);
			printf(" ______");
			if (b == 3) {
				gotoxy(x + 18, y);
				printf("↑");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 3) {
			gotoxy(x + 18, y);
			printf("↑");
			gotoxy(x + 18, y + 1);
			printf(" ______");
			if (b == 4) {
				gotoxy(x + 24, y);
				printf("↑");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
	}
}

void Insertion_Sort() {
	system("mode con cols=120 lines=50 | title Insertion_Sort()");
	system("cls");
	printf("\n\n\n");
	puts("  IIIII   N    N    SSSSS    EEEEE   RRRRR    TTTTT   IIIII    OOO     N    N        SSSSS      OOO     RRRRR    TTTTT ");
	puts("    I     N N  N   S         E       R    R     T       I     O   O    N N  N       S          O   O    R    R     T   ");
	puts("    I     N  N N    SSSSS    EEEEE   RRRRR      T       I     O   O    N  N N        SSSSS     O   O    RRRRR      T   ");
	puts("    I     N   NN         S   E       R    R     T       I     O   O    N   NN             S    O   O    R    R     T   ");
	puts("  IIIII   N    N    SSSSS    EEEEE   R     R    T     IIIII    OOO     N    N        SSSSS      OOO     R     R    T   ");
	printf("                                                                                    ");
	printf("");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 1);
	printf("<설명 - 선택정렬>\n");
	gotoxy(x + 30, y + 1);
	printf("한 번에 한 개씩 적당한 위치를 찾아 삽입·배치하는 알고리즘");
	gotoxy(x + 30, y + 2);
	printf("두 번째 값을 기준, 첫 번째 값과 비교하여 순서대로 나열한다.");
	gotoxy(x + 15, y + 3);
	printf("같은 방법으로 n번째 값을 n-1 값과 비교하고, 삽입할 적당한 위치를 찾아 삽입하며 정렬한다.");


	gotoxy(x + 70, y + 10);
	printf("<코드>");
	gotoxy(x + 70, y + 12);
	printf("void insertionSort(int arr[], int n) {");
	gotoxy(x + 70, y + 13);
	printf("    for (int i = 1; i < n; i++) {");
	gotoxy(x + 70, y + 14);
	printf("        int key = arr[i];");
	gotoxy(x + 70, y + 15);
	printf("        int j = i - 1;");
	gotoxy(x + 70, y + 16);
	printf("        while (j >= 0 && arr[j] > key) {");
	gotoxy(x + 70, y + 17);
	printf("            arr[j + 1] = arr[j];");
	gotoxy(x + 70, y + 18);
	printf("            j = j - 1;");
	gotoxy(x + 70, y + 19);
	printf("        }");
	gotoxy(x + 70, y + 20);
	printf("        arr[j + 1] = key;");
	gotoxy(x + 70, y + 21);
	printf("     }");
	gotoxy(x + 70, y + 22);
	printf("}");



	gotoxy(x + 6, y + 10);
	printf("<입력>\n");
	gotoxy(x + 6, y + 12);
	printf("정렬할 개수를 입력하시오 (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // 이전 입력을 지움
		gotoxy(x + 6, y + 12);
		printf("정렬할 개수를 입력하시오 (2~5) : ");
		scanf_s("%d", &n, sizeof(n));
	}
	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 14);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 16);
		scanf_s("%d", &arr[i]);
		x += 6;
	}

	x = 0;
	gotoxy(x + 70, y + 12);
	_getch();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



	for (int i = 1; i < n; i++) {
		gotoxy(x + 70, y + 13);
		red;
		printf("    for (int i = 1; i < n; i++) {");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 13);
		printf("    for (int i = 1; i < n; i++) {");

		int key = arr[i];
		gotoxy(x + 70, y + 14);
		red;
		printf("        int key = arr[i];");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 14);
		printf("        int key = arr[i];");
		swapAndShow(arr, i, 0);

		int j = i - 1;
		gotoxy(x + 70, y + 15);
		red;
		printf("        int j = i - 1;");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 15);
		printf("        int j = i - 1;");
		while (j >= 0 && arr[j] > key) {
			gotoxy(x + 70, y + 16);
			red;
			printf("        while (j >= 0 && arr[j] > key) {");
			black;
			Sleep(300);
			gotoxy(x + 70, y + 16);
			printf("        while (j >= 0 && arr[j] > key) {");



			arr[j + 1] = arr[j];
			gotoxy(x + 70, y + 17);
			red;
			printf("            arr[j + 1] = arr[j];");
			black;
			Sleep(300);
			gotoxy(x + 70, y + 17);
			printf("            arr[j + 1] = arr[j];");

			j = j - 1;
			gotoxy(x + 70, y + 18);
			red;
			printf("            j = j - 1;");
			black;
			Sleep(300);
			gotoxy(x + 70, y + 18);
			printf("            j = j - 1;");
		}
		gotoxy(x + 70, y + 19);
		red;
		printf("        }");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 19);
		printf("        }");

		swapAndShow(arr, i, 1);
		arr[j + 1] = key;
		gotoxy(x + 70, y + 20);
		red;
		printf("        arr[j + 1] = key;");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 20);
		printf("        arr[j + 1] = key;");
		swapAndShow(arr, j + 1, 0);
		Sleep(900);
		swapAndShow(arr, j + 1, 1);
		gotoxy(x + 70, y + 21);
		red;
		printf("     }");
		black;
		Sleep(300);
		gotoxy(x + 70, y + 21);
		printf("     }");
		for (int i = 0; i < n; i++) {
			gotoxy(x + 9, y + 16);
			printf("%d", arr[i]);
			x += 6;
		}
		x = 0;

		Sleep(300);
		_getch();

	}
	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

void swapAndShow(int* arr, int a, int t) {
	int x = 0, y = 16;
	if (t == 0) {
		red;
	}
	else {
		black;
	}
	gotoxy(x + 9 + (a * 6), y + 15);
	printf("%d", arr[a]);
}

void merge_swap(int* arr, int left, int right) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = left; i <= right; i++) {
		red;
		number_show(6 + (i * 6), 29, arr[i]);
	}
	Sleep(700);
	//_getch();

}
void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 분할 정렬된 list의 합병 */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];

	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];

	}
	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}
void merge_sort(int list[], int left, int right, int n) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int mid;
	int x = 0;
	int y = 15;

	if (left < right) {
		mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		merge_sort(list, left, mid, n); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
		merge_sort(list, mid + 1, right, n);// 뒤쪽 부분 리스트 정렬 -정복(Conquer)
		merge_swap(list, left, right);
		merge(list, left, mid, right);// 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
		merge_swap(list, left, right);
		black;
		for (int i = 0; i < n; i++) {
			gotoxy(x + 9, y + 16);
			printf("%d", list[i]);
			x += 6;
		}
		_getch();

	}
}

void Merge_Sort() {
	system("mode con cols=120 lines=50 | title Merge_Sort()");
	system("cls");
	printf("\n\n\n");
	puts("                M       M   EEEEEE    RRRRR     GGGG    EEEEE         SSSSS     OOOO    RRRRRR    TTTTT  ");
	puts("                MM     MM   E         R    R   G        E            S         O    O   R     R     T    ");
	puts("                M M   M M   EEEEEE    RRRRR    G   GG   EEEEE         SSSSS    O    O   RRRRRR      T    ");
	puts("                M  M M  M   E         R   R    G    G   E                  S   O    O   R    R      T    ");
	puts("                M   M   M   EEEEEE    R    R    GGGG    EEEEE         SSSSS     OOOO    R     R     T    ");
	printf("                                                                                    ");
	printf("");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 4);
	printf("<설명 - 병합정렬>\n");
	gotoxy(x + 46, y - 3);
	printf("분할 정복 알고리즘의 하나");
	gotoxy(x + 35, y - 2);
	printf("입력 배열을 같은 크기의 2개의 부분 배열로 분할한다.");
	gotoxy(x + 17, y - 1);
	printf("부분 배열을 정렬하고 부분 배열의 크기가 충분히 작지 않으면 다시 분할 정복 방법을 적용한다.");
	gotoxy(x + 37, y);
	printf("정렬된 부분 배열들을 하나의 배열에 합병한다");



	gotoxy(x + 60, y + 3);
	printf("<코드>");
	gotoxy(x + 60, y + 4);
	printf("void merge(int list[], int left, int mid, int right){");
	gotoxy(x + 60, y + 5);
	printf("   int i, j, k, l;");
	gotoxy(x + 60, y + 6);
	printf("   i = left;");
	gotoxy(x + 60, y + 7);
	printf("   j = mid+1;");
	gotoxy(x + 60, y + 8);
	printf("   k = left;");
	gotoxy(x + 60, y + 9);
	printf("\n");
	gotoxy(x + 60, y + 10);
	printf("   while(i<=mid && j<=right){");
	gotoxy(x + 60, y + 11);
	printf("      if(list[i]<=list[j])");
	gotoxy(x + 60, y + 12);
	printf("         sorted[k++] = list[i++];");
	gotoxy(x + 60, y + 13);
	printf("");
	gotoxy(x + 60, y + 14);
	printf("      else");
	gotoxy(x + 60, y + 15);
	printf("         sorted[k++] = list[j++]; }");
	gotoxy(x + 60, y + 16);
	printf("");
	gotoxy(x + 60, y + 17);
	printf("   if(i>mid){");
	gotoxy(x + 60, y + 18);
	printf("      for(l=j; l<=right; l++)");
	gotoxy(x + 60, y + 19);
	printf("         sorted[k++] = list[l]; }");
	gotoxy(x + 60, y + 20);
	printf("");
	gotoxy(x + 60, y + 21);
	printf("   else{");
	gotoxy(x + 60, y + 22);
	printf("      for(l=i; l<=mid; l++){");
	gotoxy(x + 60, y + 23);
	printf("         sorted[k++] = list[l]; }");
	gotoxy(x + 60, y + 24);
	printf("");
	gotoxy(x + 60, y + 25);
	printf("   for(l=left; l<=right; l++){");
	gotoxy(x + 60, y + 26);
	printf("      list[l] = sorted[l]; } }");
	gotoxy(x + 60, y + 27);
	printf("\n");
	gotoxy(x + 60, y + 28);
	printf("void merge_sort(int list[], int left, int right){");
	gotoxy(x + 60, y + 29);
	printf("   int mid;");
	gotoxy(x + 60, y + 30);
	printf("      mid = (left+right)/2");
	gotoxy(x + 60, y + 31);
	printf("      merge_sort(list, left, mid);");
	gotoxy(x + 60, y + 32);
	printf("      merge_sort(list, mid+1, right);");
	gotoxy(x + 60, y + 33);
	printf("      merge(list, left, mid, right); } }");




	gotoxy(x + 6, y + 10);
	printf("<입력>\n");
	gotoxy(x + 6, y + 12);
	printf("정렬할 개수를 입력하시오 (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // 이전 입력을 지움
		gotoxy(x + 6, y + 12);
		printf("정렬할 개수를 입력하시오 (2~5) : ");
		scanf_s("%d", &n, sizeof(n));
	}
	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 14);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 16);
		scanf_s("%d", &arr[i]);
		x += 6;
	}
	x = 0, y = 15;
	merge_sort(arr, 0, n - 1, n);
	_getch();
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 16);
		printf("%d", arr[i]);
		x += 6;
	}


	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}
}



int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

						/* low와 high가 교차할 때까지 반복(low<high) */
	do {
		/* list[low]가 피벗보다 작으면 계속 low를 증가 */
		do {
			low++; // low는 left+1 에서 시작
		} while (low <= right && list[low] < pivot);

		/* list[high]가 피벗보다 크면 계속 high를 감소 */
		do {
			high--; //high는 right 에서 시작
		} while (high >= left && list[high] > pivot);

		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
		if (low < high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;

		}
	} while (low < high);
	black;
	// low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	// 피벗의 위치인 high를 반환
	return high;
}



void quick_sort(int list[], int left, int right, int n) {


	if (left < right) {
		int q = partition(list, left, right);

		// Print current state after each partition operation
		printf("\nAfter partition: ", q);
		for (int i = 0; i < n; i++) {
			if (i == q) {
				blue;// Set text color to blue for the pivot element
					 // Implement the logic to change text color based on your environment
			}
			printf("    %d    ", list[i]);
			black;

			// Reset text color to default (black) after printing the element
			// Implement the logic to reset text color based on your environment
		}
		printf("\n");


		quick_sort(list, left, q - 1, n);
		quick_sort(list, q + 1, right, n);

	}


}

void Quick_Sort() {
	system("mode con cols=120 lines=50 | title Quick_Sort()");
	system("cls");
	printf("\n\n\n");
	puts("                       QQQ    U   U   IIIII    CCCC   K   K         SSSSS     OOO    RRRR    TTTTT");
	puts("                      Q   Q   U   U     I     C       K  K         S         O   O   R   R     T ");
	puts("                      Q   Q   U   U     I     C       KK            SSSSS    O   O   RRRR      T   ");
	puts("                      Q  QQ   U   U     I     C       K  K               S   O   O   R   R     T   ");
	puts("                       QQQQ    UUU    IIIII    CCCC   K   K         SSSSS     OOO    R    R    T ");
	puts("                           Q");
	printf("                                                                                    ");
	printf("");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 4);
	printf("<설명 - 퀵 정렬>\n");
	gotoxy(x + 35, y - 3);
	printf(" 분할 정복 방법을 통해 리스트를 정렬하는 알고리즘");
	gotoxy(x + 28, y - 2);
	printf("입력 배열을 피벗을 기준으로 비균등하게 2개의 부분 배열로 분할한다.");
	gotoxy(x + 17, y - 1);
	printf("부분 배열을 정렬하고 부분 배열의 크기가 충분히 작지 않으면 다시 분할 정복 방법을 적용한다.");
	gotoxy(x + 37, y);
	printf("정렬된 부분 배열들을 하나의 배열에 합병한다");

	gotoxy(x + 6, y + 2);
	printf("<입력>");
	gotoxy(x + 14, y + 2);
	blue;
	printf("-- pivot\n");
	gotoxy(x + 6, y + 4);
	black;
	printf("정렬할 개수를 입력하시오 : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));

	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 6);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 8);
		scanf_s("%d", &arr[i]);
		x += 6;
	}
	x = 0, y = 15;
	quick_sort(arr, 0, n - 1, n);

	printf("\n\n\n\nFinal result: ");
	for (int i = 0; i < n; i++) {
		printf("       %d ", arr[i]);
	}
	printf("\n");


	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

void shell_Sort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j;
			printf("\n      After: ");
			for (int k = 0; k < n; k++) {
				if (k == i || k == i - gap) {
					if (arr[k] != temp) {

						printf("%d ", arr[k]);

					}
					else {
						printf("%d ", arr[k]);
					}
				}
				else {
					printf("%d ", arr[k]);
				}
			}
			printf("\n");
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}


void Shell_Sort() {
	system("mode con cols=120 lines=50 | title Shell_Sort()");
	system("cls");
	printf("\n\n\n");
	puts("                      SSSSS    H    H   EEEEEE   L       L              SSSSS     OOO    RRRR    TTTTT");
	puts("                     S         H    H   E        L       L             S         O   O   R   R     T ");
	puts("                      SSSSS    HHHHHH   EEEEEE   L       L              SSSSS    O   O   RRRR      T   ");
	puts("                           S   H    H   E        L       L                   S   O   O   R   R     T   ");
	puts("                      SSSSS    H    H   EEEEEE   LLLLL   LLLLL          SSSSS     OOO    R    R    T ");
	puts("                           ");
	printf("                                                                                    ");
	printf("");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 4);
	printf("<설명 - 쉘 정렬>\n");
	gotoxy(x + 40, y - 3);
	printf("삽입 정렬을 보완하여 개선한 알고리즘");
	gotoxy(x + 17, y - 2);
	printf("배열을 일정한 간격으로 나눠서 부분 배열을 만든다. 간격의 초기 값은 배열 크기의 절반이다.");
	gotoxy(x + 26, y - 1);
	printf("각 부분 배열에 대해 삽입 정렬을 수행, 간격을 줄여가며 반복");
	gotoxy(x + 33, y);
	printf("간격이 1이 될 때까지 반복하며 최종적으로 정렬을 완성");

	gotoxy(x + 6, y + 2);
	printf("<입력>");
	gotoxy(x + 6, y + 4);
	printf("정렬할 개수를 입력하시오 : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));

	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 6);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 8);
		scanf_s("%d", &arr[i]);
		x += 6;
	}
	x = 0, y = 15;
	shell_Sort(arr, n);

	printf("\n\n\n\nFinal result: ");
	for (int i = 0; i < n; i++) {
		printf("       %d ", arr[i]);
	}
	printf("\n");


	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

void heapify(int arr[], int n, int i) {
	int largest = i;     // 루트 노드
	int left = 2 * i + 1; // 왼쪽 자식 노드
	int right = 2 * i + 2; // 오른쪽 자식 노드

						   // 왼쪽 자식이 루트보다 크면 largest를 왼쪽 자식으로 설정
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	// 오른쪽 자식이 루트보다 크면 largest를 오른쪽 자식으로 설정
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	// largest가 루트가 아니라면 교환하고 재귀적으로 heapify 호출
	if (largest != i) {
		SWAP(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

// 힙 정렬 함수
void heapSort(int arr[], int n) {
	// 최대 힙 구성
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	// 힙에서 요소 하나씩 추출하여 정렬
	for (int i = n - 1; i > 0; i--) {
		SWAP(arr[0], arr[i]); // 최대값(루트)을 마지막 요소와 교환
		heapify(arr, i, 0);   // 힙을 재구성
		printf("\n");
		printf("After extracting %d: ", arr[i]);
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
}

void Heap_Sort() {
	system("mode con cols=120 lines=50 | title Heap_Sort()");
	system("cls");
	printf("\n\n\n");
	puts("                      H    H   EEEEEE       A       PPPPP             SSSSS     OOO    RRRR    TTTTT");
	puts("                      H    H   E           A A      P    P           S         O   O   R   R     T ");
	puts("                      HHHHHH   EEEEEE     AAAAA     PPPPP             SSSSS    O   O   RRRR      T   ");
	puts("                      H    H   E         A     A    P                      S   O   O   R   R     T   ");
	puts("                      H    H   EEEEEE   A       A   P                 SSSSS     OOO    R    R    T ");
	puts("                           ");
	printf("                                                                                    ");
	printf("");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 4);
	printf("<설명 - 힙 정렬>\n");
	gotoxy(x + 27, y - 3);
	printf("완전 이진 트리의 일종으로 우선순위 큐를 위하여 만들어진 알고리즘");
	gotoxy(x + 15, y - 2);
	printf("완전 이진 트리를 구성. 루트 노드부터 부모노드, 왼쪽 자식노드, 오른쪽 자식노드 순으로 구성.");
	gotoxy(x + 51, y - 1);
	printf("최대 힙을 구성. ");
	gotoxy(x + 25, y);
	printf("가장 큰 수(루트에 위치)를 가장 끝의 노드와 교환한다. 2와 3을 반복한다.");

	gotoxy(x + 6, y + 2);
	printf("<입력>");
	gotoxy(x + 6, y + 4);
	printf("정렬할 개수를 입력하시오 : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));

	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 6);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 8);
		scanf_s("%d", &arr[i]);
		x += 6;
	}
	x = 0, y = 15;
	heapSort(arr, n);

	printf("\n\nFinal result: ");
	for (int i = 0; i < n; i++) {
		printf("       %d ", arr[i]);
	}
	printf("\n");


	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

int findMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

// 기수 정렬 함수
void radixSort(int arr[], int n) {
	int max = findMax(arr, n);

	// 자릿수에 따라 정렬
	for (int exp = 1; max / exp > 0; exp *= 10) {
		// 각 자릿수 별로 counting sort 수행
		int* output = (int*)malloc(n * sizeof(int));
		int count[10] = { 0 };

		// 각 자릿수 별로 빈도수 계산
		for (int i = 0; i < n; i++) {
			count[(arr[i] / exp) % 10]++;
		}

		// count[i]가 해당 자릿수에서의 위치를 나타내도록 수정
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		// output 배열에 정렬된 결과 저장
		for (int i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		// 정렬된 결과를 원래 배열에 복사
		for (int i = 0; i < n; i++) {
			arr[i] = output[i];
		}
		printf("\n");
		printf("After sorting by digit %d: ", exp);
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

	}
}
void Radix_Sort() {
	system("mode con cols=120 lines=50 | title Radix_Sort()");
	system("cls");
	printf("\n\n\n");
	puts("          RRRRR          A        DDDDD       IIIII    X     X                 SSSSS     OOO    RRRR    TTTTT");
	puts("          R    R        A A       D    D        I        X X                  S         O   O   R   R     T ");
	puts("          RRRRR        AAAAA      D     D       I         X                    SSSSS    O   O   RRRR      T   ");
	puts("          R    R      A     A     D    D        I        X X                        S   O   O   R   R     T   ");
	puts("          R     R    A       A    DDDDD       IIIII    X     X                 SSSSS     OOO    R    R    T ");
	puts("                           ");
	printf("                                                                                    ");
	printf("");
	sidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 50, y - 4);
	printf("<설명 - 힙 정렬>\n");
	gotoxy(x + 27, y - 3);
	printf("완전 이진 트리의 일종으로 우선순위 큐를 위하여 만들어진 알고리즘");
	gotoxy(x + 15, y - 2);
	printf("완전 이진 트리를 구성. 루트 노드부터 부모노드, 왼쪽 자식노드, 오른쪽 자식노드 순으로 구성.");
	gotoxy(x + 51, y - 1);
	printf("최대 힙을 구성. ");
	gotoxy(x + 25, y);
	printf("가장 큰 수(루트에 위치)를 가장 끝의 노드와 교환한다. 2와 3을 반복한다.");

	gotoxy(x + 6, y + 2);
	printf("<입력>");
	gotoxy(x + 6, y + 4);
	printf("정렬할 개수를 입력하시오 : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));

	for (int i = 0; i < n; i++) {
		block_show(x + 6, y + 6);
		x += 6;
		Sleep(100);
	}
	x = 0, y = 15;
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		gotoxy(x + 9, y + 8);
		scanf_s("%d", &arr[i]);
		x += 6;
	}
	x = 0, y = 15;
	radixSort(arr, n);

	printf("\n\nFinal result: ");
	for (int i = 0; i < n; i++) {
		printf("       %d ", arr[i]);
	}
	printf("\n");


	free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

typedef struct {
	int vertices[MAX_VERTICES]; // 정점 배열
	int edges[MAX_VERTICES][MAX_VERTICES]; // 간선 배열
	int numVertices; // 정점의 개수
} DGraph;

// 스택 구조체 정의
typedef struct {
	int data[MAX_VERTICES];
	int top;
} DStack;

// 스택 초기화 함수
void initializeStack(DStack* stack) {
	stack->top = -1;
}

// 스택이 비어있는지 확인하는 함수
bool isEmpty(DStack* stack) {
	return stack->top == -1;
}

// 스택에 요소를 추가하는 함수
void push(DStack* stack, int value) {
	stack->data[++stack->top] = value;
}

// 스택에서 요소를 제거하고 반환하는 함수
int pop(DStack* stack) {
	return stack->data[stack->top--];
}

// 깊이 우선 탐색 함수
void DFS(DGraph* graph, int startVertex) {
	DStack stack;
	initializeStack(&stack);

	bool visited[MAX_VERTICES] = { false };

	push(&stack, startVertex);
	visited[startVertex] = true;

	while (!isEmpty(&stack)) {
		int currentVertex = pop(&stack);
		printf("%d ", currentVertex);

		for (int i = 0; i < graph->numVertices; ++i) {
			if (graph->edges[currentVertex][i] == 1 && !visited[i]) {
				push(&stack, i);
				visited[i] = true;
			}
		}
	}
}

void Depth_First_Search() {
	system("mode con cols=150 lines=50 | title Depth_First_Search()");
	system("cls");
	printf("\n\n\n");
	puts("       DDDDD    EEEEE   PPPP   TTTTT   H   H       FFFFF   IIIII   RRRR     SSSSS   TTTTT       SSSSS   EEEEE      A      RRRR      CCC  H   H");
	puts("       D    D   E       P   P    T     H   H       F         I     R   R   S          T        S        E         A A     R   R    C     H   H");
	puts("       D    D   EEEEE   PPPP     T     HHHHH       FFFFF     I     RRRR     SSSSS     T         SSSSS   EEEEE    AAAAA    RRRR    C      HHHHH");
	puts("       D    D   E       P        T     H   H       F         I     R   R         S    T              S  E       A     A   R   R    C     H   H");
	puts("       DDDDD    EEEEE   P        T     H   H       F       IIIII   R    R   SSSSS     T         SSSSS   EEEEE  A       A  R    R    CCC  H   H");
	puts("                           ");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 깊이 우선 탐색>\n");
	gotoxy(x + 35, y - 3);
	printf("루트 노드에서 시작해서 다음 분기로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법");
	gotoxy(x + 55, y - 2);
	printf("한 방향으로 갈 수 있을 때까지 계속 이동 ");
	gotoxy(x + 28, y - 1);
	printf("더 이상 이동할 수 없는 경우, 다시 가장 가까운 갈림길로 돌아와서 다른 방향으로 다시 탐색을 진행");


	gotoxy(x + 16, y + 2);
	DGraph graph;

	// 정점의 개수 입력
	printf("정점 개수를 입력하시오:  ");
	scanf_s("%d", &graph.numVertices);
	gotoxy(x + 16, y + 4);
	// 정점 입력
	printf("정점 개수만큼 정점을 입력하시오: \n");
	for (int i = 0; i < graph.numVertices; ++i) {
		gotoxy(x + 32 + (i + 10) * 2, y + 4);
		scanf_s("%d", &graph.vertices[i]);
	}
	gotoxy(x + 40, y + 8);
	printf("ex) 0 1 1 0");
	gotoxy(x + 16, y + 6);
	// 간선 입력
	printf("간선 입력 (간선이 존재 1, 아니면 0):\n");
	for (int i = 0; i < graph.numVertices; ++i) {
		for (int j = 0; j < graph.numVertices; ++j) {
			gotoxy(x + 58, y + 6 + (i * 2));
			scanf_s("%d", &graph.edges[i][j]);

		}
	}
	gotoxy(x + 90, y + 26);
	// 깊이 우선 탐색 실행
	printf("깊이 우선 탐색(DFS)의 결과 :\n");
	gotoxy(x + 120, y + 26);
	DFS(&graph, 0);




	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}


// 그래프 구조체 정의
typedef struct {
	int vertices[MAX_VERTICES]; // 정점 배열
	int edges[MAX_VERTICES][MAX_VERTICES]; // 간선 배열
	int numVertices; // 정점의 개수
}BGraph;

// 큐 구조체 정의
typedef struct {
	int data[MAX_VERTICES];
	int front, rear;
} BQueue;

// 큐 초기화 함수
void initializeQueue(BQueue* queue) {
	queue->front = -1;
	queue->rear = -1;
}

// 큐가 비어있는지 확인하는 함수
bool BisEmpty(BQueue* queue) {
	return queue->front == -1;
}

// 큐에 요소를 추가하는 함수
void enqueue(BQueue* queue, int value) {
	if (BisEmpty(queue)) {
		queue->front = 0;
		queue->rear = 0;
	}
	else {
		queue->rear++;
	}
	queue->data[queue->rear] = value;
}

// 큐에서 요소를 제거하고 반환하는 함수
int dequeue(BQueue* queue) {
	int value = queue->data[queue->front];
	if (queue->front == queue->rear) {
		// 큐에 마지막 요소가 남아있을 경우
		queue->front = -1;
		queue->rear = -1;
	}
	else {
		queue->front++;
	}
	return value;
}

// 너비 우선 탐색 함수
void BFS(BGraph* graph, int startVertex) {
	BQueue queue;
	initializeQueue(&queue);

	bool visited[MAX_VERTICES] = { false };

	enqueue(&queue, startVertex);
	visited[startVertex] = true;

	while (!BisEmpty(&queue)) {
		int currentVertex = dequeue(&queue);
		printf("%d ", currentVertex);

		for (int i = 0; i < graph->numVertices; ++i) {
			if (graph->edges[currentVertex][i] == 1 && !visited[i]) {
				enqueue(&queue, i);
				visited[i] = true;
			}
		}
	}
}

void Breadth_first_search() {
	system("mode con cols=150 lines=50 | title Breadth_first_search()");
	system("cls");
	printf("\n\n\n");
	puts("   BBBB  RRRR   EEEEE      A     DDDD  TTTTT  H   H      FFFFF   IIIII   RRRR     SSSSS   TTTTT       SSSSS   EEEEE      A      RRRR      CCC  H   H");
	puts("   B   B R   R  E         A A    D   D   T    H   H      F         I     R   R   S          T        S        E         A A     R   R    C     H   H");
	puts("   BBBB  RRRR   EEEEE    AAAAA   D   D   T    HHHHH      FFFFF     I     RRRR     SSSSS     T         SSSSS   EEEEE    AAAAA    RRRR    C      HHHHH");
	puts("   B   B R   R  E       A     A  D   D   T    H   H      F         I     R   R         S    T              S  E       A     A   R   R    C     H   H");
	puts("   BBBB  R    R EEEEE  A       A DDDD    T    H   H      F       IIIII   R    R   SSSSS     T         SSSSS   EEEEE  A       A  R    R    CCC  H   H");
	puts("                           ");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 너비 우선 탐색>\n");
	gotoxy(x + 48, y - 3);
	printf("루트 노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법");
	gotoxy(x + 30, y - 2);
	printf("시작 정점으로부터 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에 방문하는 순회 방법");


	gotoxy(x + 16, y + 2);
	BGraph graph;

	// 정점의 개수 입력
	printf("정점 개수를 입력하시오:  ");
	scanf_s("%d", &graph.numVertices);
	gotoxy(x + 16, y + 4);
	// 정점 입력
	printf("정점 개수만큼 정점을 입력하시오: \n");
	for (int i = 0; i < graph.numVertices; ++i) {
		gotoxy(x + 32 + (i + 10) * 2, y + 4);
		scanf_s("%d", &graph.vertices[i]);
	}
	gotoxy(x + 40, y + 8);
	printf("ex) 0 1 1 0");
	gotoxy(x + 16, y + 6);
	// 간선 입력
	printf("간선 입력 (간선이 존재 1, 아니면 0):\n");
	for (int i = 0; i < graph.numVertices; ++i) {
		for (int j = 0; j < graph.numVertices; ++j) {
			gotoxy(x + 58, y + 6 + (i * 2));
			scanf_s("%d", &graph.edges[i][j]);
		}
	}
	gotoxy(x + 90, y + 26);
	// 깊이 우선 탐색 실행
	printf("너비 우선 탐색(BFS)의 결과 :\n");
	gotoxy(x + 120, y + 26);
	BFS(&graph, 0);




	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

typedef struct {
	int src, dest, weight;

} KEdge;

// 그래프 구조체 정의
typedef struct {
	int parent[MAX_VERTICES];
	int rank[MAX_VERTICES];
	int numVertices, numEdges;
	KEdge edges[MAX_EDGES];

} KGraph;

// 그래프 초기화 함수
void initializeGraph(KGraph* graph, int numVertices, int numEdges) {
	if (numVertices <= 0 || numVertices > MAX_VERTICES || numEdges <= 0 || numEdges > MAX_EDGES) {
		printf("정점 및 간선 수 오류.\n");
		exit(EXIT_FAILURE);
	}

	graph->numVertices = numVertices;
	graph->numEdges = numEdges;

	for (int i = 0; i < numVertices; ++i) {
		graph->parent[i] = i;
		graph->rank[i] = 0;
	}
}

// 간선 추가 함수
void addEdge(KGraph* graph, int src, int dest, int weight, int index) {
	if (index < 0 || index >= MAX_EDGES) {
		printf("간선 인덱스 오류.\n");
		exit(EXIT_FAILURE);
	}
	graph->edges[index].src = src;
	graph->edges[index].dest = dest;
	graph->edges[index].weight = weight;
}

// 비교 함수 (간선의 무게에 따라 정렬하기 위함)
int compareEdges(const void* a, const void* b) {
	return ((KEdge*)a)->weight - ((KEdge*)b)->weight;
}

// 부모 찾기 함수 (Union-Find에서 사용)
int findParent(KGraph* graph, int vertex) {
	if (graph->parent[vertex] != vertex) {
		graph->parent[vertex] = findParent(graph, graph->parent[vertex]);
	}
	return graph->parent[vertex];
}

// 합집합 연산 함수 (Union-Find에서 사용)
void unionSets(KGraph* graph, int x, int y) {
	int xRoot = findParent(graph, x);
	int yRoot = findParent(graph, y);

	if (graph->rank[xRoot] < graph->rank[yRoot]) {
		graph->parent[xRoot] = yRoot;
	}
	else if (graph->rank[xRoot] > graph->rank[yRoot]) {
		graph->parent[yRoot] = xRoot;
	}
	else {
		graph->parent[yRoot] = xRoot;
		graph->rank[xRoot]++;
	}
}

// 크루스칼 알고리즘 함수
void kruskal(KGraph* graph) {
	KEdge result[MAX_VERTICES]; // 최소 신장 트리를 저장할 배열
	int resultIndex = 0;
	int x = 0, y = 15;
	// 간선을 가중치에 따라 정렬
	qsort(graph->edges, graph->numEdges, sizeof(KEdge), compareEdges);

	for (int i = 0; i < graph->numEdges; ++i) {
		int src = graph->edges[i].src;
		int dest = graph->edges[i].dest;

		// 사이클을 형성하지 않으면 해당 간선을 최소 신장 트리에 추가
		if (findParent(graph, src) != findParent(graph, dest)) {
			result[resultIndex++] = graph->edges[i];
			unionSets(graph, src, dest);
		}
	}
	gotoxy(x + 90, y + 26);
	// 최소 신장 트리 출력
	printf("크루스칼 알고리즘 결과 :\n");
	for (int i = 0; i < resultIndex; ++i) {
		gotoxy(x + 120, y + 26 + (i * 2));
		printf("(%d, %d) - %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
	}
}

void Kruskal_Algorithm() {
	system("mode con cols=150 lines=50 | title Kruskal_Algorithm()");
	system("cls");
	printf("\n\n\n");
	puts("             K    k  RRRR   U   U  SSSS  K   K     A     L              A      L      GGGG   OOO  RRRR   IIIII TTTTT H   H  M         M");
	puts("             K  k    R   R  U   U S      K  K     A A    L             A A     L     G      O   O R   R    I     T   H   H  M M      MM");
	puts("             Kk      RRRR   U   U  SSSS  KK      AAAAA   L            AAAAA    L     G   GG O   O RRRR     I     T   HHHHH  M  M    M M");
	puts("             K  K    R   R  U   U      S K  K   A     A  L           A     A   L     G    G O   O R   R    I     T   H   H  M   M  M  M");
	puts("             K    K  R    R  UUU   SSSS  K   K A       A LLLLL      A       A  LLLLL  GGGG   OOO  R    R IIIII   T   H   H  M    M    M");
	puts("                                                                                           ");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 크루스칼 알고리즘>\n");
	gotoxy(x + 35, y - 3);
	printf("그리디 알고리즘(Greedy Algorithm)의 일종으로 최소 신장 트리를 구하는 대표적인 알고리즘");
	gotoxy(x + 55, y - 2);
	printf("주어진 모든 간선을 오름차순 정렬 수행한다. ");
	gotoxy(x + 38, y - 1);
	printf("정렬된 간선을 하나씩 확인하며 현재 간선이 노드 간 사이클을 발생시키는지 확인한다.");
	gotoxy(x + 37, y);
	printf("사이클 발생시키지 않을 경우 최소신장트리에 포함, 사이클 발생할 경우 포함하지 않는다.");

	gotoxy(x + 16, y + 4);
	printf("ex) 4 5");
	gotoxy(x + 16, y + 2);
	KGraph graph;
	int numVertices, numEdges;

	// 정점의 개수 입력
	printf("정점, 간선의 개수를 입력: ");
	scanf_s("%d %d", &numVertices, &numEdges);


	initializeGraph(&graph, numVertices, numEdges);

	gotoxy(x + 16, y + 8);
	printf("ex) 0 1 1");
	gotoxy(x + 16, y + 6);
	printf("간선을 입력하세요 (시작점, 끝점, 가중치):\n");

	for (int i = 0; i < numEdges; ++i) {
		gotoxy(x + 60, y + 6 + (i * 2));
		int src, dest, weight;
		scanf_s("%d %d %d", &src, &dest, &weight);
		addEdge(&graph, src - 1, dest - 1, weight, i);
	}




	gotoxy(x + 54, y + 26);

	kruskal(&graph);


	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

typedef struct {
	int weight;
	int inTree;
	int parent;
} PVertex;

typedef struct {
	int numVertices;
	int graph[MAX_VERTICES][MAX_VERTICES];
	PVertex vertices[MAX_VERTICES];
} PGraph;

// 그래프 초기화 함수
void PinitializeGraph(PGraph* g, int numVertices) {
	g->numVertices = numVertices;

	// 그래프의 간선 가중치 초기화
	for (int i = 0; i < numVertices; ++i) {
		for (int j = 0; j < numVertices; ++j) {
			g->graph[i][j] = INF;
		}
	}

	// 정점 초기화
	for (int i = 0; i < numVertices; ++i) {
		g->vertices[i].weight = INF;
		g->vertices[i].inTree = 0;
		g->vertices[i].parent = -1;
	}
}

// 정점을 그래프에 추가하는 함수
void PaddEdge(PGraph* g, int src, int dest, int weight) {
	g->graph[src][dest] = weight;
	g->graph[dest][src] = weight;
}

// 프림 알고리즘 함수
void prim(PGraph* g, int startVertex) {
	g->vertices[startVertex].weight = 0;

	for (int i = 0; i < g->numVertices - 1; ++i) {
		// 최소 가중치 정점 찾기
		int minVertex = -1;
		for (int j = 0; j < g->numVertices; ++j) {
			if (!g->vertices[j].inTree && (minVertex == -1 || g->vertices[j].weight < g->vertices[minVertex].weight)) {
				minVertex = j;
			}
		}

		// 찾은 정점을 최소 신장 트리에 추가
		g->vertices[minVertex].inTree = 1;

		// 연결된 정점들의 가중치 업데이트
		for (int k = 0; k < g->numVertices; ++k) {
			if (g->graph[minVertex][k] != INF && !g->vertices[k].inTree && g->graph[minVertex][k] < g->vertices[k].weight) {
				g->vertices[k].weight = g->graph[minVertex][k];
				g->vertices[k].parent = minVertex;
			}
		}
	}
}


void Prims_Algorithm() {
	system("mode con cols=150 lines=50 | title Prims_Algorithm()");
	system("cls");
	printf("\n\n\n");
	puts("             PPPP   RRRR    IIIII   M       M    SSSS                  A      L      GGGG   OOO  RRRR   IIIII TTTTT H   H  M         M");
	puts("             P   P  R   R     I     MM     MM   S                     A A     L     G      O   O R   R    I     T   H   H  M M      MM");
	puts("             PPPP   RRRR      I     M M   M M    SSSS                AAAAA    L     G   GG O   O RRRR     I     T   HHHHH  M  M    M M");
	puts("             P      R   R     I     M  M M  M        S              A     A   L     G    G O   O R   R    I     T   H   H  M   M  M  M");
	puts("             P      R    R  IIIII   M   M   M    SSSS              A       A  LLLLL  GGGG   OOO  R    R IIIII   T   H   H  M    M    M");
	puts("                                                                                           ");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 프림 알고리즘>\n");
	gotoxy(x + 43, y - 3);
	printf("시작 정점에서 정점을 추가해가며 단계적으로 트리를 확장하는 기법");
	gotoxy(x + 45, y - 2);
	printf("시작 단계는 시작 노드만이 최소 신장 트리(MST) 집합에 속한다.");
	gotoxy(x + 16, y - 1);
	printf("트리 집합에 속한 정점들과 인접한 정점들 중 가장 낮은 가중치의 간선과 연결된 정점에 대해 간선과 정점을 MST 트리 집합에 넣는다.");
	gotoxy(x + 37, y);
	printf("2번 과정을 MST 집합의 원소 개수가 그래프의 정점의 개수가 될 때까지 반복한다.");

	gotoxy(x + 16, y + 4);
	printf("ex) 4 5");
	gotoxy(x + 16, y + 2);
	PGraph graph;
	int numVertices, numEdges;
	// 정점의 개수 입력
	printf("정점, 간선의 개수를 입력: ");
	scanf_s("%d %d", &numVertices, &numEdges);


	PinitializeGraph(&graph, numVertices);
	gotoxy(x + 16, y + 8);
	printf("ex) 0 1 1");
	gotoxy(x + 16, y + 6);
	printf("간선을 입력하세요(시작점, 끝점, 가중치) :\n");
	for (int i = 0; i < numEdges; ++i) {
		gotoxy(x + 60, y + 6 + (i * 2));
		int src, dest, weight;
		scanf_s("%d %d %d", &src, &dest, &weight);
		PaddEdge(&graph, src - 1, dest - 1, weight);
	}
	printf("\n                ");
	int startVertex;
	printf("시작 정점을 입력:   ");
	scanf_s("%d", &startVertex);


	gotoxy(x + 16, y + 26);

	prim(&graph, startVertex - 1);
	gotoxy(x + 90, y + 26);
	// 최소 신장 트리 출력
	printf("프림 알고리즘 결과 :    \n");
	for (int i = 0; i < graph.numVertices; ++i) {
		gotoxy(x + 110, y + 26 + (i * 2));

		printf("(%d, %d)\n", i + 1, graph.vertices[i].weight);

	}


	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}
// 그래프의 정점 구조체
typedef struct Node {
	int data;
	struct Node* next;
} TNode;

// 그래프 구조체
typedef struct {
	int numVertices;
	TNode* adjList[MAX_VERTICES];
	int* inDegree;
} TGraph;

// 그래프 초기화 함수
TGraph* TinitializeGraph(int numVertices) {
	TGraph* graph = (TGraph*)malloc(sizeof(TGraph));
	graph->numVertices = numVertices;
	graph->inDegree = (int*)malloc(numVertices * sizeof(int));

	// 초기화: 인접 리스트와 진입 차수 배열
	for (int i = 0; i < numVertices; ++i) {
		graph->adjList[i] = NULL;
		graph->inDegree[i] = 0;
	}

	return graph;
}

// 간선 추가 함수
void TaddEdge(TGraph* graph, int src, int dest) {
	// dest가 src로 향하는 간선을 추가하고 dest의 진입 차수를 증가
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	newNode->data = dest;
	newNode->next = graph->adjList[src];
	graph->adjList[src] = newNode;
	graph->inDegree[dest]++;
}

// 위상 정렬 함수
void topologicalSort(TGraph* graph) {
	int visited[MAX_VERTICES];
	for (int i = 0; i < graph->numVertices; ++i) {
		visited[i] = 0;
	}

	// 진입 차수가 0인 정점을 큐에 추가
	int queue[MAX_VERTICES];
	int front = -1, rear = -1;
	for (int i = 0; i < graph->numVertices; ++i) {
		if (graph->inDegree[i] == 0) {
			queue[++rear] = i;
			visited[i] = 1;
		}
	}

	// 위상 정렬 수행
	while (front != rear) {
		int currentVertex = queue[++front];
		printf("%d ", currentVertex);

		// 현재 정점과 연결된 정점들의 진입 차수를 감소
		TNode* temp = graph->adjList[currentVertex];
		while (temp != NULL) {
			int adjVertex = temp->data;
			graph->inDegree[adjVertex]--;

			// 진입 차수가 0이 되면 큐에 추가
			if (graph->inDegree[adjVertex] == 0 && !visited[adjVertex]) {
				queue[++rear] = adjVertex;
				visited[adjVertex] = 1;
			}

			temp = temp->next;
		}
	}
}

// 메모리 해제 함수
void freeGraph(TGraph* graph) {
	for (int i = 0; i < graph->numVertices; ++i) {
		TNode* current = graph->adjList[i];
		while (current != NULL) {
			TNode* temp = current;
			current = current->next;
			free(temp);
		}
	}

	free(graph->inDegree);
	free(graph);
}


void Topological_sort() {
	system("mode con cols=150 lines=50 | title Topological_sort()");
	system("cls");
	printf("\n\n\n");
	puts("             TTTTT  OOOO   PPPP   OOOO   L      OOOO    GGGG   IIIII   CCCC      A      L               SSSS    OOOO   RRRR    TTTTT ");
	puts("               T   O    O  P   P O    O  L     O    O  G         I    C         A A     L              S       O    O  R   R     T     ");
	puts("               T   O    O  PPPP  O    O  L     O    O  G  GGG    I    C        AAAAA    L               SSSS   O    O  RRRR      T              ");
	puts("               T   O    O  P     O    O  L     O    O  G    G    I    C       A     A   L                   S  O    O  R   R     T    ");
	puts("               T    OOOO   P      OOOO   LLLLL  OOOO    GGGG   IIIII   CCCC  A       A  LLLLL           SSSS    OOOO   R    R    T    ");
	puts("                                                                                           ");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 위상 정렬>\n");
	gotoxy(x + 35, y - 3);
	printf(" 순서가 정해져 있는 일련의 작업을 차례대로 수행해야 할 때 사용할 수 있는 알고리즘");
	gotoxy(x + 55, y - 2);
	printf("진입차수가 0인 노드를 큐에 넣는다.");
	gotoxy(x + 20, y - 1);
	printf("큐에서 원소를 꺼내 해당 노드에서 나가는 간선을 그래프에서 제거, 새롭게 진입차수가 0이 된 노드를 큐에 삽입");
	gotoxy(x + 52, y);
	printf("큐가 빌 때까지 다음의 과정을 반복한다.");


	gotoxy(x + 16, y + 2);
	TGraph* graph;
	int numVertices, numEdges;
	// 정점의 개수 입력
	printf("정점의 개수를 입력하시오 :   ");
	scanf_s("%d", &numVertices);
	gotoxy(x + 16, y + 4);

	graph = TinitializeGraph(numVertices);

	printf("간선의 개수를 입력하시오 :   ");
	scanf_s("%d", &numEdges);
	gotoxy(x + 16, y + 6);
	printf("간선 입력 (시작 끝):\n");
	for (int i = 0; i < numEdges; ++i) {
		gotoxy(x + 38, y + 6 + (i * 2));
		int src, dest;
		scanf_s("%d %d", &src, &dest);
		TaddEdge(graph, src, dest);
	}
	gotoxy(x + 90, y + 26);
	printf("위상 알고리즘 결과: ");
	topologicalSort(graph);


	gotoxy(x + 16, y + 26);

	freeGraph(graph);



	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}


#define ROWS 5
#define COLS 5

typedef struct Anode {
	int x, y;
	struct Anode* parent;
	int f, g, h;
} ANode;

typedef struct {
	ANode* heap[ROWS * COLS];
	int size;
} APriorityQueue;

// 함수 선언
ANode* createNode(int x, int y, ANode* parent, int g, int h);
APriorityQueue* createPriorityQueue();
void Apush(APriorityQueue* pq, ANode* node);
ANode* Apop(APriorityQueue* pq);
int heuristic(int x1, int y1, int x2, int y2);
void AStar(int grid[ROWS][COLS], int start[2], int end[2]);

// 함수 구현
ANode* createNode(int x, int y, ANode* parent, int g, int h) {
	ANode* node = (ANode*)malloc(sizeof(ANode));
	node->x = x;
	node->y = y;
	node->parent = parent;
	node->g = g;
	node->h = h;
	node->f = g + h;
	return node;
}

APriorityQueue* createPriorityQueue() {
	APriorityQueue* pq = (APriorityQueue*)malloc(sizeof(APriorityQueue));
	pq->size = 0;
	return pq;
}

void Apush(APriorityQueue* pq, ANode* node) {
	pq->heap[pq->size] = node;
	int i = pq->size;
	pq->size++;

	while (i != 0) {
		int j = (i - 1) / 2;
		if (pq->heap[i]->f >= pq->heap[j]->f) break;
		ANode* temp = pq->heap[i];
		pq->heap[i] = pq->heap[j];
		pq->heap[j] = temp;
		i = j;
	}
}

ANode* Apop(APriorityQueue* pq) {
	ANode* node = pq->heap[0];
	pq->size--;
	pq->heap[0] = pq->heap[pq->size];

	int i = 0;
	while (1) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int min = i;

		if (left < pq->size && pq->heap[min]->f > pq->heap[left]->f)
			min = left;
		if (right < pq->size && pq->heap[min]->f > pq->heap[right]->f)
			min = right;
		if (min == i) break;

		ANode* temp = pq->heap[i];
		pq->heap[i] = pq->heap[min];
		pq->heap[min] = temp;
		i = min;
	}

	return node;
}

int heuristic(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void AStar(int grid[ROWS][COLS], int start[2], int end[2]) {
	int gx = 0, gy = 15;
	APriorityQueue* openList = createPriorityQueue();
	ANode* closedList[ROWS][COLS] = { 0 };
	ANode* startNode = createNode(start[0], start[1], NULL, 0, heuristic(start[0], start[1], end[0], end[1]));

	Apush(openList, startNode);
	gotoxy(gx + 90, gy + 6);
	printf("<이동 순서 - 아래부터 시작>");
	while (openList->size > 0) {
		ANode* currentNode = Apop(openList);
		closedList[currentNode->x][currentNode->y] = currentNode;

		if (currentNode->x == end[0] && currentNode->y == end[1]) {
			ANode* pathNode = currentNode;
			while (pathNode) {
				gotoxy(gx + 100, gy + 10);
				printf("(%d, %d)", pathNode->x, pathNode->y);
				gy += 2;  // pathNode 가 변경될 때마다 gy 값을 증가시킵니다.
				pathNode = pathNode->parent;
			}
			break;
		}

		int dx[4] = { -1, 0, 1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		for (int i = 0; i < 4; i++) {
			int nx = currentNode->x + dx[i];
			int ny = currentNode->y + dy[i];

			if (nx < 0 || ny < 0 || nx >= ROWS || ny >= COLS) continue;
			if (grid[nx][ny] || closedList[nx][ny]) continue;

			ANode* newNode = createNode(nx, ny, currentNode, currentNode->g + 1, heuristic(nx, ny, end[0], end[1]));
			Apush(openList, newNode);
		}

	}
}

void AStar_Algorithm() {
	system("mode con cols=150 lines=50 | title AStar_Algorithm()");
	system("cls");
	printf("\n\n\n");
	puts("                 A       SSSS    TTTTT      A       RRRR                    A      L      GGGG   OOO  RRRR   IIIII TTTTT H   H  M         M");
	puts("                A A     S          T       A A      R   R                  A A     L     G      O   O R   R    I     T   H   H  M M      MM");
	puts("               AAAAA     SSSS      T      AAAAA     RRRR                  AAAAA    L     G   GG O   O RRRR     I     T   HHHHH  M  M    M M");
	puts("              A     A        S     T     A     A    R   R                A     A   L     G    G O   O R   R    I     T   H   H  M   M  M  M");
	puts("             A       A   SSSS      T    A       A   R    R              A       A  LLLLL  GGGG   OOO  R    R IIIII   T   H   H  M    M    M");
	puts("                                                                                           ");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 에이스타 알고리즘>\n");
	gotoxy(x + 35, y - 3);
	printf("주어진 출발 꼭짓점에서 목표 꼭짓점까지 가는 최단 경로를 나타내는 그래프 탐색 알고리즘");
	gotoxy(x + 48, y - 2);
	printf("시작 노드에서 출발하여 이웃하는 노드들을 우선순위 큐에 추가");
	gotoxy(x + 14, y - 1);
	printf("우선순위 큐에서 가장 비용이 낮은 노드를 선택하고, 그 노드의 이웃 노드들에 대해 현재 거리 비용과 예상 거리 비용을 계산하여 큐에 추가");
	gotoxy(x + 42, y);
	printf("목표 노드가 선택되거나 모든 가능한 경로를 탐색할 때까지 이 과정을 반복");

	int grid[ROWS][COLS] = {
		{ 0, 1, 0, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0 }
	};
	int start[2] = { 0, 0 };
	int end[2] = { 4, 4 };

	gotoxy(x + 30, y + 6);
	printf("<격자 - 2차원 배열>");
	gotoxy(x + 30, y + 10);
	printf("{0, 1, 0, 0, 0}");
	gotoxy(x + 30, y + 12);
	printf("{0, 1, 0, 1, 0}");
	gotoxy(x + 30, y + 14);
	printf("{0, 0, 0, 0, 0}");
	gotoxy(x + 30, y + 16);
	printf("{0, 1, 1, 1, 1}");
	gotoxy(x + 30, y + 18);
	printf("{0, 0, 0, 0, 0}");
	AStar(grid, start, end);




	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}
#define POPULATION_SIZE 100
#define GENES "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789, .-;:_!\"#%&/()=?@${[]}"
#define TARGET "Hello, World!"
#define MAX_PRINT_COUNT 10

typedef struct
{
	char dna[13];
	int fitness;
} Individual;

Individual population[POPULATION_SIZE];

char random_gene() {
	int len = strlen(GENES);
	int r = rand() % len;
	return GENES[r];
}

int calculate_fitness(Individual individual) {
	int fitness = 0;
	for (int i = 0; i < strlen(TARGET); i++) {
		if (individual.dna[i] != TARGET[i]) {
			fitness++;
		}
	}
	return fitness;
}

Individual create_gnome() {
	Individual new_individual;
	for (int i = 0; i < strlen(TARGET); i++) {
		new_individual.dna[i] = random_gene();
	}
	new_individual.dna[strlen(TARGET)] = '\0';
	new_individual.fitness = calculate_fitness(new_individual);
	return new_individual;
}


void Genetic_Algorithm() {
	system("mode con cols=150 lines=50 | title Genetic_Algorithm()");
	system("cls");
	printf("\n\n\n");
	puts("           GGGG   EEEEE  N   N  EEEEE  TTTTT  IIIII   CCCC                 A      L      GGGG   OOO  RRRR   IIIII TTTTT H   H  M         M");
	puts("          G       E      NN  N  E        T      I    C                    A A     L     G      O   O R   R    I     T   H   H  M M      MM");
	puts("          G   GG  EEEEE  N N N  EEEEE    T      I    C                   AAAAA    L     G   GG O   O RRRR     I     T   HHHHH  M  M    M M");
	puts("          G    G  E      N  NN  E        T      I    C                  A     A   L     G    G O   O R   R    I     T   H   H  M   M  M  M");
	puts("           GGGG   EEEEE  N   N  EEEEE    T    IIIII   CCCC             A       A  LLLLL  GGGG   OOO  R    R IIIII   T   H   H  M    M    M");
	puts("                                                                                           ");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 유전자 알고리즘>\n");
	gotoxy(x + 60, y - 3);
	printf("생물의 번식을 모사한 진화 알고리즘");
	gotoxy(x + 48, y - 2);
	printf("랜덤한 개체 집합을 생성하고 각 개체의 적합도를 평가");
	gotoxy(x + 44, y - 1);
	printf(" 적합도에 기반하여 개체를 선택하고 교차시켜 새로운 개체를 생성");
	gotoxy(x + 34, y);
	printf("일부 개체에 돌연변이를 적용하여 새로운 다양성을 도입하고, 이후 세대를 현재 세대로 대체");

	srand(time(0));
	int gx = 0, gy = 15;
	for (int i = 0; i < POPULATION_SIZE; i++) {
		population[i] = create_gnome();
	}
	gotoxy(x + 30, y + 6);
	printf("<목표 - Hello, World!>");
	int generation = 0;
	int print_count = 0;
	gotoxy(x + 80, y + 6);
	printf("<출력 - 10세대 예시>");
	while (print_count < MAX_PRINT_COUNT) {
		gotoxy(gx + 80, gy + 8);
		printf("Generation: %d, Best fitness: %d, DNA: %s\n", generation, population[0].fitness, population[0].dna);
		gy += 2;
		print_count++;

		if (population[0].fitness <= 0) {
			break;
		}

		Individual new_generation[POPULATION_SIZE];

		for (int i = 0; i < POPULATION_SIZE; i++) {
			// Selection
			Individual parent1 = population[rand() % POPULATION_SIZE];
			Individual parent2 = population[rand() % POPULATION_SIZE];

			// Crossover
			Individual offspring;
			for (int i = 0; i < strlen(TARGET); i++) {
				float p = (rand() % 100) / 100.0;
				if (p < 0.45)
					offspring.dna[i] = parent1.dna[i];
				else if (p < 0.9)
					offspring.dna[i] = parent2.dna[i];
				else
					offspring.dna[i] = random_gene();
			}
			offspring.dna[strlen(TARGET)] = '\0';
			offspring.fitness = calculate_fitness(offspring);

			new_generation[i] = offspring;
		}

		for (int i = 0; i < POPULATION_SIZE; i++) {
			population[i] = new_generation[i];
		}
		generation++;
	}



	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

#define ROWS 5
#define COLS 5

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point data[ROWS * COLS];
	int front, rear;
} Queue;

void initializeQueue(Queue* queue) {
	queue->front = -1;
	queue->rear = -1;
}

bool isQueueEmpty(Queue* queue) {
	return queue->front == -1;
}

void enqueue(Queue* queue, Point value) {
	if (isQueueEmpty(queue)) {
		queue->front = 0;
	}
	queue->rear++;
	queue->data[queue->rear] = value;
}

Point dequeue(Queue* queue) {
	Point value = queue->data[queue->front];
	if (queue->front == queue->rear) {
		queue->front = -1;
		queue->rear = -1;
	}
	else {
		queue->front++;
	}
	return value;
}

int maze[ROWS][COLS] = {
	{ 0, 1, 0, 0, 0 },
	{ 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 }
};

Point goal = { 4, 4 };
Point parent[ROWS][COLS];

void SBFS() {
	Queue queue;
	initializeQueue(&queue);
	int gx = 0, gy = 15;
	Point start = { 0, 0 };
	enqueue(&queue, start);

	bool visited[ROWS][COLS] = { false };
	visited[start.x][start.y] = true;

	while (!isQueueEmpty(&queue)) {
		Point current = dequeue(&queue);

		if (current.x == goal.x && current.y == goal.y) {
			gotoxy(gx + 90, gy + 6);
			printf("<이동 순서 - 아래부터 시작>");


			Point path[ROWS * COLS];
			int pathLength = 0;
			while (!(current.x == start.x && current.y == start.y)) {
				path[pathLength++] = current;
				current = parent[current.x][current.y];
			}
			path[pathLength++] = start;

			for (int i = pathLength - 1; i >= 0; --i) {
				gotoxy(gx + 100, gy + 10 + (i * 2));
				printf("(%d, %d) ", path[i].x, path[i].y);
			}

			return;
		}

		int moves[][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
		for (int i = 0; i < 4; ++i) {
			int newX = current.x + moves[i][0];
			int newY = current.y + moves[i][1];

			if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS &&
				maze[newX][newY] == 0 && !visited[newX][newY]) {
				Point next = { newX, newY };
				enqueue(&queue, next);
				visited[newX][newY] = true;
				parent[newX][newY] = current;
			}
		}
	}

	printf("Path Not Found!\n");
}

void State_Space_Search() {
	system("mode con cols=150 lines=50 | title State_Space_Search()");
	system("cls");
	printf("\n\n\n");
	puts("     SSSS   TTTTT      A      TTTTT   EEEEE       SSSS   PPPP       A       CCCC   EEEEE       SSSSS   EEEEE      A      RRRR      CCC  H   H");
	puts("    S         T       A A       T     E          S       P   P     A A     C       E          S        E         A A     R   R    C     H   H");
	puts("     SSSS     T      AAAAA      T     EEEEE       SSSS   PPPP     AAAAA    C       EEEEE       SSSSS   EEEEE    AAAAA    RRRR    C      HHHHH");
	puts("         S    T     A     A     T     E               S  P       A     A   C       E                S  E       A     A   R   R    C     H   H");
	puts("     SSSS     T    A       A    T     EEEEE       SSSS   P      A       A   CCCC   EEEEE       SSSSS   EEEEE  A       A  R    R    CCC  H   H");
	printf("                                                                                    ");
	printf("");
	gsidebar();
	int x = 0;
	int y = 15;
	int n = 0;
	gotoxy(x + 63, y - 4);
	printf("<설명 - 상태 공간 탐색>\n");
	gotoxy(x + 35, y - 3);
	printf("답을 찾아가는 과정을 상태 공간으로 보고, 최적의 집합을 찾아가는 과정");
	gotoxy(x + 40, y - 2);
	printf("출발 상태에서 시작하여 목표 상태까지 도달하는 경로를 찾기 위해 초기 상태를 생성");
	gotoxy(x + 14, y - 1);
	printf("생성된 상태를 평가하고 가능한 다음 상태들을 생성하여 확장 각 상태는 휴리스틱 함수에 따라 평가");
	gotoxy(x + 42, y);
	printf("목표 상태에 도달하거나 최적의 상태를 찾을 때까지 과정 반복");

	gotoxy(x + 30, y + 6);
	printf("<격자 - 2차원 배열>");
	gotoxy(x + 30, y + 10);
	printf("{0, 1, 0, 0, 0}");
	gotoxy(x + 30, y + 12);
	printf("{0, 1, 0, 1, 0}");
	gotoxy(x + 30, y + 14);
	printf("{0, 0, 0, 1, 0}");
	gotoxy(x + 30, y + 16);
	printf("{0, 1, 1, 1, 0}");
	gotoxy(x + 30, y + 18);
	printf("{0, 0, 0, 0, 0}");

	SBFS();




	//free(arr);
	while (1) {
		int key = keyControl();
		if (key == DELETE) {
			previousmenuScreen();
			break;
		}
	}

}

int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// 정복하기
			int ChooseNum = ChooseDraw();
			int x = ChooseNum / 100;
			int y = ChooseNum % 100;
			if (x == 10) {
				if (y == 0) {
					Bubble_Sort();
				}
			}
			else if (x == 45) {
				if (y == 0) {
					Depth_First_Search();
				}
			}

			if (x == 10) {
				if (y == 2) {
					Selection_Sort();
				}
			}
			else if (x == 45) {
				if (y == 2) {
					Breadth_first_search();
				}
			}

			if (x == 10) {
				if (y == 4) {
					Insertion_Sort();
				}
			}
			else if (x == 45) {
				if (y == 4) {
					Kruskal_Algorithm();
				}
			}

			if (x == 10) {
				if (y == 6) {
					Merge_Sort();
				}
			}
			else if (x == 45) {
				if (y == 6) {
					Prims_Algorithm();
				}
			}

			if (x == 10) {
				if (y == 8) {
					Quick_Sort();
				}
			}
			else if (x == 45) {
				if (y == 8) {
					Topological_sort();
				}
			}


			if (x == 10) {
				if (y == 10) {
					Shell_Sort();
				}
			}
			else if (x == 45) {
				if (y == 10) {
					AStar_Algorithm();
				}
			}


			if (x == 10) {
				if (y == 12) {
					Heap_Sort();
				}
			}
			else if (x == 45) {
				if (y == 12) {
					Genetic_Algorithm();
				}
			}


			if (x == 10) {
				if (y == 14) {
					Radix_Sort();
				}
			}
			else if (x == 45) {
				if (y == 14) {
					State_Space_Search();
				}
			}



		}
		else if (menuCode == 20) {
			// 나가기
			return 0;

		}

		system("cls");
	}

	ChooseDraw();

}