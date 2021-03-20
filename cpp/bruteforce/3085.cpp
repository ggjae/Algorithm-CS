#include <iostream>
#include <vector>
using namespace std;
int mc = 0;
int n;
char board[51][51];
void horizon(){
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=0;j<n;j++){
            if(board[i][j] == board[i][j+1]){
                count++;
            } else {
                if(mc < count){
                    mc = count;
                }
                count = 1;
            }
        }
    }
}
void vertical(){
    for(int i=0;i<n;i++){
        int count = 1;
        for(int j=0;j<n;j++){
            if(board[j+1][i] == board[j][i]){
                count++;
            } else {
                if(mc < count){
                    mc = count;
                }
                count = 1;
            }
        }
    }
}
int main(){
    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){

            char tmp = board[i][j];
            board[i][j] = board[i][j+1];
            board[i][j+1] = tmp;

            vertical();
            horizon();

            tmp = board[i][j];
            board[i][j] = board[i][j+1];
            board[i][j+1] = tmp;
        }
    }
    for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n - 1; j++)
		{
			char tmp = board[j][i];	 
            board[j][i] = board[j+1][i];
			board[j+1][i] = tmp;
			vertical();		         
			horizon();
			tmp = board[j][i];		 
            board[j][i] = board[j+1][i];
			board[j+1][i] = tmp;
		}
	}
    cout << mc;
    return 0;
}