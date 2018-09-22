#include <bits/stdc++.h>
using namespace std;

int F[MAXLEN];
void build(char *s){
    F[0] = -1;
    for (int i = 1, pos = -1; s[i] ; i++){
        while (~pos && s[i] != s[pos + 1]) pos = F[pos];
        if (s[i] == s[pos + 1]) pos++;
        F[i] = pos;
    }
}
void match(char *_find, char *content){
    int findLen = strlen(_find);
    for (int i = 0, pos = -1; content[i] ; i++){
        while (~pos && content[i] != _find[pos + 1]) pos = F[pos];
        if (content[i] == _find[pos + 1]) pos++;
        if (pos + 1 == findLen) return true;
    }
    return false;
}
int main() {
    int 
}
