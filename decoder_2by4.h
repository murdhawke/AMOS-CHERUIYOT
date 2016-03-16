/*
 * decoder_2by4.h
 *
 *  Created on: Mar 16, 2016
 *      Author: Amos Cheruiyot
 */

#ifndef DECODER_2BY4_H_
#define DECODER_2BY4_H_
#include<systemc.h>

SC_MODULE(decoder){
//input and output ports
sc_in<bool> A,B;
sc_out<bool> output1,output2,output3,output4;
//constructor: where the processes are bound to simulation kernel
SC_CTOR(decoder){
	SC_METHOD(decode);
	sensitive<<A<<B;
	//dont_initialize();
}

~decoder(){
//delete stuff :P
}

void decode(void){
	if (A==0 && B==0)
	{
		output1=1;
		output2=0;
		output3=0;
		output4=0;
	}
	else if (A==0 && B==1)
	{
		output1=0;
		output2=1;
		output3=0;
		output4=0;
	}
	else if (A==1 && B==0)
	{
		output1=0;
		output2=0;
		output3=1;
		output4=0;
	}
	else if (A==1 && B==1)
	{
		output1=0;
		output2=0;
		output3=0;
		output4=1;
	}


}
};




#endif /* DECODER_2BY4_H_ */
