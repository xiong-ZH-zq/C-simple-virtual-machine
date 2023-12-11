#include "./stack.h"
#include "./stack.c"
#include "./orderParse.c"

#define LINE_MAX 30
#define REGISTER_NUM 4

int reg[REGISTER_NUM] = {0};    // 寄存器，空值默认为0
Stack mainStack;    // 主堆栈

void terminalInterface();
void orderProcess(int* order);

int main(int argc, char* argv[])
{
	mainStack = createStack();
	if(argc == 1){
		terminalInterface();
	}
	
	
	if(argc == 2){
	    FILE* instructions = fopen(argv[1],"r");
		char* line = (char*)malloc(LINE_MAX+1);
		int* order = (int*)malloc(sizeof(int)*2);
		while(fgets(line,LINE_MAX,instructions)){
			order = orderParser(line);
			if(order == NULL) continue;
			orderProcess(order);
		}
		
		terminalInterface();
	}
	
	if(argc >= 3){
		printf("Usage: main.exe filename");
	}
	
	return 0;
}


void terminalInterface(){
	// 交互式操作界面
	while(1){
		printf("$ ");
		char* line = (char*)malloc(LINE_MAX+1);
		fgets(line,LINE_MAX,stdin);
		int* order = (int*)malloc(sizeof(int)*2);
		order = orderParser(line);
		if(order == NULL) continue;
		orderProcess(order);
	}
}

void orderProcess(int* order){
	switch (order[0]) {
	case PUSH:
		pushStack(mainStack,order[1]);
		printf("Push %d into stack\n",order[1]);
		break;
	case POP:
		if(popStack(mainStack)!=NULL)
		printf("Pop element from stack\n");
		break;
	case LOAD:
		if(order[1] == -1){
			printf("[Error] No such register\n");
			break;
		}
		pushStack(mainStack,reg[order[1]]);
		reg[order[1]] = 0;
		printf("Load element in reg%d\n",order[1]);
		break;
	case STORE:
		if(order[1] == -1){
			printf("[Error] No such register\n");
			break;
		}
		reg[order[1]] = popStack(mainStack)->val;
		printf("Store element into reg%d\n",order[1]);
		break;
	case ADD:
		if(addStack(mainStack))
		printf("Add two element on top of stack\n");
		break;
	case SUB:
		if(subStack(mainStack))
		printf("Subtract two element on top of stack\n");
		break;
	case MUL:
		if(mulStack(mainStack))
		printf("Multiply two element on top of stack\n");
		break;
	case DIV:
		if(divStack(mainStack))
		printf("Divide two element on top of stack\n");
		break;
	case PRINT:
		printf("The top of stack:");
		printStack(mainStack);
		break;
	case STOP:
		printf("Exit virtual machine");
		exit(EXIT_SUCCESS);
	}
	
}
