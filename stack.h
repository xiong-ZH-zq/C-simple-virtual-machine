#include<stdbool.h>

#define TYPE int

#ifndef _LISTNODE
#define _LISTNODE
struct listnode{
	TYPE val;
	struct listnode* next;
};
typedef struct listnode* ListNode;

extern ListNode createListNode();
#endif

#ifndef _STACK
#define _STACK
// ��ջ�ṹ
struct stack
{
	ListNode top;    // ջ���ƽڵ�
	int nums;    // ����Ԫ�ظ���
};

typedef struct stack* Stack;

extern Stack createStack();    // ������ջ
extern _Bool pushStack(Stack s,TYPE elem);    // ��Ԫ��ѹ��ջ��
extern _Bool isEmptyStack(Stack s);    // ���ǿ�
extern ListNode popStack(Stack s);    // ����Ԫ��
extern void printStack(Stack s);    // ��ӡջ��Ԫ��
// ��ջ��������Ԫ�����������㲢ѹ��
extern _Bool addStack(Stack s);
extern _Bool subStack(Stack s);
extern _Bool mulStack(Stack s);
extern _Bool divStack(Stack s);
#endif
