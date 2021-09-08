#include <iostream>
#include <string.h>
using namespace std;
int main(){
    string doc;
    string search;
    bool flag = false;
    int cnt = 0;
    getline(cin,doc);
    getline(cin,search);
    for(int i=0;i<doc.length();){
        for(int j=0;j<search.length();){
            // cout << "i: " << i << "j: " << j;
            if(search[j++] == doc[i++]){
                flag = true;
            } else {
                flag = false;
                i -= j;
                break;
            }
        }
        if(flag == true){
            flag = false;
            // cout << i << endl;
            cnt++;
        } else{
            i++;
        }
    }
    cout << cnt;
    return 0;
}