#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#pragma warning(disable : 4996);

 

typedef struct {

char name[10];

int height;

int weight;

} Person;

 

int npcmp(const Person* x, const Person* y) {

 

if (x->height == y->height)

return 0;

else if (x->height < y->height)

return -1;

else return 1;

}

 

int main(void) {

 

int i;

Person x[5];

 

for (i = 0; i < 5; i++) {

printf("===x[%d] 학생===\n", i);

printf("이름 입력 : ");

scanf("%s", x[i].name);

printf("키 입력 : ");

scanf("%d", &x[i].height);

printf("몸무게 입력 : ");

scanf("%d", &x[i].weight);

puts("\n");

}

 

int nx = sizeof(x) / sizeof(x[0]);

int retry;

 

puts("키로 검색합니다.");

do {

Person temp, * p;

printf("키 : ");

scanf("%d", &temp.height);

p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void*, const void*)) npcmp);

 

if (p == NULL)

puts("검색에 실패했습니다.");

 

else {

puts("검색에 성공했습니다.\n");

printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name, p->height, p->weight);

}

 

printf("\n다시 검색할까요? (1) 예 / (0) 아니오 : ");

scanf("%d", &retry);

} while (retry == 1);

 

return 0;

}