#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
using namespace std;

void Sudoku::giveQuestion(){
				srand(time(NULL));
				int i,j,n=rand()%10;
				int Q1[10][9][9] = {
							{{3,1,2,0,0,5,4,0,6},{0,0,8,0,0,1,3,0,0},{0,0,6,0,0,0,5,0,7},{0,0,0,0,4,6,0,0,0},{0,0,1,0,0,0,6,0,0},{0,0,0,3,8,0,0,0,0},{2,0,4,0,0,0,1,0,0},{0,0,7,5,0,0,8,0,0},{5,0,3,7,0,0,2,6,4}},
							{{0,0,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},{8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9}},
							{{0,0,0,3,1,0,9,0,0},{0,0,9,0,0,2,0,6,4},{0,4,0,0,0,0,2,3,0},{0,0,5,0,0,0,0,0,8},{8,7,0,0,0,0,0,4,9},{2,0,0,0,0,0,5,0,0},{0,3,2,0,0,0,0,5,0},{5,6,0,2,0,0,8,0,0},{0,0,7,0,5,3,0,0,0}},
							{{7,0,0,1,8,0,0,9,0},{0,0,1,0,0,0,2,0,0},{5,0,0,0,0,4,3,0,0},{0,0,0,4,0,0,0,0,3},{3,0,4,8,0,5,7,0,2},{1,0,0,0,0,2,0,0,0},{0,0,2,5,0,0,0,0,8},{0,0,3,0,0,0,6,0,0},{0,1,0,0,9,8,0,0,5}},
							{{0,0,0,0,0,1,9,8,4},{3,4,0,0,0,0,0,0,0},{0,0,0,0,0,4,0,5,0},{7,0,1,0,2,0,5,0,0},{0,0,5,7,0,6,4,0,0},{0,0,4,0,8,0,7,0,6},{0,8,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,4,3},{4,9,7,3,0,0,0,0,0}},
							{{9,0,0,6,0,5,0,0,0},{5,3,8,4,0,0,0,0,0},{0,0,6,1,8,0,0,0,0},{0,0,4,2,0,0,6,3,0},{0,0,0,0,3,0,0,0,0},{0,7,3,0,0,4,9,0,0},{0,0,0,0,2,8,3,0,0},{0,0,0,0,0,1,4,8,9},{0,0,0,3,0,6,0,0,2}},
							{{0,0,7,0,0,0,4,0,9},{0,0,6,9,0,5,2,0,0},{8,0,0,0,7,0,0,0,0},{0,3,0,0,0,8,0,0,6},{1,0,0,0,6,0,0,0,5},{7,0,0,2,0,0,0,8,0},{0,0,0,0,9,0,0,0,2},{0,0,1,8,0,6,5,0,0},{5,0,9,0,0,0,3,0,0}},
							{{0,0,0,0,9,4,0,0,1},{0,2,6,0,0,7,0,0,0},{0,8,0,6,0,0,0,0,9},{5,9,0,0,0,0,0,0,0},{8,0,3,0,5,0,9,0,6},{0,0,0,0,0,0,0,4,5},{7,0,0,0,0,2,0,6,0},{0,0,0,5,0,0,1,9,0},{4,0,0,9,1,0,0,0,0}},
							{{2,0,0,0,0,0,8,1,0},{0,0,0,5,0,9,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,8,7,0,6,5,0},{0,0,0,3,0,0,0,4,0},{1,0,0,0,0,0,0,0,0},{0,5,0,0,0,0,3,0,0},{0,4,0,0,1,0,0,0,0},{0,0,0,0,2,0,0,0,0}},
							{{0,1,5,0,0,0,0,0,2},{0,0,0,3,0,4,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,9,0,0,0,0,4,0},{0,0,0,1,0,0,0,7,0},{0,0,0,0,2,0,0,0,0},{0,4,6,0,8,5,0,0,0},{0,7,0,0,0,9,0,0,0},{0,0,0,0,0,0,0,0,1}}};				

				for(i=0;i<9;i++)
					for(j=0;j<9;j++) Qr[i][j] = Q1[n][i][j];
				print(1);
	}
	
void Sudoku::readIn(){
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++) cin >> Qr[i][j];
	}

void Sudoku::solve(){
				hint = 0;
				isCorrect = 0;
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++){
						ans[i][j] = 0;
						Row_zero[i*9+j] = 0;
						Col_zero[i*9+j] = 0;						
				}

				if(check_solvable()){
					if(hint>=17){
						if(check_result()) isCorrect++;
						else {
							check_zero();
							recursive(0);
						}
					}
					else isCorrect = 2;
				}
				
				if(isCorrect==0) cout << 0 << endl;
				if(isCorrect>1) cout << 2 << endl;
				if(isCorrect==1){
					cout << 1 << endl;
					print(0);
				}
	}

void Sudoku::changeNum(int a,int b){
				if(a<0||a>9||b<0||b>9) return;
				int i,j;
				
				for(i=0;i<9;i++)
					for(j=0;j<9;j++) if(Qr[i][j]==a)  Qr[i][j]=-1;
				for(i=0;i<9;i++) 
					for(j=0;j<9;j++) if(Qr[i][j]==b)  Qr[i][j]=a;
				for(i=0;i<9;i++) 
					for(j=0;j<9;j++) if(Qr[i][j]==-1) Qr[i][j]=b;
	}

