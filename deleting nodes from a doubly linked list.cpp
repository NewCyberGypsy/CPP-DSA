#include<iostream>
#include<string.h>
using namespace std;
class node
{
  public:
  int data;
  node*next;
  node*prev;
}*head=NULL,*tail=NULL;
void node1(int n)
{
  node *t=new node;
  t->data=n;
  t->next=NULL;
  t->prev=NULL;
  head=tail=t;
}
void othernodes(int n)
{
  node *t=new node;
  t->data=n;
  tail->next=t;
  t->prev=tail;
  tail=t;

}
void delfrombeg()
{
  node*temp=head;
  head=head->next;
  head->prev=NULL;
  free(temp);
}
void delfromlast()
{
  node*temp=tail;
  tail=tail->prev;
  tail->next=NULL;
  free(temp);
}
void delfrompos(int n)
{
  node*temp=head;
  node*q;
  int i=1;
  while(i<n-1)
  {
    temp=temp->next;
    i++;
  }
  q=temp->next;
  temp->next=q->next;
  q->next->prev=temp->next;
  free(q);


}
void display()
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head=head->next;
  }
}
int main()
{
  int p,l,i=0;
  cout<<"Enter the value in the first node: ";
  cin>>p;
  node1(p);
  char n[3];
  while(i>=0){
  cout<<"Do you want to add a new node :\nEnter Yes or No :";
  cin>>n;
  if(strcmp(n,"yes")==0||strcmp(n,"Yes")==0){
  cout<<"Enter value for the next node:";
  cin>>l;
  othernodes(l);
  }
  else {
  cout<<"Dhanyawaad aapka\n";
  break;
  }
  }
  delfrombeg();
  delfrompos(3);
  delfromlast();
  display();

}
