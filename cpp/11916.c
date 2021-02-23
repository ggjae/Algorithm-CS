#include <iostream>
#include <vector>
bool base[3] = false;
int n;
int count = 0;
int ballcount = 0;
void taza(){
    base[0] = true;
}
void jinru(){
    if(base[0] == true){
        base[1] = true;
        if(base[1] == true){
            base[2] = true;
            if(base[2] == true){
                count++;
            } 
        }
    } else {
        if(base[1] == true){
            base[2] = true;
            if(base[2] == true){
                count++;
            }
        } else {
            if(base[2] == true){
                count++;
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            ballcount++;
            if(ballcount == 4){
                ballcount = 0;
                jinru();
                taza();  
            }
        } else if(tmp == 2){
            ballcount = 0;
            jinru();
            taza();
        } else {
            ballcount++;
            jinru();
            if(ballcount == 4){
                ballcount = 0;
                taza();
            } 
            
        }
        
    }
    return 0;
}