#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
        struct node *root;  
}rbtree;


typedef struct node
{
        int data;
        struct node *left;
        struct node *right;
        struct node *parent;
        char colour;                       //for red or black
}node;

rbtree T;
node *delete_single(node *p);
void d1(node *u,node *t);
void c1(node *,node *);
void c2(node *q,node *x);
void c3(node *q,node *x);
void c4(node *q,node *x);
void c5(node *q,node *x);
void depthfirst(rbtree T);     
void right_rot(node *p);
void left_rot(node *p);

node *Search(int j)                                                                 //search function
{
     node *p,*q;
     p=T.root;
     int k=0;
     while(p->left!=NULL && p->right!=NULL)
     {
           k++;
           if(p->data == j)                                                         //if the value is found 
           {
                      printf("  THE NUMBER IS FOUND AT DEPTH    =   %d \n\n",k);    
                      return p;
           }
            else                                                                    //if value is not found     
            {         if(p->data > j)
                                 p=p->left;
                      else if(p->data < j)
                                 p=p->right;           
            }      
     }
     printf("THE NUMBER IS NOT FOUND   \n\n");
     return NULL;
}                                             

     
void insert(int j)
{
     node *p,*q,*u,*s,*t,*x,*y;
     q = (node *)malloc(sizeof(node));
     s = (node *)malloc(sizeof(node));
     u = (node *)malloc(sizeof(node));
     t = (node *)malloc(sizeof(node));
     x = (node *)malloc(sizeof(node));
     y = (node *)malloc(sizeof(node));
     int i,k;
     s->right=NULL;                                                                  //creating last node which is black but has value -1 
     s->left=NULL;
     s->colour='b';
     s->data=-1;
     q->data=j;
     q->right=s;
     q->left=s;
     q->colour='r';
     p=T.root;
     if(p!=NULL)
     {
                while(p->left!=NULL && p->right!=NULL)
                {
                              u=p;
                              if(p->data <= j)
                                         p=p->right;
                              else
                                         p=p->left;
                }
                if(u->data <= j)
                        u->right = q;
                else               
                        u->left = q;
                q->parent = u;
     }                         
     else if(p==NULL)
     {
                     T.root = q;
                     q->colour='b';
                     T.root->parent=NULL;
                     return;
     }
     p=T.root;
     T.root->parent=NULL;
     if(q!=(T.root) && q!= (T.root->left) && q!= (T.root)->right)
     {
                     u=q->parent;
                     t=u->parent;
                     if( t->right == u && t->left != NULL)
                                         x=t->left;
                     else  
                                         x=t->right;
                     c1(q,x);
     }
}
void c1(node *q,node *x)                                                              // case 1 in insert funtion          
{
     node *t,*u;
     if(q!=T.root)
     {          u=q->parent;
                t=u->parent;
     } 
     if(q==T.root)
              q->colour='b';
     else
              c2(q,x);
}

void c2(node *q,node *x)                                                                 //case 2 in insert function
{
     node *t,*u;
     u=q->parent;
     t=u->parent;               
     if(u->colour=='b')
                       return;
     else 
                       c3(q,x);
}

void c3(node *q,node *x)                                                                  //case 3 in insert function        
{
     node *t,*u;
     u=q->parent;
     t=u->parent;
     if( t->right == u && t->left != NULL)
                      x=t->left;
     else  
                      x=t->right;
     if(x->left!=NULL && x->right!=NULL && u->colour == 'r' && x->colour == 'r' )
     {
                      u->colour='b';
                      x->colour='b';
                      t->colour='r';
                      q=t;
                      c1(q,x);
     }
     else
                      c4(q,x);
} 

void c4(node *q,node*x)                                                                    //case 4 in insert function      
{
     node *t,*u,*v;      
     u=q->parent; 
     t=u->parent;
     v = (node *)malloc(sizeof(node));
     if(q == u->right && u == t->left)
     {
          t->left=q;
          v->left=q->left;
          q->left=u;
          u->right=v->left;
          q->parent=t;
          u->parent= q;
          v->left->parent=u;
          q=q->left;
          u=u->parent;
     }
     else if(q == u->left && u == t->right)
     {
          t->right=q;
          v->right=q->right;
          q->right=u;
          u->left=v->right;
          q->parent=t;
          v->right->parent=u;
          u->parent=q;
          q=q->right;
          u=u->parent;
     }
     c5(q,x);
}
 
