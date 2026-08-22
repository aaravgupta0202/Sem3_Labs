`timescale 1ns/1ns
`include "prog2.v"//Name of the Verilog file
module prog2_tb();
reg a, b, c, d;//Input
wire f, g;//Output
prog2 p2(a, b, c, d, f, g); //Instantiation of the module
initial
begin
    $dumpfile("prog2_tb.vcd");
    $dumpvars(0, prog2_tb);
    a=1'b0; b=1'b0; c=1'b0; d=1'b0;
    #10
    a=1'b0; b=1'b0; c=1'b0; d=1'b1;
    #10
    a=1'b0; b=1'b0; c=1'b1; d=1'b0;
    #10
    a=1'b0; b=1'b0; c=1'b1; d=1'b1;
    #10
    a=1'b0; b=1'b1; c=1'b0; d=1'b0;
    #10
    a=1'b0; b=1'b1; c=1'b0; d=1'b1;
    #10
    a=1'b0; b=1'b1; c=1'b1; d=1'b0;
    #10
    a=1'b0; b=1'b1; c=1'b1; d=1'b1;
    #10
    a=1'b1; b=1'b0; c=1'b0; d=1'b0;
    #10
    a=1'b1; b=1'b0; c=1'b0; d=1'b1;
    #10
    a=1'b1; b=1'b0; c=1'b1; d=1'b0;
    #10
    a=1'b1; b=1'b0; c=1'b1; d=1'b1;
    #10
    a=1'b1; b=1'b1; c=1'b0; d=1'b0;
    #10
    a=1'b1; b=1'b1; c=1'b0; d=1'b1;
    #10
    a=1'b1; b=1'b1; c=1'b1; d=1'b0;
    #10
    a=1'b1; b=1'b1; c=1'b1; d=1'b1;
    #10
    $display("Test complete");
end
endmodule
