typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    uint;
typedef unsigned char    undefined1;
typedef unsigned int    undefined2;
typedef unsigned long    undefined4;



// Title:  Mamba, Version 2.0, (c) R�diger Appel, 1992
// Format: New Executable (NE) Windows
// CRC:    1ec4dad8
// 
// Program Entry Point (CS:IP):   000a:001a
// Initial Stack Pointer (SS:SP): 000b:0000
// Auto Data Segment Index:       000b
// Initial Heap Size:             2000
// Initial Stack Size:            6000
// Minimum Code Swap Size:        0000
// 
// Linker Version:  5.14
// Target OS:       Windows
// Windows Version: 3.0
// 
// Program Flags:     02
//         Multi Data
// Application Flags: 03
//         Windows P.M. API
// Other Flags:       08
// 

undefined2 __stdcall16far main_message_loop(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int in_stack_0000000a;
  undefined2 in_stack_0000000c;
  undefined2 local_16;
  undefined2 uStackY_14;
  undefined2 local_12;
  undefined2 uStackY_10;
  undefined2 *puStackY_e;
  
                    // Segment:    1
                    // Offset:     00000960
                    // Length:     0c90
                    // Min Alloc:  0c90
                    // Flags:      1d50
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     Preload
                    //     Impure (Non-shareable)
                    // 
  uVar2 = 0x1048;
  runtime_stack_safety_check();
  uRam105018c6 = in_stack_0000000c;
  if (in_stack_0000000a == 0) {
    uVar2 = 0x1008;
    puStackY_e = (undefined2 *)0x29;
    iVar1 = register_window_classes_with_icons_and_cursors();
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar3 = 0x1008;
  uStackY_10 = 0x42;
  puStackY_e = (undefined2 *)uVar2;
  iVar1 = setup_game_ui_windows(uRam105018c6,in_stack_0000000a);
  if (iVar1 == 0) {
    local_12 = 0;
  }
  else {
    while( true ) {
      puStackY_e = (undefined2 *)0x0;
      uStackY_10 = 0;
      local_12 = 0;
      local_16 = 0x60;
      uStackY_14 = uVar3;
      iVar1 = GETMESSAGE();
      if (iVar1 == 0) break;
      puStackY_e = &local_16;
      uStackY_10 = 0x1170;
      local_12 = 0x78;
      iVar1 = TRANSLATEACCELERATOR();
      if (iVar1 == 0) {
        puStackY_e = (undefined2 *)0x1170;
        uStackY_10 = 0x88;
        TRANSLATEMESSAGE();
        puStackY_e = &local_16;
        uStackY_10 = 0x1170;
        local_12 = 0x94;
        DISPATCHMESSAGE();
      }
      uVar3 = 0x1170;
    }
  }
  return local_12;
}



undefined2 __stdcall16far
FRAMEWNDPROC(int param_1,undefined2 param_2,int param_3,int param_4,byte *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 unaff_SS;
  int iStack_40;
  int iStack_3c;
  int iStack_2c;
  int iStack_2a;
  int iStack_28;
  int iStack_26;
  int iStack_24;
  int iStack_22;
  int iStack_20;
  int iStack_1e;
  int iStack_1c;
  int *piStack_1a;
  undefined1 uVar11;
  
  runtime_stack_safety_check();
  if (param_4 == 1) {
    uRam1050160a = LOADACCELERATORS();
    bRam1050160c = 0;
    uRam10501602 = 0;
    iRam10501626 = 0;
    iRam105018ee = 0;
    iRam105017a0 = 1;
    uVar6 = 0;
  }
  else if (param_4 == 2) {
    if (iRam10501896 != 0) {
      FUN_1040_0000(0);
    }
    KILLTIMER();
    FUN_1020_0552();
    piStack_1a = (int *)0xba0;
    WINHELP();
    piStack_1a = (int *)0x1170;
    iStack_1c = 0xbb5;
    WINHELP();
    POSTQUITMESSAGE();
    uVar6 = 0;
  }
  else if (param_4 == 3) {
    iVar8 = ISICONIC();
    if (iVar8 == 0) {
      GETWINDOWRECT();
      SETWINDOWWORD();
      piStack_1a = (int *)0x6f7;
      SETWINDOWWORD();
    }
    uVar6 = 0;
  }
  else if (param_4 == 5) {
    if (param_3 == 0) {
      SETWINDOWWORD();
      iRam10501626 = 0;
    }
    else if (param_3 == 1) {
      SETWINDOWWORD();
      iRam10501626 = 1;
    }
    uVar6 = 0;
  }
  else if (param_4 == 7) {
    GETDC();
    if (iRam1050189c == 0) {
      REALIZEPALETTE();
    }
    else {
      SELECTPALETTE();
      REALIZEPALETTE();
      SELECTPALETTE();
    }
    RELEASEDC();
    uVar6 = 0;
  }
  else if (param_4 == 0xf) {
    BEGINPAINT();
    GETCLIENTRECT();
    uVar6 = CREATESOLIDBRUSH();
    CREATESOLIDBRUSH();
    piStack_1a = (int *)0x813;
    CREATEPEN();
    piStack_1a = (int *)0x1170;
    iStack_1c = 0x827;
    uVar9 = CREATEPEN();
    piStack_1a = (int *)uRam105018fa;
    iStack_1c = 0x1170;
    iStack_1e = 0x83b;
    uVar10 = CREATEPEN();
    piStack_1a = &iStack_2c;
    iStack_1e = 0x1170;
    iStack_20 = 0x850;
    iStack_1c = uVar6;
    FILLRECT();
    iStack_1c = 0x1170;
    iStack_1e = 0x85b;
    piStack_1a = (int *)uVar10;
    SELECTOBJECT();
    piStack_1a = (int *)iStack_24;
    iStack_1c = 0;
    iStack_1e = iStack_26 + -1;
    iStack_20 = 0x1170;
    iStack_22 = 0x86d;
    MOVETO();
    iStack_1c = iStack_24;
    iStack_1e = 0;
    iStack_20 = 0;
    iStack_22 = 0x1170;
    iStack_24 = 0x879;
    LINETO();
    iStack_1e = iStack_24;
    iStack_20 = iStack_28 + -1;
    iStack_22 = 0;
    iStack_24 = 0x1170;
    iStack_26 = 0x888;
    LINETO();
    iStack_20 = iStack_24;
    iStack_24 = 0x1170;
    iStack_26 = 0x893;
    iStack_22 = uVar9;
    SELECTOBJECT();
    iStack_22 = iStack_24;
    iStack_24 = iStack_28 + -1;
    iStack_26 = 1;
    iStack_28 = 0x1170;
    iStack_2a = 0x8a2;
    MOVETO();
    iStack_26 = iStack_28 + -1;
    iStack_28 = iStack_28 + -2;
    iStack_2a = 0x1170;
    iStack_2c = 0x8b4;
    LINETO();
    iStack_26 = iStack_24;
    iStack_28 = 0;
    iStack_2a = iStack_24 + -1;
    iStack_2c = 0x1170;
    LINETO();
    iStack_28 = iStack_24;
    iStack_2c = 0x1170;
    iStack_2a = uVar10;
    SELECTOBJECT();
    iStack_2a = iStack_24;
    iStack_2c = 0x1c5;
    MOVETO();
    iStack_2c = iStack_24;
    LINETO();
    LINETO();
    iVar8 = iStack_24;
    SELECTOBJECT();
    iVar1 = iStack_24;
    MOVETO();
    iVar2 = iStack_24;
    LINETO();
    iVar3 = iStack_24;
    LINETO();
    iVar4 = iStack_24;
    SELECTOBJECT();
    iVar5 = iStack_24;
    MOVETO();
    LINETO();
    LINETO();
    LINETO();
    LINETO();
    iStack_2c = 0x1c6;
    iStack_28 = 0x21e;
    iStack_2a = 0x11;
    iStack_26 = 0xc0;
    FILLRECT(0x1170);
    SELECTOBJECT();
    iStack_40 = 0x29;
    for (iStack_3c = 0; iStack_3c < 5; iStack_3c = iStack_3c + 1) {
      BITBLT(0x1170,0x20,0xcc,iStack_3c * 9,0,uRam105015ca,9,0x50,iStack_40);
      iStack_40 = iStack_40 + 0x23;
    }
    SELECTOBJECT(0x1170);
    SELECTOBJECT(0x1170,iVar5);
    DELETEOBJECT(0x1170,iVar8);
    DELETEOBJECT(0x1170,iVar1);
    DELETEOBJECT(0x1170,iVar2);
    DELETEOBJECT(0x1170,iVar3);
    DELETEOBJECT(0x1170,iVar4);
    FUN_1038_005c();
    ENDPAINT(0x1038,&iStack_24,unaff_SS);
    uVar6 = 0;
  }
  else {
    if (param_4 == 0x10) {
      iVar8 = GETCLASSWORD();
      if (iVar8 == 1) {
        profile_preferences_save(param_5);
      }
      else {
        SETCLASSWORD();
      }
    }
    else {
      if (param_4 == 0x11) {
        SENDMESSAGE();
        return 1;
      }
      if (param_4 == 0x2b) {
        if ((*(uint *)(param_1 + 6) & 4) != 0) {
          return 0;
        }
        SELECTOBJECT();
        piStack_1a = (int *)*(undefined2 *)(param_1 + 0xc);
        iStack_1c = 0xcc;
        iStack_1e = 0x20;
        iStack_20 = 0x1170;
        iStack_22 = 0xb0d;
        BITBLT();
        SELECTOBJECT();
        return 0;
      }
      if (param_4 == 0x100) {
        if (((iRam10501610 != 0) && (uRam10501602 == 0)) &&
           (uVar7 = FUN_1048_08f0(), (uVar7 & 0x4000) == 0)) {
          if (param_3 == 0x20) {
            uVar7 = (uint)(*(int *)((uint)bRam1050160c * 2 + 0x18c8) == 0);
            uVar11 = *(undefined1 *)(bRam1050160c + 0x17d4);
          }
          else if (param_3 == 0x25) {
            uVar7 = 1;
            uVar11 = 3;
          }
          else if (param_3 == 0x26) {
            uVar7 = 1;
            uVar11 = 0;
          }
          else if (param_3 == 0x27) {
            uVar7 = 1;
            uVar11 = 1;
          }
          else {
            if (param_3 != 0x28) {
              return 0;
            }
            uVar7 = 1;
            uVar11 = 2;
          }
          if (bRam1050160c < 9) {
            bRam1050160c = bRam1050160c + 1;
            *(uint *)((uint)bRam1050160c * 2 + 0x18c8) = uVar7;
            *(undefined1 *)(bRam1050160c + 0x17d4) = uVar11;
          }
        }
        return 0;
      }
      if (param_4 == 0x111) {
        if ((param_3 != 0x65) || (iRam10501610 == 0)) {
          SETFOCUS();
        }
        if (param_3 == 0x65) {
          if ((iRam105018ee == 0) && (iVar8 = FUN_1018_0000(), iVar8 == 0)) {
            MESSAGEBEEP();
            return 0;
          }
          iRam105018ee = 1;
          if (iRam10501610 == 0) {
            FUN_1038_0000(iRam105017a2);
            FUN_1000_0c52(param_5);
          }
          else {
            iRam105017a0 = 0;
            FUN_1010_0404((int)param_5);
            iRam105017a0 = 1;
            FUN_1038_0000(0);
            FUN_1000_0c52(param_5);
          }
          GETCLIENTRECT();
          INVALIDATERECT();
          UPDATEWINDOW();
          if (uRam10501602 != 0) {
            uRam10501602 = 0;
            GETCLIENTRECT();
            piStack_1a = (int *)0x1170;
            iStack_1c = 0x1e3;
            INVALIDATERECT();
            UPDATEWINDOW();
          }
        }
        else if (param_3 == 0x66) {
          uRam10501602 = (uint)(uRam10501602 == 0);
          GETCLIENTRECT();
          INVALIDATERECT();
          UPDATEWINDOW();
        }
        else if (param_3 == 0x6d) {
          SENDMESSAGE();
        }
        else if (param_3 == 0xc9) {
          uRam10501788 = (uint)(uRam10501788 == 0);
        }
        else if (param_3 == 0xca) {
          FUN_1018_07f0(param_5);
        }
        else if (param_3 == 0xcb) {
          FUN_1010_0332((int)param_5);
          FUN_1018_03f4(param_5);
        }
        else if (param_3 == 0xcc) {
          LOADSTRING();
          piStack_1a = (int *)0x2b4;
          LOADSTRING();
          piStack_1a = (int *)0x24;
          iStack_1c = 0x1170;
          iStack_1e = 0x2cc;
          iVar8 = MESSAGEBOX();
                    // if YES was clicked, clear/reset highscore?
          if (iVar8 == 6) {
            profile_charts_clear(param_5);
          }
        }
        else if (param_3 == 0x12d) {
          piStack_1a = (int *)0x2f5;
          WINHELP();
        }
        else if (param_3 == 0x12e) {
          piStack_1a = (int *)0x30d;
          WINHELP();
        }
        else if (param_3 == 0x12f) {
          piStack_1a = (int *)0x325;
          WINHELP();
        }
        else if (param_3 == 0x130) {
          piStack_1a = (int *)0x33d;
          WINHELP();
        }
        else if (param_3 == 0x131) {
          piStack_1a = (int *)0x355;
          WINHELP();
        }
        else if (param_3 == 0x132) {
          piStack_1a = (int *)0x36a;
          WINHELP();
        }
        else if (param_3 == 0x133) {
          FUN_1018_0164(param_5);
        }
        else if (((((param_3 == 0x3e9) || (param_3 == 0x3ea)) ||
                  ((param_3 == 0x3eb ||
                   (((param_3 == 0x3ec || (param_3 == 0x3ed)) || (param_3 == 0x3ee)))))) ||
                 ((param_3 == 0x3ef || (param_3 == 0x3f0)))) ||
                ((param_3 == 0x3f1 || (param_3 == 0x3f2)))) {
          iRam105017a2 = param_3 + -1000;
        }
        return 0;
      }
      if (param_4 == 0x113) {
        if (((iRam105017a0 != 0) && (iRam10501626 == 0)) && (uRam10501602 == 0)) {
          if (iRam105017b2 == 0) {
            FUN_1038_02d2(param_5);
          }
          else {
            iRam105017b2 = iRam105017b2 + -1;
          }
        }
        return 0;
      }
      if (param_4 == 0x116) {
        iVar8 = GETMENU();
        LOADSTRING();
        piStack_1a = (int *)0x1170;
        iStack_1c = 0x487;
        MODIFYMENU();
        CHECKMENUITEM();
        piStack_1a = (int *)0x4ba;
        CHECKMENUITEM();
        piStack_1a = (int *)0x1170;
        iStack_1c = 0x4d4;
        CHECKMENUITEM();
        if (iRam105017a2 == 2) {
          piStack_1a = (int *)0x8;
        }
        else {
          piStack_1a = (int *)0x0;
        }
        iStack_1c = 0x1170;
        iStack_1e = 0x4ee;
        CHECKMENUITEM();
        piStack_1a = (int *)0x3eb;
        if (iRam105017a2 == 3) {
          iStack_1c = 8;
        }
        else {
          iStack_1c = 0;
        }
        iStack_1e = 0x1170;
        iStack_20 = 0x508;
        CHECKMENUITEM();
        iStack_1c = 0x3ec;
        if (iRam105017a2 == 4) {
          iStack_1e = 8;
        }
        else {
          iStack_1e = 0;
        }
        iStack_20 = 0x1170;
        iStack_22 = 0x522;
        piStack_1a = (int *)iVar8;
        CHECKMENUITEM();
        iStack_1e = 0x3ed;
        if (iRam105017a2 == 5) {
          iStack_20 = 8;
        }
        else {
          iStack_20 = 0;
        }
        iStack_22 = 0x1170;
        iStack_24 = 0x53c;
        iStack_1c = iVar8;
        CHECKMENUITEM();
        iStack_20 = 0x3ee;
        if (iRam105017a2 == 6) {
          iStack_22 = 8;
        }
        else {
          iStack_22 = 0;
        }
        iStack_24 = 0x1170;
        iStack_26 = 0x556;
        iStack_1e = iVar8;
        CHECKMENUITEM();
        iStack_22 = 0x3ef;
        if (iRam105017a2 == 7) {
          iStack_24 = 8;
        }
        else {
          iStack_24 = 0;
        }
        iStack_26 = 0x1170;
        iStack_28 = 0x570;
        iStack_20 = iVar8;
        CHECKMENUITEM();
        iStack_24 = 0x3f0;
        if (iRam105017a2 == 8) {
          iStack_26 = 8;
        }
        else {
          iStack_26 = 0;
        }
        iStack_28 = 0x1170;
        iStack_2a = 0x58a;
        iStack_22 = iVar8;
        CHECKMENUITEM();
        iStack_26 = 0x3f1;
        if (iRam105017a2 == 9) {
          iStack_28 = 8;
        }
        else {
          iStack_28 = 0;
        }
        iStack_2a = 0x1170;
        iStack_2c = 0x5a4;
        iStack_24 = iVar8;
        CHECKMENUITEM();
        iStack_28 = 0x3f2;
        if (iRam105017a2 == 10) {
          iStack_2a = 8;
        }
        else {
          iStack_2a = 0;
        }
        iStack_2c = 0x1170;
        iStack_26 = iVar8;
        CHECKMENUITEM();
        return 0;
      }
    }
    uVar6 = DEFWINDOWPROC();
  }
  return uVar6;
}



void __cdecl16far FUN_1000_0c52(undefined2 param_1)

{
  undefined2 uVar1;
  
  runtime_stack_safety_check();
  uVar1 = GETDC(0x1048,param_1);
  FUN_1038_005c();
  RELEASEDC(0x1038,uVar1);
  return;
}



undefined2 __cdecl16far register_window_classes_with_icons_and_cursors(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 local_1e;
  undefined2 *local_1c;
  
                    // Segment:    2
                    // Offset:     00003c60
                    // Length:     05b3
                    // Min Alloc:  05b3
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  local_1e = 3;
  local_1c = (undefined2 *)0xa8;
  LOADICON();
  LOADCURSOR();
  iVar1 = REGISTERCLASS();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    local_1e = 3;
    local_1c = (undefined2 *)0x0;
    LOADCURSOR();
    iVar1 = REGISTERCLASS();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      local_1c = &local_1e;
      local_1e = 0x1170;
      GETCLASSINFO();
      local_1c = (undefined2 *)0x1170;
      local_1e = 0x11a;
      LOADCURSOR();
      local_1c = (undefined2 *)0x1170;
      local_1e = 0x134;
      uVar2 = REGISTERCLASS();
    }
  }
  return uVar2;
}



undefined2 __cdecl16far setup_game_ui_windows(undefined2 param_1,int param_2)

{
  int iVar1;
  undefined1 auStackY_6a [16];
  int iStackY_5a;
  int iStackY_58;
  undefined2 uStackY_3e;
  undefined2 uStackY_3c;
  undefined2 uStackY_3a;
  undefined2 uStackY_38;
  undefined2 uStackY_36;
  undefined2 uStackY_34;
  undefined2 uStackY_32;
  int iStackY_30;
  undefined2 uStackY_2e;
  undefined2 uStackY_2c;
  undefined1 *puStackY_2a;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  
  runtime_stack_safety_check();
  GETCLASSINFO();
  uRam105018be = uStack_1c;
  uRam105018c0 = uStack_1a;
  LOADSTRING();
  GETSYSTEMMETRICS();
  iVar1 = GETSYSTEMMETRICS();
  iStackY_58 = iVar1 * 2 + 0x17d;
  puStackY_2a = (undefined1 *)0x1170;
  uStackY_2c = 0x1c5;
  iStackY_5a = GETSYSTEMMETRICS();
  iStackY_5a = iStackY_58 + iStackY_5a;
  uStackY_2c = 4;
  uStackY_2e = 0x1170;
  iStackY_30 = 0x1d4;
  iStackY_30 = GETSYSTEMMETRICS();
  iStackY_30 = iStackY_5a + iStackY_30;
  uStackY_32 = 0;
  uStackY_34 = 0;
  uStackY_36 = param_1;
  uStackY_38 = 0;
  uStackY_3a = 0;
  uStackY_3c = 0x1170;
  uStackY_3e = 0x1ea;
  iVar1 = CREATEWINDOW();
  if (iVar1 != 0) {
    iRam1050178c = iVar1;
    iVar1 = SETTIMER();
    if (iVar1 == 0) {
      puStackY_2a = (undefined1 *)0x228;
      LOADSTRING();
      puStackY_2a = (undefined1 *)0x1170;
      uStackY_2c = 0x23c;
      LOADSTRING();
      puStackY_2a = auStackY_6a;
      uStackY_2c = 0x30;
      uStackY_2e = 0x1170;
      iStackY_30 = 0x255;
      MESSAGEBOX();
      DESTROYWINDOW();
    }
    else {
      puStackY_2a = (undefined1 *)0x1c4;
      uStackY_2c = 0xcf;
      uStackY_2e = 0x5c;
      iStackY_30 = 0x24;
      uStackY_32 = 0x30;
      uStackY_34 = 0x12d;
      uStackY_36 = param_1;
      uStackY_38 = 0;
      uStackY_3a = 0;
      uStackY_3c = 0x1170;
      uStackY_3e = 0x28e;
      iRam10500454 = CREATEWINDOW();
      puStackY_2a = (undefined1 *)0xf8;
      uStackY_2c = 0x5c;
      uStackY_2e = 0x24;
      iStackY_30 = 0;
      uStackY_32 = 0x65;
      uStackY_34 = param_1;
      uStackY_36 = 0;
      uStackY_38 = 0;
      uStackY_3a = 0x1170;
      uStackY_3c = 700;
      iRam105018bc = CREATEWINDOW();
      puStackY_2a = (undefined1 *)0x5c;
      uStackY_2c = 0x24;
      uStackY_2e = 0;
      iStackY_30 = 0x66;
      uStackY_32 = param_1;
      uStackY_34 = 0;
      uStackY_36 = 0;
      uStackY_38 = 0x1170;
      uStackY_3a = 0x2ea;
      iRam105017c6 = CREATEWINDOW();
      puStackY_2a = (undefined1 *)0x24;
      uStackY_2c = 0x5000;
      uStackY_2e = 0x6d;
      iStackY_30 = param_1;
      uStackY_32 = 0;
      uStackY_34 = 0;
      uStackY_36 = 0x1170;
      uStackY_38 = 0x318;
      iRam105017b4 = CREATEWINDOW();
      puStackY_2a = (undefined1 *)0x0;
      uStackY_2c = 0;
      uStackY_2e = param_1;
      iStackY_30 = 0;
      uStackY_32 = 0;
      uStackY_34 = 0x1170;
      uStackY_36 = 0x345;
      iRam105015cc = CREATEWINDOW();
      puStackY_2a = (undefined1 *)0x0;
      uStackY_2c = param_1;
      uStackY_2e = 0;
      iStackY_30 = 0;
      uStackY_32 = 0x1170;
      uStackY_34 = 0x372;
      iRam10500440 = CREATEWINDOW();
      puStackY_2a = (undefined1 *)param_1;
      uStackY_2c = 0;
      uStackY_2e = 0;
      iStackY_30 = 0x1170;
      uStackY_32 = 0x39f;
      iRam105015c6 = CREATEWINDOW();
      puStackY_2a = (undefined1 *)0x0;
      uStackY_2c = 0;
      uStackY_2e = 0x1170;
      iStackY_30 = 0x3cc;
      iRam10501618 = CREATEWINDOW();
      puStackY_2a = (undefined1 *)0x0;
      uStackY_2c = 0x1170;
      uStackY_2e = 0x3fa;
      iRam10501600 = CREATEWINDOW();
      if ((((((iRam105015cc != 0) && (iRam10500440 != 0)) && (iRam105015c6 != 0)) &&
           ((iRam10501618 != 0 && (iRam10501600 != 0)))) &&
          ((iRam10500454 != 0 && ((iRam105018bc != 0 && (iRam105017c6 != 0)))))) &&
         ((iRam105017b4 != 0 && (iVar1 = FUN_1020_0000(0x15), iVar1 != 0)))) {
        SENDMESSAGE();
        SENDMESSAGE();
        SENDMESSAGE();
        SENDMESSAGE();
        SENDMESSAGE();
        FUN_1038_0000(0);
        profile_preferences_load(0x504);
        FUN_1020_07c2(0x504);
        if (param_2 == 0) {
          SETCLASSWORD();
          SETCLASSWORD();
        }
        else {
          GETCLASSWORD();
          SETCLASSWORD();
        }
        GETCLASSWORD();
        GETCLASSWORD();
        puStackY_2a = (undefined1 *)0x11;
        uStackY_2c = 0x1170;
        uStackY_2e = 0x580;
        SETWINDOWPOS();
        GETCLASSWORD();
        SHOWWINDOW();
        UPDATEWINDOW();
        puStackY_2a = (undefined1 *)0x5a2;
        FUN_1040_0000(0x6d);
        return 1;
      }
      FUN_1020_0552();
      LOADSTRING();
      LOADSTRING();
      MESSAGEBOX();
      DESTROYWINDOW();
    }
  }
  return 0;
}



