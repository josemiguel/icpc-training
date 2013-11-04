#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
 
using namespace std;
 
struct AhoCorasick
{
    map <int, map <char, int> > go_to;
    vector <int> failure;
    map <int, vector <int> > output;
    vector <bool> found;
 
    void const_goto (vector <string> &S)
    {
        found.resize (S.size(), 0);
 
        int new_state = 0;
        for (int i = 0; i < S.size(); i++)
        {
            int state = 0, j = 0;
            while (j < S[i].size() && go_to[state].count(S[i][j]) >= 1)
            {
                state = go_to[state][S[i][j]];
                j++;
            }
 
            for (int k = j; k < S[i].size(); k++)
            {
                new_state++;
                go_to[state][S[i][k]] = new_state;
                state = new_state;
            }
 
            if (output.count(state) > 0)
            {
                output[state].push_back(i);
            }
            else
            {
                output[state] = vector <int> (1, i);
            }
 
        }
 
        failure.resize(new_state+1, 0);
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (go_to[0].count(i) == 0)
            {
                go_to[0][i] = 0;
            }
        }
        for (char i = 'A'; i <= 'Z'; i++)
        {
            if (go_to[0].count(i) == 0)
            {
                go_to[0][i] = 0;
            }
 
        }
 
        const_failure ();
    }
 
    void const_failure ()
    {
        queue <int> q;
        int r, state;
        for (map <char, int> :: iterator it = go_to[0].begin(); it != go_to[0].end(); it++)
        {
            if ((*it).second != 0)
            {
                q.push ((*it).second);
                failure[(*it).second] = 0;
            }
        }
 
        while (!q.empty())
        {
            r = q.front ();
            q.pop();
 
            state = failure[r];
            for (map <char, int> :: iterator it = go_to[r].begin(); it != go_to[r].end(); it++)
            {
                if (go_to[r].count((*it).first) != 0)
                {
                    q.push((*it).second);
                    state = failure[r];
                    while (go_to[state].count((*it).first) == 0)
                    {
                        state = failure[state];
                    }
                    failure[(*it).second] = go_to [state][(*it).first];
                    output[(*it).second].insert(output[(*it).second].end(),output[failure[(*it).second]].begin(), output[failure[(*it).second]].end());
                }
            }
 
        }
    }
 
    void pattern_match (string &S)
    {
        int state = 0;
        for (int i = 0; i < S.size(); i++)
        {
            while (go_to[state].count(S[i]) == 0)
            {
                state = failure[state];
            }
 
            state = go_to [state][S[i]];
            if (output.count(state) > 0)
            {
                int tam = output[state].size();
                vector <int> tmp = output[state];
                for (int j = 0; j < tam; j++)
                {
 
                    found[tmp[j]] = 1;
                }
            }
        }
    }
};
 
int main ()
{
    int k, q;
    string s;
    cin >> k;
    while (k--)
    {
        cin >> s >> q;
        AhoCorasick AC;
        vector <string> queries (q);
 
        for (int j = 0; j < q; j++)
        {
            cin >> queries[j];
        }
 
        AC.const_goto (queries);
        AC.pattern_match (s);
 
        for (int i = 0; i < AC.found.size(); i++)
        {
            if (AC.found[i])
            {
                cout << "y" << endl;
            }
            else
            {
                cout << "n" << endl;
            }
        }
    }
    return 0;
 
}
