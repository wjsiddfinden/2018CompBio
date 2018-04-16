#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <tuple>
#include <array>

using namespace std;

tuple<int, int, int, int > MAX(int n1, int n2, int n3){
	int max_value, left_up=0, left=0, up=0;
	vector<int> score={n1, n2, n3};
	max_value=max(n1, n2, n3);
	if(n1==max_value){left_up=1;}
	if(n2==max_value){left=1;}
	if(n3==max_value){up=1;}
	return make_tuple(max_value, left_up, left, up);
	}

int main(){
	string S1="GAATTCAGTTA";
	string S2="GGATCGA";
	int M=S1.length(), N=S2.length();
	int s, s_match=2, s_mismatch=-1, w=-2;
	int Scoring[M+1][N+1];
	int Direction[M][N][3];
	int maxi=0, maxj=0, max=0;
	tuple<int, array<int, 3>> v;

	// Matrix fill
	for(int i=0;i<M+1;i++){Scoring[i][0]=0;}
	for(int j=0;j<N+1;j++){Scoring[j][0]=0;}
	for(int i=1;i<M+1;i++){
		for(int j=1;j<N+1;j++){
			if(S1[i-1]==S2[j-1]){s=s_match;}else{s=s_mismatch;}
			v=MAX(Scoring[i-1][j-1]+s, Scoring[i][j-1]+w, Scoring[i-1][j]+w);
			Scoring[i][j]=get<0>(v); // is a int
			Direction[i-1][j-1]=get<1>(v); // is a vector of vector boolean	
			}
		}
	
	// traceback-->function
	int i=M-1, j=N-1;
	string aS1=S1[i], aS2=S2[j];
	while(i>0 & j>0){
		if(Direction[i][j][0]==1){
			i-=1;
			j-=1;
			aS1.insert(0, S1[i]);
			aS2.insert(0, S2[j]);
			}
		else if(Direction[i][j][1]==1){
			j-=1;
			aS1.insert(0, ' ');
			aS2.insert(0, S2[j]);		
			}
		else if(Direction[i][j][2]==1){
			i-=1;
			aS1.insert(0, S1[i]);
			aS2.insert(0, ' ');
			}
		}	
	cout << aS1 << '\n' << aS2 << endl;
	}

	


// use struct to return multiple values, 1) find max and max index, 2)traceback return 2 sequences
// use two direction string to write the final two aligned strings

