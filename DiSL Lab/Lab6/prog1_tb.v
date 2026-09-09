`timescale 1ns/1ns
`include "prog1.v"

module prog1_tb();

reg [2:0] A;
reg en;
wire [7:0] Y;

decoder3to8 ex1(A,en,Y);

initial
begin
$dumpfile("prog1_tb.vcd");
$dumpvars(0,prog1_tb);

en=1'b1;
A=3'b000;
#20;
A=3'b001;
#20;
A=3'b010;
#20;
A=3'b011;
#20;
A=3'b100;
#20;
A=3'b101;
#20;
A=3'b110;
#20;
A=3'b111;
#20;

$display("Test Complete");
end

endmodule
