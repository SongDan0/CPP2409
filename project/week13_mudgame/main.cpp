#include <string>
#include <vector>
#include "user.h"

const int MAP_X = 5;
const int MAP_Y = 5;

// 사용자 정의 함수
void DisplayMap(vector<vector<int>> map, int user_x, int user_y, int job);
bool CheckXY(int user_x, int user_y, User* user);
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y);
void CheckState(vector<vector<int>> map, int user_x, int user_y, User* user);
bool CheckUser(const int hp);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };
	
	
	User *user;
	int job = 0;
	// 직업 선택
	while(1) {
		cout << "1. Magician  2. Warrior 중 직업을 선택해 주세요(숫자로 선택): ";
		cin	>> job;
		if(job == 1) {
			user = new Magician{};
			break;
		}
		else if(job == 2) {
			user = new Warrior{};
			break;
		}
		else
			cout << "잘못 입력하셨습니다. 다시 입력해주세요" << endl;
	}

	// 게임 시작 
	while(1) {	// 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자 입력
		string user_input = "";		// 사용자의 입력을 저장할 변수
		cout << "현재 HP: " << user->GetHP() << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 이동
			user->user_y -= 1;
			if (CheckXY(user->user_x, user->user_y, user)) {
				cout << "위로 한 칸 올라갑니다." << endl;
				DisplayMap(map, user->user_x, user->user_y, job);
			}
			else {
				user->user_y += 1;
				continue;
			}
		}
		else if (user_input == "하") {
			// 아래로 이동
			user->user_y += 1;
			if (CheckXY(user->user_x, user->user_y, user)) {
				cout << "아래로 한 칸 내려갑니다." << endl;
				DisplayMap(map, user->user_x, user->user_y, job);
			}
			else {
				user->user_y -= 1;
				continue;
			}
		}
		else if (user_input == "좌") {
			// 왼쪽으로 이동
			user->user_x -= 1;
			if (CheckXY(user->user_x, user->user_y, user)) { 
				cout << "왼쪽으로 이동합니다." << endl;
				DisplayMap(map, user->user_x, user->user_y, job);
			}
			else {
				user->user_x += 1;
				continue;
			}
		}
		else if (user_input == "우") {
			// 오른쪽으로 이동
			user->user_x += 1;
			if (CheckXY(user->user_x, user->user_y, user)) { 
				cout << "오른쪽으로 이동합니다." << endl;
				DisplayMap(map, user->user_x, user->user_y, job);
			}
			else {
				user->user_x -= 1;
				continue;
			}
		}
		else if (user_input == "지도") {
			// 지도 출력
			DisplayMap(map, user->user_x, user->user_y, job);
			continue;
		}
		else if (user_input == "정보") {
			// 정보 출력
			cout << user << endl;
			continue;
		}
		else if (user_input == "공격") {
			// 정보 출력
			user->DoAttack();
			continue;
		}
		else if (user_input == "종료") {
			// 종료
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		if (CheckGoal(map, user->user_x, user->user_y)) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
        
        //무기/갑옷, 포션, 적 만났는지 체크
        CheckState(map, user->user_x, user->user_y, user);

        //체력이 다 떨어졌는지 체크
		if(CheckUser(user->GetHP())) {
			cout << "체력을 모두 소모하여 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void DisplayMap(vector<vector<int>> map, int user_x, int user_y, int job) {
	// 지도 출력
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			if(job == 1 && j == user_x && i == user_y) {
				cout << "  M   |"; // 양 옆 1칸 공백
			}else if(job == 2 && j == user_x && i == user_y) {
				cout << "  W   |"; // 양 옆 1칸 공백
			}else {
				int pos_state = map[i][j];
				switch (pos_state) {
					case 0:
						cout << "      |"; // 6칸 공백
						break;
					case 1:
						cout << "아이템|";
						break;
					case 2:
						cout << "  적  |"; // 양 옆 2칸 공백
						break;
					case 3:
						cout << " 포션 |"; // 양 옆 1칸 공백
						break;
					case 4:
						cout << "목적지|";
						break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool CheckXY(int user_x, int user_y, User* user) {
	// 유효할 경우
	if (0 <= user_x && user_x < MAP_X && 0 <= user_y && user_y < MAP_Y) {
		user->DecreaseHP(1);
		return true;
	}
	cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
	return false;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y) {
	// 목적지 도착했을 경우
	if (map[user_y][user_x] == 4)
		return true;
	return false;
}

// 유저가 아이템, 포션, 적을 만났는지 체크하는 함수
void CheckState(vector<vector<int>> map, int user_x, int user_y, User* user) {
    switch(map[user_y][user_x]){
        case 1:
            cout << "아이템이 있습니다." << endl;
			user->IncreaseItemCnt();
            break;
        case 2:
            cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
            user->DecreaseHP(2);
            break;
		case 3:
            cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
            user->IncreaseHP(2);
            break;
        }
}

// user의 hp가 0인지 체크하는 함수
bool CheckUser(const int hp) {
    // hp가 0이 된 경우
	if(hp <= 0)
        return true;
    return false;
}