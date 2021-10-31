#include <iostream>                       
#include<cstring>
#include<fstream>
#include"Reader.h"
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
    while(fin.peek()!=EOF){
        prev = new ANode;
        fin.read((char *)&(*prev), sizeof(ANode));
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
ALinklist::~ALinklist(){
    ANode* temp ;
    temp = head ;
    ofstream fout;//写入文件
    fout.open("reader.txt",ios_base::out);
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
//创建添加单链表
void ALinklist::AddLinkList()
{
    ANode *prev;
    prev = new ANode;//分配动态空间
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
    return temp;
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
    if(GetNode(name)==head){
        temp = head;
        head = head->next;
        --count;
        delete temp;
    }
    else{
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
//添加读者
void Addreader(ALinklist &reader)
{
   int index;
    cout<<"输入存入的读者数目"<<endl;
    cin>>index;
    for(int i=0;i<index;i++){
        cout<<"依次输入读者编号和名称"<<endl;
        reader.AddLinkList();
    }
}
//删除读者
void Deletereader(ALinklist &reader)
{
    string name;
    cout<<"输入要删除的读者名称"<<endl;
    cin>>name;
    reader.deNode(name);
    cout<<"读者已删除"<<endl;
    cout<<reader.GetLength()<<endl;
}
//修改读者
void Revisereader(ALinklist &reader)
{
    string name;
    cout<<"输入要查找的读者名称"<<endl;
    cin>>name;
    ANode* message = reader.GetNode(name);
    cout<<"请修改读者编号和名称"<<endl;
    cin>>(*message).data;
    cout<<"读者信息已修改"<<endl;
}
//查看读者
void Viewreader(ALinklist &reader)
{
    string name;
    cout<<"输入要查找的读者名称"<<endl;
    cin>>name;
    ANode* find = reader.GetNode(name);
    cout<<(*find).data<<endl;
}