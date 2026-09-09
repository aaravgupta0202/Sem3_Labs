`timescale 1ns/1ns
`include "prog5.v"

module prog5_tb();

reg [15:0] A;
wire [3:0] Y;

encoder16to4 ex1(A,Y);

initial
begin
$dumpfile("prog5_tb.vcd");
$dumpvars(0,prog5_tb);

A=16'b0000000000000001;
#20;
A=16'b0000000000000010;
#20;
A=16'b0000000000000100;
#20;
A=16'b0000000010000000;
#20;
A=16'b0001000000000000;
#20;
A=16'b1000000000000000;
#20;
A=16'b1011000000000101;
#20;

$display("Test Complete");
end

endmodule
