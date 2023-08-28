#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Printable chars
char arr_letters[93]={
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
  'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
  'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
  'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
  'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '"', '#', '$',
  '%', '&', '"', '(', ')', '*', '+', ',', '-', '.', '/',
  ':', ';', '<', '=', '>', '?', '@', '[', ']', '^', '_',
  '`', '{', '|', '}', '~'
};
int arr[35];

// Calc letter based on +1 and -1 on flag arr
int calc(char a,char b,char c){
    int fork_status=fork();
    if(fork_status==0){
          
        uint local_d8 = (int)(char)a + (int)(char)c + (int)(char)b;
                     
        uint local_d4 = (int)(char)a * (int)(char)c * (int)(char)b;
                     
        uint local_d0 = (uint)(char)(a & c & b);
                                 
        uint local_cc = local_d8 ^ local_d4 ^ local_d0;
        exit(local_cc);
    }
    int child_result=0;
    waitpid(fork_status,&child_result,0);
    int result=(child_result >> 8) & 0xff;
    return result;
}


int main()
{
    arr[0] = 0x4d;
    arr[1] = 8;
    arr[2] = 0xc6;
    arr[3] = 0x48;
    arr[4] = 0xd7;
    arr[5] = 0xa3;
    arr[6] = 0xff;
    arr[7] = 0x7f;
    arr[8] = 0x56;
    arr[9] = 0x7a;
    arr[10] = 0xb2;
    arr[11] = 0x14;
    arr[12] = 0x34;
    arr[13] = 0x71;
    arr[14] = 0xd4;
    arr[15] = 0xe4;
    arr[16] = 0x21;
    arr[17] = 0xcf;
    arr[18] = 0xc0;
    arr[19] = 0xf9;
    arr[20] = 0xab;
    arr[21] = 0x8b;
    arr[22] = 2;
    arr[23] = 2;
    arr[24] = 0x31;
    arr[25] = 0xcf;
    arr[26] = 0x2f;
    arr[27] = 0x28;
    arr[28] = 0x56;
    arr[29] = 0xb0;
    arr[30] = 0x67;
    arr[31] = 0x3f;
    arr[32] = 0x5f;
    arr[33] = 0x53;
    arr[34] = 0x7d;


    #define SIZE 33
    
    char flag[SIZE]={'M','C','L','{','m','a','Y','','7','h','3','','F','o','r','k',
    '','w','1','l','L','','8','3','','w','1','7','h','','Y','O','U'};

    uint index= SIZE-1;
    
    // MCL{maY_7h3_Fork_w1lL_83_w17h_YOU!}
    
    for(int i=0;i<93;i++){
        int result=calc(flag[index],flag[index-1],arr_letters[i]);
        if(result == arr[index]){
            printf("%c\n",arr_letters[i]);
        }
    }

    return 0;
}