#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
typedef struct String {
	char* data;
	int len;
}String;

//int Getlen(char* string) {
//	int len = 0;
//	char* temp = string;
//	while (*temp) {
//		len++;
//		temp++;
//	}
//	return len;
//}

//void String_Init(String str, char* string) {
//	str.data = NULL;
//	str.len = Getlen(string);
//	char* temp = string;
//	str.data = (char*)malloc(sizeof(char) * (str.len + 1));
//	for (int i = 0; i < str.len; i++,temp++) {
//		str.data[i] = *temp;
//	}
//	str.data[str.len] = '\0';
//}
String* String_Init() {
	String* str = (String*)malloc(sizeof(String));
	if (str == NULL) {
		return NULL;
	}
	str->data = NULL;
	str->len = 0;
	return str;
}

void StringAssign(String* str, char* data) {
	if (str->data) {
		free(str->data);
	}
	int len = 0;
	char* temp = data;
	while (*temp) {
		len++;
		temp++;
	}
	if (len == 0) {
		str->data = NULL;
		str->len = 0;
	}
	else {
		temp = data;
		str->len = len;
		char* p = (char*)malloc(sizeof(char) * (len + 1));
		if (p == NULL) {
			return;
		}
		str->data = p;
		if (str->data != NULL) {
			for (int i = 0; i < len; i++, temp++) {
				str->data[i] = *temp;
			}
			//str->data[str->len] = '\0';
		}
		/*else {
			printf("%s\n",strerror(errno));
		}*/
	}
}

void PrintString(String* str) {
	for (int i = 0; i < str->len; i++) {
		printf(i == 0 ? "%c " : "->%c ", str->data[i]);
	}
	printf("\n");
}

int* GetNext(String* str) {
	int* p = (int*)malloc((str->len) * sizeof(int));
	if (p == NULL) {
		return NULL;
	}
	int* next = p;

	int i = 0;
	int j = -1;		//0		1	2	3	4	5
	next[i] = j;	//-1	0	
	while (i < str->len - 1) {
		if (j == -1 || str->data[i] == str->data[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	return next;
}

void PrintNext(int* next, int len) {
	if(next == NULL){
		return;
	}
	for (int i = 0; i < len; i++) {
		printf(i == 0 ? "%d " : "->%d ", next[i]+1);
	}
	printf("\n");
}

void KMPMatch(String* master, String* sub,int* next) {
	int i = 0;
	int j = 0;
	while (i < master->len && j < sub->len) {
		if (j==-1 || master->data[i] == sub->data[j]){
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == sub->len) {
		printf("kmp match success.\n");
	}
	else {
		printf("kmp match fail.\n");
	}
}
int main() {
	char S[20];
	char S1[20];
	scanf("%s",S);
	scanf("%s",S1);
	String* str = String_Init();
	String* str1 = String_Init();
	//;
	StringAssign(str, S);
	StringAssign(str1, S1);
	PrintString(str);
	PrintString(str1);
	int* next = GetNext(str1);
	KMPMatch(str, str1, next);
	return 0;
}

//int main(int argc, char* argv[])
//{
//	string * str = string_init();
//	stringassign(str, argv[1]);
//	printstring(str);
//	return 0;
//}