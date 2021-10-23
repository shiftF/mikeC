#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct LNode {
    int          data;
    struct LNode* next;
    struct LNode* pre;
}LNode, * LinkList;


typedef struct Person {
    int age;
    char name[20];
    char sex[2];
    double score;
    struct Person* next;
}Person,*person;

person InitPerson(int n);
void printPerson(person h);
LinkList CreateList(int n);
LinkList CreateTList(int n);
void printLinklist(LinkList h);
void invertedLinklist(LinkList t);
int main2()
{
    LinkList Head = NULL;
    person head = NULL;
    int n;
    printf("size=%d\n", sizeof(LNode));
    scanf("%d", &n);
    Head = CreateList(n);
    //Head = CreateTList(n);
    
    printf("�ոս����ĸ�������Ԫ�ص�ֵΪ��\n");
    printLinklist(Head);
    //invertedLinklist(Head);   //˫������������������ķ���ֵ
    printf("\n\n");

    
    printf("��������\n");
    scanf("%d", &n);
    head = InitPerson(n);
    printPerson(head);

    printf("\n\n");
    system("pause");
    return 0;
}
person InitPerson(int n) {
    person p, q, l;
    l = (Person*)malloc(sizeof(Person));//ʧ���˷���ռ�ʧ���˻᷵��0�����ؿ�ָ��NULL(0)��
    if (!l)return 0;
    l->next = NULL;//�൱��ͷ��
    q = l;//q�൱������
    for (size_t i = 0; i < n; i++)
    {
        p = (Person*)malloc(sizeof(Person));//p�൱�������Ĳ���
        if (!p)return 0;
        printf("�����%d���˵���Ϣ��", i+1);
        scanf("%d %s %s %lf",&(p->age),(p->name),(p->sex),&(p->score));
        q->next = p;
        q = p;
    }
    return l;
}
void printPerson(person h)
{
    person p = h->next;
    while (p != NULL) {
        printf("%d %s %s %lf \n", p->age,p->name,p->sex,p->score);
        p = p->next;
    }
}
LinkList CreateList(int n)
{
    //����   �����������ָ��㶨һ����������
    LinkList L, p, q;
    int i;
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)return 0;
    L->next = NULL;
    q = L;
    for (i = 1; i <= n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        printf("�������%d��Ԫ�ص�ֵ:", i);
        scanf("%d", &(p->data));
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return L;
}
LinkList CreateTList(int n)
{
    //����   �����������ָ��㶨һ����������
    LinkList L, p, q;
    int i;
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)return 0;
    L->next = NULL;
    L->pre = NULL;
    q = L;
    for (i = 1; i <= n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        printf("�������%d��Ԫ�ص�ֵ:", i);
        scanf("%d", &(p->data));
        p->next = NULL;
        p->pre = q;
        q->next = p;
        q = p;
    }
    return q;
}
void invertedLinklist(LinkList t)
{
    LinkList p = t;
    int i = 0;
    while (p->pre != NULL) {//��Ϊ�����ָ����һ��ͷָ��ֵΪ��ֵ
        printf("%d ", p->data);
        p = p->pre; i++;
    }
    printf("i=%d", i);
}
void printLinklist(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}