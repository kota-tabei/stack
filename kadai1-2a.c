/* 212010102 Tabei Kota*/


#include<stdio.h>
#include<stdlib.h>


/*構造体cellの定義*/
struct cell
 {
 int element;
 struct cell*next;
 };


/*push関数 　スタックの先頭にint型のデータxを挿入する*/
struct cell*push(int x, struct cell*init)
 {
 struct cell*q,*r;


 r=(struct cell*)malloc(sizeof(struct cell));
 q=init;init=r;
 r->element=x;
 r->next=q;
 return(init);
 }


/*pop関数　スタックの先頭のデータを削除する*/
struct cell*pop(struct cell*init)
 {
 struct cell*q;
 
 if(init==NULL)
   {
   printf("Error:Stack is empty.\n");exit(1);
   }
  q=init;init=init->next;free(q);
  return(init);
  }


/*output関数　
スタックの中のデータをポインタpの位置から最後まで順に表示する*/
void output(struct cell*p)
{
 while(p!=NULL)
 {
 printf("%d\n",p->element);
 p=p->next;
 }
}


/*main関数*/
int main(void)
 {
 struct cell*init;
 int i,n;
 
 init=NULL;
 printf("n=");
 scanf("%d",&n);
 
/*3の倍数のデータだけ挿入*/
 for(i=1;i<=n;i++){
 if(i%3==0||i/10==3||i%10==3)
  init=push(i,init);
 }

 output(init);

 return(0);
 }