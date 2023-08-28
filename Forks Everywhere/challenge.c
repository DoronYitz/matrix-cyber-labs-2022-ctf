int main(void)

{
  size_t input_len;
  long in_FS_OFFSET;
  int local_ec;
  uint xor_res;
  uint input_len_fixed;
  __pid_t child_pid;
  uint xor_res_fixed;
  uint add_result;
  uint multiply_result;
  uint and_result;
  uint xor_result;
  uint static_arr [35];
  byte input_array [33]; // Input should be overflowed to 35 
  char exclaimation_mark; // !
  byte overflow_byte; // } 
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  static_arr[0] = 0x4d; // 77
  static_arr[1] = 8;    // 8
  static_arr[2] = 0xc6; // 198
  static_arr[3] = 0x48; // 72
  static_arr[4] = 0xd7; // 215
  static_arr[5] = 0xa3; // 163
  static_arr[6] = 0xff; // 255
  
  static_arr[7] = 0x7f; // 127
  static_arr[8] = 0x56; // 86
  static_arr[9] = 0x7a; // 122
  static_arr[10] = 0xb2; // 178
  static_arr[11] = 0x14; // 20
  static_arr[12] = 0x34; // 52
  static_arr[13] = 0x71; // 113
  static_arr[14] = 0xd4; // 212
  static_arr[15] = 0xe4; // 228
  static_arr[16] = 0x21; // 33
  static_arr[17] = 0xcf; // 207
  static_arr[18] = 0xc0; // 192
  static_arr[19] = 0xf9; // 249
  static_arr[20] = 0xab; // 171
  static_arr[21] = 0x8b; // 139
  static_arr[22] = 2;    // 2
  static_arr[23] = 2;    // 2
  static_arr[24] = 0x31; // 49
  static_arr[25] = 0xcf; // 207
  static_arr[26] = 0x2f; // 47
  static_arr[27] = 0x28; // 40
  static_arr[28] = 0x56; // 86
  static_arr[29] = 0xb0; // 176
  static_arr[30] = 0x67; // 103
  static_arr[31] = 0x3f; // 63
  static_arr[32] = 0x5f; // 95 
  static_arr[33] = 0x53; // 83
  static_arr[34] = 0x7d; // 125
  xor_res = 0;           // 0 
  puts("You have something for me ?");
  __isoc99_scanf(&DAT_00102020,input_array); // Scanf %s
  input_len = strlen((char *)input_array);
  input_len_fixed = (uint)input_len & 0xfd; // 253 limit to 253 length
  while( true ) {
    if ((int)input_len_fixed < 1) {
      //    xor_res == 49              // }           // M        // 48 
      if (((xor_res == 0x31) && ((overflow_byte ^ input_array[0]) == 0x30)) && (exclaimation_mark == '!')) {
        puts("Congrats!");
      }
      else {
        puts("Wrong input.");
      }
      if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return 0;
    }
    child_pid = fork();
    if (child_pid == 0) {
      add_result = (int)(char)input_array[(int)(input_len_fixed + 1)] +
                 (int)(char)input_array[(int)(input_len_fixed - 1)] + (int)(char)input_array[(int)input_len_fixed];
      multiply_result = (int)(char)input_array[(int)(input_len_fixed + 1)] *
                 (int)(char)input_array[(int)(input_len_fixed - 1)] * (int)(char)input_array[(int)input_len_fixed];
      and_result = (uint)(char)(input_array[(int)(input_len_fixed + 1)] &
                             input_array[(int)(input_len_fixed - 1)] & input_array[(int)input_len_fixed]);
      xor_result = add_result ^ multiply_result ^ and_result;
                    /* WARNING: Subroutine does not return */
      exit(xor_result);
    }
    waitpid(child_pid,&local_ec,0);
    xor_res_fixed = local_ec >> 8 & 0xff; // 255
    if (xor_res_fixed != static_arr[(int)input_len_fixed]) break;
    xor_res = xor_res ^ xor_res_fixed;
    input_len_fixed = input_len_fixed - 1;
  }
  puts("Wrong input.");
                    /* WARNING: Subroutine does not return */
  exit(1);
}