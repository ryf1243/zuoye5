#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student{
    int stuid;//ѧ��ѧ��
	int stuAge;//ѧ������
	char stuName[100];//ѧ������
	float score;//100����
	int weight;//kg
	int height;//cm
	struct Student *next;
}stu;

struct Student *head=NULL;


void add()
{
	stu *q=(stu*)malloc(sizeof(stu));
	q->next=NULL;
	printf("������ѧ��ѧ�ţ�");
	scanf("%d",&q->stuid);
	printf("������ѧ�����䣺");
	scanf("%d",&q->stuAge);
	printf("������ѧ��������");
	scanf("%s",q->stuName);
	printf("������ѧ��������");
	scanf("%f",&q->score);
	printf("������ѧ������: ");
	scanf("%d",&q->weight);
	printf("������ѧ����ߣ�");
	scanf("%d",&q->height);
	if(head==NULL) head=q;
	else
	{
		q->next=head;
		head=q;
	}
	printf("��ӳɹ�\n");
}
void print()
{
	stu *p=head;
	while(p!=NULL)
	{
		printf("%d %d %s %f %d %d\n",p->stuid,p->stuAge,p->stuName,p->score,p->weight,p->height);
		p=p->next;
	}
	if(p==NULL)
	{
		printf("1\n");
	}
}
void find()
{
	printf("������Ҫ���ҵ����֣�");
	char name[100]={'\0'};
	scanf("%s",name);
	stu *curP=head;
	while(curP!=NULL)
	{
		if(strcmp(curP->stuName,name)==0)
		{
			printf("%d %d %s %f %d %d\n",curP->stuid,curP->stuAge,curP->stuName,curP->score,curP->weight,curP->height);
			return;
		}
		else
		{
			curP=curP->next;
		}
	}
	printf("�Բ��𣬲��޴���\n");
}
void delete1()
{	
	if(head==NULL)
	{
		printf("������û��ѧ����Ϣ\n");
		return;
	}
	struct Student *p,*q;
	int id;
	printf("��������Ҫ���ҵ�ѧ�ţ�\n");
	scanf("%d",&id);
	p=head;
	while(p->stuid!=id&&p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	if(id==p->stuid)
	{
		if(p==head)
		{
			head=p->next;
		}
		else
		{
			q->next=p->next;
		}
		printf("ɾ���ɹ�!\n");
	}
	

}
void exit()
{
  printf("�������\n");
}


int main()
{
	
	int number;
	printf("��ӭʹ�ü���ѧ������ϵͳ\n");

    printf("��������1���ѧ����Ϣ\n");
	printf("��������2��ѯѧ����Ϣ\n");
    printf("��������3ɾ��ѧ����Ϣ\n");
    printf("��������4��ӡѧ����Ϣ\n");
    printf("��������5�رմ˳���\n");
	printf("���������ϵ�����һ������\n");
	
    while(number!=5)
	{
	scanf("%d",&number);
	switch(number)
	{
	case 1:
		add();
		break;
	case 2:
		find();
		break;
	case 3:
		delete1();
		break;
	case 4:
		print();
		break;
	case 5:
		exit();
		break;
	}
	}
	return 0;

}