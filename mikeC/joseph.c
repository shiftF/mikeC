#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>


typedef struct sailor
{
	int num;
	struct sailor* next;
}*sman,man;


struct sailor* initSailor(struct sailor *s);
sman disembark(sman s);
void main() {
	int i, j, k, l, m, n;
	int a[31] = { 0 };

	m = 0;		//�����ܹ�����ʮ����
	j = 1;		//λ��
	k = 1;		//����
	while (m<15)
	{
		i = 0;

		while (i<9)
		{
			
			if (i==8&&a[j]==0)
			{
				a[j] = m+1;
				printf("��%2d���´����Ϊ%2d\n", j, a[j]);
				//printf("��%2d������%2d�´���\n", j, k);
			}
			else if (a[j]!=0)
			{
				j++;
				if (j >= 30)
				{
					j = 1;
				}
				continue;
			}
			
			if (k>=30)
			{
				k = 0;
			}
			if (j>=30)
			{
				j = 0;
			}
			i++;
			j++;
			k++;
		}
		m++;
	}

	sman s = NULL;
	s = initSailor(s);
	s = disembark(s);

}
sman disembark(sman s) {
	int i, j, k, t, m;
	m = 1;
	k = 1;
	sman p, q;
	p = s;
	while (m <= 15)		//�ܹ�Ҫ15����Ҫ�´�
	{
		for (i = 1; i < 10;i++)		//����
		{
			q = p;		//��q������һ���������ˣ������ֳ�
			p = p->next;		//pΪ����Ϊi����
			if (i == 9)		//����Ϊ9��ɾ��pλ�õ��ˣ������ֳ�
			{
				printf("------------->[%d��--%d-->%d]\n", i, k, p->num);
				/*p = p->next;
				q->next = p;*/
				q->next = q->next->next;		//ɾ����9�ź��������㣬�´ν���ʱ�´��˺���Ŀ�ʼ����
				p = q;		//�����ֳ�
				
			}
			printf("%d��--%d-->%d\n", i, k, p->num);
			if (p->next==NULL)
			{
				k = 0;
				p = s;
			}
			
			k++;
		}
		printf("��%d���������У�%d�ź���������˴�\n", m, p->num);
		m++;
	}
	printf("********�����˵�����*******\n");
	m = 0;
	p = s;
	while (m < 15)
	{
		p = p->next;
		printf("%2d:��%2d��λ��\n", m, p->num);
		m++;
	}
	return s;
}
sman initSailor(struct sailor *s) {
	int i, j, k;
	sman q, h, p;
	h = NULL;
	
	h = (sman)malloc(sizeof(man));
	if (h==0)		//!h
	{
		printf("error m size!\n");
		return 0;
	}
	q = h;
	i = 0;
	while (i<30)
	{
		p = (sman)malloc(sizeof(man));
		if (!p)return 0;
		p->num = ++i;
		p->next = NULL;
		q->next = p;
		q = p;
	}

	return h;
}