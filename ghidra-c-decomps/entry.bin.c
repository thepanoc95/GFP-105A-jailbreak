typedef unsigned char   undefined;

typedef unsigned int    undefined4;


undefined4 *DAT_00000020;
undefined4 *DAT_00000024;

// WARNING: Control flow encountered bad instruction data

void Reset(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  puVar1 = DAT_00000024;
  puVar2 = DAT_00000020;
  do {
    bVar3 = puVar1 < puVar2;
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + -1;
  } while (bVar3);
  func_0x00005220();
  func_0x00005168();
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



void UndefinedInstruction(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void SupervisorCall(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void PrefetchAbort(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void DataAbort(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void IRQ(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FIQ(void)

{
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Control flow encountered bad instruction data

void FUN_0000002c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  puVar1 = DAT_00000024;
  puVar2 = DAT_00000020;
  do {
    bVar3 = puVar1 < puVar2;
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + -1;
  } while (bVar3);
  func_0x00005220();
  func_0x00005168();
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}


