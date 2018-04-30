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
		// cout << str << endl;
		// cout << str[0] << endl;
		if(!isalpha(str[0])){
			Life1.name=str;
			n+=1;
			// cout << "n=" << n << endl;  
			}	
		else{
			Life1.seq=str;
			s+=1;
			// cout << "s=" << s << endl;  
			}
		if(n==s){
			Life.push_back(Life1);
			// cout << n << ": " << Life.size() << endl;
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
	cout << "S1, S2" << endl;

	int M=S1.length(), N=S2.length();
	// cout << "M, N" << endl;
	int s, s_match=2, s_mismatch=-1, w=-2;
	// cout << "parameter" << endl;
	int Scoring[M+1][N+1];
	cout << "scoring matrix" << endl;
	// int Direction[M][N];
	// cout << "direction matrix" << endl;
	int v[3];
	// cout << "vector" << endl;
	int max, index;
	
	// cout << "finish declare" << endl;
		
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
			// Direction[i-1][j-1]=index;
			}
		}
	cout << "end scoring" << endl;
	// delete[] Scoring;
	return Scoring[M][N];

/*	// traceback-->function
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
*/	

}

int main(){

	vector<life> L1=ReadFile("Life_X_Query_Seq_2018.txt");
	// cout << "end read life X" << endl;

	vector<life> L2=ReadFile("100_known_species_Seq_2018.txt");
	//cout << "end read life 100" << endl;

	//cout << L1.size() << endl;

	life life1=L1[0];
	//cout << life1.name << endl;
	
	string s1=life1.seq;
	int score, max_score=0;
	string result;

	int size=L2.size();
	for(int i=0;i<size;i++){
		cout << L2[i].name << endl;
		string str=L2[i].seq;
		// cout << "string= " << str << endl;
		score=align(s1, str);
		cout << "score= " << score << endl;
		if(score>max_score){
			max_score=score;
			result=L2[i].name;	
		}

	cout << result << " is the closest species." << endl;
	
	}
}	



