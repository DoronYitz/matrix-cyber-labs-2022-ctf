undefined8 main(void)

{
  int __fd;
  int iVar1;
  FILE *__stream;
  long in_FS_OFFSET;
  undefined local_48 [4];
  undefined local_44 [17];
  undefined8 local_33;
  undefined2 local_2b;
  undefined local_29;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_33 = 0x33332e312e373231;
  local_2b = 0x372e;
  local_29 = 0;
  __stream = fopen("flag.txt","r");
  _isoc99_fscanf(_stream,&DAT_00102013,&local_28);
  fclose(__stream);
  local_48.0_2 = 2;
  local_48.2_2 = htons(5000);
  __fd = socket(2,1,0);
  if (__fd < 0) {
    puts("\n Socket creation error ");
  }
  else {
    iVar1 = inet_pton(2,(char *)&local_33,local_44);
    if (0 < iVar1) {
      bind(__fd,(sockaddr *)local_48,0x10);
      do {
        listen(__fd,1);
        iVar1 = accept(__fd,(sockaddr *)0x0,(socklen_t *)0x0);
        send(iVar1,&local_28,0x14,0);
      } while( true );
    }
    puts("\nInvalid address/ Address not supported ");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}