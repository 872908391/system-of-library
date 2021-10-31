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
    Node* prev;
    ifstream fin;//读取文件
    fin.open("book.txt",ios_base::in);
    while(fin.peek()!=EOF){
        prev = new Node;
        fin.read((char *)&(*prev), sizeof(Node));
        prev->next = nullptr;
        if(head==NULL){
            head = prev;
        }
        else{
            rear->next = prev;
            rear = prev; 
        }
    }
    fin.close();
}
Linklist::~Linklist(){
    Node* temp ;
    temp = head ;
    ofstream fout;//写入文件
    fout.open("book.txt",ios_base::out);
    while(temp != nullptr){
        fout.write((char *)&temp, sizeof(temp));
        temp = temp->next;
    }
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    fout.close();
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
    Node *prev = new Node;//分配动态空间
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
void Addbook(Linklist &book)
{
    int index;
    cout<<"输入存入的书籍数目"<<endl;
    cin>>index;
    for(int i=0;i<index;i++){
        cout<<"依次输入图书编号和名称"<<endl;
        book.AddLinkList();
    }
}
//删除图书
void DeleteBook(Linklist &book)
{ 
    string name;
    cout<<"输入要删除的图书名称"<<endl;
    cin>>name;
    book.deNode(name);
    cout<<"图书已删除"<<endl;
    cout<<book.GetLength()<<endl;
}
//修改图书
void ReviseBook(Linklist &book)
{ 
    string name;
    cout<<"输入要查找的图书名称"<<endl;
    cin>>name;
    Node* message = book.GetNode(name);
    cout<<"请修改图书编号和名称"<<endl;
    cin>>(*message).data;
    cout<<"图书信息已修改"<<endl;
}
//查看图书
void Viewbook(Linklist &book)
{ 
    string name;
    cout<<"输入要查找的图书名称"<<endl;
    cin>>name;
    Node* find = book.GetNode(name);
    cout<<(*find).data<<endl;
}
//借书
void BorrowBook(Linklist &book,ALinklist &reader)
{
    string str1,str2;
    double num1,num2;
     cout<<"输入读者学号与名称"<<endl;
    cin>>num1>>str1;
    ANode* find1 = reader.GetNode(str1);
    (*find1).data.s = 0;
    cout<<"输入图书编号与名称"<<endl;
    cin>>num2>>str2;
    Node* find2 = book.GetNode(str2);
    (*find1).data.b = 0;
    (*find1).data.s = 1;
    cout<<"已借书"<<endl;
}
//还书
void ReturnBook(Linklist &book,ALinklist &reader)
{
    string str1,str2;
    double num1,num2;
    cout<<"输入读者学号与名称"<<endl;
    cin>>num1>>str1;
    ANode* find1 = reader.GetNode(str1);
    (*find1).data.s = 0;
    cout<<"输入图书编号与名称"<<endl;
    cin>>num2>>str2;
    Node* find2 = book.GetNode(str2);
    (*find1).data.b = 1;
    (*find1).data.s = 0;
    cout<<"已还书"<<endl;
}