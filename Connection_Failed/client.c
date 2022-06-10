undefined8 main(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  undefined local_58 [4];
  undefined local_54 [24];
  undefined8 local_3c;
  undefined2 local_34;
  undefined8 local_32;
  undefined2 local_2a;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_3c = 0x4f4e;
  local_34 = 0;
  local_32 = 0x2e302e302e373231;
  local_2a = 0x31;
  local_58.0_2 = 2;
  local_58.2_2 = htons(5000);
  puts("Do you want the flag ?");
  fflush(stdout);
  gets((char *)&local_3c);
  iVar1 = strcmp((char *)&local_3c,"YES");
  if (iVar1 == 0) {
    iVar1 = socket(2,1,0);
    if (iVar1 < 0) {
      puts("\n Socket creation error ");
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = inet_pton(2,(char *)&local_32,local_54);
      if (iVar2 < 1) {
        puts("\nInvalid address/ Address not supported ");
        uVar3 = 0xffffffff;
      }
      else {
        iVar2 = connect(iVar1,(sockaddr *)local_58,0x10);
        if (iVar2 < 0) {
          puts("\nConnection Failed ");
          puts("Maybe you missed something ?");
          uVar3 = 0xffffffff;
        }
        else {
          puts("Request flag from the server");
          send(iVar1,"Give me the flag !",0x14,0);
          puts("Server response");
          read(iVar1,local_28,0x14);
          puts(local_28);
          uVar3 = 0;
        }
      }
    }
  }
  else {
    puts("Seems like you dont want the flag");
    uVar3 = 0;
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}