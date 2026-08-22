`include "prog2.v"

module prog4(A, B, S, Cout);
input [3:0] A, B;
output [3:0] S;
output Cout;

wire [3:0] Z;
wire [3:0] correction;
wire K, dummy_cout;

prog2 add1 (.A(A), .B(B), .Mode(1'b0), .S(Z), .Cout(K));

assign Cout = K | (Z[3] & Z[2]) | (Z[3] & Z[1]);
assign correction = {1'b0, Cout, Cout, 1'b0};

prog2 add2 (.A(Z), .B(correction), .Mode(1'b0), .S(S), .Cout(dummy_cout));

endmodule