#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void execute(string code)
{
    char mem[30000];
    int ptr = 0;

    for (int i = 0; i < code.size(); i++)
    {
        char curr = code[i];

        if (curr == '>')
            ptr++;

        if (curr == '<')
            ptr--;

        if (curr == '+')
            mem[ptr]++;

        if (curr == '-')
            mem[ptr]--;

        if (curr == '.')
            cout << mem[ptr];

        if (curr == ',')
        {
            char inp;
            cin >> inp;
            mem[ptr] = inp;
        }

        if (curr == '[' && mem[ptr] == 0)
        {
            int unmatched = 1;
            while (unmatched)
            {
                i++;
                if (code[i] == '[')
                    unmatched++;
                if (code[i] == ']')
                    unmatched--;
            }
        }

        if (curr == ']' && mem[ptr] != 0)
        {
            int unmatched = 1;
            while (unmatched)
            {
                i--;
                if (code[i] == '[')
                    unmatched--;
                if (code[i] == ']')
                    unmatched++;
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        ifstream file(argv[1]);
        stringstream buff;
        buff << file.rdbuf();
        file.close();
        execute(buff.str());
    }
}