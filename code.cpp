//Program to print a binary tree in levelwise zigzag

#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
       int info;
       node*left;
       node*right;
       node*next;       
       
       node()
       {
             next=NULL;
       }
}*tree;



class stack
{
      public:
             node*top;
             
      void push(node*t)
      {
                  t->next=top;
                  top=t;
      }
      
      node* pop()
      {
           cout<<top->info<<",";
           top=top->next;
           return top;
      }
      
      stack()
      {
             top=NULL;
      }
      
}s1,s2;
           


node* insert(node**tree,int n)
{
      node*temp;
      temp=(node*)malloc(sizeof(node));
      temp->info=n;
      temp->left=NULL;
      temp->right=NULL;
      
      if(*tree==NULL)
                        *tree=temp;
      else
      {
          node*root;
          root=*tree;
          while(1)
          {
                  if(((root->info)>n)&&((root->left)==NULL))
                  {
                                                         root->left=temp;
                                                         break;
                  }   
                  else
                  if(((root->info)<n)&&((root->right)==NULL))
                  {
                                                       root->right=temp;
                                                       break;
                  }
                  
                  else
                      if((root->info)>n)
                                     root=root->left;
                      else
                          root=root->right;
                                                                      
          }
          
          
      }
      
     
}
      
      
void display(node*t)
{
     
     s1.push(t->left);
     s1.push(t->right);
     cout<<t->info<<",";
     do
     {
                    
                              while(s1.top!=NULL)
                              {
                                             t=s1.pop();
                                             if(t->right!=NULL)
                                                               s2.push(t->right);
                                             if(t->left!=NULL)
                                                              s2.push(t->left);
                              }
                              
                              while(s2.top!=NULL)
                              {
                                             t=s2.pop();
                                             if(t->left!=NULL)
                                                               s1.push(t->left);
                                             if(t->right!=NULL)
                                                               s1.push(t->right);
                              }
                                             
     }while(s1.top!=NULL&&s2.top!=NULL);                                       
}

int main()
{
    cout<<"Create tree:";
    char ch='Y';
    int n;
    
    while(toupper(ch)=='Y')
    {
                           cout<<"\nEnter number:";
                           cin>>n;
                           insert(&tree,n);
                           cout<<"Want to continue?";
                           cin>>ch;
    }
    
    display(tree);
    getch();
}
