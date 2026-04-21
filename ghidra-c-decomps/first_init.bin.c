typedef unsigned char   undefined;

typedef unsigned int    undefined4;


undefined4 *DAT_00000078;
undefined4 *DAT_0000007c;
int DAT_00000080;

void Reset(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)((int)DAT_0000007c + DAT_00000080);
  puVar1 = DAT_00000078;
  for (puVar2 = DAT_0000007c; puVar2 < puVar3; puVar2 = puVar2 + 1) {
    *puVar2 = *puVar1;
    puVar1 = puVar1 + 1;
  }
  return;
}



void UndefinedInstruction(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)((int)DAT_0000007c + DAT_00000080);
  for (puVar1 = DAT_0000007c; puVar1 < puVar2; puVar1 = puVar1 + 1) {
    *puVar1 = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}



void SupervisorCall(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int)param_2 + DAT_00000080);
  for (; param_2 < puVar1; param_2 = param_2 + 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}



void PrefetchAbort(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_3 + DAT_00000080);
  for (; param_2 < puVar1; param_2 = param_2 + 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}



void DataAbort(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4)

{
  for (; param_2 < (undefined4 *)(param_3 + param_4); param_2 = param_2 + 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}



void IRQ(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 in_CY;
  
  while (!(bool)in_CY) {
    *param_2 = *param_1;
    in_CY = param_3 <= param_2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



void FIQ(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined1 in_CY;
  
  while (!(bool)in_CY) {
    puVar1 = param_2 + 1;
    *param_2 = param_4;
    in_CY = param_3 <= puVar1;
    param_2 = puVar1;
    if (!(bool)in_CY) {
      param_4 = *param_1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


