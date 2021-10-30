#ifndef _BOOK_H
#define _BOOK_H
using namespace std;
class Book{
    public:
    Book();
    friend istream& operator>>(istream& in, Book&book);
    friend ostream& operator<<(ostream& out, Book&book);
    double num;//图书编号
    string name;//图书名称
    bool b;//是否存在
    bool s;//是否借阅
};
 struct Node{// 节点
    Book data;//数据域
    Node* next;//指针域
};
//链表部分
class Linklist{
    public:
    Linklist();
    ~Linklist();
    void AddLinkList();//创建添加单链表
    int GetLength();//获取线性表长度
    bool IsEmpty();//判断链表是否为空
    void ShowList();//遍历单链表
    void deLinkList();//清空单链表
    Node* GetNode(string& name);//查询特定节点
    Node* LastNode(string& name);//找到上一个节点位置
    void deNode(string& name);//删除特定节点
    private:
    int count;
    Node* head;
    Node* rear;
};
# endif
void Addbook();//添加图书
//删除图书
//修改图书
//查看图书