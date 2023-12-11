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
// 堆栈结构
struct stack
{
	ListNode top;    // 栈顶哑节点
	int nums;    // 已有元素个数
};

typedef struct stack* Stack;

extern Stack createStack();    // 创建堆栈
extern _Bool pushStack(Stack s,TYPE elem);    // 将元素压入栈内
extern _Bool isEmptyStack(Stack s);    // 检查非空
extern ListNode popStack(Stack s);    // 弹出元素
extern void printStack(Stack s);    // 打印栈顶元素
// 将栈顶的两个元素作四则运算并压回
extern _Bool addStack(Stack s);
extern _Bool subStack(Stack s);
extern _Bool mulStack(Stack s);
extern _Bool divStack(Stack s);
#endif
