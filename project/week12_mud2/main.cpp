#include <string>
#include <vector>
#include "user.h"

const int MAP_X = 5;
const int MAP_Y = 5;

// 사용자 정의 함수
void DisplayMap(vector<vector<int>> map, int magician_x, int magician_y, int warrior_x, int warrior_y);
bool CheckXY(int user_x, int user_y, User* user);
bool CheckGoal(vector<vector<int>> map, int user_x, int user_y);
void CheckState(vector<vector<int>> map, int user_x, int user_y, User* user);
bool CheckUser(const int hp);
void PrintCurrentUser(int count);

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


    int count = 0;				// 턴 계산 사용할 카운터 변수
    Magician user_magician{}; 	// magician 유저의 객체 생성(체력 = 20 시작)
	Warrior user_warrior{}; 	// Warrior 유저의 객체 생성(체력 = 20 시작)
	
	// 게임 시작 
	while(1) {	// 사용자에게 계속 입력받기 위해 무한 루프
		// 턴 설정
		User *user;
		PrintCurrentUser(count);
		switch(count % 2) {
			case 0:
				user = &user_magician;
				break;
			case 1:
				user = &user_warrior;
				break;
		}

		// 사용자 입력
		string user_input = "";		// 사용자의 입력을 저장할 변수
		cout << "현재 HP: " << user->GetHP() << "  명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 이동
			user->user_y -= 1;
			if (CheckXY(user->user_x, user->user_y, user)) {
				cout << "위로 한 칸 올라갑니다." << endl;
				DisplayMap(map, user_magician.user_x, user_magician.user_y, user_warrior.user_x, user_warrior.user_y);
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
				DisplayMap(map, user_magician.user_x, user_magician.user_y, user_warrior.user_x, user_warrior.user_y);
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
				DisplayMap(map, user_magician.user_x, user_magician.user_y, user_warrior.user_x, user_warrior.user_y);
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
				DisplayMap(map, user_magician.user_x, user_magician.user_y, user_warrior.user_x, user_warrior.user_y);
			}
			else {
				user->user_x -= 1;
				continue;
			}
		}
		else if (user_input == "지도") {
			// 지도 출력
			DisplayMap(map, user_magician.user_x, user_magician.user_y, user_warrior.user_x, user_warrior.user_y);
			continue;
		}
		else if (user_input == "정보") {
			// 정보 출력
			switch(count % 2) {
			case 0:
				cout << user_magician << endl;
				break;
			case 1:
				cout << user_warrior << endl;
				break;
			}
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
			PrintCurrentUser(count);
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
        
        //무기/갑옷, 포션, 적 만났는지 체크
        CheckState(map, user->user_x, user->user_y, user);

        //체력이 다 떨어졌는지 체크
		if(CheckUser(user->GetHP())) {
        	PrintCurrentUser(count);
			cout << "체력을 모두 소모하여 실패했습니다." << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 턴 증가
		count++;
	}
	return 0;
}


// 지도와 사용자 위치 출력하는 함수
void DisplayMap(vector<vector<int>> map, int magician_x, int magician_y, int warrior_x, int warrior_y) {
	// 두 유저가 같은 위치에 있는지 체크
	bool is_same_position = false;
	if(magician_x == warrior_x && magician_y == warrior_y){
		is_same_position = true;
	}
	 
	// 지도 출력
	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			if(is_same_position && j == magician_x && i == magician_y) {
				cout << " M  W |"; // 양 옆 1칸 공백
			}else if(!is_same_position && j == magician_x && i == magician_y) {
				cout << "  M   |"; // 양 옆 1칸 공백
			}else if(!is_same_position && j == warrior_x && i == warrior_y) {
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

// 현재 유저 출력
void PrintCurrentUser(int count) {
	switch(count % 2) {
				case 0:
					cout << "#magician 유저#" << endl;;
					break;
				case 1:
					cout << "#worrior 유저#" << endl;;
					break;
			}
}