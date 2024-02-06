#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = (int)1e5 + 5;

int a[N], n, m;

bool lin_search(int x) {
	/*  
		in case there are several x's in array,
		output position of lefmost occurence 
	*/
	for (int i = 1; i <= n; i++)
		if (a[i] == x)
			return true;
	return false;
}

bool bin_search(int x) {
	if (x < a[1] || a[n] < x)
		return false;
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == x)
			return true;
		if (a[mid] < x)
			l = mid + 1;
		else // x < a[mid]
			r = mid - 1;
	}
	return false;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	// if bin_search
	sort(a + 1, a + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		// int pos = lin_search(x);
		bool yes = bin_search(x);
		puts(yes ? "yes" : "no");
	}

	return 0;
}



