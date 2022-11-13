#include<stdio.h>
#include<stdlib.h>
 
// 操作数用链栈
typedef struct Node {
	int data;
	struct Node* next;
}SNode,*LinkStack;
 
 
void Init_int(LinkStack* L)
{
	*L = NULL;
}
 
void Push_int(LinkStack* L, int e)
{
	SNode* s = (SNode*)malloc(sizeof(SNode));
	s->data = e;
	s->next = *L;
	*L = s;
}
 
void Pop_int(LinkStack* L, int* e)
{
	SNode* p = *L;
	if (*L == NULL)
	{
		printf("Pop int failuer!\n");
		return;
	}
	*e = (*L)->data;
	(*L) = (*L)->next;
	free(p);
}
 
int GetTop_int(LinkStack L)
{
	if (!L)
	{
		printf("GetTop int failuer!\n");
		return 0;
	}
	return L->data;
}

int In(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	else return 0;
}
 
int Opreate(int a,char ch,int b)
{
	switch (ch)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return b / a;
	}
	return 0;
}
 
 
int Polan()
{
	char ch[10];
	LinkStack OPND;
    Init_int(&OPND);
	scanf("%s", &ch);
	while (ch[0] != '$' )
	{
		if (!In(ch[0]))	//In 函数为判断 字符 是否为操作符
		{
			Push_int(&OPND, atoi(ch));	//atoi()函数为 将字符串转化成Int型
			
		}
		else {
			int a, b;
			Pop_int(&OPND, &a);
			Pop_int(&OPND, &b);
			Push_int(&OPND, Opreate(a, ch[0], b));
		}
		scanf("%s", &ch);
	}
 
	return GetTop_int(OPND);
}
 
 
int main()
{
	printf("=%d\n", Polan());
	return 0;
}