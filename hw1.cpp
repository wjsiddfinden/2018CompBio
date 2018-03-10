#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

class MAX{
	public:
		vector<int> value;
		int max;
		vector<int> imax;
		
		void of(vector<int> v){
			value=v;
			max=
		}
		int score(void){
			return max;
		}

		vector<int> dir(void); 
}



int main(){
	char S1[]="GAATTCAGTTA";
	char S2[]="GGATCGA";
	int M=strlen(S1), N=strlen(S2);
	int s, s_match=2, s_mismatch=-1, w=-2;
	int Scoring[M+1][N+1], Direction[M+1][N+1];
	int maxi=0, maxj=0, max=0;

	// Matrix fill
	for(int i=0;i<M+1;i++){Scoring[i][0]=0;}
	for(int j=0;j<N+1;j++){Scoring[j][0]=0;}
	for(int i=1;i<M+1;i++){
		for(int j=1;j<N+1;j++){
			if(S1[i-1]==S2[j-1]){s=s_match;}else{s=s_mismatch;}
			v=MAX(Scoring[i-1][j-1]+s, Scoring[i][j-1]+w, Scoring[i-1][j]+w);
			Scoring[i][j]=v.score(); // is a int
			if(Scoring[i][j]>max){
				max=Scoring[i][j];
				maxi=i;
				maxj=j;
			}
			Direction[i][j]=v.dir(); // is a vector of int
		}
	}

	// traceback-->function

}

// use struct to return multiple values, 1) find max and max index, 2)traceback return 2 sequences
// use two direction string to write the final two aligned strings

