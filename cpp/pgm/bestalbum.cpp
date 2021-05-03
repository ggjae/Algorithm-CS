#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool cmp(pair<int,int> v1,pair<int,int> v2)
{
    if(v1.first > v2.first) return true;
    else if(v1.first == v2.first){
        return v1.second < v2.second;
    }
    return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> genre;
    vector<string> list;
    for(int i=0; i<genres.size(); i++){ //장르별 노래 재생횟수의 합
        if(genre[genres[i]] == 0){
            genre[genres[i]] += plays[i];
            list.push_back(genres[i]);
        }
        else
            genre[genres[i]] += plays[i];
    }

    int first = 0; string first_name;
    for(int i=0; i<list.size(); i++){
        if(genre[list[i]] > first){
            first = genre[list[i]];
            first_name = list[i];
        }
    } //가장 많이 들은 장르 알아내기
    genre[first_name] = 0; //가장 많이 들은 장르 배제
    int second = 0; string second_name;
    for(int i=0; i<list.size(); i++){
        if(genre[list[i]] > second){
            second = genre[list[i]];
            second_name = list[i];
        }
    } //두번째로 많이 들은 장르 알아내기
    vector<pair<int,int>> first_genre; //가장 많이 들은 장르의 index별 들은 횟수 저장
    vector<pair<int,int>> second_genre; //두번째로 많이 들은 장르의 index별 들은 횟수 저장

    int first_count = 0; int second_count = 0;
    for(int i=0; i<genres.size(); i++){
        if(genres[i] == first_name) {first_genre.push_back(make_pair(plays[i],i));
                                    first_count++;}
        if(genres[i] == second_name) {second_genre.push_back(make_pair(plays[i],i));
                second_count++;}
    }
    sort(first_genre.begin(),first_genre.end(),cmp);
    sort(second_genre.begin(),second_genre.end(),cmp);

    for(int i=0; i<first_genre.size(); i++){
        if(i == 2) break;
        answer.push_back(first_genre[i].second);
    }
    for(int i=0; i<second_genre.size(); i++){
        if(i == 2) break;
        answer.push_back(second_genre[i].second);
    }
    return answer;
}