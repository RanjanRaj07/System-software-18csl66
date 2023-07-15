#include <iostream>
using namespace std;

int n,findex=0,nf,hit=0,i,j,k,pagefaultcnt=0;
int pseq[30],p[10],least[10];
int flag=0;

void displaypages(){
    for(k=0;k<nf;k++){
        if(p[k]!= 9999)
        cout <<p[k]<<" ";
    }
}


int isHit(int data){
    hit = 0;
    for(j=0;j<nf;j++){
        if(p[j]==data){
            hit=1;
            least[j]=0;
            j++;
            break;
        }
        else{
            least[j]++;
        }
    }
    while(j<nf){
        least[j]++;
        j++;
    }
    return hit;
}

int findindex(int findex1){
    int max1=0;
    if(findex1>=nf || flag==1){
        for(k=0;k<nf;k++){
            if(least[k]>max1){
                max1=least[k];
                findex1=k;
                flag = 1;
            }
        }
    }else{
        findex1++;
    }
    return findex1;
}

int main(){
    cout<<"\nenter the length of page reference sequence\n";
    cin>>n;
    cout<<"enter the page reference sequence\n";
    for(i=0;i<n;i++)
        cin>>pseq[i];
    cout<<"enter the maximum number of frames\n";
    cin>>nf;   
    for(i=0;i<nf;i++){
        p[i]=9999;
        least[i]=0;
    }


    for(i=0;i<n;i++){
        cout << "\nfor "<<pseq[i]<<"---";
        if(isHit(pseq[i])==0){
            least[findex]=0;
            p[findex]=pseq[i];
                        // for(j=0;j<nf;j++){
                        //     cout<<least[j]<<" ";
                        // }
                        // cout<<"\t";
            findex=findindex(findex);
            pagefaultcnt++;
            displaypages();
        }
        else{
                        // for(j=0;j<nf;j++){
                        //     cout<<least[j]<<" ";
                        // }
                        // cout<<"\t";
            findex=findindex(findex);
            cout<<"No page fault";
        }
        cout << endl;
    }
    cout << "\n\ntotal number of page faults is "<<pagefaultcnt<<endl;
}