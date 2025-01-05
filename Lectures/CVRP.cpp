#include <bits/stdc++.h>
using namespace std;

const int maxN = 20;
const int maxXe = 6;
const int inf = 1e9;

int n, K, Q;
long long f, fopt;
int x[maxN], y[maxXe], d[maxN];
bool visited[maxN];
int c[maxN][maxN];
int c_min = inf;
int load[maxXe] = {0};
int segments = 0;
int nbR;

void input() {
	cin >> n >> K >> Q;
	for(int i = 1; i <=n; i++) {
		cin >> d[i];
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			cin >> c[i][j];
			if(i != j && c[i][j] < c_min) c_min = c[i][j];
		}
		visited[i] = false;
	}
	y[0] = 0;
	fopt = inf;
	f = 0;
}

bool check_X(int v, int k) {
	if(v > 0 && visited[v]) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void Try_X(int start, int k) {
	if(start == 0) {
		if(k < K) {
			Try_X(y[k+1], k+1);
			return;
		}		
	}
	else {
		for(int v = 0; v <= n; v++) {
			if(check_X(v, k)) {
				x[start] = v;
				visited[v] = true;
				load[k] = load[k] + d[v];
				f = f + c[start][v];
				segments = segments + 1;
				if(v > 0) {
					if(f + c_min * (n + nbR - segments) < fopt) 
					Try_X(v, k);
				}
				else {
					if(k == K) {
						if(segments == n + nbR) {
							if(f + c[v][0] < fopt) fopt = f + c[v][0];
						}
					}
					else if(f + c_min * (n + nbR - segments) < fopt) Try_X(y[k+1], k+1);
				}
				visited[v] = false;
				f = f - c[start][v];
				load[k] = load[k] - d[v];
				segments = segments - 1;
			}
		}
	}
}

bool check_Y(int k, int v) {
	if(v == 0) return true; 
	if(visited[v] == true) return false;
	if(load[k] + d[v] > Q) return false;
	return true;
}

void Try_Y(int k) {
	int start = 0;
	if(y[k-1] > 0) start = y[k - 1] + 1;
	for(int v = start; v <= n; v++){
		if(check_Y(k, v)) {
			y[k] = v;
			load[k] = load[k] + d[v];
			visited[v] = true;
			f = f + c[0][v];
			if(v > 0) segments = segments + 1;
			if(k == K) {
				nbR = segments;
				Try_X(y[1], 1);
			}
			else {
				Try_Y(k + 1);
			}
			visited[v] = false;
			f = f - c[0][v];
			load[k] = load[k] - d[v];
			if(v > 0) segments = segments - 1;
		}
	}
}

int main() {
	input();
	Try_Y(1);
	cout<<fopt<<"\n";
	return 0;
}