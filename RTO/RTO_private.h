/*
 * RTO_private.h
 *
 *  Created on: Apr 20, 2016
 *      Author: m.mamdooh
 */

#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_


typedef u8 TCBT ;


#define ISR(vector) 	\
		void vector(void) __attribute__ ((signal,used,externally_visible)) ;\
		void vector(void)

#define RTO_u8_1   1
#define RTO_u8_2   2
#define RTO_u8_3   3
#define RTO_u8_4   4
#define RTO_u8_5   5
#define RTO_u8_6   6
#define RTO_u8_7   7
#define RTO_u8_8   8
#define RTO_u8_9   9



#endif /* RTO_PRIVATE_H_ */
