#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//бесконечная константа
const long long INF = 100000000;
//Matrix
vector<vector <long long>>d(16,vector<long long>(16,0));
//dp Matrix
vector<vector <long long>>dp(((1<<16)-1),vector<long long>(64,INF));
int main() {
	//count 
	long long n;
	cin >> n;
	//cin 
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	//(mask==1) = 0
	dp[1][0] = 0;
	//перебор масок от 10 до (1<<n)-1
	for (long long mask = 2; mask < (1 << n); mask++) {
		//перебор чисел от 0 до n-1
		for (long long i = 0; i < n; i++) {
			//если в маске находится наш i-ый то
			if (((mask >> i) & 1) == 1) {
				//mi-маска без i
				long long mi = mask - (1 << i);
				//перебираем все элементы до n
				for (long long j = 0; j < n; j++) {
					//выбираем минимальное из обхода через другую вершину или через то, что было
					dp[mask][i] = min(abs((dp[mi][j] + d[j][i])), (dp[mask][i]));
				}
			}
		}
	}
	//begin of questions
	long long q;
	//количество запросов
	cin >> q;

	for (long long i = 0; i < q; i++) {
		long long n_2;
		//кол-во чисел
		cin >> n_2;
		//массив исключений 
		
		//маск без этих элементов
		long long mask = ( 1 << n)-1,f;
		for (long long j = 0; j < n_2; j++) {
			cin >> f; mask = mask ^ ( 1 << (f-1));
		}
		//вывод по маске
		long long mini = INF;
		for (long long i2 = 0; i2 < n; i2++) {
			mini = min(mini, dp[mask][i2]);
		}
		cout << mini << endl;
	}
}