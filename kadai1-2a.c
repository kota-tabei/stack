#include<stdio.h>
#include<stdlib.h>


/*�\����cell�̒�`*/
struct cell
 {
 int element;
 struct cell*next;
 };


/*push�֐� �@�X�^�b�N�̐擪��int�^�̃f�[�^x��}������*/
struct cell*push(int x, struct cell*init)
 {
 struct cell*q,*r;


 r=(struct cell*)malloc(sizeof(struct cell));
 q=init;init=r;
 r->element=x;
 r->next=q;
 return(init);
 }


/*pop�֐��@�X�^�b�N�̐擪�̃f�[�^���폜����*/
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


/*output�֐��@
�X�^�b�N�̒��̃f�[�^���|�C���^p�̈ʒu����Ō�܂ŏ��ɕ\������*/
void output(struct cell*p)
{
 while(p!=NULL)
 {
 printf("%d\n",p->element);
 p=p->next;
 }
}


/*main�֐�*/
int main(void)
 {
 struct cell*init;
 int i,n;
 
 init=NULL;
 printf("n=");
 scanf("%d",&n);
 
/*3�̔{���̃f�[�^�����}��*/
 for(i=1;i<=n;i++){
 if(i%3==0||i/10==3||i%10==3)
  init=push(i,init);
 }

 output(init);

 return(0);
 }