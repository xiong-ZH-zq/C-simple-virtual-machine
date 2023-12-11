#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdbool.h>
// �ַ�����������

char* strLower(char* string){
	// ���ַ������е�Ӣ����ĸȫ����ΪСд
	int len = strlen(string);
	char* newStr = (char*)malloc(len);
	strcpy(newStr,string);
	for(int i = 0;i<len;i++){
		if(newStr[i]>='A' && newStr[i]<='Z'){
			newStr[i] += 32;
		}
	}
	return newStr;
}

char* strLstrip(char* str)    // ȥ���������ǰ���հ��ַ�
{
	char* newStr = (char*)malloc(strlen(str) + 1);
	int i = 0;
	while (isspace(str[i]))
	{
		i++;
	}
	
	strcpy(newStr, str + i);
	
	return newStr;
}

char* strReverse(char* str)    // ��ת�ַ���
{
	char* newStr = (char*)malloc(strlen(str) + 1);
	strcpy(newStr, str);  // �ȸ���ԭʼ�ַ���
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)   // ֻ��Ҫ����һ����ַ�����Ϊ������˫���
	{
		char temp = newStr[i];
		newStr[i] = newStr[len - i - 1]; // ע�������� len-i-1����Ϊ�ַ����������Ǵ�0��ʼ��
		newStr[len - i - 1] = temp;
	}
	return newStr;
}

char* strStrip(char* str)   // ȥ�����˿ո񲢷������ַ���
{
	char* newStr = (char*)malloc(strlen(str) + 1);
	newStr = strLstrip(str);
	newStr = strReverse(strLstrip(strReverse(newStr)));
	return newStr;
}

int* my_atoi(char* str){
	// ���� atoi ʹ��0���Ա�����ѹ��
	int len = strlen(str);
	if(len==0) return NULL;
	int* num = (int*)calloc(1,sizeof(int));
	for(int i=0;i<len;i++){
	    if(str[i]<'0' || str[i]>'9'){
			return NULL;
		}
		*num += (str[i]-'0')*(int)pow(10,(len-i-1));
	}
	
	return num;
}

_Bool isCalculation(char* str){
	// ����Ƿ�Ϊ��ʽ
	// ���������ֺ�+-*/!^����Ϊ��ʽ
	char* tmp = (char*)malloc(1);
	tmp = str;
	int len = strlen(str);
	for(int i=0;i<len;i++){
        if((tmp[i]>'9' || tmp[i]<'0') 
			&& 
		(tmp[i]!='+' && tmp[i]!= '-' && tmp[i]!='*' && tmp[i]!='/' 
		&& tmp[i]!='!' && tmp[i]!='^' && tmp[i]!='(' && tmp[i]!=')') 
			){
			return false;
		}
	}
	
	return true;
}
