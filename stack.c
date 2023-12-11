#include "./stack.h"
#include<stdio.h>
#include<stdlib.h>
#define STACK_MAX 6


ListNode createListNode(){
	ListNode newNode = (ListNode)malloc(sizeof(struct listnode));
	newNode->next = NULL;
	newNode->val = 0;    // Ä¬ÈÏÎª0
	return newNode;
}

Stack createStack(){
	Stack newStack = (Stack)malloc(sizeof(struct stack));
	if(newStack == NULL){
		printf("[Error] Out of memory");
		return NULL;
	}
	newStack->top = createListNode();
	newStack->nums = 0;
	if(newStack->top == NULL){
		printf("[Error] Out of memory\n");
		return NULL;
	}
	return newStack;
}

_Bool pushStack(Stack s,TYPE elem){
	if(s->nums == STACK_MAX){
		printf("[Error] Stack overflow\n");
		return false;
	}
	
	ListNode newNode = createListNode();
	newNode->val = elem;
	newNode->next = s->top->next;
	s->top->next = newNode;
	s->nums++;
	return true;
}

ListNode popStack(Stack s){
	if(s->top->next == NULL){
		printf("[Error] Can't pop elements in empty stack\n");
		return NULL;
	}
	ListNode newNode = createListNode();
	newNode->val = s->top->next->val;
	s->top->next = s->top->next->next;
	s->nums--;
	return newNode;
}

void printStack(Stack s){
	if(s->top->next == NULL){
		printf("Empty stack\n");
		return ;
	}
	printf("%d\n",s->top->next->val);
}

_Bool isEmptyStack(Stack s){
	return (s->top->next == NULL);
}

_Bool addStack(Stack s){
	if(s->nums<2){
		printf("[Error] There aren't enough elements in stack\n");
		return false;
	}
	TYPE elem1 = popStack(s)->val;
	TYPE elem2 = popStack(s)->val;
	pushStack(s,elem1+elem2);
	return true;
}

_Bool subStack(Stack s){
	if(s->nums<2){
		printf("[Error] There aren't enough elements in stack\n");
		return false;
	}
	TYPE elem1 = popStack(s)->val;
	TYPE elem2 = popStack(s)->val;
	pushStack(s,elem2-elem1);
	return true;
}
_Bool mulStack(Stack s){
	if(s->nums<2){
		printf("[Error] There aren't enough elements in stack\n");
		return false;
	}
	TYPE elem1 = popStack(s)->val;
	TYPE elem2 = popStack(s)->val;
	pushStack(s,elem1*elem2);
	return true;
}

_Bool divStack(Stack s){
	if(s->nums<2){
		printf("[Error] There aren't enough elements in stack\n");
		return false;
	}
	TYPE elem1 = popStack(s)->val;
	TYPE elem2 = popStack(s)->val;
	
	if(elem1==0){
		printf("[Error] Zero division\n");
		pushStack(s,elem2);
		pushStack(s,elem1);
        return false;
	}
	pushStack(s,elem2/elem1);
	return true;
}
