#include<iostream>
#include<set>
#include<sstream>
#include<string>
#include<fstream>
#include<iterator>

using std::string;
using std::getline;
using std::multiset;
using std::ifstream;
using std::cout;
using std::endl;


int main()
{
    multiset<string> s;
    typedef multiset<string>::iterator it;
    ifstream infile("wordcount_test.txt");
    string a;
    while(!infile.eof())
    {
        std::istringstream iss(a);
        if (!(getline(infile,a)))
        {
            cout<<"Error"<<endl;
            break;
        } // error
        s.insert(a);
        //cout<<a<<endl;
    }
    it iterator;
    for(iterator = s.begin(); iterator != s.end(); iterator++)
        cout<<*iterator<<endl;
}
