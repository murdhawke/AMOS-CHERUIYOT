/*
 * monitor.h
 *
 *  Created on: Mar 16, 2016
 *      Author: AAmos Cheruiyot
 */

#ifndef MONITOR_H_
#define MONITOR_H_
#include<iostream>
#include<systemc>

using namespace std;

SC_MODULE(monitor){
sc_in<bool> m_A, m_B,m_output1, m_output2, m_output3, m_output4;

SC_CTOR(monitor){
	SC_METHOD(monita);
	sensitive<<m_output1<<m_output2<<m_output3<<m_output4;
	dont_initialize();
}

void monita(void){
cout<<"at "<<sc_time_stamp()<<" input is: "<<m_A<<" and "<<m_B<<" outputs are: "<<m_output1<<", "<<m_output2<<", "<<m_output3<<" and "<<m_output4<<endl;
}
};
#endif /* MONITOR_H_ */
