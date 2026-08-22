`timescale 1ns/1ns
`include "prog1.v"//Name of the Verilog file
module prog1_tb();
reg A, B, Cin;
wire HA_Sum, HA_Carry;
wire FA_Sum, FA_Cout;

half_adder HA(A, B, HA_Sum, HA_Carry);
full_adder FA(A, B, Cin, FA_Sum, FA_Cout);
initial
begin
    $dumpfile("prog1_tb.vcd");
    $dumpvars(0, prog1_tb);
    A=1'b0; B=1'b0; Cin=1'b0;
    #10
    A=1'b0; B=1'b0; Cin=1'b1;
    #10
    A=1'b0; B=1'b1; Cin=1'b0;
    #10
    A=1'b0; B=1'b1; Cin=1'b1;
    #10
    A=1'b1; B=1'b0; Cin=1'b0;
    #10
    A=1'b1; B=1'b0; Cin=1'b1;
    #10
    A=1'b1; B=1'b1; Cin=1'b0;
    #10
    A=1'b1; B=1'b1; Cin=1'b1;
    #10
    $display("Test complete");
end
endmodule
