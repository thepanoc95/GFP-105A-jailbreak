typedef unsigned char   undefined;

typedef unsigned int    undefined4;


undefined DAT_00001bac;
uint DAT_00007a8c;
uint *DAT_00007a9c;
uint *DAT_00007a94;
uint *DAT_00007a98;
undefined4 DAT_00007a7c;
undefined DAT_00007874;
undefined4 DAT_00007b8c;

// WARNING: Control flow encountered bad instruction data

void UndefinedInstruction(void)

{
  undefined1 unaff_r4;
  int in_r12;
  bool in_NG;
  
  if (in_NG) {
    *(undefined1 *)(in_r12 + -0x946) = unaff_r4;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void SupervisorCall(void)

{
  undefined1 unaff_r4;
  int in_r12;
  bool in_NG;
  
  if (in_NG) {
    *(undefined1 *)(in_r12 + -0x946) = unaff_r4;
  }
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

void FIQ(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00000494(void)

{
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data

void FUN_00000d64(int param_1)

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

void FUN_0000167c(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

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
    *param_2 = 0x1684;
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
    param_1[5] = 0x1690;
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
                    // WARNING: Could not recover jumptable at 0x00001814. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)(in_lr + (uint)bVar1 * 2))();
  return;
}



longlong FUN_00001a70(uint param_1,uint param_2)

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
                  ((byte)(&DAT_00001bac)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] - 4 >>
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
  iVar4 = (uint)(byte)(&DAT_00001bac)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] << (uVar5 & 0xff);
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

void FUN_00002a88(int *param_1,undefined4 param_2,int param_3)

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
    *unaff_r8 = 0x2a9c;
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

void FUN_00003200(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

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
    *param_2 = 0x3208;
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
    param_1[5] = 0x3214;
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



undefined8 FUN_00004a80(uint *param_1,uint *param_2,uint param_3,uint param_4)

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
                    // WARNING: Could not recover jumptable at 0x0000598c. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)(in_lr + (uint)bVar1 * 2))();
  return;
}



// WARNING: Control flow encountered bad instruction data

void FUN_000059d8(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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

void FUN_00005b3a(int param_1,undefined4 param_2,uint param_3)

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
    *unaff_r9 = 0x5b4e;
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

void FUN_00006304(int param_1)

{
  undefined4 unaff_r4;
  bool in_NG;
  char in_OV;
  
  if (in_NG != (bool)in_OV) {
    *(undefined4 *)(param_1 + -0x904) = unaff_r4;
  }
  if (!in_NG) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
                    // WARNING: Bad instruction - Truncating control flow here
  halt_baddata();
}



// WARNING: Control flow encountered bad instruction data
// WARNING: Removing unreachable block (ram,0x00004a18)

undefined8 FUN_00007600(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

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
      goto LAB_00007aa0;
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
  puVar5 = (uint *)FUN_00007b80();
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
        goto joined_r0x00007974;
      }
      if ((in_r12 & 0x8000000) == 0) {
        if ((uVar3 & 0x100) != 0) {
          halt_baddata();
        }
        if ((in_r12 & 0x40) == 0) {
          if ((in_r12 & 0xc000) == 0) {
            param_1 = DAT_00007a94;
            puVar2 = DAT_00007a98;
            if ((in_r12 & 0x10) == 0) {
              param_1 = DAT_00007a9c;
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
            param_1 = (uint *)((uint)DAT_00007a9c | (uint)param_2 & 0x80000000);
          }
          else {
            param_1 = DAT_00007a94;
            puVar2 = (uint *)((uint)DAT_00007a98 | (uint)param_2 & 0x80000000);
          }
        }
LAB_00007aa0:
        uVar3 = in_r12 & 0xf;
        if (uVar3 == 9) {
          if ((in_r12 & 0x100000) == 0) {
            return CONCAT44(puVar2,(uint)((in_r12 & 0x80000) != 0));
          }
          if ((in_r12 & 0x70000) != 0) {
            return CONCAT44(~(in_r12 << 0xf) << 1,8);
          }
          puVar2 = (uint *)FUN_00007b80();
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
      param_1 = &DAT_00007a7c;
    }
    if (bVar10) {
      uVar7 = *param_1;
      param_2 = (uint *)(param_1[1] | uVar3 & 0x80000000);
    }
    else {
      uVar7 = DAT_00007a8c | uVar3 & 0x80000000;
    }
    return CONCAT44(param_2,uVar7);
  }
  uVar3 = uVar3 & 0x800;
joined_r0x00007974:
  if (uVar3 != 0) {
                    // WARNING: Bad instruction - Truncating control flow here
    halt_baddata();
  }
  return CONCAT44(param_2,param_1);
}



longlong FUN_00007738(uint param_1,uint param_2)

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
                  ((byte)(&DAT_00007874)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] - 4 >>
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
  iVar4 = (uint)(byte)(&DAT_00007874)[(int)(param_2 << LZCOUNT(param_2)) >> 0x19] << (uVar5 & 0xff);
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



undefined4 FUN_00007b70(undefined4 param_1)

{
  FUN_00004a80();
  return param_1;
}



undefined4 FUN_00007b80(void)

{
  return DAT_00007b8c;
}


