/****************************************************/
/*********   Author    : Mariz Mamdouh   ************/
/*********   Date      : 28 Aug 2023     ************/
/*********   Version   : 0.1             ************/
/*********   File name : STD_TYPES.h     ************/
/****************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char     u8;
typedef unsigned short    u16;
typedef unsigned int      u32;
typedef unsigned long     u64;

typedef signed char       s8;
typedef signed short      s16;
typedef signed int        s32;
typedef signed long       s64;

typedef float             f32;
typedef double            f64;
typedef float             f96;

typedef u8                Std_ReturnType;

typedef struct bits{
        u8 Bit0:1;
        u8 Bit1:1;
        u8 Bit2:1;
        u8 Bit3:1;
        u8 Bit4:1;
        u8 Bit5:1;
        u8 Bit6:1;
        u8 Bit7:1;
        u8 Bit8:1;
        u8 Bit9:1;
        u8 Bit10:1;
        u8 Bit11:1;
        u8 Bit12:1;
        u8 Bit13:1;
        u8 Bit14:1;
        u8 Bit15:1;
        u8 Bit16:1;
        u8 Bit17:1;
        u8 Bit18:1;
        u8 Bit19:1;
        u8 Bit20:1;
        u8 Bit21:1;
        u8 Bit22:1;
        u8 Bit23:1;
        u8 Bit24:1;
        u8 Bit25:1;
        u8 Bit26:1;
        u8 Bit27:1;
        u8 Bit28:1;
        u8 Bit29:1;
        u8 Bit30:1;
        u8 Bit31:1;
}Bits;

#define E_OK              ((Std_ReturnType)1)
#define E_NOT_OK          ((Std_ReturnType)0)

#define NULL              ((void*)0x0)

#endif /*STD_TYPES_H*/
