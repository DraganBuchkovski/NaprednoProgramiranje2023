#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;

struct VremenskaPrognozaMK 

{
    string grad;
    int dnevnatemp;
    int nokjnatemp;
    bool operator<(const VremenskaPrognozaMK& other) const 
    {
        return dnevnatemp > other.dnevnatemp;
    }
};

int main()
{
    vector<VremenskaPrognozaMK> vremenska_prognoza;
    vremenska_prognoza.push_back({ "Skopje", 22, 12 });
    vremenska_prognoza.push_back({ "Ohrid", 24, 14 });
    vremenska_prognoza.push_back({ "Bitola", 25, 15 });
    vremenska_prognoza.push_back({ "Tetovo", 23, 13 });
    vremenska_prognoza.push_back({ "Kumanovo", 19, 9 });
    vremenska_prognoza.push_back({ "Veles", 20, 10 });
    vremenska_prognoza.push_back({ "Gostivar", 18, 8 });
    vremenska_prognoza.push_back({ "Strumica", 21, 11 });
    vremenska_prognoza.push_back({ "Prilep", 20, 10 });
    vremenska_prognoza.push_back({ "Kavadarci", 23, 13 });

    //Pecatenje na sodrzinata od vektorot
    cout << "Sodrzina na vektorot:" << endl;
    for (auto& i : vremenska_prognoza)
    {
        cout << "Grad: " << i.grad << ", Dnevna temperatura: " << i.dnevnatemp << ", Nokjna temperatura: " << i.nokjnatemp << endl;
    }

    //Sortiranje na vektorot
    sort(vremenska_prognoza.begin(), vremenska_prognoza.end());

    // Pecatenje na sortiranata sodrzina na vektorot po opagjacki redosled
    cout << endl << "Sortirana sodrzina na vektorot po opagjacki redosled:" << endl;
    for (auto& i : vremenska_prognoza) {
        cout << "Grad: " << i.grad << ", Dnevna temperatura: " << i.dnevnatemp << ", Nokjna temperatura: " << i.nokjnatemp << endl;
    }

    //Zemanje na denesniot datum
    time_t now = time(0);
    tm* datum = localtime(&now);
    //Zacuvuvanje na sodrzinata od vektorot vo file
    string file = "INKI971-vremenskaprognoza" + to_string(datum->tm_mon + 1) + to_string(datum->tm_mday) + ".txt";
    ofstream outFile(file);
    if (outFile.is_open())
    {
        for (auto& i : vremenska_prognoza)
        {
            outFile << i.grad << "," << i.dnevnatemp << "," << i.nokjnatemp << endl;
        }
        outFile.close();
    }
    else {
        cout << endl << "Error" << endl;
    }
    return 0;
}