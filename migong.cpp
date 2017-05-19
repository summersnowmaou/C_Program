#include"stdio.h"
#include"stdlib.h"
#define  N  4

typedef struct stacknode
{
	int i;
	int j;
	int d;
	struct stracknode *next;
 } stacknode,*stack; 

 stack 	creat_stack()
 {
	stack top;
	top=(stack)malloc(sizeof(struct stacknode));
	top->next=NULL;
	return top; 
 }
 
void push_stack(stack top,int i,int j,int d)
{
	stack s;
	s=(stack)malloc(sizeof(struct stacknode));
	s->i=i; s->j=j; s->d=d;
	s->next=top->next;
	top->next=s;
 } 
 
 void pop_stack(stack top)
 {
	if(top->next==NULL) break;
		Stack t;
		t=top->next;
		top->next=t->next;
		free(t);
 }
 
 	int print(stack top)
	{
		stack go;
		go=top;
		while(go!=NULL)
		{
			print(go->next);
			printf("\t(%d,%d,%d)",go->i,go->j,go->di);
			printf("\n");
			return 0;
		}
		/*if(go==NULL)
		return 0;
		else
			print(go->next);
			printf("\t(%d,%d,%d)",go->i,go->j,go->di);
			printf("\n");
			return 0;*/
	}
	
 main()
 {
 	int map[N+2][N+2]=
				{
	{1,1,1,1,1,1},
	{1,0,0,0,0,1},
	{1,0,1,1,0,1},
	{1,0,0,0,1,1},
	{1,1,1,0,0,1},
	{1,1,1,1,1,1}
				};	


 	
 	int path(int x0,int y0,int x,int y)
	 {
	 	stack top,go;
	 	int i,j,d,flag;
	 	top=creat_stack();
	 	push(top,x0,y0,-1);
	 	map[x0][y0]=-1;
		go=top->next;
	while(go)
	{
		i=go->i;
		j=go->j;
		d=go->d;
		if(i==x && j==y)
		{
			printf("路径如下：\n");
			print(top->next);
		return 1;
		}
		else
		{
			flag=0;
			while(d<4&&flag==0)
			{
				d++;
				switch(d)
				{
				case 0:i=go->i;j=go->j+1;break;
				case 1:i=go->i-1;j=go->j;break;
				case 2:i=go->i+1;j=go->j;break;
				case 3:i=go->i;j=go->j-1;break;
				}
				if(map[i][j]==0)
					flag=1;
			}
			if(flag==1)
			{
			    go->d=d;
				map[go->i][go->j]=-1;
				push_stack(top,i,j,-1);
				
			}
			else
			{
				map[go->i][go->j]=0;
				pop_stack(top);
			}
			go=top->next;
		}
	}
	if(go==NULL)
		printf("无通路！");
	return 0;
	   }  
