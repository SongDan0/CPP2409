#include <iostream>
using namespace std;
//사용자 정의 함수
bool isValid(char** board_p, int numCell, int x, int y);
bool checkWin(char** board_p, int numCell, char currentUser);

int main() {
	// 게임을 진행하는 데 필요한 변수 선언
	int numCell = 3; // 보드판의 가로 세로 길이
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	int x = 0, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수
	
	// 보드판 크기 입력 받기
	cout << "n x n 보드판의 크기n을 입력해주세요.: ";
	cin >> numCell;

	// 보드판을 나타내는 2차원 배열 선언
    char** board = (char**)malloc(numCell * sizeof(char*));
    for (int i = 0; i < numCell; ++i) 
        board[i] = (char*)malloc(numCell * sizeof(char));

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
			case 2:			
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		if(isValid(board ,numCell, x, y) == false)
            continue;

		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
			for(int k = 0; k < numCell - 1; k++)
				cout << "---|";
			cout << "---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1)
					break;
				cout << "  |";
			}
			cout << endl;
		}
		for(int k = 0; k < numCell - 1; k++)
			cout << "---|";
		cout << "---" << endl;

		// 6. 가로/세로/대각선 돌 체크하기
        if(checkWin(board, numCell, currentUser) == true) {
            cout << k % 3 + 1<< "번 유저(" << currentUser << ")의 승리입니다!" << endl;
			break;
        }

		// 7. 모든 칸 다 찼는지 체크하기
        if(k == numCell * numCell - 1) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++; //턴 증가
	}

	return 0;
}

//입력 받은 좌표의 유효성 체크 함수
bool isValid(char** board_p, int numCell, int x, int y) {
    if (x < 0 || x >= numCell || y < 0 || y >= numCell) {// 좌표 범위를 벗어날때
		cout << x << "," << y << ": x와 y둘중 하나가 칸을 벗어납니다. " << endl;
		return false;
	}
	if (board_p[x][y] != ' ') {// 좌표범위의 입력값이 중복될때
		cout << x << "," << y << ": 이미 돌이 차있습니다. " << endl;
		return false;
	}
    return true;
}

//승자 체크 함수
bool checkWin(char** board_p, int numCell, char currentUser) {
    bool isWidth[numCell]; //0~3행의 가로 체크(true일 시 승자 존재)
	bool isHeight[numCell]; //0~3행의 세로 체크(true일 시 승자 존재)
	bool isDiagonal1 = true; //왼쪽 위부터 오른쪽 아래까지의 대각선 체크(true일 시 승자 존재)
	bool isDiagonal2 = true; //오른쪽 위부터 왼쪽 아래까지의 대각선 체크(true일 시 승자 존재)
	// isWidth true로 초기화
	for(int i = 0; i < numCell; i++)
		isWidth[i] = true;
	// isHeight true로 초기화
	for(int i = 0; i < numCell; i++)
		isHeight[i] = true;		

	// 가로/세로 체크
	for(int i = 0; i < numCell; i++) {
		for(int j = 0; j < numCell; j++) {
			if(currentUser != board_p[i][j]){
				isWidth[i] = false;
				break;
			}
		}
		for(int j = 0; j < numCell; j++) {
			if(currentUser != board_p[j][i]){
				isHeight[i] = false;
				break;
			}
		}
	}
	//1번 대각선 체크
	for(int i = 0; i < numCell; i++) {
		if(currentUser != board_p[i][i]){
			isDiagonal1 = false;
			break;
		}
	}
	//2번 대각선 체크
	for(int i = 0; i < numCell; i++) {
		if(currentUser != board_p[i][numCell-1 - i]){
			isDiagonal2 = false;
			break;
		}
	}

	//체크된 값에 따라 문구 출력 및 true/false 반환
	for(int i = 0; i < numCell; i++) {
		if(isWidth[i]){
			cout << "가로에 모두 돌이 놓였습니다!!";
    			return true;
		}
		if(isHeight[i]){
			cout << "세로에 모두 돌이 놓였습니다!!";
    			return true;
		}
	}
	if(isDiagonal1){
		cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
    		return true;
	}
	if(isDiagonal2){
		cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
    		return true;
	}
	return false;
}
