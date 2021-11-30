#include <iostream>                       
#include<string>
#include<fstream>
#include"book.h"
#include"Reader.h"
using namespace std;
int main()
{
    string str;
    int i;
    Linklist book;
    ALinklist reader;
    while(true){
    cout << "1、增加图书    2、删除图书"<<endl;
    cout << "3、修改图书    4、查找图书"<<endl;
    cout << "5、增加读者    6、删除读者"<<endl;
    cout << "7、修改读者    8、查找读者"<<endl;
    cout << "9、借书功能   10、还书功能"<<endl;
    cout << "11、遍历图书   12、遍历读者"<<endl;
    cout <<"13、退出"<<endl;
    cout <<"输入以下功能的序号"<<endl;
    cin>>str;
    i = toInt(str);
    if(i==13){
        cout<<"正在退出"<<endl;
        break;
    }
    switch(i){
    case 1:Addbook(book);break;
    case 2:DeleteBook(book);break;
    case 3:ReviseBook(book);break;
    case 4:Viewbook(book);break;
    case 5:Addreader(reader);break;
    case 6:Deletereader(reader);break;
    case 7:Revisereader(reader);break;
    case 8:Viewreader(reader);break;
    case 9:BorrowBook(book,reader);break;
    case 10:ReturnBook(book,reader);break;
    case 11:book.ShowList();break;
    case 12:reader.ShowList();break;
    default:break;
    }
    }
    cout<<"已退出"<<endl;
    return 0;
}