void __cdecl16far profile_preferences_load(undefined2 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 uVar3;
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  
                    // Segment:    3
                    // Offset:     00004300
                    // Length:     0d75
                    // Min Alloc:  0d75
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  uStack_a = param_1;
  uStack_c = 0;
  uStack_e = 0x1048;
  uStack_10 = 0x1e;
  iVar1 = GETCLASSWORD();
  if (iVar1 == 0) {
    uStack_c = param_1;
    uStack_e = 2;
    uStack_10 = 0x1050;
    uStack_12 = 0x54;
    uStack_12 = GETPRIVATEPROFILEINT(0x1170,0x4a,0x1050,5,0x62,0x1050);
    SETCLASSWORD(0x1170);
    uStack_10 = param_1;
    uStack_12 = 4;
    uVar3 = 0x1050;
    uVar2 = GETPRIVATEPROFILEINT(0x1170,0x4a,0x1050,0,0x6c,0x1050,0x54);
    SETCLASSWORD(0x1170,uVar2,uVar3);
    uVar3 = 0x1050;
    uVar2 = GETPRIVATEPROFILEINT(0x1170,0x4a,0x1050,0,0x6e,0x1050,0x54);
    SETCLASSWORD(0x1170,uVar2,uVar3);
  }
  uRam10501788 = GETPRIVATEPROFILEINT(0x1170,0x4a,0x1050,0,0x70,0x1050,0x54);
  iRam105017a2 = GETPRIVATEPROFILEINT(0x1170,0x4a,0x1050,1,0x76,0x1050,0x54);
  LOADSTRING(0x1170,0xc,&uStack_12,unaff_SS,0x65);
  GETPRIVATEPROFILESTRING(0x1170,0x4a,0x1050,0xd,0x18de,0x1050,&uStack_12,unaff_SS,0x7c,0x1050,0x54)
  ;
  if (iRam105017a2 < 1) {
    iRam105017a2 = 1;
  }
  if (10 < iRam105017a2) {
    iRam105017a2 = 10;
  }
  uRam10501644 = uRam10501788;
  LSTRCPY(0x1170,0x18de,0x1050,0x1792);
  return;
}



void __cdecl16far profile_preferences_save(byte *param_1)

{
  int iVar1;
  undefined2 unaff_SS;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  byte abStack_e [2];
  byte *pbStack_c;
  byte *pbStack_a;
  
  runtime_stack_safety_check();
  pbStack_a = param_1;
  pbStack_c = (byte *)0x2;
  abStack_e[0] = 0x48;
  abStack_e[1] = 0x10;
  GETCLASSWORD();
  pbStack_c = param_1;
  abStack_e[0] = 0;
  abStack_e[1] = 0;
  iVar4 = 0x1170;
  iVar1 = GETWINDOWWORD(0x1170);
  if (iVar4 != iVar1) {
    abStack_e[0] = 10;
    abStack_e[1] = 0;
    pbVar2 = abStack_e;
    pbVar3 = param_1;
    iVar1 = GETWINDOWWORD(0x1170,0);
    FUN_1048_09be(iVar1,pbVar3,(uint)pbVar2);
    WRITEPRIVATEPROFILESTRING(0x1048,0x4a,0x1050,abStack_e,unaff_SS,0x62,0x1050,0x54);
  }
  iVar1 = GETCLASSWORD(0x1170,4);
  iVar4 = GETWINDOWWORD(0x1170,2);
  if (iVar1 != iVar4) {
    pbVar2 = abStack_e;
    pbVar3 = param_1;
    iVar1 = GETWINDOWWORD(0x1170,2);
    FUN_1048_09be(iVar1,pbVar3,(uint)pbVar2);
    WRITEPRIVATEPROFILESTRING(0x1048,0x4a,0x1050,abStack_e,unaff_SS,0x6c,0x1050,0x54);
  }
  iVar1 = GETCLASSWORD(0x1170,6);
  iVar4 = GETWINDOWWORD(0x1170,4);
  if (iVar1 != iVar4) {
    pbVar2 = abStack_e;
    iVar1 = GETWINDOWWORD(0x1170,4);
    FUN_1048_09be(iVar1,param_1,(uint)pbVar2);
    WRITEPRIVATEPROFILESTRING(0x1048,0x4a,0x1050,abStack_e,unaff_SS,0x6e,0x1050,0x54);
  }
  if (iRam10501644 != iRam10501788) {
    FUN_1048_09be(iRam10501788,abStack_e,10);
    WRITEPRIVATEPROFILESTRING(0x1048,0x4a,0x1050,abStack_e,unaff_SS,0x70,0x1050,0x54);
  }
  if (iRam10501612 != iRam105017a2) {
    FUN_1048_09be(iRam105017a2,abStack_e,10);
    WRITEPRIVATEPROFILESTRING(0x1048,0x4a,0x1050,abStack_e,unaff_SS,0x76,0x1050,0x54);
  }
  iVar1 = LSTRCMP(0x1170,0x18de,0x1050,0x1792);
  if (iVar1 != 0) {
    WRITEPRIVATEPROFILESTRING(0x1170,0x4a,0x1050,0x18de,0x1050,0x7c,0x1050,0x54);
  }
  return;
}



void __cdecl16far FUN_1010_0332(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  runtime_stack_safety_check();
  iVar1 = GETCLASSWORD(0x1048,8);
  if (iVar1 != param_1) {
    SETCLASSWORD(0x1170,param_1,8);
    iVar1 = 0;
    for (uVar3 = 0; (int)uVar3 < 10; uVar3 = uVar3 + 1) {
      iVar2 = profile_charts_load_and_validate(uVar3,iVar1);
      if (iVar2 != 0) {
        iVar1 = iVar1 + 1;
      }
    }
    if (iVar1 < 10) {
      for (; (int)uVar3 < 10; uVar3 = uVar3 + 1) {
        *(undefined2 *)(uVar3 * 0x20 + 0x164c) = 0;
        *(undefined2 *)(uVar3 * 0x20 + 0x1648) = 0;
        *(undefined2 *)(uVar3 * 0x20 + 0x164a) = 0;
        *(undefined1 *)(uVar3 * 0x20 + 0x164e) = 0;
      }
      for (uVar3 = 0; (int)uVar3 < 10; uVar3 = uVar3 + 1) {
        profile_charts_save_entry(uVar3);
      }
    }
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x1010047e)

void __cdecl16far FUN_1010_0404(int param_1)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  runtime_stack_safety_check();
  lVar6 = SENDMESSAGE(0x1048,0,0,0,0x403);
  if (lVar6 != 0) {
    FUN_1010_0332(param_1);
    uVar5 = 0x1170;
    iVar3 = SENDMESSAGE(0x1010,0,0,0,0x403);
    uVar9 = 0;
    bVar2 = false;
    do {
      if ((CONCAT22(*(undefined2 *)(uVar9 * 0x20 + 0x164a),*(undefined2 *)(uVar9 * 0x20 + 0x1648)) <
           lVar6) ||
         ((lVar6 == CONCAT22(*(undefined2 *)(uVar9 * 0x20 + 0x164a),
                             *(undefined2 *)(uVar9 * 0x20 + 0x1648)) &&
          (*(int *)(uVar9 * 0x20 + 0x164c) < iVar3)))) {
        bVar2 = true;
      }
      else {
        uVar9 = uVar9 + 1;
      }
    } while ((!bVar2) && ((int)uVar9 < 10));
    if (bVar2) {
      iVar7 = 9;
      while ((int)uVar9 < iVar7) {
        iVar4 = (iVar7 + -1) * 0x20;
        uVar1 = *(undefined2 *)(iVar4 + 0x164a);
        *(undefined2 *)(iVar7 * 0x20 + 0x1648) = *(undefined2 *)(iVar4 + 0x1648);
        *(undefined2 *)(iVar7 * 0x20 + 0x164a) = uVar1;
        *(undefined2 *)(iVar7 * 0x20 + 0x164c) = *(undefined2 *)((iVar7 + -1) * 0x20 + 0x164c);
        uVar8 = 0x1050;
        LSTRCPY(uVar5,0x202e,0x1050,iVar7 * 0x20 + 0x164e);
        uVar5 = 0x1010;
        profile_charts_save_entry(uVar8);
        iVar7 = uVar8 - 1;
      }
      FUN_1018_0b1c(param_1);
      *(undefined2 *)(uVar9 * 0x20 + 0x1648) = (int)lVar6;
      *(undefined2 *)(uVar9 * 0x20 + 0x164a) = (int)((ulong)lVar6 >> 0x10);
      *(int *)(uVar9 * 0x20 + 0x164c) = iVar3;
      LSTRCPY(0x1018,0x1628,0x1050,uVar9 * 0x20 + 0x164e);
      profile_charts_save_entry(uVar9);
    }
  }
  return;
}



void __cdecl16far profile_charts_clear(undefined2 param_1)

{
  uint uVar1;
  
  runtime_stack_safety_check();
  SETCLASSWORD(0x1048,param_1,8);
  for (uVar1 = 0; (int)uVar1 < 10; uVar1 = uVar1 + 1) {
    *(undefined2 *)(uVar1 * 0x20 + 0x164c) = 0;
    *(undefined2 *)(uVar1 * 0x20 + 0x1648) = 0;
    *(undefined2 *)(uVar1 * 0x20 + 0x164a) = 0;
    *(undefined1 *)(uVar1 * 0x20 + 0x164e) = 0;
    profile_charts_save_entry(uVar1);
  }
  return;
}



