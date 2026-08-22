`timescale 1ns/1ns
`include "prog3.v"//Name of the Verilog file
module prog3_tb();
reg a, b, c;//Input
wire f1, f2;//Output
prog3 p3(a, b, c, f1, f2); //Instantiation of the module
initial
begin
    $dumpfile("prog3_tb.vcd");
    $dumpvars(0, prog3_tb);
    a=1'b0; b=1'b0; c=1'b0;
    #10
    a=1'b0; b=1'b0; c=1'b1;
    #10
    a=1'b0; b=1'b1; c=1'b0;
    #10
    a=1'b0; b=1'b1; c=1'b1;
    #10
    a=1'b1; b=1'b0; c=1'b0;
    #10
    a=1'b1; b=1'b0; c=1'b1;
    #10
    a=1'b1; b=1'b1; c=1'b0;
    #10
    a=1'b1; b=1'b1; c=1'b1;
    #10
    $display("Test complete");
end
endmodule
