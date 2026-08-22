`include "prog1.v"

module prog2(A, B, Mode, S, Cout);
	input [3:0] A, B;
	input Mode;
	output [3:0] S;
	output Cout;

	wire [3:0] B_xor;
	wire c1, c2, c3;

	assign B_xor[0] = B[0] ^ Mode;
	assign B_xor[1] = B[1] ^ Mode;
	assign B_xor[2] = B[2] ^ Mode;
	assign B_xor[3] = B[3] ^ Mode;

	full_adder FA0 (.A(A[0]), .B(B_xor[0]), .Cin(Mode), .Sum(S[0]), .Cout(c1));
	full_adder FA1 (.A(A[1]), .B(B_xor[1]), .Cin(c1), .Sum(S[1]), .Cout(c2));
	full_adder FA2 (.A(A[2]), .B(B_xor[2]), .Cin(c2), .Sum(S[2]), .Cout(c3));
	full_adder FA3 (.A(A[3]), .B(B_xor[3]), .Cin(c3), .Sum(S[3]), .Cout(Cout));
endmodule