undefined2 __cdecl16far profile_charts_load_and_validate(uint param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  int b_hi;
  int iVar5;
  long lVar6;
  uint uStack_a;
  
  runtime_stack_safety_check();
  s_chart_1050_0084[5] = (char)param_1 + '0';
  GETPRIVATEPROFILESTRING(0x1048,0x4a,0x1050,0x32,0x15ce,0x1050,0x16a,0x1050,0x84,0x1050,0x54);
  iVar2 = LSTRLEN(0x1170,0x15ce);
  if (iVar2 < 0x14) {
    uVar3 = 0;
  }
  else {
    lVar6 = 0;
    iVar2 = 0xb;
    while( true ) {
      iVar5 = (int)((ulong)lVar6 >> 0x10);
      uStack_a = (uint)lVar6;
      if (0x10 < iVar2) break;
      if (*(char *)(iVar2 + 0x15ce) == ' ') {
        *(undefined1 *)(iVar2 + 0x15ce) = 0x30;
      }
      if ((*(char *)(iVar2 + 0x15ce) < '0') || ('9' < *(char *)(iVar2 + 0x15ce))) {
        return 0;
      }
      uVar4 = (int)*(char *)(iVar2 + 0x15ce) - 0x30;
      b_hi = (int)uVar4 >> 0xf;
      lVar6 = _2bit_multiply(uStack_a,iVar5,uVar4,b_hi);
      lVar6 = lVar6 + CONCAT22(b_hi,uVar4);
      iVar2 = iVar2 + 1;
    }
    *(uint *)(param_2 * 0x20 + 0x1648) = uStack_a;
    *(int *)(param_2 * 0x20 + 0x164a) = iVar5;
    lVar6 = 0;
    iVar2 = 0x11;
    while( true ) {
      uStack_a = (uint)lVar6;
      if (0x13 < iVar2) break;
      if (*(char *)(iVar2 + 0x15ce) == ' ') {
        *(undefined1 *)(iVar2 + 0x15ce) = 0x30;
      }
      if ((*(char *)(iVar2 + 0x15ce) < '0') || ('9' < *(char *)(iVar2 + 0x15ce))) {
        return 0;
      }
      uVar4 = (int)*(char *)(iVar2 + 0x15ce) - 0x30;
      iVar5 = (int)uVar4 >> 0xf;
      lVar6 = _2bit_multiply(uStack_a,(int)((ulong)lVar6 >> 0x10),uVar4,iVar5);
      lVar6 = lVar6 + CONCAT22(iVar5,uVar4);
      iVar2 = iVar2 + 1;
    }
    *(uint *)(param_2 * 0x20 + 0x164c) = uStack_a;
    iVar2 = 0x14;
    do {
      *(undefined1 *)(param_2 * 0x20 + iVar2 + 0x163a) = *(undefined1 *)(iVar2 + 0x15ce);
      pcVar1 = (char *)(iVar2 + 0x15ce);
      iVar2 = iVar2 + 1;
    } while (*pcVar1 != '\0');
    compute_signature(param_1,*(uint *)(param_2 * 0x20 + 0x1648),*(uint *)(param_2 * 0x20 + 0x164a),
                      *(uint *)(param_2 * 0x20 + 0x164c),param_2 * 0x20 + 0x164e,0x1050);
    uVar3 = 1;
    for (iVar2 = 0; iVar2 < 10; iVar2 = iVar2 + 1) {
      if (*(char *)(iVar2 + 0x15ce) != *(char *)(iVar2 + 0x18ab)) {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



void __cdecl16far profile_charts_save_entry(uint param_1)

{
  runtime_stack_safety_check();
  compute_signature(param_1,*(uint *)(param_1 * 0x20 + 0x1648),*(uint *)(param_1 * 0x20 + 0x164a),
                    *(uint *)(param_1 * 0x20 + 0x164c),param_1 * 0x20 + 0x164e,0x1050);
  _WSPRINTF(0x1010,0x15ce,0x1050,0x16b,0x1050,0x18ab,0x1050,param_1,
            *(undefined2 *)(param_1 * 0x20 + 0x1648),*(undefined2 *)(param_1 * 0x20 + 0x164a),
            *(undefined2 *)(param_1 * 0x20 + 0x164c),param_1 * 0x20 + 0x164e,0x1050);
  s_chart_1050_0084[5] = (char)param_1 + '0';
  WRITEPRIVATEPROFILESTRING(0x1170,0x4a,0x1050,0x15ce,0x1050,0x84,0x1050,0x54);
  return;
}



void __cdecl16far
compute_signature(uint param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined2 param_6
                 )

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uStackY_32;
  int iStackY_30;
  int iStackY_2e;
  uint auStackY_2c [9];
  undefined2 uStackY_1a;
  undefined2 uStackY_18;
  
  runtime_stack_safety_check();
  FUN_1048_0740(param_1 + 0x3b);
  for (iStackY_2e = 0; iStackY_2e < 10; iStackY_2e = iStackY_2e + 1) {
    uVar2 = FUN_1048_0754();
    auStackY_2c[iStackY_2e * 2] = (int)uVar2 % 0x7a7;
    auStackY_2c[iStackY_2e * 2 + 1] = (int)uVar2 % 0x7a7 >> 0xf;
  }
  uVar3 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_1;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + ((int)param_1 >> 0xf) + (uint)CARRY2(uVar2,param_1);
  uVar3 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_1;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + ((int)param_1 >> 0xf) + (uint)CARRY2(uVar2,param_1);
  uVar3 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_2;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + param_3 + (uint)CARRY2(uVar2,param_2);
  uVar3 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_2;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + param_3 + (uint)CARRY2(uVar2,param_2);
  uVar7 = FUN_1048_0784(param_2,param_3,0xd,0);
  uVar3 = FUN_1048_0754();
  iStackY_30 = (int)((ulong)uVar7 >> 0x10);
  uStackY_32 = (uint)uVar7;
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uStackY_32;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + iStackY_30 + (uint)CARRY2(uVar2,uStackY_32);
  uVar7 = FUN_1048_0850(param_2,param_3,0xd,0);
  uVar3 = FUN_1048_0754();
  iStackY_30 = (int)((ulong)uVar7 >> 0x10);
  uStackY_32 = (uint)uVar7;
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uStackY_32;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + iStackY_30 + (uint)CARRY2(uVar2,uStackY_32);
  uVar7 = FUN_1048_0784(param_2,param_3,0x6f,0);
  uVar3 = FUN_1048_0754();
  iStackY_30 = (int)((ulong)uVar7 >> 0x10);
  uStackY_32 = (uint)uVar7;
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uStackY_32;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + iStackY_30 + (uint)CARRY2(uVar2,uStackY_32);
  uVar7 = FUN_1048_0850(param_2,param_3,0x6f,0);
  uVar3 = FUN_1048_0754();
  iStackY_30 = (int)((ulong)uVar7 >> 0x10);
  uStackY_32 = (uint)uVar7;
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uStackY_32;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + iStackY_30 + (uint)CARRY2(uVar2,uStackY_32);
  uVar7 = FUN_1048_0784(param_2,param_3,0x309,0);
  uVar3 = FUN_1048_0754();
  iStackY_30 = (int)((ulong)uVar7 >> 0x10);
  uStackY_32 = (uint)uVar7;
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uStackY_32;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + iStackY_30 + (uint)CARRY2(uVar2,uStackY_32);
  uVar7 = FUN_1048_0850(param_2,param_3,0x309,0);
  uVar3 = FUN_1048_0754();
  iStackY_30 = (int)((ulong)uVar7 >> 0x10);
  uStackY_32 = (uint)uVar7;
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uStackY_32;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + iStackY_30 + (uint)CARRY2(uVar2,uStackY_32);
  uVar3 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_4;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + ((int)param_4 >> 0xf) + (uint)CARRY2(uVar2,param_4);
  uVar3 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_4;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + ((int)param_4 >> 0xf) + (uint)CARRY2(uVar2,param_4);
  uVar3 = (int)param_4 / 7;
  uVar4 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar4 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar3;
  auStackY_2c[((int)uVar4 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar4 % 10) * 2 + 1] + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
  uVar4 = (int)param_4 % 7;
  uVar3 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar3 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar4;
  auStackY_2c[((int)uVar3 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar3 % 10) * 2 + 1] + ((int)uVar4 >> 0xf) + (uint)CARRY2(uVar2,uVar4);
  uVar3 = LSTRLEN();
  uVar4 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar4 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar3;
  auStackY_2c[((int)uVar4 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar4 % 10) * 2 + 1] + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
  uVar3 = LSTRLEN();
  uVar4 = FUN_1048_0754();
  puVar1 = auStackY_2c + ((int)uVar4 % 10) * 2;
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar3;
  auStackY_2c[((int)uVar4 % 10) * 2 + 1] =
       auStackY_2c[((int)uVar4 % 10) * 2 + 1] + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
  iStackY_2e = 0;
  while( true ) {
    iVar5 = LSTRLEN();
    if (iVar5 <= iStackY_2e) break;
    uVar3 = (uint)*(char *)(param_5 + iStackY_2e);
    uVar4 = FUN_1048_0754();
    puVar1 = auStackY_2c + ((int)uVar4 % 10) * 2;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    auStackY_2c[((int)uVar4 % 10) * 2 + 1] =
         auStackY_2c[((int)uVar4 % 10) * 2 + 1] + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
    uVar3 = (uint)*(char *)(param_5 + iStackY_2e);
    uVar4 = FUN_1048_0754();
    puVar1 = auStackY_2c + ((int)uVar4 % 10) * 2;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    auStackY_2c[((int)uVar4 % 10) * 2 + 1] =
         auStackY_2c[((int)uVar4 % 10) * 2 + 1] + ((int)uVar3 >> 0xf) + (uint)CARRY2(uVar2,uVar3);
    iStackY_2e = iStackY_2e + 1;
  }
  uVar6 = 0x1170;
  for (iStackY_2e = 0; iStackY_2e < 10; iStackY_2e = iStackY_2e + 1) {
    uStackY_1a = 0xd41;
    uStackY_18 = uVar6;
    uVar7 = FUN_1048_0850(auStackY_2c[iStackY_2e * 2],auStackY_2c[iStackY_2e * 2 + 1],0x5f,0);
    *(char *)(iStackY_2e + 0x18ab) = (char)uVar7 + ' ';
    uVar6 = 0x1048;
  }
  uRam105018b5 = 0;
  uVar6 = GETCURRENTTIME();
  FUN_1048_0740(uVar6);
  return;
}



undefined2 __cdecl16far FUN_1018_0000(void)

{
  ulong uVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  bool bVar6;
  char *pcVar7;
  undefined2 local_22;
  undefined2 uStackY_20;
  undefined2 uStackY_1e;
  undefined2 uStackY_1c;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  
                    // Segment:    4
                    // Offset:     00005140
                    // Length:     0e3c
                    // Min Alloc:  0e3d
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  iVar8 = 0;
  iVar3 = FINDRESOURCE();
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    iVar3 = SIZEOFRESOURCE();
    if (iVar8 == 0) {
      iVar8 = 0;
      if (iVar3 != 0xd0) {
        return 0;
      }
    }
    else {
      FUN_1048_09be((int)&local_22,(byte *)&local_22,10);
      iVar8 = 0;
      uStackY_1c = 0x78;
      MESSAGEBOX();
    }
    uVar13 = uRam105018c6;
    iVar3 = LOADRESOURCE();
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      iVar11 = 0x1170;
      iVar9 = 0xa6;
      pcVar7 = (char *)LOCKRESOURCE();
      if (pcVar7 != (char *)0x0) {
        uVar10 = 0;
        iVar11 = 0;
        for (uVar12 = 0; pcVar2 = pcVar7, uVar12 < uVar13; uVar12 = uVar12 + 1) {
          uVar1 = (ulong)pcVar7 >> 0x10;
          pcVar7 = (char *)CONCAT22((int)uVar1,pcVar14 + 1);
          uVar5 = ((int)*pcVar2 + 0xbU) % (uVar12 + 0xd);
          bVar6 = CARRY2(uVar10,uVar5);
          uVar10 = uVar10 + uVar5;
          iVar11 = iVar11 + (uint)bVar6;
        }
        if (iVar8 != 0) {
          uStackY_1c = 0x1170;
          uStackY_1e = 0x115;
          FUN_1048_09da((int)&local_22,10,(byte *)&local_22,10);
          iVar11 = 0;
          uStackY_1c = 0x26e;
          uStackY_1e = 0;
          uStackY_20 = 0x1048;
          local_22 = 0x12f;
          MESSAGEBOX();
        }
        iVar9 = iVar3;
        GLOBALUNLOCK();
        uStackY_1c = 0x13f;
        FREERESOURCE();
        iVar8 = iVar3;
      }
      if ((iVar8 == 0) && ((iVar9 != 0x1f82 || (iVar11 != 0)))) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}



void __cdecl16far FUN_1018_0164(undefined2 param_1)

{
  undefined4 uVar1;
  
  runtime_stack_safety_check();
  FUN_1040_0000(0x6d);
  uVar1 = MAKEPROCINSTANCE(0x1040,uRam105018c6,0x1c6);
  DIALOGBOX(0x1170,uVar1,param_1,0x287,0x1050);
  FREEPROCINSTANCE(0x1170,(int)uVar1);
  return;
}



undefined2 __stdcall16far
ABOUTDLGPROC(undefined2 param_1,undefined2 param_2,undefined2 param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  int iStack_28;
  int iStack_26;
  undefined2 uStack_24;
  int iStack_22;
  int iStack_20;
  int iStack_1e;
  int iStack_1c;
  undefined2 uStack_1a;
  int iStack_18;
  int iStack_16;
  undefined1 *puStack_14;
  
  uVar4 = 0x1048;
  runtime_stack_safety_check();
  if (param_4 == 0xf) {
    BEGINPAINT();
    GETCLIENTRECT();
    if (iRam105015c8 != 0) {
      puStack_14 = (undefined1 *)0x1170;
      iStack_16 = 0x285;
      uVar4 = CREATEPEN();
      puStack_14 = (undefined1 *)uRam105018fa;
      iStack_16 = 0x1170;
      iStack_18 = 0x299;
      uVar1 = CREATEPEN();
      puStack_14 = (undefined1 *)0x1170;
      iStack_16 = 0x2a5;
      uVar2 = SELECTOBJECT();
      puStack_14 = (undefined1 *)0x0;
      iStack_16 = iStack_26 + -2;
      iStack_18 = 0x1170;
      uStack_1a = 0x2b9;
      MOVETO();
      puStack_14 = (undefined1 *)uStack_24;
      iStack_16 = 0;
      iStack_18 = 0;
      uStack_1a = 0x1170;
      iStack_1c = 0x2c5;
      LINETO();
      iStack_16 = uStack_24;
      iStack_18 = iStack_28 + -1;
      uStack_1a = 0;
      iStack_1c = 0x1170;
      iStack_1e = 0x2d4;
      LINETO();
      iStack_18 = uStack_24;
      iStack_1c = 0x1170;
      iStack_1e = 0x2df;
      uStack_1a = uVar4;
      SELECTOBJECT();
      uStack_1a = uStack_24;
      iStack_1c = iStack_28 + -1;
      iStack_1e = 1;
      iStack_20 = 0x1170;
      iStack_22 = 0x2ee;
      MOVETO();
      iStack_1c = uStack_24;
      iStack_1e = iStack_28 + -1;
      iStack_20 = iStack_26 + -1;
      iStack_22 = 0x1170;
      uStack_24 = 0x300;
      LINETO();
      iStack_1e = uStack_24;
      iStack_20 = 0;
      iStack_22 = iStack_26 + -1;
      uStack_24 = 0x1170;
      LINETO();
      iStack_20 = uStack_24;
      uStack_24 = 0x1170;
      iStack_22 = uVar2;
      SELECTOBJECT();
      uStack_24 = 0x1170;
      iStack_22 = uVar1;
      DELETEOBJECT();
      uStack_24 = uVar4;
      DELETEOBJECT();
    }
    iVar3 = LOADBITMAP();
    if (iVar3 != 0) {
      SELECTOBJECT();
      uVar4 = 0x73;
      BITBLT(0x1170,0x20,0xcc,0,0,uRam105015ca,0xc,0x73,0x46);
      SELECTOBJECT(0x1170,uVar4);
      DELETEOBJECT(0x1170,uVar4);
    }
    uVar4 = 0x1170;
    ENDPAINT(0x1170,&uStack_24,unaff_SS);
  }
  else {
    if (param_4 == 0x14) {
      uVar4 = CREATESOLIDBRUSH();
      uVar1 = SELECTOBJECT();
      puStack_14 = (undefined1 *)0x1170;
      iStack_16 = 0x221;
      GETCLIENTRECT();
      puStack_14 = &stack0xfff0;
      iStack_18 = 0x1170;
      uStack_1a = 0x233;
      iStack_16 = uVar4;
      FILLRECT();
      iStack_16 = 0x1170;
      iStack_18 = 0x23e;
      puStack_14 = (undefined1 *)uVar1;
      SELECTOBJECT();
      iStack_16 = 0x1170;
      iStack_18 = 0x246;
      puStack_14 = (undefined1 *)uVar4;
      DELETEOBJECT();
      return 1;
    }
    if (param_4 != 0x19) {
      if (param_4 == 0x110) {
        return 1;
      }
      if (param_4 == 0x111) {
        ENDDIALOG();
        return 1;
      }
      return 0;
    }
  }
  SETBKMODE(uVar4,1);
  uVar4 = GETSTOCKOBJECT(0x1170,5,param_3);
  return uVar4;
}



void __cdecl16far FUN_1018_03f4(undefined2 param_1)

{
  undefined4 uVar1;
  
  runtime_stack_safety_check();
  uVar1 = MAKEPROCINSTANCE(0x1048,uRam105018c6,0x44c);
  DIALOGBOX(0x1170,uVar1,param_1,0x29c,0x1050);
  FREEPROCINSTANCE(0x1170,(int)uVar1);
  return;
}



undefined2 __stdcall16far CHARTDLGPROC(void)

{
  undefined2 uVar1;
  int in_stack_0000000a;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int local_28;
  int local_26;
  undefined2 local_24;
  int iStack_22;
  int iStack_20;
  int iStack_1e;
  undefined2 *puStack_1c;
  int iVar7;
  undefined1 *puVar8;
  
  uVar1 = 0x1048;
  runtime_stack_safety_check();
  if (in_stack_0000000a == 0xf) {
    BEGINPAINT();
    GETCLIENTRECT();
    if (iRam105015c8 == 0) {
      CREATEPEN();
      SELECTOBJECT();
      MOVETO();
      LINETO();
      SELECTOBJECT();
      DELETEOBJECT();
    }
    else {
      CREATEPEN();
      CREATEPEN();
      SELECTOBJECT();
      MOVETO();
      puStack_1c = (undefined2 *)0x5eb;
      LINETO();
      puStack_1c = (undefined2 *)0x1170;
      iStack_1e = 0x5fa;
      LINETO();
      puStack_1c = (undefined2 *)0x1170;
      iStack_1e = 0x605;
      SELECTOBJECT();
      puStack_1c = (undefined2 *)(local_28 + -1);
      iStack_1e = 1;
      iStack_20 = 0x1170;
      iStack_22 = 0x614;
      MOVETO();
      puStack_1c = (undefined2 *)local_24;
      iStack_1e = local_28 + -1;
      iStack_20 = local_26 + -1;
      iStack_22 = 0x1170;
      local_24 = 0x626;
      LINETO();
      iStack_1e = local_24;
      iStack_20 = 0;
      iStack_22 = local_26 + -1;
      local_24 = 0x1170;
      LINETO();
      iStack_20 = local_24;
      iStack_22 = 0xd;
      local_24 = 0x22;
      MOVETO();
      iStack_22 = local_24;
      local_24 = 0x634;
      LINETO();
      SELECTOBJECT();
      MOVETO();
      LINETO(0x1170);
      SELECTOBJECT(0x1170);
      MOVETO(0x1170,0x16,0x2f);
      uVar2 = local_24;
      LINETO(0x1170,0xda,0x2f);
      uVar6 = local_24;
      MOVETO(0x1170,0x16,0x69);
      LINETO(0x1170,0xda,0x69);
      uVar5 = local_24;
      MOVETO(0x1170,0x16,0x96);
      LINETO(0x1170,0xda,0x96);
      SELECTOBJECT(0x1170,uVar2);
      MOVETO(0x1170,0x16,0x30);
      LINETO(0x1170,0xda,0x30);
      MOVETO(0x1170,0x16,0x6a);
      LINETO(0x1170,0xda,0x6a);
      uVar4 = local_24;
      MOVETO(0x1170,0x16,0x97);
      uVar3 = local_24;
      LINETO(0x1170,0xda,0x97);
      uVar1 = local_24;
      SELECTOBJECT(0x1170,uVar5);
      DELETEOBJECT(0x1170,uVar2);
      DELETEOBJECT(0x1170,uVar6,uVar2,uVar1,uVar3,uVar4);
    }
    puStack_1c = &local_24;
    iStack_1e = 0x1170;
    uVar1 = 0x1170;
    iStack_20 = 0x7a7;
    ENDPAINT();
  }
  else {
    if (in_stack_0000000a == 0x14) {
      CREATESOLIDBRUSH();
      SELECTOBJECT();
      GETCLIENTRECT();
      FILLRECT();
      SELECTOBJECT();
      DELETEOBJECT();
      return 1;
    }
    if (in_stack_0000000a != 0x19) {
      if (in_stack_0000000a == 0x110) {
        for (iVar7 = 0; iVar7 < 10; iVar7 = iVar7 + 1) {
          if ((*(int *)(iVar7 * 0x20 + 0x1648) != 0) || (*(int *)(iVar7 * 0x20 + 0x164a) != 0)) {
            FUN_1048_09da(*(int *)(iVar7 * 0x20 + 0x1648),*(uint *)(iVar7 * 0x20 + 0x164a),
                          &stack0xfff2,10);
            puVar8 = &stack0xfff2;
            SETDLGITEMTEXT();
            iVar7 = *(int *)((int)puVar8 * 0x20 + 0x164c);
            SETDLGITEMINT();
            iVar7 = iVar7 + 0x79;
            SETDLGITEMTEXT();
          }
        }
        return 1;
      }
      if (in_stack_0000000a == 0x111) {
        ENDDIALOG();
        return 1;
      }
      return 0;
    }
  }
  puStack_1c = (undefined2 *)0x1;
  iStack_20 = 0x7b1;
  iStack_1e = uVar1;
  SETBKMODE();
  puStack_1c = (undefined2 *)0x5;
  iStack_1e = 0x1170;
  iStack_20 = 0x7b8;
  uVar1 = GETSTOCKOBJECT();
  return uVar1;
}



void __cdecl16far FUN_1018_07f0(undefined2 param_1)

{
  undefined4 uVar1;
  
  runtime_stack_safety_check();
  uVar1 = MAKEPROCINSTANCE(0x1048,uRam105018c6,0x848);
  DIALOGBOX(0x1170,uVar1,param_1,0x2a8,0x1050);
  FREEPROCINSTANCE(0x1170,(int)uVar1);
  return;
}



undefined2 __stdcall16far
PICTUREDLGPROC(undefined2 param_1,undefined2 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  long lVar3;
  
  runtime_stack_safety_check();
  if (param_4 == 0xf) {
    BEGINPAINT();
    GETCLIENTRECT();
    if (iRam105015c8 != 0) {
      CREATEPEN();
      CREATEPEN();
      SELECTOBJECT();
      MOVETO();
      LINETO();
      LINETO();
      SELECTOBJECT();
      MOVETO();
      LINETO();
      LINETO();
      SELECTOBJECT();
      DELETEOBJECT();
      DELETEOBJECT();
    }
    ENDPAINT();
  }
  else {
    if (param_4 == 0x14) {
      CREATESOLIDBRUSH();
      SELECTOBJECT();
      GETCLIENTRECT();
      FILLRECT();
      SELECTOBJECT();
      DELETEOBJECT();
      return 1;
    }
    if (param_4 != 0x19) {
      if (param_4 == 0x110) {
        LOADSTRING();
        SENDDLGITEMMESSAGE();
        SENDDLGITEMMESSAGE();
        lVar3 = SENDDLGITEMMESSAGE();
        if (lVar3 == -1) {
          SENDDLGITEMMESSAGE();
        }
        return 1;
      }
      if (param_4 == 0x111) {
        if (param_3 == 1) {
          iVar1 = SENDDLGITEMMESSAGE();
          if (iVar1 != -1) {
            SENDDLGITEMMESSAGE();
            iVar1 = LSTRCMP();
            if (iVar1 != 0) {
              LSTRCPY();
            }
          }
          uVar2 = GETWINDOWWORD();
          FUN_1020_07c2(uVar2);
          uVar2 = GETWINDOWWORD();
          FUN_1038_00ac(uVar2);
          ENDDIALOG();
        }
        else if (param_3 == 2) {
          ENDDIALOG();
        }
        return 1;
      }
      return 0;
    }
  }
  SETBKMODE();
  uVar2 = GETSTOCKOBJECT();
  return uVar2;
}



void __cdecl16far FUN_1018_0b1c(undefined2 param_1)

{
  long lVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  int in_stack_0000fff4;
  
  runtime_stack_safety_check();
  if (iRam10501896 != 0) {
    in_stack_0000fff4 = 0x1050;
    iVar2 = FINDRESOURCE(0x1048,0x2b6,0x1050,699,0x1050);
    if (iVar2 != 0) {
      in_stack_0000fff4 = LOADRESOURCE(0x1170,iVar2);
      if (in_stack_0000fff4 != 0) {
        lRam105017ba = LOCKRESOURCE(0x1170,in_stack_0000fff4);
      }
    }
  }
  FUN_1040_0000(0x6c);
  uVar7 = 0x1018;
  uVar4 = MAKEPROCINSTANCE(0x1040,uRam105018c6,0xc02);
  uVar5 = (undefined2)((ulong)uVar4 >> 0x10);
  uVar6 = uRam105018c6;
  DIALOGBOX(0x1170,uVar4,param_1,0x2c6,0x1050);
  FREEPROCINSTANCE(0x1170,(int)uVar4);
  uVar3 = 0x1040;
  FUN_1040_0000(0);
  lVar1 = lRam105017ba;
  if (iRam10501896 != 0) {
    if (lRam105017ba != 0) {
      uVar3 = 0x1170;
      GLOBALUNLOCK(0x1040,in_stack_0000fff4,uVar5,uVar6,uVar7);
    }
    lVar1 = lRam105017ba;
    if (in_stack_0000fff4 != 0) {
      FREERESOURCE(uVar3,in_stack_0000fff4);
      lVar1 = lRam105017ba;
    }
  }
  lRam105017ba._2_2_ = (undefined2)((ulong)lVar1 >> 0x10);
  lRam105017ba._0_2_ = (undefined2)lVar1;
  return;
}



undefined2 __stdcall16far NAMEDLGPROC(undefined2 param_1,undefined2 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  
  runtime_stack_safety_check();
  if (param_4 == 0xf) {
    BEGINPAINT();
    GETCLIENTRECT();
    if (iRam105015c8 != 0) {
      CREATEPEN();
      CREATEPEN();
      SELECTOBJECT();
      MOVETO();
      LINETO();
      LINETO();
      SELECTOBJECT();
      MOVETO();
      LINETO();
      LINETO();
      SELECTOBJECT();
      DELETEOBJECT();
      DELETEOBJECT();
    }
    ENDPAINT();
  }
  else {
    if (param_4 == 0x14) {
      CREATESOLIDBRUSH();
      SELECTOBJECT();
      GETCLIENTRECT();
      FILLRECT();
      SELECTOBJECT();
      DELETEOBJECT();
      return 1;
    }
    if (param_4 != 0x19) {
      if (param_4 == 0x110) {
        uRam10501628 = 0;
        SENDDLGITEMMESSAGE();
        GETDLGITEM();
        SETFOCUS();
        return 1;
      }
      if (param_4 == 0x111) {
        if (param_3 == 1) {
          GETDLGITEMTEXT();
          ENDDIALOG();
        }
        return 1;
      }
      return 0;
    }
  }
  iVar1 = FUN_1048_08f0();
  if (iVar1 == 1) {
    uVar2 = DEFWINDOWPROC(0x1048,param_1,param_2);
  }
  else {
    SETBKMODE();
    uVar2 = GETSTOCKOBJECT();
  }
  return uVar2;
}



undefined2 __cdecl16far FUN_1020_0000(undefined2 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  int iVar12;
  undefined2 uVar13;
  
                    // Segment:    5
                    // Offset:     00006120
                    // Length:     0dc7
                    // Min Alloc:  0dc7
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  uVar8 = GETDC(0x1048,param_1);
  uRam1050189e = GETDEVICECAPS(0x1170,0x18);
  iRam105018a0 = (int)uRam1050189e >> 0xf;
  if ((iRam105018a0 < 0) || ((iRam105018a0 < 1 && (uRam1050189e < 3)))) {
    iRam105015c8 = 0;
  }
  else {
    iRam105015c8 = 1;
  }
  if (iRam105015c8 == 0) {
    uRam10501904 = 0;
    uRam10501906 = 0;
    uRam105017a8 = 0xffff;
    uRam105017aa = 0xff;
    uRam105018fa = 0xffff;
    uRam105018fc = 0xff;
    uRam10501898 = 0xffff;
    uRam1050189a = 0xff;
    uRam1050161e = 0;
    uRam10501620 = 0;
    uRam1050190a = 0xffff;
    uRam1050190c = 0xff;
    uRam105018f6 = 0xffff;
    uRam105018f8 = 0xff;
    uRam10501614 = 0x7f7f;
    uRam10501616 = 0x7f;
    iRam105018dc = LOADBITMAP(0x1170,0x1a5,0x1050);
    iRam10501902 = LOADBITMAP(0x1170,0x1b1,0x1050);
    uVar13 = uRam105018c6;
    iRam10501642 = LOADBITMAP(0x1170,0x1ba,0x1050);
    uVar11 = uRam105018c6;
    iRam1050160e = LOADBITMAP(0x1170,0x1c3,0x1050);
    uVar10 = uRam105018c6;
    iRam10500456 = LOADBITMAP(0x1170,0x1cb,0x1050);
  }
  else {
    uRam10501904 = 0;
    uRam10501906 = 0;
    uRam105017a8 = 0x7f7f;
    uRam105017aa = 0x7f;
    uRam105018fa = 0xffff;
    uRam105018fc = 0xff;
    uRam10501898 = 0xc0c0;
    uRam1050189a = 0xc0;
    uRam1050161e = 0;
    uRam10501620 = 0;
    uRam1050190a = 0x7f;
    uRam1050190c = 0;
    uRam105018f6 = 0;
    uRam105018f8 = 0x7f;
    uRam10501614 = 0x7f00;
    uRam10501616 = 0x7f;
    iRam105018dc = LOADBITMAP(0x1170,0x17a,0x1050);
    iRam105017a4 = LOADBITMAP(0x1170,0x184,0x1050);
    uVar13 = uRam105018c6;
    iRam10501902 = LOADBITMAP(0x1170,0x18a,0x1050);
    uVar11 = uRam105018c6;
    iRam10501642 = LOADBITMAP(0x1170,0x191,0x1050);
    uVar10 = uRam105018c6;
    iRam1050160e = LOADBITMAP(0x1170,0x198,0x1050);
    iRam10500456 = LOADBITMAP(0x1170,0x19e,0x1050);
  }
  uRam1050189c = 0;
  iRam105015ca = CREATECOMPATIBLEDC(0x1170,uVar8,uVar10,uVar11,uVar13);
  iRam105017e0 = CREATECOMPATIBLEDC(0x1170,uVar8);
  iRam10500442 = CREATECOMPATIBLEDC(0x1170,uVar8);
  iRam1050044c = CREATECOMPATIBLEDC(0x1170,uVar8);
  iRam1050044a = CREATECOMPATIBLEBITMAP(0x1170,0x17b,0x1c3);
  iRam10500458 = CREATECOMPATIBLEBITMAP(0x1170,0x15c,0x1a4);
  iVar12 = 0x1e;
  uVar10 = uVar8;
  iRam10501900 = CREATECOMPATIBLEBITMAP(0x1170,0x1e,0x1e);
  if ((iRam10500442 != 0) && (iRam1050044a != 0)) {
    iVar12 = iRam10500442;
    iRam105018ec = SELECTOBJECT(0x1170,iRam1050044a);
  }
  if ((iRam1050044c != 0) && (iRam10500458 != 0)) {
    iRam10501622 = SELECTOBJECT(0x1170,iRam10500458);
  }
  RELEASEDC(0x1170,uVar8);
  SETERRORMODE(0x1170,0x8000,param_1,iVar12,uVar10);
  uVar8 = 0x1050;
  uRam10501896 = LOADLIBRARY(0x1170,0x1d4);
  uVar9 = CONCAT22(uRam10501790,uRam1050178e);
  if (uRam10501896 < 0x21) {
    uRam10501896 = 0;
    uVar1 = CONCAT22(uRam10500450._2_2_,(undefined2)uRam10500450);
    uVar2 = CONCAT22(uRam10501604._2_2_,(undefined2)uRam10501604);
    uVar3 = CONCAT22(uRam105017cc._2_2_,(undefined2)uRam105017cc);
    uVar4 = CONCAT22(uRam105017d0._2_2_,(undefined2)uRam105017d0);
    uVar5 = CONCAT22(uRam105018a2._2_2_,(undefined2)uRam105018a2);
    uVar6 = CONCAT22(uRam105018b6._2_2_,(undefined2)uRam105018b6);
    uVar7 = CONCAT22(uRam105018c2._2_2_,(undefined2)uRam105018c2);
  }
  else {
    uVar10 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x1dd,0x1050,0x1e2,0x1050);
    if (iVar12 != 0) {
      uVar11 = uRam105018c6;
      iRam10501624 = LOADRESOURCE(0x1170,iVar12);
      if (iRam10501624 != 0) {
        uRam105018c2 = LOCKRESOURCE(0x1170,iRam10501624,uVar11,uVar10,uVar8);
      }
    }
    uVar8 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x1ec,0x1050,0x1f1,0x1050);
    if (iVar12 != 0) {
      uVar10 = uRam105018c6;
      iRam105017a6 = LOADRESOURCE(0x1170,iVar12);
      if (iRam105017a6 != 0) {
        uRam10501604 = LOCKRESOURCE(0x1170,iRam105017a6,uVar10,uVar8);
      }
    }
    uVar8 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x1fa,0x1050,0x1ff,0x1050);
    if (iVar12 != 0) {
      uVar10 = uRam105018c6;
      iRam1050161c = LOADRESOURCE(0x1170,iVar12);
      if (iRam1050161c != 0) {
        uRam10500450 = LOCKRESOURCE(0x1170,iRam1050161c,uVar10,uVar8);
      }
    }
    uVar8 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x208,0x1050,0x20d,0x1050);
    if (iVar12 != 0) {
      uVar10 = uRam105018c6;
      iRam10500444 = LOADRESOURCE(0x1170,iVar12);
      if (iRam10500444 != 0) {
        uRam105018a2 = LOCKRESOURCE(0x1170,iRam10500444,uVar10,uVar8);
      }
    }
    uVar8 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x216,0x1050,0x21b,0x1050);
    if (iVar12 != 0) {
      uVar10 = uRam105018c6;
      iRam10501908 = LOADRESOURCE(0x1170,iVar12);
      if (iRam10501908 != 0) {
        uRam105018b6 = LOCKRESOURCE(0x1170,iRam10501908,uVar10,uVar8);
      }
    }
    uVar8 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x225,0x1050,0x22a,0x1050);
    if (iVar12 != 0) {
      uVar10 = uRam105018c6;
      iRam105017b8 = LOADRESOURCE(0x1170,iVar12);
      if (iRam105017b8 != 0) {
        uRam105017d0 = LOCKRESOURCE(0x1170,iRam105017b8,uVar10,uVar8);
      }
    }
    uVar8 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x233,0x1050,0x238,0x1050);
    if (iVar12 != 0) {
      uVar10 = uRam105018c6;
      iRam105018f0 = LOADRESOURCE(0x1170,iVar12);
      if (iRam105018f0 != 0) {
        uRam105017cc = LOCKRESOURCE(0x1170,iRam105018f0,uVar10,uVar8);
      }
    }
    uVar8 = uRam105018c6;
    iVar12 = FINDRESOURCE(0x1170,0x240,0x1050,0x245,0x1050);
    uVar9 = CONCAT22(uRam10501790,uRam1050178e);
    uVar1 = uRam10500450;
    uVar2 = uRam10501604;
    uVar3 = uRam105017cc;
    uVar4 = uRam105017d0;
    uVar5 = uRam105018a2;
    uVar6 = uRam105018b6;
    uVar7 = uRam105018c2;
    if (iVar12 != 0) {
      uVar10 = uRam105018c6;
      iRam1050045a = LOADRESOURCE(0x1170,iVar12);
      uVar9 = CONCAT22(uRam10501790,uRam1050178e);
      uVar1 = uRam10500450;
      uVar2 = uRam10501604;
      uVar3 = uRam105017cc;
      uVar4 = uRam105017d0;
      uVar5 = uRam105018a2;
      uVar6 = uRam105018b6;
      uVar7 = uRam105018c2;
      if (iRam1050045a != 0) {
        uVar9 = LOCKRESOURCE(0x1170,iRam1050045a,uVar10,uVar8);
        uVar1 = uRam10500450;
        uVar2 = uRam10501604;
        uVar3 = uRam105017cc;
        uVar4 = uRam105017d0;
        uVar5 = uRam105018a2;
        uVar6 = uRam105018b6;
        uVar7 = uRam105018c2;
      }
    }
  }
  uRam10501790 = (undefined2)((ulong)uVar9 >> 0x10);
  uRam1050178e = (undefined2)uVar9;
  uRam105018c2._2_2_ = (undefined2)((ulong)uVar7 >> 0x10);
  uRam105018c2._0_2_ = (undefined2)uVar7;
  uRam105018b6._2_2_ = (undefined2)((ulong)uVar6 >> 0x10);
  uRam105018b6._0_2_ = (undefined2)uVar6;
  uRam105018a2._2_2_ = (undefined2)((ulong)uVar5 >> 0x10);
  uRam105018a2._0_2_ = (undefined2)uVar5;
  uRam105017d0._2_2_ = (undefined2)((ulong)uVar4 >> 0x10);
  uRam105017d0._0_2_ = (undefined2)uVar4;
  uRam105017cc._2_2_ = (undefined2)((ulong)uVar3 >> 0x10);
  uRam105017cc._0_2_ = (undefined2)uVar3;
  uRam10501604._2_2_ = (undefined2)((ulong)uVar2 >> 0x10);
  uRam10501604._0_2_ = (undefined2)uVar2;
  uRam10500450._2_2_ = (undefined2)((ulong)uVar1 >> 0x10);
  uRam10500450._0_2_ = (undefined2)uVar1;
  if (((((iRam105018dc == 0) || (iRam10501902 == 0)) || (iRam10501642 == 0)) ||
      ((((iRam1050160e == 0 || (iRam10500456 == 0)) ||
        ((iRam10501900 == 0 || ((iRam105017a4 == 0 && (iRam105015c8 != 0)))))) ||
       (iRam10500442 == 0)))) ||
     (((((iRam1050044a == 0 || (iRam105018ec == 0)) || (iRam1050044c == 0)) ||
       ((iRam10500458 == 0 || (iRam10501622 == 0)))) || ((iRam105015ca == 0 || (iRam105017e0 == 0)))
      ))) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  return uVar8;
}



