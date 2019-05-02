#include <iostream>
#include<fstream>
#include<string>
using namespace std;
class student
{
    int id;
    string name,div,addr;
public:
    void set_info()
    {
        cout<<"Enter roll no.: ";
        cin>>id;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter division: ";
        cin>>div;
        cout<<"Enter address: ";
        cin>>addr;
    }
    void show_info()
    {
        cout<<"The name is "<<name<<" and the roll no is "<<id<<endl;
    }
    void write_record(student obj)
    {
        ofstream fout;
        fout.open("sample.txt",ios::binary|ios::app);
        fout.write((char*)&obj,sizeof(obj));
        fout.close();
        cout<<"Data written\n";
    }
    void read_record(int id)
    {
        ifstream fin;
        student obj;
        int loc,i=0;
        fin.open("sample.txt",ios::binary);
        fin.seekg(0, ios::beg);
        while(fin.read((char*)&obj,sizeof(obj)))
        {
            loc=sizeof(obj)*i;
            fin.seekg(loc, ios::beg);
            fin.read((char*)&obj,sizeof(obj));
            obj.show_info();
            if(obj.id==id)
            {
                obj.show_info();
                cout<<"This\n";
                break;
            }
            i++;
        }
        if(obj.id!=id)
        {
                cout<<"Error 404! Record not found\n";
        }
    }
};
int main()
{
    char op;
    do
    {
        int c;
        cout<<"======================Menu=====================\n";
        cout<<"1] Add record\n2] Search record\n3] Delete record\n";
        cout<<"_______________________________________________\n";
        cout<<"Enter your choice: ";
        cin>>c;
        switch(c)
        {
            case 1: {
                        student s;
                        s.set_info();
                        s.write_record(s);
                    }
                    break;
            case 2: {
                        int id;
                        student s;
                        cout<<"Enter roll no. of record you wish to search\n";
                        cin>>id;
                        s.read_record(id);
                    }
                    break;
            default:cout<<"Invalid\n";
        }
        cout<<"Do you wish to go again?(y/n): ";
        cin>>op;
    }while(op=='y' || op=='Y');
    return 0;
}




