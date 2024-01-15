#include<bits/stdc++.h>
using namespace std;

bool used[26];
vector<vector<int>> v(5, vector<int>(5, -1));

string encryption(string);

int main()
{
    string key;
    used[9] = true;
    cout << "Enter a key(capital letter): ";
    getline(cin, key);
    cout << "Key is: " << key << endl;
    int rotation = 0;
    bool flag = false;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(rotation==key.size())
            {
                flag = true;
                break;
            }
            int temp = key[rotation] - 'A';
            if(used[temp]!=true)
            {
                v[i][j] = temp;
                used[temp] = true;
            }
            rotation++;
        }
        if(flag)
            break;
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(v[i][j]==-1)
            {
                for(int k=0; k<26; k++)
                {
                    if(!used[k])
                    {
                        v[i][j] = k;
                        used[k] = true;
                        break;
                    }
                }
            }
        }
    }

    cout << "Key Matrix: " << endl;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            char c = v[i][j] + 'A';
            cout << c << ' ';
            //cout << v[i][j] << ' ';
        }
        cout << endl;
    }


    string plainText;
    cout << "Enter Plain Text(capital letter): ";
    getline(cin, plainText);
    vector<string> store;
    for(int i=0; i<plainText.size(); )
    {
        string temp = "";
        if(plainText[i]==plainText[i+1])
        {
            temp+=plainText[i];
            temp+='X';
            i++;
        }
        else
        {
            temp+=plainText[i];
            temp+=plainText[i+1];
            i+=2;
        }
        store.push_back(temp);
    }

    string cipherText = "";
    for(auto i:store)
    {
        cout << i << endl;
        cipherText+=encryption(i);
    }
    cout << "Cipher Text: " << cipherText << endl;

    return 0;
}

string encryption(string s)
{
    string cipher = "";
    int char1 = s[0] - 'A';
    int char2 = s[1] - 'A';
    int row1 = -1;
    int row2 = -1;
    int column1 = -1;
    int column2  = -1;
    bool flag = false;
    bool find1 = false;
    bool find2 = false;

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(v[i][j] == char1)
            {
                row1 = i;
                column1 = j;
                find1 = true;
            }
            else if(v[i][j] == char2)
            {
                row2 = i;
                column2 = j;
                find2 = true;
            }
            if(find1 && find2)
            {
                flag = true;
            }
        }
        if(flag)
        {
            break;
        }
    }



    if(row1 == row2)
    {
        int row = row1;
        column1++;
        column2++;
        if(column1 > 4)
        {
            column1 = 0;
        }
        if(column2 > 4)
        {
            column2 = 0;
        }
        char c1 = v[row][column1] + 'A';
        char c2 = v[row][column2] + 'A';
        cipher+=c1;
        cipher+=c2;
    }

    else if(column1 == column2)
    {
        int column = column1;
        row1++;
        row2++;
        if(row1 > 4)
        {
            row1 = 0;
        }
        if(row2 > 4)
        {
            row2 = 0;
        }
        char c1 = v[row1][column] + 'A';
        char c2 = v[row2][column] + 'A';
        cipher+=c1;
        cipher+=c2;
    }

    else
    {
        char c1 = v[row1][column2] + 'A';
        char c2 = v[row2][column1] + 'A';
        cipher+=c1;
        cipher+=c2;
    }

    return cipher;
}

