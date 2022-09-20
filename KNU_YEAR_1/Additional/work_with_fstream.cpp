#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

signed main()
{
    string buff = "";

    map <char, int> cnt;

    map <string, int> words;

    setlocale(LC_ALL, "rus");

    ifstream fin1 ("in.txt");
    ifstream fin2 ("in.txt");
    ofstream fout ("out.txt");

    for(string tmp; getline(fin1, tmp); buff+=tmp + "\n") ;

    for(string tmp; fin2 >> tmp; words[tmp] = tmp.size());

    cout << buff << endl;

    for(int i = 0; i < buff.size(); i++)
    {
        cnt[buff[i]]++;
    }

    cout << "1) \n" << endl;

    for(auto smb : cnt)
    {
        cout << smb.first << " : " << smb.second/double(cnt.size()) << endl;
    }

    cout << "2) \n" << endl;

    for(auto smb : cnt)
    {
        while(smb.second)
        {
            cout << smb.first;
            smb.second--;
        }
    }
    cout << endl;

    cout << "3) \n" << endl;

    for(auto pr : words)
    {
        cout << pr.first << " : " << pr.second << endl;
    }


    return 0;
}
