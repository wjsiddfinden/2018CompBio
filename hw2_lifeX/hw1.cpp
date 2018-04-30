#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <tuple>
#include <array>

using namespace std;

string Reverse(string str){
	string temp;
	for(int i=str.size()-1;i>=0;i--){
		temp+=str[i];
		}
	return temp;
	}

string ReadFile(string filename){
	
	ifstream File;
	string str, str1;
	
	File.open(filename);
	while(getline(File, str)){
		str1 = str;
		}
	File.close();
	return str1;
	}

int main(){
	
	string S1=ReadFile("seq1.fa");
	string S2=ReadFile("seq2.fa");

	int M=S1.length(), N=S2.length();
	int s, s_match=2, s_mismatch=-1, w=-2;
	int Scoring[M+1][N+1];
	int Direction[M][N];
	int v[3];
	int max, index;
	
	// Matrix fill
	for(int i=0;i<M+1;i++){Scoring[i][0]=0;}
	for(int j=0;j<N+1;j++){Scoring[j][0]=0;}
	for(int i=1;i<M+1;i++){
		for(int j=1;j<N+1;j++){
			if(S1[i-1]==S2[j-1]){s=s_match;}else{s=s_mismatch;}
			v[0]=Scoring[i-1][j-1]+s;
			v[1]=Scoring[i][j-1]+w;
			v[2]=Scoring[i-1][j]+w;

			if(v[0]>v[1]){index=0;max=v[0];}
			else{index=1;max=v[1];}
			if(v[2]>max){index=2;max=v[2];}
			Scoring[i][j]=max;
			Direction[i-1][j-1]=index;
			}
		}

	// traceback-->function
	int i=M-1, j=N-1;
	string aS1, aS2;
	char space='_';
	aS1=S1[i], aS2=S2[j];
	while(i>0 & j>0){
		if(Direction[i][j]==0){
			i-=1;
			j-=1;
			aS1+=S1[i];
			aS2+=S2[j];
			}
		else if(Direction[i][j]==1){
			j-=1;
			aS1+=space;
			aS2+=S2[j];		
			}
		else if(Direction[i][j]==2){
			i-=1;
			aS1+=S1[i];
			aS2+=space;
			}
		}
	
	aS1=Reverse(aS1);
	aS2=Reverse(aS2);	
	// cout << aS1 << '\n' << aS2 << endl;

	string o_filename="alignment.dat";
	ofstream outfile;
	outfile.open(o_filename);
	outfile << aS1 << '\n' << aS2;
	outfile.close();
	}

	



