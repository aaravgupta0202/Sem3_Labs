`timescale 1ns/1ns
`include "prog2.v"//Name of the Verilog file
module prog2_tb();
reg [3:0] A, B;
reg Mode;//Input
wire [3:0] S;
wire Cout;//Output
prog2 p2(A, B, Mode, S, Cout); //Instantiation of the module
initial
begin
    $dumpfile("prog2_tb.vcd");
    $dumpvars(0, prog2_tb);
    Mode=1'b0; A=4'b0010; B=4'b1001;
    #10
    Mode=1'b0; A=4'b1011; B=4'b0001;
    #10
    Mode=1'b1; A=4'b1110; B=4'b0001;
    #10
    Mode=1'b1; A=4'b1010; B=4'b0101;
    #10
    $display("Test complete");
end
endmodule
