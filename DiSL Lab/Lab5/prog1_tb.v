`timescale 1ns/1ns
`include "prog1.v"
module prog1_tb();
reg [3:0] A, B;
wire gt, eq, lt;
comparator4bit ex1(A, B, gt, eq, lt);
initial
begin
$dumpfile("prog1_tb.vcd");
$dumpvars(0, prog1_tb);
A=4'b0000; B=4'b0000;
#20;
A=4'b0101; B=4'b0011;
#20;
A=4'b0010; B=4'b0110;
#20;
$display("Test Complete");
end
endmodule
