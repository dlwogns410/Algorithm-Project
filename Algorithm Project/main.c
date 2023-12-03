#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // ����(����Ű)
#define DELETE 5 // �� ȭ�� �̵�
#define red SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
#define blue SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
#define black SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#define SWAP(x, y) { int temp = x; x = y; y = temp; }
HANDLE hConsole;


/* �Լ� ���� */
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
# define MAX_SIZE 20
int sorted[MAX_SIZE];
#define MAX_VERTICES 100
#define MAX_EDGES 100
#define INF INT_MAX


/* �Լ� ���� */

void previoustitleScreen() {
	system("cls"); // ȭ�� �����

	titleDraw();
	int menuCode = menuDraw();
	if (menuCode == 0) {
		// �����ϱ�
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
			if (y == 8) {
				Quick_Sort();
			}
		}


		if (x == 10) {
			if (y == 10) {
				Shell_Sort();
			}
		}


		if (x == 10) {
			if (y == 12) {
				Heap_Sort();
			}
		}


		if (x == 10) {
			if (y == 14) {
				Radix_Sort();
			}
		}



	}
	else if (menuCode == 20) {
		// ������
		return 0;

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
			if (y == 8) {
				Quick_Sort();
			}
		}


		if (x == 10) {
			if (y == 10) {
				Shell_Sort();
			}
		}


		if (x == 10) {
			if (y == 12) {
				Heap_Sort();
			}
		}


		if (x == 10) {
			if (y == 14) {
				Radix_Sort();
			}
		}
		system("cls");
	}

	ChooseDraw();

}

void sidebar() {
	int x = 0, y = 0;
	gotoxy(x + 100, y + 47);
	printf("    ����: ENTER \n");
	gotoxy(x + 100, y + 48);
	printf("�ڷΰ���: DELETE");
}

