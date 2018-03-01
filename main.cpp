/*In practice, better to make class variables private rather than public
* If you want to change the value of a linked list object from main routine by subroutines, especially when you 
* need to change the head, you MUST call by reference
*/

#include <iostream>

using namespace std;

class node{
public:
  int n;
  node* next;
  node(int _n):n{_n},next{NULL} {}
  node(int _n, node* _next) {n=_n;next=_next;}
};

class LList{
public:
  node *head;
  LList():head{NULL} {}
  void reverse();
  void insert(int n);
  ~LList();
  void display();
  
};

void LList::reverse(){
  if(head==NULL || head->next==NULL)
    return;
    
  node* prev=head;
  node* curr=prev->next;
  
  prev->next=NULL;
  while(curr!=NULL){
    node* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
    
  }
  head=prev;
  return;
}



LList::~LList(){
  if(!head)
    return;
  if(!head->next){
    delete head;
    return;
  }
  
  node* prev=head;
  node* curr=prev->next;
  
  while(!curr){
    delete prev;
    prev=curr;
    curr=curr->next;
  }
  delete prev;
  return;
}

void LList::display(){
  node* curr=head;
  
  while(curr!=NULL){
    cout<<curr->n<<" ";
    curr=curr->next;
  }
  cout<<endl;
  return;
}

void LList::insert(int n){
  if(!head){
    head=new node(n);
    return;
  }
  
  if(head->n > n){
    head=new node(n,head);
    return;
  }
  
  node *prev=head;
  node *curr=head->next;
  
  while(curr!=NULL){
    if(curr->n > n){
      prev->next=new node(n,curr);
      return;
    }
    else{
      prev=curr;
      curr=prev->next;
    }
  }
  
  prev->next=new node(n);
  return;
  
}


int main() {
  LList mylist;
  mylist.insert(10);
  mylist.insert(9);
  mylist.insert(30);
  mylist.insert(60);
  mylist.insert(50);
  mylist.insert(11);
  mylist.insert(1);
  mylist.display();
  
  mylist.reverse();
  mylist.display();
  
}
