#include <iostream>                       
#include<string>
#include<fstream>
#include"book.h"
#include<sstream>
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
    fin.open("book.txt",ios_base::in);//以文本文件格式存取
    string line;
    if(!fin.eof())
    {
        while(getline(fin, line)){
        istringstream str(line);
        prev = new Node;
        str>>(*prev).data.b
        >>(*prev).data.s
        >>(*prev).data.num
        >>(*prev).data.name;
        cout<<(*prev).data;
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
Linklist::~Linklist(){
    Node* temp ;
    temp = head ;
    ofstream fout;//写入文件
    fout.open("book.txt",ios_base::out);
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
void Linklist::AddLinkList(long& num,string& name)
{
    Node *prev = new Node;//分配动态空间
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
    while(temp!=nullptr){
        cout<<(*temp).data;
        temp = temp->next;
    }
}
//查询特定节点
Node* Linklist::GetNode(string& name)
{
    Node* temp = head;
    while(temp!=nullptr){
        if((*temp).data.name==name)
            break;
        temp = temp->next;
    }
    return temp;//找到返回非空指针否则空指针
}
//找到上一个节点位置
Node* Linklist::LastNode(string& name)
{
   Node* last = head;
    while(last!=nullptr){
        if((*last->next).data.name==name)
            break;
        last = last->next;
    }
    return last; 
}
//删除特定节点
void Linklist::deNode(string& name)
{
    Node* temp;
    if(GetNode(name)==head){//删除的是头节点
        temp = head;
        head = head->next;
        --count;
        delete temp;
    }
    else{//非头节点
        Node* last =  LastNode(name);
        temp = last->next;
        last->next = last->next->next;
        delete temp;
        --count;
    }
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
//查找图书名称
string Linklist::getName(string& name)
{
    Node* temp = head;
    while(temp!=nullptr){
        if((*temp).data.name==name)
            return (*temp).data.name;
        temp = temp->next;
    }
    return " ";
}
//添加图书
void Addbook(Linklist &book)
{
    int index;
    cout<<"输入存入的书籍数目"<<endl;
    cin>>index;
    long num;
    string name;
    for(int i=0;i<index;i++){
        cout<<"依次输入图书编号和名称"<<endl;
        cin>>num>>name;
        if(name==book.getName(name)){
        cout<<"该图书《"<<name<<"》已存在，不可添加"<<endl
        <<"还能输入"<<index-i<<"次"<<endl;
        }
        else{
        book.AddLinkList(num,name);
        }
    }
}
//删除图书
void DeleteBook(Linklist &book)
{ 
    string name;
    cout<<"输入要删除的图书名称"<<endl;
    cin>>name;
    if(book.GetNode(name)==nullptr)
    cout<<"该图书《"<<name<<"》不存在，无法删除"<<endl;
    if(book.GetNode(name)->data.s==1)
    cout<<"该图书"<<name<<"已外借，无法删除"<<endl;
    else{
    book.deNode(name);
    cout<<"图书《"<<name<<"》已删除"<<endl;
    cout<<book.GetLength()<<endl;
    }
}
//修改图书
void ReviseBook(Linklist &book)
{ 
    string name;
    cout<<"输入要查找的图书名称"<<endl;
    cin>>name;
    Node* message = book.GetNode(name);
    if(message==nullptr)
    cout<<"该图书《"<<name<<"》不存在，不可修改"<<endl;
    else if((*message).data.s==1)
    cout<<"该图书《"<<name<<"》已外借，不可修改"<<endl;
    else{
    cout<<"请修改图书编号和名称"<<endl;
    cin>>(*message).data;
    cout<<"图书信息已修改"<<endl;
    }
}
//查看图书
void Viewbook(Linklist &book)
{ 
    string name;
    cout<<"输入要查找的图书名称"<<endl;
    cin>>name;
    Node* find = book.GetNode(name);
    if(find==nullptr)
    cout<<"未查找到图书《"<<name<<"》"<<endl;
    else
    cout<<(*find).data<<endl;
}
//借书
void BorrowBook(Linklist &book,ALinklist &reader)
{
    string str1,str2;
    long num1,num2;
    cout<<"输入读者学号与名称"<<endl;
    cin>>num1>>str1;
    ANode* find1 = reader.GetNode(str1);
    if (find1==nullptr)
    cout<<"读者"<<str1<<"不存在,无法借书"<<endl;
    else if((*find1).data.s==1)
    cout<<"读者"<<str1<<"已借书,无法借书"<<endl;
    else{
    cout<<"输入图书编号与名称"<<endl;
    cin>>num2>>str2;
    Node* find2 = book.GetNode(str2);
    if (find2==nullptr)
    cout<<"图书《"<<str2<<"》不存在,无法借书"<<endl;
    else if((*find2).data.s==1)
    cout<<"图书《"<<str2<<"》已外借，无法借书"<<endl;
    else{
    (*find1).data.s = 1;
    (*find2).data.b = 0;
    (*find2).data.s = 1;
    cout<<"已借书"<<endl;
    }
    }
}
//还书
void ReturnBook(Linklist &book,ALinklist &reader)
{
    string str1,str2;
    long num1,num2;
    cout<<"输入读者学号与名称"<<endl;
    cin>>num1>>str1;
    ANode* find1 = reader.GetNode(str1);
    if (find1==nullptr)
    cout<<"读者"<<str1<<"不存在,无法还书"<<endl;
    else if((*find1).data.s==0)
    cout<<"该读者"<<str1<<"无借书,无法还书"<<endl;
    else{
    cout<<"输入图书编号与名称"<<endl;
    cin>>num2>>str2;
    Node* find2 = book.GetNode(str2);
    if (find2==nullptr)
    cout<<"图书《"<<str2<<"》不存在,无法还书"<<endl;
    else if((*find2).data.s==0)
    cout<<"图书《"<<str2<<"》无外借，无法还书"<<endl;
    else{
    (*find1).data.s = 0;
    (*find2).data.b = 1;
    (*find2).data.s = 0;
    cout<<"已还书"<<endl;
    }
    }
}
int  toInt(string& str)
{
    if (str[0] == '-'){//输入为负数
	    for (size_t i = 1; i < str.length(); i++){
			if (str[i] >= '0' && str[i] <= '9')
				continue;
			else{
				cout << "输入的数据中含有非数字" << endl;
				return -1;
                // return 0;
			}
		}
	}
	else{
		for (size_t i = 0; i < str.length(); i++){
			if (str[i] >= '0' && str[i] <= '9')
				continue;
			else{
				cout << "输入的数据中含有非数字" << endl;
				return -1;
                // return 0;
			}
		}
	}
    //功能要求
    int m = stoi(str);
    if(m<1||m>13){
      cout<<"输入的数字无效，有效数字为1~13"<<endl;
    //   return 0;
      return -1;
    }
    return m;//将str转换为int类型 有上界
}