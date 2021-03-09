#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool compare(const pair<pair<int, int>, int > &a, const pair<pair<int, int>, int > &b)
{
	if (a.first.first == b.first.first) {
		return a.first.second < b.first.second;
	}
	return a.first.first < b.first.first;
}
int main(){
    int n,c,m;
    vector<pair<pair<int,int> , int> > box;
    int ans = 0;
    int nowbox = 0;
    int truck[2001];
    int start,end,cap;
    memset(truck, 0, sizeof(truck));
    cin >> n >> c;
    cin >> m;
    for(int i=0;i<m;i++){
        int tmp1,tmp2,tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;
        box.push_back(make_pair(make_pair(tmp2,tmp1), tmp3)); // 받는거부터 골라놓음
    }
    sort(box.begin(),box.end(),compare);
    for(int i=0;i<m;++i){ // 생각한 알고리즘은 end가 빠른친구먼저 계산해주고 truck에
    // 탑승이 가능하다면 바로 태움. 그러고 내가 이걸 들고있던 때의 truck 값을
    // 늘려주면서 못태울수도있고 태울수도 있고 함.
        nowbox = 0;
        start = box[i].first.second;
        end = box[i].first.first;
        cap = box[i].second;
        for(int j=start;j<end;j++){
            // printf("truck[j] : %d\n",truck[j]);
            nowbox = max(nowbox, truck[j]);
            
        }
        nowbox = min(c-nowbox, cap);
        // printf("나우박스 : %d\n",nowbox);
        ans += nowbox;
        for(int j=start;j<end;j++){
            truck[j] += nowbox;
        }
        // printf("출발: %d, 도착 : %d, %d\n",box[i].first.second,box[i].first.first,box[i].second);
        // printf("-----현재상황 : nowbox : %d\n",nowbox);
        // if(box[i].first.second == i && nowbox < c){
        //     printf("1번 들어옴.\n");
        //     if(box[i].second + nowbox > c){
        //         box[i].second = box[i].second - (c - nowbox);
        //         nowbox = c;
        //     } else {
        //         nowbox += box[i].second;
        //     }
        // }
        // if(box[i].first.first == i) {
        //     printf("2번 들어옴.\n");
        //     nowbox -= box[i].second;
        //     ans += box[i].second;
        // }
    }
    printf("%d",ans);
    return 0;
}