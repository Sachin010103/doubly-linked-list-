#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int element){
         this->data=element;
         this->next=NULL;
         this->prev=NULL;
    }
};

void athead(node*& head,int element){
     node* temp=new node(element);
    if(head==NULL){
         head=temp;
         return;
    }
   
    head->prev=temp;
    temp->next=head;
    head=temp;
}



void atposition(node*& head,int position,int element){
    node* x=new node(element);
    if(head==NULL){
        head=x;
        return;
    }

     if(position==1){
        athead(head,element);
        return;
    }

    node* temp=head;
     
    auto count=1;
    while (count<position-1 && temp->next!=NULL)
    {
       temp=temp->next;
       count++;
    }

   if(temp->next==NULL){
    temp->next=x;
    x->prev=temp;
    return;
   }

   x->next=temp->next;
   temp->next->prev=x; 
   temp->next=x;
   x->prev=temp;
}


void insertattail(node*& tail,int element){

   node* x=new node(element);
    node* temp=tail;
    while(temp->next!=NULL){
        temp=temp->next;
    }
   
     temp->next=x;
     x->prev=temp;

}

/// delete at postion

void deletepostion(node*& head,int position){

       if(position==1){
        head=head->next;
        return;
       }
  
        node* curr=head;
        node* prev=NULL;
        
        auto count=1;
        while (count<position && curr->next!=NULL)
        { 
              prev=curr;
              curr=curr->next;
              count++;
        }

          if(curr->next==NULL){
            prev->next=NULL;
            curr->prev=NULL;
            delete curr;
            return;
        }  
        prev->next=curr->next;
        curr->next->prev=prev;

        curr->next=NULL;
        curr->prev=NULL;

        delete curr;

}


void print(node* head){
    while (head!=NULL)
    {
 
         cout<<head->data<<" ";
         head=head->next;
 
 
    }
    cout<<endl;
}

int main(){
     node* head=NULL;
     athead(head,1);
     print(head);

      athead(head,2);
     print(head);
    
    insertattail(head,23);
    print(head);

    insertattail(head,100);
    print(head);
    
    atposition(head,2,200);
    print(head);

    atposition(head,1,300);
    print(head);

    atposition(head,8,1000);
    print(head);
    
   deletepostion(head,2);
     print(head);  
   deletepostion(head,1);
     print(head);  
   
    deletepostion(head,1);
     print(head); 
    deletepostion(head,4);
     print(head); 
      
}