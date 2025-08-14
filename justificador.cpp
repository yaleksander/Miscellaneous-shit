#include <iostream>
#include <cstring>

#define TAM 5000

using namespace std;

void formatar(char orig[])
{
	int i, j = 0;
	char* dest;
	for (i = 0; orig[i] != '\0'; i++)
	{
		dest[j++] = orig[i];
		while (orig[i] == ' ')
			i++;
	}
	dest[i] = '\0';
	orig = dest;
}

void justificar(char str[], int col)
{
	char linha[col + 1];
	int espacos[col];
	int i, d, dif, inicio = 0, n = strlen(str);
	do
	{
		while (str[inicio] == ' ')
			inicio++;
		for (i = 0; str[inicio + i] != '\0' && i < col + 1; i++)
			linha[i] = str[inicio + i];
		while (i > 0 && linha[i] != ' ')
			i--;
		if (i == 0)
			i = col + 1;
		linha[i] = '\0';
		inicio += i;
		dif = col - strlen(linha);
		for (i = 0; linha[i] != '\0'; i++)
			espacos[i] = (linha[i] == ' ' ? 1 : 0);
		while (dif > 0)
		{
			d = dif;
			for (i = 0; linha[i] != '\0'; i++)
				if (linha[i] == ' ')
					if (dif-- > 0)
						espacos[i]++;
			if (d == dif)
				break;
		}
		for (i = 0; linha[i] != '\0'; i++)
		{
			cout << linha[i];
			for (int j = 1; j < espacos[i]; j++)
				cout << ' ';
		}
		cout << endl;
	}
	while (inicio < n);
}

int main(int argc, char** argv)
{
	if (argc < 2)
		return 1;
	char str[TAM];
	cin.getline(str, TAM);
	formatar(str);
	justificar(str, stoi(argv[1]));
	return 0;
}

