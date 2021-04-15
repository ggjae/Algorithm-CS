#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
 
using namespace std;
 
int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
 
 
    vector<string> v;
    vector<string> v_result;
 
    //입력1
    //push_back을 사용하면 2^n제곱으로 메모리(capacity)를 잡습니다.
    //하지만 resize를 이용하면 미리 메모리를 할당하여, 속도를 줄이고 v[i]를 이용하여 입력을 받을 수 있습니다.
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];    //빠르게 받기위해 push_back이 아닌 배열처럼 받음
    }
 
    //오름차순으로 정렬
    sort(v.begin(), v.end());
 
    //입력2
    string str;
    for(int j=0; j<m; j++){
        cin >> str;
 
        if(binary_search(v.begin(), v.end(), str)){ //중복값 존재하면 v_result에 삽입
            v_result.push_back(str);
        }
    }
 
    //정렬
    sort(v_result.begin(), v_result.end());
 
    //출력
    printf("%d\n", (int)v_result.size());
    for(int i=0; i<v_result.size(); i++){
        printf("%s\n", v_result[i].c_str());
    }
 
    return 0;
}
