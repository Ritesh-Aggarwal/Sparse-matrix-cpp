#include <bits/stdc++.h>
using namespace std;

#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);

#define p 1000000007
#define ll long long int

class element
{
public:
	int i;
	int j;
	int x;
	inline void display()
	{
		cout << i << " " << j << " " << x << "\n";
	}
	element(int a, int b, int c)
	{
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
	// void create()
	// {
	// 	cin >> m;
	// 	cin >> n;
	// 	cin >> nums;
	// 	int i = 0;
	// 	while (i < nums)
	// 	{
	// 		int a, b, c;
	// 		cin >> a >> b >> c;
	// 		e.push_back(element(a, b, c));
	// 		i++;
	// 	}
	// }

	void createByMatrix(vector<vector<int>> &matrix)
	{
		m = matrix.size();
		n = matrix[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] != 0)
				{
					e.push_back(element (i + 1, j + 1, matrix[i][j]));
				}
			}
		}
		nums = e.size();
	}
	void display()
	{
		cout << "number of rows :" << this->m;
		cout << "\n";
		cout << "number of columns:" << this->n;
		cout << "\n";
		cout << "number of non-zero elements:" << this->nums;
		cout << "\n";
		for (int i = 0; i < this->e.size(); ++i)
		{
			this->e[i].display();
		}
		cout << "\n";
	}
	void displayMatrix()
	{
		int k = 0;
		for (int a = 0; a < m; a++)
		{
			for (int b = 0; b < n; b++)
			{
				if (nums != 0) {
					if (e[k].i - 1 == a && e[k].j - 1 == b) {
						cout << e[k].x << "\t";
						k++;
					} else
						cout << "0\t";
				} else
					cout << "Matrix is empty\n";
			}
			cout << endl;
		}
		cout << "\n";
	}

	friend istream & operator>>(istream &is, sparse &s);

	sparse operator + (sparse const &obj) {
		int a = 0, b = 0;
		if (m == obj.m && n == obj.n) {
			sparse result(m, n);
			while (a < e.size() || b < obj.e.size()) {
				if (e[a].i == obj.e[b].i) {
					if (e[a].j == obj.e[b].j) {
						result.e.push_back(element (e[a].i, e[a].j, e[a].x + obj.e[b].x));
						a++;
						b++;
					} else if (e[a].j < obj.e[b].j) {
						result.e.push_back(element (e[a].i, e[a].j, e[a].x));
						a++;
					} else {
						result.e.push_back(element (e[a].i, obj.e[b].j, obj.e[b].x));
						b++;
					}
				} else if (e[a].i < obj.e[b].i) {
					result.e.push_back(element (e[a].i, e[a].j, e[a].x));
					a++;
				} else {
					result.e.push_back(element (obj.e[b].i, obj.e[b].j, obj.e[b].x));
					b++;
				}
			}
			result.nums = result.e.size();
			return result;
		} else return sparse (1, 1);

	}

	sparse operator - (sparse const &obj) {
		int a = 0, b = 0;
		if (m == obj.m && n == obj.n) {
			sparse result(m, n);
			while (a < e.size() || b < obj.e.size()) {
				if (e[a].i == obj.e[b].i) {
					if (e[a].j == obj.e[b].j) {
						result.e.push_back(element (e[a].i, e[a].j, e[a].x - obj.e[b].x));
						a++;
						b++;
					} else if (e[a].j < obj.e[b].j) {
						result.e.push_back(element (e[a].i, e[a].j, e[a].x));
						a++;
					} else {
						result.e.push_back(element (e[a].i, obj.e[b].j, -1 * obj.e[b].x));
						b++;
					}
				} else if (e[a].i < obj.e[b].i) {
					result.e.push_back(element (e[a].i, e[a].j, e[a].x));
					a++;
				} else {
					result.e.push_back(element (obj.e[b].i, obj.e[b].j, -1 * obj.e[b].x));
					b++;
				}
			}
			result.nums = result.e.size();
			return result;
		} else return sparse (1, 1);

	}

	sparse() {}
	sparse(int a, int b) {
		m = a; n = b; nums = 0;
	}
};

istream & operator>>(istream &is, sparse &s)
{
	cin >> s.m;
	cin >> s.n;
	cin >> s.nums;
	int i = 0;
	while (i < s.nums)
	{
		int a, b, c;
		cin >> a >> b >> c;
		s.e.push_back(element(a, b, c));
		i++;
	}
	return is;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FIO;

	sparse A;
	cin >> A;
	// A.display();
	A.displayMatrix();

	vector<vector<int>> matrix1{
		{1, 0, 0},
		// {1, 2, 0},
		{0, 2, 5},
		{0, 0, 3}};
	sparse B;
	B.createByMatrix(matrix1);
	// B.display();
	B.displayMatrix();


	sparse C;
	C = (A - B) + B;
	// C.display();
	C.displayMatrix();
	return 0;
}
