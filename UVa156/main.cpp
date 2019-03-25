#include <iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
set<string> s;
set<string> ::iterator sit;
struct node{
    string real;
    bool ifok=true;
};
map<string,node> m;
map<string,node> ::iterator mit;
pair<string,node> p;
int main()
{
    string str,tempstr;
    node n;
    while(cin>>str){
        if(str=="#")break;
        tempstr=str;
        transform(tempstr.begin(),tempstr.end(),tempstr.begin(),::tolower);
        sort(tempstr.begin(),tempstr.begin()+tempstr.size());
        mit=m.find(tempstr);
        if(mit==m.end()){
            n.real=str;
            n.ifok=true;
            m[tempstr]=n;
        }else{
            m[tempstr].ifok=false;
        }

    }
    for(mit=m.begin();mit!=m.end();mit++){
        p=*mit;
        n=p.second;
        if(n.ifok){
            s.insert(n.real);
        }
    }
    for(sit=s.begin();sit!=s.end();sit++){
        cout<<*sit<<endl;
    }
    return 0;
}
