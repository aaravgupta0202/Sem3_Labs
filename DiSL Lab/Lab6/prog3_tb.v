`timescale 1ns/1ns
`include "prog3.v"

module prog3_tb();

reg [3:0] A;
reg en;
wire [15:0] Y;

decoder4to16 ex1(A,en,Y);

initial
begin
$dumpfile("prog3_tb.vcd");
$dumpvars(0,prog3_tb);

en=1'b1;

A=4'b0000;
#20;
A=4'b0001;
#20;
A=4'b0010;
#20;
A=4'b0011;
#20;
A=4'b0100;
#20;
A=4'b0101;
#20;
A=4'b0110;
#20;
A=4'b0111;
#20;
A=4'b1000;
#20;
A=4'b1001;
#20;
A=4'b1010;
#20;
A=4'b1011;
#20;
A=4'b1100;
#20;
A=4'b1101;
#20;
A=4'b1110;
#20;
A=4'b1111;
#20;

$display("Test Complete");
end

endmodule
