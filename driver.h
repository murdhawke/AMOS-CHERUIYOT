/*
 * driver.h
 *
 *  Created on: Mar 16, 2016
 *      Author: Amos Cheruiyot
 */

#ifndef DRIVER_H_
#define DRIVER_H_

#include<systemc>

SC_MODULE(driver){
sc_out<bool> d_A;
sc_out<bool> d_B;


SC_CTOR(driver){
	SC_THREAD(drive);
}

void drive(void){
	while(1){

		d_A=0; d_B=0;	
		wait(5, SC_NS);
		d_B=1;	
		wait(5, SC_NS);
		d_A=1; d_B=0;	
		wait(5, SC_NS);
		d_B=1;		
		wait(5, SC_NS);
	}
}
};
#endif /* DRIVER_H_ */
