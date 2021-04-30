#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // vector<int> answer;
    // vector<pair<pair<string, int>, int> > v;
    // 
    // map<int, string>::iterator iter;
    // map<int, string> m; // 모든 장르는 재생된 횟수가 다르다는데?
    // // 오름차순 정렬이 자동으로 됨
    // for(int i=0;i<genres.size();i++){
    //     v.push_back(make_pair(make_pair(genres[i], plays[i]),0));
    // }
    // int sumplay = 0;
    // for(int i=0;i<v.size();i++){
    //     string nowgen = v[i].first.first;
    //     int play = v[i].first.second;
    //     sumplay += play;
    //     for(int j=i+1;j<v.size();j++){
    //         if(nowgen == v[j].first.first && v[j].second == 0){
    //             v[j].second = 1;
    //             sumplay += v[j].first.second;
    //         }
    //     }
    //     m.insert(make_pair(-sumplay,nowgen));
    // }
    vector<int> answer;
    map<string, int> mp;
    pair<int, int> arr[10001];
    map<string, int>::iterator it;
    for(int i=0; i<(int)genres.size(); i++){
        it = mp.find(genres[i]);
        if(it != mp.end()){
            int pre = it->second;
            mp[genres[i]] = pre+plays[i];
        }else{
            mp.insert({genres[i], plays[i]});
        }
    }
    map<int, string> rev;
    map<int, string>::iterator iter;
    for(it = mp.begin(); it != mp.end(); it++){
        rev.insert({-(it->second), it->first});
    }
    
    for(iter=rev.begin();iter!=rev.end();iter++){
        // printf("%s : %d\n",iter->second, -iter->first);
        string gen = iter->second;
        int idx = 0;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<(int)genres.size();i++){
            if(gen.compare(genres[i]) == 0){
                arr[idx++] = {-plays[i],i};
            }
        }
        sort(arr, arr+idx);
        if(idx == 1){
            answer.push_back(arr[0].second);
        } else {
            answer.push_back(arr[0].second);
            answer.push_back(arr[1].second);
        }
    }
    return answer;
}