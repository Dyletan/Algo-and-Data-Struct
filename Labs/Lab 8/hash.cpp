#include <iostream>
using namespace std;

const int p = 31;

int my_hash(string s) {
	int h = 0;
	for (int i = 0; i < s.length(); i++) {
		h = h * p + s[i]; // mod 2^32
	}
	return h;
}


int main() {
	int n, m;
	string s, w;
	cin >> s >> w;

	n = s.length();
	m = w.length();

	int hw = my_hash(w); // create a hash of string to find
	int hs = my_hash(s.substr(0, m)); // create a hash of first m charachters of original string 

	int pm = 1; // p^{m-1}
	for (int i = 0; i < m-1; i++)
		pm = pm * p;

	for (int i = 0; i + m <= n; i++) {
		if (hs == hw) // the hashes match -> strings match
        {
			cout << i << ' '; // the position of current match
		}
		// [i, i + m - 1] --> [i + 1, i + m]
		if (i + m < n) // to prevent out of bounds exception when i + m = n
			hs = (hs - pm * s[i]) * p + s[i + m];
        //move your window one character to the right, you need to update the hash value hs for the new window. You do this by subtracting the contribution of the character at the left edge of the window (i.e., s[i]) and adding the contribution of the new character at the right edge of the window (i.e., s[i + m]).
	}
	cout << "\n";

	return 0;
}