void __cdecl16far FUN_1020_0552(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  uVar1 = 0x1048;
  runtime_stack_safety_check();
  if (iRam1050189c != 0) {
    uVar1 = 0x1170;
    DELETEOBJECT(0x1048,iRam1050189c);
  }
  uVar2 = uVar1;
  if (iRam105018dc != 0) {
    uVar2 = 0x1170;
    DELETEOBJECT(uVar1,iRam105018dc);
  }
  uVar1 = uVar2;
  if (iRam105017a4 != 0) {
    uVar1 = 0x1170;
    DELETEOBJECT(uVar2,iRam105017a4);
  }
  uVar2 = uVar1;
  if (iRam10501902 != 0) {
    uVar2 = 0x1170;
    DELETEOBJECT(uVar1,iRam10501902);
  }
  uVar1 = uVar2;
  if (iRam10501642 != 0) {
    uVar1 = 0x1170;
    DELETEOBJECT(uVar2,iRam10501642);
  }
  uVar2 = uVar1;
  if (iRam1050160e != 0) {
    uVar2 = 0x1170;
    DELETEOBJECT(uVar1,iRam1050160e);
  }
  uVar1 = uVar2;
  if (iRam10500456 != 0) {
    uVar1 = 0x1170;
    DELETEOBJECT(uVar2,iRam10500456);
  }
  uVar2 = uVar1;
  if (iRam10501900 != 0) {
    uVar2 = 0x1170;
    DELETEOBJECT(uVar1,iRam10501900);
  }
  uVar1 = uVar2;
  if (iRam105018ec != 0) {
    uVar1 = 0x1170;
    SELECTOBJECT(uVar2,iRam105018ec);
  }
  uVar2 = uVar1;
  if (iRam1050044a != 0) {
    uVar2 = 0x1170;
    DELETEOBJECT(uVar1,iRam1050044a);
  }
  uVar1 = uVar2;
  if (iRam10501622 != 0) {
    uVar1 = 0x1170;
    SELECTOBJECT(uVar2,iRam10501622);
  }
  uVar2 = uVar1;
  if (iRam10500458 != 0) {
    uVar2 = 0x1170;
    DELETEOBJECT(uVar1,iRam10500458);
  }
  uVar1 = uVar2;
  if (iRam105015ca != 0) {
    uVar1 = 0x1170;
    DELETEDC(uVar2,iRam105015ca);
  }
  uVar2 = uVar1;
  if (iRam105017e0 != 0) {
    uVar2 = 0x1170;
    DELETEDC(uVar1,iRam105017e0);
  }
  uVar1 = uVar2;
  if (iRam1050044c != 0) {
    uVar1 = 0x1170;
    DELETEDC(uVar2,iRam1050044c);
  }
  uVar2 = uVar1;
  if (iRam10500442 != 0) {
    uVar2 = 0x1170;
    DELETEDC(uVar1,iRam10500442);
  }
  uVar1 = uVar2;
  if (iRam10501896 != 0) {
    uVar1 = 0x1170;
    FREELIBRARY(uVar2,iRam10501896);
  }
  if ((iRam105018c2 != 0) || (uVar2 = uVar1, iRam105018c4 != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam10501624);
  }
  uVar1 = uVar2;
  if (iRam10501624 != 0) {
    uVar1 = 0x1170;
    FREERESOURCE(uVar2,iRam10501624);
  }
  if ((iRam10501604 != 0) || (uVar2 = uVar1, iRam10501606 != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam105017a6);
  }
  uVar1 = uVar2;
  if (iRam105017a6 != 0) {
    uVar1 = 0x1170;
    FREERESOURCE(uVar2,iRam105017a6);
  }
  if ((iRam10500450 != 0) || (uVar2 = uVar1, iRam10500452 != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam1050161c);
  }
  uVar1 = uVar2;
  if (iRam1050161c != 0) {
    uVar1 = 0x1170;
    FREERESOURCE(uVar2,iRam1050161c);
  }
  if ((iRam105018a2 != 0) || (uVar2 = uVar1, iRam105018a4 != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam10500444);
  }
  uVar1 = uVar2;
  if (iRam10500444 != 0) {
    uVar1 = 0x1170;
    FREERESOURCE(uVar2,iRam10500444);
  }
  if ((iRam105018b6 != 0) || (uVar2 = uVar1, iRam105018b8 != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam10501908);
  }
  uVar1 = uVar2;
  if (iRam10501908 != 0) {
    uVar1 = 0x1170;
    FREERESOURCE(uVar2,iRam10501908);
  }
  if ((iRam105017d0 != 0) || (uVar2 = uVar1, iRam105017d2 != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam105017b8);
  }
  uVar1 = uVar2;
  if (iRam105017b8 != 0) {
    uVar1 = 0x1170;
    FREERESOURCE(uVar2,iRam105017b8);
  }
  if ((iRam105017cc != 0) || (uVar2 = uVar1, iRam105017ce != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam105018f0);
  }
  uVar1 = uVar2;
  if (iRam105018f0 != 0) {
    uVar1 = 0x1170;
    FREERESOURCE(uVar2,iRam105018f0);
  }
  if ((iRam1050178e != 0) || (uVar2 = uVar1, iRam10501790 != 0)) {
    uVar2 = 0x1170;
    GLOBALUNLOCK(uVar1,iRam1050045a);
  }
  if (iRam1050045a != 0) {
    FREERESOURCE(uVar2,iRam1050045a);
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x10200c8a)
// WARNING: Removing unreachable block (ram,0x10200c74)

void __cdecl16far FUN_1020_07c2(undefined2 param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  int iStack_508;
  int iStack_506;
  uint uStack_4fe;
  undefined2 uStack_4fc;
  uint uStack_4fa;
  undefined1 auStack_4f8 [1024];
  undefined2 uStack_f8;
  int iStack_f6;
  undefined4 uStack_f4;
  int iStack_f0;
  undefined2 auStack_ee [2];
  int iStack_ea;
  int iStack_e8;
  int iStack_e6;
  int iStack_e4;
  int iStack_e2;
  int iStack_e0;
  int iStack_de;
  int iStack_dc;
  uint uStack_da;
  int iStack_d8;
  int iStack_c6;
  uint uStack_c4;
  int iStack_c2;
  uint uStack_bc;
  int iStack_ba;
  uint uStack_b8;
  int iStack_b6;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  int iStack_ac;
  undefined2 *puStack_aa;
  uint uStack_a8;
  undefined2 uStack_54;
  undefined2 uStack_52;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined2 uStack_4c;
  int iStack_4a;
  undefined2 *puStack_48;
  int iStack_46;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 *puStack_3c;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined2 *puStack_34;
  undefined2 *puStack_32;
  undefined4 uStack_30;
  int iStack_2c;
  uint uStack_2a;
  int iStack_28;
  undefined2 *puStack_26;
  
  runtime_stack_safety_check();
  if (iRam1050189c != 0) {
    DELETEOBJECT();
    iRam1050189c = 0;
  }
  CREATESOLIDBRUSH();
  FILLRECT();
  DELETEOBJECT();
  LOADSTRING();
  iVar3 = LSTRCMP();
  if ((iVar3 != 0) && (iVar3 = OPENFILE(), iVar3 != -1)) {
    iVar3 = _LREAD();
    if ((iVar3 == 0xe) && (iStack_c6 == 0x4d42)) {
      iVar3 = _LREAD();
      if (iVar3 == 0x28) {
        if (((iStack_e2 == 1) && (iStack_de == 0)) && (iStack_dc == 0)) {
          if (iStack_e0 == 1) {
            uStack_a8 = 2;
          }
          else if (iStack_e0 == 4) {
            uStack_a8 = 0x10;
          }
          else {
            if (iStack_e0 != 8) {
              _LCLOSE();
              return;
            }
            uStack_a8 = 0x100;
          }
          iVar3 = GLOBALALLOC();
          iStack_f0 = iVar3;
          if (iVar3 == 0) {
            _LCLOSE();
          }
          else {
            uStack_f4 = (undefined2 *)GLOBALLOCK();
            puVar8 = (undefined2 *)uStack_f4;
            puVar7 = auStack_ee;
            for (iVar6 = 0x14; iVar6 != 0; iVar6 = iVar6 + -1) {
              puVar2 = puVar8;
              puVar8 = puVar8 + 1;
              puVar1 = puVar7;
              puVar7 = puVar7 + 1;
              *puVar2 = *puVar1;
            }
            puStack_26 = (undefined2 *)0x0;
            iStack_28 = 0x1170;
            uStack_2a = 0x98a;
            _LLSEEK();
            iVar6 = uStack_a8 << 2;
            puStack_26 = (undefined2 *)uStack_f4 + 0x14;
            iStack_28 = uStack_a8 << 2;
            uStack_2a = 0x1170;
            iStack_2c = 0x9b6;
            iVar4 = _LREAD();
            if (iVar6 == iVar4) {
              if (((-1 < iRam105018a0) && ((0 < iRam105018a0 || (0x10 < uRam1050189e)))) &&
                 (uStack_a8 == 0x100)) {
                uStack_4fc = 0x300;
                uStack_4fa = uStack_a8;
                uStack_4fe = 0;
                puVar1 = uStack_f4;
                while( true ) {
                  uStack_f4._2_2_ = (undefined2)((ulong)puVar1 >> 0x10);
                  uStack_f4._0_2_ = (undefined2 *)puVar1;
                  uStack_f4 = puVar1;
                  if (uStack_a8 <= uStack_4fe) break;
                  puVar1 = (undefined2 *)uStack_f4 + uStack_4fe * 2 + 0x15;
                  auStack_4f8[uStack_4fe * 4] = *(undefined1 *)puVar1;
                  auStack_4f8[uStack_4fe * 4 + 1] =
                       *(undefined1 *)((int)(undefined2 *)uStack_f4 + uStack_4fe * 4 + 0x29);
                  auStack_4f8[uStack_4fe * 4 + 2] =
                       *(undefined1 *)((undefined2 *)uStack_f4 + uStack_4fe * 2 + 0x14);
                  auStack_4f8[uStack_4fe * 4 + 3] = 0;
                  uStack_4fe = uStack_4fe + 1;
                  puVar1 = uStack_f4;
                }
                puStack_26 = &uStack_4fc;
                iStack_28 = 0x1170;
                uStack_2a = 0xacc;
                iRam1050189c = CREATEPALETTE();
              }
              if ((uStack_da == 0) && (iStack_d8 == 0)) {
                uStack_da = uStack_c4 - uStack_bc;
                iStack_d8 = (iStack_c2 - iStack_ba) - (uint)(uStack_c4 < uStack_bc);
              }
              puStack_26 = (undefined2 *)0x0;
              iStack_28 = iStack_d8;
              uStack_2a = uStack_da;
              iStack_2c = 0x1170;
              uStack_30._2_2_ = 0xb04;
              iStack_ac = GLOBALALLOC();
              if (iStack_ac == 0) {
                iStack_28 = iStack_f0;
                uStack_2a = 0x1170;
                iStack_2c = 0xb18;
                GLOBALUNLOCK();
                uStack_2a = iStack_f0;
                iStack_2c = 0x1170;
                uStack_30._2_2_ = 0xb21;
                GLOBALFREE();
                uStack_30._2_2_ = 0x1170;
                uStack_30._0_2_ = (undefined2 *)0xb29;
                iStack_2c = iVar3;
                _LCLOSE();
              }
              else {
                uStack_2a = 0x1170;
                iStack_2c = 0xb35;
                iStack_28 = iStack_ac;
                uStack_b4 = GLOBALLOCK();
                iStack_2c = iStack_ba;
                uStack_30._2_2_ = uStack_bc;
                uStack_30._0_2_ = (undefined2 *)0x0;
                puStack_32 = (undefined2 *)0x1170;
                puStack_34 = (undefined2 *)0xb61;
                uStack_2a = iVar3;
                uStack_b0 = uStack_b4;
                _LLSEEK();
                iStack_b6 = iStack_d8;
                for (uStack_b8 = uStack_da;
                    (uStack_30 = uStack_b4, iStack_b6 != 0 || (0x8000 < uStack_b8));
                    uStack_b8 = uStack_b8 + 0x8000) {
                  puStack_32 = (undefined2 *)0x8000;
                  puStack_34 = (undefined2 *)0x1170;
                  uStack_38._2_2_ = (undefined2 *)0xb89;
                  iStack_2c = iVar3;
                  _LREAD();
                  iStack_b6 = iStack_b6 - (uint)(uStack_b8 < 0x8000);
                  uStack_b4 = CONCAT22((uint)(0x7fff < (uint)uStack_b4) * 0x1000 + uStack_b4._2_2_,
                                       (uint)uStack_b4 + 0x8000);
                }
                puStack_32 = (undefined2 *)uStack_b8;
                puStack_34 = (undefined2 *)0x1170;
                uStack_38._2_2_ = (undefined2 *)0xbde;
                iStack_2c = iVar3;
                _LREAD();
                uStack_30._2_2_ = param_1;
                uStack_30._0_2_ = (undefined2 *)0x1170;
                puStack_32 = (undefined2 *)0xbe6;
                puStack_aa = (undefined2 *)GETDC();
                if (iRam1050189c != 0) {
                  puStack_32 = (undefined2 *)iRam1050189c;
                  puStack_34 = (undefined2 *)0x0;
                  uStack_38._2_2_ = (undefined2 *)0x1170;
                  uStack_38._0_2_ = (undefined2 *)0xc00;
                  uStack_30._0_2_ = puStack_aa;
                  uStack_f8 = SELECTPALETTE();
                  puStack_32 = puStack_aa;
                  puStack_34 = (undefined2 *)0x1170;
                  uStack_38._2_2_ = (undefined2 *)0xc0d;
                  REALIZEPALETTE();
                }
                puStack_34 = puStack_aa;
                uStack_3a = 0;
                puStack_3c = (undefined2 *)0x4;
                iStack_46 = 0;
                puStack_48 = (undefined2 *)0x1170;
                iStack_4a = 0xc34;
                uStack_40 = uStack_b0;
                uStack_38 = uStack_f4;
                uStack_44 = uStack_f4;
                iStack_f6 = CREATEDIBITMAP();
                if (iRam1050189c != 0) {
                  uStack_38._2_2_ = puStack_aa;
                  uStack_38._0_2_ = (undefined2 *)uStack_f8;
                  uStack_3a = 0;
                  puStack_3c = (undefined2 *)0x1170;
                  uStack_40._2_2_ = (undefined2 *)0xc4e;
                  SELECTPALETTE();
                  uStack_38._0_2_ = puStack_aa;
                  uStack_3a = 0x1170;
                  puStack_3c = (undefined2 *)0xc57;
                  REALIZEPALETTE();
                }
                uStack_3a = param_1;
                puStack_3c = puStack_aa;
                uStack_40._2_2_ = (undefined2 *)0x1170;
                uStack_40._0_2_ = 0xc63;
                RELEASEDC();
                if (((iStack_f6 != 0) && ((iStack_e8 != 0 || (iStack_ea != 0)))) &&
                   ((iStack_e4 != 0 || (iStack_e6 != 0)))) {
                  iVar6 = iStack_ea;
                  if (0x1a4 < iStack_ea) {
                    iVar6 = 0x1a4;
                  }
                  iVar4 = iStack_e6;
                  if (0x15c < iStack_e6) {
                    iVar4 = 0x15c;
                  }
                  puStack_3c = puRam105015ca;
                  uStack_40._2_2_ = (undefined2 *)iStack_f6;
                  uStack_40._0_2_ = 0x1170;
                  uStack_44._2_2_ = 0xce7;
                  uVar5 = SELECTOBJECT();
                  for (iStack_506 = 0; iStack_506 < 0x1a4; iStack_506 = iStack_506 + iVar6) {
                    for (iStack_508 = 0; iStack_508 < 0x15c; iStack_508 = iStack_508 + iVar4) {
                      uStack_40._2_2_ = (undefined2 *)uRam1050044c;
                      uStack_40._0_2_ = iStack_506;
                      uStack_44._2_2_ = iStack_508;
                      uStack_44._0_2_ = (undefined2 *)iVar6;
                      if (0x1a4 - iStack_506 <= iVar6) {
                        uStack_44._0_2_ = (undefined2 *)(0x1a4 - iStack_506);
                      }
                      iStack_46 = iVar4;
                      if (0x15c - iStack_508 <= iVar4) {
                        iStack_46 = 0x15c - iStack_508;
                      }
                      puStack_48 = puRam105015ca;
                      iStack_4a = 0;
                      uStack_4c = 0;
                      uStack_4e = 0xcc;
                      uStack_50 = 0x20;
                      uStack_52 = 0x1170;
                      uStack_54 = 0xd54;
                      BITBLT();
                    }
                  }
                  uStack_40._2_2_ = puRam105015ca;
                  uStack_44._2_2_ = 0x1170;
                  uStack_44._0_2_ = (undefined2 *)0xd87;
                  uStack_40._0_2_ = uVar5;
                  SELECTOBJECT();
                  uStack_40._0_2_ = iStack_f6;
                  uStack_44._2_2_ = 0x1170;
                  uStack_44._0_2_ = (undefined2 *)0xd90;
                  DELETEOBJECT();
                }
                uStack_44._2_2_ = iStack_ac;
                uStack_44._0_2_ = (undefined2 *)0x1170;
                iStack_46 = 0xd99;
                GLOBALUNLOCK();
                uStack_44._0_2_ = (undefined2 *)iStack_ac;
                iStack_46 = 0x1170;
                puStack_48 = (undefined2 *)0xda2;
                GLOBALFREE();
                iStack_46 = iStack_f0;
                puStack_48 = (undefined2 *)0x1170;
                iStack_4a = 0xdab;
                GLOBALUNLOCK();
                puStack_48 = (undefined2 *)iStack_f0;
                iStack_4a = 0x1170;
                uStack_4c = 0xdb4;
                GLOBALFREE();
                uStack_4c = 0x1170;
                uStack_4e = 0xdbc;
                iStack_4a = iVar3;
                _LCLOSE();
              }
            }
            else {
              puStack_26 = (undefined2 *)0x1170;
              iStack_28 = 0x9c7;
              GLOBALUNLOCK();
              puStack_26 = (undefined2 *)iStack_f0;
              iStack_28 = 0x1170;
              uStack_2a = 0x9d0;
              GLOBALFREE();
              uStack_2a = 0x1170;
              iStack_2c = 0x9d8;
              iStack_28 = iVar3;
              _LCLOSE();
            }
          }
        }
        else {
          _LCLOSE();
        }
      }
      else {
        _LCLOSE();
      }
    }
    else {
      _LCLOSE();
    }
  }
  return;
}



undefined2 __stdcall16far
COUNTERWNDPROC(undefined2 param_1,undefined2 param_2,undefined2 param_3,int param_4,
              undefined2 **param_5)

{
  int iVar1;
  undefined2 uStackY_24;
  
                    // Segment:    6
                    // Offset:     00007010
                    // Length:     0262
                    // Min Alloc:  0262
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  if (param_4 == 1) {
    SETWINDOWLONG();
    SETWINDOWWORD();
    param_1 = 0;
  }
  else if (param_4 == 0xf) {
    BEGINPAINT();
    FUN_1028_0170(param_5,uStackY_24);
    ENDPAINT();
    param_1 = 0;
  }
  else if (param_4 == 0x401) {
    SETWINDOWWORD();
    param_1 = 0;
  }
  else if (param_4 == 0x402) {
    SETWINDOWLONG();
    iVar1 = GETDC();
    FUN_1028_0170(param_5,iVar1);
    RELEASEDC();
  }
  else if (param_4 == 0x403) {
    param_1 = GETWINDOWLONG();
  }
  else if (param_4 == 0x404) {
    GETWINDOWLONG();
    param_1 = SENDMESSAGE();
  }
  else if (param_4 == 0x405) {
    GETWINDOWLONG();
    param_1 = SENDMESSAGE();
  }
  else {
    param_1 = DEFWINDOWPROC();
  }
  return param_1;
}



void __cdecl16far FUN_1028_0170(undefined2 **param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 **ppuVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 ***pppuStack_e;
  
  runtime_stack_safety_check();
  pppuStack_e = &pppuStack_e;
  GETCLIENTRECT(0x1048);
  pppuStack_e = pppuRam10501902;
  uVar1 = SELECTOBJECT(0x1170);
  pppuStack_e = (undefined2 ***)param_1;
  GETWINDOWLONG(0x1170,0);
  ppuVar5 = param_1;
  iVar2 = GETWINDOWWORD(0x1170,4);
  for (iVar7 = 0; iVar7 < iVar2; iVar7 = iVar7 + 1) {
    FUN_1048_0850(0,(uint)ppuVar5,10,0);
    iVar7 = 0;
    uVar6 = FUN_1048_0784(0,(uint)ppuVar5,10,0);
    ppuVar5 = (undefined2 **)((ulong)uVar6 >> 0x10);
    iVar4 = (int)param_1 + (iVar7 + 1) * -0xd;
    iVar2 = 0;
    iVar7 = 0xd;
    if (((iVar4 == 0) && (param_2 == 0)) && (ppuVar5 == (undefined2 **)0x0)) {
      iVar3 = 0x82;
    }
    else {
      iVar3 = iVar4 * 0xd;
    }
    BITBLT(0x1048,0x20,0xcc,0,iVar3,uRam105015ca,0x15,0xd,0,iVar4);
  }
  SELECTOBJECT(0x1170,uVar1);
  return;
}



undefined2 __stdcall16far
BUTTONWNDPROC(undefined2 param_1,undefined2 param_2,undefined2 param_3,int param_4,
             undefined2 param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 uStack_c;
  undefined2 uStack_a;
  
                    // Segment:    7
                    // Offset:     00007300
                    // Length:     00cc
                    // Min Alloc:  00cd
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  if (((param_4 == 0x100) || (param_4 == 0x101)) || (param_4 == 0x102)) {
    uVar1 = 0;
  }
  else if (param_4 == 0x202) {
    uStack_a = uRam105018c0;
    uStack_c = uRam105018be;
    CALLWINDOWPROC(0x1048,param_1,param_2,param_3,0x202,param_5);
    uStack_c = param_5;
    GETCLIENTRECT(0x1170,&uStack_c,unaff_SS);
    iVar2 = PTINRECT(0x1170,param_1,param_2,&uStack_c);
    if (iVar2 == 0) {
      uVar1 = GETWINDOWWORD(0x1170,0xfff8);
      SETFOCUS(0x1170,uVar1,param_5);
    }
    uVar1 = 0;
  }
  else {
    uStack_a = uRam105018c0;
    uStack_c = uRam105018be;
    uVar1 = CALLWINDOWPROC(0x1048,param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}



void __cdecl16far FUN_1038_0000(int param_1)

{
  undefined2 uVar1;
  
                    // Segment:    8
                    // Offset:     00007400
                    // Length:     4a4a
                    // Min Alloc:  4a4a
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  iRam10501610 = param_1;
  FUN_1038_065c();
  SENDMESSAGE(0x1038,0,0,0,0x402);
  if (iRam10501610 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 3;
  }
  SENDMESSAGE(0x1170,uVar1,0,0,0x402);
  return;
}



void __cdecl16far FUN_1038_005c(void)

{
  runtime_stack_safety_check();
  BITBLT(0x1048,0x20,0xcc,0,0,uRam10500442,0x17b,0x1c3,1,1);
  if (iRam10501610 != 0) {
    draw_sprite_or_frame();
  }
  return;
}



void __cdecl16far FUN_1038_00ac(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  
  runtime_stack_safety_check();
  if (iRam10501610 != 0) {
    iVar1 = GETDC(0x1048,param_1);
    for (uVar11 = 2; (byte)uVar11 < 0x47; uVar11 = (uint)(byte)((byte)uVar11 + 2)) {
      uVar10 = 2;
      while (bVar9 = (byte)uVar10, bVar9 < 0x3b) {
        if (*(char *)(uVar11 * 0x3d + 0x460 + uVar10) == '\b') {
          iVar2 = uVar11 * 6 + 4;
          if (*(char *)((uVar11 + 1) * 0x3d + 0x460 + uVar10) == '\0') {
            iVar3 = 0xc;
          }
          else {
            iVar3 = 0xb;
          }
          if (*(char *)(uVar11 * 0x3d + uVar10 + 0x461) == '\0') {
            uVar4 = 0xc;
          }
          else {
            uVar4 = 0xb;
          }
          iVar7 = iRam1050044c;
          iVar8 = iRam10500442;
          BITBLT(0x1170,0x20,0xcc,uVar4,iVar3,iRam1050044c,uVar4,iVar3,uVar10 * 6 + 4,iVar2);
          if (iVar8 != 0) {
            iVar5 = iRam10500442 + iVar7 + -1;
            iVar6 = iVar5 + iVar3;
            iVar3 = 0x1170;
            iVar7 = iRam1050161e;
            iVar2 = iRam10500442;
            SETPIXEL(0x1170,iRam1050161e,uRam10501620,iVar6 + -1,iVar5);
          }
          iVar2 = iVar2 + 1;
          iVar5 = iVar1;
          BITBLT(0x1170,0x20,0xcc,iVar1,iVar2,iRam1050044c,iVar3,iVar7,iVar1,iVar2);
          if (iVar8 != 0) {
            SETPIXEL(0x1170,iRam1050161e,uRam10501620,iVar5 + iVar3 + -1,iVar2 + iVar7 + -1);
          }
        }
        uVar10 = (uint)(byte)(bVar9 + 2);
      }
    }
    draw_sprite_or_frame();
    RELEASEDC(0x1038,iVar1);
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x103805ba)
// WARNING: Removing unreachable block (ram,0x103804f0)

void __cdecl16far FUN_1038_02d2(undefined2 param_1)

{
  uint uVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  byte bVar12;
  
  runtime_stack_safety_check();
  uVar2 = 0x1170;
  uVar1 = GETDC(0x1048,param_1);
  if (uRam10501610 == 0) {
    if ((uint)bRam105018aa % 2 == 0) {
      for (bVar12 = 0; bVar12 < bRam1050178a; bVar12 = bVar12 + 1) {
        uVar2 = 0x1038;
        FUN_1038_0ffc(uVar1,bVar12);
      }
    }
  }
  else {
    if (iRam10501608 != 0) {
      FUN_1038_3574();
      FUN_1038_2e22();
      lVar5 = SENDMESSAGE(0x1038,1,0,0,0x405);
      if (lVar5 == 0) {
        RELEASEDC(0x1170,uVar1);
        SENDMESSAGE(0x1170,0,0,0x65,0x111);
        return;
      }
      SENDMESSAGE(0x1170,0x1e,0,0,0x402);
      iRam105018fe = 0x12;
      bRam105018aa = 0;
    }
    uVar2 = 0x1170;
    if (iRam10500448 == 0) {
      if (iRam105017c4 == 0) {
        FUN_1038_2e86(param_1,uVar1);
        if ((uRam105017c0 == 0) && (iRam105017c2 == 0)) {
          if ((uint)bRam105018aa % 2 == 0) {
            for (bVar12 = 0; bVar12 < bRam1050178a; bVar12 = bVar12 + 1) {
              FUN_1038_0ffc(uVar1,bVar12);
            }
            if (iRam10501608 != 0) {
              uRam105017b2 = 0x12;
              FUN_1038_399a(uVar1);
              FUN_1038_2da0(uVar1);
              RELEASEDC(0x1038,uVar1);
              return;
            }
          }
          uVar2 = 0x1038;
          if (iRam105018fe == 0) {
            lVar5 = SENDMESSAGE(0x1038,1,0,0,0x405);
            if (lVar5 == 0) {
              FUN_1040_0000(0x6b);
              lVar5 = SENDMESSAGE(0x1040,1,0,0,0x405);
              if (lVar5 == 0) {
                uRam105017b2 = 0x12;
                RELEASEDC(0x1170,uVar1);
                SENDMESSAGE(0x1170,0,0,0x65,0x111);
                return;
              }
              uVar2 = 0x1170;
              SENDMESSAGE(0x1170,0x1e,0,0,0x402);
              iRam105018fe = 0x12;
            }
            else {
              uVar2 = 0x1170;
              lVar5 = SENDMESSAGE(0x1170,0,0,0,0x403);
              if (lVar5 < 6) {
                uVar2 = 0x1040;
                FUN_1040_0000(0x6e);
              }
              iRam105018fe = 0x12;
            }
          }
          else {
            iRam105018fe = iRam105018fe + -1;
          }
        }
        else {
          SENDMESSAGE(0x1038,0x1e,0,0,0x402);
          uVar9 = 0x404;
          uVar2 = 0;
          uVar6 = uRam10501610;
          if (9 < (int)uRam10501610) {
            uVar6 = 10;
          }
          lVar5 = _2bit_multiply(uVar6,(int)uVar6 >> 0xf,uRam105017c0,iRam105017c2);
          SENDMESSAGE(0x1048,lVar5,uVar2,uVar9);
          bVar3 = CARRY2(uRam105018f2,uRam105017c0);
          uRam105018f2 = uRam105018f2 + uRam105017c0;
          iRam105018f4 = iRam105018f4 + iRam105017c2 + (uint)bVar3;
          uRam105017c0 = 0;
          iRam105017c2 = 0;
          uVar10 = 0x4b;
          uVar11 = 0;
          uVar8 = 0x402;
          uVar9 = 0;
          uVar7 = 0;
          uVar6 = 0x3f7;
          lVar5 = _2bit_multiply(uRam105018f2,iRam105018f4,100,0);
          uVar4 = FUN_1048_0784((uint)lVar5,(uint)((ulong)lVar5 >> 0x10),uVar6,uVar7);
          uVar2 = 0x1170;
          lVar5 = SENDMESSAGE(0x1048,uVar4,uVar9,uVar8);
          if (CONCAT22(uVar11,uVar10) <= lVar5) {
            iRam10500448 = 1;
            uRam105017b2 = 0x12;
          }
        }
      }
      else {
        uRam10501610 = uRam10501610 + 1;
        FUN_1038_065c();
        FUN_1038_005c();
        uVar2 = 0x1038;
        draw_sprite_or_frame();
      }
    }
    else if ((uint)bRam105018aa % 2 == 0) {
      for (bVar12 = 0; bVar12 < bRam1050178a; bVar12 = bVar12 + 1) {
        uVar2 = 0x1038;
        FUN_1038_1f90(uVar1,bVar12);
      }
    }
  }
  bRam105018aa = (byte)((ulong)(bRam105018aa + 1) % 4);
  RELEASEDC(uVar2,uVar1);
  return;
}



void __cdecl16far FUN_1038_065c(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  long lVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 local_1a;
  undefined2 *local_18;
  
  runtime_stack_safety_check();
  uRam105017c4 = 0;
  uRam105018aa = 0;
  uRam105018f2 = 0;
  iRam105018f4 = 0;
  uRam105017c0 = 0;
  uRam105017c2 = 0;
  if (iRam10501610 == 0) {
    uRam105017b2 = 100;
  }
  else {
    uRam105017b2 = 10;
  }
  uRam105018fe = 0x12;
  for (uVar12 = 0; uVar12 < 0x49; uVar12 = (uint)(byte)((char)uVar12 + 1)) {
    *(undefined1 *)(uVar12 * 0x3d + 0x460) = 8;
    *(undefined1 *)(uVar12 * 0x3d + 0x49c) = 8;
  }
  for (uVar12 = 0; uVar12 < 0x3d; uVar12 = (uint)(byte)((char)uVar12 + 1)) {
    *(undefined1 *)(uVar12 + 0x460) = 8;
    *(undefined1 *)(uVar12 + 0x1588) = 8;
  }
  for (uVar12 = 1; uVar12 < 0x48; uVar12 = (uint)(byte)((char)uVar12 + 1)) {
    *(undefined1 *)(uVar12 * 0x3d + 0x461) = 2;
    *(undefined1 *)(uVar12 * 0x3d + 0x49b) = 2;
  }
  for (uVar12 = 1; uVar12 < 0x3c; uVar12 = (uint)(byte)((char)uVar12 + 1)) {
    *(undefined1 *)(uVar12 + 0x49d) = 2;
    *(undefined1 *)(uVar12 + 0x154b) = 2;
  }
  for (uVar12 = 2; uVar12 < 0x47; uVar12 = (uint)(byte)((char)uVar12 + 1)) {
    for (uVar13 = 2; uVar13 < 0x3b; uVar13 = (uint)(byte)((char)uVar13 + 1)) {
      *(undefined1 *)(uVar12 * 0x3d + 0x460 + uVar13) = 0;
    }
  }
  FUN_1038_2e22();
  uRam10500448 = 0;
  uRam10501608 = 0;
  if (iRam10501610 == 0) {
    bRam1050178a = 4;
    uRam105017e5 = 0xc;
    uRam105017e6 = 0xc;
    uRam105017e7 = 1;
    uRam10501812 = 0x3c;
    uRam10501813 = 0xc;
    uRam10501814 = 2;
    uRam1050183f = 0x3c;
    uRam10501840 = 0x30;
    uRam10501841 = 3;
    uRam1050186c = 0xc;
    uRam1050186d = 0x30;
    uRam1050186e = 0;
  }
  else {
    bRam1050178a = 3;
    if (iRam10501610 < 10) {
      bRam1050178a = 2;
    }
    if (iRam10501610 < 7) {
      bRam1050178a = 1;
    }
    for (uVar12 = 0; uVar12 < bRam1050178a; uVar12 = (uint)(byte)((char)uVar12 + 1)) {
      *(char *)(uVar12 * 0x2d + 0x17e5) =
           ((char)uVar12 + '\x01') * '\x02' * (char)(0x23 / (ulong)(long)(int)(bRam1050178a + 1)) +
           '\x02';
      *(undefined1 *)(uVar12 * 0x2d + 0x17e6) = 0x1e;
      if ((char)uVar12 == '\0') {
        uVar13 = FUN_1048_0754();
        uVar9 = (undefined1)((int)uVar13 % 4);
      }
      else {
        uVar9 = (undefined1)((*(byte *)((uVar12 - 1) * 0x2d + 0x17e7) + 1) % 4);
      }
      *(undefined1 *)((uVar12 & 0xff) * 0x2d + 0x17e7) = uVar9;
    }
  }
  for (uVar12 = 0; uVar12 < bRam1050178a; uVar12 = (uint)(byte)((char)uVar12 + 1)) {
    *(undefined1 *)(uVar12 * 0x2d + 0x17e2) = 1;
    *(undefined1 *)(uVar12 * 0x2d + 0x17e3) = 0;
    *(undefined1 *)(uVar12 * 0x2d + 0x17e4) = 0;
    *(undefined1 *)
     ((uint)*(byte *)(uVar12 * 0x2d + 0x17e5) * 0x3d + 0x460 +
     (uint)*(byte *)(uVar12 * 0x2d + 0x17e6)) = 1;
  }
  uVar1 = CREATESOLIDBRUSH();
  uVar2 = CREATESOLIDBRUSH();
  local_18 = (undefined2 *)0xa30;
  uVar3 = CREATEPEN();
  local_18 = (undefined2 *)0x1170;
  local_1a = 0xa44;
  uVar4 = CREATEPEN();
  local_18 = (undefined2 *)uRam105018fa;
  local_1a = 0x1170;
  uVar5 = CREATEPEN();
  local_18 = &local_1a;
  local_1a = uVar1;
  FILLRECT(0x1170);
  local_1a = 0x1170;
  local_18 = (undefined2 *)uVar3;
  uVar6 = SELECTOBJECT();
  local_18 = (undefined2 *)uRam10500442;
  local_1a = uVar2;
  uVar7 = SELECTOBJECT(0x1170);
  local_1a = uRam10500442;
  RECTANGLE(0x1170,0x16c,0x1b4,0xf,0xf);
  SELECTOBJECT(0x1170,uVar4);
  MOVETO(0x1170,0x16b,0xe);
  LINETO(0x1170,0xe,0xe);
  LINETO(0x1170,0xe,0x1b4);
  SELECTOBJECT(0x1170,uVar5);
  MOVETO(0x1170,0x16c,0xf);
  LINETO(0x1170,0x16c,0x1b4);
  LINETO(0x1170,0xe,0x1b4);
  if ((iRam10501610 == 0) && (iRam105015c8 != 0)) {
    uRam105017ae = 0x2c;
    uRam105017b0 = 0x8d;
    uRam1050045c = 0x36;
    uRam1050045e = 0x97;
    uVar8 = SELECTOBJECT(0x1170,uRam105017a4);
    BITBLT(0x1170,0xc6,0x88,0x60,0,uRam105015ca,0x60,0x16a,uRam105017b0,uRam105017ae);
    BITBLT(0x1170,0xc6,0x88,0x60,0,uRam105015ca,0x60,0x16a,uRam1050045e,uRam1050045c);
    BITBLT(0x1170,0x86,0xee,0,0,uRam105015ca,0x60,0x16a,uRam105017b0,uRam105017ae);
    SELECTOBJECT(0x1170,uVar8);
  }
  uVar15 = uRam10500442;
  SETPIXEL(0x1170,uRam10501904,uRam10501906,0x90,0x1b3);
  uVar14 = uRam10500442;
  SETPIXEL(0x1170,uRam10501904,uRam10501906,0x120,0x1b3);
  uVar8 = uRam10500442;
  SELECTOBJECT(0x1170,uVar6);
  uVar6 = uRam10500442;
  SELECTOBJECT(0x1170,uVar7);
  DELETEOBJECT(0x1170,uVar1,uVar6,uVar8,uVar14,uVar15);
  DELETEOBJECT(0x1170,uVar2);
  DELETEOBJECT(0x1170,uVar3);
  DELETEOBJECT(0x1170,uVar4);
  uVar1 = 0x1170;
  DELETEOBJECT(0x1170,uVar5);
  if (iRam10501610 == 1) {
    FUN_1038_0dc2(0x11,1,0x13,0x17);
    FUN_1038_0dc2(0x11,0x25,0x13,0x3b);
    FUN_1038_0dc2(0x23,1,0x25,0x17);
    FUN_1038_0dc2(0x23,0x25,0x25,0x3b);
    FUN_1038_0dc2(0x35,1,0x37,0x17);
    uVar1 = 0x1038;
    FUN_1038_0dc2(0x35,0x25,0x37,0x3b);
    uRam105018f2 = 0x42;
    iRam105018f4 = 0;
  }
  else if (iRam10501610 == 2) {
    FUN_1038_0dc2(0x17,1,0x19,0x17);
    FUN_1038_0dc2(0x17,0x25,0x19,0x3b);
    FUN_1038_0dc2(0x2f,1,0x31,0x17);
    uVar1 = 0x1038;
    FUN_1038_0dc2(0x2f,0x25,0x31,0x3b);
    uRam105018f2 = 0x2c;
    iRam105018f4 = 0;
  }
  else if (iRam10501610 == 3) {
    FUN_1038_0dc2(0x23,1,0x25,0x17);
    uVar1 = 0x1038;
    FUN_1038_0dc2(0x23,0x25,0x25,0x3b);
    uRam105018f2 = 0x16;
    iRam105018f4 = 0;
  }
  SENDMESSAGE(uVar1,iRam10501610,iRam10501610 >> 0xf,0,0x402);
  if (iRam10501610 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x1e;
  }
  SENDMESSAGE(0x1170,uVar1,0,0,0x402);
  uVar2 = 0x402;
  uVar1 = 0;
  uVar13 = 0;
  uVar12 = 0x3f7;
  lVar10 = _2bit_multiply(uRam105018f2,iRam105018f4,100,0);
  uVar11 = FUN_1048_0784((uint)lVar10,(uint)((ulong)lVar10 >> 0x10),uVar12,uVar13);
  SENDMESSAGE(0x1048,uVar11,uVar1,uVar2);
  return;
}



void __cdecl16far FUN_1038_0dc2(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  
  runtime_stack_safety_check();
  for (iVar3 = param_1; iVar4 = param_2, iVar3 <= param_3; iVar3 = iVar3 + 1) {
    *(undefined1 *)(iVar3 * 0x3d + 0x460 + param_2) = 2;
    *(undefined1 *)(iVar3 * 0x3d + 0x460 + param_4) = 2;
  }
  for (; iVar4 <= param_4; iVar4 = iVar4 + 1) {
    *(undefined1 *)(param_1 * 0x3d + 0x460 + iVar4) = 2;
    *(undefined1 *)(param_3 * 0x3d + 0x460 + iVar4) = 2;
  }
  uVar7 = 0;
  uVar1 = CREATEPEN(0x1048,uRam1050161e,uRam10501620,1);
  iVar5 = iRam10500442;
  uVar2 = SELECTOBJECT(0x1170,uVar1);
  iVar4 = iRam10500442;
  RECTANGLE(0x1170,param_4 * 6 + 10,param_3 * 6 + 10,param_2 * 6 + 9,param_1 * 6 + 9);
  iVar3 = iRam10500442;
  SELECTOBJECT(0x1170,uVar2);
  DELETEOBJECT(0x1170,uVar1,iVar3,iVar4,iVar5,uVar7);
  for (iVar3 = param_1 + 1; iVar3 < param_3; iVar3 = iVar3 + 2) {
    for (iVar4 = param_2 + 1; iVar4 < param_4; iVar4 = iVar4 + 2) {
      *(undefined1 *)(iVar3 * 0x3d + 0x460 + iVar4) = 8;
      *(undefined1 *)(iVar3 * 0x3d + 0x460 + iVar4) = 8;
      iVar5 = iVar3 * 6 + 4;
      iVar6 = iVar4 * 6 + 4;
      if (*(char *)(iVar3 * 0x3d + iVar4 + 0x461) == '\0') {
        uVar1 = 0xc;
      }
      else {
        uVar1 = 0xb;
      }
      BITBLT(0x1170,0x20,0xcc,iRam10500442,iVar3 * 6 + -0xc,uRam1050044c,uVar1,iVar5,iVar6,iVar5);
      if (((*(char *)((iVar3 + 1) * 0x3d + 0x460 + iVar4) == '\0') &&
          (*(char *)(iVar3 * 0x3d + iVar4 + 0x461) == '\0')) &&
         (*(char *)((iVar3 + 1) * 0x3d + iVar4 + 0x461) != '\0')) {
        iVar5 = iVar5 + iRam10500442 + -1;
        SETPIXEL(0x1170,uRam1050161e,uRam10501620,iVar6 + iVar5 + -1,iVar5);
      }
    }
  }
  return;
}



void __cdecl16far FUN_1038_0ffc(int param_1,byte param_2)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  byte bVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  byte bVar13;
  
  runtime_stack_safety_check();
  if ((iRam10501610 == 0) || (iRam10501608 == 0)) {
    uVar3 = SELECTOBJECT(0x1048,uRam1050160e);
    uVar4 = SELECTOBJECT(0x1170,uRam105017a4);
    bVar1 = *(byte *)((uint)param_2 * 0x2d + 0x17e3);
    uVar12 = (uint)*(byte *)((uint)param_2 * 0x2d + 0x17e4);
    bVar11 = *(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bVar1 * 3);
    bVar13 = *(byte *)((uint)param_2 * 0x2d + (uint)bVar1 * 3 + 0x17e6);
    if ((*(char *)((uint)bVar11 * 0x3d + bVar13 + 0x45e) == '\0') ||
       (((*(char *)((uint)bVar11 * 0x3d + bVar13 + 0x462) == '\0' ||
         (*(char *)((bVar11 - 2) * 0x3d + 0x460 + (uint)bVar13) == '\0')) ||
        (*(char *)((bVar11 + 2) * 0x3d + 0x460 + (uint)bVar13) == '\0')))) {
      if (cRam105017e2 == '\x01') {
        FUN_1040_0000(0x65);
      }
      if (*(char *)((uint)param_2 * 0x2d + 0x17e2) == '\r') {
        FUN_1038_232e(param_1,param_2);
        *(undefined1 *)
         ((uint)*(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uVar12 & 0xff) * 3) * 0x3d + 0x460 +
         (uint)*(byte *)((uint)param_2 * 0x2d + (uVar12 & 0xff) * 3 + 0x17e6)) = 0;
        *(undefined1 *)((uint)param_2 * 0x2d + 0x17e4) = (char)((ulong)((uVar12 & 0xff) + 1) % 0xd);
        FUN_1038_2478(param_1,param_2);
      }
      iVar5 = FUN_1038_16d2(param_2);
      uVar6 = (uint)param_2;
      uVar12 = 0x1038;
      cVar8 = '6';
      cVar2 = FUN_1038_1bb6(param_2,(char)iVar5);
      if (CONCAT11(extraout_AH,cVar2) == 0) {
        uVar12 = FUN_1048_0754();
        uVar9 = (int)uVar12 % 4 & 0xff;
        uVar12 = 0x1048;
        while( true ) {
          uVar6 = (uint)param_2;
          uVar10 = 0x125e;
          cVar2 = FUN_1038_1bb6(param_2,(char)uVar9);
          cVar8 = (char)uVar10;
          if (CONCAT11(extraout_AH_00,cVar2) != 0) break;
          uVar9 = (uint)(byte)((ulong)((uVar10 & 0xff) + 1) % 4);
          uVar12 = 0x1038;
        }
      }
      bVar13 = (byte)uVar6;
      bVar11 = (byte)uVar12;
      if (cVar8 == '\0') {
        if (*(char *)((uVar6 & 0xff) * 0x3d + (uVar12 & 0xff) + 0x45f) == '\x04') {
          bVar13 = 0x38;
          bVar11 = 0xab;
          FUN_1038_399a(param_1);
        }
        bVar11 = bVar11 - 2;
      }
      else if (cVar8 == '\x01') {
        if (*(char *)(((uVar6 & 0xff) + 1) * 0x3d + 0x460 + (uVar12 & 0xff)) == '\x04') {
          bVar13 = 0x38;
          bVar11 = 0xdf;
          FUN_1038_399a(param_1);
        }
        bVar13 = bVar13 + 2;
      }
      else if (cVar8 == '\x02') {
        if (*(char *)((uVar6 & 0xff) * 0x3d + (uVar12 & 0xff) + 0x461) == '\x04') {
          bVar13 = 0x38;
          bVar11 = 0x13;
          FUN_1038_399a(param_1);
        }
        bVar11 = bVar11 + 2;
      }
      else if (cVar8 == '\x03') {
        if (*(char *)(((uVar6 & 0xff) - 1) * 0x3d + 0x460 + (uVar12 & 0xff)) == '\x04') {
          bVar13 = 0x38;
          bVar11 = 0x47;
          FUN_1038_399a(param_1);
        }
        bVar13 = bVar13 - 2;
      }
      bVar7 = (byte)((ulong)(bVar1 + 1) % 0xd);
      *(byte *)((uint)param_2 * 0x2d + 0x17e3) = bVar7;
      *(char *)((uint)param_2 * 0x2d + (uint)bVar1 * 3 + 0x17e7) = cVar8;
      *(char *)((uint)param_2 * 0x2d + (uint)bVar7 * 3 + 0x17e7) = cVar8;
      *(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bVar7 * 3) = bVar13;
      *(byte *)((uint)param_2 * 0x2d + (uint)bVar7 * 3 + 0x17e6) = bVar11;
      *(undefined1 *)((uint)bVar13 * 0x3d + 0x460 + (uint)bVar11) = 1;
      if (*(char *)((uint)param_2 * 0x2d + 0x17e2) == '\x02') {
        FUN_1038_222a(param_1,param_2);
      }
      else {
        FUN_1038_2784(param_1,param_2,bVar1);
      }
      FUN_1038_25bc(param_1,param_2);
      bVar1 = bVar7;
    }
    else {
      FUN_1038_1d0e(param_1,param_2);
    }
    SELECTOBJECT(0x1038,uVar3);
    SELECTOBJECT(0x1170,uVar4);
    if (iRam105018ba != 0) {
      bVar11 = *(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bVar1 * 3);
      bVar1 = *(byte *)((uint)param_2 * 0x2d + (uint)bVar1 * 3 + 0x17e6);
      if (((uint)bRam105017ac + (uint)bRam1050044e) % 2 == 0) {
        if (((((bRam105017ac == (byte)(bVar11 - 1)) && (bRam1050044e == (byte)(bVar1 - 1))) ||
             ((bRam105017ac == (byte)(bVar11 - 1) && (bRam1050044e == (byte)(bVar1 + 1))))) ||
            ((bRam105017ac == (byte)(bVar11 + 1) && (bRam1050044e == (byte)(bVar1 - 1))))) ||
           ((bRam105017ac == (byte)(bVar11 + 1) && (bRam1050044e == (byte)(bVar1 + 1))))) {
          iRam10501608 = 1;
        }
        else {
          iRam10501608 = 0;
        }
      }
      else if ((uint)bRam105017ac % 2 == 0) {
        if ((bRam105017ac == bVar11) &&
           ((bRam1050044e == (byte)(bVar1 - 1) || (bRam1050044e == (byte)(bVar1 + 1))))) {
          iRam10501608 = 1;
        }
        else {
          iRam10501608 = 0;
        }
      }
      else if ((bRam1050044e == bVar1) &&
              ((bRam105017ac == (byte)(bVar11 - 1) || (bRam105017ac == (byte)(bVar11 + 1))))) {
        iRam10501608 = 1;
      }
      else {
        iRam10501608 = 0;
      }
    }
  }
  return;
}



int __cdecl16far FUN_1038_16d2(byte param_1)

{
  char *pcVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte bStack_10;
  
  runtime_stack_safety_check();
  uVar2 = *(undefined1 *)
           ((uint)param_1 * 0x2d + (uint)*(byte *)((uint)param_1 * 0x2d + 0x17e3) * 3 + 0x17e7);
  bVar3 = *(byte *)((uint)param_1 * 0x2d + 0x17e5 +
                   (uint)*(byte *)((uint)param_1 * 0x2d + 0x17e3) * 3);
  bVar5 = *(byte *)((uint)param_1 * 0x2d + (uint)*(byte *)((uint)param_1 * 0x2d + 0x17e3) * 3 +
                   0x17e6);
  if (*(byte *)((uint)param_1 * 0x2d + 0x17e2) < 0xd) {
    pcVar1 = (char *)((uint)param_1 * 0x2d + 0x17e2);
    *pcVar1 = *pcVar1 + '\x01';
    iVar8 = CONCAT11((char)((uint)param_1 * 0x2d >> 8),uVar2);
  }
  else if (iRam10501610 == 0) {
    uVar6 = FUN_1048_0754();
    if ((int)uVar6 % 3 == 0) {
      uVar6 = FUN_1048_0754();
      iVar8 = (int)uVar6 % 4;
    }
    else {
      iVar8 = CONCAT11((char)((uint)((int)uVar6 / 3) >> 8),uVar2);
    }
  }
  else if (*(char *)((bVar3 - 1) * 0x3d + 0x460 + (uint)bVar5) == '\x04') {
    iVar8 = 3;
  }
  else if (*(char *)((bVar3 + 1) * 0x3d + 0x460 + (uint)bVar5) == '\x04') {
    iVar8 = 1;
  }
  else if (*(char *)((uint)bVar3 * 0x3d + bVar5 + 0x45f) == '\x04') {
    iVar8 = 0;
  }
  else if (*(char *)((uint)bVar3 * 0x3d + bVar5 + 0x461) == '\x04') {
    iVar8 = 2;
  }
  else {
    if (bRam105017ac < bVar3) {
      bVar4 = bVar3 - bRam105017ac;
    }
    else {
      bVar4 = bRam105017ac - bVar3;
    }
    if (bRam1050044e < bVar5) {
      bVar5 = bVar5 - bRam1050044e;
    }
    else {
      bVar5 = bRam1050044e - bVar5;
    }
    bStack_10 = (byte)iRam10501610;
    if (iRam10501610 < 7) {
      if (3 < iRam10501610) {
        bStack_10 = bStack_10 - 3;
      }
    }
    else if (iRam10501610 < 10) {
      bStack_10 = bStack_10 - 6;
    }
    else {
      bStack_10 = bStack_10 - 9;
    }
    if ((uint)bStack_10 * 3 < (uint)bVar4 + (uint)bVar5) {
      uVar6 = FUN_1048_0754();
      if (iRam105018ba == 0) {
        iVar8 = 0x24;
      }
      else {
        iVar8 = 0x18;
      }
      if ((int)(uint)bStack_10 <= (int)uVar6 % iVar8) {
        uVar6 = FUN_1048_0754();
        if ((int)uVar6 % 3 != 0) {
          return CONCAT11((char)((uint)((int)uVar6 / 3) >> 8),uVar2);
        }
        uVar6 = FUN_1048_0754();
        return (int)uVar6 % 4;
      }
    }
    uVar6 = FUN_1048_0754();
    uVar7 = FUN_1048_0754();
    if ((int)uVar7 % (int)(uint)(byte)(bVar5 + 1) < (int)uVar6 % 0xbf) {
      if (bRam105017ac < bVar3) {
        if (*(char *)((bVar3 - 2) * 0x3d + 0x4a8) == '\0') {
          return 3;
        }
      }
      else if (*(char *)((bVar3 + 2) * 0x3d + 0x4a8) == '\0') {
        return 1;
      }
      if (bRam1050044e < 0x48) {
        if (*(char *)((uint)bVar3 * 0x3d + 0x4a6) == '\0') {
          return 0;
        }
      }
      else if (*(char *)((uint)bVar3 * 0x3d + 0x4aa) == '\0') {
        return 2;
      }
    }
    else {
      if (bRam1050044e < 0x48) {
        if (*(char *)((uint)bVar3 * 0x3d + 0x4a6) == '\0') {
          return 0;
        }
      }
      else if (*(char *)((uint)bVar3 * 0x3d + 0x4aa) == '\0') {
        return 2;
      }
      if (bRam105017ac < bVar3) {
        if (*(char *)((bVar3 - 2) * 0x3d + 0x4a8) == '\0') {
          return 3;
        }
      }
      else if (*(char *)((bVar3 + 2) * 0x3d + 0x4a8) == '\0') {
        return 1;
      }
    }
    uVar6 = FUN_1048_0754();
    if ((int)uVar6 % 3 == 0) {
      uVar6 = FUN_1048_0754();
      iVar8 = (int)uVar6 % 4;
    }
    else {
      iVar8 = CONCAT11((char)((uint)((int)uVar6 / 3) >> 8),uVar2);
    }
  }
  return iVar8;
}



char __cdecl16far FUN_1038_1bb6(byte param_1,char param_2)

{
  byte bVar1;
  byte bVar2;
  
  runtime_stack_safety_check();
  bVar1 = *(byte *)((uint)param_1 * 0x2d + 0x17e5 +
                   (uint)*(byte *)((uint)param_1 * 0x2d + 0x17e3) * 3);
  bVar2 = *(byte *)((uint)param_1 * 0x2d + (uint)*(byte *)((uint)param_1 * 0x2d + 0x17e3) * 3 +
                   0x17e6);
  if (param_2 == '\0') {
    param_2 = *(char *)((uint)bVar1 * 0x3d + bVar2 + 0x45e) == '\0';
  }
  else if (param_2 == '\x01') {
    param_2 = *(char *)((bVar1 + 2) * 0x3d + 0x460 + (uint)bVar2) == '\0';
  }
  else if (param_2 == '\x02') {
    param_2 = *(char *)((uint)bVar1 * 0x3d + bVar2 + 0x462) == '\0';
  }
  else if (param_2 == '\x03') {
    param_2 = *(char *)((bVar1 - 2) * 0x3d + 0x460 + (uint)bVar2) == '\0';
  }
  return param_2;
}



void __cdecl16far FUN_1038_1d0e(undefined2 param_1,byte param_2)

{
  byte bStackY_32;
  byte bStackY_30;
  byte bStackY_2e;
  undefined1 auStackY_2c [28];
  undefined2 uStackY_10;
  undefined2 uStackY_e;
  
  runtime_stack_safety_check();
  if (0xc < *(byte *)((uint)param_2 * 0x2d + 0x17e2)) {
    bStackY_2e = *(byte *)((uint)param_2 * 0x2d + 0x17e3);
    bStackY_30 = *(byte *)((uint)param_2 * 0x2d + 0x17e4);
    for (bStackY_32 = 0; bStackY_32 < 0xd; bStackY_32 = bStackY_32 + 1) {
      auStackY_2c[(uint)bStackY_30 * 3] =
           *(undefined1 *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bStackY_2e * 3);
      auStackY_2c[(uint)bStackY_30 * 3 + 1] =
           *(undefined1 *)((uint)param_2 * 0x2d + (uint)bStackY_2e * 3 + 0x17e6);
      bStackY_2e = (byte)((ulong)(bStackY_2e + 0xc) % 0xd);
      auStackY_2c[(uint)bStackY_30 * 3 + 2] =
           (char)((ulong)(*(byte *)((uint)param_2 * 0x2d + (uint)bStackY_2e * 3 + 0x17e7) + 2) % 4);
      bStackY_30 = (byte)((ulong)(bStackY_30 + 1) % 0xd);
    }
    auStackY_2c[(uint)*(byte *)((uint)param_2 * 0x2d + 0x17e3) * 3 + 2] =
         *(undefined1 *)
          ((uint)param_2 * 0x2d + (uint)(byte)((ulong)(bStackY_2e + 0xc) % 0xd) * 3 + 0x17e7);
    for (bStackY_32 = 0; bStackY_32 < 0xd; bStackY_32 = bStackY_32 + 1) {
      *(undefined1 *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bStackY_32 * 3) =
           auStackY_2c[(uint)bStackY_32 * 3];
      *(undefined1 *)((uint)param_2 * 0x2d + (uint)bStackY_32 * 3 + 0x17e6) =
           auStackY_2c[(uint)bStackY_32 * 3 + 1];
      *(undefined1 *)((uint)param_2 * 0x2d + (uint)bStackY_32 * 3 + 0x17e7) =
           auStackY_2c[(uint)bStackY_32 * 3 + 2];
    }
    uStackY_e = 0x1048;
    uStackY_10 = 0x1f70;
    FUN_1038_2478(param_1,param_2);
    uStackY_e = 0x1038;
    uStackY_10 = 0x1f82;
    FUN_1038_25bc(param_1,param_2);
  }
  return;
}



void __cdecl16far FUN_1038_1f90(undefined2 param_1,byte param_2)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 uVar6;
  
  runtime_stack_safety_check();
  uVar4 = SELECTOBJECT(0x1048,uRam1050160e);
  bVar2 = *(byte *)((uint)param_2 * 0x2d + 0x17e3);
  iVar5 = (*(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bVar2 * 3) + 1) * 6 + -2;
  if (*(char *)((uint)param_2 * 0x2d + 0x17e2) == '\r') {
    cVar3 = *(char *)((uint)param_2 * 0x2d + (uint)bVar2 * 3 + 0x17e7);
    if (cVar3 == '\0') {
      FUN_1038_2abc(param_1,iVar5,1,10,10,0x8c,1);
    }
    else if (cVar3 == '\x01') {
      FUN_1038_2abc(param_1,iVar5,1,10,10,0x96,1);
    }
    else if (cVar3 == '\x02') {
      FUN_1038_2abc(param_1,iVar5,1,10,10,0xa0,1);
    }
    else if (cVar3 == '\x03') {
      FUN_1038_2abc(param_1,iVar5,1,10,10,0xaa,1);
    }
  }
  FUN_1038_232e(param_1,param_2);
  *(undefined1 *)((uint)param_2 * 0x2d + 0x17e4) =
       (char)((ulong)(*(byte *)((uint)param_2 * 0x2d + 0x17e4) + 1) % 0xd);
  pcVar1 = (char *)((uint)param_2 * 0x2d + 0x17e2);
  *pcVar1 = *pcVar1 + -1;
  if (1 < *(byte *)((uint)param_2 * 0x2d + 0x17e2)) {
    FUN_1038_2478(param_1,param_2);
  }
  if (*(char *)((uint)param_2 * 0x2d + 0x17e2) == '\x01') {
    FUN_1038_2abc(param_1,iVar5,1,10,10,0xb4,1);
  }
  uVar6 = 0x1038;
  if ((*(char *)((uint)param_2 * 0x2d + 0x17e2) == '\0') && ((uint)param_2 == bRam1050178a - 1)) {
    FUN_1040_0000(0x68);
    FUN_1038_3574();
    uVar6 = 0x1170;
    BITBLT(0x1038,0x20,0xcc,0,0,uRam1050044c,0x15b,0x1a3,0x11,0x11);
    uRam105017b2 = 8;
    uRam10500448 = 0;
    uRam105017c4 = 1;
  }
  SELECTOBJECT(uVar6,uVar4);
  return;
}



void __cdecl16far FUN_1038_222a(undefined2 param_1,byte param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  runtime_stack_safety_check();
  iVar2 = (*(byte *)((uint)param_2 * 0x2d + 0x17e5) + 1) * 6 + -2;
  iVar3 = (*(byte *)((uint)param_2 * 0x2d + 0x17e6) + 1) * 6 + -2;
  cVar1 = *(char *)((uint)param_2 * 0x2d + 0x17e7);
  if (cVar1 == '\0') {
    FUN_1038_2abc(param_1,iVar2,iVar3,10,10,0xa0,1);
  }
  else if (cVar1 == '\x01') {
    FUN_1038_2abc(param_1,iVar2,iVar3,10,10,0xaa,1);
  }
  else if (cVar1 == '\x02') {
    FUN_1038_2abc(param_1,iVar2,iVar3,10,10,0x8c,1);
  }
  else if (cVar1 == '\x03') {
    FUN_1038_2abc(param_1,iVar2,iVar3,10,10,0x96,1);
  }
  return;
}



void __cdecl16far FUN_1038_232e(undefined2 param_1,byte param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  runtime_stack_safety_check();
  bVar1 = *(byte *)((uint)param_2 * 0x2d + 0x17e4);
  iVar3 = (*(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bVar1 * 3) + 1) * 6;
  iVar4 = iVar3 + -2;
  cVar2 = *(char *)((uint)param_2 * 0x2d + (uint)bVar1 * 3 + 0x17e7);
  if (cVar2 == '\0') {
    FUN_1038_2abc(param_1,iVar4,-2,10,0xc,0,0);
  }
  else if (cVar2 == '\x01') {
    FUN_1038_2abc(param_1,iVar4,0,0xc,10,0,0);
  }
  else if (cVar2 == '\x02') {
    FUN_1038_2abc(param_1,iVar4,0,10,0xc,0,0);
  }
  else if (cVar2 == '\x03') {
    FUN_1038_2abc(param_1,iVar3 + -4,0,0xc,10,0,0);
  }
  return;
}



void __cdecl16far FUN_1038_2478(undefined2 param_1,byte param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  runtime_stack_safety_check();
  bVar1 = *(byte *)((uint)param_2 * 0x2d + 0x17e4);
  iVar3 = (*(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bVar1 * 3) + 1) * 6 + -2;
  cVar2 = *(char *)((uint)param_2 * 0x2d + (uint)bVar1 * 3 + 0x17e7);
  if (cVar2 == '\0') {
    FUN_1038_2abc(param_1,iVar3,1,10,10,0x78,1);
  }
  else if (cVar2 == '\x01') {
    FUN_1038_2abc(param_1,iVar3,1,10,10,0x82,1);
  }
  else if (cVar2 == '\x02') {
    FUN_1038_2abc(param_1,iVar3,1,10,10,100,1);
  }
  else if (cVar2 == '\x03') {
    FUN_1038_2abc(param_1,iVar3,1,10,10,0x6e,1);
  }
  return;
}



void __cdecl16far FUN_1038_25bc(undefined2 param_1,byte param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  runtime_stack_safety_check();
  bVar1 = *(byte *)((uint)param_2 * 0x2d + 0x17e3);
  iVar3 = (*(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)bVar1 * 3) + 1) * 6;
  iVar4 = iVar3 + -2;
  cVar2 = *(char *)((uint)param_2 * 0x2d + ((bVar1 + 0xc) % 0xd) * 3 + 0x17e7);
  if (cVar2 == '\0') {
    FUN_1038_2abc(param_1,iVar4,0xb,10,2,0,1);
    FUN_1038_2abc(param_1,iVar4,1,10,10,0x3c,1);
  }
  else if (cVar2 == '\x01') {
    FUN_1038_2abc(param_1,iVar3 + -4,1,2,10,10,1);
    FUN_1038_2abc(param_1,iVar4,1,10,10,0x46,1);
  }
  else if (cVar2 == '\x02') {
    FUN_1038_2abc(param_1,iVar4,-1,10,2,0,1);
    FUN_1038_2abc(param_1,iVar4,1,10,10,0x50,1);
  }
  else if (cVar2 == '\x03') {
    FUN_1038_2abc(param_1,iVar3 + 8,1,2,10,10,1);
    FUN_1038_2abc(param_1,iVar4,1,10,10,0x5a,1);
  }
  return;
}



