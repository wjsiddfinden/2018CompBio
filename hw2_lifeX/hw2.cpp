#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <tuple>
#include <array>

using namespace std;


struct life{
	string name;
	string seq;
};


vector<life> ReadFile(string filename){
	
	ifstream File;
	string str, str1;
	vector<life> Life;
	life Life1;
	int n=0, s=0;

	File.open(filename);
	while(getline(File, str)){
		if(!isalpha(str[0])){
			Life1.name=str;
			n+=1;
			}	
		else{
			Life1.seq=str;
			s+=1;
			}
		if(n==s){
			Life.push_back(Life1);
			}
		}
	File.close();
	return Life;
	}

string Reverse(string str){
	string temp;
	for(int i=str.size()-1;i>=0;i--){
		temp+=str[i];
		}
	return temp;
	}

int align(string str1, string str2){
	
	string S1=str1;
	string S2=str2;

	int M=S1.length(), N=S2.length();
	int s, s_match=3, s_mismatch=-3, w=-2;
	int *Scoring = new int[(M+1)*(N+1)];
	int v[3];
	int max, index;
	
	// Matrix fill
	for(int i=0;i<M+1;i++){Scoring[i*(N+1)]=0;}
	for(int j=0;j<N+1;j++){Scoring[j]=0;}
	for(int i=1;i<M+1;i++){
		for(int j=1;j<N+1;j++){
			if(S1[i-1]==S2[j-1]){s=s_match;}else{s=s_mismatch;}
			v[0]=Scoring[(i-1)*(N+1)+(j-1)]+s;
			v[1]=Scoring[i*(N+1)+j-1]+w;
			v[2]=Scoring[(i-1)*(N+1)+j]+w;
				

			if(v[0]>v[1]){index=0;max=v[0];}
			else{index=1;max=v[1];}
			if(v[2]>max){index=2;max=v[2];}
			if(max>0){Scoring[i*(N+1)+j]=max;}
			else{Scoring[i*(N+1)+j]=0;}
			}
		}
	int ss=Scoring[(M+1)*(N+1)-1];
	delete Scoring;
	return ss;
}

int main(){

	vector<life> L1=ReadFile("Life_X_Query_Seq_2018.txt");
	vector<life> L2=ReadFile("100_known_species_Seq_2018.txt");
	life life1=L1[0];
	string s1=life1.seq;
	int score, max_score;
	string result;

	int size=L2.size();
	for(int i=0;i<size;i++){
		string str=L2[i].seq;
		string strn=L2[i].name;
		score=align(s1, str);
		if(i==0){max_score=score;}
		if(score>max_score){
			max_score=score;
			result.assign(strn);
		}
	}
	cout << "Result: " << result << endl;
	
	return 0;	
	
}	



