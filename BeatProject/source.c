#include <stdio.h>
#include <string.h>

typedef struct _Student {
    char name[20];
    int age;
    char hometown[20];
    char hobby[20];
    char phoneNumber[15];
    char phoneType[20];
    int Kor;
    int Eng;
    int Math;
    float Avg;
} Student;

int inputInt(int min, int max);
void printAll(int count, Student* student);
void printName(int count, Student* student, char name[20]);
void addStudent(Student* student, int* count);
void deleteStudent(Student* student, int* count, char name[20]);
void showMenu();

int main() {
    Student student[30];
    int count = 0;

    while (1) {
        showMenu();
        int input = inputInt(1, 4);

        if (input == 1) {
            addStudent(student, &count);
        }
        else if (input == 2) {
            printf("1. ��ü ����ϱ� \t 2. ���� ����ϱ�\n");
            printf("���ϴ� �޴��� �Է��ϼ���: ");
            input = inputInt(1, 2);
            if (input == 1) {
                printAll(count, student);
            }
            else {
                printf("ã�� �̸��� �Է��ϼ���: ");
                char name[20];
                scanf_s("%s", name, sizeof(name));
                printName(count, student, name);
            }
        }
        else if (input == 3) {
            printf("������ �л��� �̸��� �Է��ϼ���: ");
            char name[20];
            scanf_s("%s", name, sizeof(name));
            deleteStudent(student, &count, name);
        }
        else if (input == 4) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
    }
    return 0;
}

void showMenu() {
    printf("===== �л� ���� ���� ���α׷� =====\n");
    printf("1. �л� ���� �Է��ϱ� \t 2. �л� ���� ����ϱ� \t 3. �л� ���� �����ϱ� \t 4. ���α׷� �����ϱ�\n");
    printf("���ϴ� �޴��� �Է��ϼ���: ");
}

int inputInt(int min, int max) {
    int num;
    while (1) {
        scanf_s("%d", &num);
        if (num >= min && num <= max) {
            return num;
        }
        printf("�������� ��� ���Դϴ�. �ٽ� �Է����ּ��� (%d ~ %d)\n", min, max);
    }
}

void addStudent(Student* student, int* count) {
    char dummy; // ���۸� ����ֱ� ���� ����

    if (*count >= 30) {
        printf("�̹� 30���� �л� ������ �ԷµǾ����ϴ�. �� �̻� �Է��� �� �����ϴ�.\n");
        return;
    }
    printf("===== �л� ���� �Է��ϱ� [%d / 30] =====\n", *count + 1);
    printf("�̸�: ");
    scanf_s("%s", student[*count].name, sizeof(student[*count].name));
    dummy = getchar(); // ���۸� ����ִ� �κ�
    printf("����: ");
    scanf_s("%d", &student[*count].age);
    printf("����: ");
    scanf_s("%s", student[*count].hometown, sizeof(student[*count].hometown));
    dummy = getchar(); // ���۸� ����ִ� �κ�
    printf("���: ");
    scanf_s("%s", student[*count].hobby, sizeof(student[*count].hobby));
    dummy = getchar(); // ���۸� ����ִ� �κ�
    printf("��ȭ��ȣ: ");
    scanf_s("%s", student[*count].phoneNumber, sizeof(student[*count].phoneNumber));
    dummy = getchar(); // ���۸� ����ִ� �κ�
    printf("�� ����: ");
    scanf_s("%s", student[*count].phoneType, sizeof(student[*count].phoneType));
    dummy = getchar(); // ���۸� ����ִ� �κ�
    printf("����: ");
    student[*count].Kor = inputInt(0, 100);
    printf("����: ");
    student[*count].Eng = inputInt(0, 100);
    printf("����: ");
    student[*count].Math = inputInt(0, 100);
    student[*count].Avg = (float)(student[*count].Kor + student[*count].Eng + student[*count].Math) / 3.0f;
    (*count)++;
}

void printAll(int count, Student* student) {
    printf("===== �л� ���� ��ü ����ϱ� =====\n");
    for (int i = 0; i < count; i++) {
        printf("�л� [%d/30]\n", i + 1);
        printf("�̸�: %s, ����: %d, ����: %s, ���: %s, ��ȭ��ȣ: %s, �� ����: %s, ����: %d, ����: %d, ����: %d, ���: %.2f\n\n",
            student[i].name, student[i].age, student[i].hometown, student[i].hobby, student[i].phoneNumber, student[i].phoneType, student[i].Kor, student[i].Eng, student[i].Math, student[i].Avg);
    }
}

void printName(int count, Student* student, char name[20]) {
    printf("===== �л� ���� ���� ����ϱ�(%s) =====\n", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(name, student[i].name) == 0) {
            printf("�̸�: %s, ����: %d, ����: %s, ���: %s, ��ȭ��ȣ: %s, �� ����: %s, ����: %d, ����: %d, ����: %d, ���: %.2f\n\n",
                student[i].name, student[i].age, student[i].hometown, student[i].hobby, student[i].phoneNumber, student[i].phoneType, student[i].Kor, student[i].Eng, student[i].Math, student[i].Avg);
            return;
        }
    }
    printf("ã�� �л��� �������� �ʽ��ϴ�.\n");
}

void deleteStudent(Student* student, int* count, char name[20]) {
    printf("===== �л� ���� �����ϱ� =====\n");
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, student[i].name) == 0) {
            printf("�л� ������ �����Ͻðڽ��ϱ�? (Y/N): ");
            char confirm;
            scanf_s(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y') {
                for (int j = i; j < *count - 1; j++) {
                    student[j] = student[j + 1];
                }
                (*count)--;
                printf("������ �Ϸ�Ǿ����ϴ�.\n");
                return;
            }
            else if (confirm == 'N' || confirm == 'n') {
                printf("������ ��ҵǾ����ϴ�.\n");
                return;
            }
            else {
                printf("�߸� �Է��ϼ̽��ϴ�.\n");
                return;
            }
        }
    }
    printf("ã�� �л��� �������� �ʽ��ϴ�.\n");
}
