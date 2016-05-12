#ifndef _util_H_
#define _util_H_
#define getbit(reg,bitno) ((reg>>bitno) &0x01)
#define clrbit(reg,bitno) reg=reg&(~(0x01<<bitno))
#define setbit(reg,bitno) reg=reg|(0x01<<bitno)
#define togglebit(reg,bitno) reg=reg^(0x01<<bitno)
#define assignbit(reg,bitno,val) reg=(val<<bitno) | (reg & (~(0x01<<bitno)))

#define setreg(reg) reg=0xff
#define clrreg(reg) reg=reg&0x00 
#define togglereg(reg) reg=reg^0xff
#define assignreg(reg,val) reg=val
#define getreg(reg) reg

#define set_low_nib(reg) reg=(0x0f | reg)
#define clr_low_nib(reg) reg=(reg & 0xf0) 
#define toggle_low_nib(reg) reg=(reg^0x0f)
#define assign_low_nib(reg,val) reg=((val&0x0f)|(reg&0xf0))
#define get_low_nib(reg) (0x0f & reg)

#define set_high_nib(reg) reg=(0xf0 | reg)
#define clr_high_nib(reg) reg=(reg & 0x0f) 
#define toggle_high_nib(reg) reg=(reg^0xf0)
#define assign_high_nib(reg,val) reg=((val<<4)|(reg&0x0f))
#define get_high_nib(reg) (0xf0 & reg)
#endif
