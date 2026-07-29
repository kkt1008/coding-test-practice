#include "a.h"
#include<stdio.h>

int main(void) {

    FILE* dummy_file = fopen("dummy_log.txt", "a");

    if (dummy_file == NULL) {
        printf("파일을 생성하거나 열 수 없습니다.\n");
        return 1;
    }

    // 2. 에러 조건 없이 실행 시 무조건 더미 데이터 기록
    fprintf(dummy_file, "[DUMMY LOG] 파일명: %s | 줄번호: %d | 빌드날짜: %s | 빌드시간: %s\n",
        __FILE__, __LINE__, __DATE__, __TIME__);

    // 3. 파일 닫기
    fclose(dummy_file);

    printf("dummy_log.txt 파일에 더미 데이터가 정상적으로 기록되었습니다.\n");

    // ----------------------------------------------------
   // 사례 2: 일반 변수에 값 대입하기
   // ----------------------------------------------------
   // __FILE__은 문자열이므로 char 포인터 변수에 주소를 대입합니다.
    const char* target_file = __FILE__;

    // __LINE__은 정수이므로 int형 변수에 값을 대입합니다.
    int current_line = __LINE__;


    // ----------------------------------------------------
    // 사례 3: 문자열 자동 합치기 (컴파일 타임 결합)
    // ----------------------------------------------------
    // C언어는 "문자열1" "문자열2"를 나란히 쓰면 하나의 문자열로 합쳐집니다.
    // 컴파일 시점에 "Error occurred in " + "main.c"로 결합되어 메모리에 들어갑니다.
    const char* error_message = "Error occurred in " __FILE__;

    // 빌드 정보 메시지도 미리 결합하여 만들 수 있습니다.
    const char* build_info = "Build Version 1.0 \
        (Date: " __DATE__ " ,Time: " __TIME__ ")";


    // ----------------------------------------------------
    // 변수에 저장된 값들을 활용하는 부분 (출력 또는 가공)
    // ----------------------------------------------------
    printf("--- 대입된 변수 확인 ---\n");
    printf("저장된 파일명: %s\n", target_file);
    printf("저장된 줄번호: %d\n\n", current_line);

    printf("--- 자동 합쳐진 문자열 확인 ---\n");
    printf("결합된 메시지: %s\n", error_message);
    printf("결합된 빌드정보: %s\n", build_info);


    return 0;
}
