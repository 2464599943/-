#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N,Q,num,cnt=0;
    scanf("%d %d",&N,&Q);
    while(!(N==0&&Q==0)){
        cnt++;
        vector<int> v;
        for(int i=0;i<N;i++){
            scanf("%d",&num);
            v.push_back(num);
        }
        sort(v.begin(),v.begin()+v.size());
        printf("CASE# %d:\n",cnt);
        for(int i=0;i<Q;i++){
            scanf("%d",&num);
            bool ifok=false;
            for(int j=0;v[j]<=num&&j<v.size();j++){
                if(v[j]==num){
                    printf("%d found at %d\n",num,j+1);
                    ifok=true;
                    break;
                }
            }
            if(!ifok){
                printf("%d not found\n",num);
            }
        }
        scanf("%d %d",&N,&Q);
    }
    return 0;
}
