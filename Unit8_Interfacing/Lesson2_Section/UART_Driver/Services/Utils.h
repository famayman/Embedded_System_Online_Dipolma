/*
 * Utils.h
 *
 * Created: 8/8/2022 4:09:39 PM
 *  Author: Fam Ayman
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#define set(Reg,Bit)    (Reg |= (1<<Bit))
#define Reset(Reg,Bit)  (Reg &= ~(1<<Bit))
#define Toggle(Reg,Bit) (Reg ^= (1<<Bit))
#define Read(Reg,Bit)   ( (Reg>>Bit) & 1)




#endif /* UTILS_H_ */