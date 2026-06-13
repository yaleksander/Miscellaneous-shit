#include <iostream>
#include <cstring>

#define TAM 200

using namespace std;

int separa(char s0[], char s1[], char s2[])
{
    strcpy(s1, s0);
    int n = 0, j = 0;
    while (s1[n] != '\0')
        n++;
    while (s1[n] != ' ')
        n--;
    s1[n] = '\0';
    for (int i = n + 1; s1[i] != '\0'; i++, j++)
    {
        s2[j] = s1[i];
        if (s1[i] >= 'a' && s1[i] <= 'z')
            s2[j] = s2[j] - 'a' + 'A';
    }
    s2[j] = '\0';
    return j;
}

void abrev(char s1[], char s2[], int j, int k, bool espaco)
{
    s2[j++] = s1[k];
    s2[j++] = '.';
    if (espaco)
        s2[j++] = ' ';
    for (int i = k + 1; s1[i] != '\0'; i++)
    {
        if (s1[i] == ' ')
        {
            s2[j++] = s1[i + 1];
            s2[j++] = '.';
            if (espaco)
                s2[j++] = ' ';
        }
    }
    s2[j] = '\0';
}

void cite1(char s1[], char s2[])
{
    char nome[TAM], sobrenome[TAM];
    separa(s1, nome, sobrenome);
    int i;
    for (i = 0; nome[i] != ' '; i++)
        s2[i] = nome[i];
    s2[i++] = ' ';
    abrev(nome, s2, i, i, true);
    strcat(s2, sobrenome);
}

void cite2(char s1[], char s2[])
{
    char nome[TAM];
    separa(s1, nome, s2);
    strcat(s2, ", ");
    strcat(s2, nome);
}

void cite3(char s1[], char s2[])
{
    char nome[TAM];
    int j = separa(s1, nome, s2) + 2;
    strcat(s2, ", ");
    abrev(nome, s2, j, 0, false);
}

int main()
{
    char s1[TAM], s2[TAM];
    cin.getline(s1, TAM);
    cite1(s1, s2);
    cout << s2 << endl;
    cite2(s1, s2);
    cout << s2 << endl;
    cite3(s1, s2);
    cout << s2 << endl;
    return 0;
}
