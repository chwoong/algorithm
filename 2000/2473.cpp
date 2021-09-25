#include<stdio.h>
#include <iostream>
#define Swap(aa,bb) {cc=aa;aa=bb;bb=cc;}
using namespace std;
const int MAXN = 5000;
int a[MAXN], n, cc;
long long Opt, Sol;
int Opt_x, Opt_y, Opt_z;
int Sol_x, Sol_y, Sol_z;
void Sort(int l, int r)
{
	if (l < r)
	{
		int i = l - 1, j = r + 1, mid = a[(l + r) >> 1];
		while (1)
		{
			while (a[++i] < mid);
			while (a[--j] > mid);
			if (i >= j) break;
			Swap(a[i], a[j]);
		}
		Sort(l, i - 1);
		Sort(j + 1, r);
	}
}
int main(void)
{
	int l1, l2, l3, l4;
	cin >> n;
	for (l1 = 0; l1<n; l1++)
	{
		cin >> a[l1];
	}
	Sort(0, n - 1);
	Opt = (long long)a[0] + (long long)a[1] + (long long)a[2];
	if (Opt < 0) Opt = -Opt;
	Opt_x = a[0];
	Opt_y = a[1];
	Opt_z = a[2];
	if (Opt_x > Opt_y) Swap(Opt_x, Opt_y);
	if (Opt_x > Opt_z) Swap(Opt_x, Opt_z);
	if (Opt_y > Opt_z) Swap(Opt_y, Opt_z);
	for (l1 = 0; l1<n; l1++)
	{
		l3 = n - 1;
		for (l2 = l1 + 1; l2<n; l2++)
		{
			while (1)
			{
				if (l3 <= l2) break;
				if ((long long)a[l1] + (long long)a[l2] + (long long)a[l3] <= 0) break;
				l3--;
			}
			if (l3 < l2) break;
			for (l4 = l3 - 1; l4 <= l3 + 1; l4++)
			{
				if (l4 <= l2 || l4 >= n) continue;
				Sol = (long long)a[l1] + (long long)a[l2] + (long long)a[l4];
				if (Sol < 0) Sol = -Sol;
				if (Sol < Opt)
				{
					Opt = Sol;
					Opt_x = a[l1];
					Opt_y = a[l2];
					Opt_z = a[l4];
					if (Opt_x > Opt_y) Swap(Opt_x, Opt_y);
					if (Opt_x > Opt_z) Swap(Opt_x, Opt_z);
					if (Opt_y > Opt_z) Swap(Opt_y, Opt_z);
				}
			}
		}
	}
	printf("%d %d %d\n", Opt_x, Opt_y, Opt_z);
	return 0;
}