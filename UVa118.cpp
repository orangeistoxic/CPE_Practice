#include<bits/stdc++.h>

using namespace std;
int turnR(char ori){
    if(ori=='N'){
        ori='E';
    }
    else if(ori=='E'){
        ori='S';
    }
    else if (ori=='S'){
        ori='W';
    }
    else if(ori=='W'){
        ori='N';
    }
    return(ori);

}
int turnL(char ori){
    if(ori=='N'){
        ori='W';
    }
    else if(ori=='E'){
        ori='N';
    }
    else if (ori=='S'){
        ori='E';
    }
    else if(ori=='W'){
        ori='S';
    }
    return(ori);

}
int JudgeLost(int x,int y,char ori,int Xaxis,int Yaxis){
                bool lost=false;
                if(x<0){
                    x+=1;
                    
                    lost=true;
                }
                else if(x>Xaxis){
                    x-=1;
                    
                    lost=true;
                }
                else if(y<0){
                    y+=1;
                    
                    lost=true;
                }
                else if(y>Yaxis){
                    y-=1;
                    
                    lost=true;
                }
                return(x,y,lost);
}
int main(){
    set<int,int> Scent;
    int Xaxis,Yaxis;
    cin>>Xaxis>>Yaxis;
    int x,y;
    char ori;
    while(cin>>x>>y>>ori){
        bool lost=false;
        string Commend;
        cin>>Commend;
        for(int i=0;i<Commend.length();i++){
            if(Commend[i]=='R'){
                ori=turnR(ori);
            }
            else if(Commend[i]=='L'){
                ori=turnL(ori);
            }
            else if(Commend[i]=='F'){
                if(ori=='N'){
                    y+=1;
                }
                else if(ori=='E'){
                    x+=1;
                }
                else if(ori=='S'){
                    y-=1;
                }
                else if(ori=='W'){
                    x-=1;
                }

            }
            (x,y,lost)=JudgeLost(x,y,ori,Xaxis,Yaxis);
            if(lost){
                if(Scent.count((x,y))==1){

                }
                else if(Scent.count((x,y))==0){
                    Scent.insert(x,y);
                    cout<<x<<" "<<y<<" "<<ori<<" "<<"LOST"<<endl;
                    break;
                }
            }

        }
        if(lost==false){
            cout<<x<<" "<<y<<" "<<ori<<endl;
        }

    }
}