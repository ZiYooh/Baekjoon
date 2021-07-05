#include <fstream>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class Olympiad{
public:
    int start, finish, money;

    bool operator < (const Olympiad& x) const{
        if (finish != x.finish)
            return finish < x.finish;
        return start < x.start;
    }
} *plans;

int binary_search(int low, int high, int val){
    int middle;
    while (low < high){
        middle = low + (high - low + 1) / 2;
        if (plans[middle].finish < val)
            low = middle;
        else
            high = middle - 1;
    }
    if (plans[low].finish > val)
        return 0;
    return low;
}

int main(){
    int row, i;
	long long *dp, *p;

	cin >> row;
	
	dp = new long long[row+1];
    p = new long long[row+1];
	
    plans = new Olympiad[row+1];

    plans[0].start = 0;
	plans[0].finish = 0;
	plans[0].money = 0;

	dp[0] = 0;
	p[0] = 0;
	for(i = 1; i <= row; i++){
		cin >> plans[i].start >> plans[i].finish >> plans[i].money;
	}

    sort(plans+1, plans+row+1);

    for (i = 1; i <= row; i++){
        p[i] = binary_search(0, i-1, plans[i].start);
        dp[i] = max(plans[i].money + dp[p[i]], dp[i-1]);
    }
    cout << dp[row];
	delete[] p;
	delete[] plans;
	delete[] dp;

    return 0;
}
