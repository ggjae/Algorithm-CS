#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
  vector<int> answer(enter.size());
  set<int> room;
  map<int, int> guest;
  
  int lidx = 0;
  for(int i=0; i<enter.size(); i++){
    for(auto guestIter=guest.begin(); guestIter!=guest.end(); guestIter++){
      guestIter->second += 1;
    }
    
    guest[enter[i]] = room.size();
    room.insert(enter[i]);
    while(true){
      auto leaveTarget = room.find(leave[lidx]);
      if(leaveTarget == room.end() || lidx >= leave.size()) break;
      room.erase(leaveTarget);
      answer[leave[lidx]-1] = guest[leave[lidx]];
      lidx++;
    }
  }
  return answer;
}