void c5(node *q,node *x)                                                               //case 5 in insert function           
{
     node *t,*u,*v,*m;      
     u=q->parent; 
     t=u->parent;
     m=t->parent;
     v = (node *)malloc(sizeof(node));
     if(t->parent==NULL)
     {          
            if(q==u->left)
            {
                        v->right=u->right;                            
                        u->right=t;
                        t->left=v->right;
                        t->parent=u;
                        v->right->parent=t;
            }
            else
            {
                        v->left=u->left;
                        u->left=t;
                        t->right=v->left;
                        t->parent=u;
                        v->left->parent=t;
            }
            T.root=u;
     }
     else if(m->left == t && m!=NULL)
     {    
          if(q==u->left)
          {
                        v->right=u->right;                            
                        u->right=t;
                        t->left=v->right;
                        u->parent=m;
                        t->parent=u;
                        v->right->parent=t;
          }
          else
          {
                        v->left=u->left;
                        u->left=t;
                        t->right=v->left;
                        u->parent=m;
                        t->parent=u;
                        v->left->parent=t;
          }
          m->left=u;
     }
     else
     {   
          if(q==u->left)
          {
                        m->right=u;
                        v->right=u->right;                            
                        u->right=t;
                        t->left=v->right;
                        u->parent=m;
                        t->parent=u;
                        v->right->parent=t;
          }
          else
          {
                        m->right=u;
                        v->left=u->left;
                        u->left=t;
                        t->right=v->left;
                        u->parent=m;
                        t->parent=u;
                        v->left->parent=t;
          }
     }                   
     u->colour='b';
     t->colour='r';
     return;
}

void delete(int j)                                                                            
{
     node *p,*q,*r,*u,*t,*x;
     int k=0,n=0;
     p = (node *)malloc(sizeof(node));
     r = (node *)malloc(sizeof(node));
     p=Search(j);
     if(p==NULL)
                return;
     if(p->colour =='r')
                  k=1;             
     else 
                  k=0;
     if(p->left->data==-1 || p->right->data==-1)
                  r=delete_single(p);                       // r is child of deleted node i.e r is doubly child
     else
     {
           q=p->right;
           while(q->left->data!=-1)
                  q=q->left;
           p->data=q->data;
           r=delete_single(q);
     }
     if(r==NULL)
                return;
     u=r->parent;
     if(k==1)
            return;
     else
     {      
            if(r->colour=='r')
            {
                             r->colour='b';
                             return;      
            }     
            else
            {   
                while(1)
                {
                             u=r->parent;
                             if(r==u->left)
                             {
                                           t=u->right;
                                           if(t->colour=='r')
                                           {
                                                             u->colour='r';
                                                             t->colour='b';
                                                             left_rot(u);                                                                    
                                           }
                                           else
                                           {
                                                              if(t->right->colour == 'b' && t->left->colour == 'b')
                                                              {                 
                                                                                d1(u,t);
                                                                                r=r->parent;
                                                              } 
                                                              else if(t->left->colour == 'r' && t->right->colour == 'b')
                                                              {
                                                                                t->left->colour='b';
                                                                                t->colour='r';
                                                                                right_rot(t);
                                                                                
                                                              }  
                                                              else if(t->right->colour=='r')
                                                              {
                                                                                x=t->right;
                                                                                u->colour='b';
                                                                                t->colour=u->colour;
                                                                                x->colour='b';
                                                                                left_rot(u);
                                                              }
                                                              else
                                                                                n=10;                    
                                                                                                                                               
                                           }
                                           if(n=10)                                                                                    
                                                              break;
                             }                                     
                             else
                             {
                                           t=u->left;
                                           if(t->colour=='r')
                                           {
                                                             u->colour='r';
                                                             t->colour='b';
                                                             right_rot(u);                                                                    
                                           }
                                           else
                                           {
                                                              if(t->left->colour == 'b' && t->right->colour == 'b')
                                                              {                 
                                                                                d1(u,t);
                                                                                r=r->parent;
                                                              } 
                                                              else if(t->right->colour == 'r' && t->left->colour == 'b')
                                                              {
                                                                                t->right->colour='b';
                                                                                t->colour='r';
                                                                                left_rot(t);
                                                              }  
                                                              else if(t->left->colour=='r')
                                                              {
                                                                                x=t->left;
                                                                                u->colour='b';
                                                                                t->colour=u->colour;
                                                                                x->colour='b';
                                                                                right_rot(u);
                                                              }
                                                              else
                                                                                n=10;
                                           }
                                           if(n=10)
                                                              break; 
                             }
                
                }
            }
            return ; 
     }
}                     

