#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 300;
char str[MAXN][260], ans[260];
int nFiles, len;
bool vis[MAXN], flag;
map<string, bool>mp;
int cmp(const void *a, const void *b) {
    int l1 = strlen((char *)a);
    int l2 = strlen((char *)b);
    if (l1 != l2) {
        return l1 - l2;
    } else {
        return strcmp((char *)a, (char *)b);
    }
}
void init_input() {
    nFiles = 0;
    int minLength = 1000, maxLength = -1000;
    while (gets(str[nFiles])) {
        if (! str[nFiles][0]) break;
        int l = strlen(str[nFiles]);
        if (l > maxLength) maxLength = l;
        if (l < minLength) minLength = l;
        nFiles ++;
    }
    len = minLength + maxLength;
}
void ssearch(int cnt, char *file) {
    if (flag) return;
    if (cnt == nFiles / 2) {
        strcpy(ans, file);
        flag = true;
        return;
    }
    for (int i = 0; i < nFiles / 2; i ++) {
        if (! vis[i]) {
            vis[i] = true;
            if (cnt == 0) {
                for (int j = nFiles - 1; j >= nFiles / 2; j --) {
                    if (! vis[j]) {
                        int l = strlen(str[i]) + strlen(str[j]);
                        if (l < len) return;
                        if (l > len) continue;
                        char temp1[MAXN];
                        strcpy(temp1, str[i]);
                        strcat(temp1, str[j]);
                        if (! mp[temp1]) {
                            mp[temp1] = true;
                            vis[j] = true;
                            ssearch(cnt + 1, temp1);
                        }
                        char temp2[MAXN];
                        strcpy(temp2, str[j]);
                        strcat(temp2, str[i]);
                        if (strcmp(temp1, temp2) == 0) continue;
                        if (! mp[temp2]) {
                            mp[temp2] = true;
                            vis[j] = true;
                            ssearch(cnt + 1, temp2);
                        }
                        vis[j] = false;
                    }
                }
            } else {
                for (int j = nFiles - 1; j >= nFiles / 2; j --) {
                    if (! vis[j]) {
                        int l = strlen(str[i]) + strlen(str[j]);
                        if (l < len) return;
                        if (l > len) continue;
                        char temp1[MAXN];
                        strcpy(temp1, str[i]);
                        strcat(temp1, str[j]);
                        if (strcmp(temp1, file) == 0) {
                            vis[j] = true;
                            ssearch(cnt + 1, temp1);
                        }
                        char temp2[MAXN];
                        strcpy(temp2, str[j]);
                        strcat(temp2, str[i]);
                        if (strcmp(temp2, temp1) != 0) {
                            vis[j] = true;
                            ssearch(cnt + 1, temp2);
                        }
                        vis[j] = false;
                    }
                }
            }
            vis[i] = false;
        }
    }
}
int main() {
    int T;
    scanf("%d%*c", &T);
    gets(str[0]);
    while (T --) {
        init_input();
        qsort(str, nFiles, sizeof(str[0]), cmp);
        memset(vis, false, sizeof(vis));
        mp.clear();
        char t[10]="abc";
        flag = false;
        if (nFiles > 2) {
            ssearch(0, t);
        } else {
            strcpy(ans, str[0]);
            strcat(ans, str[1]);
        }
        puts(ans);
        if (T) {
            printf("\n");
        }
    }
    return 0;
}
