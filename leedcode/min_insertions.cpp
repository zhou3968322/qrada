#include <iostream>
#include <string>

using namespace std;

void searchMinInsertions(string& s, int first, int last, int count, int &dfs)
{
    if (first >= last)
    {
        cout << "result,string:" << s << "\tcount:" << count << "\tdfs:" << dfs << endl;
        if (dfs > count)
            dfs = count;
    }
    else if (s[first] == s[last])
        searchMinInsertions(s, first + 1, last - 1, count, dfs);
    else
    {
        string f_s(s, first, 1);
        s.insert(last + 1, f_s);
        searchMinInsertions(s, first + 1, last, count + 1, dfs);
        s.erase(last + 1);
        string l_s(s, last, 1);
        s.insert(first, l_s);
        searchMinInsertions(s, first, last - 1, count + 1, dfs);
        s.erase(first);
    }
}

int minInsertions(string s)
{
    int dfs = s.size() - 1;
    int first = 0;
    int last = s.size() - 1;
    searchMinInsertions(s, first, last, 0, dfs);
    return dfs;
}

int main(int argc, char const *argv[])
{
    string s = "leetcodeaber23gb";
    int count = minInsertions(s);
    cout << count << endl;
    return 0;
}
