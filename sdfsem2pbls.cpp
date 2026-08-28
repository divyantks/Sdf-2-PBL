#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class LibraryItem
{
protected:
    int id;
    string title;
    bool issued;

public:
    LibraryItem(int i=0,string t="",bool is=false)
    {
        id=i;
        title=t;
        issued=is;
    }

    virtual void display()=0;
    virtual void issue()=0;
    virtual void returnItem()=0;
    virtual void write(ofstream &out)=0;

    int getId()
    {
        return id;
    }

    bool isIssued()
    {
        return issued;
    }

    virtual ~LibraryItem(){}
};

class Book:public LibraryItem
{
    string author;

public:
    Book(int i=0,string t="",string a="",bool is=false):LibraryItem(i,t,is)
    {
        author=a;
    }

    void display()
    {
        cout<<"[Book] ID:"<<id<<" Title:"<<title<<" Author:"<<author<<" Status:"<<(issued?"Issued":"Available")<<endl;
    }

    void issue()
    {
        if(!issued)
        {
            issued=true;
            cout<<"Book Issued\n";
        }
        else
        {
            cout<<"Already Issued\n";
        }
    }

    void returnItem()
    {
        if(issued)
        {
            issued=false;
            cout<<"Book Returned\n";
        }
        else
        {
            cout<<"Not Issued\n";
        }
    }

    void write(ofstream &out)
    {
        out<<"BOOK\n";
        out<<id<<endl;
        out<<title<<endl;
        out<<author<<endl;
        out<<issued<<endl;
    }
};

class ReferenceBook:public LibraryItem
{
public:
    ReferenceBook(int i=0,string t="",bool is=false):LibraryItem(i,t,is)
    {
    }

    void display()
    {
        cout<<"[Reference] ID:"<<id<<" Title:"<<title<<" Status:Reference Only"<<endl;
    }

    void issue()
    {
        cout<<"Cannot issue reference book\n";
    }

    void returnItem()
    {
        cout<<"Not applicable\n";
    }

    void write(ofstream &out)
    {
        out<<"REF\n";
        out<<id<<endl;
        out<<title<<endl;
        out<<issued<<endl;
    }
};

class Library
{
    vector<LibraryItem*>items;

public:
    void load()
{
    ifstream in("data.txt");

    if(!in)
        return;

    while(true)
    {
        string type;
        getline(in,type);

        if(in.eof() || type=="")
            break;

        if(type=="BOOK")
        {
            int id;
            string title,author;
            bool issued;

            in>>id;
            in.ignore(100,'\n');
            getline(in,title);
            getline(in,author);
            in>>issued;
            in.ignore(100,'\n');

            items.push_back(new Book(id,title,author,issued));
        }
        else if(type=="REF")
        {
            int id;
            string title;
            bool issued;

            in>>id;
            in.ignore(100,'\n');
            getline(in,title);
            in>>issued;
            in.ignore(100,'\n');

            items.push_back(new ReferenceBook(id,title,issued));
        }
    }

    in.close();
}

    void save()
    {
        ofstream out("data.txt");

        for(auto item:items)
        {
            item->write(out);
        }

        out.close();
    }

    void addBook()
    {
        int id;
        string title,author;

        cout<<"Enter ID:";
        cin>>id;
        cin.ignore(100,'\n');

        cout<<"Enter Title:";
        getline(cin,title);

        cout<<"Enter Author:";
        getline(cin,author);

        items.push_back(new Book(id,title,author));
        save();

        cout<<"Book Added\n";
    }

    void addReference()
    {
        int id;
        string title;

        cout<<"Enter ID:";
        cin>>id;
        cin.ignore(100,'\n');

        cout<<"Enter Title:";
        getline(cin,title);

        items.push_back(new ReferenceBook(id,title));
        save();

        cout<<"Reference Book Added\n";
    }

    void view()
    {
        if(items.empty())
        {
            cout<<"No items\n";
            return;
        }

        for(auto item:items)
        {
            item->display();
        }
    }

    void searchItem()
    {
        int id;
        cout<<"Enter ID:";
        cin>>id;

        for(auto item:items)
        {
            if(item->getId()==id)
            {
                item->display();
                return;
            }
        }

        cout<<"Item not found\n";
    }

    void issueItem()
    {
        int id;
        cout<<"Enter ID:";
        cin>>id;

        for(auto item:items)
        {
            if(item->getId()==id)
            {
                item->issue();
                save();
                return;
            }
        }

        cout<<"Not found\n";
    }

    void returnItem()
    {
        int id;
        cout<<"Enter ID:";
        cin>>id;

        for(auto item:items)
        {
            if(item->getId()==id)
            {
                item->returnItem();
                save();
                return;
            }
        }

        cout<<"Not found\n";
    }

    ~Library()
    {
        for(auto item:items)
        {
            delete item;
        }
    }
};

int main()
{
    Library lib;
    lib.load();

    int choice;

    while(true)
    {
        cout<<"\n---Library---\n";
        cout<<"1.Add Book\n";
        cout<<"2.Add Reference\n";
        cout<<"3.View\n";
        cout<<"4.Issue\n";
        cout<<"5.Return\n"; 
        cout<<"6.Search\n";
        cout<<"7.Exit\n";
        cout<<"Choice:";
        cin>>choice;

        switch(choice)
        {
            case 1:lib.addBook();break;
            case 2:lib.addReference();break;
            case 3:lib.view();break;
            case 4:lib.issueItem();break;
            case 5:lib.returnItem();break;
            case 6:lib.searchItem();break;
            case 7:return 0;
            default:cout<<"Invalid\n";
        }
    }
}