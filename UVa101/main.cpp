#include <iostream>
#include<vector>
#include<algorithm>
#define maxN 30
using namespace std;
vector<int> v[maxN];
int where[maxN];
void m2(int a,int b){
    if(a==b||where[a]==where[b])return;
    int i,j;
    int temp1=where[a];
    int temp2=where[b];
    int temp3;
    for(i=0;i<v[temp1].size()&&v[temp1][i]!=a;i++);
    for(int cnt1=i+1;cnt1<v[temp1].size();cnt1++){
          temp3=v[temp1][cnt1];
          reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          v[temp3].push_back(temp3);
          reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          where[temp3]=temp3;
    }
    v[temp1].erase(v[temp1].begin()+i,v[temp1].begin()+v[temp1].size());
    v[temp2].push_back(a);
    where[a]=where[b];
}
void m1(int a,int b){
    if(a==b||where[a]==where[b])return;
    int i,j;
    int temp1=where[a];
    int temp2=where[b];
    int temp3;
    for(i=0;i<v[temp1].size()&&v[temp1][i]!=a;i++);
    for(j=0;j<v[temp2].size()&&v[temp2][j]!=b;j++);
    for(int cnt1=i+1;cnt1<v[temp1].size();cnt1++){
          temp3=v[temp1][cnt1];
          reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          v[temp3].push_back(temp3);
          reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          where[temp3]=temp3;
    }
    v[temp1].erase(v[temp1].begin()+i,v[temp1].begin()+v[temp1].size());
    for(int cnt2=j+1;cnt2<v[temp2].size();cnt2++){
          temp3=v[temp2][cnt2];
         reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          v[temp3].push_back(temp3);
          reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          where[temp3]=temp3;
    }
    v[temp2].erase(v[temp2].begin()+j+1,v[temp2].begin()+v[temp2].size());
    v[temp2].push_back(a);
    where[a]=where[b];
}
void m3(int a,int b){
    if(a==b||where[a]==where[b])return;
    int i,j;
    int temp1=where[a];
    int temp2=where[b];
    int temp3;
    for(i=0;i<v[temp1].size()&&v[temp1][i]!=a;i++);
    for(j=0;j<v[temp2].size()&&v[temp2][j]!=b;j++);
    for(int cnt2=j+1;cnt2<v[temp2].size();cnt2++){
          temp3=v[temp2][cnt2];
          reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          v[temp3].push_back(temp3);
          reverse(v[temp3].begin(),v[temp3].begin()+v[temp3].size());
          where[temp3]=temp3;
    }
    v[temp2].erase(v[temp2].begin()+j+1,v[temp2].begin()+v[temp2].size());
    for(int cnt1=i;cnt1<v[temp1].size();cnt1++){
        temp3=v[temp1][cnt1];
        v[temp2].push_back(temp3);
        where[temp3]=temp2;
    }
    v[temp1].erase(v[temp1].begin()+i,v[temp1].begin()+v[temp1].size());
}
void m4(int a,int b){
    if(a==b||where[a]==where[b])return;
    int i,j;
    int temp1=where[a];
    int temp2=where[b];
    int temp3;
    for(i=0;i<v[temp1].size()&&v[temp1][i]!=a;i++);
    for(int cnt1=i;cnt1<v[temp1].size();cnt1++){
          temp3=v[temp1][cnt1];
          v[temp2].push_back(temp3);
          where[temp3]=temp2;
    }
    v[temp1].erase(v[temp1].begin()+i,v[temp1].begin()+v[temp1].size());

}
int main()
{
    int n,a,b;
    string s1,s2;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        v[i].push_back(i);
        where[i]=i;
    }
    cin>>s1;
    while(s1!="quit"){
        cin>>a>>s2>>b;
        if(s1=="move"&&s2=="onto"){
            m1(a,b);
        }else if(s1=="move"&&s2=="over"){
            m2(a,b);
        }
        else if(s1=="pile"&&s2=="onto"){
            m3(a,b);
        }else {
            m4(a,b);
        }
        cin>>s1;

    }
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<v[i].size();j++){
            printf(" %d",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
