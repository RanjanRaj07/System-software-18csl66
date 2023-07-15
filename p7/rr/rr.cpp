#include <iostream>

using namespace std;

int limit,i;

class Process {
public:
    int arriveT, burstT, remT;
    int endT, waitT, turnarroundT;
};

int main() {
    int  quant,y,count,time;
    int wt = 0, tt = 0;
    float awt, att;

    cout << "enter the total number of processes" << endl;
    cin >> limit;
    y=limit;
    Process* p = new Process[limit];

    cout << "enter the details of each processes" << endl;

    for (i = 0; i < limit; i++) {
        cout << "enter the Arrival time of process " << i << "\t";
        cin >> p[i].arriveT;
        cout << "enter the Burst time of process " << i << "\t";
        cin >> p[i].burstT;
        p[i].remT = p[i].burstT;
    }
    cout<<"enter the quantum time for RR scheduling" << endl;
    cin >> quant;

    for (time=0,i=0;y!=0;){
        if(p[i].remT<=quant && p[i].remT>0){
            time += p[i].remT;
            p[i].remT = 0;
            count = 1;
        }
        else if(p[i].remT>0){
            p[i].remT -= quant;
            time += quant;
        }
        if(p[i].remT==0 && count==1){
            y--;
            p[i].endT=time;
            p[i].waitT = time - p[i].arriveT - p[i].burstT;
            p[i].turnarroundT = time - p[i].arriveT;
            count = 0;
        }
        i++;
        i = i%limit;
    }
    cout <<"process |waitT\t|turnroundT\t|endT\t|arraive|burstT"<<endl;
    for (i=0;i<limit;i++){
        cout << "p" << i << "\t|" << p[i].waitT <<"\t|"<<p[i].turnarroundT<<"\t\t|"<<p[i].endT<<"\t|"<<p[i].arriveT<<"\t|"<<p[i].burstT<<endl;
    }

    for (i = 0; i < limit; i++) {
        wt += p[i].waitT;
        tt += p[i].turnarroundT;
    }

    awt = float(wt) / limit;
    att = float(tt) / limit;

    cout << "\n\n Average waiting time is\t" << awt << endl;
    cout << "\n\n Average Turnaroud time is\t" << att << endl;

    return 0;
}