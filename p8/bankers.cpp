#include <iostream>

using namespace std;

int main() {
	int p, r, i, j,process,count=0;
	int max[10][5], need[10][5], alloc[10][5];
	int total[5], finish[10], available[5], sum[5] = {}, safeseq[10];

	cout << "Implementation of bankers algorithm\n";
	cout << "enter the number of processes\n";
	cin >> p;
	cout << "enter the number of resources\n";
	cin >> r;
	for (i = 0; i < p; i++) {
		finish[i] = 0;
	}

	for (i = 0; i < r; i++) {
		cout << "enter the total instances of resources" << i << "\t";
		cin >> total[i];
	}

	cout << "enter the allocation matrix of all process for each resource\n";
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			cin >> alloc[i][j];
		}
	}
	cout << "enter the maximum allocation matrix of all process for each resource\n";
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			cin >> max[i][j];
		}
	}
	for (j = 0; j < r; j++) {
		for (i = 0; i < p; i++) {
			if (max[i][j] > total[j]) {
				cout << "maximum allocation of process" << i+1 << " is more than avialable instances of the resource\n";
				return 1;
			}
			if (alloc[i][j] > max[i][j]) {
				cout << "allocation of prcoess" << i + 1 << " is more than maximum needed\n";
				return 1;
			}
		}
	}
	for (j = 0; j < r; j++) {
		for (i = 0; i < p; i++) {
			sum[j] = sum[j] + alloc[i][j];
		}
	}
	for (i = 0; i < r; i++) {
		available[i] = total[i] - sum[i];
	}

	cout << "need matrix for the given allocation and max instance matrix\n";
	for (i = 0; i < p; i++) {
		for (j = 0; j < r; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
			cout << need[i][j] << "\t";
		}
		cout << endl;
	}

	do {
		cout << "available instance of each resources\n";
		for (i = 0; i < r; i++) {
			cout << available[i] <<"\t";
		}
		cout << endl;

		cout << "ALLOC\t\tNEED" << endl;
		for (i = 0; i < p; i++) {
			for (j = 0; j < r; j++) {
				cout << alloc[i][j];
			}
			cout << "\t\t";
			for (j = 0; j < r; j++) {
				cout << need[i][j];
			}
			cout << endl;
		}
		process = -1;
		for (i = 0; i < p; i++) {
			if (finish[i] == 0) {
				process = i;
				for (j = 0; j < r; j++) {
					if (available[j] < need[i][j]) {
						process = -1;
						break;
					}
				}
			}
			if (process != -1) break;
		}

		if (process != -1) {
			cout << "process" << process + 1 << " runs to completion\n";
			safeseq[count] = process + 1;
			count++;
			for (j = 0; j < r; j++) {
				available[j] += alloc[process][j];
				alloc[process][j] = 0;
				need[process][j] = 0;
				finish[process] = 1;
			}
		}
	} while (count != p && process != -1);

	if (count == p) {
		cout << "\n system is in safe state :)\n";
		cout << "safe sequence : <";
		for (i = 0; i < p; i++)
			cout << safeseq[i] << ",";
		cout << ">\n";
	}
	else
		cout << "system is not in safe state :(\n";
}