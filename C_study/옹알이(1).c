#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
//각 문자열은 4가지 단어의 조합
#define WORD_NUM 4

int solution(const char* babbling[], size_t babbling_len) {//배열, 배열길이
    int answer = 0;
    const char *sound[WORD_NUM] = {"aya", "ye", "woo", "ma"};
    int sound_length[WORD_NUM]={3,2,3,2};
    
    for(int i=0;i<babbling_len;i++){//배열 전체 순회
        int pos=0;  //한 개의 단어 내에서의 위치
        int word_length=strlen(babbling[i]);   //배열 한개에서의 단어의 길이
        bool used[WORD_NUM]={false,};

        //단어 한개를 순회해서 겹치는게 있는지 탐색
        while(pos<word_length){//위치가 단어보다 작을때 탐색
            bool match=false; //단어가 겹치는지 확인

            for(int j=0;j<WORD_NUM;j++){ //4가지 단어 모두 확인
                if(used[j]){ //이미 사용한 단어면 continue
                    continue;
                }
                
                //남은 길이가 충분하고, 현재 위치부터 글자가 일치하는지 확인
                if(pos+sound_length[j]<=word_length &&
                   strncmp(babbling[i]+pos, sound[j], sound_length[j])==0){
                    match = true;
                    pos += sound_length[j];
                    used[j] = true;
                    break; //각 단어에서는 한번만 발음을 허용하므로 break
                }
            }
            if(!match) break; //하나도 일치하지 않으면 break
        }
        if(pos == word_length) answer++;
    }
    
    return answer;
}
