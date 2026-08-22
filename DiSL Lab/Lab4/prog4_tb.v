`timescale 1ns/1ns
`include "prog4.v"

module prog4_tb();
reg [3:0] A, B;
wire [3:0] S;
wire Cout;

prog4 p4(A, B, S, Cout);

initial begin
    $dumpfile("prog4_tb.vcd");
    $dumpvars(0, prog4_tb);

    // Test 1: 3 + 4 = 7 (S = 7, Cout = 0)
    A = 4'd3; B = 4'd4; #20;

    // Test 2: 5 + 7 = 12 -> Corrected: 12 + 6 = 18 (S = 2, Cout = 1)
    A = 4'd5; B = 4'd7; #20;

    // Test 3: 8 + 9 = 17 -> Corrected: 17 + 6 = 23 (S = 7, Cout = 1)
    A = 4'd8; B = 4'd9; #20;

    // Test 4: 9 + 0 = 9 (S = 9, Cout = 0)
    A = 4'd9; B = 4'd0; #20;

    $display("Test complete");
end
endmodule