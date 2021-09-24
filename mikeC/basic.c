﻿#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>




enum Color
{
	red, white, blue
};
enum DAY
{
	MON = 1, TUE, WED, THU, FRI, SAT, SUN
};
enum DAY day;
enum day
{
	saturday,
	sunday,
	monday,
	tuesday,
	wednesday,
	thursday,
	friday
} workday;

struct StructPerson
{
	int age;
	char name[20];
	char str[10];
	char* nam;
}person;
	//struct StructPerson p = { 22,"maimai","mmmmm" };

void reverseSentence();
int fibonaci(int i);
double factorial(unsigned int i);
char* spilitStr(char* str, char* delim);
int strTimes(char *str,char *substr);
int lengthOfLongestSubstring(char* s);
void statisticChar(char str[]);
void reverseArr(int arr[],int n);
void timeMaker(int n);
void guessNum(int n);

int main(void) {

	int n, m;
	char s[] = "hello world";
	int arr[] = { 1,2,3,4,5,6 };
	char str[] = "he.llo.a.llo.b.llo.c.llo"; 
	char *st = "llo";
	int len;
	char str1[] = "ABCDEF49629423";
	char str2[] = "013";
	char *str3 = "013";

	n = 20;
	m = 30;
	
	
	
	//FILE* fp = NULL;
	//fp= fopen("D:\23236\mike.txt", "w");
	////fopen_s(fp, "D:\23236\mike.txt", "w");
	//if (fp==NULL)
	//{
	//	perror("file open errors");
	//	return -1;
	//}
	//fprintf(fp, "%s", str1);
	//fclose(fp);
	


	//printf("ret=%s\n",s);
	//printf("ret=%d\n",lengthOfLongestSubstring(s));
	printf("%s:%u:%d:%s\n", (char*)(strstr("maimaitijumai","ti")), sizeof(arr), n, st);

	n = sizeof(arr) / sizeof(arr[0]);


	//以下为函数调用
	
	//reverseSentence();
	printf("ret=%d\n",fibonaci(9));
	printf("ret=%f\n",factorial(5));
	//printf("result=%s\n", spilitStr(str, "."));
	//printf("ret=%d\n",strTimes(str,st));
	//printf("ret=%d\n",lengthOfLongestSubstring(s));
	//statisticChar(str);
	//reverseArr(&arr,n);
	//timeMaker(n);
	//guessNum(n);


	//printf("Error: %s\n", strerror(errno));
	return 0;
	
}

////重要的注释
	

	//printf("ret=%s\n",(strstr(str, "a")));
	//printf("ret=%s\n",strrchr(str, 2));
	//printf("ret=%s\n",strtok(str,st));
	//
	//printf("第一个匹配的字符是在第 %d个位置\n",strcspn(str1, str2)+ 1);
	//strlen()
	//char* strchr(str, 'a')//返回a第一次出现后的字符串
	//strstr("maimaitijumai","ti")
	// 
	//s=getchar();
	// gets(str);
	//scanf("%s", st);
	//printf("%c\n", s);


	//sizeof不是函数，所以不需要包含任何头文件，它的功能是计算一个数据类型的大小，单位为字节,
	//sizeof的返回值为size_t.
	//size_t类型在32位操作系统下是unsigned int，是一个无符号的整数。

	//size_t t = 4;
	//printf("sizeof=%d\n", sizeof(int));

	/*Sleep(2000);
	system("cls");
	Sleep(1000);*/
	//system("calc");

//函数实现

//字符串的反转
void reverseSentence()
{
	char c;
	scanf("%c", &c);

	if (c != '\n')
	{
		reverseSentence();
		printf("%c", c);
	}
}
//斐波那契数列
int fibonaci(int i)
{
	if (i == 0)
	{
		return 0;
	}
	if (i == 1)
	{
		return 1;
	}
	//printf("%d\n", i);
	int f=fibonaci(i - 1) + fibonaci(i - 2);
	//printf("%d\n", f);		//回溯？？
	return f;
}
//阶乘
double factorial(unsigned int i)
{
	if (i < 1)
	{
		return 1;
	}
	printf("bef=%d\n", i);
	double f=i * factorial(i - 1);
	printf("aft=%d\n", i);
	return f;
}

//s字符串来分割str字符串
char* spilitStr(char* str,char* s) {
	char ret[100]="";
	char* temp = strtok(str, s);

	while (temp != NULL)
	{
		//printf("%s\n", temp);
		strcat(ret, temp);
		temp = strtok(NULL, s);
		
	}
	//printf("%s\n", ret);
	return ret;
}

//字符串中找字串
int strTimes(char* str, char* substr) {
	int count = 0;
	char* p = strstr(str, substr);
	while (p != NULL)
	{
		count++;
		p += strlen(substr);
		p = strstr(p, substr);
	}
	return count;
}
int lengthOfLongestSubstring(char* s) {
	int start = 0, end = 0, maxlen = 0;
	char map[256] = { 0 };

	map[(int)*(s + start)] = 1;
	//printf("%c-%d-%c\n", *s,(int)*(s + start), (int)*(s + start));
	//printf("%d-%c-%d\n", 0=='\0',0,'\0');
	printf("%d\n", *(s + 11)==0 );
	while (*(s + end) != 0)
	{
		maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
		++end;
		while (map[(int)*(s + end)]!=0 )//将要加入的新元素与map内元素冲突
		{
			map[(int)*(s + start)] = 0;
			++start;
		}
		map[(int)*(s + end)] = 1;
	}
	//三目运算符是每次右窗口向右移动式更新一次最长强度。
	//里面的循环相当于左窗口，外循环相当于右窗口。

	return maxlen;

}
void statisticChar(char str[]) {		//没有写成函数之前是对的
	int count[26] = { 0 };
	printf("%s", str);
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		count[str[i] - 'a'] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c=%d ", 'a' + i, count[i]);
		}
	}
	printf("\n");
}

void reverseArr(int arr[],int n) {
	int  m;
	
	
	//n = (sizeof(arr) / sizeof(arr[0]));		//获取数组的长度//这里sizeof取到的大小不是数组的大小而是指针的大小32位为4，64位为8.
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	printf("n=%d\n", n);
	for (int i = 0; i < n / 2; i++)
	{
		m = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = m;
	}

	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	printf("n=%d\n", n);
}

void timeMaker(int n) {

	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				printf("%02d:%02d:%02d\n", i, j, k);
				Sleep(1000);
				system("cls");
			}
		}
	}
}

void guessNum(int n) {
	int m;
	srand(time(NULL) % 100);		//给随机数添加随机数,给种子

	n = rand() % 100;
	while (1)
	{
		printf("输入你猜的数字=");
		scanf("%d", &m);
		if (n == m)
		{
			printf("ni成功了\n");
			break;
		}
		else if (m > n)
		{
			printf("你输入的大了\n");
		}
		else if (m < n)
		{
			printf("你输入的小了\n");
		}

	}
}