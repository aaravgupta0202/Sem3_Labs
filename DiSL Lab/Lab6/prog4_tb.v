`timescale 1ns/1ns
`include "prog4.v"

module prog4_tb();

reg [3:0] A;
wire [1:0] Y;

encoder4to2 ex1(A,Y);

initial
begin
$dumpfile("prog4_tb.vcd");
$dumpvars(0,prog4_tb);

A=4'b0001;
#20;
A=4'b0010;
#20;
A=4'b0100;
#20;
A=4'b1000;
#20;
A=4'b1010;
#20;
A=4'b1111;
#20;

$display("Test Complete");
end

endmodule
