#include <iostream>
using namespace std;

int n,findex=0,nf,hit=0,i,j,k,pagefaultcnt=0;
int pseq[20],p[10];

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
            break;
        }
    }
    return hit;
}

int main(){
    cout<<"\nenter the length of page reference sequence\n";
    cin>>n;
    cout<<"enter the page reference sequence\n";
    for(i=0;i<n;i++)
        cin>>pseq[i];
    cout<<"enter the maximum number of frames\n";
    cin>>nf;   
    for(i=0;i<nf;i++)
        p[i]=9999;
    
    for(i=0;i<n;i++){
        cout<<"for "<<pseq[i]<<"---";
        if(isHit(pseq[i])==0){
            p[findex]=pseq[i];
            findex=(findex+1)%nf;
            pagefaultcnt++;
            displaypages();
        }
        else{
            cout<<"No Page fault";
        }
        cout << endl;
    }
    cout << "\n\ntotal number of page faults is "<<pagefaultcnt<<endl;
}