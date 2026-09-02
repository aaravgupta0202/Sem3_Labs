`timescale 1ns/1ns
`include "prog2_4.v"
module prog2_tb();
reg w0,w1,w2,w3,s0,s1;
wire f;
mux4to1 ex2(w0,w1,w2,w3,s0,s1,f);
initial
begin
$dumpfile("prog2_tb.vcd");
$dumpvars(0,prog2_tb);
w0=0;w1=1;w2=0;w3=1;
s1=0;s0=0;
#20;
s1=0;s0=1;
#20;
s1=1;s0=0;
#20;
s1=1;s0=1;
#20;
$display("test Complete");
end
endmodule
