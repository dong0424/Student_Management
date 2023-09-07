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
            printf("1. 전체 출력하기 \t 2. 선택 출력하기\n");
            printf("원하는 메뉴를 입력하세요: ");
            input = inputInt(1, 2);
            if (input == 1) {
                printAll(count, student);
            }
            else {
                printf("찾을 이름을 입력하세요: ");
                char name[20];
                scanf_s("%s", name, sizeof(name));
                printName(count, student, name);
            }
        }
        else if (input == 3) {
            printf("삭제할 학생의 이름을 입력하세요: ");
            char name[20];
            scanf_s("%s", name, sizeof(name));
            deleteStudent(student, &count, name);
        }
        else if (input == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
    }
    return 0;
}

void showMenu() {
    printf("===== 학생 성적 관리 프로그램 =====\n");
    printf("1. 학생 정보 입력하기 \t 2. 학생 정보 출력하기 \t 3. 학생 정보 삭제하기 \t 4. 프로그램 종료하기\n");
    printf("원하는 메뉴를 입력하세요: ");
}

int inputInt(int min, int max) {
    int num;
    while (1) {
        scanf_s("%d", &num);
        if (num >= min && num <= max) {
            return num;
        }
        printf("범위에서 벗어난 값입니다. 다시 입력해주세요 (%d ~ %d)\n", min, max);
    }
}

void addStudent(Student* student, int* count) {
    char dummy; // 버퍼를 비워주기 위한 변수

    if (*count >= 30) {
        printf("이미 30명의 학생 정보가 입력되었습니다. 더 이상 입력할 수 없습니다.\n");
        return;
    }
    printf("===== 학생 정보 입력하기 [%d / 30] =====\n", *count + 1);
    printf("이름: ");
    scanf_s("%s", student[*count].name, sizeof(student[*count].name));
    dummy = getchar(); // 버퍼를 비워주는 부분
    printf("나이: ");
    scanf_s("%d", &student[*count].age);
    printf("고향: ");
    scanf_s("%s", student[*count].hometown, sizeof(student[*count].hometown));
    dummy = getchar(); // 버퍼를 비워주는 부분
    printf("취미: ");
    scanf_s("%s", student[*count].hobby, sizeof(student[*count].hobby));
    dummy = getchar(); // 버퍼를 비워주는 부분
    printf("전화번호: ");
    scanf_s("%s", student[*count].phoneNumber, sizeof(student[*count].phoneNumber));
    dummy = getchar(); // 버퍼를 비워주는 부분
    printf("폰 종류: ");
    scanf_s("%s", student[*count].phoneType, sizeof(student[*count].phoneType));
    dummy = getchar(); // 버퍼를 비워주는 부분
    printf("국어: ");
    student[*count].Kor = inputInt(0, 100);
    printf("영어: ");
    student[*count].Eng = inputInt(0, 100);
    printf("수학: ");
    student[*count].Math = inputInt(0, 100);
    student[*count].Avg = (float)(student[*count].Kor + student[*count].Eng + student[*count].Math) / 3.0f;
    (*count)++;
}

void printAll(int count, Student* student) {
    printf("===== 학생 정보 전체 출력하기 =====\n");
    for (int i = 0; i < count; i++) {
        printf("학생 [%d/30]\n", i + 1);
        printf("이름: %s, 나이: %d, 고향: %s, 취미: %s, 전화번호: %s, 폰 종류: %s, 국어: %d, 영어: %d, 수학: %d, 평균: %.2f\n\n",
            student[i].name, student[i].age, student[i].hometown, student[i].hobby, student[i].phoneNumber, student[i].phoneType, student[i].Kor, student[i].Eng, student[i].Math, student[i].Avg);
    }
}

void printName(int count, Student* student, char name[20]) {
    printf("===== 학생 정보 선택 출력하기(%s) =====\n", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(name, student[i].name) == 0) {
            printf("이름: %s, 나이: %d, 고향: %s, 취미: %s, 전화번호: %s, 폰 종류: %s, 국어: %d, 영어: %d, 수학: %d, 평균: %.2f\n\n",
                student[i].name, student[i].age, student[i].hometown, student[i].hobby, student[i].phoneNumber, student[i].phoneType, student[i].Kor, student[i].Eng, student[i].Math, student[i].Avg);
            return;
        }
    }
    printf("찾는 학생이 존재하지 않습니다.\n");
}

void deleteStudent(Student* student, int* count, char name[20]) {
    printf("===== 학생 정보 삭제하기 =====\n");
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, student[i].name) == 0) {
            printf("학생 정보를 삭제하시겠습니까? (Y/N): ");
            char confirm;
            scanf_s(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y') {
                for (int j = i; j < *count - 1; j++) {
                    student[j] = student[j + 1];
                }
                (*count)--;
                printf("삭제가 완료되었습니다.\n");
                return;
            }
            else if (confirm == 'N' || confirm == 'n') {
                printf("삭제가 취소되었습니다.\n");
                return;
            }
            else {
                printf("잘못 입력하셨습니다.\n");
                return;
            }
        }
    }
    printf("찾는 학생이 존재하지 않습니다.\n");
}
