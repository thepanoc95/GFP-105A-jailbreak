typedef unsigned char   undefined;

typedef unsigned int    undefined4;
typedef unsigned char    byte;


undefined DAT_000023ac;
uint DAT_0000828c;
uint *DAT_0000829c;
uint *DAT_00008294;
uint *DAT_00008298;
undefined4 DAT_0000827c;
undefined DAT_00008074;
undefined4 DAT_0000838c;
int DAT_001edb6e;
undefined DAT_001eda5c;
undefined DAT_001eda60;
undefined DAT_001eda64;
undefined DAT_001eda68;
undefined DAT_001eda6c;
undefined DAT_001eda70;
undefined DAT_001eda74;
undefined DAT_001eda78;
undefined DAT_001eda7c;
undefined DAT_001eda80;
undefined DAT_001eda84;
uint DAT_00030d78;
uint DAT_000311c4;
uint DAT_000319ec;
undefined4 DAT_000322dc;
undefined4 DAT_00031d08;
uint DAT_00031d80;
uint DAT_00031fd4;
undefined4 DAT_000323ec;
undefined s_~}|{zyxwvvutsrqqponnmllkjjihhgff_000328ff;
uint DAT_00032980;
undefined4 DAT_00032984;
uint DAT_00032988;
undefined LAB_00032e5c;
int DAT_000423d0;
undefined DAT_00150000;
undefined DAT_00120000;
uint *DAT_0005b70c;
uint *DAT_0005b710;
undefined4 DAT_0005b840;
int DAT_0005b894;
int DAT_0005b898;
int DAT_0005b8e8;
int DAT_0005b8ec;
int DAT_0005b93c;
int DAT_0005b940;
undefined4 DAT_0005d680;
int DAT_0005d684;
undefined4 DAT_0005d688;
int DAT_0005dcd8;
int DAT_0005dcdc;
uint DAT_0005de60;
int DAT_0005df18;
undefined4 DAT_0005df1c;
undefined4 DAT_0005df20;
uint DAT_0005e1b8;
uint DAT_0005eb70;
undefined4 DAT_0005ec60;
undefined4 DAT_0005ec64;
uint DAT_0005ec68;
int DAT_0005ecfc;
undefined4 DAT_0005ee2c;
undefined4 DAT_0005ee30;
int DAT_0005ef28;
undefined4 DAT_002d4692;
undefined4 DAT_002d4696;
undefined4 DAT_002d469a;
undefined4 DAT_002d469e;
undefined4 DAT_002d46a2;
undefined4 DAT_002d46a6;
undefined4 DAT_002d46aa;

// WARNING: Control flow encountered bad instruction data

void Reset(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void UndefinedInstruction(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void SupervisorCall(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void PrefetchAbort(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void DataAbort(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00000c94(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



void FUN_000014a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 < param_1) {
    for (; param_2 < param_3; param_2 = param_2 + 1) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
    }
    return;
  }
  if (param_1 != param_2) {
    iVar3 = (int)param_3 + (-4 - (int)param_2);
    puVar1 = (undefined4 *)((int)param_1 + iVar3);
    for (puVar2 = (undefined4 *)((int)param_2 + iVar3); (int)param_2 <= (int)puVar2;
        puVar2 = puVar2 + -1) {
      *puVar2 = *puVar1;
      puVar1 = puVar1 + -1;
    }
    return;
  }
  return;
}



void FUN_000014d4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    *param_1 = 0;
  }
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_00001564(int param_1)

{
  undefined4 unaff_r4;
  char in_NG;
  char in_OV;
  
  if (in_NG != in_OV) {
    *(undefined4 *)(param_1 + -0x96e) = unaff_r4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00001e7c(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  undefined4 in_lr;
  bool in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  
  if (in_OV) {
    *param_2 = 0x1e84;
    param_2[-1] = register0x00000054;
    param_2[-2] = in_r12;
    param_2[-3] = unaff_r10;
    param_2[-4] = unaff_r8;
    param_2[-5] = unaff_r4;
  }
  if (in_NG) {
    param_1 = param_2 + -0x1c000000;
  }
  if (in_CY && !in_ZR) {
    *param_1 = param_1;
    param_1[1] = param_4;
    param_1[2] = unaff_r8;
    param_1[3] = in_r12;
    param_1[4] = in_lr;
    param_1[5] = 0x1e90;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: This is an inlined function

void switch8_r3(void)

{
  byte bVar1;
  uint in_r3;
  int in_lr;
  
  if (in_r3 < *(byte *)(in_lr + -1)) {
    bVar1 = *(byte *)(in_lr + in_r3);
  }
  else {
    bVar1 = *(byte *)(in_lr + (uint)*(byte *)(in_lr + -1));
  }
                    // WARNING: Could not recover jumptable at 0x00002014. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)(in_lr + (uint)bVar1 * 2))();
  return;
}



longlong FUN_00002270(uint param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_2 & 0x80000000;
  if ((int)uVar7 < 0) {
    param_2 = -param_2;
  }
  bVar2 = (byte)(param_1 >> 0x18);
  iVar1 = (int)param_1 >> 0x20;
  bVar3 = (byte)(uVar7 >> 0x18) ^ (char)bVar2 >> 7;
  if ((bool)(bVar2 >> 7)) {
    param_1 = -param_1;
  }
  uVar5 = LZCOUNT(param_2) - 7;
  uVar7 = -param_2;
  if ((int)uVar5 < 0) {
    iVar4 = (int)((ulonglong)
                  ((byte)(&DAT_000023ac)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] - 4 >>
                  (-uVar5 & 0xff)) * (ulonglong)param_1 >> 0x20);
    param_1 = iVar4 * uVar7 + param_1;
    if (CARRY4(uVar7,param_1 >> 1)) {
      param_1 = param_1 + param_2 * -2;
      iVar4 = iVar4 + 2;
    }
    if (CARRY4(uVar7,param_1)) {
      param_1 = param_1 + uVar7;
      iVar4 = iVar4 + 1;
    }
    if ((bool)(bVar3 >> 7)) {
      iVar4 = -iVar4;
    }
    if (iVar1 << 1 < 0) {
      param_1 = -param_1;
    }
    return CONCAT44(param_1,iVar4);
  }
  iVar4 = (uint)(byte)(&DAT_000023ac)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] << (uVar5 & 0xff);
  uVar5 = (int)((uint6)((int6)iVar4 * (int6)(short)(iVar4 * uVar7 >> 0x10)) >> 0x10) + iVar4;
  if (uVar7 == (int)uVar7 >> 1) {
    if (!(bool)((byte)uVar7 & 1)) {
      if (iVar1 << 1 < 0) {
        param_1 = -param_1;
      }
      return (ulonglong)param_1 << 0x20;
    }
    uVar5 = 0;
  }
  else {
    uVar6 = (uint)(((longlong)(int)uVar5 * (longlong)(int)(uVar5 * uVar7) +
                    ((ulonglong)uVar5 << 0x20) >> 0x20) * (ulonglong)param_1 >> 0x20);
    uVar5 = uVar6 * uVar7 + param_1 + uVar7;
    iVar4 = uVar5 + uVar7;
    if (CARRY4(uVar5,uVar7)) {
      uVar5 = uVar5 + param_2;
      param_1 = uVar6;
    }
    else {
      param_1 = uVar6 + 1;
    }
    if (-1 < iVar4) {
      uVar5 = uVar5 + param_2 * -2;
      param_1 = param_1 + 2;
    }
  }
  if ((bool)(bVar3 >> 7)) {
    param_1 = -param_1;
  }
  if (iVar1 << 1 < 0) {
    uVar5 = -uVar5;
  }
  return CONCAT44(uVar5,param_1);
}



// WARNING: Control flow encountered bad instruction data

void FUN_00003288(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int unaff_r6;
  int unaff_r7;
  undefined4 *unaff_r8;
  undefined4 in_r12;
  bool in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  undefined4 in_cr11;
  
  if (in_NG) {
    coprocessor_store(5,in_cr11,unaff_r6 + -0x3c0);
  }
  piVar1 = param_1;
  if (in_CY) {
    piVar1 = (int *)((int)param_1 + -0x64a);
    *param_1 = param_3;
  }
  if (in_ZR) {
    param_3 = unaff_r7 * unaff_r7 + param_3;
  }
  if (!in_OV) {
    *unaff_r8 = 0x329c;
    unaff_r8[-1] = register0x00000054;
    unaff_r8[-2] = in_r12;
    unaff_r8[-3] = unaff_r7;
    unaff_r8[-4] = param_3;
    unaff_r8[-5] = piVar1;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00003a00(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  undefined4 in_lr;
  bool in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  
  if (in_OV) {
    *param_2 = 0x3a08;
    param_2[-1] = register0x00000054;
    param_2[-2] = in_r12;
    param_2[-3] = unaff_r10;
    param_2[-4] = unaff_r8;
    param_2[-5] = unaff_r4;
  }
  if (in_NG) {
    param_1 = param_2 + -0x1c000000;
  }
  if (in_CY && !in_ZR) {
    *param_1 = param_1;
    param_1[1] = param_4;
    param_1[2] = unaff_r8;
    param_1[3] = in_r12;
    param_1[4] = in_lr;
    param_1[5] = 0x3a14;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_000050a8(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int unaff_r4;
  bool in_NG;
  undefined1 in_ZR;
  bool in_CY;
  bool bVar1;
  undefined4 in_cr11;
  undefined4 in_cr15;
  
  if (in_NG) {
    coprocessor_load(5,in_cr11,param_4 - 0x1c0);
  }
  if (in_CY) {
    *param_1 = (int)param_1 + -6;
  }
  if (in_NG) {
    in_ZR = unaff_r4 + 0xa00 + (uint)in_CY == 0;
  }
  bVar1 = false;
  if ((bool)in_ZR) {
    param_3 = param_4 & unaff_r4 << 2;
    bVar1 = param_3 == 0;
  }
  if (bVar1) {
    param_3 = param_4 & unaff_r4 << 2;
  }
  coprocessor_storelong2(0,in_cr15,param_3);
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



undefined8 FUN_00005280(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  byte *pbVar3;
  uint *puVar4;
  byte bVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  uint in_r12;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  
  if (3 < param_3) {
    uVar14 = (uint)param_1 & 3;
    in_r12 = uVar14;
    if (uVar14 != 0) {
      bVar5 = (byte)*param_2;
      puVar2 = (uint *)((int)param_2 + 1);
      if (uVar14 < 3) {
        puVar2 = (uint *)((int)param_2 + 2);
        in_r12 = (uint)*(byte *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar5;
      param_2 = puVar2;
      if (uVar14 < 2) {
        param_2 = (uint *)((int)puVar2 + 1);
        bVar5 = (byte)*puVar2;
      }
      puVar2 = (uint *)((int)param_1 + 1);
      if (uVar14 < 3) {
        puVar2 = (uint *)((int)param_1 + 2);
        *(byte *)((int)param_1 + 1) = (byte)in_r12;
      }
      param_3 = (param_3 + uVar14) - 4;
      param_1 = puVar2;
      if (uVar14 < 2) {
        param_1 = (uint *)((int)puVar2 + 1);
        *(byte *)puVar2 = bVar5;
      }
    }
    param_4 = (uint)param_2 & 3;
    if (param_4 == 0) {
      bVar17 = 0x1f < param_3;
      uVar14 = param_3 - 0x20;
      uVar7 = 0;
      if (bVar17) {
        do {
          if (bVar17) {
            uVar7 = *param_2;
            uVar8 = param_2[1];
            uVar9 = param_2[2];
            uVar10 = param_2[3];
            uVar11 = param_2[4];
            uVar12 = param_2[5];
            uVar15 = param_2[6];
            uVar16 = param_2[7];
            param_2 = param_2 + 8;
            *param_1 = uVar7;
            param_1[1] = uVar8;
            param_1[2] = uVar9;
            param_1[3] = uVar10;
            param_1[4] = uVar11;
            param_1[5] = uVar12;
            param_1[6] = uVar15;
            param_1[7] = uVar16;
            param_1 = param_1 + 8;
            bVar17 = 0x1f < uVar14;
            uVar14 = uVar14 - 0x20;
          }
        } while (bVar17);
        if ((bool)((byte)(uVar14 >> 4) & 1)) {
          uVar7 = *param_2;
          uVar8 = param_2[1];
          uVar9 = param_2[2];
          uVar10 = param_2[3];
          param_2 = param_2 + 4;
          *param_1 = uVar7;
          param_1[1] = uVar8;
          param_1[2] = uVar9;
          param_1[3] = uVar10;
          param_1 = param_1 + 4;
        }
        if ((int)(uVar14 << 0x1c) < 0) {
          uVar7 = *param_2;
          uVar8 = param_2[1];
          param_2 = param_2 + 2;
          *param_1 = uVar7;
          param_1[1] = uVar8;
          param_1 = param_1 + 2;
        }
        puVar1 = param_1;
        puVar2 = param_2;
        if ((bool)((byte)(uVar14 >> 2) & 1)) {
          puVar2 = param_2 + 1;
          uVar7 = *param_2;
          puVar1 = param_1 + 1;
          *param_1 = uVar7;
        }
        uVar6 = (undefined2)uVar7;
        if ((uVar14 & 3) == 0) {
          return CONCAT44(puVar2,puVar1);
        }
      }
      else {
        uVar7 = 0;
        if ((bool)((byte)(uVar14 >> 4) & 1)) {
          uVar7 = *param_2;
          uVar8 = param_2[1];
          uVar9 = param_2[2];
          uVar10 = param_2[3];
          param_2 = param_2 + 4;
          *param_1 = uVar7;
          param_1[1] = uVar8;
          param_1[2] = uVar9;
          param_1[3] = uVar10;
          param_1 = param_1 + 4;
        }
        if ((int)(param_3 * 0x10000000) < 0) {
          uVar7 = *param_2;
          uVar8 = param_2[1];
          param_2 = param_2 + 2;
          *param_1 = uVar7;
          param_1[1] = uVar8;
          param_1 = param_1 + 2;
        }
        puVar1 = param_1;
        puVar2 = param_2;
        if ((bool)((byte)(uVar14 >> 2) & 1)) {
          puVar2 = param_2 + 1;
          uVar7 = *param_2;
          puVar1 = param_1 + 1;
          *param_1 = uVar7;
        }
        uVar6 = (undefined2)uVar7;
        if ((param_3 & 3) == 0) {
          return CONCAT44(puVar2,puVar1);
        }
      }
      bVar18 = (bool)((byte)(uVar14 >> 1) & 1);
      uVar14 = uVar14 << 0x1f;
      bVar17 = (int)uVar14 < 0;
      puVar4 = puVar2;
      if (bVar18) {
        puVar4 = (uint *)((int)puVar2 + 2);
        uVar6 = (undefined2)*puVar2;
      }
      puVar2 = puVar4;
      if (bVar17) {
        puVar2 = (uint *)((int)puVar4 + 1);
        uVar14 = (uint)(byte)*puVar4;
      }
      puVar4 = puVar1;
      if (bVar18) {
        puVar4 = (uint *)((int)puVar1 + 2);
        *(undefined2 *)puVar1 = uVar6;
      }
      puVar1 = puVar4;
      if (bVar17) {
        puVar1 = (uint *)((int)puVar4 + 1);
        *(byte *)puVar4 = (byte)uVar14;
      }
      return CONCAT44(puVar2,puVar1);
    }
    bVar17 = 3 < param_3;
    param_3 = param_3 - 4;
    if (bVar17) {
      param_2 = (uint *)((int)param_2 - param_4);
      in_r12 = *param_2;
      puVar2 = param_1;
      if (param_4 == 2) {
        do {
          puVar1 = param_2;
          param_4 = in_r12 >> 0x10;
          param_2 = puVar1 + 1;
          in_r12 = *param_2;
          bVar17 = 3 < param_3;
          param_3 = param_3 - 4;
          param_4 = param_4 | in_r12 << 0x10;
          param_1 = puVar2 + 1;
          *puVar2 = param_4;
          puVar2 = param_1;
        } while (bVar17);
        param_2 = (uint *)((int)puVar1 + 6);
      }
      else if (param_4 < 3) {
        do {
          puVar1 = param_2;
          param_4 = in_r12 >> 8;
          param_2 = puVar1 + 1;
          in_r12 = *param_2;
          bVar17 = 3 < param_3;
          param_3 = param_3 - 4;
          param_4 = param_4 | in_r12 << 0x18;
          param_1 = puVar2 + 1;
          *puVar2 = param_4;
          puVar2 = param_1;
        } while (bVar17);
        param_2 = (uint *)((int)puVar1 + 5);
      }
      else {
        do {
          puVar1 = param_2;
          param_4 = in_r12 >> 0x18;
          param_2 = puVar1 + 1;
          in_r12 = *param_2;
          bVar17 = 3 < param_3;
          param_3 = param_3 - 4;
          param_4 = param_4 | in_r12 << 8;
          param_1 = puVar2 + 1;
          *puVar2 = param_4;
          puVar2 = param_1;
        } while (bVar17);
        param_2 = (uint *)((int)puVar1 + 7);
      }
    }
  }
  bVar13 = (byte)in_r12;
  bVar5 = (byte)param_4;
  bVar18 = (bool)((byte)(param_3 >> 1) & 1);
  param_3 = param_3 << 0x1f;
  bVar17 = (int)param_3 < 0;
  if (bVar18) {
    pbVar3 = (byte *)((int)param_2 + 1);
    bVar5 = (byte)*param_2;
    param_2 = (uint *)((int)param_2 + 2);
    bVar13 = *pbVar3;
  }
  puVar2 = param_2;
  if (bVar17) {
    puVar2 = (uint *)((int)param_2 + 1);
    param_3 = (uint)(byte)*param_2;
  }
  if (bVar18) {
    pbVar3 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = bVar5;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar3 = bVar13;
  }
  puVar1 = param_1;
  if (bVar17) {
    puVar1 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  return CONCAT44(puVar2,puVar1);
}



// WARNING: This is an inlined function

void switch8_r3(void)

{
  byte bVar1;
  uint in_r3;
  int in_lr;
  
  if (in_r3 < *(byte *)(in_lr + -1)) {
    bVar1 = *(byte *)(in_lr + in_r3);
  }
  else {
    bVar1 = *(byte *)(in_lr + (uint)*(byte *)(in_lr + -1));
  }
                    // WARNING: Could not recover jumptable at 0x0000618c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)(in_lr + (uint)bVar1 * 2))();
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_000061d8(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int unaff_r10;
  bool in_NG;
  bool in_CY;
  undefined4 in_cr11;
  undefined4 in_cr15;
  
  if (in_NG) {
    coprocessor_load(5,in_cr11,param_4 + -0x1c0);
  }
  if (in_CY) {
    *param_1 = (int)param_1 + -6;
  }
  coprocessor_storelong2(7,in_cr15,unaff_r10 + -0x3fc);
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0000633a(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint unaff_r8;
  undefined4 *unaff_r9;
  int in_r12;
  bool in_NG;
  bool in_ZR;
  undefined1 in_CY;
  bool bVar2;
  undefined4 in_cr9;
  
  if (in_NG) {
    return;
  }
  bVar2 = false;
  if (in_ZR) {
    uVar1 = (int)param_3 >> (unaff_r8 & 0xff);
    in_CY = uVar1 <= param_3;
    param_1 = param_3 - uVar1;
    bVar2 = param_1 == 0;
  }
  if ((bool)in_CY && !bVar2) {
    *unaff_r9 = 0x634e;
    unaff_r9[-1] = param_2;
  }
  if (bVar2) {
    *(char *)(in_r12 + param_3) = (char)param_1;
  }
  else {
    coprocessor_moveto2(8,4,param_1,param_1,in_cr9);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00128b30)

undefined8 FUN_00006b04(int param_1)

{
  undefined4 unaff_r4;
  int unaff_r10;
  bool in_NG;
  char in_OV;
  
  if (in_NG != (bool)in_OV) {
    *(undefined4 *)(param_1 + -0x904) = unaff_r4;
  }
  if (in_NG) {
    if (in_OV != '\x01') {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    return *(undefined8 *)(unaff_r10 + -0x2c);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00005218)

undefined8 FUN_00007e00(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint in_r12;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  byte in_Q;
  
  uVar3 = (int)param_2 * 2;
  bVar10 = uVar3 == 0xffe00000 && param_1 == (uint *)0x0;
  if (uVar3 < 0xffe00000 || uVar3 == 0xffe00000 && param_1 == (uint *)0x0) {
    uVar3 = (int)param_4 * 2;
    bVar10 = uVar3 == 0xffe00000;
  }
  if (!bVar10 && uVar3 < 0xffe00000 || bVar10 && param_3 == (uint *)0x0) {
    if ((int)((uint)param_2 | (uint)param_4) < 0) {
      bVar10 = param_2 <= param_4;
      if (param_4 == param_2) {
        bVar10 = param_1 <= param_3;
      }
      uVar3 = ((byte)((param_4 == param_2 && param_3 == param_1) << 3 | bVar10 << 2 | in_Q) & 0xd)
              << 0x1b;
      if (!bVar10) {
        uVar3 = uVar3 | 0x80000000;
      }
      return CONCAT44(param_2,uVar3);
    }
    bVar10 = param_4 <= param_2;
    bVar11 = SBORROW4((int)param_2,(int)param_4);
    iVar1 = (int)param_2 - (int)param_4;
    if (param_2 == param_4) {
      bVar10 = param_3 <= param_1;
      bVar11 = SBORROW4((int)param_1,(int)param_3);
      iVar1 = (int)param_1 - (int)param_3;
    }
    bVar8 = param_2 == param_4 && param_1 == param_3;
    if (bVar11) {
      bVar11 = !bVar10;
      if (bVar11) {
        bVar10 = false;
      }
      bVar9 = !bVar11;
      if (bVar9) {
        bVar10 = true;
      }
      return CONCAT44(param_2,(uint)(byte)((!bVar9 && (bVar11 || iVar1 < 0)) << 4 |
                                           (!bVar9 && (!bVar11 && bVar8)) << 3 | bVar10 << 2 | in_Q)
                              << 0x1b);
    }
    return CONCAT44(param_2,(uint)(byte)((iVar1 < 0) << 4 | bVar8 << 3 | bVar10 << 2 | in_Q) << 0x1b
                   );
  }
  puVar2 = param_2;
  if ((in_r12 & 0xd0000) == 0) {
    uVar7 = (int)param_2 * 2 + 0x100000 + (uint)(param_1 != (uint *)0x0);
    uVar3 = uVar7;
    if (uVar7 < 0xfff00001) {
      uVar3 = (int)param_4 * 2 + 0x100000 + (uint)(param_3 != (uint *)0x0);
    }
    if (uVar3 < 0xfff00001) {
      if (0xfffff < uVar7) {
        param_1 = param_3;
        puVar2 = param_4;
      }
      goto LAB_000082a0;
    }
    if (uVar7 < 0xfff00001) {
      in_r12 = in_r12 | 0x8000;
    }
    else {
      in_r12 = in_r12 | 0x4000;
    }
  }
  if ((in_r12 & 0x70) == 0) {
    param_3 = param_2;
  }
  puVar5 = (uint *)FUN_00008380();
  uVar3 = *puVar5;
  if ((in_r12 & ~(uVar3 << 0x12) & 0x30000000) != 0) {
    in_r12 = in_r12 | 0x40000000;
  }
  uVar7 = in_r12 & 0xf;
  bVar10 = uVar7 != 8;
  if (bVar10) {
    uVar7 = in_r12 & 0x70;
  }
  *puVar5 = uVar3 | (in_r12 << 1) >> 0x1b;
  if (bVar10) {
    in_r12 = in_r12 | uVar7 << 3;
  }
  if ((in_r12 & 0x20000000) == 0) {
    if ((in_r12 & 0x10000000) == 0) {
      if ((in_r12 & 0x40000000) != 0) {
        uVar3 = uVar3 & 0x1000;
        goto joined_r0x00008174;
      }
      if ((in_r12 & 0x8000000) == 0) {
        if ((uVar3 & 0x100) != 0) {
          halt_baddata();
        }
        if ((in_r12 & 0x40) == 0) {
          if ((in_r12 & 0xc000) == 0) {
            param_1 = DAT_00008294;
            puVar2 = DAT_00008298;
            if ((in_r12 & 0x10) == 0) {
              param_1 = DAT_0000829c;
              puVar2 = param_2;
            }
          }
          else {
            bVar10 = (in_r12 & 0x8000) != 0;
            if (bVar10) {
              param_1 = param_3;
            }
            if (bVar10) {
              in_r12 = in_r12 ^ (in_r12 & 0x100) >> 1;
              puVar2 = param_4;
            }
            if ((in_r12 & 0x80) == 0) {
              param_1 = (uint *)((uint)param_1 | 0x400000);
            }
            else {
              puVar2 = (uint *)((uint)puVar2 | 0x80000);
            }
            if (((in_r12 ^ in_r12 >> 3) & 0x10) != 0) {
              in_r12 = in_r12 & 0xfffffff0 | 8;
            }
          }
        }
        else {
          if ((in_r12 & 0x80) == 0) {
            param_2 = param_1;
          }
          if ((in_r12 & 0x10) == 0) {
            param_1 = (uint *)((uint)DAT_0000829c | (uint)param_2 & 0x80000000);
          }
          else {
            param_1 = DAT_00008294;
            puVar2 = (uint *)((uint)DAT_00008298 | (uint)param_2 & 0x80000000);
          }
        }
LAB_000082a0:
        uVar3 = in_r12 & 0xf;
        if (uVar3 == 9) {
          if ((in_r12 & 0x100000) == 0) {
            return CONCAT44(puVar2,(uint)((in_r12 & 0x80000) != 0));
          }
          if ((in_r12 & 0x70000) != 0) {
            return CONCAT44(~(in_r12 << 0xf) << 1,8);
          }
          puVar2 = (uint *)FUN_00008380();
          *puVar2 = *puVar2 & 0xfffffff | 0x30000000;
          return 0xe000000030000000;
        }
        if (uVar3 == 10) {
          if ((in_r12 & 0x40) != 0) {
            param_1 = (uint *)0x80000000;
          }
          return CONCAT44(puVar2,param_1);
        }
        if (uVar3 != 8) {
          return CONCAT44(puVar2,param_1);
        }
        if ((in_r12 & 0x40) == 0) {
          if ((in_r12 & 0x10) != 0) {
            return CONCAT44((uint)param_1 & 0xff000000 | ((uint)param_1 & 0xfffffff) >> 3,
                            ((uint)param_1 & 0xfffffff) << 0x1d);
          }
          return CONCAT44(puVar2,(uint)puVar2 & 0xff000000 |
                                 (uint)param_1 >> 0x1d | ((uint)puVar2 & 0xffffff) << 3);
        }
        if ((in_r12 & 0x10000) == 0) {
          if ((in_r12 & 0x20) == 0) {
            if ((in_r12 & 0x10) == 0) {
              uVar3 = 0x7fffffff;
              puVar5 = puVar2;
              puVar2 = param_1;
            }
            else {
              puVar5 = (uint *)0x7fffffff;
              uVar3 = 0xffffffff;
            }
            if (((uint)puVar2 & 0x80000000) != 0) {
              uVar3 = ~uVar3;
              puVar5 = (uint *)~(uint)puVar5;
            }
            return CONCAT44(puVar5,uVar3);
          }
          if ((in_r12 & 0x10) != 0) {
            param_1 = puVar2;
          }
          uVar4 = 0xffffffff;
          uVar6 = 0xffffffff;
          if (((uint)param_1 & 0x80000000) != 0) {
            uVar4 = 0;
            uVar6 = 0;
          }
          return CONCAT44(uVar6,uVar4);
        }
        return 0;
      }
      if ((uVar3 & 0x200) != 0) {
        halt_baddata();
      }
      if ((in_r12 & 0x40) != 0) {
        return CONCAT44(param_2,0x80000001);
      }
      if ((in_r12 & 0x10) == 0) {
        uVar3 = (uint)param_1 ^ (uint)param_3;
      }
      else {
        uVar3 = (uint)param_2 ^ (uint)param_4;
      }
      param_1 = (uint *)(in_r12 & 0xf);
      if (param_1 == (uint *)0xa) {
        uVar3 = 0xffffffff;
      }
    }
    else {
      if ((uVar3 & 0x400) != 0) {
        halt_baddata();
      }
      if ((in_r12 & 0x80) == 0) {
        uVar3 = (uint)param_1 & 0x80000000;
        in_r12 = in_r12 & 0xefffffff;
      }
      else {
        uVar3 = (uint)param_2 & 0x80000000;
        in_r12 = in_r12 & 0xefffffff;
      }
    }
    bVar10 = (in_r12 & 0x10) != 0;
    if (bVar10) {
      param_1 = &DAT_0000827c;
    }
    if (bVar10) {
      uVar7 = *param_1;
      param_2 = (uint *)(param_1[1] | uVar3 & 0x80000000);
    }
    else {
      uVar7 = DAT_0000828c | uVar3 & 0x80000000;
    }
    return CONCAT44(param_2,uVar7);
  }
  uVar3 = uVar3 & 0x800;
joined_r0x00008174:
  if (uVar3 != 0) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  return CONCAT44(param_2,param_1);
}



longlong FUN_00007f38(uint param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_2 & 0x80000000;
  if ((int)uVar7 < 0) {
    param_2 = -param_2;
  }
  bVar2 = (byte)(param_1 >> 0x18);
  iVar1 = (int)param_1 >> 0x20;
  bVar3 = (byte)(uVar7 >> 0x18) ^ (char)bVar2 >> 7;
  if ((bool)(bVar2 >> 7)) {
    param_1 = -param_1;
  }
  uVar5 = LZCOUNT(param_2) - 7;
  uVar7 = -param_2;
  if ((int)uVar5 < 0) {
    iVar4 = (int)((ulonglong)
                  ((byte)(&DAT_00008074)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] - 4 >>
                  (-uVar5 & 0xff)) * (ulonglong)param_1 >> 0x20);
    param_1 = iVar4 * uVar7 + param_1;
    if (CARRY4(uVar7,param_1 >> 1)) {
      param_1 = param_1 + param_2 * -2;
      iVar4 = iVar4 + 2;
    }
    if (CARRY4(uVar7,param_1)) {
      param_1 = param_1 + uVar7;
      iVar4 = iVar4 + 1;
    }
    if ((bool)(bVar3 >> 7)) {
      iVar4 = -iVar4;
    }
    if (iVar1 << 1 < 0) {
      param_1 = -param_1;
    }
    return CONCAT44(param_1,iVar4);
  }
  iVar4 = (uint)(byte)(&DAT_00008074)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] << (uVar5 & 0xff);
  uVar5 = (int)((uint6)((int6)iVar4 * (int6)(short)(iVar4 * uVar7 >> 0x10)) >> 0x10) + iVar4;
  if (uVar7 == (int)uVar7 >> 1) {
    if (!(bool)((byte)uVar7 & 1)) {
      if (iVar1 << 1 < 0) {
        param_1 = -param_1;
      }
      return (ulonglong)param_1 << 0x20;
    }
    uVar5 = 0;
  }
  else {
    uVar6 = (uint)(((longlong)(int)uVar5 * (longlong)(int)(uVar5 * uVar7) +
                    ((ulonglong)uVar5 << 0x20) >> 0x20) * (ulonglong)param_1 >> 0x20);
    uVar5 = uVar6 * uVar7 + param_1 + uVar7;
    iVar4 = uVar5 + uVar7;
    if (CARRY4(uVar5,uVar7)) {
      uVar5 = uVar5 + param_2;
      param_1 = uVar6;
    }
    else {
      param_1 = uVar6 + 1;
    }
    if (-1 < iVar4) {
      uVar5 = uVar5 + param_2 * -2;
      param_1 = param_1 + 2;
    }
  }
  if ((bool)(bVar3 >> 7)) {
    param_1 = -param_1;
  }
  if (iVar1 << 1 < 0) {
    uVar5 = -uVar5;
  }
  return CONCAT44(uVar5,param_1);
}



undefined4 FUN_00008370(undefined4 param_1)

{
  FUN_00005280();
  return param_1;
}



undefined4 FUN_00008380(void)

{
  return DAT_0000838c;
}



// WARNING: Control flow encountered bad instruction data

void FUN_0000940a(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  bool in_NG;
  bool in_OV;
  
  if (in_OV) {
    *param_2 = 0x9412;
    param_2[-1] = register0x00000054;
    param_2[-2] = in_r12;
    param_2[-3] = unaff_r10;
    param_2[-4] = unaff_r8;
    param_2[-5] = unaff_r7;
    param_2[-6] = unaff_r6;
    param_2[-7] = unaff_r5;
    param_2[-8] = unaff_r4;
    *(undefined4 *)(param_1 + -4) = param_3;
  }
  if (in_NG) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00009b24(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_r12;
  bool in_CY;
  
  if (in_CY) {
    *in_r12 = param_3;
    FUN_0005a7bc();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0000f628(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  bool in_NG;
  bool in_CY;
  bool in_OV;
  
  if (in_CY) {
    param_1[-1] = in_lr;
    param_1[-2] = register0x00000054;
    param_1[-3] = in_r12;
    param_1[-4] = unaff_r11;
    param_1[-5] = unaff_r7;
    param_1[-6] = param_1;
  }
  if (in_NG) {
    *(undefined4 *)(unaff_r7 + -4) = 0xf638;
    *(undefined4 *)(unaff_r7 + -8) = in_lr;
    *(undefined4 *)(unaff_r7 + -0xc) = in_r12;
    *(undefined4 *)(unaff_r7 + -0x10) = unaff_r8;
    *(undefined4 *)(unaff_r7 + -0x14) = param_3;
  }
  if (in_CY) {
    param_1[-1] = in_lr;
    param_1[-2] = register0x00000054;
    param_1[-3] = in_r12;
    param_1[-4] = unaff_r11;
    param_1[-5] = param_4;
    param_1[-6] = param_1;
  }
  if (!in_OV) {
    *param_1 = in_r12;
    param_1[1] = in_lr;
    param_1[2] = 0xf640;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00010f76(undefined4 *param_1)

{
  undefined4 unaff_r4;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  bool in_OV;
  
  if (in_OV) {
    *param_1 = 0x10f7e;
    param_1[-1] = register0x00000054;
    param_1[-2] = in_r12;
    param_1[-3] = unaff_r10;
    param_1[-4] = unaff_r8;
    param_1[-5] = unaff_r4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00010fc4(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00013d5c(int param_1)

{
  undefined4 unaff_r4;
  char in_NG;
  char in_OV;
  
  if (in_NG != in_OV) {
    *(undefined4 *)(param_1 + -0xa11) = unaff_r4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00019cec)
// WARNING: Removing unreachable block (ram,0x00074d34)
// WARNING: Removing unreachable block (ram,0x00074d38)
// WARNING: Removing unreachable block (ram,0x00074d3c)
// WARNING: Removing unreachable block (ram,0x00074d40)
// WARNING: Removing unreachable block (ram,0x00074d44)
// WARNING: Removing unreachable block (ram,0x00074d48)

undefined8 FUN_00019cc4(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int unaff_r4;
  undefined4 unaff_r5;
  int unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  int unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  bool in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  undefined4 in_cr0;
  undefined4 in_cr13;
  
  if (in_OV) {
    *(int *)param_4 = param_4;
    *(int *)(param_4 + 4) = unaff_r4;
    *(undefined4 *)(param_4 + 8) = unaff_r5;
    *(undefined4 *)(param_4 + 0xc) = unaff_r8;
    *(undefined4 *)(param_4 + 0x10) = unaff_r10;
    *(undefined4 *)(param_4 + 0x14) = in_r12;
    *(BADSPACEBASE **)(param_4 + 0x18) = register0x00000054;
    *(undefined4 *)(param_4 + 0x1c) = 0x19ccc;
  }
  if (in_CY) {
    param_1 = (undefined4 *)(unaff_r4 - (int)param_1);
    param_1[-1] = in_lr;
    param_1[-2] = in_r12;
    param_1[-3] = unaff_r11;
    param_1[-4] = unaff_r7;
    param_1[-5] = unaff_r6;
    param_1[-6] = param_1;
  }
  if (in_NG) {
    coprocessor_store(0xd,in_cr13,0x19c68);
  }
  if (in_OV) {
    param_3 = param_4 - (unaff_r9 + (uint)!in_CY);
  }
  if (!in_CY) {
    if (!in_OV) {
      if (!in_ZR) {
        coprocessor_moveto(0,2,0,&stack0x00000000,in_cr0,in_cr0);
      }
      return CONCAT44(param_2,*(undefined4 *)(unaff_r6 + -0x18));
    }
    return *(undefined8 *)(param_3 + -0x10);
  }
  if (in_ZR) {
    *param_1 = param_2;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0001a3d4(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0001a484(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 unaff_r4;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  char in_NG;
  bool in_CY;
  char in_OV;
  
  if (in_NG != in_OV) {
    *(undefined4 *)((int)param_1 + -0xa0a) = unaff_r4;
  }
  if (in_CY) {
    *param_1 = in_lr;
    param_1[-1] = register0x00000054;
    param_1[-2] = in_r12;
    param_1[-3] = unaff_r11;
    param_1[-4] = unaff_r7;
    param_1[-5] = unaff_r4;
    param_1[-6] = param_1;
    *(undefined4 *)(param_2 + -4) = 0x1a494;
    *(undefined4 *)(param_2 + -8) = in_lr;
    *(undefined4 *)(param_2 + -0xc) = in_r12;
    *(undefined4 *)(param_2 + -0x10) = unaff_r8;
    *(undefined4 *)(param_2 + -0x14) = param_3;
    *(undefined4 **)(param_2 + -0x18) = param_1;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0001c5d8(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0001fc7c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  int in_r12;
  bool in_NG;
  bool in_ZR;
  bool in_OV;
  undefined4 in_cr4;
  
  if (in_OV) {
    *param_1 = unaff_r4;
    param_1[1] = unaff_r5;
    param_1[2] = unaff_r6;
    param_1[3] = unaff_r8;
    param_1[4] = unaff_r10;
    param_1[5] = in_r12;
    param_1[6] = register0x00000054;
    param_1[7] = 0x1fc84;
  }
  if (in_NG) {
    coprocessor_store(9,in_cr4,in_r12 + -0x2c);
  }
  if (!in_OV) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  if (in_ZR) {
    *param_4 = param_2;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x001eda00)

void FUN_000259d0(undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  uint unaff_r4;
  undefined4 unaff_r5;
  uint unaff_r6;
  undefined4 unaff_r7;
  uint unaff_r8;
  undefined4 unaff_r9;
  int unaff_r10;
  undefined4 *unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  bool in_NG;
  bool in_ZR;
  undefined1 in_CY;
  bool in_OV;
  bool bVar2;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr4;
  undefined4 in_cr8;
  
  if (in_NG != in_OV) {
    unaff_r4 = param_1[-0x244];
  }
  if (!in_NG) {
    coprocessor_function(0,0,0,in_cr2,in_cr8,in_cr0);
  }
  if (!in_ZR) {
    coprocessor_store(10,in_cr4,unaff_r9);
  }
  if (in_ZR || in_NG != in_OV) {
    param_3 = unaff_r6 & (int)param_1 << 0x10;
  }
  bVar2 = false;
  if (in_ZR) {
    in_CY = (byte)((uint)unaff_r11 >> 0x10) & 1;
    unaff_r8 = unaff_r4 & (int)unaff_r11 << 0x10;
    in_NG = (int)unaff_r8 < 0;
    bVar2 = unaff_r8 == 0;
  }
  if (!bVar2) {
    coprocessor_store(0xd,in_cr1,unaff_r9);
    coprocessor_function(0,4,1,in_cr8,in_cr0,in_cr3);
  }
  if (in_NG) {
    *(undefined4 *)(unaff_r10 + -4) = 0x259f4;
    *(undefined4 *)(unaff_r10 + -8) = in_lr;
    *(undefined4 *)(unaff_r10 + -0xc) = in_r12;
    *(uint *)(unaff_r10 + -0x10) = unaff_r8;
    *(undefined4 *)(unaff_r10 + -0x14) = unaff_r7;
    *(uint *)(unaff_r10 + -0x18) = unaff_r6;
    *(undefined4 *)(unaff_r10 + -0x1c) = unaff_r5;
    *(uint *)(unaff_r10 + -0x20) = unaff_r4;
    *(uint *)(unaff_r10 + -0x24) = param_4;
    puVar1 = param_1;
    if (bVar2 || in_OV != true) {
      puVar1 = (undefined4 *)((int)param_1 - (param_4 >> 0xc));
      *param_1 = unaff_r7;
    }
    if (bVar2) {
      unaff_r10 = DAT_001edb6e;
    }
    if (!in_OV) {
      *(undefined4 *)(&DAT_001eda84 + (byte)in_CY) = 0x1eda14;
      *(undefined4 *)(&DAT_001eda80 + (byte)in_CY) = in_lr;
      *(undefined **)(&DAT_001eda7c + (byte)in_CY) = &DAT_001eda84 + (byte)in_CY;
      *(int *)(&DAT_001eda78 + (byte)in_CY) = unaff_r10;
      *(undefined4 *)(&DAT_001eda74 + (byte)in_CY) = unaff_r9;
      *(uint *)(&DAT_001eda70 + (byte)in_CY) = unaff_r8;
      *(undefined4 *)(&DAT_001eda6c + (byte)in_CY) = unaff_r7;
      *(undefined4 *)(&DAT_001eda68 + (byte)in_CY) = unaff_r5;
      *(uint *)(&DAT_001eda64 + (byte)in_CY) = param_4;
      *(undefined4 *)(&DAT_001eda60 + (byte)in_CY) = param_2;
      *(undefined4 **)(&DAT_001eda5c + (byte)in_CY) = puVar1;
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  if ((bool)in_CY) {
    *param_1 = in_r12;
    param_1[-1] = unaff_r11;
    param_1[-2] = unaff_r10;
    param_1[-3] = unaff_r7;
    param_1[-4] = param_4;
    param_1[-5] = param_1;
    if (!bVar2) {
      *unaff_r11 = 0x25a04;
      unaff_r11[-1] = in_lr;
      unaff_r11[-2] = in_r12;
      unaff_r11[-3] = param_3;
      unaff_r11[-4] = param_2;
      coprocessor_load(0,in_cr0,param_3 - 0x50);
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0002aa0c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_r10;
  bool in_NG;
  
  if (!in_NG) {
    *unaff_r10 = param_3;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0002e610(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 *unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  uint unaff_r10;
  undefined4 in_r12;
  char in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  
  if (in_OV) {
    *unaff_r6 = unaff_r4;
    unaff_r6[1] = unaff_r5;
    unaff_r6[2] = unaff_r6;
    unaff_r6[3] = unaff_r7;
    unaff_r6[4] = unaff_r8;
    unaff_r6[5] = unaff_r10;
    unaff_r6[6] = in_r12;
    unaff_r6[7] = register0x00000054;
    unaff_r6[8] = 0x2e618;
  }
  if (in_ZR || (bool)in_NG != in_OV) {
    param_3 = unaff_r10 & param_1 << 0x1c;
  }
  if (in_CY) {
    FUN_0004892c(param_1,param_2,param_3);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031714)

undefined8 FUN_00030d04(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte in_Q;
  
  uVar5 = param_2 | param_4;
  if ((int)uVar5 < 0) {
    if ((int)(uVar5 + 0x100000) < 0) {
      bVar8 = (param_2 & 0x7fffffff) == 0;
      bVar9 = param_1 == 0 && bVar8;
      if (param_1 == 0 && bVar8) {
        bVar9 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (!bVar9) {
        bVar9 = param_4 == param_2;
      }
      if (bVar9) {
        return CONCAT44(param_2,param_1);
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 << 1 < 0xffe00000 && param_4 << 1 < 0xffe00000) {
      return CONCAT44(param_2,param_1);
    }
  }
  else {
    if (-1 < (int)(uVar5 + 0x100000)) {
      if (param_2 == param_4) {
        return CONCAT44(param_2,param_1);
      }
      return CONCAT44(param_2,param_1);
    }
    if (-1 < (int)(param_2 + 0x100000) && -1 < (int)(param_4 + 0x100000)) {
      return CONCAT44(param_2,param_1);
    }
  }
  uVar5 = param_2 * 2;
  bVar8 = uVar5 == 0xffe00000 && param_1 == 0;
  if (uVar5 < 0xffe00000 || uVar5 == 0xffe00000 && param_1 == 0) {
    uVar5 = param_4 * 2;
    bVar8 = uVar5 == 0xffe00000;
  }
  if (!bVar8 && uVar5 < 0xffe00000 || bVar8 && param_3 == 0) {
    if ((int)(param_2 | param_4) < 0) {
      bVar8 = param_2 <= param_4;
      if (param_4 == param_2) {
        bVar8 = param_1 <= param_3;
      }
      uVar5 = ((byte)((param_4 == param_2 && param_3 == param_1) << 3 | bVar8 << 2 | in_Q) & 0xd) <<
              0x1b;
      if (!bVar8) {
        uVar5 = uVar5 | 0x80000000;
      }
      return CONCAT44(param_2,uVar5);
    }
    bVar8 = param_4 <= param_2;
    bVar9 = SBORROW4(param_2,param_4);
    iVar1 = param_2 - param_4;
    if (param_2 == param_4) {
      bVar8 = param_3 <= param_1;
      bVar9 = SBORROW4(param_1,param_3);
      iVar1 = param_1 - param_3;
    }
    bVar6 = param_2 == param_4 && param_1 == param_3;
    if (!bVar9) {
      return CONCAT44(param_2,(uint)(byte)((iVar1 < 0) << 4 | bVar6 << 3 | bVar8 << 2 | in_Q) <<
                              0x1b);
    }
    bVar9 = !bVar8;
    if (bVar9) {
      bVar8 = false;
    }
    bVar7 = !bVar9;
    if (bVar7) {
      bVar8 = true;
    }
    return CONCAT44(param_2,(uint)(byte)((!bVar7 && (bVar9 || iVar1 < 0)) << 4 |
                                         (!bVar7 && (!bVar9 && bVar6)) << 3 | bVar8 << 2 | in_Q) <<
                            0x1b);
  }
  if ((DAT_00030d78 & 0xd0000) == 0) {
    uVar4 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
    uVar5 = uVar4;
    if (uVar4 < 0xfff00001) {
      uVar5 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
    }
    if (uVar5 < 0xfff00001) {
      if (0xfffff < uVar4) {
        param_1 = param_3;
        param_2 = param_4;
      }
      uVar5 = DAT_00030d78 & 0xf;
      if (uVar5 == 9) {
        if ((DAT_00030d78 & 0x100000) == 0) {
          return CONCAT44(param_2,(uint)((DAT_00030d78 & 0x80000) != 0));
        }
        if ((DAT_00030d78 & 0x70000) == 0) {
                    // WARNING: Bad instruction - Truncating control flow here
          halt_baddata();
        }
        return CONCAT44(~(DAT_00030d78 << 0xf) << 1,8);
      }
      if (uVar5 == 10) {
        if ((DAT_00030d78 & 0x40) != 0) {
          param_1 = 0x80000000;
        }
        return CONCAT44(param_2,param_1);
      }
      if (uVar5 == 8) {
        if ((DAT_00030d78 & 0x40) == 0) {
          if ((DAT_00030d78 & 0x10) == 0) {
            return CONCAT44(param_2,param_2 & 0xff000000 |
                                    param_1 >> 0x1d | (param_2 & 0xffffff) << 3);
          }
          return CONCAT44(param_1 & 0xff000000 | (param_1 & 0xfffffff) >> 3,
                          (param_1 & 0xfffffff) << 0x1d);
        }
        if ((DAT_00030d78 & 0x10000) != 0) {
          return 0;
        }
        if ((DAT_00030d78 & 0x20) != 0) {
          if ((DAT_00030d78 & 0x10) != 0) {
            param_1 = param_2;
          }
          uVar2 = 0xffffffff;
          uVar3 = 0xffffffff;
          if ((param_1 & 0x80000000) != 0) {
            uVar2 = 0;
            uVar3 = 0;
          }
          return CONCAT44(uVar3,uVar2);
        }
        if ((DAT_00030d78 & 0x10) == 0) {
          uVar4 = 0x7fffffff;
          uVar5 = param_2;
          param_2 = param_1;
        }
        else {
          uVar5 = 0x7fffffff;
          uVar4 = 0xffffffff;
        }
        if ((param_2 & 0x80000000) != 0) {
          uVar4 = ~uVar4;
          uVar5 = ~uVar5;
        }
        return CONCAT44(uVar5,uVar4);
      }
      return CONCAT44(param_2,param_1);
    }
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031714)
// WARNING: Restarted to delay deadcode elimination for space: stack

ulonglong FUN_000319a0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  
  if ((DAT_000319ec & (param_2 + 0x100000) * 2) == 0 ||
      (DAT_000319ec & (param_4 + 0x100000) * 2) == 0) {
    uVar10 = DAT_000319ec | 0x200000;
    if ((uVar10 & ~(param_4 << 1)) == 0 || (uVar10 & ~(param_2 << 1)) == 0) {
      uVar6 = param_4 * 2 + (uint)(param_3 != 0);
      uVar12 = param_2 * 2 + (uint)(param_1 != 0);
      bVar13 = uVar10 <= uVar6;
      bVar14 = uVar6 == uVar10;
      if (!bVar13 || bVar14) {
        bVar13 = uVar10 <= uVar12;
        bVar14 = uVar12 == uVar10;
      }
      if (!bVar13 || bVar14) {
        iVar9 = param_4 * 2 + (uint)(param_3 != 0);
        if (iVar9 != param_2 * 2 + (uint)(param_1 != 0)) {
          if (iVar9 != -0x200000) {
            return (ulonglong)(param_2 ^ 0x80000000) << 0x20;
          }
          return (ulonglong)param_4 << 0x20;
        }
        if (-1 < (int)(param_2 ^ param_4)) {
          halt_baddata();
        }
        return (ulonglong)param_4 << 0x20;
      }
      uVar6 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
      uVar10 = uVar6;
      if (uVar6 < 0xfff00001) {
        uVar10 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
      }
      if (0xfff00000 < uVar10) {
        halt_baddata();
      }
      if (0xfffff < uVar6) {
        param_3 = param_1;
        param_4 = param_2;
      }
      uVar10 = DAT_000311c4 & 0xf;
      if (uVar10 != 9) {
        if (uVar10 == 10) {
          if ((DAT_000311c4 & 0x40) != 0) {
            param_3 = 0x80000000;
          }
          return CONCAT44(param_4,param_3);
        }
        if (uVar10 != 8) {
          return CONCAT44(param_4,param_3);
        }
        if ((DAT_000311c4 & 0x40) == 0) {
          if ((DAT_000311c4 & 0x10) == 0) {
            return CONCAT44(param_4,param_4 & 0xff000000 |
                                    param_3 >> 0x1d | (param_4 & 0xffffff) << 3);
          }
          return CONCAT44(param_3 & 0xff000000 | (param_3 & 0xfffffff) >> 3,
                          (param_3 & 0xfffffff) << 0x1d);
        }
        if ((DAT_000311c4 & 0x10000) != 0) {
          return 0;
        }
        if ((DAT_000311c4 & 0x20) != 0) {
          if ((DAT_000311c4 & 0x10) != 0) {
            param_3 = param_4;
          }
          uVar3 = 0xffffffff;
          uVar5 = 0xffffffff;
          if ((param_3 & 0x80000000) != 0) {
            uVar3 = 0;
            uVar5 = 0;
          }
          return CONCAT44(uVar5,uVar3);
        }
        if ((DAT_000311c4 & 0x10) == 0) {
          uVar6 = 0x7fffffff;
          uVar10 = param_4;
          param_4 = param_3;
        }
        else {
          uVar10 = 0x7fffffff;
          uVar6 = 0xffffffff;
        }
        if ((param_4 & 0x80000000) != 0) {
          uVar6 = ~uVar6;
          uVar10 = ~uVar10;
        }
        return CONCAT44(uVar10,uVar6);
      }
      if ((DAT_000311c4 & 0x100000) == 0) {
        return CONCAT44(param_4,(uint)((DAT_000311c4 & 0x80000) != 0));
      }
      if ((DAT_000311c4 & 0x70000) == 0) {
                    // WARNING: Bad instruction - Truncating control flow here
        halt_baddata();
      }
      return CONCAT44(~(DAT_000311c4 << 0xf) << 1,8);
    }
    if ((int)(param_2 ^ param_4) < 0) {
      param_2 = param_2 ^ 0x80000000;
      uVar10 = param_3 - param_1;
      iVar9 = param_4 - (param_2 + (param_1 > param_3));
      if (param_4 <= param_2 && (uint)(param_1 <= param_3) <= param_4 - param_2) {
        bVar14 = CARRY4(param_1,uVar10);
        param_1 = param_1 + uVar10;
        param_2 = param_2 + iVar9 + (uint)bVar14;
        bVar14 = param_3 < uVar10;
        param_3 = param_3 - uVar10;
        param_4 = param_4 - (iVar9 + (uint)bVar14);
      }
      uVar10 = param_4 >> 0x14;
      if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
        if ((uVar10 & 0x7ff) != 0) {
          return CONCAT44(param_4,param_3);
        }
        if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
          return CONCAT44(param_4,param_3);
        }
      }
      else {
        uVar6 = param_4 & ~(uVar10 << 0x14);
        if ((uVar10 & 0x7ff) != 0) {
          uVar12 = param_2 & 0x7fffffff;
          uVar7 = (uVar10 - (param_2 >> 0x14)) - 1;
          goto LAB_00032104;
        }
        bVar14 = CARRY4(param_3,param_1);
        param_3 = param_3 + param_1;
        param_4 = uVar6 + param_2 + (uint)bVar14;
      }
    }
    else {
      bVar14 = param_1 <= param_3;
      uVar10 = param_3 - param_1;
      if (param_4 <= param_2 && (uint)bVar14 <= param_4 - param_2) {
        bVar13 = CARRY4(param_1,uVar10);
        param_1 = param_1 + uVar10;
        uVar6 = param_4 - (param_2 + !bVar14) ^ 0x80000000;
        param_2 = param_2 + uVar6 + (uint)bVar13;
        bVar14 = param_3 < uVar10;
        param_3 = param_3 - uVar10;
        param_4 = param_4 - (uVar6 + bVar14);
      }
      uVar10 = param_4 >> 0x14;
      if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
        if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) goto LAB_000310a0;
      }
      else {
        uVar6 = param_4 & ~(uVar10 << 0x14);
        if ((uVar10 & 0x7ff) != 0) {
          uVar12 = (uVar10 - (param_2 >> 0x14)) - 1;
          iVar9 = -((param_2 & 0x7fffffff) + (uint)(param_1 != 0));
          goto LAB_00030f50;
        }
        bVar14 = param_3 < param_1;
        param_3 = param_3 - param_1;
        param_4 = uVar6 - (param_2 + bVar14);
      }
    }
  }
  else {
    uVar6 = param_2 ^ 0x80000000;
    if ((int)(param_2 ^ param_4) < 0) {
      uVar12 = param_1 - param_3;
      iVar9 = uVar6 - (param_4 + (param_3 > param_1));
      uVar10 = param_1;
      if (uVar6 <= param_4 && (uint)(param_3 <= param_1) <= uVar6 - param_4) {
        param_4 = param_4 + iVar9 + (uint)CARRY4(param_3,uVar12);
        uVar6 = uVar6 - (iVar9 + (uint)(param_1 < uVar12));
        uVar10 = param_1 - uVar12;
        param_3 = param_3 + uVar12;
      }
      param_1 = param_3;
      param_3 = uVar10;
      uVar10 = uVar6 >> 0x14;
      uVar7 = uVar10 - (param_4 >> 0x14);
      uVar6 = uVar6 & ~(uVar10 << 0x14);
      uVar12 = param_4 & ~((int)DAT_000319ec >> 1) | 0x100000;
LAB_00032104:
      uVar11 = 0x20 - uVar7;
      if (uVar7 < 0x21) {
        uVar1 = param_1 >> (uVar7 & 0xff);
        bVar14 = CARRY4(param_3,uVar1);
        uVar1 = param_3 + uVar1;
        uVar2 = uVar12 << (uVar11 & 0xff);
        param_3 = uVar1 + uVar2;
        uVar12 = uVar6 + (uVar12 >> (uVar7 & 0xff)) + (uint)bVar14 + (uint)CARRY4(uVar1,uVar2);
        if (uVar12 < 0x100000) {
          uVar6 = uVar12 + uVar10 * 0x100000;
LAB_00032128:
          iVar9 = param_1 << (uVar11 & 0xff);
          if (-1 < iVar9) {
            return CONCAT44(uVar6,param_3);
          }
          uVar12 = param_3 + 1;
          uVar10 = uVar12;
          if (param_3 != 0xffffffff) {
            uVar10 = iVar9 << 1;
          }
          if (uVar10 != 0) {
            return CONCAT44(uVar6,uVar12);
          }
          goto LAB_00032140;
        }
      }
      else {
        param_1 = uVar12 * 2 + (uint)(param_1 != 0);
        uVar7 = uVar7 - 0x20;
        bVar14 = uVar7 < 0x20;
        uVar11 = 0x1f - uVar7;
        if (bVar14) {
          uVar12 = uVar12 >> (uVar7 & 0xff);
          bVar14 = CARRY4(param_3,uVar12);
          param_3 = param_3 + uVar12;
        }
        else {
          uVar11 = 0;
        }
        uVar6 = uVar6 + uVar10 * 0x100000 + (uint)bVar14;
        if (uVar10 == uVar6 >> 0x14) goto LAB_00032128;
        uVar12 = uVar6 + uVar10 * -0x100000;
      }
      uVar6 = (uVar12 + 0x100000 >> 1) + uVar10 * 0x100000;
      uVar12 = (uint)((byte)(uVar12 + 0x100000) & 1) << 0x1f | param_3 >> 1;
      if ((bool)((byte)param_3 & 1)) {
        bVar14 = uVar12 != 0xffffffff;
        uVar12 = uVar12 + 1;
        uVar10 = uVar12;
        if (bVar14) {
          uVar10 = param_1 << (uVar11 & 0xff);
        }
        if (uVar10 == 0) {
LAB_00032140:
          if (uVar12 == 0) {
            uVar6 = uVar6 + 1;
            uVar12 = 0;
          }
          else {
            uVar12 = uVar12 & 0xfffffffe;
          }
          if (0xffdfffff < uVar6 << 1) {
                    // WARNING: Bad instruction - Truncating control flow here
            halt_baddata();
          }
          return CONCAT44(uVar6,uVar12);
        }
      }
      if (0xffdfffff < uVar6 * 2) {
        halt_baddata();
      }
      return CONCAT44(uVar6,uVar12);
    }
    param_4 = param_4 ^ 0x80000000;
    uVar10 = param_1 - param_3;
    uVar7 = param_3;
    if (uVar6 <= param_4 && (uint)(param_3 <= param_1) <= uVar6 - param_4) {
      uVar7 = param_3 + uVar10;
      uVar12 = uVar6 - (param_4 + (param_3 > param_1)) ^ 0x80000000;
      param_4 = param_4 + uVar12 + (uint)CARRY4(param_3,uVar10);
      uVar6 = uVar6 - (uVar12 + (param_1 < uVar10));
      param_1 = param_1 - uVar10;
    }
    param_3 = param_1;
    uVar10 = uVar6 >> 0x14;
    uVar12 = uVar10 - (param_4 >> 0x14);
    uVar6 = uVar6 & ~(uVar10 << 0x14);
    iVar9 = ((int)DAT_000319ec >> 2) - ((param_4 & ~((int)DAT_000319ec >> 2)) + (uint)(uVar7 != 0));
    param_1 = uVar7;
LAB_00030f50:
    uVar7 = -param_1;
    uVar11 = 0x20 - uVar12;
    if (uVar12 < 0x21) {
      uVar2 = uVar7 >> (uVar12 & 0xff);
      uVar1 = param_3 + uVar2;
      uVar12 = uVar6 + (iVar9 >> (uVar12 & 0xff)) + (uint)CARRY4(param_3,uVar2);
      uVar6 = iVar9 << (uVar11 & 0xff);
      uVar2 = uVar1 + uVar6;
      bVar14 = CARRY4(uVar12,(uint)CARRY4(uVar1,uVar6));
      iVar4 = uVar12 + CARRY4(uVar1,uVar6);
    }
    else {
      uVar12 = uVar12 - 0x20;
      uVar7 = (uint)(param_1 * -2 != 0) | (iVar9 * 2 + (uint)CARRY4(uVar7,uVar7)) * 2;
      uVar11 = 0x1e - uVar12;
      if (0x1e < uVar12 || uVar11 == 0) {
        return CONCAT44(uVar6 + uVar10 * 0x100000,param_3);
      }
      uVar12 = iVar9 >> (uVar12 & 0xff);
      uVar2 = param_3 + uVar12;
      bVar14 = uVar6 != 0 || uVar6 < CARRY4(param_3,uVar12);
      iVar4 = uVar6 - !CARRY4(param_3,uVar12);
    }
    if (-1 < iVar4) {
      iVar4 = iVar4 + uVar10 * 0x100000;
      iVar9 = uVar7 << (uVar11 & 0xff);
      if (-1 < iVar9) {
        return CONCAT44(iVar4,uVar2);
      }
      uVar2 = uVar2 + 1;
      if (uVar2 == 0 || iVar9 == -0x80000000) {
        if (uVar2 == 0) {
          iVar4 = iVar4 + 1;
          uVar2 = 0;
        }
        else {
          uVar2 = uVar2 & 0xfffffffe;
        }
        return CONCAT44(iVar4,uVar2);
      }
      return CONCAT44(iVar4,uVar2);
    }
    uVar6 = uVar11 + 1 & 0xff;
    bVar14 = uVar6 == 0 && bVar14 || uVar6 != 0 && (bool)((byte)(uVar7 >> 0x20 - uVar6) & 1);
    param_3 = uVar2 * 2 + (uint)bVar14;
    iVar4 = iVar4 * 2 + (uint)(CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar14));
    uVar12 = iVar4 + uVar10 * 0x200000;
    bVar14 = (bool)((byte)(uVar12 >> 0x14) & 1);
    if (bVar14 && uVar12 >> 0x15 != 0) {
      iVar4 = iVar4 + uVar10 * 0x100000;
      uVar10 = -((int)(uVar7 << uVar6) >> 0x1f);
      uVar12 = param_3 + uVar10;
      bVar14 = uVar12 == 0;
      if (!CARRY4(param_3,uVar10)) {
        bVar14 = uVar7 << uVar6 == -0x80000000;
      }
      if (bVar14) {
        if (uVar12 == 0) {
          iVar4 = iVar4 + 1;
          uVar12 = 0;
        }
        else {
          uVar12 = uVar12 & 0xfffffffe;
        }
        return CONCAT44(iVar4,uVar12);
      }
      return CONCAT44(iVar4,uVar12);
    }
    if (!bVar14) {
      iVar4 = iVar4 + 0x200000;
      if (iVar4 != 0 || param_3 != 0) {
        iVar8 = LZCOUNT(iVar4);
        if (iVar8 == 0x20) {
          iVar9 = LZCOUNT(param_3);
        }
        if (iVar8 == 0x20) {
          iVar8 = iVar9 + 0x20;
        }
        uVar6 = iVar8 - 0xb;
        iVar9 = ((uVar10 & 0xfffff7ff) - 2) - uVar6;
        if (uVar6 < 0x20) {
          uVar12 = iVar4 << (uVar6 & 0xff) | param_3 >> (0x20 - uVar6 & 0xff);
          iVar4 = param_3 << (uVar6 & 0xff);
        }
        else {
          uVar12 = param_3 << (iVar8 - 0x2bU & 0xff);
          iVar4 = 0;
        }
        if (iVar9 < 0) {
                    // WARNING: Bad instruction - Truncating control flow here
          halt_baddata();
        }
        return CONCAT44(uVar12 + (uVar10 >> 0xb) * -0x80000000 + iVar9 * 0x100000,iVar4);
      }
      goto LAB_000310a0;
    }
    param_4 = (iVar4 >> 1) + uVar10 * 0x100000;
    param_3 = (uint)((byte)iVar4 & 1) << 0x1f | param_3 >> 1;
  }
  if (param_4 << 1 != 0 || param_3 != 0) {
    if (param_4 << 1 < 0x200000) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    return CONCAT44(param_4,param_3);
  }
LAB_000310a0:
  return (ulonglong)param_3;
}



ulonglong FUN_000319f0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  ulonglong uVar15;
  
  if (param_4 != 0 || (int)param_3 < 0) {
    if ((param_4 & 0x80000000) != 0) {
      return (ulonglong)(param_4 < param_2 || param_2 - param_4 < (uint)(param_3 <= param_1));
    }
    uVar10 = LZCOUNT(param_4) - 1;
    uVar8 = param_3 << (uVar10 & 0xff);
    uVar3 = param_4 << (uVar10 & 0xff) | param_3 >> (0x20 - uVar10 & 0xff);
    bVar11 = param_2 - uVar3 < (uint)(uVar8 <= param_1);
    uVar1 = param_2;
    if (uVar3 < param_2 || bVar11) {
      uVar1 = param_2 - (uVar3 + (uVar8 > param_1));
      param_1 = param_1 - uVar8;
    }
    bVar12 = uVar1 - uVar3 < (uint)(uVar8 <= param_1);
    uVar2 = uVar1;
    if (uVar3 < uVar1 || bVar12) {
      uVar2 = uVar1 - (uVar3 + (uVar8 > param_1));
      param_1 = param_1 - uVar8;
    }
    bVar14 = uVar2 - uVar3 < (uint)(uVar8 <= param_1);
    uVar6 = param_1;
    uVar7 = uVar2;
    if (uVar3 < uVar2 || bVar14) {
      uVar6 = param_1 - uVar8;
      uVar7 = uVar2 - (uVar3 + (uVar8 > param_1));
    }
    uVar2 = (uint)(uVar3 < param_2 || bVar11) + (uint)(uVar3 < uVar1 || bVar12) +
            (uint)(uVar3 < uVar2 || bVar14);
    uVar1 = -uVar8;
    uVar8 = -(uVar3 + (uVar8 != 0));
    uVar3 = LZCOUNT(uVar7) - 2;
    if ((int)uVar3 < 0) {
      uVar3 = 0;
    }
    if (uVar10 < uVar3) {
      uVar3 = uVar10;
    }
    uVar7 = uVar7 << (uVar3 & 0xff) | uVar6 >> (0x20 - uVar3 & 0xff);
    uVar6 = uVar6 << (uVar3 & 0xff);
    bVar11 = false;
    if (uVar10 - uVar3 != 0) {
      uVar4 = (uVar10 - uVar3) - 1;
      uVar3 = 3 - (uVar4 & 3);
      bVar11 = CARRY4(uVar3,uVar3 * 2);
      switch(uVar4 & 3) {
      case 0:
        while( true ) {
          uVar4 = uVar4 - 4;
          bVar12 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar11);
          uVar6 = uVar6 * 2 + (uint)bVar11;
          bVar14 = CARRY4(uVar7,uVar7) || CARRY4(uVar7 * 2,(uint)bVar12);
          uVar7 = uVar7 * 2 + (uint)bVar12;
          bVar13 = CARRY4(uVar1,uVar6) || CARRY4(uVar1 + uVar6,(uint)bVar14);
          bVar12 = CARRY4(uVar8 + uVar7,(uint)bVar13);
          bVar11 = CARRY4(uVar8,uVar7) || bVar12;
          if (CARRY4(uVar8,uVar7) || bVar12) {
            uVar7 = uVar8 + uVar7 + (uint)bVar13;
            uVar6 = uVar1 + uVar6 + (uint)bVar14;
          }
          if ((int)uVar4 < 0) break;
switchD_00031be8_caseD_3:
          bVar12 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar11);
          uVar6 = uVar6 * 2 + (uint)bVar11;
          bVar14 = CARRY4(uVar7,uVar7) || CARRY4(uVar7 * 2,(uint)bVar12);
          uVar7 = uVar7 * 2 + (uint)bVar12;
          bVar13 = CARRY4(uVar1,uVar6) || CARRY4(uVar1 + uVar6,(uint)bVar14);
          bVar12 = CARRY4(uVar8 + uVar7,(uint)bVar13);
          bVar11 = CARRY4(uVar8,uVar7) || bVar12;
          if (CARRY4(uVar8,uVar7) || bVar12) {
            uVar7 = uVar8 + uVar7 + (uint)bVar13;
            uVar6 = uVar1 + uVar6 + (uint)bVar14;
          }
switchD_00031be8_caseD_2:
          bVar12 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar11);
          uVar6 = uVar6 * 2 + (uint)bVar11;
          bVar14 = CARRY4(uVar7,uVar7) || CARRY4(uVar7 * 2,(uint)bVar12);
          uVar7 = uVar7 * 2 + (uint)bVar12;
          bVar13 = CARRY4(uVar1,uVar6) || CARRY4(uVar1 + uVar6,(uint)bVar14);
          bVar12 = CARRY4(uVar8 + uVar7,(uint)bVar13);
          bVar11 = CARRY4(uVar8,uVar7) || bVar12;
          if (CARRY4(uVar8,uVar7) || bVar12) {
            uVar7 = uVar8 + uVar7 + (uint)bVar13;
            uVar6 = uVar1 + uVar6 + (uint)bVar14;
          }
switchD_00031be8_caseD_1:
          bVar12 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar11);
          uVar6 = uVar6 * 2 + (uint)bVar11;
          bVar14 = CARRY4(uVar7,uVar7) || CARRY4(uVar7 * 2,(uint)bVar12);
          uVar7 = uVar7 * 2 + (uint)bVar12;
          bVar13 = CARRY4(uVar1,uVar6) || CARRY4(uVar1 + uVar6,(uint)bVar14);
          bVar12 = CARRY4(uVar8 + uVar7,(uint)bVar13);
          bVar11 = CARRY4(uVar8,uVar7) || bVar12;
          if (CARRY4(uVar8,uVar7) || bVar12) {
            uVar7 = uVar8 + uVar7 + (uint)bVar13;
            uVar6 = uVar1 + uVar6 + (uint)bVar14;
          }
        }
        break;
      case 1:
        goto switchD_00031be8_caseD_1;
      case 2:
        goto switchD_00031be8_caseD_2;
      case 3:
        goto switchD_00031be8_caseD_3;
      }
    }
    uVar6 = uVar6 & ~((uVar6 >> (uVar10 & 0xff)) << (uVar10 & 0xff));
    bVar12 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar11);
    uVar1 = uVar6 * 2 + (uint)bVar11;
    uVar10 = uVar10 & 0xff;
    uVar8 = uVar2 << uVar10;
    return CONCAT44((uint)bVar12 +
                    (uint)(uVar10 == 0 && bVar12 ||
                          uVar10 != 0 && (bool)((byte)(uVar2 >> 0x20 - uVar10) & 1)) +
                    (uint)CARRY4(uVar1,uVar8),uVar1 + uVar8);
  }
  if (param_3 == 0) {
    uVar15 = FUN_0005d608(0,0);
    return uVar15;
  }
  iVar9 = LZCOUNT(param_3);
  uVar10 = iVar9 - 1;
  param_3 = param_3 << (uVar10 & 0xff);
  iVar5 = 0;
  if (param_3 << 1 <= param_2) {
    param_2 = param_2 + param_3 * -2;
    iVar5 = 2;
  }
  bVar11 = param_3 <= param_2;
  if (bVar11) {
    param_2 = param_2 - param_3;
  }
  uVar3 = iVar9 + 0x1f;
  uVar1 = -param_3;
  uVar8 = param_1;
  if ((0x1f < uVar3) && (param_2 == 0 && param_1 >> 0x1e == 0)) {
    uVar8 = 0;
    uVar3 = iVar9 - 1;
    param_2 = param_1;
  }
  uVar2 = LZCOUNT(param_2) - 2;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  if (uVar3 < uVar2) {
    uVar2 = uVar3;
  }
  uVar6 = param_2 << (uVar2 & 0xff) | uVar8 >> (0x20 - uVar2 & 0xff);
  uVar8 = uVar8 << (uVar2 & 0xff);
  bVar12 = false;
  if (uVar3 - uVar2 != 0) {
    uVar2 = (uVar3 - uVar2) - 1;
    uVar3 = uVar2 & 7 ^ 7;
    bVar12 = CARRY4(uVar3,uVar3 * 2);
    switch(uVar2 & 7) {
    case 0:
      while( true ) {
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        uVar2 = uVar2 - 8;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
        if ((int)uVar2 < 0) break;
switchD_00031acc_caseD_7:
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
switchD_00031acc_caseD_6:
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
switchD_00031acc_caseD_5:
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
switchD_00031acc_caseD_4:
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
switchD_00031acc_caseD_3:
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
switchD_00031acc_caseD_2:
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
switchD_00031acc_caseD_1:
        bVar13 = CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12);
        uVar8 = uVar8 * 2 + (uint)bVar12;
        uVar3 = uVar6 * 2;
        bVar14 = CARRY4(uVar1 + uVar3,(uint)bVar13);
        bVar12 = CARRY4(uVar1,uVar3) || bVar14;
        uVar6 = uVar1 + uVar3 + (uint)bVar13;
        if (!CARRY4(uVar1,uVar3) && !bVar14) {
          uVar6 = uVar6 + param_3;
        }
      }
      break;
    case 1:
      goto switchD_00031acc_caseD_1;
    case 2:
      goto switchD_00031acc_caseD_2;
    case 3:
      goto switchD_00031acc_caseD_3;
    case 4:
      goto switchD_00031acc_caseD_4;
    case 5:
      goto switchD_00031acc_caseD_5;
    case 6:
      goto switchD_00031acc_caseD_6;
    case 7:
      goto switchD_00031acc_caseD_7;
    }
  }
  return CONCAT44((uVar6 & ~((uVar6 >> (uVar10 & 0xff)) << (uVar10 & 0xff))) * 2 +
                  (uint)(CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar12)) +
                  (iVar5 + (uint)bVar11 << (uVar10 & 0xff)),uVar8 * 2 + (uint)bVar12);
}



// WARNING: Control flow encountered bad instruction data

void FUN_00031cd0(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031714)

undefined8 FUN_00031d0c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  byte in_Q;
  
  uVar5 = param_2 | param_4;
  if ((int)uVar5 < 0) {
    if ((int)(uVar5 + 0x100000) < 0) {
      bVar8 = (param_2 & 0x7fffffff) == 0;
      bVar9 = param_1 == 0 && bVar8;
      if (param_1 == 0 && bVar8) {
        bVar9 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (!bVar9) {
        bVar9 = param_4 == param_2;
      }
      if (bVar9) {
        return CONCAT44(param_2,param_1);
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 << 1 < 0xffe00000 && param_4 << 1 < 0xffe00000) {
      return CONCAT44(param_2,param_1);
    }
  }
  else {
    if (-1 < (int)(uVar5 + 0x100000)) {
      if (param_2 == param_4) {
        return CONCAT44(param_2,param_1);
      }
      return CONCAT44(param_2,param_1);
    }
    if (-1 < (int)(param_2 + 0x100000) && -1 < (int)(param_4 + 0x100000)) {
      return CONCAT44(param_2,param_1);
    }
  }
  uVar5 = param_2 * 2;
  bVar8 = uVar5 == 0xffe00000 && param_1 == 0;
  if (uVar5 < 0xffe00000 || uVar5 == 0xffe00000 && param_1 == 0) {
    uVar5 = param_4 * 2;
    bVar8 = uVar5 == 0xffe00000;
  }
  if (!bVar8 && uVar5 < 0xffe00000 || bVar8 && param_3 == 0) {
    if ((int)(param_2 | param_4) < 0) {
      bVar8 = param_2 <= param_4;
      if (param_4 == param_2) {
        bVar8 = param_1 <= param_3;
      }
      uVar5 = ((byte)((param_4 == param_2 && param_3 == param_1) << 3 | bVar8 << 2 | in_Q) & 0xd) <<
              0x1b;
      if (!bVar8) {
        uVar5 = uVar5 | 0x80000000;
      }
      return CONCAT44(param_2,uVar5);
    }
    bVar8 = param_4 <= param_2;
    bVar9 = SBORROW4(param_2,param_4);
    iVar1 = param_2 - param_4;
    if (param_2 == param_4) {
      bVar8 = param_3 <= param_1;
      bVar9 = SBORROW4(param_1,param_3);
      iVar1 = param_1 - param_3;
    }
    bVar6 = param_2 == param_4 && param_1 == param_3;
    if (!bVar9) {
      return CONCAT44(param_2,(uint)(byte)((iVar1 < 0) << 4 | bVar6 << 3 | bVar8 << 2 | in_Q) <<
                              0x1b);
    }
    bVar9 = !bVar8;
    if (bVar9) {
      bVar8 = false;
    }
    bVar7 = !bVar9;
    if (bVar7) {
      bVar8 = true;
    }
    return CONCAT44(param_2,(uint)(byte)((!bVar7 && (bVar9 || iVar1 < 0)) << 4 |
                                         (!bVar7 && (!bVar9 && bVar6)) << 3 | bVar8 << 2 | in_Q) <<
                            0x1b);
  }
  if ((DAT_00031d80 & 0xd0000) == 0) {
    uVar4 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
    uVar5 = uVar4;
    if (uVar4 < 0xfff00001) {
      uVar5 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
    }
    if (uVar5 < 0xfff00001) {
      if (0xfffff < uVar4) {
        param_1 = param_3;
        param_2 = param_4;
      }
      uVar5 = DAT_00031d80 & 0xf;
      if (uVar5 == 9) {
        if ((DAT_00031d80 & 0x100000) == 0) {
          return CONCAT44(param_2,(uint)((DAT_00031d80 & 0x80000) != 0));
        }
        if ((DAT_00031d80 & 0x70000) == 0) {
                    // WARNING: Bad instruction - Truncating control flow here
          halt_baddata();
        }
        return CONCAT44(~(DAT_00031d80 << 0xf) << 1,8);
      }
      if (uVar5 == 10) {
        if ((DAT_00031d80 & 0x40) != 0) {
          param_1 = 0x80000000;
        }
        return CONCAT44(param_2,param_1);
      }
      if (uVar5 == 8) {
        if ((DAT_00031d80 & 0x40) == 0) {
          if ((DAT_00031d80 & 0x10) == 0) {
            return CONCAT44(param_2,param_2 & 0xff000000 |
                                    param_1 >> 0x1d | (param_2 & 0xffffff) << 3);
          }
          return CONCAT44(param_1 & 0xff000000 | (param_1 & 0xfffffff) >> 3,
                          (param_1 & 0xfffffff) << 0x1d);
        }
        if ((DAT_00031d80 & 0x10000) != 0) {
          return 0;
        }
        if ((DAT_00031d80 & 0x20) != 0) {
          if ((DAT_00031d80 & 0x10) != 0) {
            param_1 = param_2;
          }
          uVar2 = 0xffffffff;
          uVar3 = 0xffffffff;
          if ((param_1 & 0x80000000) != 0) {
            uVar2 = 0;
            uVar3 = 0;
          }
          return CONCAT44(uVar3,uVar2);
        }
        if ((DAT_00031d80 & 0x10) == 0) {
          uVar4 = 0x7fffffff;
          uVar5 = param_2;
          param_2 = param_1;
        }
        else {
          uVar5 = 0x7fffffff;
          uVar4 = 0xffffffff;
        }
        if ((param_2 & 0x80000000) != 0) {
          uVar4 = ~uVar4;
          uVar5 = ~uVar5;
        }
        return CONCAT44(uVar5,uVar4);
      }
      return CONCAT44(param_2,param_1);
    }
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031714)

ulonglong FUN_00031e14(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar6 = param_2 & 0x80000000;
  uVar3 = param_2 & 0x7fffffff;
  uVar5 = uVar3 ^ uVar3 << 1;
  if ((uVar5 & 0x7f000000) == 0 && (uVar5 & 0xe00000) == 0) {
    if ((param_2 & 0x100000) == 0) {
      if (param_1 == 0 && uVar3 == 0) {
        return CONCAT44(param_2,param_2) & 0x7fffffff80000000;
      }
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return CONCAT44(param_2,param_2) & 0xffffffffff8fffff;
    }
    if (((param_2 & 0x80000) != 0) && ((DAT_00031fd4 & 0x4f) != 0x48)) {
      uVar3 = DAT_00031fd4 & 0xf;
      if (uVar3 == 9) {
        if ((DAT_00031fd4 & 0x100000) == 0) {
          return CONCAT44(param_2,(uint)((DAT_00031fd4 & 0x80000) != 0));
        }
        if ((DAT_00031fd4 & 0x70000) != 0) {
          return CONCAT44(~(DAT_00031fd4 << 0xf) << 1,8);
        }
                    // WARNING: Bad instruction - Truncating control flow here
        halt_baddata();
      }
      if (uVar3 == 10) {
        if ((DAT_00031fd4 & 0x40) != 0) {
          param_1 = 0x80000000;
        }
        return CONCAT44(param_2,param_1);
      }
      if (uVar3 != 8) {
        return CONCAT44(param_2,param_1);
      }
      if ((DAT_00031fd4 & 0x40) == 0) {
        if ((DAT_00031fd4 & 0x10) != 0) {
          return CONCAT44(param_1 & 0xff000000 | (param_1 & 0xfffffff) >> 3,
                          (param_1 & 0xfffffff) << 0x1d);
        }
        return CONCAT44(param_2,param_2 & 0xff000000 | param_1 >> 0x1d | (param_2 & 0xffffff) << 3);
      }
      if ((DAT_00031fd4 & 0x10000) == 0) {
        if ((DAT_00031fd4 & 0x20) == 0) {
          if ((DAT_00031fd4 & 0x10) == 0) {
            uVar5 = 0x7fffffff;
            uVar3 = param_2;
            param_2 = param_1;
          }
          else {
            uVar3 = 0x7fffffff;
            uVar5 = 0xffffffff;
          }
          if ((param_2 & 0x80000000) != 0) {
            uVar5 = ~uVar5;
            uVar3 = ~uVar3;
          }
          return CONCAT44(uVar3,uVar5);
        }
        if ((DAT_00031fd4 & 0x10) != 0) {
          param_1 = param_2;
        }
        uVar1 = 0xffffffff;
        uVar2 = 0xffffffff;
        if ((param_1 & 0x80000000) != 0) {
          uVar1 = 0;
          uVar2 = 0;
        }
        return CONCAT44(uVar2,uVar1);
      }
      return 0;
    }
  }
  else {
    iVar4 = uVar3 + 0xc8000000;
    if (iVar4 < 0x100000) {
      uVar6 = uVar6 | 1;
    }
    bVar7 = (bool)((byte)(param_1 >> 0x1c) & 1);
    if ((bVar7 && (param_1 & 0xfffffff) != 0) ||
       ((bVar7 && (-1 < (int)((param_1 & 0x20000000) * 4 + -0x40000000))))) {
      bVar7 = 0xdfffffff < param_1;
      param_1 = param_1 + 0x20000000;
      iVar4 = iVar4 + (uint)bVar7;
    }
    if ((uVar6 & 1) != 0) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    if (iVar4 < 0xff00000) {
      return CONCAT44(iVar4,uVar6 | iVar4 << 3 | param_1 >> 0x1d);
    }
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031704)
// WARNING: Removing unreachable block (ram,0x00031728)
// WARNING: Removing unreachable block (ram,0x00031730)
// WARNING: Removing unreachable block (ram,0x00031734)
// WARNING: Removing unreachable block (ram,0x000313bc)
// WARNING: Removing unreachable block (ram,0x000313c0)
// WARNING: Removing unreachable block (ram,0x000313c4)
// WARNING: Removing unreachable block (ram,0x000313c8)
// WARNING: Removing unreachable block (ram,0x000313d4)
// WARNING: Removing unreachable block (ram,0x000313d8)
// WARNING: Removing unreachable block (ram,0x000313dc)
// WARNING: Removing unreachable block (ram,0x000313f0)
// WARNING: Removing unreachable block (ram,0x000313e0)
// WARNING: Removing unreachable block (ram,0x0003170c)
// WARNING: Removing unreachable block (ram,0x00031714)
// WARNING: Removing unreachable block (ram,0x0003171c)
// WARNING: Removing unreachable block (ram,0x0003137c)
// WARNING: Removing unreachable block (ram,0x00031380)
// WARNING: Removing unreachable block (ram,0x000313f8)
// WARNING: Removing unreachable block (ram,0x00031414)
// WARNING: Removing unreachable block (ram,0x00031400)
// WARNING: Removing unreachable block (ram,0x00031398)
// WARNING: Removing unreachable block (ram,0x00031384)
// WARNING: Removing unreachable block (ram,0x0003139c)
// WARNING: Removing unreachable block (ram,0x000313ac)
// WARNING: Removing unreachable block (ram,0x000313b0)
// WARNING: Removing unreachable block (ram,0x000313b8)
// WARNING: Removing unreachable block (ram,0x00031774)
// WARNING: Removing unreachable block (ram,0x00031364)
// WARNING: Removing unreachable block (ram,0x00031778)
// WARNING: Removing unreachable block (ram,0x000313ec)
// WARNING: Removing unreachable block (ram,0x00031444)

undefined8 FUN_000322e4(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char in_OV;
  bool bVar4;
  bool bVar5;
  
  uVar3 = 0x7ff;
  uVar2 = param_2 >> 0x14 & 0x7ff;
  bVar4 = uVar2 == 0;
  if (!bVar4) {
    uVar3 = uVar2 ^ 0x7ff;
    bVar4 = uVar3 == 0;
  }
  bVar5 = bVar4;
  if (!bVar4) {
    in_OV = SBORROW4(uVar3,param_3);
    bVar5 = uVar3 == param_3;
  }
  bVar4 = !bVar4 && (int)(uVar3 - param_3) < 0;
  if (!bVar5 && bVar4 == (bool)in_OV) {
    in_OV = SCARRY4(param_3,uVar2);
    bVar4 = (int)(param_3 + uVar2) < 0;
    bVar5 = param_3 + uVar2 == 0;
  }
  if (!bVar5 && bVar4 == (bool)in_OV) {
    return CONCAT44(param_2 + param_3 * 0x100000,param_1);
  }
  if (uVar2 == 0) {
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return CONCAT44(param_2,param_1);
    }
    iVar1 = param_2 << 0xc;
    if (iVar1 == 0) {
      uVar3 = param_1 << LZCOUNT(param_1);
      uVar2 = -(LZCOUNT(param_1) + 0x14);
      param_1 = uVar3 << 0x15;
      param_2 = (param_2 | uVar3 >> 0xb) & 0xffefffff;
    }
    else {
      uVar3 = 0x14 - LZCOUNT(iVar1);
      uVar2 = 0x14 - uVar3;
      param_2 = param_2 & 0x80000000 |
                ((iVar1 << LZCOUNT(iVar1) | param_1 >> (uVar3 & 0xff)) << 1) >> 0xc;
      param_1 = (param_1 << (uVar2 & 0xff)) << 1;
      uVar2 = -uVar2;
    }
  }
  else {
    if (uVar3 == 0) {
      if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
        return CONCAT44(param_2,param_1);
      }
      if ((param_2 & 0x80000) == 0) {
        halt_baddata();
      }
      return CONCAT44(param_2,param_1);
    }
    param_2 = param_2 + uVar2 * -0x100000;
  }
  if (-0xe40 < (int)param_3) {
    if ((int)param_3 < 0xe00) {
      param_3 = param_3 + uVar2;
    }
    if (-2 < (int)(param_3 - 0x800)) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    if (0 < (int)param_3) {
      return CONCAT44(param_2 | param_3 << 0x14,param_1);
    }
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031714)
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

ulonglong FUN_000323f0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  ulonglong uVar13;
  
  if ((ram0x0003297c & ~(param_2 >> 4)) != 0 && (ram0x0003297c & ~(param_4 >> 4)) != 0) {
    uVar5 = ram0x0003297c & param_2 >> 4;
    uVar6 = uVar5 | (param_2 ^ param_4) >> 0x1f;
    uVar9 = ram0x0003297c & param_4 >> 4;
    if (uVar9 == 0 || (param_2 & ram0x0003297c << 4) == 0) {
      if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
        if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
          halt_baddata();
        }
        return CONCAT44(param_2 ^ param_4,param_1) & 0x80000000ffffffff;
      }
      if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
        halt_baddata();
      }
      if (uVar9 == 0) {
        param_4 = param_4 & 0x7fffffff;
        uVar4 = 0;
        iVar8 = 0x10000;
        if (param_4 == 0 && param_3 >> 0xc == 0) {
          param_3 = param_3 << 0x14;
          iVar8 = -0x130000;
        }
        uVar1 = param_3;
        if (param_4 == 0) {
          param_4 = param_3 >> 0xc;
          uVar1 = param_3 << 0x14;
          iVar8 = iVar8 + -0x140000;
        }
        if (param_4 >> 5 == 0) {
          param_4 = param_4 << 0x10;
          uVar4 = 0x10;
        }
        if (param_4 >> 0xd == 0) {
          param_4 = param_4 << 8;
          uVar4 = uVar4 + 8;
        }
        if (param_4 >> 0x11 == 0) {
          param_4 = param_4 << 4;
          uVar4 = uVar4 + 4;
        }
        if (param_4 >> 0x13 == 0) {
          param_4 = param_4 << 2;
          uVar4 = uVar4 + 2;
        }
        if (param_4 >> 0x14 == 0) {
          uVar4 = uVar4 + 1;
          param_4 = 0;
        }
        param_3 = uVar1 << (uVar4 & 0xff);
        uVar9 = iVar8 + uVar4 * -0x10000;
        param_4 = param_4 | uVar1 >> (0x20 - uVar4 & 0xff);
      }
      if ((uVar5 & 0xfffffffe) == 0) {
        param_2 = param_2 & 0x7fffffff;
        uVar5 = 0;
        iVar8 = uVar6 + 0x10000;
        if (param_2 == 0 && param_1 >> 0xc == 0) {
          param_1 = param_1 << 0x14;
          iVar8 = uVar6 - 0x130000;
        }
        uVar4 = param_1;
        if (param_2 == 0) {
          param_2 = param_1 >> 0xc;
          uVar4 = param_1 << 0x14;
          iVar8 = iVar8 + -0x140000;
        }
        if (param_2 >> 5 == 0) {
          param_2 = param_2 << 0x10;
          uVar5 = 0x10;
        }
        if (param_2 >> 0xd == 0) {
          param_2 = param_2 << 8;
          uVar5 = uVar5 + 8;
        }
        if (param_2 >> 0x11 == 0) {
          param_2 = param_2 << 4;
          uVar5 = uVar5 + 4;
        }
        if (param_2 >> 0x13 == 0) {
          param_2 = param_2 << 2;
          uVar5 = uVar5 + 2;
        }
        if (param_2 >> 0x14 == 0) {
          uVar5 = uVar5 + 1;
          param_2 = param_2 << 1;
        }
        param_1 = uVar4 << (uVar5 & 0xff);
        uVar6 = iVar8 + uVar5 * -0x10000;
        param_2 = param_2 | uVar4 >> (0x20 - uVar5 & 0xff);
      }
    }
    uVar4 = param_4 << 0xb | param_3 >> 0x15;
    iVar7 = uVar6 - uVar9;
    uVar13 = FUN_0003269c(param_1 << 0xb,param_2 << 0xb | param_1 >> 0x15 | 0x80000000,
                          param_3 << 0xb);
    iVar8 = (int)uVar13 << 0x15;
    uVar5 = (uint)(uVar13 >> 0xb);
    uVar9 = (int)((uVar13 >> 0xb) >> 0x20) + (uVar4 + (iVar7 + 0x3fc0000 >> 0x10)) * 0x100000;
    uVar6 = uVar9 ^ iVar7 * -0x80000000;
    if ((iVar8 != 0) && (SUB41((uint)iVar8 >> 0x1f,0))) {
      if ((uVar13 & 0x3ff) == 0) {
        uVar4 = 0x80000000;
      }
      else {
        uVar4 = 0;
      }
      uVar6 = uVar6 + (0xfffffffe < uVar5);
      uVar5 = uVar5 + 1 & ~(uVar4 >> 0x1f);
    }
    if ((-1 < (int)(uVar6 ^ iVar7 * -0x80000000)) &&
       ((uVar9 & DAT_00032980) != 0 && (DAT_00032980 & ~uVar6) != 0)) {
      return CONCAT44(uVar6,uVar5);
    }
    if (0x4000000 < iVar7 + 0x3fc0000) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  uVar5 = param_2 * 2;
  uVar6 = ram0x0003297c * 0x20;
  bVar10 = uVar5 == uVar6;
  bVar11 = bVar10 && param_1 == 0;
  bVar12 = bVar10 || uVar6 <= uVar5;
  if (!bVar10 && uVar6 > uVar5 || bVar10 && param_1 == 0) {
    bVar12 = ram0x0003297c * 0x20 <= param_4 * 2;
    bVar11 = param_4 * 2 == ram0x0003297c * 0x20;
  }
  if (bVar11) {
    bVar12 = true;
  }
  if (!bVar12 || bVar11 && param_3 == 0) {
    if ((param_2 & 0x7fffffff) != 0x7ff00000) {
      return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
    }
    if ((param_4 & 0x7fffffff) == 0x7ff00000) {
      halt_baddata();
    }
    uVar5 = param_2 & 0x7fffffff;
    if ((int)(param_2 ^ param_4) < 0) {
      uVar5 = uVar5 | 0x80000000;
    }
    return CONCAT44(uVar5,param_1);
  }
  uVar6 = param_2 * 2 + 0x100000 + (uint)(param_1 != 0);
  uVar5 = uVar6;
  if (uVar6 < 0xfff00001) {
    uVar5 = param_4 * 2 + 0x100000 + (uint)(param_3 != 0);
  }
  if (0xfff00000 < uVar5) {
    halt_baddata();
  }
  if (0xfffff < uVar6) {
    param_1 = param_3;
    param_2 = param_4;
  }
  uVar5 = DAT_00032988 & 0xf;
  if (uVar5 != 9) {
    if (uVar5 == 10) {
      if ((DAT_00032988 & 0x40) != 0) {
        param_1 = 0x80000000;
      }
      return CONCAT44(param_2,param_1);
    }
    if (uVar5 != 8) {
      return CONCAT44(param_2,param_1);
    }
    if ((DAT_00032988 & 0x40) == 0) {
      if ((DAT_00032988 & 0x10) != 0) {
        return CONCAT44(param_1 & 0xff000000 | (param_1 & 0xfffffff) >> 3,
                        (param_1 & 0xfffffff) << 0x1d);
      }
      return CONCAT44(param_2,param_2 & 0xff000000 | param_1 >> 0x1d | (param_2 & 0xffffff) << 3);
    }
    if ((DAT_00032988 & 0x10000) == 0) {
      if ((DAT_00032988 & 0x20) == 0) {
        if ((DAT_00032988 & 0x10) == 0) {
          uVar6 = 0x7fffffff;
          uVar5 = param_2;
          param_2 = param_1;
        }
        else {
          uVar5 = 0x7fffffff;
          uVar6 = 0xffffffff;
        }
        if ((param_2 & 0x80000000) != 0) {
          uVar6 = ~uVar6;
          uVar5 = ~uVar5;
        }
        return CONCAT44(uVar5,uVar6);
      }
      if ((DAT_00032988 & 0x10) != 0) {
        param_1 = param_2;
      }
      uVar2 = 0xffffffff;
      uVar3 = 0xffffffff;
      if ((param_1 & 0x80000000) != 0) {
        uVar2 = 0;
        uVar3 = 0;
      }
      return CONCAT44(uVar3,uVar2);
    }
    return 0;
  }
  if ((DAT_00032988 & 0x100000) == 0) {
    return CONCAT44(param_2,(uint)((DAT_00032988 & 0x80000) != 0));
  }
  if ((DAT_00032988 & 0x70000) != 0) {
    return CONCAT44(~(DAT_00032988 << 0xf) << 1,8);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



undefined8 FUN_0003269c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  
  uVar7 = param_4 >> 0x10;
  uVar8 = param_3 >> 0x10;
  uVar11 = (uint)*(byte *)((param_4 >> 0x18) + 0x3287c);
  param_3 = param_3 & ~(uVar8 << 0x10);
  uVar10 = param_4 & ~(uVar7 << 0x10);
  uVar1 = (uint)((byte)param_2 & 1) << 0x1f | param_1 >> 1;
  if ((bool)((byte)param_1 & 1)) {
    uVar14 = 0x80000000;
  }
  else {
    uVar14 = 0;
  }
  iVar12 = ((0x800000 - (uVar7 * uVar11 + uVar11)) * uVar11 >> 0x13) + 2;
  uVar13 = 0x20000000 - ((param_4 >> 0xd) * iVar12 + iVar12);
  uVar11 = uVar13 >> 0x10;
  uVar11 = uVar11 * iVar12 + ((uVar13 & ~(uVar11 << 0x10)) * iVar12 >> 0x10) >> 6;
  uVar13 = uVar11 * (param_2 >> 0x10) >> 0x10;
  uVar3 = uVar1 - uVar13 * uVar8;
  uVar15 = uVar13 * param_3;
  bVar21 = uVar15 * 0x10000 <= uVar14;
  uVar14 = uVar14 + uVar15 * -0x10000;
  uVar15 = uVar15 >> 0x10;
  bVar2 = uVar3 - uVar15 < (uint)bVar21;
  bVar22 = uVar15 < uVar3 || bVar2;
  uVar4 = uVar3 - (uVar15 + !bVar21);
  uVar16 = uVar13 * uVar10;
  if (uVar15 < uVar3 || bVar2) {
    bVar22 = uVar16 * 0x10000 <= uVar4;
  }
  uVar4 = uVar4 + uVar16 * -0x10000;
  uVar16 = ((param_2 >> 1) - (uVar7 * uVar13 + (uint)(uVar1 < uVar13 * uVar8))) -
           ((uVar16 >> 0x10) + (uint)!bVar22);
  uVar1 = uVar11 * (uVar16 >> 2) >> 0x10;
  uVar15 = uVar1 * uVar8;
  bVar21 = uVar15 * 0x80000 <= uVar14;
  uVar14 = uVar14 + uVar15 * -0x80000;
  uVar15 = uVar15 >> 0xd;
  bVar2 = uVar4 - uVar15 < (uint)bVar21;
  bVar22 = uVar15 < uVar4 || bVar2;
  uVar3 = uVar4 - (uVar15 + !bVar21);
  uVar17 = uVar7 * uVar1;
  if (uVar15 < uVar4 || bVar2) {
    bVar22 = uVar17 * 0x80000 <= uVar3;
  }
  uVar3 = uVar3 + uVar17 * -0x80000;
  uVar15 = uVar1 * param_3;
  bVar23 = uVar15 * 8 <= uVar14;
  uVar4 = uVar15 >> 0x1d;
  bVar2 = uVar3 - uVar4 < (uint)bVar23;
  bVar21 = uVar4 < uVar3 || bVar2;
  uVar5 = uVar3 - (uVar4 + !bVar23);
  uVar18 = uVar1 * uVar10;
  if (uVar4 < uVar3 || bVar2) {
    bVar21 = uVar18 * 8 <= uVar5;
  }
  uVar5 = uVar5 + uVar18 * -8;
  uVar18 = ((uVar16 - ((uVar17 >> 0xd) + (uint)!bVar22)) - ((uVar18 >> 0x1d) + (uint)!bVar21)) *
           0x4000000 | uVar5 >> 6;
  uVar4 = uVar5 * 0x4000000 | uVar14 + uVar15 * -8 >> 6;
  uVar5 = uVar11 * (uVar18 >> 0xf);
  uVar15 = uVar15 * -0x20000000;
  uVar14 = uVar5 >> 0x10;
  uVar16 = uVar4 - uVar14 * uVar8;
  uVar3 = uVar14 * param_3;
  bVar21 = uVar3 * 0x10000 <= uVar15;
  uVar15 = uVar15 + uVar3 * -0x10000;
  uVar3 = uVar3 >> 0x10;
  bVar2 = uVar16 - uVar3 < (uint)bVar21;
  bVar22 = uVar3 < uVar16 || bVar2;
  uVar17 = uVar16 - (uVar3 + !bVar21);
  uVar19 = uVar14 * uVar10;
  if (uVar3 < uVar16 || bVar2) {
    bVar22 = uVar19 * 0x10000 <= uVar17;
  }
  uVar17 = uVar17 + uVar19 * -0x10000;
  uVar16 = (uVar18 - (uVar7 * uVar14 + (uint)(uVar4 < uVar14 * uVar8))) -
           ((uVar19 >> 0x10) + (uint)!bVar22);
  uVar11 = uVar11 * (uVar16 >> 2) >> 0x10;
  uVar3 = uVar11 * uVar8;
  bVar21 = uVar3 * 0x80000 <= uVar15;
  uVar15 = uVar15 + uVar3 * -0x80000;
  uVar3 = uVar3 >> 0xd;
  bVar2 = uVar17 - uVar3 < (uint)bVar21;
  bVar22 = uVar3 < uVar17 || bVar2;
  uVar4 = uVar17 - (uVar3 + !bVar21);
  uVar18 = uVar7 * uVar11;
  if (uVar3 < uVar17 || bVar2) {
    bVar22 = uVar18 * 0x80000 <= uVar4;
  }
  uVar4 = uVar4 + uVar18 * -0x80000;
  uVar17 = uVar11 * param_3;
  bVar23 = uVar17 * 8 <= uVar15;
  uVar3 = uVar17 >> 0x1d;
  bVar2 = uVar4 - uVar3 < (uint)bVar23;
  bVar21 = uVar3 < uVar4 || bVar2;
  uVar19 = uVar4 - (uVar3 + !bVar23);
  uVar20 = uVar11 * uVar10;
  if (uVar3 < uVar4 || bVar2) {
    bVar21 = uVar20 * 8 <= uVar19;
  }
  uVar19 = uVar19 + uVar20 * -8;
  uVar9 = uVar14 * 0x400000 + uVar11 * 0x200;
  uVar6 = uVar19 * 0x4000000 | uVar15 + uVar17 * -8 >> 6;
  uVar15 = uVar17 * -0x20000000;
  uVar3 = uVar17 * -0x40000000;
  uVar4 = uVar6 * 2 + (uint)CARRY4(uVar15,uVar15);
  uVar10 = uVar10 | uVar7 << 0x10;
  param_3 = param_3 | uVar8 << 0x10;
  uVar8 = (((uVar16 - ((uVar18 >> 0xd) + (uint)!bVar22)) - ((uVar20 >> 0x1d) + (uint)!bVar21)) *
           0x4000000 | uVar19 >> 6) * 2 +
          (uint)(CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)CARRY4(uVar15,uVar15)));
  bVar2 = uVar8 - uVar10 < (uint)(param_3 <= uVar4);
  uVar7 = uVar8;
  if (uVar10 < uVar8 || bVar2) {
    uVar7 = uVar8 - (uVar10 + (param_3 > uVar4));
    uVar4 = uVar4 - param_3;
  }
  uVar17 = uVar17 * -0x80000000;
  bVar21 = CARRY4(uVar4,uVar4) || CARRY4(uVar4 * 2,(uint)CARRY4(uVar3,uVar3));
  uVar15 = uVar4 * 2 + (uint)CARRY4(uVar3,uVar3);
  bVar22 = CARRY4(uVar7 * 2,(uint)bVar21);
  bVar23 = CARRY4(uVar7,uVar7) || bVar22;
  uVar3 = uVar7 * 2 + (uint)bVar21;
  bVar21 = bVar23 < (uVar10 < uVar3 || uVar3 - uVar10 < (uint)(param_3 <= uVar15));
  if ((CARRY4(uVar7,uVar7) || bVar22) || bVar21) {
    uVar3 = uVar3 - (uVar10 + (param_3 > uVar15));
    uVar15 = uVar15 - param_3;
  }
  bVar24 = CARRY4(uVar15,uVar15) || CARRY4(uVar15 * 2,(uint)CARRY4(uVar17,uVar17));
  uVar7 = uVar15 * 2 + (uint)CARRY4(uVar17,uVar17);
  bVar22 = CARRY4(uVar3 * 2,(uint)bVar24);
  bVar25 = CARRY4(uVar3,uVar3) || bVar22;
  uVar15 = uVar3 * 2 + (uint)bVar24;
  bVar24 = bVar25 < (uVar10 < uVar15 || uVar15 - uVar10 < (uint)(param_3 <= uVar7));
  if ((CARRY4(uVar3,uVar3) || bVar22) || bVar24) {
    uVar15 = uVar15 - (uVar10 + (param_3 > uVar7));
    uVar7 = uVar7 - param_3;
  }
  uVar8 = (((uint)(uVar10 < uVar8 || bVar2) * 2 + (uint)(bVar23 || bVar21)) * 2 +
          (uint)(bVar25 || bVar24)) * 0x200;
  iVar12 = uVar13 * 0x10000 + uVar1 * 8 + (uVar5 >> 0x1a) +
           (uint)CARRY4(uVar14 * 0x400000,uVar11 * 0x200) + (uint)CARRY4(uVar9,uVar8);
  uVar7 = uVar9 + uVar8 | (uint)(uVar15 != 0 || uVar7 != 0);
  if (iVar12 < 0) {
    return CONCAT44(iVar12,uVar7);
  }
  return CONCAT44(iVar12 * 2 + (uint)CARRY4(uVar7,uVar7),uVar7 * 2);
}



ulonglong FUN_00032c68(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = LZCOUNT(param_2) - 7;
  uVar1 = -param_2;
  if ((int)uVar5 < 0) {
    iVar2 = (int)((ulonglong)
                  ((byte)(&LAB_00032e5c)[(param_2 << LZCOUNT(param_2)) >> 0x19] - 4 >>
                  (-uVar5 & 0xff)) * (ulonglong)param_1 >> 0x20);
    param_1 = iVar2 * uVar1 + param_1;
    if (CARRY4(uVar1,param_1 >> 1)) {
      param_1 = param_1 + param_2 * -2;
      iVar2 = iVar2 + 2;
    }
    if (CARRY4(uVar1,param_1)) {
      param_1 = param_1 + uVar1;
      iVar2 = iVar2 + 1;
    }
    return CONCAT44(param_1,iVar2);
  }
  iVar2 = (uint)(byte)(&LAB_00032e5c)[(param_2 << LZCOUNT(param_2)) >> 0x19] << (uVar5 & 0xff);
  uVar4 = (int)((uint6)((int6)iVar2 * (int6)(short)(iVar2 * uVar1 >> 0x10)) >> 0x10) + iVar2;
  if (uVar1 == (int)uVar1 >> 1) {
    if ((bool)((byte)uVar1 & 1)) {
      return (ulonglong)param_1;
    }
    uVar3 = FUN_0005b714(0,uVar4,uVar5);
    return CONCAT44(param_1,uVar3);
  }
  iVar6 = (int)(((longlong)(int)uVar4 * (longlong)(int)(uVar4 * uVar1) + ((ulonglong)uVar4 << 0x20)
                >> 0x20) * (ulonglong)param_1 >> 0x20);
  uVar5 = iVar6 * uVar1 + param_1 + uVar1;
  iVar2 = uVar5 + uVar1;
  if (CARRY4(uVar5,uVar1)) {
    uVar5 = uVar5 + param_2;
  }
  else {
    iVar6 = iVar6 + 1;
  }
  if (-1 < iVar2) {
    uVar5 = uVar5 + param_2 * -2;
    iVar6 = iVar6 + 2;
  }
  return CONCAT44(uVar5,iVar6);
}



undefined8 FUN_00032d20(uint param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_2 & 0x80000000;
  if ((int)uVar7 < 0) {
    param_2 = -param_2;
  }
  bVar2 = (byte)(param_1 >> 0x18);
  iVar1 = (int)param_1 >> 0x20;
  bVar3 = (byte)(uVar7 >> 0x18) ^ (char)bVar2 >> 7;
  if ((bool)(bVar2 >> 7)) {
    param_1 = -param_1;
  }
  uVar6 = LZCOUNT(param_2) - 7;
  uVar7 = -param_2;
  if (-1 < (int)uVar6) {
    iVar4 = (uint)(byte)(&LAB_00032e5c)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] <<
            (uVar6 & 0xff);
    uVar5 = (int)((uint6)((int6)iVar4 * (int6)(short)(iVar4 * uVar7 >> 0x10)) >> 0x10) + iVar4;
    if (uVar7 == (int)uVar7 >> 1) {
      if (!(bool)((byte)uVar7 & 1)) {
        iVar4 = FUN_0005b714(0,uVar5,uVar6);
        if ((bool)(bVar3 >> 7)) {
          iVar4 = -iVar4;
        }
        if (iVar1 << 1 < 0) {
          param_1 = -param_1;
        }
        return CONCAT44(param_1,iVar4);
      }
      uVar6 = 0;
    }
    else {
      uVar5 = (uint)(((longlong)(int)uVar5 * (longlong)(int)(uVar5 * uVar7) +
                      ((ulonglong)uVar5 << 0x20) >> 0x20) * (ulonglong)param_1 >> 0x20);
      uVar6 = uVar5 * uVar7 + param_1 + uVar7;
      iVar4 = uVar6 + uVar7;
      if (CARRY4(uVar6,uVar7)) {
        uVar6 = uVar6 + param_2;
        param_1 = uVar5;
      }
      else {
        param_1 = uVar5 + 1;
      }
      if (-1 < iVar4) {
        uVar6 = uVar6 + param_2 * -2;
        param_1 = param_1 + 2;
      }
    }
    if ((bool)(bVar3 >> 7)) {
      param_1 = -param_1;
    }
    if (iVar1 << 1 < 0) {
      uVar6 = -uVar6;
    }
    return CONCAT44(uVar6,param_1);
  }
  iVar4 = (int)((ulonglong)
                ((byte)(&LAB_00032e5c)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] - 4 >>
                (-uVar6 & 0xff)) * (ulonglong)param_1 >> 0x20);
  param_1 = iVar4 * uVar7 + param_1;
  if (CARRY4(uVar7,param_1 >> 1)) {
    param_1 = param_1 + param_2 * -2;
    iVar4 = iVar4 + 2;
  }
  if (CARRY4(uVar7,param_1)) {
    param_1 = param_1 + uVar7;
    iVar4 = iVar4 + 1;
  }
  if ((bool)(bVar3 >> 7)) {
    iVar4 = -iVar4;
  }
  if (iVar1 << 1 < 0) {
    param_1 = -param_1;
  }
  return CONCAT44(param_1,iVar4);
}



// WARNING: Control flow encountered bad instruction data

void FUN_00032e60(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



int FUN_0003300c(void)

{
  int iVar1;
  
  iVar1 = FUN_0005b838();
  return iVar1 + 0x20;
}



// WARNING: Control flow encountered bad instruction data

void FUN_00033020(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined1 *param_5)

{
  int extraout_r1;
  undefined4 unaff_r7;
  undefined1 *puVar1;
  int in_lr;
  bool in_NG;
  undefined1 in_CY;
  undefined1 in_OV;
  undefined4 in_cr7;
  
  if (in_NG) {
    in_lr = 0x33024;
    func_0x006205e8();
    param_2 = extraout_r1;
  }
  puVar1 = (undefined1 *)0x0;
  if (!(bool)in_OV) {
    puVar1 = param_5;
  }
  if (!(bool)in_CY) {
    if ((bool)in_OV) {
      *(int *)(in_lr + 4) = param_2;
      *(undefined4 *)(in_lr + 8) = param_3;
      *(uint *)(in_lr + 0xc) = param_4 << ((uint)puVar1 & 0xff) & 0x3303c;
      *(undefined4 *)(in_lr + 0x10) = unaff_r7;
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    return;
  }
  coprocessor_store(8,in_cr7,param_2 + -0x270);
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_00033458(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r8;
  undefined4 unaff_r11;
  int in_r12;
  undefined4 in_lr;
  bool in_NG;
  bool in_CY;
  
  if (in_CY) {
    *param_1 = in_lr;
    param_1[-1] = register0x00000054;
    param_1[-2] = in_r12;
    param_1[-3] = unaff_r11;
  }
  if (in_NG) {
    *(undefined4 *)(in_r12 + -4) = 0x33470;
    *(undefined4 *)(in_r12 + -8) = unaff_r8;
    *(undefined4 *)(in_r12 + -0xc) = param_4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_000353c2(undefined4 *param_1)

{
  undefined4 unaff_r4;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  bool in_OV;
  
  if (in_OV) {
    *param_1 = 0x353ca;
    param_1[-1] = register0x00000054;
    param_1[-2] = in_r12;
    param_1[-3] = unaff_r10;
    param_1[-4] = unaff_r8;
    param_1[-5] = unaff_r4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_000362fe(int param_1)

{
  uint unaff_r4;
  undefined4 *unaff_r5;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  bool in_ZR;
  bool in_OV;
  undefined4 in_cr12;
  
  if (in_OV) {
    *unaff_r5 = 0x36306;
    unaff_r5[-1] = register0x00000054;
    unaff_r5[-2] = in_r12;
    unaff_r5[-3] = unaff_r10;
    unaff_r5[-4] = unaff_r8;
    unaff_r5[-5] = unaff_r5;
    unaff_r5[-6] = unaff_r4;
  }
  if (!in_ZR || (unaff_r4 & param_1 << 6) != 0) {
    coprocessor_movefromRt(0,0xd,in_cr12);
    coprocessor_movefromRt2(0,0xd,in_cr12);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x0003c870)
// WARNING: Removing unreachable block (ram,0x0003c88c)
// WARNING: Removing unreachable block (ram,0x0003c890)
// WARNING: Removing unreachable block (ram,0x0003c89c)
// WARNING: Removing unreachable block (ram,0x0003c864)
// WARNING: Removing unreachable block (ram,0x0003c86c)
// WARNING: Type propagation algorithm not settling

undefined4 FUN_0003c84c(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  char in_NG;
  bool in_ZR;
  bool in_OV;
  
  if (in_OV) {
    *param_4 = 0x3c854;
    param_4[-1] = register0x00000054;
    param_4[-2] = in_r12;
    param_4[-3] = unaff_r10;
    param_4[-4] = unaff_r8;
    param_4[-5] = unaff_r5;
    param_4[-6] = unaff_r4;
  }
  if (in_ZR || (bool)in_NG != in_OV) {
    param_3 = param_3 & param_1 << 0x16;
  }
  if (in_OV) {
    return *(undefined4 *)(param_3 - 0x10);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0003dd08(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 *unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r11;
  undefined4 in_lr;
  bool in_CY;
  bool in_OV;
  
  if (in_CY) {
    if (in_OV) {
      *param_2 = in_lr;
      param_2[-1] = register0x00000054;
      param_2[-2] = unaff_r11;
      param_2[-3] = unaff_r7;
      param_2[-4] = unaff_r5;
      param_2[-5] = param_4;
      *unaff_r8 = param_4;
      unaff_r8[1] = unaff_r6;
      unaff_r8[2] = unaff_r7;
      unaff_r8[3] = unaff_r9;
      unaff_r8[4] = register0x00000054;
      unaff_r8[5] = in_lr;
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x0003fec8)
// WARNING: Removing unreachable block (ram,0x0003fed0)

void FUN_0003fea0(int param_1,uint param_2)

{
  undefined4 unaff_r8;
  bool in_NG;
  undefined1 in_ZR;
  undefined1 in_CY;
  bool in_OV;
  bool bVar1;
  bool bVar2;
  undefined4 in_cr0;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr8;
  undefined4 in_cr10;
  undefined4 in_cr15;
  
  if (in_NG) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  bVar1 = false;
  bVar2 = false;
  if (in_OV) {
    in_CY = CARRY4(param_2,param_2 * 0x40000);
    bVar2 = SCARRY4(param_2,param_2 * 0x40000);
    bVar1 = (int)(param_2 * 0x40001) < 0;
    in_ZR = param_2 * 0x40001 == 0;
  }
  if (!(bool)in_CY) {
    *(int *)(param_2 - 4) = param_1;
  }
  if ((bool)in_ZR) {
    coprocessor_function(6,0,0,in_cr0,in_cr0,in_cr8);
  }
  coprocessor_function2(7,7,7,in_cr15,in_cr10,in_cr7);
  if (bVar1) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  if ((bool)in_CY) {
    *(BADSPACEBASE **)param_1 = register0x00000054;
    *(undefined4 *)(param_1 + -4) = unaff_r8;
    *(int *)(param_1 + -8) = param_1;
    param_1 = param_1 + -0xc;
  }
  if (bVar2) {
    coprocessor_load(2,in_cr6,param_1 + -0x44);
    coprocessor_load(2,in_cr6,param_1 + -0x144);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0004076c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 *unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 in_r12;
  bool in_ZR;
  bool in_OV;
  
  if (!in_OV) {
    if (in_ZR) {
      *(undefined4 *)(param_2 + -4) = param_4;
      *(undefined4 *)(param_2 + -8) = param_3;
      *(undefined4 *)(param_2 + -0xc) = param_1;
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  *unaff_r6 = 0x40774;
  unaff_r6[-1] = register0x00000054;
  unaff_r6[-2] = in_r12;
  unaff_r6[-3] = unaff_r10;
  unaff_r6[-4] = unaff_r8;
  unaff_r6[-5] = unaff_r7;
  unaff_r6[-6] = unaff_r6;
  unaff_r6[-7] = unaff_r5;
  unaff_r6[-8] = unaff_r4;
  unaff_r6[-9] = param_4;
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



uint FUN_00042348(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint uVar2;
  byte *pbVar3;
  uint *puVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  
  if (((uint)param_1 & 3) != 0 || ((uint)param_2 & 3) != 0) {
    do {
      pbVar3 = (byte *)((int)param_1 + 1);
      uVar6 = (uint)(byte)*param_1;
      pbVar5 = (byte *)((int)param_2 + 1);
      uVar7 = (uint)(byte)*param_2;
      bVar11 = uVar6 == 1;
      if (uVar6 != 0) {
        bVar11 = uVar6 == uVar7;
      }
      if (!bVar11) break;
      param_1 = (uint *)((int)param_1 + 2);
      uVar6 = (uint)*pbVar3;
      param_2 = (uint *)((int)param_2 + 2);
      uVar7 = (uint)*pbVar5;
      bVar11 = uVar6 == 1;
      if (uVar6 != 0) {
        bVar11 = uVar6 == uVar7;
      }
    } while (bVar11);
    return uVar6 - uVar7;
  }
  do {
    puVar1 = param_1 + 1;
    uVar6 = *param_1;
    puVar4 = param_2 + 1;
    uVar7 = *param_2;
    uVar8 = uVar6 - DAT_000423d0 & ~uVar6 & DAT_000423d0 << 7;
    if (uVar8 != 0 || uVar6 != uVar7) break;
    param_1 = param_1 + 2;
    uVar6 = *puVar1;
    param_2 = param_2 + 2;
    uVar7 = *puVar4;
    uVar8 = uVar6 - DAT_000423d0 & ~uVar6 & DAT_000423d0 << 7;
  } while (uVar8 == 0 && uVar6 == uVar7);
  uVar2 = uVar7 * 0x1000000 + uVar6 * -0x1000000;
  bVar9 = uVar2 == 0;
  bVar12 = !bVar9 && uVar6 * 0x1000000 <= uVar7 * 0x1000000;
  bVar10 = (uVar8 & 0xff0) == 0;
  bVar11 = bVar9 && bVar10;
  if (bVar9 && bVar10) {
    uVar2 = uVar7 * 0x10000 + uVar6 * -0x10000;
    bVar9 = uVar2 == 0;
    bVar12 = !bVar9 && uVar6 * 0x10000 <= uVar7 * 0x10000;
    bVar10 = (uVar8 & 0xff00) == 0;
    bVar11 = bVar9 && bVar10;
    if (bVar9 && bVar10) {
      uVar2 = uVar7 * 0x100 + uVar6 * -0x100;
      bVar9 = uVar2 == 0;
      bVar12 = !bVar9 && uVar6 * 0x100 <= uVar7 * 0x100;
      bVar10 = (uVar8 & 0xff0000) == 0;
      bVar11 = bVar9 && bVar10;
      if (bVar9 && bVar10) {
        bVar12 = uVar6 <= uVar7;
        uVar2 = uVar7 - uVar6;
        bVar11 = uVar2 == 0;
      }
    }
  }
  if (!bVar11) {
    uVar2 = (uint)bVar12 << 0x1f | uVar2 >> 1;
  }
  return uVar2;
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00045720)

void FUN_00045710(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  bool in_NG;
  bool in_OV;
  undefined4 in_cr0;
  undefined4 in_cr6;
  
  if (in_NG) {
    return;
  }
  if (in_OV) {
    *(int *)param_3 = param_3;
    *(undefined4 *)(param_3 + 4) = unaff_r8;
    *(undefined4 *)(param_3 + 8) = unaff_r10;
    *(undefined4 *)(param_3 + 0xc) = unaff_r11;
    *(undefined4 *)(param_3 + 0x10) = in_r12;
    coprocessor_function(9,10,0,in_cr6,in_cr6,in_cr0);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00046d92)
// WARNING: Removing unreachable block (ram,0x00046d7a)
// WARNING: Removing unreachable block (ram,0x00046d86)
// WARNING: Removing unreachable block (ram,0x00046d9a)

void FUN_00046d6e(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint unaff_r4;
  uint unaff_r5;
  undefined *unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  uint uVar2;
  uint uVar3;
  undefined4 *unaff_r10;
  int unaff_r11;
  int in_r12;
  undefined4 uVar4;
  undefined4 in_lr;
  bool in_NG;
  bool in_ZR;
  byte in_CY;
  bool in_OV;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr6;
  
  if (in_OV) {
    *unaff_r10 = 0x46d76;
    unaff_r10[-1] = register0x00000054;
    unaff_r10[-2] = in_r12;
    unaff_r10[-3] = unaff_r10;
    unaff_r10[-4] = unaff_r8;
    unaff_r10[-5] = unaff_r5;
    unaff_r10[-6] = unaff_r4;
  }
  if (!in_ZR) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  uVar4 = *(undefined4 *)param_3;
  uVar3 = *(uint *)(param_3 - 4);
  uVar2 = *(uint *)(param_3 - 8);
  uVar1 = unaff_r4 & (int)param_1 << (param_3 & 0xff);
  if (in_NG) {
    unaff_r6 = &DAT_00150000 + in_CY + unaff_r5;
  }
  bVar7 = true;
  bVar5 = false;
  if (in_NG) {
    in_CY = 0xfffffffe < uVar2;
    in_OV = SCARRY4(uVar2,1);
    uVar1 = uVar2 + 1;
    bVar5 = (int)uVar1 < 0;
    bVar7 = uVar1 == 0;
  }
  if (!in_OV) {
    if ((bool)in_CY) {
      *param_1 = in_lr;
      param_1[-1] = uVar4;
      param_1[-2] = unaff_r11;
      param_1[-3] = unaff_r7;
      param_1[-4] = unaff_r6;
      param_1[-5] = unaff_r4;
    }
    bVar8 = false;
    bVar6 = false;
    if (bVar5) {
      param_1 = param_1 + -0xd1;
      coprocessor_load(0,in_cr6,param_1);
      uVar2 = (int)param_1 << (unaff_r5 & 0xff);
      in_CY = CARRY4(param_3,uVar2);
      bVar8 = SCARRY4(param_3,uVar2);
      unaff_r11 = param_3 + uVar2;
      bVar6 = unaff_r11 < 0;
      bVar7 = unaff_r11 == 0;
    }
    if (bVar6 == bVar8) {
      if (!bVar7 && bVar6 == bVar8) {
        coprocessor_function(4,3,1,in_cr1,in_cr6,in_cr6);
      }
      if (bVar6 != bVar8) {
        if (!bVar7) {
          if (bVar6 != bVar8) {
            coprocessor_load(0xb,in_cr0,0x246cf2);
          }
                    // WARNING: Bad instruction - Truncating control flow here
          halt_baddata();
        }
                    // WARNING: Bad instruction - Truncating control flow here
        halt_baddata();
      }
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    if (!(bool)in_CY || bVar7) {
      unaff_r10 = (undefined4 *)((uint)unaff_r6 & 0x24000);
    }
    if (bVar7) {
      uVar3 = uVar1 & unaff_r5 << 2;
    }
    if (bVar6 == bVar8) {
      *unaff_r10 = 0x46dba;
      unaff_r10[-1] = uVar4;
      unaff_r10[-2] = unaff_r11;
      unaff_r10[-3] = uVar3;
      unaff_r10[-4] = uVar1;
      unaff_r10[-5] = param_2;
      unaff_r10[-6] = param_1;
      *(undefined4 *)(in_r12 + -4) = 0x46dbe;
      *(int *)(in_r12 + -8) = in_r12;
      *(uint *)(in_r12 + -0xc) = uVar3;
      *(undefined4 *)(in_r12 + -0x10) = param_2;
      *(undefined4 **)(in_r12 + -0x14) = param_1;
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_0004892c(void)

{
  bool in_OV;
  
  if (!in_OV) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00048d68(void)

{
  undefined4 in_r3;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  undefined4 *in_r12;
  bool in_OV;
  
  if (in_OV) {
    *in_r12 = 0x48d70;
    in_r12[-1] = register0x00000054;
    in_r12[-2] = in_r12;
    in_r12[-3] = unaff_r10;
    in_r12[-4] = unaff_r8;
    in_r12[-5] = unaff_r7;
    in_r12[-6] = unaff_r6;
    in_r12[-7] = unaff_r5;
    in_r12[-8] = unaff_r4;
    in_r12[-9] = in_r3;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0004a9f2(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *unaff_r4;
  uint unaff_r5;
  uint unaff_r6;
  undefined4 *unaff_r7;
  int unaff_r8;
  uint unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  char in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  bool bVar1;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr9;
  undefined4 in_cr11;
  undefined4 in_cr13;
  
  if (in_OV) {
    *unaff_r4 = 0x4a9fa;
    unaff_r4[-1] = register0x00000054;
    unaff_r4[-2] = in_r12;
    unaff_r4[-3] = unaff_r10;
    unaff_r4[-4] = unaff_r8;
    unaff_r4[-5] = unaff_r7;
    unaff_r4[-6] = unaff_r6;
    unaff_r4[-7] = unaff_r5;
    unaff_r4[-8] = unaff_r4;
    unaff_r4[-9] = param_4;
    unaff_r4[-10] = param_3;
    unaff_r4[-0xb] = param_2;
    unaff_r4[-0xc] = param_1;
  }
  bVar1 = false;
  if (in_ZR) {
    param_1 = (undefined4 *)(unaff_r6 & unaff_r5);
    in_NG = (int)param_1 < 0;
    bVar1 = param_1 == (undefined4 *)0x0;
  }
  if ((bool)in_NG != in_OV) {
    param_3 = param_2;
  }
  if (in_CY) {
    coprocessor_function(0,0,0,in_cr13,in_cr0,in_cr7);
  }
  if (in_CY && !bVar1) {
    if (bVar1) {
      unaff_r9 = (uint)param_1 ^ param_3 << 0x12;
    }
    if (in_CY) {
      *param_1 = in_lr;
      param_1[-1] = unaff_r10;
      param_1[-2] = unaff_r9;
      param_1[-3] = unaff_r8;
      param_1[-4] = unaff_r7;
      param_1[-5] = unaff_r5;
      param_1[-6] = unaff_r4;
      register0x00000054 = (BADSPACEBASE *)((uint)param_1 & param_3 << 0x1a);
    }
    if ((bool)in_NG != in_OV) {
      param_1 = param_1 + 5;
      coprocessor_loadlong(0,in_cr11,param_1);
    }
    if (in_OV) {
      *unaff_r7 = in_lr;
      unaff_r7[-1] = register0x00000054;
      unaff_r7[-2] = unaff_r11;
      unaff_r7[-3] = unaff_r5;
      unaff_r7[-4] = param_4;
    }
    if (!in_CY || bVar1) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    if (bVar1) {
      unaff_r9 = (uint)param_1 ^ param_3 << 0x12;
    }
    if (in_CY) {
      *param_1 = in_lr;
      param_1[-1] = unaff_r10;
      param_1[-2] = unaff_r9;
      param_1[-3] = unaff_r8;
      param_1[-4] = unaff_r7;
      param_1[-5] = unaff_r5;
      param_1[-6] = unaff_r4;
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  if (bVar1 || (bool)in_NG != in_OV) {
    coprocessor_loadlong(0xe,in_cr9,unaff_r8 + -0x1e4);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0004e380(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *unaff_r4;
  undefined4 unaff_r8;
  undefined4 unaff_r11;
  undefined4 in_r12;
  undefined4 in_lr;
  bool in_NG;
  bool in_ZR;
  bool in_CY;
  char in_OV;
  
  if (in_NG != (bool)in_OV) {
    unaff_r4 = *(undefined4 **)(param_1 + -0x806);
  }
  if (in_CY) {
    *param_2 = in_lr;
    param_2[-1] = register0x00000054;
    param_2[-2] = unaff_r11;
  }
  if (in_NG) {
    *unaff_r4 = 0x4e390;
    unaff_r4[-1] = in_lr;
    unaff_r4[-2] = in_r12;
    unaff_r4[-3] = unaff_r8;
    unaff_r4[-4] = param_3;
    unaff_r4[-5] = param_2;
  }
  if (!in_ZR) {
    software_interrupt(0x2200);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x0017d2d0)
// WARNING: Removing unreachable block (ram,0x0017d2d4)
// WARNING: Removing unreachable block (ram,0x0017d2d8)
// WARNING: Removing unreachable block (ram,0x0017d2dc)
// WARNING: Removing unreachable block (ram,0x0017d2e0)
// WARNING: Removing unreachable block (ram,0x0017d2e4)
// WARNING: Removing unreachable block (ram,0x0017d2e8)

void FUN_0004fe74(int param_1)

{
  int *in_r12;
  char in_NG;
  bool in_ZR;
  bool in_CY;
  bool in_OV;
  undefined4 in_cr5;
  
  if (in_CY && !in_ZR) {
    param_1 = *in_r12;
  }
  if (in_OV) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  if (in_NG != '\0') {
    coprocessor_load(2,in_cr5,param_1 + -0x28);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00051608(undefined4 param_1,undefined4 *param_2)

{
  uint unaff_r8;
  uint unaff_r9;
  bool in_NG;
  
  if (!in_NG) {
    if ((unaff_r9 & unaff_r8) == 0) {
      *param_2 = param_1;
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_00052082(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_000523f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *unaff_r5;
  undefined4 *unaff_r6;
  byte *unaff_r8;
  byte *pbVar1;
  byte unaff_r9;
  undefined4 in_r12;
  bool in_NG;
  bool in_ZR;
  bool in_CY;
  char in_OV;
  
  if (!in_CY || in_ZR) {
    unaff_r9 = (byte)param_3 & (byte)param_1;
  }
  if (in_NG) {
    param_3 = param_1;
  }
  if (in_CY) {
    unaff_r9 = (byte)param_1 & (byte)param_2;
  }
  pbVar1 = unaff_r8;
  if (in_NG) {
    *unaff_r6 = 0x52410;
    unaff_r6[-1] = in_r12;
    unaff_r6[-2] = param_2;
    unaff_r6[-3] = param_1;
    pbVar1 = unaff_r8 + -0x204;
    unaff_r9 = *unaff_r8;
    *unaff_r5 = 0x52418;
    unaff_r5[-1] = in_r12;
    unaff_r5[-2] = param_4;
    unaff_r5[-3] = param_2;
  }
  if (in_NG == (bool)in_OV) {
    if (!in_CY) {
      FUN_00333524(param_1,param_2,param_3);
    }
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  if (in_NG) {
    *pbVar1 = unaff_r9;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_000537a4(uint param_1)

{
  uint unaff_r4;
  bool in_ZR;
  bool in_CY;
  
  if (in_ZR) {
    param_1 = (uint)&stack0x00000000 & unaff_r4;
  }
  if (!in_CY || in_ZR) {
    FUN_002d3814(param_1);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00053da4(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00054092(void)

{
  uint unaff_r4;
  uint unaff_r8;
  bool in_ZR;
  bool in_CY;
  
  if (!in_CY || in_ZR && (unaff_r8 & unaff_r4) == 0) {
    FUN_002d40fa();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0005461e(void)

{
  uint unaff_r4;
  uint unaff_r8;
  bool in_ZR;
  bool in_CY;
  
  if (!in_CY || in_ZR && (unaff_r8 & unaff_r4) == 0) {
    FUN_002d4686();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_000553d4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *unaff_r6;
  int unaff_r8;
  uint unaff_r9;
  undefined4 in_r12;
  char in_NG;
  undefined1 in_ZR;
  char in_OV;
  
  if (in_NG != in_OV) {
    in_NG = param_2 + 0x154f7000 < 0;
    in_ZR = param_2 == -0x154f7000;
  }
  if ((bool)in_ZR) {
    in_NG = (int)(unaff_r9 & unaff_r8 << 0x10) < 0;
  }
  if ((bool)in_NG) {
    *unaff_r6 = 0x553f0;
    unaff_r6[-1] = in_r12;
    unaff_r6[-2] = param_4;
    unaff_r6[-3] = param_3;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00058100(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00058360(int param_1)

{
  bool in_NG;
  char in_OV;
  undefined4 in_cr4;
  
  if (in_NG) {
    in_OV = SCARRY4(param_1,0x120000);
  }
  if ((in_NG && (int)(&DAT_00120000 + param_1) < 0) != (bool)in_OV) {
    coprocessor_load(3,in_cr4,param_1 + -0x300);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_000586d4(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



uint FUN_0005b640(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  puVar1 = DAT_0005b70c;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = 0;
  puVar2 = (uint *)(param_1 + (uint)*(ushort *)(param_1 + 4) * 0x10 + 0x10);
  while (puVar2 = (uint *)(puVar2[1] & 0xfffffffe), puVar2 != *(uint **)(param_1 + 0x14)) {
    if ((*puVar2 & 1) == 0) {
      uVar4 = ((puVar2[1] & 0xfffffffe) - (int)puVar2) - 8;
      if (uVar5 < uVar4) {
        uVar5 = uVar4;
      }
      uVar6 = uVar6 + uVar4;
      if ((uint)LZCOUNT(uVar4) < 0x1b) {
        uVar4 = 0x1b - LZCOUNT(uVar4);
      }
      else {
        uVar4 = 0;
      }
      uVar7 = uVar7 + (1 << ((uVar4 & 0x7f) << 1));
    }
  }
  if (uVar5 < DAT_0005b70c[3]) {
    DAT_0005b70c[3] = uVar5;
  }
  iVar3 = FUN_00032c68(uVar5 * 100,uVar6);
  puVar2 = DAT_0005b710;
  if (*puVar1 < 100U - iVar3) {
    *puVar1 = 100U - iVar3;
    puVar1[1] = uVar6;
    puVar2 = DAT_0005b710;
    puVar1[2] = uVar5;
  }
  if (uVar7 < *puVar2) {
    puVar2[2] = uVar5;
    puVar2[1] = uVar6;
    *puVar2 = uVar7;
  }
  return uVar6;
}



// WARNING: Control flow encountered bad instruction data

void FUN_0005b714(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 unaff_r4;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  bool in_NG;
  
  if (in_NG) {
    *param_3 = 0x2e5dc;
    param_3[-1] = register0x00000054;
    param_3[-2] = 0x2e5d5;
    param_3[-3] = unaff_r10;
    param_3[-4] = unaff_r8;
    param_3[-5] = unaff_r4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



undefined4 FUN_0005b838(void)

{
  return DAT_0005b840;
}



int FUN_0005b84c(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&
     (iVar1 = FUN_00042348(DAT_0005b894 + 0x5b870), iVar1 != 0)) {
    return 0;
  }
  return DAT_0005b898 + 0x5b890;
}



int FUN_0005b8a0(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&
     (iVar1 = FUN_00042348(DAT_0005b8e8 + 0x5b8c4), iVar1 != 0)) {
    return 0;
  }
  return DAT_0005b8ec + 0x5b8e4;
}



int FUN_0005b8f4(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&
     (iVar1 = FUN_00042348(DAT_0005b93c + 0x5b918), iVar1 != 0)) {
    return 0;
  }
  return DAT_0005b940 + 0x5b938;
}



// WARNING: Control flow encountered bad instruction data

void FUN_0005d608(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 unaff_r4;
  undefined4 unaff_r8;
  undefined4 unaff_r10;
  bool in_NG;
  
  if (in_NG) {
    *param_3 = 0x2e5dc;
    param_3[-1] = register0x00000054;
    param_3[-2] = 0x2e5d5;
    param_3[-3] = unaff_r10;
    param_3[-4] = unaff_r8;
    param_3[-5] = unaff_r4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0005d60c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  if (param_1 == 0) {
    FUN_00032e60(0x820,1,param_3,param_4,param_3,param_4);
  }
  if ((uint)LZCOUNT(param_1 + -1) < 0x1b) {
    uVar1 = 0x1b - LZCOUNT(param_1 + -1);
  }
  else {
    uVar1 = 0;
  }
  if (7 < uVar1) {
    FUN_00032e60(DAT_0005d680,param_1);
  }
  if (*(int *)(DAT_0005d684 + uVar1 * 0x10) == 0) {
    FUN_00032e60(DAT_0005d688,param_1);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



void FUN_0005d6fc(undefined4 *param_1,code *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  bool bVar5;
  
  bVar5 = 3 < param_3;
  bVar4 = param_3 - 4 == 0;
  if (bVar5 && !bVar4) {
    puVar3 = param_4 + 4;
    puVar1 = param_1 + -(param_3 - 4);
    do {
      puVar2 = puVar1;
      if (bVar5 && !bVar4) {
        puVar2 = puVar1 + 1;
        *puVar1 = *puVar3;
        puVar3 = puVar3 + 1;
      }
      bVar5 = puVar2 <= param_1;
      bVar4 = param_1 == puVar2;
      puVar1 = puVar2;
    } while (bVar5 && !bVar4);
  }
  (*param_2)(*param_4,param_4[1],param_4[2],param_4[3]);
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_0005d75c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = 0;
  if (iVar1 != 0) {
    return;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_0005d7a0(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



int FUN_0005dc90(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&
     (iVar1 = FUN_00042348(DAT_0005dcd8 + 0x5dcb4), iVar1 != 0)) {
    return 0;
  }
  return DAT_0005dcdc + 0x5dcd4;
}



void FUN_0005ddcc(int *param_1,int *param_2)

{
  if ((param_1[1] & ~(*param_1 << 1)) < 0 && (param_2[1] & ~(*param_2 << 1)) < 0) {
    FUN_0005e410(*param_1,param_1[1],param_1[2]);
    FUN_0005e334();
  }
  return;
}



void FUN_0005de00(uint *param_1,uint *param_2)

{
  if ((*param_1 & 0x40000000) == 0 && (*param_2 & 0x40000000) == 0) {
    FUN_0005e75c(*param_1,param_1[1],param_1[2]);
    FUN_0005e334();
  }
  return;
}



uint FUN_0005de34(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    uVar1 = 4;
  }
  if ((param_2 << 1) >> 0x15 != 0) {
    uVar1 = uVar1 | 1;
  }
  if (DAT_0005de60 == (param_2 << 1) >> 0x15) {
    uVar1 = uVar1 | 2;
  }
  if (uVar1 == 1) {
    uVar1 = 5;
  }
  return uVar1;
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031714)
// WARNING: Restarted to delay deadcode elimination for space: stack

undefined8 FUN_0005deb8(uint param_1,uint param_2)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_r4;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  
  iVar6 = DAT_0005df18 - ((uint)(param_1 != 0) | param_2 & 0x7fffffff);
  bVar14 = (bool)((byte)((uint)iVar6 >> 0x1e) & 1);
  if ((-1 < iVar6) && (FUN_00031d0c(), !bVar14)) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  if ((param_2 & 0x7ff00000) == 0) {
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return CONCAT44(param_2,param_1);
    }
    if (-1 < (int)param_2) {
      iVar6 = 1;
      uVar3 = 0;
      if (param_2 == 0 && param_1 >> 0xc == 0) {
        param_1 = param_1 << 0x14;
        iVar6 = -0x13;
      }
      uVar13 = param_1;
      if (param_2 == 0) {
        param_2 = param_1 >> 0xc;
        uVar13 = param_1 << 0x14;
        iVar6 = iVar6 + -0x14;
      }
      if (param_2 >> 5 == 0) {
        param_2 = param_2 << 0x10;
        uVar3 = 0x10;
      }
      if (param_2 >> 0xd == 0) {
        param_2 = param_2 << 8;
        uVar3 = uVar3 + 8;
      }
      if (param_2 >> 0x11 == 0) {
        param_2 = param_2 << 4;
        uVar3 = uVar3 + 4;
      }
      if (param_2 >> 0x13 == 0) {
        param_2 = param_2 << 2;
        uVar3 = uVar3 + 2;
      }
      bVar14 = param_2 >> 0x14 == 0;
      if (bVar14) {
        uVar3 = uVar3 + 1;
      }
      uVar12 = iVar6 - uVar3;
      param_1 = uVar13 << (uVar3 & 0xff);
      if (bVar14) {
        param_2 = param_2 << 1;
      }
      param_2 = param_2 | uVar13 >> (0x20 - uVar3 & 0xff);
LAB_0005dffc:
      if ((bool)((byte)(uVar12 + 0xfd) & 1)) {
        iVar6 = (int)param_1 >> 0x1f;
        param_1 = param_1 << 1;
        param_2 = param_2 * 2 - iVar6;
      }
      uVar8 = 0;
      uVar7 = 0x40000000;
      uVar3 = param_1 << 10;
      uVar5 = (param_2 << 10 | param_1 >> 0x16) + 0xc0000000;
      uVar13 = 0x10000000;
      do {
        uVar9 = uVar5 - uVar7;
        uVar10 = uVar9;
        if (uVar7 <= uVar5) {
          uVar10 = uVar9 - uVar13;
        }
        if (uVar7 <= uVar5 && uVar13 <= uVar9) {
          uVar7 = uVar7 + uVar13 * 2;
          uVar5 = uVar10;
        }
        iVar6 = (int)uVar3 >> 0x1f;
        uVar3 = uVar3 * 2;
        uVar5 = uVar5 * 2 - iVar6;
        bVar14 = (bool)((byte)uVar13 & 1);
        uVar13 = uVar13 >> 1;
      } while (uVar13 != 0);
      uVar10 = uVar5 - (uVar7 + !bVar14);
      uVar13 = uVar3;
      if (uVar7 < uVar5 || uVar5 - uVar7 < (uint)bVar14) {
        if (uVar10 != 0 || uVar10 < (0x7fffffff < uVar3)) {
          uVar7 = uVar7 + 1;
          uVar13 = uVar3 + 0x80000000;
          uVar5 = uVar10 - (0x7fffffff >= uVar3);
        }
      }
      uVar10 = 0x40000000;
      uVar3 = uVar13 << 1;
      uVar13 = uVar5 * 2 - ((int)uVar13 >> 0x1f);
      do {
        uVar11 = uVar3 - uVar8;
        uVar9 = uVar13 - (uVar7 + (uVar8 > uVar3));
        uVar5 = uVar3;
        if (uVar7 < uVar13 || uVar13 - uVar7 < (uint)(uVar8 <= uVar3)) {
          if (uVar9 != 0 || uVar9 < (uVar10 <= uVar11)) {
            uVar8 = uVar8 + uVar10 * 2;
            uVar5 = uVar11 - uVar10;
            uVar13 = uVar9 - (uVar10 > uVar11);
          }
        }
        uVar10 = uVar10 >> 1;
        uVar3 = uVar5 << 1;
        uVar13 = uVar13 * 2 - ((int)uVar5 >> 0x1f);
      } while (uVar10 != 0x80);
      uVar5 = 0;
      if (uVar13 != 0 || uVar3 != 0) {
        uVar5 = 2;
      }
      uVar3 = (uint)((byte)(uVar8 >> 9) & 1) << 0x1f | uVar5 >> 1;
      uVar13 = uVar3;
      if (uVar3 == 0) {
        uVar13 = unaff_r4;
      }
      uVar5 = uVar8 >> 10 | uVar7 << 0x16;
      iVar6 = (uVar7 >> 10) + ((uVar12 + 0xfd >> 1) + 0x180) * 0x100000;
      if (uVar3 != 0) {
        bVar1 = (byte)(uVar13 >> 0x1f);
        uVar3 = uVar5 + bVar1;
        if ((uVar13 & 0x7fffffff) == 0) {
          uVar3 = uVar3 & 0xfffffffe;
        }
        return CONCAT44(iVar6 + (uint)CARRY4(uVar5,(uint)bVar1),uVar3);
      }
      return CONCAT44(iVar6,uVar5);
    }
  }
  else if ((~param_2 & 0x7ff00000) == 0) {
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      if (-1 < (int)param_2) {
        return CONCAT44(param_2,param_1);
      }
    }
    else if (((param_2 & 0x80000) != 0) && ((DAT_0005e1b8 & 0x4f) != 0x48)) {
      uVar3 = DAT_0005e1b8 & 0xf;
      if (uVar3 == 9) {
        if ((DAT_0005e1b8 & 0x100000) == 0) {
          return CONCAT44(param_2,(uint)((DAT_0005e1b8 & 0x80000) != 0));
        }
        if ((DAT_0005e1b8 & 0x70000) == 0) {
                    // WARNING: Bad instruction - Truncating control flow here
          halt_baddata();
        }
        return CONCAT44(~(DAT_0005e1b8 << 0xf) << 1,8);
      }
      if (uVar3 == 10) {
        if ((DAT_0005e1b8 & 0x40) != 0) {
          param_1 = 0x80000000;
        }
        return CONCAT44(param_2,param_1);
      }
      if (uVar3 == 8) {
        if ((DAT_0005e1b8 & 0x40) == 0) {
          if ((DAT_0005e1b8 & 0x10) == 0) {
            return CONCAT44(param_2,param_2 & 0xff000000 |
                                    param_1 >> 0x1d | (param_2 & 0xffffff) << 3);
          }
          return CONCAT44(param_1 & 0xff000000 | (param_1 & 0xfffffff) >> 3,
                          (param_1 & 0xfffffff) << 0x1d);
        }
        if ((DAT_0005e1b8 & 0x10000) != 0) {
          return 0;
        }
        if ((DAT_0005e1b8 & 0x20) != 0) {
          if ((DAT_0005e1b8 & 0x10) != 0) {
            param_1 = param_2;
          }
          uVar2 = 0xffffffff;
          uVar4 = 0xffffffff;
          if ((param_1 & 0x80000000) != 0) {
            uVar2 = 0;
            uVar4 = 0;
          }
          return CONCAT44(uVar4,uVar2);
        }
        if ((DAT_0005e1b8 & 0x10) == 0) {
          uVar13 = 0x7fffffff;
          uVar3 = param_2;
          param_2 = param_1;
        }
        else {
          uVar3 = 0x7fffffff;
          uVar13 = 0xffffffff;
        }
        if ((param_2 & 0x80000000) != 0) {
          uVar13 = ~uVar13;
          uVar3 = ~uVar3;
        }
        return CONCAT44(uVar3,uVar13);
      }
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((param_2 & 0x80000000) == 0) {
    uVar12 = param_2 >> 0x14;
    param_2 = param_2 & ~(uVar12 << 0x14) | 0x100000;
    goto LAB_0005dffc;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



undefined8 FUN_0005e334(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint unaff_r6;
  int unaff_r11;
  bool bVar3;
  bool bVar4;
  
  uVar2 = param_4;
  if ((int)param_4 < 0) {
    unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
    if ((int)param_4 < -0x3f) {
      uVar1 = unaff_r6 | param_3;
      uVar2 = 0;
      param_3 = 0;
      unaff_r6 = (uVar1 | uVar1 << 0x10) >> 0x10 | param_2;
      param_2 = 0;
      if ((int)param_4 < -0x40) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
      }
    }
    else {
      if ((int)param_4 < -0x1f) {
        unaff_r6 = unaff_r6 | param_3;
        param_4 = param_4 + 0x20;
        param_2 = 0;
        param_3 = param_2;
      }
      uVar1 = -param_4;
      uVar2 = 0;
      if (uVar1 != 0) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10 | param_3 << (param_4 + 0x20 & 0xff);
        param_3 = param_3 >> (uVar1 & 0xff) | param_2 << (param_4 + 0x20 & 0xff);
        param_2 = param_2 >> (uVar1 & 0xff);
        uVar2 = 0;
      }
    }
  }
  bVar4 = SUB41(unaff_r6 >> 0x1f,0);
  if ((unaff_r6 & 0x7fffffff) == 0) {
    if (!bVar4) goto LAB_0005e380;
    bVar4 = (bool)((byte)param_3 & 1);
  }
  FUN_00031cd0(0x10,0x10);
  bVar3 = unaff_r11 != -1;
  if (unaff_r11 == 0) {
    bVar3 = SUB41(((uint)bVar4 << 0x1f) >> 0x1f,0);
  }
  bVar3 = bVar3 && 0xfffffffe < param_3;
  uVar1 = param_2;
  if (bVar3) {
    uVar1 = param_2 + 1;
  }
  bVar3 = bVar3 && 0xfffffffe < param_2;
  if (bVar3) {
    uVar1 = 0x80000000;
  }
  uVar2 = uVar2 + bVar3;
  param_2 = uVar1;
LAB_0005e380:
  return CONCAT44(param_2,uVar2 | param_1 & 0x80000000);
}



// WARNING: Restarted to delay deadcode elimination for space: stack

ulonglong FUN_0005e410(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  
  uVar10 = unaff_r4 >> 0x10;
  uVar9 = unaff_r5 >> 0x10;
  uVar12 = (uint)*(byte *)((unaff_r4 >> 0x18) + 0x5e65c);
  uVar23 = unaff_r5 & ~(uVar9 << 0x10);
  uVar19 = unaff_r4 & ~(uVar10 << 0x10);
  uVar1 = (uint)((byte)param_2 & 1) << 0x1f | param_3 >> 1;
  if ((bool)((byte)param_3 & 1)) {
    uVar3 = 0x80000000;
  }
  else {
    uVar3 = 0;
  }
  iVar13 = ((0x800000 - (uVar10 * uVar12 + uVar12)) * uVar12 >> 0x13) + 2;
  uVar20 = 0x20000000 - ((unaff_r4 >> 0xd) * iVar13 + iVar13);
  uVar12 = uVar20 >> 0x10;
  uVar22 = uVar12 * iVar13 + ((uVar20 & ~(uVar12 << 0x10)) * iVar13 >> 0x10) >> 6;
  uVar12 = uVar22 * (param_2 >> 0x10) >> 0x10;
  uVar4 = uVar1 - uVar12 * uVar9;
  uVar20 = uVar12 * uVar23;
  bVar24 = uVar20 * 0x10000 <= uVar3;
  uVar3 = uVar3 + uVar20 * -0x10000;
  uVar20 = uVar20 >> 0x10;
  bVar2 = uVar4 - uVar20 < (uint)bVar24;
  bVar25 = uVar20 < uVar4 || bVar2;
  uVar5 = uVar4 - (uVar20 + !bVar24);
  uVar14 = uVar12 * uVar19;
  if (uVar20 < uVar4 || bVar2) {
    bVar25 = uVar14 * 0x10000 <= uVar5;
  }
  uVar5 = uVar5 + uVar14 * -0x10000;
  uVar4 = ((param_2 >> 1) - (uVar10 * uVar12 + (uint)(uVar1 < uVar12 * uVar9))) -
          ((uVar14 >> 0x10) + (uint)!bVar25);
  uVar1 = uVar22 * (uVar4 >> 2) >> 0x10;
  uVar20 = uVar1 * uVar9;
  bVar24 = uVar20 * 0x80000 <= uVar3;
  uVar3 = uVar3 + uVar20 * -0x80000;
  uVar20 = uVar20 >> 0xd;
  bVar2 = uVar5 - uVar20 < (uint)bVar24;
  bVar25 = uVar20 < uVar5 || bVar2;
  uVar14 = uVar5 - (uVar20 + !bVar24);
  uVar15 = uVar10 * uVar1;
  if (uVar20 < uVar5 || bVar2) {
    bVar25 = uVar15 * 0x80000 <= uVar14;
  }
  uVar14 = uVar14 + uVar15 * -0x80000;
  uVar20 = uVar1 * uVar23;
  bVar26 = uVar20 * 8 <= uVar3;
  uVar5 = uVar20 >> 0x1d;
  bVar2 = uVar14 - uVar5 < (uint)bVar26;
  bVar24 = uVar5 < uVar14 || bVar2;
  uVar6 = uVar14 - (uVar5 + !bVar26);
  uVar16 = uVar1 * uVar19;
  if (uVar5 < uVar14 || bVar2) {
    bVar24 = uVar16 * 8 <= uVar6;
  }
  uVar6 = uVar6 + uVar16 * -8;
  uVar5 = ((uVar4 - ((uVar15 >> 0xd) + (uint)!bVar25)) - ((uVar16 >> 0x1d) + (uint)!bVar24)) *
          0x4000000 | uVar6 >> 6;
  uVar14 = uVar6 * 0x4000000 | uVar3 + uVar20 * -8 >> 6;
  uVar21 = uVar22 * (uVar5 >> 0xf);
  uVar20 = uVar20 * -0x20000000;
  uVar3 = uVar21 >> 0x10;
  uVar15 = uVar14 - uVar3 * uVar9;
  uVar4 = uVar3 * uVar23;
  bVar24 = uVar4 * 0x10000 <= uVar20;
  uVar20 = uVar20 + uVar4 * -0x10000;
  uVar4 = uVar4 >> 0x10;
  bVar2 = uVar15 - uVar4 < (uint)bVar24;
  bVar25 = uVar4 < uVar15 || bVar2;
  uVar6 = uVar15 - (uVar4 + !bVar24);
  uVar16 = uVar3 * uVar19;
  if (uVar4 < uVar15 || bVar2) {
    bVar25 = uVar16 * 0x10000 <= uVar6;
  }
  uVar6 = uVar6 + uVar16 * -0x10000;
  uVar14 = (uVar5 - (uVar10 * uVar3 + (uint)(uVar14 < uVar3 * uVar9))) -
           ((uVar16 >> 0x10) + (uint)!bVar25);
  uVar4 = uVar22 * (uVar14 >> 2) >> 0x10;
  uVar5 = uVar4 * uVar9;
  bVar24 = uVar5 * 0x80000 <= uVar20;
  uVar20 = uVar20 + uVar5 * -0x80000;
  uVar5 = uVar5 >> 0xd;
  bVar2 = uVar6 - uVar5 < (uint)bVar24;
  bVar25 = uVar5 < uVar6 || bVar2;
  uVar15 = uVar6 - (uVar5 + !bVar24);
  uVar16 = uVar10 * uVar4;
  if (uVar5 < uVar6 || bVar2) {
    bVar25 = uVar16 * 0x80000 <= uVar15;
  }
  uVar15 = uVar15 + uVar16 * -0x80000;
  uVar5 = uVar4 * uVar23;
  bVar26 = uVar5 * 8 <= uVar20;
  uVar6 = uVar5 >> 0x1d;
  bVar2 = uVar15 - uVar6 < (uint)bVar26;
  bVar24 = uVar6 < uVar15 || bVar2;
  uVar7 = uVar15 - (uVar6 + !bVar26);
  uVar17 = uVar4 * uVar19;
  if (uVar6 < uVar15 || bVar2) {
    bVar24 = uVar17 * 8 <= uVar7;
  }
  uVar7 = uVar7 + uVar17 * -8;
  uVar16 = ((uVar14 - ((uVar16 >> 0xd) + (uint)!bVar25)) - ((uVar17 >> 0x1d) + (uint)!bVar24)) *
           0x4000000 | uVar7 >> 6;
  uVar11 = uVar3 * 0x400000 + uVar4 * 0x200;
  uVar22 = uVar22 * (uVar16 >> 0xf);
  uVar7 = uVar7 * 0x4000000 | uVar20 + uVar5 * -8 >> 6;
  uVar5 = uVar5 * -0x20000000;
  uVar14 = uVar22 >> 0x10;
  uVar20 = uVar14 << 0x1c;
  uVar17 = uVar7 - uVar14 * uVar9;
  uVar6 = uVar14 * uVar23;
  bVar24 = uVar6 * 0x10000 <= uVar5;
  uVar15 = uVar6 >> 0x10;
  bVar2 = uVar17 - uVar15 < (uint)bVar24;
  bVar25 = uVar15 < uVar17 || bVar2;
  uVar8 = uVar17 - (uVar15 + !bVar24);
  uVar18 = uVar14 * uVar19;
  if (uVar15 < uVar17 || bVar2) {
    bVar25 = uVar18 * 0x10000 <= uVar8;
  }
  uVar8 = uVar8 + uVar18 * -0x10000;
  uVar22 = uVar22 >> 0x14;
  uVar17 = uVar11 + uVar22;
  uVar15 = ((uVar16 - (uVar10 * uVar14 + (uint)(uVar7 < uVar14 * uVar9))) -
           ((uVar18 >> 0x10) + (uint)!bVar25)) * 0x4000 | uVar8 >> 0x12;
  uVar14 = uVar8 * 0x4000 | uVar5 + uVar6 * -0x10000 >> 0x12;
  uVar5 = uVar6 * -0x40000000;
  uVar19 = uVar19 | uVar10 << 0x10;
  uVar23 = uVar23 | uVar9 << 0x10;
  bVar2 = uVar15 - uVar19 < (uint)(uVar23 <= uVar14);
  uVar10 = uVar15;
  if (uVar19 < uVar15 || bVar2) {
    uVar10 = uVar15 - (uVar19 + (uVar23 > uVar14));
    uVar14 = uVar14 - uVar23;
  }
  uVar6 = uVar6 * -0x80000000;
  bVar24 = CARRY4(uVar14,uVar14) || CARRY4(uVar14 * 2,(uint)CARRY4(uVar5,uVar5));
  uVar9 = uVar14 * 2 + (uint)CARRY4(uVar5,uVar5);
  bVar25 = CARRY4(uVar10 * 2,(uint)bVar24);
  bVar26 = CARRY4(uVar10,uVar10) || bVar25;
  uVar5 = uVar10 * 2 + (uint)bVar24;
  bVar24 = bVar26 < (uVar19 < uVar5 || uVar5 - uVar19 < (uint)(uVar23 <= uVar9));
  if ((CARRY4(uVar10,uVar10) || bVar25) || bVar24) {
    uVar5 = uVar5 - (uVar19 + (uVar23 > uVar9));
    uVar9 = uVar9 - uVar23;
  }
  bVar27 = CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)CARRY4(uVar6,uVar6));
  uVar10 = uVar9 * 2 + (uint)CARRY4(uVar6,uVar6);
  bVar25 = CARRY4(uVar5 * 2,(uint)bVar27);
  bVar28 = CARRY4(uVar5,uVar5) || bVar25;
  uVar9 = uVar5 * 2 + (uint)bVar27;
  bVar27 = bVar28 < (uVar19 < uVar9 || uVar9 - uVar19 < (uint)(uVar23 <= uVar10));
  if ((CARRY4(uVar5,uVar5) || bVar25) || bVar27) {
    uVar9 = uVar9 - (uVar19 + (uVar23 > uVar10));
    uVar10 = uVar10 - uVar23;
  }
  if (uVar9 != 0 || uVar10 != 0) {
    uVar20 = uVar20 | 1;
  }
  uVar10 = (((uint)(uVar19 < uVar15 || bVar2) * 2 + (uint)(bVar26 || bVar24)) * 2 +
           (uint)(bVar28 || bVar27)) * 0x10000000;
  uVar9 = uVar17 + CARRY4(uVar20,uVar10);
  iVar13 = uVar12 * 0x10000 + uVar1 * 8 + (uVar21 >> 0x1a) +
           (uint)CARRY4(uVar3 * 0x400000,uVar4 * 0x200) + (uint)CARRY4(uVar11,uVar22) +
           (uint)CARRY4(uVar17,(uint)CARRY4(uVar20,uVar10));
  if (-1 < iVar13) {
    return CONCAT44(iVar13 * 2 +
                    (uint)(CARRY4(uVar9,uVar9) ||
                          CARRY4(uVar9 * 2,(uint)CARRY4(uVar20 + uVar10,uVar20 + uVar10))),
                    param_1 ^ param_4) & 0xffffffff80000000;
  }
  return CONCAT44(iVar13,param_1 ^ param_4) & 0xffffffff80000000;
}



// WARNING: Restarted to delay deadcode elimination for space: stack

ulonglong FUN_0005e75c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  bool bVar19;
  
  param_1 = param_1 ^ param_4;
  if (param_3 == 0) {
    if (unaff_r5 == 0) {
      uVar11 = unaff_r4 >> 0x10;
      uVar12 = param_2 >> 0x10;
      uVar14 = unaff_r4 & ~(uVar11 << 0x10);
      param_2 = param_2 & ~(uVar12 << 0x10);
      uVar3 = uVar14 * uVar12;
      uVar14 = param_2 * uVar14;
      param_2 = uVar11 * param_2;
      uVar2 = uVar3 * 0x10000;
      uVar13 = uVar14 + uVar2;
      uVar1 = param_2 * 0x10000;
      uVar15 = uVar13 + uVar1;
      iVar5 = uVar11 * uVar12 + (uVar3 >> 0x10) + (uint)CARRY4(uVar14,uVar2) + (param_2 >> 0x10) +
              (uint)CARRY4(uVar13,uVar1);
      if (-1 < iVar5) {
        return CONCAT44(iVar5 * 2 + (uint)CARRY4(uVar15,uVar15),param_1) & 0xffffffff80000000;
      }
      return CONCAT44(iVar5,param_1) & 0xffffffff80000000;
    }
    uVar14 = param_2 >> 0x10;
    uVar13 = unaff_r4 >> 0x10;
    param_2 = param_2 & ~(uVar14 << 0x10);
    uVar10 = unaff_r4 & ~(uVar13 << 0x10);
    uVar3 = uVar10 * param_2;
    uVar10 = uVar14 * uVar10;
    uVar2 = param_2 * uVar13 * 0x10000;
    uVar4 = uVar3 + uVar2;
    uVar15 = unaff_r5 >> 0x10;
    uVar1 = uVar10 * 0x10000;
    uVar6 = uVar4 + uVar1;
    uVar16 = unaff_r5 & ~(uVar15 << 0x10);
    uVar7 = uVar16 * param_2;
    uVar16 = uVar14 * uVar16;
    uVar11 = param_2 * uVar15 * 0x10000;
    uVar8 = uVar7 + uVar11;
    uVar12 = uVar16 * 0x10000;
    uVar9 = uVar8 + uVar12;
    uVar11 = uVar14 * uVar15 + (param_2 * uVar15 >> 0x10) + (uint)CARRY4(uVar7,uVar11) +
             (uVar16 >> 0x10) + (uint)CARRY4(uVar8,uVar12);
    uVar12 = uVar11 + uVar6;
    iVar5 = uVar14 * uVar13 + (param_2 * uVar13 >> 0x10) + (uint)CARRY4(uVar3,uVar2) +
            (uVar10 >> 0x10) + (uint)CARRY4(uVar4,uVar1) + (uint)CARRY4(uVar11,uVar6);
    if (-1 < iVar5) {
      return CONCAT44(iVar5 * 2 +
                      (uint)(CARRY4(uVar12,uVar12) || CARRY4(uVar12 * 2,(uint)CARRY4(uVar9,uVar9))),
                      param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar5,param_1) & 0xffffffff80000000;
  }
  if (unaff_r5 == 0) {
    uVar14 = unaff_r4 >> 0x10;
    uVar13 = param_2 >> 0x10;
    uVar7 = unaff_r4 & ~(uVar14 << 0x10);
    param_2 = param_2 & ~(uVar13 << 0x10);
    uVar3 = param_2 * uVar7;
    param_2 = uVar14 * param_2;
    uVar2 = uVar7 * uVar13 * 0x10000;
    uVar4 = uVar3 + uVar2;
    uVar15 = param_3 >> 0x10;
    uVar1 = param_2 * 0x10000;
    uVar6 = uVar4 + uVar1;
    param_3 = param_3 & ~(uVar15 << 0x10);
    uVar8 = param_3 * uVar7;
    param_3 = uVar14 * param_3;
    uVar11 = uVar7 * uVar15 * 0x10000;
    uVar9 = uVar8 + uVar11;
    uVar12 = param_3 * 0x10000;
    uVar10 = uVar9 + uVar12;
    uVar12 = uVar14 * uVar15 + (uVar7 * uVar15 >> 0x10) + (uint)CARRY4(uVar8,uVar11) +
             (param_3 >> 0x10) + (uint)CARRY4(uVar9,uVar12);
    uVar11 = uVar12 + uVar6;
    iVar5 = uVar14 * uVar13 + (uVar7 * uVar13 >> 0x10) + (uint)CARRY4(uVar3,uVar2) +
            (param_2 >> 0x10) + (uint)CARRY4(uVar4,uVar1) + (uint)CARRY4(uVar12,uVar6);
    if (-1 < iVar5) {
      return CONCAT44(iVar5 * 2 +
                      (uint)(CARRY4(uVar11,uVar11) || CARRY4(uVar11 * 2,(uint)CARRY4(uVar10,uVar10))
                            ),param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar5,param_1) & 0xffffffff80000000;
  }
  uVar12 = param_2 >> 0x10;
  uVar14 = unaff_r4 >> 0x10;
  uVar8 = param_2 & ~(uVar12 << 0x10);
  uVar6 = unaff_r4 & ~(uVar14 << 0x10);
  uVar3 = uVar8 * uVar14;
  uVar8 = uVar6 * uVar8;
  uVar6 = uVar12 * uVar6;
  uVar2 = uVar3 * 0x10000;
  uVar9 = uVar8 + uVar2;
  uVar13 = param_3 >> 0x10;
  uVar1 = uVar6 * 0x10000;
  uVar10 = uVar9 + uVar1;
  uVar15 = unaff_r5 >> 0x10;
  uVar16 = param_3 & ~(uVar13 << 0x10);
  uVar7 = unaff_r5 & ~(uVar15 << 0x10);
  uVar4 = uVar16 * uVar15;
  uVar16 = uVar7 * uVar16;
  uVar7 = uVar13 * uVar7;
  uVar11 = uVar4 * 0x10000;
  uVar17 = uVar16 + uVar11;
  uVar15 = uVar13 * uVar15 + (uVar4 >> 0x10) + (uint)CARRY4(uVar16,uVar11);
  iVar5 = 0;
  uVar11 = uVar7 * 0x10000;
  uVar4 = uVar17 + uVar11;
  uVar13 = uVar15 + (uVar7 >> 0x10) + (uint)CARRY4(uVar17,uVar11);
  uVar11 = uVar10 + uVar13;
  uVar1 = uVar12 * uVar14 + (uVar3 >> 0x10) + (uint)CARRY4(uVar8,uVar2) + (uVar6 >> 0x10) +
          (uint)CARRY4(uVar9,uVar1) + (uint)CARRY4(uVar10,uVar13);
  uVar14 = uVar11 + uVar4;
  uVar12 = uVar11 + uVar1 + (uint)CARRY4(uVar11,uVar4);
  bVar19 = param_3 <= param_2;
  param_2 = param_2 - param_3;
  bVar18 = param_2 == 0;
  uVar2 = 0;
  if (!bVar19) {
    uVar2 = 0xffffffff;
    iVar5 = unaff_r4 - unaff_r5;
  }
  if (!bVar18) {
    bVar19 = unaff_r4 <= unaff_r5;
    uVar15 = unaff_r5 - unaff_r4;
    bVar18 = uVar15 == 0;
  }
  uVar13 = param_2 >> 0x10;
  if (bVar18) {
    uVar2 = 0;
  }
  if (!bVar19) {
    iVar5 = iVar5 - param_2;
  }
  param_2 = param_2 & ~(uVar13 << 0x10);
  uVar3 = uVar15 >> 0x10;
  if (!bVar19) {
    uVar2 = ~uVar2;
  }
  uVar15 = uVar15 & ~(uVar3 << 0x10);
  uVar10 = param_2 * uVar3;
  param_2 = uVar15 * param_2;
  uVar15 = uVar13 * uVar15;
  uVar6 = uVar10 * 0x10000;
  uVar8 = param_2 + uVar6;
  uVar7 = uVar15 * 0x10000;
  uVar9 = uVar8 + uVar7;
  uVar13 = uVar13 * uVar3 + iVar5 + (uVar10 >> 0x10) + (uint)CARRY4(param_2,uVar6) +
           (uVar15 >> 0x10) + (uint)CARRY4(uVar8,uVar7);
  uVar15 = uVar12 + uVar13 + (uint)CARRY4(uVar14,uVar9);
  iVar5 = uVar1 + (CARRY4(uVar11,uVar1) || CARRY4(uVar11 + uVar1,(uint)CARRY4(uVar11,uVar4))) +
          uVar2 + (uint)(CARRY4(uVar12,uVar13) || CARRY4(uVar12 + uVar13,(uint)CARRY4(uVar14,uVar9))
                        );
  uVar2 = uVar14 + uVar9 | (uVar4 | uVar4 * 4) >> 2;
  if (-1 < iVar5) {
    return CONCAT44(iVar5 * 2 +
                    (uint)(CARRY4(uVar15,uVar15) || CARRY4(uVar15 * 2,(uint)CARRY4(uVar2,uVar2))),
                    param_1) & 0xffffffff80000000;
  }
  return CONCAT44(iVar5,param_1) & 0xffffffff80000000;
}



// WARNING: Control flow encountered bad instruction data

void FUN_0005e9c4(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



void FUN_0005eaa0(int *param_1,int *param_2)

{
  if ((param_1[1] & ~(*param_1 << 1)) < 0 && (param_2[1] & ~(*param_2 << 1)) < 0) {
    FUN_0005e410(*param_1,param_1[1],param_1[2]);
    FUN_0005eb10();
  }
  return;
}



void FUN_0005ead4(uint *param_1,uint *param_2)

{
  if ((*param_1 & 0x40000000) == 0 && (*param_2 & 0x40000000) == 0) {
    FUN_0005e75c(*param_1,param_1[1],param_1[2]);
    FUN_0005eb10();
  }
  return;
}



ulonglong FUN_0005eb10(undefined4 param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = param_3 >> 0xb | param_2 << 0x15;
  uVar3 = FUN_0005e334(param_1,param_2 >> 0xb,uVar2,param_4 + -0x3c01);
  uVar1 = (uint)uVar3 & 0x7fffffff;
  if (uVar1 + 1 < 0x800) {
    return CONCAT44(uVar2,(int)((ulonglong)uVar3 >> 0x20) + uVar1 * 0x100000);
  }
  return (ulonglong)DAT_0005eb70;
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00031714)
// WARNING: Restarted to delay deadcode elimination for space: stack

uint FUN_0005eb94(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  int local_18;
  
  local_18 = param_4;
  FUN_0005ec90(param_1,param_2,&local_18);
  local_18 = local_18 + 0x7e;
  bVar5 = local_18 == 0;
  if ((local_18 < 1) &&
     (FUN_00030d04(param_1,param_2,DAT_0005ec60,DAT_0005ec64), uVar3 = DAT_0005ec68, !bVar5)) {
    uVar1 = FUN_00031cd0(DAT_0005ec68,0);
    uVar2 = FUN_00031e14(param_1,param_2);
    FUN_00031cd0(uVar3,uVar1 & uVar3);
    if ((uVar2 & 0x7fffffff) == 0) {
      func_0x0003177c(2);
    }
    return uVar2;
  }
  if (0xfe < local_18) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  uVar2 = param_2 & 0x80000000;
  uVar3 = param_2 & 0x7fffffff;
  uVar1 = uVar3 ^ uVar3 << 1;
  if ((uVar1 & 0x7f000000) == 0 && (uVar1 & 0xe00000) == 0) {
    if ((param_2 & 0x100000) == 0) {
      if (param_1 != 0 || uVar3 != 0) {
                    // WARNING: Bad instruction - Truncating control flow here
        halt_baddata();
      }
      return uVar2;
    }
    if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
      return param_2 & 0xff8fffff;
    }
    if (((param_2 & 0x80000) != 0) && ((DAT_00031fd4 & 0x4f) != 0x48)) {
      uVar3 = DAT_00031fd4 & 0xf;
      if (uVar3 == 9) {
        if ((DAT_00031fd4 & 0x100000) == 0) {
          return (uint)((DAT_00031fd4 & 0x80000) != 0);
        }
        if ((DAT_00031fd4 & 0x70000) == 0) {
                    // WARNING: Bad instruction - Truncating control flow here
          halt_baddata();
        }
        return 8;
      }
      if (uVar3 == 10) {
        if ((DAT_00031fd4 & 0x40) != 0) {
          param_1 = 0x80000000;
        }
        return param_1;
      }
      if (uVar3 == 8) {
        if ((DAT_00031fd4 & 0x40) == 0) {
          if ((DAT_00031fd4 & 0x10) == 0) {
            return param_2 & 0xff000000 | param_1 >> 0x1d | (param_2 & 0xffffff) << 3;
          }
          return param_1 << 0x1d;
        }
        if ((DAT_00031fd4 & 0x10000) != 0) {
          return 0;
        }
        if ((DAT_00031fd4 & 0x20) != 0) {
          if ((DAT_00031fd4 & 0x10) != 0) {
            param_1 = param_2;
          }
          uVar3 = 0xffffffff;
          if ((param_1 & 0x80000000) != 0) {
            uVar3 = 0;
          }
          return uVar3;
        }
        if ((DAT_00031fd4 & 0x10) == 0) {
          uVar3 = 0x7fffffff;
          param_2 = param_1;
        }
        else {
          uVar3 = 0xffffffff;
        }
        if ((param_2 & 0x80000000) != 0) {
          uVar3 = ~uVar3;
        }
        return uVar3;
      }
      return param_1;
    }
  }
  else {
    iVar4 = uVar3 + 0xc8000000;
    if (iVar4 < 0x100000) {
      uVar2 = uVar2 | 1;
    }
    bVar5 = (bool)((byte)(param_1 >> 0x1c) & 1);
    if ((bVar5 && (param_1 & 0xfffffff) != 0) ||
       ((bVar5 && (-1 < (int)((param_1 & 0x20000000) * 4 + -0x40000000))))) {
      bVar5 = 0xdfffffff < param_1;
      param_1 = param_1 + 0x20000000;
      iVar4 = iVar4 + (uint)bVar5;
    }
    if ((uVar2 & 1) != 0) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    if (iVar4 < 0xff00000) {
      return uVar2 | iVar4 << 3 | param_1 >> 0x1d;
    }
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



void FUN_0005ec90(int param_1,uint param_2,int *param_3)

{
  uint extraout_r1;
  uint uVar1;
  int iVar2;
  
  *param_3 = 0;
  uVar1 = param_2 & 0x7fffffff;
  if (DAT_0005ecfc <= (int)uVar1) {
    return;
  }
  if (uVar1 != 0 || param_1 != 0) {
    if (uVar1 < 0x100000) {
      FUN_000322e4(param_1,param_2,0x36);
      iVar2 = -0x36;
      uVar1 = extraout_r1 & 0x7fffffff;
      *param_3 = -0x36;
    }
    else {
      iVar2 = *param_3;
    }
    *param_3 = iVar2 + ((int)uVar1 >> 0x14) + -0x3fe;
    return;
  }
  return;
}



int FUN_0005ed00(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = param_2 >> 1;
  uVar1 = param_4 >> 1;
  if ((int)uVar2 < 0) {
    bVar4 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + (uint)bVar4);
  }
  if ((int)param_4 < 0) {
    bVar4 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(param_4 + bVar4);
  }
  iVar3 = FUN_000319f0(param_1,param_2,param_3,param_4);
  if (((uVar2 ^ uVar1) & 0x40000000) != 0) {
    iVar3 = -iVar3;
  }
  return iVar3;
}



// WARNING: Control flow encountered bad instruction data

undefined4 FUN_0005ed54(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  bool bVar5;
  undefined8 uVar6;
  
  iVar1 = FUN_0005ef10();
  uVar4 = iVar1 == 0;
  if (!(bool)uVar4) {
    FUN_00030d04(param_1,param_2);
  }
  if (!(bool)uVar4) {
    uVar2 = FUN_00031cd0(0);
    uVar6 = FUN_000322e4(param_1,param_2,param_3);
    uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
    param_1 = (undefined4)uVar6;
    FUN_00031cd0(0xc,uVar2 & 0xc);
    iVar1 = FUN_0005ef10(param_1,uVar3);
    bVar5 = iVar1 == 0;
    if (bVar5) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
    FUN_00030d04(param_1,uVar3,DAT_0005ee2c,DAT_0005ee30);
    if (bVar5) {
                    // WARNING: Bad instruction - Truncating control flow here
      halt_baddata();
    }
  }
  return param_1;
}



bool FUN_0005ef10(undefined4 param_1,uint param_2)

{
  return DAT_0005ef28 != (param_2 >> 0x14) * 0x200000;
}



void FUN_0005ef2c(uint *param_1,uint *param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar1 = param_1[1];
  *param_2 = uVar1;
  uVar1 = uVar1 << 1;
  param_2[1] = *param_1;
  if (uVar1 >> 0x15 == 0) {
    uVar3 = FUN_000322e4(*param_1,param_1[1],0x40);
    uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
    if (param_4 != 0) {
      param_2[1] = (uint)uVar3;
    }
    uVar1 = (uVar2 >> 0x14 & 0xfffff7ff) - 0x40;
    if (param_4 != 0) {
      *param_2 = uVar2;
    }
  }
  else {
    uVar1 = uVar1 >> 0x15;
  }
  *param_3 = uVar1;
  return;
}



undefined1 FUN_0005ef90(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  
  *param_2 = (uint)param_1[1] >> 0x1f;
  iVar1 = FUN_0005de34(*param_1,param_1[1]);
  if (iVar1 != 3) {
    return iVar1 == 7;
  }
  return 2;
}



undefined8 FUN_00092be0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_1 >> 2 | param_2 << 0x1e;
  uVar1 = param_1 - uVar3;
  uVar2 = param_2 - ((param_2 >> 2) + (uint)(param_1 < uVar3));
  uVar4 = uVar1 >> 4 | uVar2 * 0x10000000;
  uVar3 = uVar1 + uVar4;
  uVar2 = uVar2 + (uVar2 >> 4) + (uint)CARRY4(uVar1,uVar4);
  uVar4 = uVar3 >> 8 | uVar2 * 0x1000000;
  uVar1 = uVar3 + uVar4;
  uVar3 = uVar2 + (uVar2 >> 8) + (uint)CARRY4(uVar3,uVar4);
  uVar4 = uVar1 >> 0x10 | uVar3 * 0x10000;
  uVar2 = uVar1 + uVar4;
  uVar4 = uVar3 + (uVar3 >> 0x10) + (uint)CARRY4(uVar1,uVar4);
  uVar3 = uVar4 + CARRY4(uVar2,uVar4);
  uVar1 = uVar3 * 0x20000000;
  uVar2 = uVar2 + uVar4 >> 3 | uVar1;
  uVar3 = uVar3 >> 3;
  if (-1 < (int)((param_2 - (param_1 < 10)) -
                (((uVar3 << 2 | uVar1 >> 0x1e) + uVar3 + (uint)CARRY4(uVar2,uVar2 * 4)) * 2 +
                 (uint)CARRY4(uVar2 * 5,uVar2 * 5) + (uint)(param_1 - 10 < uVar2 * 10)))) {
    return CONCAT44(uVar3 + (0xfffffffe < uVar2),uVar2 + 1);
  }
  return CONCAT44(uVar3,uVar2);
}



// WARNING: This is an inlined function

void switch8_r3(void)

{
  byte bVar1;
  uint in_r3;
  int in_lr;
  
  if (in_r3 < *(byte *)(in_lr + -1)) {
    bVar1 = *(byte *)(in_lr + in_r3);
  }
  else {
    bVar1 = *(byte *)(in_lr + (uint)*(byte *)(in_lr + -1));
  }
                    // WARNING: Could not recover jumptable at 0x00092c94. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)(in_lr + (uint)bVar1 * 2))();
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_002d40fa(undefined4 param_1,undefined4 param_2)

{
  bool in_ZR;
  undefined1 in_CY;
  undefined4 in_cr3;
  undefined4 in_cr11;
  
  if (!in_ZR) {
    in_CY = true;
  }
  if ((bool)in_CY) {
    coprocessor_moveto(4,7,3,param_2,in_cr3,in_cr11);
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_002d4686(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_r5;
  undefined4 unaff_r7;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 in_r12;
  bool in_ZR;
  bool in_CY;
  
  if (in_CY && !in_ZR) {
    DAT_002d4692 = param_1;
    DAT_002d4696 = param_3;
    DAT_002d469a = unaff_r5;
    DAT_002d469e = unaff_r7;
    DAT_002d46a2 = unaff_r10;
    DAT_002d46a6 = unaff_r11;
    DAT_002d46aa = in_r12;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}


