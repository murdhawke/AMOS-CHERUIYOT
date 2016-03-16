/*
 * decoder_2by4.h
 *
 *  Created on: Mar 16, 2016
 *      Author: Amos Cheruiyot
 */
#include"decoder_2by4.h"
#include"driver.h"
#include"monitor.h"
#include<systemc.h>

int sc_main(int argc, char *argv[]){
//some signals for interconnections
sc_signal<bool> inp1, inp2, out1, out2, out3, out4; //increased the number of inputs and outputs.
//module instances
decoder dec("decoder_instance");
driver dr("driver");
monitor mn("monitor");
//interconnections between modules
dr.d_A(inp1);
dec.A(inp1);
mn.m_A(inp1);

dr.d_B(inp2);
dec.B(inp2);
mn.m_B(inp2);

dec.output1(out1);
mn.m_output1(out1);

dec.output2(out2);
mn.m_output2(out2);

dec.output3(out3);
mn.m_output3(out3);

dec.output4(out4);
mn.m_output4(out4);

//create a trace file with nanosecond resolution
sc_trace_file *tf;
tf = sc_create_vcd_trace_file("timing_diagram");
tf->set_time_unit(1, SC_NS);
//trace the signals interconnecting modules
// signals to be traced
sc_trace(tf, inp1, "inp1");
sc_trace(tf, inp2, "inp2");
sc_trace(tf, out1, "out1");
sc_trace(tf, out2, "out2");
sc_trace(tf, out3, "out3");
sc_trace(tf, out4, "out4");

//run a simulation for 20 systemc nano-seconds
if( !sc_pending_activity() )
sc_start(20,SC_NS);
//close the trace file
sc_close_vcd_trace_file(tf);
return 0;
}



