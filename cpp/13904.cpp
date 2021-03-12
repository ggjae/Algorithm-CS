#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isuse[1001];
bool compare(pair<int,int> &a, pair<int, int> &b)
{
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first > b.first;
}
int main(){
    int n;
    vector<pair<int, int> > v;
    cin >> n;
    for(int i=0;i<n;i++){
        int d,w;
        cin >> d >> w;
        v.push_back(make_pair(w,d));
    }
    sort(v.begin(),v.end(),compare);
    int sum = 0;
    isuse[0] = true;
    for(int i=0;i<n;i++){
        int grade = v[i].first;
        int daytime = v[i].second;
        // printf("grade : %d, daytime : %d\n",grade,daytime);
        if(isuse[daytime] == false){
            isuse[daytime] = true;
            sum += grade;
            // printf("%d 만큼 추가됐음",grade);
            // printf("-------------------------\n");
        } else {
            while(daytime>0){
                // printf("못들어갔어-\n");
                daytime--;
                if(isuse[daytime] == false){
                    isuse[daytime] = true;
                    sum += grade;
                    break;
                }
            }
        }
    }
    cout << sum;
    // 값이 큰놈부터 마감일에다 넣고 생각할까..?
    return 0;
}