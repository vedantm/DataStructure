
#include<stdio.h>
#include<stdlib.h>
typedef struct Tree 
{
        struct Node *root;        
}binTree;

typedef struct Node
{
        int data;
        struct Node *left;
        struct Node *right;
        struct Node *parent;
}node;

binTree createTree()                                                               
{
        
        binTree T ;
        T.root = NULL ;                                                             
        return T;
}

void insert(int x,binTree *T)
{
     node *q,*p,*r;
     q=T->root;
     p=(node *)malloc(sizeof(node));
     p->data=x;
     p->left=NULL;
     p->right=NULL;
     if(q!=NULL)
     {
                while(q!=NULL)
                {
                        r=q;
                        if(q->data > x)
                              q=q->left;
                        else 
                              q=q->right;
                }
                if((r->data) > x)
                        r->left= p;
                else
                        r->right=p;
                p->parent=r;
     }
     else if(q==NULL)
                T->root=p; 
}
    
void delete_single(node *p,binTree *T)
{
     node *q,*r;
     if(p->left==NULL)
     {
                   q=p->right;
                   r=p->parent;
                   if(T->root == p)
                             T->root=q;
                              
                    else
                   {
                             if(r->right==p)
                             {        if(p->right==NULL)
                                      {                  r->right=NULL;
                                                         free(p);
                                                         return;
                                      }
                                      r->right=q;
                                      q->parent=r;
                             }
                             else
                             {        
                                      if(p->right==NULL)
                                      {                  r->left=NULL;
                                                         free(p);
                                                         return;
                                      }
                                      r->left=q;
                                      q->parent=r;
                             }
                   }  
     }
     else if(p->right==NULL)
     {
                   q=p->left;
                   r=p->parent;
                   if(T->root == p)
                             T->root=q;
                   else 
                   {
                            
                            if(r->right==p)
                             {        r->right=q;
                                      q->parent=r;
                             }
                             else
                             {        r->left=q;
                                      q->parent=r;
                             }
                   }  
     }
     free(p);
}
/*
void delete(node *p,binTree *T)
{
     node *q,*r;
     if(p->left==NULL || p->right==NULL)
                 delete_single(p,&T);
     else
     {
                      q=p->right;
                      while(q->left!=NULL)
                                q=q->left;
                      p->data=q->data;
                      delete_single(q,&T);
       }
}                 
*/                    
               
int depthFirst(binTree T)
{
     node *p;
     int y;
     p=T.root;
     if(p==NULL)
                return 0;
     printf("    p->data = %d\n",p->data);
     binTree T_1;
     T_1.root=p->left;
     y= depthFirst(T_1);
     //if(y==0){
     T_1.root=p->right;
     y=depthFirst(T_1);
     //}
}         


int depthFirst_3(binTree T,int min,int max)
{
     node *p;
     int y,sum=0;
     p=T.root;
     if(p==NULL)
                return 0;
     if(p->data > min && p->data < max)  sum += p->data;
     
   printf("    p->data = %d\n",p->data);
     binTree T_1;
     T_1.root=p->left;
     y= depthFirst_3(T_1,min,max);
     sum += y;
     //if(y==0){
     T_1.root=p->right;
     y=depthFirst_3(T_1,min,max);
     //}
     sum +=y;
     return sum;
}         

int a[100];
int cou=0;

int depthFirst_2(binTree T,int x,int cou)
{
     node *p;
     int y,i;
     p=T.root;
     if(p==NULL && x!=0)
     {
                return 0;
     }
     if(x==0)
     {
            // for(i=0;i<6;i++)
             //{
             // printf("ARRAY\n");
             // printf("  %d  ",a[i]);        
             //}
             return 1;
     }
     printf("    p->data = %d\n",p->data);
     binTree T_1;
     T_1.root=p->left;
     a[cou]=p->data;
     //printf("%d",a[cou]);
     //cou++;
     y= depthFirst_2(T_1,x-p->data,cou+1);
     if(y==1){ return 1;}
     T_1.root=p->right;
     y=depthFirst_2(T_1,x-p->data,cou+1);
     if(y==1) return 1;
}         





node *search(int x,binTree T)
{
     node *p,*q;
     p=T.root;
     while(p!=NULL)
     {
           if(p->data == x)
                       return p;
            else
            {         if(p->data > x)
                                 p=p->left;
                      else if(p->data < x)
                                 p=p->right;
            }      
     }
     return NULL;
}                                             

node *LUB(int x,binTree T)
{
     node *p,*q,*r;
     p=T.root;
     while(p!=NULL)
     { 
            r=p;                   
            if(p->data == x)
                       return p;
            else
            {
                       if(p->data > x)
                                 p=p->left;
                      else if(p->data < x)
                                 p=p->right;
            }      
     }
     if(r->data > x)
                return r;
     else 
     {    
          while(r->data < x)
          {
                        r=r->parent;
                        if(r==NULL);
                                    return NULL;
          }
          return r;
     }    
}
     
int main()
{
          int i,x,y,z,k;
          binTree T;
          node *p,*q;
          T.root=NULL;
          printf("  Enter the elements for the binary tree \n");
          for(i=1;i<6;i++)
          {
                           printf("Enter the %d element   ",i);
                           scanf("%d",&x);
                           insert(x,&T);
          }
          T.root->parent=NULL;
          scanf("%d",&x);
         //k=depthFirst_2(T,x,0);
          k=depthFirst_3(T,x,10);
         printf("VAALUE  %d",k);
      //   printf("\n%d\n",cou);
      //   for(i=0;i<cou;i++)
      //   {
      //                   printf("  %d  ",a[i]);
       //                  } 
         // k=depthFirst(T);
        /*  printf("Enter the integer to be searched  ");
          scanf("%d",&z);
          p=search(z,T);
          if(p==NULL)
                     printf("The number is not present in the TREE \n");
          else
                     printf("Given number exists in the TREE \n");
          printf("Enter the number y  =  ");
          scanf("%d",&y);
          q=LUB(y,T);
          if(q==NULL)
                     printf("Number greater than y cannot be found \n");
          else
          {
                     printf("Number greater than or equal to y is %d\n",q->data);
                     delete(q,&T);
          }
          printf("FINAL TREE IS \n");
          depthFirst(T);
          */
          getch();
}        
        
