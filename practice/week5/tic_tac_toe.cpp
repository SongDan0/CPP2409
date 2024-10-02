#include <iostream>
using namespace std;

//왼쪽 아래부터 0,0으로 하기 위해 for문의 조건식과 board배열의 인덱스를 많이 수정했습니다.
int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; //사용자에게 입력받는 x, y 좌표를 저장할 변수

    //보드판 초기화
    for(x = 0; x < numCell; x++){
        for(y = 0; y < numCell; y++)
            board[y][x] = ' ';
    }

    //게임하는 코드
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; //현재 유저의 돌을 저장하기 위한 문자 변수
    cout << "좌표는 왼쪽 아래에서부터 0 0입니다.(x, y좌표를 띄어쓰기로 구분하여 입력해주세요.)" << endl;
    while(true){
        //1. 누구 차례인지 출력
        switch(k % 2){
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
        }

        //2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        //3. 입력받은 좌표의 유효성 체크
        if(x >= numCell || y >= numCell){
            cout << x << ", " << y << ": ";
            cout << " x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if(board[y][x] != ' '){
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        //4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[y][x] = currentUser;

        //5. 현재 보드 판 출력
        for(int i = numCell - 1 ; i >= 0; i--){
            for(int j = 0; j < numCell; j++){
                cout << board[i][j];
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;
        cout << endl;

        //6.빙고 시 승자 출력 후 종료(현재 놓은 돌 위치 기준 비교)
        if(k >= 4){     //빙고는 5개의 돌이 놓인 후부터 가능
            //6-1. 가로
            if(board[y][0] == board[y][1] && board[y][0] == board[y][2]){
                switch(k % 2){
                    case 0:
                        cout << "첫번째 유저 빙고!";
                        return 0;
                    case 1:
                        cout << "두번째 유저 빙고!";
                        return 0;
                }
            }
            
            //6-2. 세로
            if(board[0][x] == board[1][x] && board[0][x] == board[2][x]){
                switch(k % 2){
                    case 0:
                        cout << "첫번째 유저 빙고!";
                        return 0;
                    case 1:
                        cout << "두번째 유저 빙고!";
                        return 0;
                }
            }
            
            //6-3. 대각선
            if((x + y) % 2 == 0) {
                if(board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
                    switch(k % 2){
                        case 0:
                            cout << "첫번째 유저 빙고!";
                            return 0;
                        case 1:
                            cout << "두번째 유저 빙고!";
                            return 0;
                    }
                }
                if(board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
                    switch(k % 2){
                        case 0:
                            cout << "첫번째 유저 빙고!";
                            return 0;
                        case 1:
                            cout << "두번째 유저 빙고!";
                            return 0;
                    }
                }
            } 

            //6-4. 모든 칸이 찼을 경우
            if(k == 8){
                cout << "모든 칸이 찼습니다.";
                return 0;
            }
        }
        k++;
    }
    return 0;
}