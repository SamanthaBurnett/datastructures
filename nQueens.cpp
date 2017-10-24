/*
Name: Samantha Burnett
Presented to: Prof. Ramos
Purpose: To solve n queens problem
*/

#include <iostream>
#include <stack>
#include<cmath>

using namespace std;

struct Queen
{
	Queen(int row, int col)
	{
		this->row = row;
		this->col = col;
	}
	Queen()
	{
		this->row = 1;
		this->col = 1;
	}
	int row;
	int col;
};

void solve(stack<Queen>&, int& Size);
bool isConflict(Queen a, stack<Queen> b);

int main() 
{
	int b_size;
	
	cout << "How big do you want your board to be? Ex. 5 (for a 5 x 5 board) : ";
	cin >> b_size;
	
	if (b_size < 4)
	{
		cout << "Size cannot be below 4. Try again.";
	}
	
	else
	{
		cout << "We will now try to place " << b_size << " queens on a " << b_size << " by " << b_size << " board." << endl;

		stack<Queen> q; //creates stack of queens
		solve(q, b_size);

		while (!q.empty())
		{
			cout << (q.top().row) << " " << (q.top().col) << endl;
			q.pop();
		}
	}
	system("pause");
    return 0;
}

void solve(stack<Queen>& queens , int& Size)
{
	if (queens.size() >= Size) return;

	if (queens.empty())
		queens.push(Queen(1,1));

	for (int i = 1; i <= Size; ++i)
	{
		Queen s(queens.top().row + 1 ,i);
		if (queens.size() < Size && !isConflict(s , queens))
		{
			queens.push(s);
			solve(queens, Size);
			if (queens.size() != Size)
			queens.pop();
		}
	}
	if (queens.size() == 1 && queens.top().col < Size)
	{
		queens.top().col++;
		solve(queens , Size);
	}
}




bool isConflict(Queen queen, stack<Queen> searchStack)
{
	while(!searchStack.empty())
	{
		if (queen.col == (searchStack.top().col) || queen.row == (searchStack.top().row) || abs(float(queen.row - (searchStack.top().row)) / float(queen.col - (searchStack.top().col))) == 1)
		{
			return true;
		}
		searchStack.pop();
	}
	
	return false;
}