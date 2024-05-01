#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
/*
	행맨게임(단어 스펠링 맞추기 게임)
        1. 시스템이 정답 단어 한 개를 선정
	2. 시스템이 정답 단어의 스펠링 수를 표시
        3. 사용자가 영어 스펠링 하나를 입력
	4. 정답 단어에 사용자가 입력한 스펠링이 있을 경우 -> 해당하는 모든 위치의 스펠링이 표시
                                             없을 경우 -> 남은 기회 차감(기본 8번 지급)
	5. 정답 단어의 스펠링을 모두 맞추면 승리
           남은 기회를 모두 소진하면 패배
	**** 사용자가 스펠링을 한 개를 입력하지 않은 경우 남은 기회가 차감된다.
        **** 리플릿으로 실행 시 오류가 없으나 dev c++ 사용 시 오류가 생길 수 있음.                                 
*/
int main(){
	// 정답 단어 리스트 (4 ~ 7글자 15개씩 총 60개)
	char* arr[] = {"love", "rock", "fish", "bird", 
	"bear", "jump", "sand", "cake", "tree", "rain", "baby", 
	"duck", "cold", "kite", "book", "house", "smile", "plant", 
	"drink", "apple", "dance", "earth", "cloud", "chair", "ghost", 
	"happy", "tiger", "grape", "bread", "ocean", "garden", "yellow", 
	"banana", "circle", "pillow", "window", "forest", "purple", "friend", 
	"cherry", "flower", "orange", "turtle", "pencil", "rocket", "penguin", 
	"bicycle", "weather", "library", "diamond", "kitchen", "chicken", "journey", 
	"lantern", "present", "rainbow", "monitor", "concert", "pumpkin", "dolphin"};
	srand(time(NULL)); // 난수 시드 값 지정
	int num = rand() % 60; // 0~59 중 랜덤한 값 생성
	int letter; // 글자 수
	int correct = 0; // 알파벳이 정답 문자에 포함하는지 여부
	int left = 8; // 남은 기회의 기본값
	char in; // 사용자가 입력한 알파벳
	
	letter = strlen(arr[num]); // 랜덤한 요소의 글자 수 대입
	char hint[letter + 1]; // 현재까지 맞춘 알파벳 문자 현황
	for(int i = 0; i < letter; i++){ // 게임 초기에 빈칸(_)으로 초기화
		hint[i] = '_'; 
	}
	hint[letter + 1] = '\0';
	for(int i = 0; i < left ; i++){ // 남은 기회만큼 반복
		printf("left : %d\n", left - i); // 남은 기회 표시
		printf("%s\n", hint); // 현재 현황을 표시
		printf("enter 1 letter : "); 
		scanf(" %c", &in); // 사용자의 알파벳 입력
		for(int j = 0; j < letter; j++){
			if(in == arr[num][j]){ // 입력한 값이 정답 문자에 포함 될 경우 
				hint[j] = in; // 현재 현황에 추가
				correct = 1; // 알파벳이 정답 문자에 포함됨
			}
		}
		if(correct){ // 알파벳이 정답 문자에 포함됐을 경우
			correct = 0; // 초기값으로 초기화
			left++; // 남은 기회 유지
		}
		if(strcmp(hint, arr[num]) == 0){ // 현재 현황이 정답 문자와 동일한 경우 
			printf("%s\n", arr[num]); // 정답 표시
			printf("You win!\n"); // 승리 표시
			exit(0); // 프로그램 종료 
		}
	}
	// 남은 기회를 모두 소진 했을 경우
	printf("answer : %s\n", arr[num]); // 정답 표시
	printf("You lose.."); // 패배 표시
}
