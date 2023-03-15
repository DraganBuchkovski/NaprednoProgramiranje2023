#include <iostream>
#include <vector>

using namespace std;

int findSmallest(vector<int>&, int);

int main()
{
    string input = "Dragan Buckovski INKI971";
    string index_number = "INKI971";
    vector<int> ascii_codes;


    for (int i = 0; i < input.size(); i++)
    {
        int code = int(input[i]);
        ascii_codes.push_back(code);
    }

    
    for (int i = 0; i < index_number.size(); i++)
    {
        int code = int(index_number[i]);
        ascii_codes.push_back(code);
    }

    int pos, temp, pass = 0;

    cout << "\n Vnesi lista na elementi za sortiranje\n";
    for (int i = 0; i < ascii_codes.size(); i++)
    {
        cout << ascii_codes[i] << "\t";
    }

    for (int i = 0; i < ascii_codes.size(); i++)
    {
        pos = findSmallest(ascii_codes, i);
        temp = ascii_codes[i];
        ascii_codes[i] = ascii_codes[pos];
        ascii_codes[pos] = temp;
        pass++;
    }

    cout << "\n Sortiranata lista na elementi e:\n";
    for (int i = 0; i < ascii_codes.size(); i++)
    {
        cout << ascii_codes[i] << "\t";
    }

    cout << "\nBroj na premini potrebni za sortiranje na nizata: " << pass;

    return 0;
}

int findSmallest(vector<int>& ascii_codes, int i)
{
    int ele_small, position, j;
    ele_small = ascii_codes[i];
    position = i;
    for (j = i + 1; j < ascii_codes.size(); j++)
    {
        if (ascii_codes[j] < ele_small)
        {
            ele_small = ascii_codes[j];
            position = j;
        }
    }
    return position;
}