void __cdecl16far FUN_1038_2784(undefined2 param_1,byte param_2,byte param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  runtime_stack_safety_check();
  cVar1 = *(char *)((uint)param_2 * 0x2d + (uint)param_3 * 3 + 0x17e7);
  iVar3 = (*(byte *)((uint)param_2 * 0x2d + 0x17e5 + (uint)param_3 * 3) + 1) * 6;
  iVar4 = iVar3 + -2;
  cVar2 = *(char *)((uint)param_2 * 0x2d + ((param_3 + 0xc) % 0xd) * 3 + 0x17e7);
  if (cVar2 == '\0') {
    FUN_1038_2abc(param_1,iVar4,0xb,10,2,0,1);
    if (cVar1 == '\0') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0,1);
    }
    else if (cVar1 == '\x01') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x14,1);
    }
    else if (cVar1 == '\x03') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x1e,1);
    }
  }
  else if (cVar2 == '\x01') {
    FUN_1038_2abc(param_1,iVar3 + -4,1,2,10,10,1);
    if (cVar1 == '\0') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x32,1);
    }
    else if (cVar1 == '\x01') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,10,1);
    }
    else if (cVar1 == '\x02') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x1e,1);
    }
  }
  else if (cVar2 == '\x02') {
    FUN_1038_2abc(param_1,iVar4,-1,10,2,0,1);
    if (cVar1 == '\x01') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x28,1);
    }
    else if (cVar1 == '\x02') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0,1);
    }
    else if (cVar1 == '\x03') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x32,1);
    }
  }
  else if (cVar2 == '\x03') {
    FUN_1038_2abc(param_1,iVar3 + 8,1,2,10,10,1);
    if (cVar1 == '\0') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x28,1);
    }
    else if (cVar1 == '\x02') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,0x14,1);
    }
    else if (cVar1 == '\x03') {
      FUN_1038_2abc(param_1,iVar4,1,10,10,10,1);
    }
  }
  return;
}



