#include <iostream>                       
#include<string>
#include<fstream>
#include"Reader.h"
#include<sstream>
using namespace std;
istream& operator>>(istream& in, Reader&Reader)
{
   in>>Reader.num>>Reader.name;
   return in;
}
ostream& operator<<(ostream& out, Reader&Reader)
{
    out<<"读者名称："<<Reader.name<<"\n读者编号:"
    <<Reader.num<<"\n读者存在:"<<Reader.b<<"\n读者借阅:"<<Reader.s<<endl;
    return out;
}
//初始化
Reader::Reader()
{
    b = 0;
    s = 0;
}
//初始化链表
ALinklist::ALinklist(){
    head = rear = nullptr;
    count = 0;
    ANode *prev;
    ifstream fin;//读取文件
    fin.open("reader.txt",ios_base::in);
    string line;
    if(!fin.eof())
    {
        while(getline(fin, line)){
        istringstream str(line);
        prev = new ANode;
        str>>(*prev).data.b
        >>(*prev).data.s
        >>(*prev).data.num
        >>(*prev).data.name;
        // cout<<(*prev).data;
        prev->next = nullptr;
        if(head==nullptr){
            head = prev;
        }
        else
            rear->next = prev;
        rear = prev; 
    }
    }
    fin.close();
}
ALinklist::~ALinklist(){
    ANode* temp ;
    temp = head ;
    ofstream fout;//写入文件
    fout.open("reader.txt",ios_base::out);
    while(temp != nullptr){
        fout<<(*temp).data.b<<" ";
        fout<<(*temp).data.s<<" ";
        fout<<(*temp).data.num<<" ";
        fout<<(*temp).data.name<<"\n";
        temp = temp->next;  
    }
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
    fout.close();
}
//创建添加单链表
void ALinklist::AddLinkList(long& num,string& name)
{
    ANode *prev = new ANode;//分配动态空间
    (*prev).data.num = num;
    (*prev).data.name = name;
    (*prev).data.b = 1;
    (*prev).data.s = 0;
    prev->next = nullptr;
    if(head == nullptr)
    head = prev;
    else
    rear->next = prev;
    rear = prev; 
    ++count;
}
//获取线性表长度
int ALinklist::GetLength()
{
    return count;
    cout<<count<<endl;
}
//判断链表是否为空
bool ALinklist::IsEmpty()
{
    return count;
}
//遍历单链表
void ALinklist::ShowList()
{   
    ANode* temp = head;
    while(temp!=NULL){
        cout<<(*temp).data;
        temp = temp->next;
    }
}
//查询特定节点
ANode* ALinklist::GetNode(string& name)
{
    ANode* temp = head;
    while(temp!=NULL){
        if((*temp).data.name==name)
            break;
        temp = temp->next;
    }
    return temp;//找到返回非空指针否则空指针
}
//找到上一个节点位置
ANode* ALinklist::LastNode(string& name)
{
   ANode* last = head;
    while(last!=NULL){
        if((*last->next).data.name==name)
            break;
        last = last->next;
    }
    return last; 
}
//删除特定节点
void ALinklist::deNode(string& name)
{
    ANode* temp;
    if(GetNode(name)==head){//删除的是头节点
        temp = head;
        head = head->next;
        --count;
        delete temp;
    }
    else{//非头节点
        ANode* last =  LastNode(name);
        temp = last->next;
        last->next = last->next->next;
        delete temp;
        --count;
    }
}
//清空单链表
void ALinklist::deLinkList()
{
    ANode* temp ;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
        --count;
    }
}
//查找图书名称
string ALinklist::getName(string& name)
{
    ANode* temp = head;
    while(temp!=nullptr){
        if((*temp).data.name==name)
            return (*temp).data.name;
        temp = temp->next;
    }
    return " ";
}
//添加读者
void Addreader(ALinklist &reader)
{
   int index;
    cout<<"输入存入的读者数目"<<endl;
    cin>>index;
    long num;
    string name;
    for(int i=0;i<index;i++){
        cout<<"依次输入读者编号和名称"<<endl;
        cin>>num>>name;
        if(name==reader.getName(name))
        cout<<"该读者已存在，不可添加"<<endl
        <<"还能输入"<<index-i<<"次"<<endl;
        else
        reader.AddLinkList(num,name);
    }
}
//删除读者
void Deletereader(ALinklist &reader)
{
    string name;
    cout<<"输入要删除的读者名称"<<endl;
    cin>>name;
    if(reader.GetNode(name)==nullptr)
    cout<<"该读者"<<name<<"不存在，无法删除"<<endl;
    if(reader.GetNode(name)->data.s==1)
    cout<<"该读者"<<name<<"已借书，无法删除"<<endl;
    else{
    reader.deNode(name);
    cout<<"读者已删除"<<endl;
    cout<<reader.GetLength()<<endl;
    }
}
//修改读者
void Revisereader(ALinklist &reader)
{
    string name;
    cout<<"输入要查找的读者名称"<<endl;
    cin>>name;
    ANode* message = reader.GetNode(name);
    if(message==nullptr)
    cout<<"该读者"<<name<<"不存在，不可修改"<<endl;
    else if((*message).data.s==1)
    cout<<"读者"<<name<<"已借书，不可修改"<<endl;
    else{
    cout<<"请修改读者编号和名称"<<endl;
    cin>>(*message).data;
    cout<<"读者信息已修改"<<endl;
    }
}
//查看读者
void Viewreader(ALinklist &reader)
{
    string name;
    cout<<"输入要查找的读者名称"<<endl;
    cin>>name;
    ANode* find = reader.GetNode(name);
    if(find==nullptr)
    cout<<"未找到读者"<<name<<endl;
    else
    cout<<(*find).data<<endl;
}