void gsidebar() {
	int x = 0, y = 0;
	gotoxy(x + 134, y + 47);
	printf("    ����: ENTER \n");
	gotoxy(x + 134, y + 48);
	printf("�ڷΰ���: DELETE");
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

void init() { //ù ȭ�� â ũ�� ����
	system("mode con cols=120 lines=30 | title ALGORITHM");
	CursorView(0);
}

void titleDraw() { //Ÿ��Ʋ ���� ���
	printf("\n\n\n\n\n");
	printf("\t\t           A      L       GGG      OOO     RRRR    III   TTTTT   H   H    M     M\n");
	printf("\t\t          A A     L      G        O   O    R   R    I      T     H   H    MM   MM\n");
	printf("\t\t         AAAAA    L      G  GG    O   O    RRRR     I      T     HHHHH    M M M M\n");
	printf("\t\t         A   A    L      G   G    O   O    R  R     I      T     H   H    M  M  M\n");
	printf("\t\t        A     A   LLLLL   GGGG     OOO     R   R   III     T     H   H    M     M\n");
	printf("\n\n\n\n\n\n\n\n\n");

	puts("                                     �������������������������");
	puts("                                     ���                                        ���");
	puts("                                     ���                                        ���");
	puts("                                     ���                                        ���");
	puts("                                     ���                                        ���");
	puts("                                     ���                                        ���");
	printf("                                     �������������������������");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t�̵�: ����墺");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t����: Enter");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void CursorView(int visible) //Ŀ�� �����
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y) { //Ŀ�� ��ġ �̵��Լ�
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int menuDraw() {
	int x = 46; // �ʱ� x ��ǥ
	int y = 22; // �ʱ� y ��ǥ
	gotoxy(x, y); printf("�� �����ϱ�"); // �ʱ� �޴� �׸� 1 ���
									// ���� �߰����� ����غ���
	gotoxy(x + 22, y); printf(" ������"); // �ʱ� �޴� �׸� 2 ���

	while (1) {
		int key = keyControl(); // Ű���� �Է� �ޱ�
		switch (key) {
		case LEFT: {
			if (x == 66 || x == 67) {
				gotoxy(x, y);
				printf("  "); // ȭ���� �����
				x -= 20; // x ��ǥ�� �������� �̵�
				gotoxy(x, y);
				printf("��"); // ���ο� ��ġ�� ���� ǥ��
			}
			break;
		}
		case RIGHT: {
			if (x == 46 || x == 47) {
				gotoxy(x, y);
				printf("  "); // ȭ���� �����
				x += 20; // x ��ǥ�� ���������� �̵�
				gotoxy(x, y);
				printf("��"); // ���ο� ��ġ�� ���� ǥ��
			}
			break;
		}
		case SUBMIT: {
			return  x - 46; // ���͸� ������ �޴� ���� �ϷḦ ��Ÿ���� �� ��ȯ �� �Լ� ����
		}
		}
	}
}

int keyControl() {
	int key = _getch();
	if (key == 13) { return SUBMIT; }
	else if (key == 72) { //��
		return UP;
	}
	else if (key == 80) { //�Ʒ�
		return DOWN;
	}
	else if (key == 75) { //��
		return LEFT;
	}
	else if (key == 77) { //��
		return RIGHT;
	}
	else if (key == 83) {
		return DELETE;
	}

	return -1; // �߸��� �Է��� ó���ϱ� ���� ��
}

int ChooseDraw() {
	system("mode con cols=120 lines=30 | title ChooseSort");
	system("cls");

	int x = 10, y = 5;
	gotoxy(x, y); printf("�� ���� ����");
	gotoxy(x, y + 2); printf("   ���� ����");
	gotoxy(x, y + 4); printf("   ���� ����");
	gotoxy(x, y + 6); printf("   ���� ����");
	gotoxy(x, y + 8); printf("   �� ����");
	gotoxy(x, y + 10); printf("   �� ����");
	gotoxy(x, y + 12); printf("   �� ����");
	gotoxy(x, y + 14); printf("   ��� ����");
	gotoxy(x + 35, y); printf("   ���� �켱 Ž��");
	gotoxy(x + 35, y + 2); printf("   �ʺ� �켱 Ž��");
	gotoxy(x + 35, y + 4); printf("   ũ�罺Į �˰���");
	gotoxy(x + 35, y + 6); printf("   ���� �˰���");
	gotoxy(x + 35, y + 8); printf("   ���� �˰���");
	gotoxy(x + 92, y + 22); printf("    �̵�: ����墺");
	gotoxy(x + 91, y + 23); printf("     ����: ENTER");
	gotoxy(x + 90, y + 24); printf("  �ڷΰ���: DELETE");

	while (1) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int key = keyControl();// Ű���� �Է� �ޱ�
		switch (key) {
		case DOWN: {
			if ((x == 44 || x == 45) && y < 13) {
				gotoxy(x, y);
				printf("  "); // ȭ���� �����
				y += 2; // y ��ǥ�� �Ʒ��� �̵�
				gotoxy(x, y);
				printf("��"); // ���ο� ��ġ�� ���� ǥ��

			}
			else if (x != 45 && y < 19) {
				gotoxy(x, y);
				printf("  "); // ȭ���� �����
				y += 2; // y ��ǥ�� �Ʒ��� �̵�
				gotoxy(x, y);
				printf("��"); // ���ο� ��ġ�� ���� ǥ��

			}
			break;

		}
		case UP: {
			if (5 < y) {
				gotoxy(x, y);
				printf("  "); // ȭ���� �����
				y -= 2; // y ��ǥ�� ���� �̵�
				gotoxy(x, y);
				printf("��"); // ���ο� ��ġ�� ���� ǥ��
			}
			break;
		}
		case RIGHT: {
			if (y == 15 || y == 17 || y == 19) {

				gotoxy(x, y);
				x = 45; y = 13;
				printf("   ");
				gotoxy(x, y);
				printf("��");

			}
			else if (x < 45) {
				gotoxy(x, y);
				printf("   ");
				x += 35;
				gotoxy(x, y);
				printf("��");
			}

			break;
		}
		case LEFT: {
			if (x > 10) {
				gotoxy(x, y);
				printf("   ");
				x -= 35;
				gotoxy(x, y);
				printf("��");
			}
			break;
		}
		case DELETE: {

			previoustitleScreen();
			break;
		}
		case SUBMIT: {
			return 100 * x + y - 5; // ���͸� ������ �޴� ���� �ϷḦ ��Ÿ���� �� ��ȯ �� �Լ� ����
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
	printf("<���� - ��������>\n");
	gotoxy(x + 30, y + 1);
	printf("���� ������ �� ���Ҹ� �˻��Ͽ� �ڸ��� ��ȯ�ϸ� �����ϴ� �˰���");
	gotoxy(x + 30, y + 2);
	printf("������ ó�� �� ���� ���Һ��� ������ ���ұ��� ���ϸ� �ڸ���ȯ");
	gotoxy(x + 42, y + 3);
	printf("���� ū ���Ұ� ������ �ڸ��� ����");


	gotoxy(x + 70, y + 10);
	printf("<�ڵ�>");
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
	printf("<�Է�>\n");
	gotoxy(x + 6, y + 12);
	printf("������ ������ �Է��Ͻÿ� (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // ���� �Է��� ����
		gotoxy(x + 6, y + 12);
		printf("������ ������ �Է��Ͻÿ� (2~5) : ");
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
	}// �� �̻� �ݺ����� �ʵ��� ���� ����
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
			printf("��");
			gotoxy(x, y + 1);
			printf(" _____");
			if (b == 1) {
				gotoxy(x + 6, y);
				printf("��");
				gotoxy(x + 6, y + 1);
				printf("_");
			}
			else if (b == 2) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y);
				printf("��");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("��");
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
				printf("��");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 1) {
			gotoxy(x + 6, y);
			printf("��");
			gotoxy(x + 6, y + 1);
			printf(" ______");
			if (b == 2) {
				gotoxy(x + 12, y);
				printf("��");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("��");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("��");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 2) {
			gotoxy(x + 12, y);
			printf("��");
			gotoxy(x + 12, y + 1);
			printf(" ______");
			if (b == 3) {
				gotoxy(x + 18, y);
				printf("��");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("��");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 3) {
			gotoxy(x + 18, y);
			printf("��");
			gotoxy(x + 18, y + 1);
			printf(" ______");
			if (b == 4) {
				gotoxy(x + 24, y);
				printf("��");
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
	printf("<���� - ��������>\n");
	gotoxy(x + 30, y + 1);
	printf("��ü ���� �� ���� ��ġ�� �´� ���Ҹ� ������ ��ȯ�ϴ� �˰���");
	gotoxy(x + 20, y + 2);
	printf("��ü ���� �� ���� ���� ���Ҹ� ã�� ���� �ڸ� ��ȯ, ��°�� ���� ���� ã�� �ڸ���ȯ");
	gotoxy(x + 32, y + 3);
	printf("���� ������� ���� �� ���� ū ���Ұ� ������ �ڸ��� ����");


	gotoxy(x + 70, y + 10);
	printf("<�ڵ�>");
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
	printf("<�Է�>\n");
	gotoxy(x + 6, y + 12);
	printf("������ ������ �Է��Ͻÿ� (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // ���� �Է��� ����
		gotoxy(x + 6, y + 12);
		printf("������ ������ �Է��Ͻÿ� (2~5) : ");
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

void SelectionSwap(int a, int b) { // ���⼭���� ����
	int x = 9;
	int y = 33;
	gotoxy(x, y);
	printf("                                            ");//�ʱ�ȭ
	gotoxy(x, y + 1);
	printf("                                            ");//�ʱ�ȭ
	if (a > b) {
		int c = a;
		a = b;
		b = c;
	}
	if (a != b) {
		if (a == 0) {
			gotoxy(x, y);
			printf("��");
			gotoxy(x, y + 1);
			printf(" _____");
			if (b == 1) {
				gotoxy(x + 6, y);
				printf("��");
				gotoxy(x + 6, y + 1);
				printf("_");
			}
			else if (b == 2) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y);
				printf("��");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 6, y + 1);
				printf("______");
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("��");
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
				printf("��");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 1) {
			gotoxy(x + 6, y);
			printf("��");
			gotoxy(x + 6, y + 1);
			printf(" ______");
			if (b == 2) {
				gotoxy(x + 12, y);
				printf("��");
				gotoxy(x + 12, y + 1);
				printf("_");
			}
			else if (b == 3) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y);
				printf("��");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 12, y + 1);
				printf("______");
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("��");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 2) {
			gotoxy(x + 12, y);
			printf("��");
			gotoxy(x + 12, y + 1);
			printf(" ______");
			if (b == 3) {
				gotoxy(x + 18, y);
				printf("��");
				gotoxy(x + 18, y + 1);
				printf("_");
			}
			else if (b == 4) {
				gotoxy(x + 18, y + 1);
				printf("______");
				gotoxy(x + 24, y);
				printf("��");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
		else if (a == 3) {
			gotoxy(x + 18, y);
			printf("��");
			gotoxy(x + 18, y + 1);
			printf(" ______");
			if (b == 4) {
				gotoxy(x + 24, y);
				printf("��");
				gotoxy(x + 24, y + 1);
				printf("_");
			}
		}
	}
}

void Insertion_Sort() {
	system("mode con cols=120 lines=50 | title Selection_Sort");
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
	printf("<���� - ��������>\n");
	gotoxy(x + 30, y + 1);
	printf("�� ���� �� ���� ������ ��ġ�� ã�� ���ԡ���ġ�ϴ� �˰���");
	gotoxy(x + 30, y + 2);
	printf("�� ��° ���� ����, ù ��° ���� ���Ͽ� ������� �����Ѵ�.");
	gotoxy(x + 15, y + 3);
	printf("���� ������� n��° ���� n-1 ���� ���ϰ�, ������ ������ ��ġ�� ã�� �����ϸ� �����Ѵ�.");


	gotoxy(x + 70, y + 10);
	printf("<�ڵ�>");
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
	printf("<�Է�>\n");
	gotoxy(x + 6, y + 12);
	printf("������ ������ �Է��Ͻÿ� (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // ���� �Է��� ����
		gotoxy(x + 6, y + 12);
		printf("������ ������ �Է��Ͻÿ� (2~5) : ");
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

	/* ���� ���ĵ� list�� �պ� */
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];

	}

	// ���� �ִ� ������ �ϰ� ����
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];

	}
	// ���� �ִ� ������ �ϰ� ����
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	}

	// �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
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
		mid = (left + right) / 2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		merge_sort(list, left, mid, n); // ���� �κ� ����Ʈ ���� -����(Conquer)
		merge_sort(list, mid + 1, right, n);// ���� �κ� ����Ʈ ���� -����(Conquer)
		merge_swap(list, left, right);
		merge(list, left, mid, right);// ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine)
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
	system("mode con cols=120 lines=50 | title Selection_Sort");
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
	printf("<���� - ��������>\n");
	gotoxy(x + 46, y - 3);
	printf("���� ���� �˰����� �ϳ�");
	gotoxy(x + 35, y - 2);
	printf("�Է� �迭�� ���� ũ���� 2���� �κ� �迭�� �����Ѵ�.");
	gotoxy(x + 17, y - 1);
	printf("�κ� �迭�� �����ϰ� �κ� �迭�� ũ�Ⱑ ����� ���� ������ �ٽ� ���� ���� ����� �����Ѵ�.");
	gotoxy(x + 37, y);
	printf("���ĵ� �κ� �迭���� �ϳ��� �迭�� �պ��Ѵ�");



	gotoxy(x + 60, y + 3);
	printf("<�ڵ�>");
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
	printf("<�Է�>\n");
	gotoxy(x + 6, y + 12);
	printf("������ ������ �Է��Ͻÿ� (2~5) : ");
	CursorView(1);
	scanf_s("%d", &n, sizeof(n));
	while (n < 2 || n > 5) {
		gotoxy(x + 6, y + 12);
		printf("                                   "); // ���� �Է��� ����
		gotoxy(x + 6, y + 12);
		printf("������ ������ �Է��Ͻÿ� (2~5) : ");
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
	pivot = list[left]; // ������ ����Ʈ�� ���� ���� �����͸� �ǹ����� ����(������ ���� �ǹ����� ����)

						/* low�� high�� ������ ������ �ݺ�(low<high) */
	do {
		/* list[low]�� �ǹ����� ������ ��� low�� ���� */
		do {
			low++; // low�� left+1 ���� ����
		} while (low <= right && list[low] < pivot);

		/* list[high]�� �ǹ����� ũ�� ��� high�� ���� */
		do {
			high--; //high�� right ���� ����
		} while (high >= left && list[high] > pivot);

		// ���� low�� high�� �������� �ʾ����� list[low]�� list[high] ��ȯ
		if (low < high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;

		}
	} while (low < high);
	black;
	// low�� high�� ���������� �ݺ����� �������� list[left]�� list[high]�� ��ȯ
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	// �ǹ��� ��ġ�� high�� ��ȯ
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
	system("mode con cols=120 lines=50 | title Selection_Sort");
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
	printf("<���� - �� ����>\n");
	gotoxy(x + 35, y - 3);
	printf(" ���� ���� ����� ���� ����Ʈ�� �����ϴ� �˰���");
	gotoxy(x + 28, y - 2);
	printf("�Է� �迭�� �ǹ��� �������� ��յ��ϰ� 2���� �κ� �迭�� �����Ѵ�.");
	gotoxy(x + 17, y - 1);
	printf("�κ� �迭�� �����ϰ� �κ� �迭�� ũ�Ⱑ ����� ���� ������ �ٽ� ���� ���� ����� �����Ѵ�.");
	gotoxy(x + 37, y);
	printf("���ĵ� �κ� �迭���� �ϳ��� �迭�� �պ��Ѵ�");

	gotoxy(x + 6, y + 2);
	printf("<�Է�>");
	gotoxy(x + 14, y + 2);
	blue;
	printf("-- pivot\n");
	gotoxy(x + 6, y + 4);
	black;
	printf("������ ������ �Է��Ͻÿ� : ");
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
	system("mode con cols=120 lines=50 | title Selection_Sort");
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
	printf("<���� - �� ����>\n");
	gotoxy(x + 40, y - 3);
	printf("���� ������ �����Ͽ� ������ �˰���");
	gotoxy(x + 17, y - 2);
	printf("�迭�� ������ �������� ������ �κ� �迭�� �����. ������ �ʱ� ���� �迭 ũ���� �����̴�.");
	gotoxy(x + 26, y - 1);
	printf("�� �κ� �迭�� ���� ���� ������ ����, ������ �ٿ����� �ݺ�");
	gotoxy(x + 33, y);
	printf("������ 1�� �� ������ �ݺ��ϸ� ���������� ������ �ϼ�");

	gotoxy(x + 6, y + 2);
	printf("<�Է�>");
	gotoxy(x + 6, y + 4);
	printf("������ ������ �Է��Ͻÿ� : ");
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
	int largest = i;     // ��Ʈ ���
	int left = 2 * i + 1; // ���� �ڽ� ���
	int right = 2 * i + 2; // ������ �ڽ� ���

						   // ���� �ڽ��� ��Ʈ���� ũ�� largest�� ���� �ڽ����� ����
	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	// ������ �ڽ��� ��Ʈ���� ũ�� largest�� ������ �ڽ����� ����
	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	// largest�� ��Ʈ�� �ƴ϶�� ��ȯ�ϰ� ��������� heapify ȣ��
	if (largest != i) {
		SWAP(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

// �� ���� �Լ�
void heapSort(int arr[], int n) {
	// �ִ� �� ����
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	// ������ ��� �ϳ��� �����Ͽ� ����
	for (int i = n - 1; i > 0; i--) {
		SWAP(arr[0], arr[i]); // �ִ밪(��Ʈ)�� ������ ��ҿ� ��ȯ
		heapify(arr, i, 0);   // ���� �籸��
		printf("\n");
		printf("After extracting %d: ", arr[i]);
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
}

void Heap_Sort() {
	system("mode con cols=120 lines=50 | title Selection_Sort");
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
	printf("<���� - �� ����>\n");
	gotoxy(x + 27, y - 3);
	printf("���� ���� Ʈ���� �������� �켱���� ť�� ���Ͽ� ������� �˰���");
	gotoxy(x + 15, y - 2);
	printf("���� ���� Ʈ���� ����. ��Ʈ ������ �θ���, ���� �ڽĳ��, ������ �ڽĳ�� ������ ����.");
	gotoxy(x + 51, y - 1);
	printf("�ִ� ���� ����. ");
	gotoxy(x + 25, y);
	printf("���� ū ��(��Ʈ�� ��ġ)�� ���� ���� ���� ��ȯ�Ѵ�. 2�� 3�� �ݺ��Ѵ�.");

	gotoxy(x + 6, y + 2);
	printf("<�Է�>");
	gotoxy(x + 6, y + 4);
	printf("������ ������ �Է��Ͻÿ� : ");
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

// ��� ���� �Լ�
void radixSort(int arr[], int n) {
	int max = findMax(arr, n);

	// �ڸ����� ���� ����
	for (int exp = 1; max / exp > 0; exp *= 10) {
		// �� �ڸ��� ���� counting sort ����
		int* output = (int*)malloc(n * sizeof(int));
		int count[10] = { 0 };

		// �� �ڸ��� ���� �󵵼� ���
		for (int i = 0; i < n; i++) {
			count[(arr[i] / exp) % 10]++;
		}

		// count[i]�� �ش� �ڸ��������� ��ġ�� ��Ÿ������ ����
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		// output �迭�� ���ĵ� ��� ����
		for (int i = n - 1; i >= 0; i--) {
			output[count[(arr[i] / exp) % 10] - 1] = arr[i];
			count[(arr[i] / exp) % 10]--;
		}

		// ���ĵ� ����� ���� �迭�� ����
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
	system("mode con cols=120 lines=50 | title Selection_Sort");
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
	printf("<���� - �� ����>\n");
	gotoxy(x + 27, y - 3);
	printf("���� ���� Ʈ���� �������� �켱���� ť�� ���Ͽ� ������� �˰���");
	gotoxy(x + 15, y - 2);
	printf("���� ���� Ʈ���� ����. ��Ʈ ������ �θ���, ���� �ڽĳ��, ������ �ڽĳ�� ������ ����.");
	gotoxy(x + 51, y - 1);
	printf("�ִ� ���� ����. ");
	gotoxy(x + 25, y);
	printf("���� ū ��(��Ʈ�� ��ġ)�� ���� ���� ���� ��ȯ�Ѵ�. 2�� 3�� �ݺ��Ѵ�.");

	gotoxy(x + 6, y + 2);
	printf("<�Է�>");
	gotoxy(x + 6, y + 4);
	printf("������ ������ �Է��Ͻÿ� : ");
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
	int vertices[MAX_VERTICES]; // ���� �迭
	int edges[MAX_VERTICES][MAX_VERTICES]; // ���� �迭
	int numVertices; // ������ ����
} DGraph;

// ���� ����ü ����
typedef struct {
	int data[MAX_VERTICES];
	int top;
} DStack;

// ���� �ʱ�ȭ �Լ�
void initializeStack(DStack *stack) {
	stack->top = -1;
}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty(DStack *stack) {
	return stack->top == -1;
}

// ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
void push(DStack *stack, int value) {
	stack->data[++stack->top] = value;
}

// ���ÿ��� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
int pop(DStack *stack) {
	return stack->data[stack->top--];
}

// ���� �켱 Ž�� �Լ�
void DFS(DGraph *graph, int startVertex) {
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

int Depth_First_Search() {
	system("mode con cols=150 lines=50 | title Selection_Sort");
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
	printf("<���� - ���� �켱 Ž��>\n");
	gotoxy(x + 35, y - 3);
	printf("��Ʈ ��忡�� �����ؼ� ���� �б�� �Ѿ�� ���� �ش� �б⸦ �Ϻ��ϰ� Ž���ϴ� ���");
	gotoxy(x + 55, y - 2);
	printf("�� �������� �� �� ���� ������ ��� �̵� ");
	gotoxy(x + 28, y - 1);
	printf("�� �̻� �̵��� �� ���� ���, �ٽ� ���� ����� ������� ���ƿͼ� �ٸ� �������� �ٽ� Ž���� ����");


	gotoxy(x + 16, y + 2);
	DGraph graph;

	// ������ ���� �Է�
	printf("Enter the number of vertices: ");
	scanf_s("%d", &graph.numVertices);
	gotoxy(x + 16, y + 4);
	// ���� �Է�
	printf("Enter the vertices:\n");
	for (int i = 0; i < graph.numVertices; ++i) {
		gotoxy(x + 32 + (i + 2) * 2, y + 4);
		scanf_s("%d", &graph.vertices[i]);
	}

	gotoxy(x + 16, y + 6);
	// ���� �Է�
	printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");
	for (int i = 0; i < graph.numVertices; ++i) {
		for (int j = 0; j < graph.numVertices; ++j) {
			gotoxy(x + 82, y + 6 + (i * 2));
			scanf_s("%d", &graph.edges[i][j]);
		}
	}
	gotoxy(x + 16, y + 26);
	// ���� �켱 Ž�� ����
	printf("DFS starting from vertex 0:\n");
	gotoxy(x + 46, y + 26);
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


// �׷��� ����ü ����
typedef struct {
	int vertices[MAX_VERTICES]; // ���� �迭
	int edges[MAX_VERTICES][MAX_VERTICES]; // ���� �迭
	int numVertices; // ������ ����
}BGraph;

// ť ����ü ����
typedef struct {
	int data[MAX_VERTICES];
	int front, rear;
} BQueue;

// ť �ʱ�ȭ �Լ�
void initializeQueue(BQueue *queue) {
	queue->front = -1;
	queue->rear = -1;
}

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
bool BisEmpty(BQueue *queue) {
	return queue->front == -1;
}

// ť�� ��Ҹ� �߰��ϴ� �Լ�
void enqueue(BQueue *queue, int value) {
	if (BisEmpty(queue)) {
		queue->front = 0;
		queue->rear = 0;
	}
	else {
		queue->rear++;
	}
	queue->data[queue->rear] = value;
}

// ť���� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
int dequeue(BQueue *queue) {
	int value = queue->data[queue->front];
	if (queue->front == queue->rear) {
		// ť�� ������ ��Ұ� �������� ���
		queue->front = -1;
		queue->rear = -1;
	}
	else {
		queue->front++;
	}
	return value;
}

// �ʺ� �켱 Ž�� �Լ�
void BFS(BGraph *graph, int startVertex) {
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

int Breadth_first_search() {
	system("mode con cols=150 lines=50 | title Selection_Sort");
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
	printf("<���� - �ʺ� �켱 Ž��>\n");
	gotoxy(x + 48, y - 3);
	printf("��Ʈ ��忡�� �����ؼ� ������ ��带 ���� Ž���ϴ� ���");
	gotoxy(x + 30, y - 2);
	printf("���� �������κ��� ����� ������ ���� �湮�ϰ� �ָ� ������ �ִ� ������ ���߿� �湮�ϴ� ��ȸ ���");


	gotoxy(x + 16, y + 2);
	BGraph graph;

	// ������ ���� �Է�
	printf("Enter the number of vertices: ");
	scanf_s("%d", &graph.numVertices);
	gotoxy(x + 16, y + 4);
	// ���� �Է�
	printf("Enter the vertices:\n");
	for (int i = 0; i < graph.numVertices; ++i) {
		gotoxy(x + 32 + (i + 2) * 2, y + 4);
		scanf_s("%d", &graph.vertices[i]);
	}

	gotoxy(x + 16, y + 6);
	// ���� �Է�
	printf("Enter the adjacency matrix (1 if there is an edge, 0 otherwise):\n");
	for (int i = 0; i < graph.numVertices; ++i) {
		for (int j = 0; j < graph.numVertices; ++j) {
			gotoxy(x + 82, y + 6 + (i * 2));
			scanf_s("%d", &graph.edges[i][j]);
		}
	}
	gotoxy(x + 16, y + 26);
	// ���� �켱 Ž�� ����
	printf("DFS starting from vertex 0:\n");
	gotoxy(x + 46, y + 26);
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

// �׷��� ����ü ����
typedef struct {
	int parent[MAX_VERTICES];
	int rank[MAX_VERTICES];
	int numVertices, numEdges;
	KEdge edges[MAX_EDGES];
} KGraph;

// �׷��� �ʱ�ȭ �Լ�
void initializeGraph(KGraph *graph, int numVertices, int numEdges) {
	if (numVertices <= 0 || numVertices > MAX_VERTICES || numEdges <= 0 || numEdges > MAX_EDGES) {
		printf("Invalid number of vertices or edges.\n");
		exit(EXIT_FAILURE);
	}

	graph->numVertices = numVertices;
	graph->numEdges = numEdges;

	for (int i = 0; i < numVertices; ++i) {
		graph->parent[i] = i;
		graph->rank[i] = 0;
	}
}

// ���� �߰� �Լ�
void addEdge(KGraph *graph, int src, int dest, int weight, int index) {
	if (index < 0 || index >= MAX_EDGES) {
		printf("Invalid edge index.\n");
		exit(EXIT_FAILURE);
	}
	graph->edges[index].src = src;
	graph->edges[index].dest = dest;
	graph->edges[index].weight = weight;
}

// �� �Լ� (������ ���Կ� ���� �����ϱ� ����)
int compareEdges(const void *a, const void *b) {
	return ((KEdge *)a)->weight - ((KEdge *)b)->weight;
}

// �θ� ã�� �Լ� (Union-Find���� ���)
int findParent(KGraph *graph, int vertex) {
	if (graph->parent[vertex] != vertex) {
		graph->parent[vertex] = findParent(graph, graph->parent[vertex]);
	}
	return graph->parent[vertex];
}

// ������ ���� �Լ� (Union-Find���� ���)
void unionSets(KGraph *graph, int x, int y) {
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

// ũ�罺Į �˰��� �Լ�
void kruskal(KGraph *graph) {
	KEdge result[MAX_VERTICES]; // �ּ� ���� Ʈ���� ������ �迭
	int resultIndex = 0; // �ּ� ���� Ʈ�� �迭�� �ε���

						 // ������ ����ġ�� ���� ����
	qsort(graph->edges, graph->numEdges, sizeof(KEdge), compareEdges);

	for (int i = 0; i < graph->numEdges; ++i) {
		int src = graph->edges[i].src;
		int dest = graph->edges[i].dest;

		// ����Ŭ�� �������� ������ �ش� ������ �ּ� ���� Ʈ���� �߰�
		if (findParent(graph, src) != findParent(graph, dest)) {
			result[resultIndex++] = graph->edges[i];
			unionSets(graph, src, dest);
		}
	}

	// �ּ� ���� Ʈ�� ���
	printf("Edges of the Minimum Spanning Tree:\n");
	for (int i = 0; i < resultIndex; ++i) {
		printf("(%d, %d) - %d\n", result[i].src + 1, result[i].dest + 1, result[i].weight);
	}
}

int Kruskal_Algorithm() {
	system("mode con cols=150 lines=50 | title Selection_Sort");
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
	printf("<���� - ũ�罺Į �˰���>\n");
	gotoxy(x + 35, y - 3);
	printf("�׸��� �˰���(Greedy Algorithm)�� �������� �ּ� ���� Ʈ���� ���ϴ� ��ǥ���� �˰���");
	gotoxy(x + 55, y - 2);
	printf("�־��� ��� ������ �������� ���� �����Ѵ�. ");
	gotoxy(x + 38, y - 1);
	printf("���ĵ� ������ �ϳ��� Ȯ���ϸ� ���� ������ ��� �� ����Ŭ�� �߻���Ű���� Ȯ���Ѵ�.");
	gotoxy(x + 37, y);
	printf("����Ŭ �߻���Ű�� ���� ��� �ּҽ���Ʈ���� ����, ����Ŭ �߻��� ��� �������� �ʴ´�.");


	gotoxy(x + 16, y + 2);
	KGraph graph;
	int numVertices, numEdges;
	// ������ ���� �Է�
	printf("Enter the number of vertices and edges: ");
	scanf_s("%d %d", &numVertices, &numEdges);
	gotoxy(x + 16, y + 4);

	initializeGraph(&graph, numVertices, numEdges);

	printf("Enter the edges (src dest weight):\n");
	for (int i = 0; i < numEdges; ++i) {
		gotoxy(x + 52, y + 4 + (i * 2));
		int src, dest, weight;
		scanf_s("%d %d %d", &src, &dest, &weight);
		addEdge(&graph, src - 1, dest - 1, weight, i);
	}




	gotoxy(x + 16, y + 26);

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

// �׷��� �ʱ�ȭ �Լ�
void PinitializeGraph(PGraph *g, int numVertices) {
	g->numVertices = numVertices;

	// �׷����� ���� ����ġ �ʱ�ȭ
	for (int i = 0; i < numVertices; ++i) {
		for (int j = 0; j < numVertices; ++j) {
			g->graph[i][j] = INF;
		}
	}

	// ���� �ʱ�ȭ
	for (int i = 0; i < numVertices; ++i) {
		g->vertices[i].weight = INF;
		g->vertices[i].inTree = 0;
		g->vertices[i].parent = -1;
	}
}

// ������ �׷����� �߰��ϴ� �Լ�
void PaddEdge(PGraph *g, int src, int dest, int weight) {
	g->graph[src][dest] = weight;
	g->graph[dest][src] = weight;
}

// ���� �˰��� �Լ�
void prim(PGraph *g, int startVertex) {
	g->vertices[startVertex].weight = 0;

	for (int i = 0; i < g->numVertices - 1; ++i) {
		// �ּ� ����ġ ���� ã��
		int minVertex = -1;
		for (int j = 0; j < g->numVertices; ++j) {
			if (!g->vertices[j].inTree && (minVertex == -1 || g->vertices[j].weight < g->vertices[minVertex].weight)) {
				minVertex = j;
			}
		}

		// ã�� ������ �ּ� ���� Ʈ���� �߰�
		g->vertices[minVertex].inTree = 1;

		// ����� �������� ����ġ ������Ʈ
		for (int k = 0; k < g->numVertices; ++k) {
			if (g->graph[minVertex][k] != INF && !g->vertices[k].inTree && g->graph[minVertex][k] < g->vertices[k].weight) {
				g->vertices[k].weight = g->graph[minVertex][k];
				g->vertices[k].parent = minVertex;
			}
		}
	}
}


int Prims_Algorithm() {
	system("mode con cols=150 lines=50 | title Selection_Sort");
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
	printf("<���� - ���� �˰���>\n");
	gotoxy(x + 43, y - 3);
	printf("���� �������� ������ �߰��ذ��� �ܰ������� Ʈ���� Ȯ���ϴ� ���");
	gotoxy(x + 45, y - 2);
	printf("���� �ܰ�� ���� ��常�� �ּ� ���� Ʈ��(MST) ���տ� ���Ѵ�.");
	gotoxy(x + 16, y - 1);
	printf("Ʈ�� ���տ� ���� ������� ������ ������ �� ���� ���� ����ġ�� ������ ����� ������ ���� ������ ������ MST Ʈ�� ���տ� �ִ´�.");
	gotoxy(x + 37, y);
	printf("2�� ������ MST ������ ���� ������ �׷����� ������ ������ �� ������ �ݺ��Ѵ�.");


	gotoxy(x + 16, y + 2);
	PGraph graph;
	int numVertices, numEdges;
	// ������ ���� �Է�
	printf("Enter the number of vertices and edges: ");
	scanf_s("%d %d", &numVertices, &numEdges);
	gotoxy(x + 16, y + 4);

	PinitializeGraph(&graph, numVertices);

	printf("Enter the edges (src dest weight):\n");
	for (int i = 0; i < numEdges; ++i) {
		gotoxy(x + 52, y + 4 + (i * 2));
		int src, dest, weight;
		scanf_s("%d %d %d", &src, &dest, &weight);
		PaddEdge(&graph, src - 1, dest - 1, weight);
	}

	int startVertex;
	printf("Enter the starting vertex: ");
	scanf_s("%d", &startVertex);


	gotoxy(x + 16, y + 26);

	prim(&graph, startVertex - 1);

	// �ּ� ���� Ʈ�� ���
	printf("Edges of the Minimum Spanning Tree:\n");
	for (int i = 0; i < graph.numVertices; ++i) {
		if (i != startVertex) {
			printf("(%d, %d)\n", i + 1, graph.vertices[i].weight);
		}
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
// �׷����� ���� ����ü
typedef struct Node {
	int data;
	struct Node* next;
} TNode;

// �׷��� ����ü
typedef struct {
	int numVertices;
	TNode* adjList[MAX_VERTICES];
	int* inDegree;
} TGraph;

// �׷��� �ʱ�ȭ �Լ�
TGraph* TinitializeGraph(int numVertices) {
	TGraph* graph = (TGraph*)malloc(sizeof(TGraph));
	graph->numVertices = numVertices;
	graph->inDegree = (int*)malloc(numVertices * sizeof(int));

	// �ʱ�ȭ: ���� ����Ʈ�� ���� ���� �迭
	for (int i = 0; i < numVertices; ++i) {
		graph->adjList[i] = NULL;
		graph->inDegree[i] = 0;
	}

	return graph;
}

// ���� �߰� �Լ�
void TaddEdge(TGraph* graph, int src, int dest) {
	// dest�� src�� ���ϴ� ������ �߰��ϰ� dest�� ���� ������ ����
	TNode* newNode = (TNode*)malloc(sizeof(TNode));
	newNode->data = dest;
	newNode->next = graph->adjList[src];
	graph->adjList[src] = newNode;
	graph->inDegree[dest]++;
}

// ���� ���� �Լ�
void topologicalSort(TGraph* graph) {
	int visited[MAX_VERTICES];
	for (int i = 0; i < graph->numVertices; ++i) {
		visited[i] = 0;
	}

	// ���� ������ 0�� ������ ť�� �߰�
	int queue[MAX_VERTICES];
	int front = -1, rear = -1;
	for (int i = 0; i < graph->numVertices; ++i) {
		if (graph->inDegree[i] == 0) {
			queue[++rear] = i;
			visited[i] = 1;
		}
	}

	// ���� ���� ����
	while (front != rear) {
		int currentVertex = queue[++front];
		printf("%d ", currentVertex);

		// ���� ������ ����� �������� ���� ������ ����
		TNode* temp = graph->adjList[currentVertex];
		while (temp != NULL) {
			int adjVertex = temp->data;
			graph->inDegree[adjVertex]--;

			// ���� ������ 0�� �Ǹ� ť�� �߰�
			if (graph->inDegree[adjVertex] == 0 && !visited[adjVertex]) {
				queue[++rear] = adjVertex;
				visited[adjVertex] = 1;
			}

			temp = temp->next;
		}
	}
}

// �޸� ���� �Լ�
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


int Topological_sort() {
	system("mode con cols=150 lines=50 | title Selection_Sort");
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
	printf("<���� - ���� ����>\n");
	gotoxy(x + 35, y - 3);
	printf(" ������ ������ �ִ� �Ϸ��� �۾��� ���ʴ�� �����ؾ� �� �� ����� �� �ִ� �˰���");
	gotoxy(x + 55, y - 2);
	printf("���������� 0�� ��带 ť�� �ִ´�.");
	gotoxy(x + 20, y - 1);
	printf("ť���� ���Ҹ� ���� �ش� ��忡�� ������ ������ �׷������� ����, ���Ӱ� ���������� 0�� �� ��带 ť�� ����");
	gotoxy(x + 52, y);
	printf("ť�� �� ������ ������ ������ �ݺ��Ѵ�.");


	gotoxy(x + 16, y + 2);
	TGraph* graph;
	int numVertices, numEdges;
	// ������ ���� �Է�
	printf("Enter the number of vertices: ");
	scanf_s("%d", &numVertices);
	gotoxy(x + 16, y + 4);

	graph = TinitializeGraph(numVertices);

	printf("Enter the number of edges: ");
	scanf_s("%d", &numEdges);
	gotoxy(x + 16, y + 6);
	printf("Enter the edges (src dest):\n");
	for (int i = 0; i < numEdges; ++i) {
		gotoxy(x + 46, y + 6 + (i * 2));
		int src, dest;
		scanf_s("%d %d", &src, &dest);
		TaddEdge(graph, src, dest);
	}
	gotoxy(x + 16, y + 26);
	printf("Topological Sort: ");
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


int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// �����ϱ�
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
				if (y == 8) {
					Quick_Sort();
				}
			}


			if (x == 10) {
				if (y == 10) {
					Shell_Sort();
				}
			}


			if (x == 10) {
				if (y == 12) {
					Heap_Sort();
				}
			}


			if (x == 10) {
				if (y == 14) {
					Radix_Sort();
				}
			}
		 


		}
		else if (menuCode == 20) {
			// ������
			return 0;

		}

		system("cls");
	}

	ChooseDraw();

}