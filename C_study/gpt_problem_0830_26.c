#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 소문자로 구성된 문자열에서 연속해서 나타나는 문자와 개수를 기록한 새로운 문자열을 동적 할당해 반환하라.
입력은 a~z와 널 문자로 구성된다.
반환 문자열은 호출자가 free()한다.
빈 문자열은 동적 할당된 빈 문자열로 반환한다.
할당 실패 또는 s == NULL이면 NULL을 반환한다.
| 입력           | 출력           |
| ------------- | ------------ |
| `"aabccccaa"` | `"a2b1c4a2"` |
| `"x"`         | `"x1"`       |
| `""`          | `""`         |
*/

 /*====접근 방법====*/
//현재 문자와 뒤쪽 문자와 같은지 확인
//같은 경우에는 한칸 뒤 문자 계속 비교
//문자열이 다를 경우 카운팅 중지. 
//문자열이 다른 위치로 i 값 변경

char *rle_encode(const char *s){//문자열 입력
    int string_len = strlen(s); //문자열 길이
    int input_idx=0;    //입력 문자열 idx
    int result_idx=0;   //정답 문자열 idx
    //char result[string_len*2+1]; //정답 문자열. 
    // 배열로 선언할 경우 함수가 종료되면 return하는 순간 해당 배열의 메모리 주소가 사라짐
    char *result = (char*)malloc(2*string_len+1);    //c에서는 malloc의 반환값이 void* 이고 자동으로 캐스팅된다. 
                                                     //cpp에서는 void*으로 자동 변환되지 않아서 캐스팅 필수
   
    while(input_idx<string_len){//i가 0,1,2... 순차적으로 증가하는 경우가 아님.
    //전체 문자열의 길이보다 작고 i값이 불규칙적으로 변경되므로 while이 적절
        char current = s[input_idx]; //현재 시작 문자
        int count=1; //연속되는 횟수. 문자 1개도 1개 연속으로 취급하기 때문
        while((input_idx+1<string_len) && (s[input_idx]==s[input_idx+1])){ //시작문자 바로 한칸 뒤부터 검사 시작
            count++;
            input_idx++;
        }
        result[result_idx++]=current;//문자 저장
        
        //숫자를 문자열 형태로 바꿔서 result 배열에 저장
        result_idx += sprintf(result+result_idx,"%d",count); //반환값: 실제 기록한 문자 수
        //result 배열에서 실제로 기록한 문자 수 만큼 인덱스 증가시켜줘야함
        input_idx++; // input_idx 위치 이동======> 제일 놓치기 쉬운 부분!!!
    }
    result[result_idx]='\0'; // 문자열 끝 명시
    return result;
}

int main(){
    char* test =rle_encode("aabccccaa");
    printf("%s\n",test);
    free(test);
    return 0;  
}
