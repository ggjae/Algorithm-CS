#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int main(){
    int t;
    vector<string> number;
    cin >> t;
    for(int i=0;i<t;i++){
        int flag = 0;
        int n;
        cin >> n;
        for(int j=0;j<n;j++){
            string a;
            cin >> a;
            number.push_back(a);
        }
        sort(number.begin(),number.end());
        
        for(int p=0;p<n;p++){
            string c = number[p];
            for(int q=p+1;q<n;q++){
                if(c == number[q].substr(0,c.size())){
                    flag = 1;
                }
            }
        }
        if (flag == 1){
            printf("NO");
        } else {
            printf("YES");
        }
    }
    return 0;
}