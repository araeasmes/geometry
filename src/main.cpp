#include <iostream>
#include "geometry2d.h"

using namespace std;

typedef vector<int> vi;
typedef long long int lli;

int main(){
	
	Polygon a, b;
	int n, tmpx, tmpy;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmpx >> tmpy;
		a.add_coord(tmpx, tmpy);
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> tmpx >> tmpy;
		b.add_coord(tmpx, tmpy);
	}
	cout << a.intersect(b) << endl;

	return 0;
}