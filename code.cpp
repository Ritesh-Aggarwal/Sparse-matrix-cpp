
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define p 1000000007
#define ll long long int

struct element
{

	int i;
	int j;
	int x;
	inline void display() {
		cout << i << " " << j << " " << x << "\n";
	}

	element(int a, int b, int c) {
		i = a;
		j = b;
		x = c;
	}
};

class sparse
{
private:
	int m;
	int n;
	int nums;
	vector<element> e;
public:

	void create() {
		cin >> m;
		cin >> n;
		cin >> nums;
		int i = 0;
		while (i < nums)
		{
			int a, b, c;
			cin >> a >> b >> c;
			// element ele(a, b, c);
			e.push_back(element (a, b, c));
			i++;
		}
	}
	void display() {
		cout << "list details: \n";
		cout << "number of rows :" << this->m; cout << "\n";
		cout << "number of columns:" << this->n; cout << "\n";
		cout << "number of non-zero elements:" << this->nums; cout << "\n";
		for (int i = 0; i < this->e.size(); ++i)
		{
			this->e[i].display();
		}
	}
	void displayMatrix() {

		vector<vector<int>> vec( n , vector<int> (m));

		for (int k = 0; k < e.size(); k++) {
			int r = e[k].i;
			int c = e[k].j;
			vec[r - 1][c - 1] = e[k].x;
		}

		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				cout << vec[a][b] << "\t";
			}
			cout << endl;
		}
	}
	void createByMatrix(vector< vector<int> > &matrix) {
		m = matrix.size();
		n = matrix[0].size();
		e.push_back(element (m, n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] != 0) {
					e.push_back(element (i + 1, j + 1, matrix[i][j]));
				}
			}
		}
		nums = e.size() - 1;
		e[0].x = nums;

	}
};



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FIO;

	sparse A;
	A.create();
	A.display();
	A.displayMatrix();

	vector< vector<int>> matrix1 {
		{1, 0, 0},
		{0, 2, 4},
		{0, 0, 3}
	};
	sparse B;
	B.createByMatrix(matrix1);
	B.display();
	B.displayMatrix();

	return 0;
}



