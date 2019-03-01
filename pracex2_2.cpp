#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	//Write your code here
	ofstream dest("rank.txt");
	ifstream source("score1.txt");
	string line;
	int i=0,k=0;
	float a[20],b[20];
	while(getline(source,line)){
		a[i]=atof(line.c_str()) ;
		i++;
	}
	sort(a,20);
	for(int i = 0; i < 20;i++){
		b[i]=i+1+k;
		while(a[i]=a[i+1]){
			b[i]=b[i+1];
			k++;
		}
	}
	for(int i=0;i<20;i++){
		dest << a[i] << "=" << b[i] << "\n";
	}
	dest.close();
	return 0;
}