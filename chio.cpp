#include <iostream>

#define MAX 100

using namespace std;

double chio(double M[MAX][MAX], int n)
{
	double mult = 1;
	int z = 0;
	while (n - z >= 3)
	{
		if (M[z][z] == 1)
		{
			for (int i = z + 1; i < n; i++)
				for (int j = z + 1; j < n; j++)
					M[i][j] -= M[i][z] * M[z][j];
			z++;
		}
		else if (M[z][z] == 0)
		{
			int i;
			for (i = z + 1; i < n; i++)
				if (M[z][i] != 0)
					break;
			if (i == n)
				return 0;
			for (int j = z; j < n; j++)
				M[j][z] -= M[j][i];
		}
		else
		{
			double d = M[z][z];
			for (int j = z; j < n; j++)
				M[z][j] /= d;
			mult *= d;
		}
	}
	return (M[z][z] * M[z + 1][z + 1] - M[z][z + 1] * M[z + 1][z]) * mult;
}

int main()
{
	double M[MAX][MAX];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> M[i][j];
	cout << "Determinante: " << chio(M, n) << endl;
	return 0;
}