void __cdecl16far
FUN_1038_2abc(undefined2 param_1,int param_2,int param_3,int param_4,int param_5,undefined2 param_6,
             int param_7)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  runtime_stack_safety_check();
  uVar1 = CREATESOLIDBRUSH();
  FILLRECT(0x1170,uVar1,&stack0xfff2);
  DELETEOBJECT(0x1170);
  if ((iRam10501610 == 0) && (iRam105015c8 != 0)) {
    if (param_2 - iRam1050045c < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_2 - iRam1050045c;
    }
    if (param_3 - iRam1050045e < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_3 - iRam1050045e;
    }
    if (((param_2 + param_4) - iRam1050045c) + -1 < 0x16a) {
      iVar4 = ((param_2 + param_4) - iRam1050045c) + -1;
    }
    else {
      iVar4 = 0x169;
    }
    if (((param_3 + param_5) - iRam1050045e) + -1 < 0x60) {
      iVar5 = ((param_3 + param_5) - iRam1050045e) + -1;
    }
    else {
      iVar5 = 0x5f;
    }
    if ((iVar2 <= iVar4) && (iVar3 <= iVar5)) {
      BITBLT(0x1170,0xc6,0x88,iVar3 + 0x60,iVar2,uRam105017e0,(iVar5 - iVar3) + 1,
             (iVar4 - iVar2) + 1,iRam1050045e + iVar3,iRam1050045c + iVar2);
    }
  }
  if (param_7 != 0) {
    BITBLT(0x1170,0xc6,0x88,10,param_6,uRam105015ca,param_5,param_4,param_3,param_2);
    BITBLT(0x1170,0x86,0xee,0,param_6,uRam105015ca,param_5,param_4,param_3,param_2);
  }
  if ((iRam10501610 == 0) && (iRam105015c8 != 0)) {
    if (param_2 - iRam105017ae < 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_2 - iRam105017ae;
    }
    if (param_3 - iRam105017b0 < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_3 - iRam105017b0;
    }
    if (((param_2 + param_4) - iRam105017ae) + -1 < 0x16a) {
      iVar4 = ((param_2 + param_4) - iRam105017ae) + -1;
    }
    else {
      iVar4 = 0x169;
    }
    if (((param_3 + param_5) - iRam105017b0) + -1 < 0x60) {
      iVar5 = ((param_3 + param_5) - iRam105017b0) + -1;
    }
    else {
      iVar5 = 0x5f;
    }
    if ((iVar2 <= iVar4) && (iVar3 <= iVar5)) {
      BITBLT(0x1170,0xc6,0x88,iVar3 + 0x60,iVar2,uRam105017e0,(iVar5 - iVar3) + 1,
             (iVar4 - iVar2) + 1,iRam105017b0 + iVar3,iRam105017ae + iVar2);
      BITBLT(0x1170,0x86,0xee,iVar3,iVar2,uRam105017e0,(iVar5 - iVar3) + 1,(iVar4 - iVar2) + 1,
             iRam105017b0 + iVar3,iRam105017ae + iVar2);
    }
  }
  BITBLT(0x1170,0x20,0xcc,param_3,param_2,uRam10500442,param_5,param_4,param_3 + 1,param_2 + 1);
  return;
}



void __cdecl16far FUN_1038_2da0(undefined2 param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  byte bVar3;
  
  runtime_stack_safety_check();
  draw_sprite_or_frame();
  uVar2 = 0x1170;
  uVar1 = SELECTOBJECT(0x1038,uRam1050160e);
  for (bVar3 = 0; bVar3 < bRam1050178a; bVar3 = bVar3 + 1) {
    uVar2 = 0x1038;
    FUN_1038_25bc(param_1,bVar3);
  }
  SELECTOBJECT(uVar2,uVar1);
  FUN_1040_0000(0x6a);
  return;
}



void __cdecl16far FUN_1038_2e22(void)

{
  runtime_stack_safety_check();
  uRam1050160c = 0;
  uRam105018c8 = 0;
  uRam105017d4 = 2;
  uRam105017c8 = 0;
  uRam105017ca = 0;
  uRam105017ac = 1;
  uRam1050044e = 1;
  uRam105017be = 2;
  uRam105017de = 0;
  uRam105018ba = 0;
  uRam1050161a = 0;
  uRam10501608 = 0;
  return;
}



void __cdecl16far FUN_1038_2e86(undefined2 param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  undefined1 extraout_AH;
  byte bVar3;
  
  runtime_stack_safety_check();
  if (cRam105018aa == '\0') {
    if (bRam1050160c != 0) {
      for (bVar3 = 0; bVar3 < bRam1050160c; bVar3 = bVar3 + 1) {
        *(undefined2 *)((uint)bVar3 * 2 + 0x18c8) = *(undefined2 *)((bVar3 + 1) * 2 + 0x18c8);
        *(undefined1 *)(bVar3 + 0x17d4) = *(undefined1 *)(bVar3 + 0x17d5);
      }
      bRam1050160c = bRam1050160c - 1;
    }
    if ((iRam105018c8 == 0) ||
       (cVar2 = FUN_1038_3232(bRam105017d4), CONCAT11(extraout_AH,cVar2) == 0)) {
      iRam105017de = 0;
    }
    else {
      iRam105017de = 1;
    }
    bRam105017be = bRam105017d4;
  }
  bVar1 = bRam105017ac;
  bVar3 = bRam1050044e;
  if (iRam105017de != 0) {
    iRam105018a6 = iRam105017c8;
    iRam105018a8 = iRam105017ca;
    if (bRam105017be == 0) {
      iRam105017ca = iRam105017ca + -3;
    }
    else if (bRam105017be == 1) {
      iRam105017c8 = iRam105017c8 + 3;
    }
    else if (bRam105017be == 2) {
      iRam105017ca = iRam105017ca + 3;
    }
    else if (bRam105017be == 3) {
      iRam105017c8 = iRam105017c8 + -3;
    }
    if ((cRam105018aa == '\0') || (cRam105018aa == '\x03')) {
      bRam10500446 = bRam105017ac;
      bRam10501646 = bRam1050044e;
      if (bRam105017be == 0) {
        bRam1050044e = bRam1050044e - 1;
      }
      else if (bRam105017be == 1) {
        bRam105017ac = bRam105017ac + 1;
      }
      else if (bRam105017be == 2) {
        bRam1050044e = bRam1050044e + 1;
      }
      else if (bRam105017be == 3) {
        bRam105017ac = bRam105017ac - 1;
      }
      if (iRam105018ba == 0) {
        if ((cRam105018aa == '\0') &&
           (*(char *)((uint)bRam105017ac * 0x3d + 0x460 + (uint)bRam1050044e) == '\0')) {
          if ((uint)bRam105017be % 2 == 0) {
            if ((*(char *)((bRam105017ac - 1) * 0x3d + 0x460 + (uint)bRam1050044e) == '\b') ||
               (*(char *)((bRam105017ac + 1) * 0x3d + 0x460 + (uint)bRam1050044e) == '\b')) {
              iRam105018ba = 0;
            }
            else {
              iRam105018ba = 1;
            }
          }
          else if ((*(char *)((uint)bRam105017ac * 0x3d + bRam1050044e + 0x45f) == '\b') ||
                  (*(char *)((uint)bRam105017ac * 0x3d + bRam1050044e + 0x461) == '\b')) {
            iRam105018ba = 0;
          }
          else {
            iRam105018ba = 1;
          }
          if (iRam105018ba != 0) {
            iRam1050161a = 1;
            bRam105017b6 = bVar1;
            bRam105018eb = bVar3;
            *(undefined1 *)((uint)bRam105017ac * 0x3d + 0x460 + (uint)bRam1050044e) = 4;
          }
        }
      }
      else if (cRam105018aa == '\0') {
        if (*(char *)((uint)bRam105017ac * 0x3d + 0x460 + (uint)bRam1050044e) == '\0') {
          if (iRam1050161a != 0) {
            *(undefined1 *)((uint)bRam105017ac * 0x3d + 0x460 + (uint)bRam1050044e) = 4;
          }
        }
        else {
          iRam1050161a = 0;
          FUN_1038_35ba();
        }
      }
      else {
        cVar2 = *(char *)((uint)bRam105017ac * 0x3d + 0x460 + (uint)bRam1050044e);
        if (cVar2 == '\0') {
          if (iRam1050161a != 0) {
            *(undefined1 *)((uint)bRam105017ac * 0x3d + 0x460 + (uint)bRam1050044e) = 4;
          }
        }
        else {
          if (cVar2 == '\x02') {
            draw_sprite_or_frame();
            if (iRam1050161a == 0) {
              FUN_1038_35ba();
            }
            else {
              FUN_1038_3f12(param_1,param_2);
            }
            iRam1050161a = 0;
            iRam105018ba = 0;
            return;
          }
          if (cVar2 == '\x04') {
            draw_sprite_or_frame();
            if (iRam1050161a == 0) {
              FUN_1038_35ba();
            }
            else {
              FUN_1038_366e(param_2);
            }
            iRam1050161a = 1;
            return;
          }
        }
      }
    }
  }
  draw_sprite_or_frame();
  return;
}



char __cdecl16far FUN_1038_3232(char param_1)

{
  runtime_stack_safety_check();
  if (param_1 == '\0') {
    if ((bRam1050044e < 2) ||
       ((*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x45f) == '\x01' &&
        (*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x45f) == '\x01')))) {
      param_1 = '\0';
    }
    else {
      param_1 = '\x01';
    }
  }
  else if (param_1 == '\x01') {
    if ((bRam105017ac < 0x46) &&
       ((*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x45f) != '\x01' ||
        (*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x461) != '\x01')))) {
      param_1 = '\x01';
    }
    else {
      param_1 = '\0';
    }
  }
  else if (param_1 == '\x02') {
    if ((bRam1050044e < 0x3a) &&
       ((*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x461) != '\x01' ||
        (*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x461) != '\x01')))) {
      param_1 = '\x01';
    }
    else {
      param_1 = '\0';
    }
  }
  else if (param_1 == '\x03') {
    if ((bRam105017ac < 2) ||
       ((*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x45f) == '\x01' &&
        (*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x461) == '\x01')))) {
      param_1 = '\0';
    }
    else {
      param_1 = '\x01';
    }
  }
  return param_1;
}



void __cdecl16far draw_sprite_or_frame(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 someHandle;
  
  someHandle = 0x1048;
  runtime_stack_safety_check();
  if ((iRam105017de != 0) && (iRam1050161a != 0)) {
    someHandle = CREATEPEN(0x1048,uRam1050161e,uRam10501620,1);
    uVar4 = uRam10500442;
    SELECTOBJECT(0x1170,someHandle);
    someHandle = uRam10500442;
    MOVETO(0x1170,iRam105018a8 + 0xf,iRam105018a6 + 0xf);
    uVar3 = uRam10500442;
    LINETO(0x1170,iRam105017ca + 0xf,iRam105017c8 + 0xf);
    uVar2 = uRam10500442;
    SELECTOBJECT(0x1170,someHandle);
    someHandle = 0x1170;
    DELETEOBJECT(0x1170,uVar4,uVar2,uVar3);
  }
  if (iRam105017de == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = ((uint)bRam105018aa % 2 + 1) * 0x18;
  }
  iVar1 = (uint)bRam105017be * 0x48 + iVar1;
  someHandle = SELECTOBJECT(someHandle,uRam10501900);
  uVar2 = SELECTOBJECT(0x1170,uRam10500456);
  BITBLT(0x1170,0x20,0xcc,iRam105017ca,iRam105017c8,uRam10500442,0x1e,0x1e,0,0);
  BITBLT(0x1170,0xc6,0x88,0x18,iVar1,uRam105017e0,0x18,0x18,3,3);
  BITBLT(0x1170,0x86,0xee,0,iVar1,uRam105017e0,0x18,0x18,3,3);
  BITBLT(0x1170,0x20,0xcc,0,0,uRam105015ca,0x1e,0x1e,iRam105017ca + 1,iRam105017c8 + 1);
  SELECTOBJECT(0x1170,someHandle);
  SELECTOBJECT(0x1170,uVar2);
  return;
}



void __cdecl16far FUN_1038_3574(void)

{
  runtime_stack_safety_check();
  BITBLT(0x1048,0x20,0xcc,iRam105017ca,iRam105017c8,uRam10500442,0x1e,0x1e,iRam105017ca + 1,
         iRam105017c8 + 1);
  return;
}



void __cdecl16far FUN_1038_35ba(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  runtime_stack_safety_check();
  *(undefined1 *)((uint)bRam10500446 * 0x3d + 0x460 + (uint)bRam10501646) = 0;
  uVar1 = CREATEPEN(0x1048,uRam1050190a,uRam1050190c,1);
  uVar6 = uRam10500442;
  uVar2 = SELECTOBJECT(0x1170,uVar1);
  uVar5 = uRam10500442;
  MOVETO(0x1170,(uint)bRam10501646 * 6 + 9,(uint)bRam10500446 * 6 + 9);
  uVar4 = uRam10500442;
  LINETO(0x1170,(uint)bRam1050044e * 6 + 9,(uint)bRam105017ac * 6 + 9);
  uVar3 = uRam10500442;
  SELECTOBJECT(0x1170,uVar2);
  DELETEOBJECT(0x1170,uVar1,uVar3,uVar4,uVar5,uVar6);
  return;
}



