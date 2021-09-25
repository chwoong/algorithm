/*
 *  author: chw0501
 *  reference: 	https://speakerdeck.com/wookayin/fast-fourier-transform-algorithm
 				https://github.com/kks227/BOJ/blob/master/1000/1067.cpp
 *  created: 27.12.2020 10:59:28(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w){
	int n = f.size();
	if(n == 1) return;
	vector<cpx> even(n/2), odd(n/2);
	for(int i = 0; i < n; i++)
		(i % 2 ? odd : even)[i / 2] = f[i];
	FFT(even, w*w);
	FFT(odd, w*w);
	
	cpx wp(1,0);
	for(int i = 0; i < n / 2; i++){
		f[i] = even[i] + wp*odd[i];
		f[i + n / 2] = even[i] - wp* odd[i];
		wp *= w;
	}
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b){
	int n = 1;
	while(n < a.size() + 1 || n < b.size() + 1) n *= 2;
	n *= 2;
	a.resize(n);
	b.resize(n);
	vector<cpx> c(n);
	
	cpx w(cos(2*PI/n), sin(2*PI/n));
	FFT(a,w);
	FFT(b,w);
	for(int i = 0; i < n; i++)
		c[i] = a[i]*b[i];
	FFT(c, cpx(1,0)/w);
	for(int i = 0; i < n; i++){
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag()));
	}
	return c;
}


int main(){
	int t;
	int num;
	scanf("%d", &t);
	vector<cpx> x(t*2), y(t), z;
	for(int i = 0; i < t; i++){
		scanf("%d", &num);
		x[i] = x[i + t] = cpx(num, 0);
	}
	for(int i = 0; i < t; i++){
		scanf("%d", &num);
		y[t - i - 1] = cpx(num, 0);
	}
	int ans = 0;
	z = multiply(x, y);
	for(int i = t - 1; i < 2 * t - 1; i++){
		ans = max(ans, (int)round(z[i].real()));
	}
	printf("%d", ans);
	return 0;
}