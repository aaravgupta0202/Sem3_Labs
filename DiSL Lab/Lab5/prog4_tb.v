`timescale 1ns/1ns
`include "prog4_16.v"
module prog4_tb();
reg [15:0] w;
reg s0,s1,s2,s3;
wire f;
mux16to1 ex4(
w[0],w[1],w[2],w[3],
w[4],w[5],w[6],w[7],
w[8],w[9],w[10],w[11],
w[12],w[13],w[14],w[15],
s0,s1,s2,s3,f);
initial
begin
$dumpfile("prog4_tb.vcd");
$dumpvars(0,prog4_tb);
w=16'b1010101010101010;
s3=0;s2=0;s1=0;s0=0;
#20;
s3=0;s2=0;s1=0;s0=1;
#20;
s3=0;s2=1;s1=0;s0=0;
#20;
s3=0;s2=1;s1=1;s0=1;
#20;
s3=1;s2=0;s1=0;s0=0;
#20;
s3=1;s2=1;s1=1;s0=1;
#20;
$display("Test Complete");
end
endmodule