void __cdecl16far FUN_1038_366e(uint param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar4 = 0x1048;
  runtime_stack_safety_check();
  if (iRam1050161a != 0) {
    uVar4 = 0x1040;
    FUN_1040_0000(0x69);
  }
  uVar4 = CREATEPEN(uVar4,uRam1050190a,uRam1050190c,1);
  uVar1 = SELECTOBJECT(0x1170,uVar4);
  uVar2 = SELECTOBJECT(0x1170,uVar4);
  iVar3 = (uint)bRam1050044e * 6 + 9;
  iVar6 = 0x1170;
  uVar10 = uRam10500442;
  MOVETO(0x1170,iVar3,(uint)bRam105017ac * 6 + 9);
  uVar5 = param_1;
  MOVETO(0x1170,iVar6 + 1,iVar3 + 1);
  if (cRam105017be == '\0') {
    *(undefined1 *)((uVar10 & 0xff) * 0x3d + (uVar5 & 0xff) + 0x461) = 0;
    uVar5 = (uint)(byte)((char)uVar5 + 2);
  }
  else if (cRam105017be == '\x01') {
    *(undefined1 *)(((uVar10 & 0xff) - 1) * 0x3d + 0x460 + (uVar5 & 0xff)) = 0;
    uVar10 = (uint)(byte)((char)uVar10 - 2);
  }
  else if (cRam105017be == '\x02') {
    *(undefined1 *)((uVar10 & 0xff) * 0x3d + (uVar5 & 0xff) + 0x45f) = 0;
    uVar5 = (uint)(byte)((char)uVar5 - 2);
  }
  else if (cRam105017be == '\x03') {
    *(undefined1 *)(((uVar10 & 0xff) + 1) * 0x3d + 0x460 + (uVar5 & 0xff)) = 0;
    uVar10 = (uint)(byte)((char)uVar10 + 2);
  }
  uVar8 = uRam10500442;
  LINETO(0x1170,uRam10500442,uRam10500442);
  uVar7 = param_1;
  LINETO(0x1170,param_1 + 1,uVar8 + 1);
  while (((uint)bRam105017ac != (uVar10 & 0xff) || ((uint)bRam1050044e != (uVar5 & 0xff)))) {
    *(undefined1 *)((uVar10 & 0xff) * 0x3d + 0x460 + (uVar5 & 0xff)) = 0;
    uVar11 = uVar10;
    if (*(char *)(((uVar10 & 0xff) - 1) * 0x3d + 0x460 + (uVar5 & 0xff)) == '\x04') {
      *(undefined1 *)(((uVar10 & 0xff) - 1) * 0x3d + 0x460 + (uVar5 & 0xff)) = 0;
      uVar11 = (uint)(byte)((char)uVar10 - 2);
      uVar8 = uVar8 - 0xc;
    }
    if (*(char *)(((uVar10 & 0xff) + 1) * 0x3d + 0x460 + (uVar5 & 0xff)) == '\x04') {
      *(undefined1 *)(((uVar10 & 0xff) + 1) * 0x3d + 0x460 + (uVar5 & 0xff)) = 0;
      uVar11 = (uint)(byte)((char)uVar11 + 2);
      uVar8 = uVar8 + 0xc;
    }
    uVar9 = uVar5;
    if (*(char *)((uVar10 & 0xff) * 0x3d + (uVar5 & 0xff) + 0x45f) == '\x04') {
      *(undefined1 *)((uVar10 & 0xff) * 0x3d + (uVar5 & 0xff) + 0x45f) = 0;
      uVar9 = (uint)(byte)((char)uVar5 - 2);
      uVar7 = uVar7 - 0xc;
    }
    if (*(char *)((uVar10 & 0xff) * 0x3d + (uVar5 & 0xff) + 0x461) == '\x04') {
      *(undefined1 *)((uVar10 & 0xff) * 0x3d + (uVar5 & 0xff) + 0x461) = 0;
      uVar7 = uVar7 + 0xc;
      uVar9 = (uint)(byte)((char)uVar9 + 2);
    }
    uVar5 = uVar9;
    LINETO(0x1170,uVar7,uVar8);
    LINETO(0x1170,uVar7 + 1,uVar8 + 1);
    uVar10 = uVar11;
  }
  uVar5 = uRam10500442;
  SELECTOBJECT(0x1170,uVar1);
  SELECTOBJECT(0x1170,uVar2);
  DELETEOBJECT(0x1170,uVar4,param_1,uVar5);
  return;
}



