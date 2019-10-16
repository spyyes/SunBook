#include <iostream>
using namespace std;
int board[8][8];
int press[8][8];
bool check(){
    for(int i = 1; i < 5; i++)
        for(int j = 1; j < 7; j++){
            press[i + 1][j] = (press[i][j-1] + press[i][j+1] + press[i][j] + board[i][j])%2;
        }
    for(int j = 1; j < 7; j++){
        if(press[5][j] == 1){
            return false;
        }
    }
    return true;
}
int main(){
    memset(board, 0, sizeof(board));
    memset(press, 0, sizeof(press));
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 6; j++)
            cin>>board[i][j];
    
    for(int i1 = 0; i1 < 2; i1 ++)
		for (int i2 = 0; i2 < 2; i2++)
			for(int i3 = 0; i3 < 2; i3++)
				for (int i4 = 0; i4 < 2; i4++)
					for (int i5 = 0; i5 < 2; i5++)
						for (int i6 = 0; i6 < 2; i6++){
                            press[1][1] = i1;
                            press[1][2] = i2;
                            press[1][3] = i3;
                            press[1][4] = i4;
                            press[1][5] = i5;
                            press[1][6] = i6;
                            if(check()){
                                for(int i = 1; i <= 5; i++){
                                    for(int j = 1; j <= 6; j++)
                                        cout << press[i][j] << " ";
                                    cout <<endl;
                                }
                            }
                        }

}