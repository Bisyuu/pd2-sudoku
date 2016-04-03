#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		bool check_result();
		void check_zero();
		void recursive(int a);
		bool check_solvable();
		void print(int x);
	private:
		int isCorrect,hint,Qr[9][9],ans[9][9],Row_zero[81],Col_zero[81];
};