void d1(node *u,node *t)
{
     t->colour='r';
     u->colour='b';
     return;
}

void right_rot(node *p)
{
     node *q,*r,*t,*v;
     v = (node *)malloc(sizeof(node));
     r=p->left;
     t=p->right;
     v->left = r->right;
     r->right=p;
     p->left=v->left;
     v->left->parent=p;
     if(p!=T.root)
     {            q=p->parent;
                  r->parent=q;
                  if(p==q->left)
                                q->left=r;
                  else
                                q->right=r;
     }
     else 
                  T.root=r;
     p->parent=r;
}

void left_rot(node *p)
{
     node *q,*r,*t,*v;
     v = (node *)malloc(sizeof(node));
     r=p->left;
     t=p->right;
     v->left = t->left;
     t->left=p;
     p->right=v->left;
     v->left->parent=p;
     if(p!=T.root)
     {            q=p->parent;
                  t->parent=q;
                  if(p==q->left)
                                q->left=t;
                  else
                                q->right=t;
     }
     else 
                  T.root=t;
     p->parent=t;
}
     
node *delete_single(node *p)
{
     node *q,*r,*t,*x;
     x = (node *)malloc(sizeof(node));
     if(p->left->data==-1)
     {               
                   q=p->right;
                   r=p->parent;
                   if(T.root == p)
                   {
                             T.root=q;
                             q->colour='b';
                             return NULL;
                   }
                   else
                   {
                             if(r->right==p)
                             {        if(p->right->data==-1)
                                      {                  
                                                         p->data=-1;
                                                         p->right=NULL;
                                                         p->left=NULL;
                                                         p->parent=r;
                                                         return(p);
                                      }
                                      r->right=q;
                                      q->parent=r;
                                      return(q);
                             }
                             else
                             {        
                                      if(p->right->data==-1)
                                      {                  
                                                         p->data=-1;
                                                         p->right=NULL;
                                                         p->left=NULL;
                                                         p->parent=r;
                                                         return(p);
                                      }
                                      r->left=q;
                                      q->parent=r;
                                      return(q);
                             }
                   }  
     }
     else if(p->right->data==-1)
     {    
                   q=p->left;
                   r=p->parent;
                   if(T.root == p)
                   {
                             T.root=q;
                             q->colour='b';
                             return NULL;
                   }
                   else 
                   {
                             if(r->right==p)
                             {        
                                      if(p->left->data==-1)
                                      {                  
                                                         p->data=-1;
                                                         p->right=NULL;
                                                         p->left=NULL;
                                                         p->parent=r;
                                                         return(p);
                                      }
                                      r->right=q;
                                      q->parent=r;
                                      return(q);
                             }
                             else
                             {        
                                      if(p->left->data==-1)
                                      {                  
                                                         p->data=-1;
                                                         p->right=NULL;
                                                         p->left=NULL;
                                                         p->parent=r;
                                                         return(p);
                                      }
                                      r->left=q;
                                      q->parent=r;
                                      return(q);
                             }         
                     }    
     }
     free(p);
}

int main()
{
    int n,i,j,x,z;
    node *a;
    a = (node *)malloc(sizeof(node));
    printf("Enter the value of n ");
    scanf("%d",&n);
    T.root=NULL;
    for(i=0;i<n;i++)
    {
                    printf("Enter the %d element ",i+1);
                    scanf("%d",&j);
                    insert(j);
    }
    for(i=0;i<n;i++)
    {
                    printf("print the number to be deleted   ");
                    scanf("%d",&z);
                    delete(z);
    }
    
}