void __cdecl16far FUN_1038_399a(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar7 = 0x1048;
  runtime_stack_safety_check();
  if (iRam1050161a != 0) {
    uVar7 = 0x1040;
    FUN_1040_0000(0x69);
  }
  if (*(char *)((uint)bRam105017ac * 0x3d + 0x460 + (uint)bRam1050044e) == '\x04') {
    uVar7 = CREATEPEN(uVar7,uRam1050190a,uRam1050190c,1);
    uVar1 = SELECTOBJECT(0x1170,uVar7);
    uVar2 = SELECTOBJECT(0x1170,uVar7);
    iVar10 = 1;
    uVar9 = (uint)bRam105017ac;
    uVar8 = uRam10500442;
    MOVETO(0x1170,iRam105017ca + 0xf,iRam105017c8 + 0xf);
    MOVETO(0x1170,param_1 + 2,param_1 + 1);
    do {
      iVar3 = (uVar9 & 0xff) * 6;
      iVar4 = iVar3 + 9;
      *(undefined1 *)((uVar9 & 0xff) * 0x3d + 0x460 + (uVar8 & 0xff)) = 0;
      if (*(char *)(((uVar9 & 0xff) - 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x04') {
        uVar9 = (uint)(byte)((char)uVar9 - 1);
      }
      else if (*(char *)(((uVar9 & 0xff) + 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x04') {
        uVar9 = (uint)(byte)((char)uVar9 + 1);
      }
      else if (*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x45f) == '\x04') {
        uVar8 = (uint)(byte)((char)uVar8 - 1);
      }
      else if (*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x461) == '\x04') {
        uVar8 = (uint)(byte)((char)uVar8 + 1);
      }
      else {
        iVar10 = 0;
      }
      iVar5 = param_1;
      LINETO(0x1170,param_1 + 1,iVar3 + 10);
      LINETO(0x1170,iVar5,iVar4);
    } while (iVar10 != 0);
    if ((((*(char *)(((uVar9 & 0xff) - 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x02') ||
         (*(char *)(((uVar9 & 0xff) + 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x02')) ||
        (*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x45f) == '\x02')) ||
       (*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x461) == '\x02')) {
      iVar10 = (uint)bRam105017b6 * 6 + 9;
      iVar3 = (uint)bRam105018eb * 6 + 9;
    }
    else {
      iVar10 = iRam105017c8 + 0xf;
      iVar3 = iRam105017ca + 0xf;
    }
    LINETO(0x1170,iVar3 + 1,iVar10 + 1);
    LINETO(0x1170,iVar3,iVar10);
    uVar9 = (uint)bRam105017ac;
    uVar8 = (uint)bRam1050044e;
    if (((*(char *)((bRam105017ac - 1) * 0x3d + 0x460 + (uint)bRam1050044e) == '\x04') ||
        (*(char *)((bRam105017ac + 1) * 0x3d + 0x460 + (uint)bRam1050044e) == '\x04')) ||
       ((*(char *)((uint)bRam105017ac * 0x3d + bRam1050044e + 0x45f) == '\x04' ||
        (*(char *)((uint)bRam105017ac * 0x3d + bRam1050044e + 0x461) == '\x04')))) {
      iVar4 = 1;
      iVar10 = iRam105017c8 + 0xf;
      iVar3 = iRam105017ca + 0xf;
      MOVETO(0x1170,iVar3,iVar10);
      MOVETO(0x1170,iVar3 + 1,iVar10 + 1);
      do {
        iVar10 = (uVar9 & 0xff) * 6;
        iVar3 = iVar10 + 9;
        iVar5 = (uVar8 & 0xff) * 6;
        iVar6 = iVar5 + 9;
        *(undefined1 *)((uVar9 & 0xff) * 0x3d + 0x460 + (uVar8 & 0xff)) = 0;
        if (*(char *)(((uVar9 & 0xff) - 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x04') {
          uVar9 = (uint)(byte)((char)uVar9 - 1);
        }
        else if (*(char *)(((uVar9 & 0xff) + 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x04') {
          uVar9 = (uint)(byte)((char)uVar9 + 1);
        }
        else if (*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x45f) == '\x04') {
          uVar8 = (uint)(byte)((char)uVar8 - 1);
        }
        else if (*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x461) == '\x04') {
          uVar8 = (uint)(byte)((char)uVar8 + 1);
        }
        else {
          iVar4 = 0;
        }
        LINETO(0x1170,iVar5 + 10,iVar10 + 10);
        LINETO(0x1170,iVar6,iVar3);
      } while (iVar4 != 0);
      if (((*(char *)(((uVar9 & 0xff) - 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x02') ||
          (*(char *)(((uVar9 & 0xff) + 1) * 0x3d + 0x460 + (uVar8 & 0xff)) == '\x02')) ||
         ((*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x45f) == '\x02' ||
          (*(char *)((uVar9 & 0xff) * 0x3d + (uVar8 & 0xff) + 0x461) == '\x02')))) {
        iVar10 = (uint)bRam105017b6 * 6 + 9;
        iVar3 = (uint)bRam105018eb * 6 + 9;
      }
      else {
        iVar10 = iRam105017c8 + 0xf;
        iVar3 = iRam105017ca + 0xf;
      }
      LINETO(0x1170,iVar3 + 1,iVar10 + 1);
      LINETO(0x1170,iVar3,iVar10);
    }
    iRam1050161a = 0;
    uVar8 = uRam10500442;
    SELECTOBJECT(0x1170,uVar1);
    SELECTOBJECT(0x1170,uVar2);
    DELETEOBJECT(0x1170,uVar7,param_1,uVar8);
  }
  return;
}



void __cdecl16far FUN_1038_3f12(undefined2 param_1,int param_2)

{
  char *pcVar1;
  byte bVar2;
  bool bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  int iVar15;
  int in_stack_0000fff0;
  uint uVar16;
  byte bVar17;
  uint uVar18;
  byte bVar19;
  
  uVar10 = 0x1048;
  runtime_stack_safety_check();
  for (bVar19 = 0; bVar19 < bRam1050178a; bVar19 = bVar19 + 1) {
    bVar17 = *(byte *)((uint)bVar19 * 0x2d + 0x17e5 +
                      (uint)*(byte *)((uint)bVar19 * 0x2d + 0x17e3) * 3);
    bVar2 = *(byte *)((uint)bVar19 * 0x2d + (uint)*(byte *)((uint)bVar19 * 0x2d + 0x17e3) * 3 +
                     0x17e6);
    if (*(byte *)((uint)bVar17 * 0x3d + 0x460 + (uint)bVar2) < 0x10) {
      uVar10 = 0x1038;
      in_stack_0000fff0 = 0x3fc4;
      FUN_1038_4906((uint)bVar17,(uint)bVar2);
    }
  }
  if (cRam105017be == '\0') {
    if (*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x461) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else if (*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x461) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else {
      in_stack_0000fff0 = 0;
    }
  }
  else if (cRam105017be == '\x01') {
    if (*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x461) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else if (*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x45f) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else {
      in_stack_0000fff0 = 0;
    }
  }
  else if (cRam105017be == '\x02') {
    if (*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x45f) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else if (*(char *)((bRam105017ac - 1) * 0x3d + bRam1050044e + 0x45f) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else {
      in_stack_0000fff0 = 0;
    }
  }
  else if (cRam105017be == '\x03') {
    if (*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x461) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else if (*(char *)((bRam105017ac + 1) * 0x3d + bRam1050044e + 0x45f) == '\0') {
      in_stack_0000fff0 = 1;
    }
    else {
      in_stack_0000fff0 = 0;
    }
  }
  for (uVar18 = 2; (byte)uVar18 < 0x47; uVar18 = (uint)(byte)((byte)uVar18 + 2)) {
    for (uVar16 = 2; (byte)uVar16 < 0x3b; uVar16 = (uint)(byte)((byte)uVar16 + 2)) {
      if (0xf < *(byte *)(uVar18 * 0x3d + 0x460 + uVar16)) {
        pcVar1 = (char *)(uVar18 * 0x3d + 0x460 + uVar16);
        *pcVar1 = *pcVar1 + -0x10;
      }
    }
  }
  if (in_stack_0000fff0 == 0) {
    iVar6 = 0;
  }
  else {
    uVar16 = 0x427d;
    FUN_1040_0000(0x66);
    uVar18 = uVar10 & 0xff;
    uVar10 = 0x1038;
    iVar6 = 0x4293;
    FUN_1038_47c4(uVar18,uVar16 & 0xff);
    for (uVar18 = 2; (byte)uVar18 < 0x47; uVar18 = (uint)(byte)((char)uVar18 + 2)) {
      for (uVar16 = 2; (byte)uVar16 < 0x3b; uVar16 = (uint)(byte)((char)uVar16 + 2)) {
        if (*(char *)((uVar18 & 0xff) * 0x3d + 0x460 + uVar16) == '\x10') {
          *(undefined1 *)((uVar18 & 0xff) * 0x3d + 0x460 + uVar16) = 8;
          iVar7 = (uVar18 & 0xff) * 6;
          iVar15 = uVar16 * 6;
          iVar6 = iVar7 + -0xc;
          iVar8 = iVar15 + -0xc;
          if (*(char *)(((uVar18 & 0xff) + 1) * 0x3d + 0x460 + uVar16) == '\0') {
            uVar5 = 0xc;
          }
          else {
            uVar5 = 0xb;
          }
          if (*(char *)((uVar18 & 0xff) * 0x3d + uVar16 + 0x461) == '\0') {
            uVar4 = 0xc;
          }
          else {
            uVar4 = 0xb;
          }
          uVar14 = 0xcc;
          uVar13 = 0x20;
          iVar11 = 0x43f3;
          iVar9 = iRam1050044c;
          uVar16 = uRam10500442;
          BITBLT(uVar10,0x20,0xcc,iVar8,iVar6,iRam1050044c,uVar4,uVar5,iVar15 + 4,iVar7 + 4);
          uVar12 = uVar10;
          if (iVar9 != 0) {
            iVar7 = iVar6 + uVar10;
            iVar15 = iVar8 + iVar11;
            iVar6 = 0x1170;
            iVar8 = 0x441a;
            SETPIXEL(0x1170,uRam1050161e,uRam10501620,iVar15 + -1,iVar7 + -1);
            uVar12 = uVar10;
          }
          iVar6 = iVar6 + 1;
          iVar9 = 0xcc;
          iVar15 = 0x20;
          uVar10 = 0x1170;
          iVar7 = iRam1050044c;
          BITBLT(0x1170,0x20,0xcc,uVar13,uVar14,iRam1050044c,iVar11,uVar12,iVar8 + 1,iVar6);
          if (uVar12 != 0) {
            uVar10 = 0x1170;
            iVar6 = param_2;
            SETPIXEL(0x1170,uRam1050161e,uRam10501620,iVar7 + iVar15 + -1,iVar11 + iVar9 + -1);
          }
        }
      }
    }
  }
  if (iVar6 == 0) {
    if (iRam1050161a != 0) {
      uVar10 = 0x1040;
      FUN_1040_0000(0x69);
    }
    uVar5 = CREATEPEN(uVar10,uRam1050190a,uRam1050190c,1);
    SELECTOBJECT(0x1170,uVar5);
    SELECTOBJECT(0x1170,uVar5);
    uVar18 = (uint)bRam105017ac;
    uVar10 = (uint)bRam1050044e;
    iVar6 = iRam105017c8 + 0xf;
    iVar7 = iRam105017ca + 0xf;
    if (cRam105017be == '\0') {
      iVar7 = iRam105017ca + 0x10;
    }
    else if (cRam105017be == '\x01') {
      iVar6 = iRam105017c8 + 0xe;
    }
    else if (cRam105017be == '\x02') {
      iVar7 = iRam105017ca + 0xe;
    }
    else if (cRam105017be == '\x03') {
      iVar6 = iRam105017c8 + 0x10;
    }
    MOVETO(0x1170,iVar7,iVar6);
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 1;
    uVar5 = 0x1170;
    iVar15 = param_2;
    MOVETO(0x1170,iVar7,iVar6);
    do {
      if (*(char *)((uVar18 & 0xff) * 0x3d + 0x460 + (uVar10 & 0xff)) == '\x04') {
        *(undefined1 *)((uVar18 & 0xff) * 0x3d + 0x460 + (uVar10 & 0xff)) = 0;
      }
      if (*(char *)(((uVar18 & 0xff) - 1) * 0x3d + 0x460 + (uVar10 & 0xff)) == '\x04') {
        uVar18 = (uint)(byte)((char)uVar18 - 1);
      }
      else if (*(char *)(((uVar18 & 0xff) + 1) * 0x3d + 0x460 + (uVar10 & 0xff)) == '\x04') {
        uVar18 = (uint)(byte)((char)uVar18 + 1);
      }
      else if (*(char *)((uVar18 & 0xff) * 0x3d + (uVar10 & 0xff) + 0x45f) == '\x04') {
        uVar10 = (uint)(byte)((char)uVar10 - 1);
      }
      else if (*(char *)((uVar18 & 0xff) * 0x3d + (uVar10 & 0xff) + 0x461) == '\x04') {
        uVar10 = (uint)(byte)((char)uVar10 + 1);
      }
      else {
        iVar15 = 0;
      }
      if (iVar15 != 0) {
        iVar8 = (uVar18 & 0xff) * 6 + 9;
        iVar9 = (uVar10 & 0xff) * 6 + 9;
        LINETO(0x1170,iVar9,iVar8);
        uVar18 = 0x1170;
        uVar10 = 0x4742;
        LINETO(0x1170,iVar9 + 1,iVar8 + 1);
      }
    } while (iVar15 != 0);
    iVar8 = (uint)bRam105017b6 * 6 + 9;
    iVar9 = (uint)bRam105018eb * 6 + 9;
    LINETO(0x1170,iVar9,iVar8);
    iVar15 = param_2;
    LINETO(0x1170,iVar9 + 1,iVar8 + 1);
    uVar10 = uRam10500442;
    SELECTOBJECT(0x1170,iVar7);
    SELECTOBJECT(0x1170,uVar5);
    DELETEOBJECT(0x1170,iVar6,param_2,uVar10,iVar15);
  }
  else {
    bVar3 = true;
    bVar17 = bRam1050044e;
    bVar19 = bRam105017ac;
    do {
      *(undefined1 *)((uint)bVar19 * 0x3d + 0x460 + (uint)bVar17) = 2;
      if (*(char *)((bVar19 - 1) * 0x3d + 0x460 + (uint)bVar17) == '\x04') {
        bVar19 = bVar19 - 1;
      }
      else if (*(char *)((bVar19 + 1) * 0x3d + 0x460 + (uint)bVar17) == '\x04') {
        bVar19 = bVar19 + 1;
      }
      else if (*(char *)((uint)bVar19 * 0x3d + bVar17 + 0x45f) == '\x04') {
        bVar17 = bVar17 - 1;
      }
      else if (*(char *)((uint)bVar19 * 0x3d + bVar17 + 0x461) == '\x04') {
        bVar17 = bVar17 + 1;
      }
      else {
        bVar3 = false;
      }
    } while (bVar3);
  }
  iRam1050161a = 0;
  draw_sprite_or_frame();
  return;
}



void __cdecl16far FUN_1038_47c4(int param_1,int param_2)

{
  bool bVar1;
  
  runtime_stack_safety_check();
  bVar1 = 0xfffe < uRam105017c0;
  uRam105017c0 = uRam105017c0 + 1;
  iRam105017c2 = iRam105017c2 + (uint)bVar1;
  *(undefined1 *)(param_1 * 0x3d + 0x460 + param_2) = 0x10;
  if ((*(char *)((param_1 + -1) * 0x3d + 0x460 + param_2) == '\0') &&
     (*(char *)((param_1 + -2) * 0x3d + 0x460 + param_2) == '\0')) {
    FUN_1038_47c4(param_1 + -2,param_2);
  }
  if ((*(char *)((param_1 + 1) * 0x3d + 0x460 + param_2) == '\0') &&
     (*(char *)((param_1 + 2) * 0x3d + 0x460 + param_2) == '\0')) {
    FUN_1038_47c4(param_1 + 2,param_2);
  }
  if ((*(char *)(param_1 * 0x3d + param_2 + 0x45f) == '\0') &&
     (*(char *)(param_1 * 0x3d + param_2 + 0x45e) == '\0')) {
    FUN_1038_47c4(param_1,param_2 + -2);
  }
  if ((*(char *)(param_1 * 0x3d + param_2 + 0x461) == '\0') &&
     (*(char *)(param_1 * 0x3d + param_2 + 0x462) == '\0')) {
    FUN_1038_47c4(param_1,param_2 + 2);
  }
  return;
}



void __cdecl16far FUN_1038_4906(int param_1,int param_2)

{
  char *pcVar1;
  
  runtime_stack_safety_check();
  pcVar1 = (char *)(param_1 * 0x3d + 0x460 + param_2);
  *pcVar1 = *pcVar1 + '\x10';
  if ((*(char *)((param_1 + -1) * 0x3d + 0x460 + param_2) == '\0') &&
     (*(byte *)((param_1 + -2) * 0x3d + 0x460 + param_2) < 0x10)) {
    FUN_1038_4906(param_1 + -2,param_2);
  }
  if ((*(char *)((param_1 + 1) * 0x3d + 0x460 + param_2) == '\0') &&
     (*(byte *)((param_1 + 2) * 0x3d + 0x460 + param_2) < 0x10)) {
    FUN_1038_4906(param_1 + 2,param_2);
  }
  if ((*(char *)(param_1 * 0x3d + param_2 + 0x45f) == '\0') &&
     (*(byte *)(param_1 * 0x3d + param_2 + 0x45e) < 0x10)) {
    FUN_1038_4906(param_1,param_2 + -2);
  }
  if ((*(char *)(param_1 * 0x3d + param_2 + 0x461) == '\0') &&
     (*(byte *)(param_1 * 0x3d + param_2 + 0x462) < 0x10)) {
    FUN_1038_4906(param_1,param_2 + 2);
  }
  return;
}



void __cdecl16far FUN_1040_0000(int param_1)

{
  code *pcVar1;
  int iVar2;
  code *pcVar3;
  
                    // Segment:    9
                    // Offset:     0000bfb0
                    // Length:     0255
                    // Min Alloc:  0255
                    // Flags:      1d10
                    //     Code
                    //     Discardable
                    //     Moveable
                    //     LoadOnCall
                    //     Impure (Non-shareable)
                    // 
  runtime_stack_safety_check();
  if (param_1 == 0) {
    if (iRam10501896 != 0) {
      iVar2 = iRam10501896;
      pcVar1 = (code *)GETPROCADDRESS(0x1048,0x2d2,0x1050);
      if (pcVar1 != (code *)0x0) {
        (*(code *)pcVar1)(0x1170,0,0,0,iVar2);
      }
    }
  }
  else if (iRam10501788 != 0) {
    if (iRam10501896 == 0) {
      pcVar1 = (code *)0x0;
    }
    else {
      pcVar1 = (code *)GETPROCADDRESS(0x1048,0x2df,0x1050);
    }
    pcVar3 = (code *)pcVar1;
    switch(param_1) {
    case 0x65:
      if ((pcVar1 != (code *)0x0) && ((iRam10500450 != 0 || (iRam10500452 != 0)))) {
        (*pcVar3)(0x1040,7,iRam10500450,iRam10500452);
      }
      break;
    case 0x66:
      if ((pcVar1 != (code *)0x0) && ((iRam10501604 != 0 || (iRam10501606 != 0)))) {
        (*pcVar3)(0x1040,7,iRam10501604,iRam10501606);
      }
      break;
    case 0x68:
      if ((pcVar1 != (code *)0x0) && ((iRam105018a2 != 0 || (iRam105018a4 != 0)))) {
        (*pcVar3)(0x1040,7,iRam105018a2,iRam105018a4);
      }
      break;
    case 0x69:
      if ((pcVar1 != (code *)0x0) && ((iRam105018c2 != 0 || (iRam105018c4 != 0)))) {
        (*pcVar3)(0x1040,7,iRam105018c2,iRam105018c4);
      }
      break;
    case 0x6a:
      if ((pcVar1 == (code *)0x0) || ((iRam105018b6 == 0 && (iRam105018b8 == 0)))) {
        MESSAGEBEEP(0x1040,0);
      }
      else {
        (*pcVar3)(0x1040,7,iRam105018b6,iRam105018b8);
      }
      break;
    case 0x6b:
      if ((pcVar1 == (code *)0x0) || ((iRam105017cc == 0 && (iRam105017ce == 0)))) {
        MESSAGEBEEP(0x1040,0);
      }
      else {
        (*pcVar3)(0x1040,7,iRam105017cc,iRam105017ce);
      }
      break;
    case 0x6c:
      if ((pcVar1 == (code *)0x0) || ((iRam105017ba == 0 && (iRam105017bc == 0)))) {
        MESSAGEBEEP(0x1040,0);
      }
      else {
        (*pcVar3)(0x1040,7,iRam105017ba,iRam105017bc);
      }
      break;
    case 0x6d:
      if ((pcVar1 != (code *)0x0) && ((iRam1050178e != 0 || (iRam10501790 != 0)))) {
        (*pcVar3)(0x1040,7,iRam1050178e,iRam10501790);
      }
      break;
    case 0x6e:
      if ((pcVar1 != (code *)0x0) && ((iRam105017d0 != 0 || (iRam105017d2 != 0)))) {
        (*pcVar3)(0x1040,7,iRam105017d0,iRam105017d2);
      }
    }
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x1048005b)

void entry(void)

{
  int initAppReturn;
  uint in_CX;
  undefined2 in_BX;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  bool bVar1;
  undefined4 initTaskReturn;
  undefined2 uVar2;
  code *dos_interrupt_function_pointer;
  
  do {
    initTaskReturn = INITTASK(unaff_CS,0);
    if (((int)initTaskReturn != 0) &&
       (bVar1 = in_CX < 0xff00, in_CX = in_CX + 0x100, DAT_1050_00c8 = unaff_ES, bVar1)) {
      uVar2 = 0x4d;
      DAT_1050_0092 = in_CX;
      DAT_1050_0094 = unaff_SI;
      DAT_1050_0096 = unaff_DI;
      DAT_1050_0098 = in_BX;
      DAT_1050_009a = unaff_ES;
      DAT_1050_009c = (int)((ulong)initTaskReturn >> 0x10);
      g_version = GETVERSION(0x1170);
                    // swi means 'software interrupt'
      dos_interrupt_function_pointer = (code *)swi(0x21);
      g_dos_interrupt_return_val = (*dos_interrupt_function_pointer)();
      DAT_1050_00cf = 0;
      WAITEVENT(0x1048,0,uVar2);
      initAppReturn = INITAPP(0x1170,DAT_1050_0096);
      if (initAppReturn != 0) {
        FUN_1048_00e8();
        FUN_1048_0332(0x1048);
        copy_environment_excluding_c_file_info();
        noop();
        run_main_message_loop();
        call_some_cleanup_function_with_0();
        fatal_app_exit(0x15);
        return;
      }
    }
    unaff_CS = 0x1048;
    call_some_cleanup_function_with_1();
  } while( true );
}



void __cdecl16far run_main_message_loop(void)

{
  main_message_loop();
  return;
}



// WARNING: Removing unreachable block (ram,0x104800fe)
// WARNING: Removing unreachable block (ram,0x10480120)

void __cdecl16far FUN_1048_00e8(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  undefined2 in_BX;
  int unaff_BP;
  byte *pbVar7;
  byte *pbVar8;
  undefined2 unaff_ES;
  undefined2 uVar9;
  undefined2 unaff_SS;
  bool bVar10;
  
  pcVar5 = (code *)swi(0x21);
  (*pcVar5)(unaff_BP + 1);
  uVar9 = 0x1048;
  pcVar5 = (code *)swi(0x21);
  DAT_1050_00b4 = in_BX;
  DAT_1050_00b6 = unaff_ES;
  (*pcVar5)();
  if (*(int *)&DAT_1050_0126 != 0) {
    bVar10 = false;
    (*(code *)*(undefined2 *)&g_someCleanupFunctionPointer)(0x1048,uVar9);
    if (bVar10) {
      fatal_app_exit_2();
      return;
    }
    (*(code *)*(undefined2 *)&g_someCleanupFunctionPointer)(0x1048);
  }
  iVar4 = *(int *)((char *)s_MAMBA_CNTR_RA_2_1050_0020 + 0xc);
  if (iVar4 != 0) {
    pbVar8 = (byte *)0x0;
    do {
      bVar10 = *pbVar8 == 0;
      if (bVar10) break;
      iVar6 = 0xd;
      pbVar7 = (byte *)s__C_FILE_INFO__1050_00a6;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pbVar3 = pbVar8;
        pbVar8 = pbVar8 + 1;
        pbVar1 = pbVar7;
        pbVar7 = pbVar7 + 1;
        bVar10 = *pbVar1 == *pbVar3;
      } while (bVar10);
      if (bVar10) {
        pbVar7 = (byte *)0xd8;
        goto LAB_1048_018f;
      }
      iVar6 = 0x7fff;
      bVar10 = true;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pbVar1 = pbVar8;
        pbVar8 = pbVar8 + 1;
        bVar10 = *pbVar1 == 0;
      } while (!bVar10);
    } while (bVar10);
  }
LAB_1048_01a3:
  noop_maybe_run_cleanup_callbacks();
  noop_maybe_run_cleanup_callbacks();
  noop_maybe_run_cleanup_callbacks();
  noop_maybe_run_cleanup_callbacks();
  noop_maybe_run_cleanup_callbacks();
  return;
LAB_1048_018f:
  pbVar1 = pbVar8;
  pbVar2 = pbVar8 + 1;
  if (*pbVar1 < 0x41) goto LAB_1048_01a3;
  pbVar8 = pbVar8 + 2;
  if (*pbVar2 < 0x41) goto LAB_1048_01a3;
  pbVar3 = pbVar7;
  pbVar7 = pbVar7 + 1;
  *pbVar3 = *pbVar2 + 0xbf | (*pbVar1 + 0xbf) * '\x10';
  goto LAB_1048_018f;
}



void call_some_cleanup_function_with_0(void)

{
  some_cleanup_function(0);
  return;
}



void call_some_cleanup_function_with_1(void)

{
  some_cleanup_function(1);
  return;
}



// WARNING: Removing unreachable block (ram,0x10480263)

void __cdecl16far some_cleanup_function(int param_in_CX)

{
  code *pcVar1;
  char cVar2;
  
  DAT_1050_010d = (undefined1)((uint)param_in_CX >> 8);
  if ((char)param_in_CX == '\0') {
    noop_maybe_run_cleanup_callbacks();
    noop_maybe_run_cleanup_callbacks();
    noop();
  }
  cVar2 = (char)((uint)param_in_CX >> 8);
  noop_maybe_run_cleanup_callbacks();
  noop_maybe_run_cleanup_callbacks();
  FUN_1048_0277();
  if (cVar2 == '\0') {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x10480295)

void __cdecl16near FUN_1048_0277(void)

{
  code *dos_interrupt_function_pointer;
  
  if (DAT_1050_0126 != 0) {
    (*g_someCleanupFunctionPointer)();
  }
  dos_interrupt_function_pointer = (code *)swi(0x21);
  (*dos_interrupt_function_pointer)();
  return;
}



void __cdecl16near noop_maybe_run_cleanup_callbacks(void)

{
  int *piVar1;
  int *unaff_SI;
  int *unaff_DI;
  int *piVar2;
  
  while (unaff_SI < unaff_DI) {
    piVar2 = unaff_DI + -2;
    piVar1 = unaff_DI + -1;
    unaff_DI = piVar2;
    if (*piVar2 != 0 || *piVar1 != 0) {
      (*(code *)*piVar2)();
    }
  }
  return;
}



void __cdecl16far FUN_1048_02b4(void)

{
  FUN_1048_05c3();
  FUN_1048_05c3();
  return;
}



void fatal_app_exit_2(void)

{
  fatal_app_exit(2);
  return;
}



// WARNING (jumptable): Unable to track spacebase fully for stack
// WARNING: Unable to track spacebase fully for stack

void __cdecl16far runtime_stack_safety_check(void)

{
  int in_AX;
  undefined1 *puVar1;
  uint uVar2;
  undefined2 unaff_SS;
  undefined2 in_stack_00000000;
  undefined2 in_stack_00000002;
  
  puVar1 = (undefined1 *)(in_AX + 1U & 0xfffe);
  if ((puVar1 < &stack0x0004) && (uVar2 = -((int)puVar1 - (int)&stack0x0004), *(uint *)0xa <= uVar2)
     ) {
    if (uVar2 < *(uint *)0xc) {
      *(uint *)0xc = uVar2;
    }
    *(undefined2 *)(uVar2 - 2) = in_stack_00000002;
    *(undefined2 *)(uVar2 - 4) = in_stack_00000000;
    return;
  }
  if (DAT_1050_0112 != 0xffff) {
                    // WARNING: Could not recover jumptable at 0x10480327. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)(ulong)DAT_1050_0112)();
    return;
  }
  fatal_app_exit(0);
  return;
}



// WARNING (jumptable): Unable to track spacebase fully for stack
// WARNING: Unable to track spacebase fully for stack

void FUN_1048_0332(undefined2 param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined2 *puVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  undefined2 uVar12;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 uVar13;
  undefined4 uVar14;
  undefined2 in_stack_00000000;
  
  DAT_1050_0118 = param_1;
  param_1 = 0x343;
  DAT_1050_0116 = in_stack_00000000;
  uVar14 = allocate_4k_block_or_exit();
  iVar6 = DAT_1050_0096;
  DAT_1050_0108 = (undefined2)((ulong)uVar14 >> 0x10);
  DAT_1050_0106 = (int)uVar14;
  param_1 = DAT_1050_0108;
  iVar3 = GETMODULEFILENAME(unaff_CS,0x104,uVar14);
  *(undefined1 *)(iVar6 + iVar3) = 0;
  iVar6 = 1;
  iVar3 = 1;
  pcVar8 = (char *)s_picture_1050_007c + 5;
LAB_1048_0370:
  do {
    do {
      pcVar1 = pcVar8;
      pcVar8 = pcVar8 + 1;
      cVar2 = *pcVar1;
    } while (cVar2 == ' ');
  } while (cVar2 == '\t');
  if ((cVar2 != '\r') && (cVar2 != '\0')) {
    iVar3 = iVar3 + 1;
    do {
      pcVar8 = pcVar8 + -1;
LAB_1048_0383:
      pcVar1 = pcVar8;
      pcVar8 = pcVar8 + 1;
      cVar2 = *pcVar1;
      if ((cVar2 == ' ') || (cVar2 == '\t')) goto LAB_1048_0370;
      if ((cVar2 == '\r') || (cVar2 == '\0')) break;
      if (cVar2 == '\"') {
LAB_1048_03bc:
        do {
          while( true ) {
            while( true ) {
              pcVar1 = pcVar8;
              pcVar8 = pcVar8 + 1;
              cVar2 = *pcVar1;
              if ((cVar2 == '\r') || (cVar2 == '\0')) goto LAB_1048_03ec;
              if (cVar2 == '\"') goto LAB_1048_0383;
              if (cVar2 == '\\') break;
              iVar6 = iVar6 + 1;
            }
            uVar4 = 0;
            do {
              pcVar11 = pcVar8;
              uVar4 = uVar4 + 1;
              pcVar8 = pcVar11 + 1;
            } while (*pcVar11 == '\\');
            if (*pcVar11 == '\"') break;
            iVar6 = iVar6 + uVar4;
            pcVar8 = pcVar11;
          }
          iVar6 = iVar6 + (uVar4 >> 1) + (uint)((uVar4 & 1) != 0);
        } while ((uVar4 & 1) != 0);
        goto LAB_1048_0383;
      }
      if (cVar2 != '\\') {
        iVar6 = iVar6 + 1;
        goto LAB_1048_0383;
      }
      uVar4 = 0;
      do {
        uVar4 = uVar4 + 1;
        pcVar1 = pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (*pcVar1 == '\\');
      if (*pcVar1 == '\"') {
        iVar6 = iVar6 + (uVar4 >> 1) + (uint)((uVar4 & 1) != 0);
        if ((uVar4 & 1) == 0) goto LAB_1048_03bc;
        goto LAB_1048_0383;
      }
      iVar6 = iVar6 + uVar4;
    } while( true );
  }
LAB_1048_03ec:
  *(int *)&DAT_1050_0100 = iVar3;
  iVar10 = (iVar3 + 1) * 2;
  iVar6 = -(iVar6 + iVar3 + iVar10 + 1U & 0xfffe);
  *(int *)0x102 = (int)&param_1 + iVar6;
  pcVar11 = (char *)((int)&param_1 + iVar10 + iVar6);
  *(undefined2 *)(&stack0x0000 + iVar6) = unaff_SS;
  uVar12 = *(undefined2 *)(&stack0x0000 + iVar6);
  *(undefined2 *)((int)&param_1 + iVar6) = (int)*(undefined4 *)&DAT_1050_0106;
  puVar7 = (undefined2 *)(&stack0x0004 + iVar6);
  uVar13 = *(undefined2 *)&DAT_1050_00c8;
  pcVar8 = (char *)s_picture_1050_007c + 5;
LAB_1048_0420:
  do {
    do {
      pcVar1 = pcVar8;
      pcVar8 = pcVar8 + 1;
      cVar2 = *pcVar1;
    } while (cVar2 == ' ');
  } while (cVar2 == '\t');
  if ((cVar2 == '\r') || (cVar2 == '\0')) {
LAB_1048_04a9:
    *(undefined2 *)(&stack0x0000 + iVar6) = unaff_SS;
    uVar13 = *(undefined2 *)(&stack0x0000 + iVar6);
    *puVar7 = 0;
                    // WARNING: Could not recover jumptable at 0x104804af. Too many branches
                    // WARNING: Treating indirect jump as call
    (*(code *)(ulong)*(uint *)&DAT_1050_0116)();
    return;
  }
  *puVar7 = pcVar11;
  puVar7 = puVar7 + 1;
  do {
    pcVar8 = pcVar8 + -1;
LAB_1048_0437:
    pcVar1 = pcVar8;
    pcVar8 = pcVar8 + 1;
    cVar2 = *pcVar1;
    if ((cVar2 == ' ') || (cVar2 == '\t')) {
      pcVar1 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar1 = '\0';
      goto LAB_1048_0420;
    }
    if ((cVar2 == '\r') || (cVar2 == '\0')) {
LAB_1048_04a6:
      *pcVar11 = '\0';
      goto LAB_1048_04a9;
    }
    pcVar9 = pcVar8;
    if (cVar2 == '\"') {
LAB_1048_0473:
      while( true ) {
        pcVar8 = pcVar9 + 1;
        cVar2 = *pcVar9;
        if ((cVar2 == '\r') || (cVar2 == '\0')) goto LAB_1048_04a6;
        if (cVar2 == '\"') break;
        if (cVar2 == '\\') {
          uVar4 = 0;
          do {
            pcVar9 = pcVar8;
            uVar4 = uVar4 + 1;
            pcVar8 = pcVar9 + 1;
          } while (*pcVar9 == '\\');
          if (*pcVar9 == '\"') {
            for (uVar5 = uVar4 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
              pcVar1 = pcVar11;
              pcVar11 = pcVar11 + 1;
              *pcVar1 = '\\';
            }
            if ((uVar4 & 1) == 0) break;
            pcVar1 = pcVar11;
            pcVar11 = pcVar11 + 1;
            *pcVar1 = '\"';
            pcVar9 = pcVar8;
          }
          else {
            for (; uVar4 != 0; uVar4 = uVar4 - 1) {
              pcVar1 = pcVar11;
              pcVar11 = pcVar11 + 1;
              *pcVar1 = '\\';
            }
          }
        }
        else {
          pcVar1 = pcVar11;
          pcVar11 = pcVar11 + 1;
          *pcVar1 = cVar2;
          pcVar9 = pcVar8;
        }
      }
      goto LAB_1048_0437;
    }
    if (cVar2 != '\\') {
      pcVar1 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar1 = cVar2;
      goto LAB_1048_0437;
    }
    uVar4 = 0;
    do {
      uVar4 = uVar4 + 1;
      pcVar1 = pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (*pcVar1 == '\\');
    if (*pcVar1 == '\"') {
      for (uVar5 = uVar4 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
        pcVar1 = pcVar11;
        pcVar11 = pcVar11 + 1;
        *pcVar1 = '\\';
      }
      pcVar9 = pcVar8;
      if ((uVar4 & 1) == 0) goto LAB_1048_0473;
      pcVar1 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar1 = '\"';
      goto LAB_1048_0437;
    }
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      pcVar1 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar1 = '\\';
    }
  } while( true );
}



void __cdecl16far copy_environment_excluding_c_file_info(void)

{
  int *piVar1;
  char *pcVar2;
  int *piVar3;
  char cVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  char *pcVar11;
  int *piVar12;
  undefined2 unaff_SS;
  bool bVar13;
  undefined4 u_dosEnv;
  
  u_dosEnv = GETDOSENVIRONMENT();
  iVar7 = (int)((ulong)u_dosEnv >> 0x10);
  if ((int)u_dosEnv != 0) {
    iVar7 = (int)u_dosEnv;
  }
  iVar8 = 0;
  pcVar11 = (char *)0x0;
  iVar6 = -1;
  if (iVar7 != 0) {
    cVar4 = *(char *)0x0;
    while (cVar4 != '\0') {
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar2 = pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (*pcVar2 != '\0');
      iVar8 = iVar8 + 1;
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      cVar4 = *pcVar2;
    }
  }
  pcVar11 = (char *)allocate_4k_block_or_exit();
  puVar5 = (undefined2 *)allocate_4k_block_or_exit();
  piVar9 = (int *)0x0;
  DAT_1050_0104 = puVar5;
  do {
    if (iVar8 == 0) {
      *puVar5 = 0;
      return;
    }
    bVar13 = *piVar9 == *(int *)s__C_FILE_INFO__1050_00a6;
    if (bVar13) {
      piVar12 = (int *)s__C_FILE_INFO__1050_00a6;
      iVar6 = 6;
      piVar10 = piVar9;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        piVar3 = piVar12;
        piVar12 = piVar12 + 1;
        piVar1 = piVar10;
        piVar10 = piVar10 + 1;
        bVar13 = *piVar1 == *piVar3;
      } while (bVar13);
      if (!bVar13) goto LAB_1048_0529;
    }
    else {
LAB_1048_0529:
      *puVar5 = pcVar11;
      puVar5 = puVar5 + 1;
    }
    do {
      piVar1 = piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
      iVar6 = *piVar1;
      pcVar2 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar2 = (char)iVar6;
    } while ((char)iVar6 != '\0');
    iVar8 = iVar8 + -1;
  } while( true );
}



int * __stdcall16far fatal_app_exit(int param_in_AX)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  char in_CL;
  int unaff_SI;
  int *piVar6;
  char *pcVar7;
  undefined2 unaff_CS;
  undefined2 uVar8;
  
  FUN_1048_02b4();
  FUN_1048_05c3();
                    // WARNING: Call to offcut address within same function
  pcVar3 = (char *)func_0x1048058c();
  if (pcVar3 != (char *)0x0) {
    iVar4 = 9;
    if (*pcVar3 == 'M') {
      iVar4 = 0xf;
    }
    pcVar3 = pcVar3 + iVar4;
    iVar4 = 0x22;
    pcVar7 = pcVar3;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar2 = pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar2 != '\r');
    in_CL = (char)iVar4;
    pcVar7[-1] = '\0';
  }
  uVar8 = 0;
  FATALAPPEXIT(unaff_CS,pcVar3,0x1050);
  uVar8 = FATALEXIT(0x1170,0xff,uVar8);
  *(char *)(unaff_SI + -0x6f28) = *(char *)(unaff_SI + -0x6f28) + in_CL;
  piVar6 = (int *)0x2f4;
  do {
    piVar1 = piVar6;
    piVar6 = piVar6 + 1;
    piVar5 = piVar6;
    if ((*piVar1 == param_in_AX) || (piVar5 = (int *)(*piVar1 + 1), piVar5 == (int *)0x0)) {
      return piVar5;
    }
    iVar4 = -1;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      piVar1 = piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
    } while ((char)*piVar1 != '\0');
  } while( true );
}



void __stdcall16far FUN_1048_05c3(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined2 unaff_ES;
  
  if (DAT_1050_0120 != 0) {
    pcVar2 = (char *)func_0x1048058c();
    if (pcVar2 != (char *)0x0) {
      iVar3 = -1;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar1 = pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (*pcVar1 != '\0');
      fatal_app_exit_14();
    }
  }
  return;
}



void __cdecl16near allocate_4k_block_or_exit(void)

{
  undefined2 uVar1;
  int in_AX;
  int iVar2;
  int in_CX;
  
  uVar1 = DAT_1050_011a;
  LOCK();
  DAT_1050_011a = 0x1000;
  UNLOCK();
  iVar2 = allocate_memory_safe(in_AX);
  DAT_1050_011a = uVar1;
  if (iVar2 != 0) {
    return;
  }
  fatal_app_exit(in_CX);
  return;
}



void __cdecl16far FUN_1048_0740(undefined2 param_1)

{
  DAT_1050_011c = param_1;
  DAT_1050_011e = 0;
  return;
}



uint __cdecl16far FUN_1048_0754(void)

{
  long lVar1;
  
  lVar1 = _2bit_multiply(DAT_1050_011c,DAT_1050_011e,0x43fd,3);
  DAT_1050_011e = (uint)((ulong)(lVar1 + 0x269ec3) >> 0x10);
  DAT_1050_011c = (int)(lVar1 + 0x269ec3);
  return DAT_1050_011e & 0x7fff;
}



undefined4 __stdcall16far FUN_1048_0784(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulong)param_2 % (ulong)param_3 << 0x10 | (ulong)param_1) / (ulong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0xf;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0xf;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT22(uVar7,uVar3) / (ulong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulong)param_3 * (uVar1 & 0xffff);
    uVar3 = (uint)((ulong)lVar2 >> 0x10);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY2(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT22(uVar3,iVar4);
}



long __stdcall16far _2bit_multiply(uint a_lo,int a_hi,uint b_lo,int b_hi)

{
  if (b_hi == 0 && a_hi == 0) {
    return (ulong)a_lo * (ulong)b_lo;
  }
  return CONCAT22((int)((ulong)a_lo * (ulong)b_lo >> 0x10) + a_hi * b_lo + a_lo * b_hi,
                  (int)((ulong)a_lo * (ulong)b_lo));
}



undefined4 __stdcall16far FUN_1048_0850(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  bVar13 = (int)param_2 < 0;
  if (bVar13) {
    bVar12 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar12 - param_2;
  }
  uVar11 = (uint)bVar13;
  if ((int)param_4 < 0) {
    bVar13 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar13 - param_4;
  }
  uVar3 = param_1;
  uVar4 = param_3;
  uVar8 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    iVar5 = (int)(((ulong)param_2 % (ulong)param_3 << 0x10 | (ulong)param_1) % (ulong)param_3);
    iVar6 = 0;
    if ((int)(uVar11 - 1) < 0) goto LAB_1048_08ea;
  }
  else {
    do {
      uVar10 = uVar9 >> 1;
      uVar4 = uVar4 >> 1 | (uint)((uVar9 & 1) != 0) << 0xf;
      uVar7 = uVar8 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar8 & 1) != 0) << 0xf;
      uVar8 = uVar7;
      uVar9 = uVar10;
    } while (uVar10 != 0);
    uVar1 = CONCAT22(uVar7,uVar3) / (ulong)uVar4;
    uVar3 = (int)uVar1 * param_4;
    lVar2 = (uVar1 & 0xffff) * (ulong)param_3;
    uVar8 = (uint)((ulong)lVar2 >> 0x10);
    uVar4 = (uint)lVar2;
    uVar9 = uVar8 + uVar3;
    if (((CARRY2(uVar8,uVar3)) || (param_2 < uVar9)) || ((param_2 <= uVar9 && (param_1 < uVar4)))) {
      bVar13 = uVar4 < param_3;
      uVar4 = uVar4 - param_3;
      uVar9 = (uVar9 - param_4) - (uint)bVar13;
    }
    iVar5 = uVar4 - param_1;
    iVar6 = (uVar9 - param_2) - (uint)(uVar4 < param_1);
    if (-1 < (int)(uVar11 - 1)) goto LAB_1048_08ea;
  }
  bVar13 = iVar5 != 0;
  iVar5 = -iVar5;
  iVar6 = -(uint)bVar13 - iVar6;
LAB_1048_08ea:
  return CONCAT22(iVar6,iVar5);
}



void __cdecl16far FUN_1048_08f0(void)

{
  uint in_CX;
  uint uVar1;
  
  for (uVar1 = in_CX & 0xff; uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}



void __cdecl16near noop(void)

{
  return;
}



void fatal_app_exit_14(void)

{
  fatal_app_exit(0x14);
  return;
}



undefined2 __cdecl16far allocate_memory_safe(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar3 = 0xffff;
  LOCKSEGMENT();
  uVar2 = 0x20;
  if (param_1 == 0) {
    param_1 = 1;
  }
  uVar1 = LOCALALLOC(0x1170,param_1);
  UNLOCKSEGMENT(0x1170,0xffff,uVar2,uVar3);
  return uVar1;
}



byte * __cdecl16far FUN_1048_09be(int param_1,byte *param_2,uint param_3)

{
  ulong uVar1;
  byte bVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  char cVar3;
  
  uVar5 = 0;
  pbVar8 = param_2;
  pbVar7 = param_2;
  if ((param_3 == 10) && (uVar5 = param_1 >> 0xf, (int)uVar5 < 0)) {
    pbVar8 = param_2 + 1;
    *param_2 = 0x2d;
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    uVar5 = -(uVar5 + bVar10);
    pbVar7 = pbVar8;
  }
  do {
    uVar6 = 0;
    uVar4 = uVar5;
    if (uVar5 != 0) {
      uVar4 = uVar5 / param_3;
      uVar6 = uVar5 % param_3;
    }
    uVar1 = CONCAT22(uVar6,param_1);
    param_1 = (int)(uVar1 / param_3);
    cVar3 = (char)(uVar1 % (ulong)param_3);
    bVar2 = cVar3 + 0x30;
    if (0x39 < bVar2) {
      bVar2 = cVar3 + 0x57;
    }
    pbVar9 = pbVar8 + 1;
    *pbVar8 = bVar2;
    uVar5 = uVar4;
    pbVar8 = pbVar9;
  } while (uVar4 != 0 || param_1 != 0);
  *pbVar9 = 0;
  do {
    pbVar9 = pbVar9 + -1;
    LOCK();
    bVar2 = *pbVar9;
    *pbVar9 = *pbVar7;
    UNLOCK();
    *pbVar7 = bVar2;
    pbVar8 = pbVar7 + 2;
    pbVar7 = pbVar7 + 1;
  } while (pbVar8 < pbVar9);
  return param_2;
}



byte * __cdecl16far FUN_1048_09da(int param_1,uint param_2,byte *param_3,uint param_4)

{
  ulong uVar1;
  byte bVar2;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  char cVar3;
  
  pbVar7 = param_3;
  pbVar6 = param_3;
  if ((param_4 == 10) && ((int)param_2 < 0)) {
    pbVar7 = param_3 + 1;
    *param_3 = 0x2d;
    bVar9 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(param_2 + bVar9);
    pbVar6 = pbVar7;
  }
  do {
    uVar5 = 0;
    uVar4 = param_2;
    if (param_2 != 0) {
      uVar4 = param_2 / param_4;
      uVar5 = param_2 % param_4;
    }
    uVar1 = CONCAT22(uVar5,param_1);
    param_1 = (int)(uVar1 / param_4);
    cVar3 = (char)(uVar1 % (ulong)param_4);
    bVar2 = cVar3 + 0x30;
    if (0x39 < bVar2) {
      bVar2 = cVar3 + 0x57;
    }
    pbVar8 = pbVar7 + 1;
    *pbVar7 = bVar2;
    param_2 = uVar4;
    pbVar7 = pbVar8;
  } while (uVar4 != 0 || param_1 != 0);
  *pbVar8 = 0;
  do {
    pbVar8 = pbVar8 + -1;
    LOCK();
    bVar2 = *pbVar8;
    *pbVar8 = *pbVar6;
    UNLOCK();
    *pbVar6 = bVar2;
    pbVar7 = pbVar6 + 2;
    pbVar6 = pbVar6 + 1;
  } while (pbVar7 < pbVar8);
  return param_3;
}
