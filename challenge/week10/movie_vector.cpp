#include <vector>
#include <iostream>
using namespace std;

//영화의 정보를 저장하는 구조체
class Movie {
private:
    string title;   //영화 이름
    float rating;   //평점
public:
    //생성자
    Movie(string title_i = "", float rating_i = 0) {
        title = title_i;
        rating = rating_i;
    }

    //출력 메소드
    void print_movie() {
        cout << title << ": " << rating<< endl;
    }
    
    string getTitle() {return title;}                   //타이틀 반환 메소드
    float getRating() {return rating;}                   //평점 반환 메소드
    void setTitle(string title_i){title = title_i;}      //타이틀 설정 메소드
    void setRating(float rating_i){rating = rating_i;}   //평점 설정 메소드
};

int main() {
    vector<Movie> movie;     //영화 정보 동적 벡터
    
    //영화 정보 추가
    movie.push_back(Movie{"titinic", 9.9});
    movie.push_back(Movie{"gone with the wind", 9.6});
    movie.push_back(Movie{"terminator", 9.7});
    
    //영화 정보 출력
    for(Movie m: movie) {
        m.print_movie();
    }
}