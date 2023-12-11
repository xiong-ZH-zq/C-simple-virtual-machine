#include "./mystring.c"
// ��������ز������������

enum ORDERS
{
	PUSH = 1, POP=2, LOAD = 3,STORE = 4, ADD = 5, SUB = 6,
	MUL = 7, DIV = 8, PRINT = 9, STOP = 10
};

int* orderParser(char* line){
	// ���������ʶ�𲢷��ؽ����Ĳ���
	line = strLower(strStrip(line));
	int* order = (int*)calloc(2,sizeof(int));
	
	if(!strcmp(line,"")){
		return NULL;
	}
	char* token = strtok(line," ");
	
	// ���ദ��
	if(!strcmp(token,"push")){
		order[0] = PUSH;
		token = strtok(NULL," ");
		if(token == NULL){
			printf("[Error] Invalid instruction\n");
			return NULL;
		}
		if(my_atoi(token)== NULL){
			// ����Ƿ�Ϊ����
			printf("[Error] Pushing non-numeric element\n");
			return NULL;
		}
		order[1] = *my_atoi(token);
		return order;
	} else if(!strcmp(token,"pop")){
		order[0] = POP;
		return order;
	} else if(!strcmp(token,"load")){
		order[0] = LOAD;
		token = strtok(NULL," ");
		if(token == NULL){
			printf("[Error] Invalid instruction\n");
			return NULL;
		}
			if(!strcmp(token,"reg0")) order[1] = 0;
			else if(!strcmp(token,"reg1")) order[1] = 1;
			else if(!strcmp(token,"reg2")) order[1] = 2;
			else if(!strcmp(token,"reg3")) order[1] = 3;
		    else order[1] = -1;
		return order;
	} else if(!strcmp(token,"store")){
		order[0] = STORE;
		token = strtok(NULL," ");
		if(token == NULL){
			printf("[Error] Invalid instruction\n");
			return NULL;
		}
			if(!strcmp(token,"reg0")) order[1] = 0;
			else if(!strcmp(token,"reg1")) order[1] = 1;
			else if(!strcmp(token,"reg2")) order[1] = 2;
			else if(!strcmp(token,"reg3")) order[1] = 3;
			else order[1] = -1;
		return order;
	} else if(!strcmp(token,"add")){
		order[0] = ADD;
		return order;
	} else if(!strcmp(token,"sub")){
		order[0] = SUB;
		return order;
	} else if(!strcmp(token,"mul")){
		order[0] = MUL;
		return order;
	} else if(!strcmp(token,"div")){
		order[0] = DIV;
		return order;
	} else if(!strcmp(token,"print")){
		order[0] = PRINT;
		return order;
	} else if(!strcmp(token,"stop")){
		order[0] = STOP;
		return order;
	} else {
		printf("[Error] Invalid instruction\n");
		return NULL;
	}
	
	return NULL;
};
