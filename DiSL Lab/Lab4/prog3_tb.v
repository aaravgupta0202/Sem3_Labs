`timescale 1ns/1ns
`include "prog3.v"//Name of the Verilog file
module prog3_tb();
reg [1:0] A, B;
wire [3:0] P;
prog3 p3(A, B, P); //Instantiation of the module
initial
begin
    $dumpfile("prog3_tb.vcd");
    $dumpvars(0, prog3_tb);
    A=4'b00; B=4'b01;
    #10
    A=4'b11; B=4'b01;
    #10
    A=4'b01; B=4'b10;
    #10
    A=4'b10; B=4'b11;
    #10
    $display("Test complete");
end
endmodule