#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Record
{
        int bit;
        struct Record *next;
}bit_cell;

bit_cell *create_list()
{
         bit_cell *n=NULL;
         return n;
}

void insert_head(int b,bit_cell **p)
{
         bit_cell *q;
         q=(bit_cell*)malloc(sizeof(bit_cell));
         q->bit = b;
         q->next = *p;
         *p=q;
}

int top(bit_cell *p)
{
    if(p==NULL)
               return -1;
    else
               return (p->bit);
} 
     
void delete_head(bit_cell **p)
{
         bit_cell *h;
         if(*p==NULL)
                     printf("ERROR");
         else 
         {
                    h=*p;
                    *p=(*p)->next;
                    free(h);
         }
}                   

bit_cell *make_list(int k)
{     
      int i,j;   
      bit_cell *p;
      p=create_list();
      for(i=0;i<k;i++)
      {
                    scanf("%d",&j);
                    insert_head(j,&p);
      }
      return p;
}

void print_list(bit_cell *p)
{    printf("\t");
     while(p->next!=NULL)
     {
                   printf("%d --> ",p->bit);
                   p=p->next;
     }
     printf("%d\n",p->bit); 
}                                   

void increment(bit_cell *p)
{
         if(p->bit==0)
         {
                      p->bit=1;
                      return ;
         }
         else
         {
                      p->bit=0;
                      if(p->next==NULL)
                      {
                                       bit_cell *new_bit;
                                       new_bit=(bit_cell*)malloc(sizeof(bit_cell));
                                       p->next=new_bit;
                                       new_bit->bit=1; 
                                       new_bit->next=NULL;
                                       return;
                      }
                      else
                      {
                                           p=p->next;
                                           increment(p);
                      }
         }
}

int evaluate(bit_cell *p)
{
    int i,j=0,x=0;
    while(p!=NULL)
    {
                  i=p->bit;
                  x=pow(2,j)*i+x;
                  p=p->next;
                  j=j+1;
    }
    return x;
}

void reverse(bit_cell **p)
{
    int i;
    bit_cell *q,*r,*s;
    q=*p;
    r=*p;
    s=*p;
    while(s->next!=NULL)
              s=s->next;
    *p=s;
    while(q->next!=NULL)
    {        q=r;
             while((q->next->next)!=NULL)
                       q=q->next;
         //    s=q->next;
             s->next=q;
             q->next=NULL;
             q=r;
    }
}
  
main()
{
     int k,i,j,l,x;
     bit_cell *p,*r,*s,*t;
     printf("Enter the number of Bits  "); 
     scanf("%d",&k);
     p = create_list();
     printf("Enter the Bits from MSB to LSB \n");
     for(i=0;i<k;i++)
     {
                    printf("Enter the %d bit \t",i+1);
                    scanf("%d",&j);
                    insert_head(j,&p);
     }
     r=p;
     s=p;
     if(p==NULL){
                    printf("There are no elements \n");
     }else
     {
                      printf("the original list is  \n");
                      print_list(p);
                      j=top(p);
                      if(j==-1)
                               printf("This is NULL set \n");
                      else
                               printf("value of top element is %d \n",j);
     }
     j=evaluate(r);
     printf("The decimal number is   %d\n",j);
     if(p!=NULL)
     {
                printf("Enter the value of increment   ");
                scanf("%d",&l); 
                for(i=0;i<l;i++)
                {
                                 increment(s);
                }
                printf("List after increment  \n");
                print_list(s);
                reverse(&p);
                printf("Reversed list after increment  \n");
                print_list(p);
     }
     getch();
}
                                       
