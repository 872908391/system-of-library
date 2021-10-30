#include <iostream>                       
#include<cstring>
#include<fstream>
#include"book.h"
using namespace std;
//初始化
Book::Book()
{
    b = 0;
    s = 0;
}
//初始化链表
Linklist::Linklist(){
    head = rear = nullptr;
    count = 0;
}
Linklist::~Linklist(){
    Node* temp ;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
}
//重载>>运算符
istream& operator>>(istream& in, Book& book)
{
    in>>book.num>>book.name;
    return in;
}
//重载>>运算符
ostream& operator<<(ostream& out, Book&book)
{
    out<<"图书名称："<<book.name<<"\n图书编号:"
    <<book.num<<"\n图书存在:"<<book.b<<"\n图书借阅: "<<book.s<<endl;
    return out;
}
//创建添加单链表
void Linklist::AddLinkList()
{
    Node *prev;
    prev = new Node;//分配动态空间
    cout<<"依次输入图书编号和名称"<<endl;
    cin >>(*prev).data;
    (*prev).data.b = 1;
    (*prev).data.s = 0;
    prev->next = NULL;
    if(head == NULL)
    head = prev;
    else
    rear->next = prev;
    rear = prev; 
    ++count;
}
//获取线性表长度
int Linklist::GetLength()
{
    return count;
    cout<<count<<endl;
}
//判断链表是否为空
bool Linklist::IsEmpty()
{
    return count;
}
//遍历单链表
void Linklist::ShowList()
{   
    Node* temp = head;
    while(temp!=NULL){
        cout<<(*temp).data;
        temp = temp->next;
    }
}
//查询特定节点
Node* Linklist::GetNode(string& name)
{
    Node* temp = head;
    while(temp!=NULL){
        if((*temp).data.name==name)
            break;
        temp = temp->next;
    }
    return temp;
}
//找到上一个节点位置
Node* Linklist::LastNode(string& name)
{
   Node* last = head;
    while(last!=NULL){
        if((*last->next).data.name==name)
            break;
        last = last->next;
    }
    return last; 
}
//删除特定节点
void Linklist::deNode(string& name)
{
    Node* last =  LastNode(name);
    Node* temp = last->next;
    last->next = last->next->next;
    delete temp;
    --count;
}
//清空单链表
void Linklist::deLinkList()
{
    Node* temp ;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
        --count;
    }
}
//添加图书
void Addbook()
{
    Linklist book;
    int index;
    cout<<"输入存入的书籍数目"<<endl;
    cin>>index;
    for(int i=0;i<index;i++)book.AddLinkList();
}
//删除图书
//修改图书
//查看图书