void Sudoku::changeRow(int a,int b){
				if(a<0||a>2||b<0||b>2) return;
				int i,j,temp[3][9];
					
				for(i=0;i<3;i++)
					for(j=0;j<9;j++){
						temp[i][j] = Qr[a*3+i][j];
						Qr[a*3+i][j] = Qr[b*3+i][j];
						Qr[b*3+i][j] = temp[i][j];
					}
	}
	
void Sudoku::changeCol(int a,int b){
				if(a<0||a>2||b<0||b>2) return;
				int i,j,temp[3][9];
				
				for(i=0;i<3;i++)
					for(j=0;j<9;j++){
						temp[i][j] = Qr[j][a*3+i];
 						Qr[j][a*3+i] = Qr[j][b*3+i];
 						Qr[j][b*3+i] = temp[i][j];
 					}
	}
	
void Sudoku::rotate(int n){
				if(n<0||n>100) return;
				
				int i,j,k,temp[9][9];
				if(n>=4) n=n%4;
				if(n==0) return;
				
				for(k=0;k<n;k++){
					for(i=0;i<9;i++)
						for(j=0;j<9;j++) temp[i][j] = Qr[8-j][i];
					for(i=0;i<9;i++)
						for(j=0;j<9;j++) Qr[i][j] = temp[i][j];
				}
	}

void Sudoku::flip(int n){
				int i,j,temp[4][9];
			
				if(n==0) for(i=0;i<4;i++)
							for(j=0;j<9;j++){
								temp[i][j] = Qr[j][i];
								Qr[j][i] = Qr[j][8-i];
								Qr[j][8-i] = temp[i][j];
							}
			
				if(n==1) for(i=0;i<4;i++)
							for(j=0;j<9;j++){
								temp[i][j] = Qr[i][j];
								Qr[i][j] = Qr[8-i][j];
								Qr[8-i][j] = temp[i][j];	
							}
	}

void Sudoku::transform(){
				srand(time(NULL));
				readIn();
				changeRow(rand()%3,rand()%3);
				rotate(rand()%101);
				changeCol(rand()%3,rand()%3);
				flip(rand()%2);
				changeNum(rand()%9+1,rand()%9+1);
				print(1);
	}
	
bool Sudoku::check_result(){
				for(int i=8;i>=0;i--)
					for(int j=8;j>=0;j--)
						if(Qr[i][j]==0) return false;
				for(int i=0;i<9;i++)
						for(int j=0;j<9;j++) ans[i][j] = Qr[i][j];		
				return true;
	}
	
void Sudoku::check_zero(){
				int i=0,j=0,k=0;
				for(i=0;i<9;i++)
					for(j=0;j<9;j++) if(Qr[i][j]==0){
						Row_zero[k] = i;
						Col_zero[k] = j;
						k++;
					}
	}	

void Sudoku::recursive(int a){
				if(isCorrect>=2) {
					cout << 2 << endl;
					exit(0);
				}		
				int i,j,Row,Col,possibility[9]={0};

				Row = Row_zero[a];
				Col = Col_zero[a];
				
				if(Row==0&&Col==0&&a!=0){
					for(i=0;i<9;i++)
						for(j=0;j<9;j++) ans[i][j] = Qr[i][j];
					isCorrect++;
					return;
				}
				
				for(i=0;i<9;i++) if(Qr[Row][i]!=0) possibility[Qr[Row][i]-1] += 1;
				for(i=0;i<9;i++) if(Qr[i][Col]!=0) possibility[Qr[i][Col]-1] += 1;
				for(i=0;i<3;i++)
					for(j=0;j<3;j++) 
						if(Qr[Row/3*3+i][Col/3*3+j]!=0) 
							if((Row/3*3+i)!=Row&&(Col/3*3+j)!=Col) possibility[Qr[Row/3*3+i][Col/3*3+j]-1] += 1;

				for(i=0;i<9;i++)
					if(possibility[i]==0){
						Qr[Row][Col] = i+1;
						recursive(a+1);
					}
				Qr[Row][Col] = 0;
	}

bool Sudoku::check_solvable(){
				int i,j,k,l,check[9]={0};
				
				for(i=0;i<9;i++){
					for(j=0;j<9;j++) if(Qr[i][j]!=0){
						check[Qr[i][j]-1] += 1;
						hint++;
					}
					for(j=0;j<9;j++){
						if(check[j]>=2) return false;
						check[j] = 0;
					}
				}
				for(i=0;i<9;i++){
					for(j=0;j<9;j++) if(Qr[j][i]!=0) check[Qr[j][i]-1] += 1;
					for(j=0;j<9;j++){
						if(check[j]>=2) return false;
						check[j] = 0;
					}
				}
				for(i=0;i<9;i+=3)
					for(j=0;j<9;j+=3){
						for(k=0;k<3;k++)
							for(l=0;l<3;l++) if(Qr[i+k][j+l]!=0) check[Qr[i+k][j+l]-1] += 1;
						for(k=0;k<9;k++){
							if(check[k]>=2) return false;
							check[k] = 0;
						}
					}
				return true;
	}

void Sudoku::print(int x){
				for(int i=0;i<9;i++)
					for(int j=0;j<9;j++) if(x==1) cout << Qr[i][j] << ((j<8)?' ':'\n');
									 else cout << ans[i][j] << ((j<8)?' ':'\n');
	}
