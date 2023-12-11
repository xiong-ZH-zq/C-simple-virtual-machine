#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdbool.h>
// 字符串操作方法

char* strLower(char* string){
	// 将字符串当中的英文字母全部改为小写
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

char* strLstrip(char* str)    // 去除多余的左前导空白字符
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

char* strReverse(char* str)    // 反转字符串
{
	char* newStr = (char*)malloc(strlen(str) + 1);
	strcpy(newStr, str);  // 先复制原始字符串
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)   // 只需要交换一半的字符，因为交换是双向的
	{
		char temp = newStr[i];
		newStr[i] = newStr[len - i - 1]; // 注意这里是 len-i-1，因为字符串的索引是从0开始的
		newStr[len - i - 1] = temp;
	}
	return newStr;
}

char* strStrip(char* str)   // 去除两端空格并返回新字符串
{
	char* newStr = (char*)malloc(strlen(str) + 1);
	newStr = strLstrip(str);
	newStr = strReverse(strLstrip(strReverse(newStr)));
	return newStr;
}

int* my_atoi(char* str){
	// 改良 atoi 使得0可以被正常压入
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
	// 检查是否为算式
	// 仅包含数字和+-*/!^的视为算式
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
