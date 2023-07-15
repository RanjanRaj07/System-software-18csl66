#include <iostream>

using namespace std;

int limit,i,j;

class Process {
public:
    int arriveT, burstT, remT;
    int endT, waitT, turnarroundT;
};

int main() {
    int smallest, count=0, time,ith=0,kth,proc[30];
    int wt = 0, tt = 0;
    float awt, att;

    cout << "enter the total number of processes" << endl;
    cin >> limit;

    Process* p = new Process[limit];

    cout << "enter the details of each processes" << endl;

    for (i = 0; i < limit; i++) {
        cout << "enter the Arrival time of process " << i << "\t";
        cin >> p[i].arriveT;
        cout << "enter the Burst time of process " << i << "\t";
        cin >> p[i].burstT;
        p[i].remT = p[i].burstT;
    }

    for (time = 0; count != limit; time++) {
        for (i = 0; i < limit; i++) {
            smallest = 999;
            for (j = 0; j < limit; j++) {
                if (p[j].arriveT <= time && p[j].remT > 0 && p[j].remT <= smallest) {
                    smallest = p[j].remT;
                }
            }
            if (p[i].arriveT <= time && p[i].remT <= smallest && p[i].remT>0) {
                p[i].remT -= 1;
                kth = i;
                if (p[i].remT == 0) {
                    ith = i;
                    break;
                }
            }
        }
        if (p[ith].remT == 0) {
            count++;
            p[ith].endT = time + 1;
            p[ith].waitT = p[ith].endT - p[ith].arriveT - p[ith].burstT;
            p[ith].turnarroundT = p[ith].endT - p[ith].arriveT;
            p[ith].remT = -1;
        }
        proc[time] = kth;
    }
    cout << "\nprocess | wait |turnaround| end | arrive|burst" << endl;

    for (i = 0; i < limit; i++) {
        cout <<"p" << i << "\t|" << p[i].waitT << "\t|" << p[i].turnarroundT << "\t|" << p[i].endT<<"\t|"<<p[i].arriveT<<"\t|"<<p[i].burstT << endl;
    }

    cout << "\n";

    for (i = 0; i <time; i++) {
        cout << i << "\t|\t";
        cout << proc[i] << "\n";
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