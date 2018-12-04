#include <iostream>
#include "Message.h"
#ifndef MARMOSET_TESTING
int main(){
int b=-3;
std::string c="";
Message newmessage;
std::cin>>b;
while(b!=-2){
  if(b==-1){
  newmessage.print_message();
  }else{
  std::cin>>c;
  newmessage.insert(b,c);
  }
  std::cin>>b;
}
return 0;
}
#endif

Node::Node ( unsigned int id, std::string frag){
  this->identifier=id;
  this->fragment=frag;
  this->p_next=nullptr;
}

std::string Node::get_fragment()
{
  return this->fragment;
}

Node *Node::get_next(){
  return this->p_next;
}

Message::Message(){
  this->head=nullptr;
}

Message::~Message(){
Node *temp1{this->head};
while(temp1!=nullptr){
  Node *temp2=temp1->p_next;
  delete temp1;
  temp1=temp2;
}
head=0;
}

void Message::insert( unsigned int id, std::string fragment){
  Node *newnode=new Node(id,fragment);
  if(head==nullptr){
    head=newnode;
    newnode->p_next=nullptr;
  }
  else if (id<head->identifier){
    newnode->p_next=head;
    head=newnode;
  }else{
    Node *tempnode=head;
    while((tempnode->p_next != nullptr)&&(tempnode->p_next->identifier<id)){
      tempnode=tempnode->p_next;
    }
    newnode->p_next=tempnode->p_next;
    tempnode->p_next=newnode;
  }
  // for(Node *test{head};test!=nullptr;test=test->p_next){
  //   std::cout<<test->get_fragment();
  // }
}


  // if(head==nullptr){
  //   head=new Node{id,fragment};
  // }else if(head->identifier>id){
  //   Node *temp1{head};
  //   head=new Node{id,fragment};
  //   head->p_next=temp1;
  //
  // }else if(head->identifier==id) {
  //   Node *temp1{head->p_next};
  //   head=new Node{id,fragment};
  //   head->p_next=temp1;
  // }else{
  //   Node *temp1{head};
  //   Node *temp2{nullptr};
  //   if(head->p_next==nullptr){
  //     temp2=new Node{id,fragment};
  //     head->p_next=temp2;
  //   }else{
  //     do{temp2=temp1;
  //       temp1=temp1->p_next;
  //     }while ((temp1->identifier<id)&&(temp1!=nullptr));
  //
  //       Node *temp3=new Node{id,fragment};
  //       temp2->p_next=temp3;
  //       temp3->p_next=temp1;
  // //
  // //   }
  // }


void Message::print_message(){
  Node *temp1{head};
  while(temp1->p_next!=nullptr){
    temp1=temp1->p_next;
  }
  unsigned int b=0;
  b=temp1->identifier;
  Node *temp2{head};
  for(unsigned int a{0};a<temp2->identifier;a++){
      std::cout<<"... ";
    }
    // int count = 0;
  for(unsigned int a{temp2->identifier};a<=b;a++){
    if(temp1->fragment=="EOT"){
      if(a==b){break;}
      if(a==temp2->identifier){
        if(temp2!=head){
          std::cout<<" ";
        }
         std::cout<<temp2->fragment;
         temp2=temp2->p_next;
          // if(temp2->p_next->fragment !="EOT"){ temp2=temp2->p_next;}
          // else{count=temp1->identifier-temp2->identifier;}
       }else{

         std::cout<<" ...";
       }


    }else{
      if(a==b){
        std::cout<<temp2->fragment<<" ???";
        break;}
      if(a==temp2->identifier){
          if(temp2!=head){
            std::cout<<" ";
          }
         std::cout<<temp2->fragment;
           temp2=temp2->p_next;

       }else{
         std::cout<<" ...";
       }

       // if(temp2->fragment != "EOT"){
       //   std::cout<<" ";
       // }
    }

      }
      std::cout << std::endl;
}
