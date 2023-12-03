// AoC day 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

int main()
{
    ofstream out("out.txt");
    streambuf* coutbuf = std::cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirects std::cout to out.txt */
    int total = 0;
    int digit1_spot = 0;
    char digit1;
    int line_num = 0;
    ifstream fin("input.txt");
    string line;
    while (getline(fin, line)) {
        string num;
        for (int i = 0; i < line.size(); ++i) {
            if (num.length() >= 1) {
                break;
            }
            if (isdigit(line[i])) {
                num += line[i];
                digit1_spot = i;
                digit1 = line[i];
                //keeps track of first digit
            }
        }
        for (int j = line.size() - 1; j > -1; --j) {
            if (num.length() == 2) {
                break;
            }
            if (j == digit1_spot) {
                num += digit1;
                break;
            }
            if (isdigit(line[j])) {
                num += line[j];
            }
        }
        cout << "num on line " << line_num << ": " << num << endl;
        total += stoi(num);
        line_num++;
    }
    cout << "total: " << total << endl;
    cout.rdbuf(coutbuf); //resets to standard output
    return total;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
