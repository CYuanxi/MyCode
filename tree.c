#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* ltree;
	struct TreeNode* rtree;
}TreeNode;

void BuildTree(TreeNode** T,char* data,int* index) {

	char ch;
	ch = data[*index];
	(*index)++;
	if(ch != '#') {//��ʱ��Ϊ�սڵ�
		TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
		if (temp == NULL) {
			return;
		}
		*T=temp;
		(*T)->data = ch;
		BuildTree(&((*T)->ltree),data,index);
		BuildTree(&((*T)->rtree),data,index);
	}
	else {//��Ϊ�սڵ�
		*T = NULL;
	}
}
//ǰ�����
void preOrder(TreeNode* T) {
	if (T == NULL){
		return;
	}
	printf("%c ",T->data);
	preOrder(T->ltree);
	preOrder(T->rtree);
}
//�������
void inOrder(TreeNode* T) {
	if (T == NULL){
		return;
	}
	inOrder(T->ltree);
	printf("%c ",T->data);
	inOrder(T->rtree);
}
//�������
void postOrder(TreeNode* T) {
	if (T == NULL){
		return;
	}
	postOrder(T->ltree);
	postOrder(T->rtree);
	printf("%c ",T->data);
}
int main() {
	TreeNode* T;
	char data[20];
	scanf("%s", data);
	int index = 0;
	BuildTree(&T,data,&index);
	preOrder(T);
	printf("\n");
	inOrder(T);
	printf("\n");
	postOrder(T);
	printf("\n");
	return 0;
}