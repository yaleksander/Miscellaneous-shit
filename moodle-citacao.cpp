#include <iostream>

#define TAM 200

using namespace std;

void separa(char s1[], char s2[])
{
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
}

void abrev(char str[], int k, bool espaco)
{
    cout << str[k] << '.';
    if (espaco)
        cout << ' ';
    for (int i = k + 1; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            cout << str[i + 1] << '.';
            if (espaco)
                cout << ' ';
        }
    }
}

void cite1(char str[], char sn[])
{
    int i;
    for (i = 0; str[i] != ' '; i++)
        cout << str[i];
    cout << ' ';
    abrev(str, i + 1, true);
    cout << sn << endl;
}

void cite2(char str[], char sn[])
{
    cout << sn << ", ";
    for (int i = 0; str[i] != '\0'; i++)
        cout << str[i];
    cout << endl;
}

void cite3(char str[], char sn[])
{
    cout << sn << ", ";
    abrev(str, 0, false);
    cout << endl;
}

int main()
{
    char str[TAM], sn[TAM];
    cin.getline(str, TAM);
    separa(str, sn);
    cite1(str, sn);
    cite2(str, sn);
    cite3(str, sn);
    return 0;
}

