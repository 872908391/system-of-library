#ifndef _READER_H
#define _READER_H
using namespace std;
//读者类
class Reader{
    public:
    Reader();
    friend istream& operator>>(istream& in, Reader&Reader);
    friend ostream& operator<<(ostream& out,Reader&Reader);
    double num; //读者学号
    string name; //读者姓名
    bool b;//读者存在
    bool s;//读者借阅
};
struct ANode{// 节点
    Reader data;//图书数据域
    ANode* next;//指针域
};
//链表部分
class ALinklist{
    public:
    ALinklist();
    ~ALinklist();
    void AddLinkList();//创建添加单链表
    int GetLength();//获取线性表长度
    bool IsEmpty();//判断链表是否为空
    void ShowList();//遍历单链表
    void deLinkList();//清空单链表
    ANode* GetNode(string& name);//查询特定节点
    ANode* LastNode(string& name);//找到上一个节点位置
    void deNode(string& name);//删除特定节点
    private:
    int count;//读者计数
    ANode* head;
    ANode* rear;
};
void Addreader(ALinklist &reader);//添加读者
void Deletereader(ALinklist &reader);//删除读者
void Revisereader(ALinklist &reader);//修改读者
void Viewreader(ALinklist &reader);//查看读者
# endif