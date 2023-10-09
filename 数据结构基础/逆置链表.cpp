#include<iostream>
#define MAXSIZE 100005
using namespace std;



int main() {
	
	int data[100005];
	int next[100005];
	int list[100005];

	int firstAdd, N, K;
	cin >> firstAdd >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmpData, tmpAdd, tmpNext;
		cin >> tmpAdd >> tmpData >> tmpNext;
		data[tmpAdd] = tmpData;
		next[tmpAdd] = tmpNext;
	}
	int sum = 0;
	while (firstAdd != -1) {//按照地址前后顺序在list数组中存放地址
		list[sum++] = firstAdd;
		firstAdd = next[firstAdd];
	}
	for (int i = 0; i < sum - sum % K; i += K) {//从第零个开始每k个逆置，最后不够k个忽略
		for (int j = 0; j < K / 2; j++) {
			int t = list[i + j];
			list[i + j] = list[i + K - j - 1];
			list[i + K - j - 1] = t;
		}
	}
	for (int i = 0; i < sum - 1; i++) {
		cout << list[i] << " " << data[list[i]] << " " << list[i + 1] << endl;
	}
	cout << list[sum - 1] << " " << data[list[sum - 1]] << " " << "-1" << endl;

	return 0;
}
