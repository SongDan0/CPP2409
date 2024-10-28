#include <iostream>
#include <string>
using namespace std;
//사용자 정의 메소드
bool checkNumber(int first, int second, int third);

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성
		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// randomNum(3자리 숫자) 자릿수를 추출
		firstNum = randomNum / 100;
		secondNum = randomNum % 100 / 10;
		thirdNum = randomNum % 10;

        // 각 자리수가 모두 다른지 체크
        same = checkNumber(firstNum, secondNum, thirdNum);
		if (same == true) {
			break;
		}
	}
    
	int turn = 0; //턴 저장 변수
	while (1) {
		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수

        //턴 출력
		cout << turn + 1 << "번째 시도입니다. " << endl;

		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

            //userNumber(3자리 숫자) 입력 받기
            cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

            //userNumber이 3자리 숫자인지 체크
            if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

            // randomNum(3자리 숫자) 자릿수를 추출
		    guessFirst = userNumber / 100;
		    guessSecond = userNumber % 100 / 10;
		    guessThird = userNumber % 10;
			
            // 각 자리수가 모두 다른지 체크
            same = checkNumber(guessFirst, guessSecond, guessThird);
		    if (same == true) {
			    break;
		    }
		}

		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수

        //순차적으로 strick와 ball 체크
        if(firstNum == guessFirst)
            strike++;
        else if(firstNum == guessSecond || firstNum == guessThird)
            ball++;
        if(secondNum == guessSecond)
            strike++;
        else if(secondNum == guessFirst || secondNum == guessThird)
            ball++;
        if(thirdNum == guessThird)
            strike++;
        else if(thirdNum == guessFirst || thirdNum == guessSecond)
            ball++;

        //strick와 ball 체크
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
        //정답 시 종료
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

        //턴 증가
		turn += 1;
	}

	return 0;
}

//각 자리수가 다른지 체크하는 메소드
bool checkNumber(int first, int second, int third) {
    if(first != second && first != third && second != third)
        return true;
    else
        return false;
}