`timescale 1ns/1ns
`include "prog5.v"//Name of the Verilog file
module prog5_tb();
reg a, b, c, d;//Input
wire f;//Output
prog5 p5(a, b, c, d, f); //Instantiation of the module
initial
begin
    $dumpfile("prog5_tb.vcd");
    $dumpvars(0, prog5_tb);
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
