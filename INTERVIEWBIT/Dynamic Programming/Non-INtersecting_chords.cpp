// cpp code to count ways
// to divide circle using
// N non-intersecting chords.
#include <bits/stdc++.h>
using namespace std;

int chordCnt( int A){

	// n = no of points required
	int n = 2 * A;

	// dp array containing the sum
	int dpArray[n + 1]={ 0 };
	dpArray[0] = 1;
	dpArray[2] = 1;
	for (int i=4;i<=n;i+=2){
		for (int j=0;j<i-1;j+=2){

		dpArray[i] +=
			(dpArray[j]*dpArray[i-2-j]);
		}
	}

	// returning the required number
	return dpArray[n];
}
// Driver function
int main()
{

	int N;
	N = 2;
cout<<chordCnt( N)<<'\n';
	N = 1;
cout<<chordCnt( N)<<'\n';
	N = 4;
cout<<chordCnt( N)<<'\n';
for(int i=1;i<=10;i++){
    cout<<chordCnt(i)<<endl;
}

	return 0;
}


/*

Think in terms of DP.
Can we relate answer for N with smaller answers.

If we draw a chord between any two points, can you observe current set of points getting broken into two smaller sets S_1 and S_2? Can a chord be drawn between two points where each point belong to different set?

If we draw a chord from a point in S_1 to a point in S_2, it will surely intersect the chord we’ve just drawn.

So, we can arrive at a recurrence that Ways(n) = sum[i = 0 to n-1] { Ways(i)*Ways(n-i-1) }.
Here we iterate over i, assuming that size of one of the sets is i and size of other set automatically is (n-i-1) since we’ve already used a pair of points and i pair of points in one set.

*/



