#include<bits/stdc++.h>

using namespace std;

int CycleLength(int k){
    int Count=1;
    while(k!=1){
        if(k%2==1){
            k=k*3+1;
        }
        else{
            k=k/2;
        }
        Count++;
        
    }
    return(Count);
}

int main(){
    
    long int j,i;
    while(cin>>i>>j){
        int MaxCycleLength=0;
        cout<<i<<" "<<j<<" ";
        if(i>j){
            swap(i,j);
        }
        for(long int o=i;o<=j;o++){
            if(CycleLength(o)>MaxCycleLength){
                MaxCycleLength=CycleLength(o);
            }
        }
        cout<<MaxCycleLength<<endl;
    }

}