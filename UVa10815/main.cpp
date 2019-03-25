#include <iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
set<string> s;
string line;
int main()
{
    while(cin>>line){
        string str="";
        int first=0;
        for(int i=0;i<line.size();i++){
           if(!((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z'))){
               str=line.substr(first,i-first);
               if(str.size()>0){
                 transform(str.begin(),str.end(),str.begin(),::tolower);
                 s.insert(str);
                 str.erase();
               }
               first=i+1;
           }
        }
        str=line.substr(first,line.size()-first);
        if(str.size()>0){
            transform(str.begin(),str.end(),str.begin(),::tolower);
            s.insert(str);
            str.erase();
        }
    }
    set<string>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}
