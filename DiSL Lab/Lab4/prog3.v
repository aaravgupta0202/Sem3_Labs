`include "prog1.v"

module prog3(A, B, P);
	input [1:0] A, B;
	output [3:0] P;

	wire p0, p1, p2, p3;
	wire c1;

	assign p0 = A[0] & B[0];
	assign p1 = A[1] & B[0];
	assign p2 = A[0] & B[1];
	assign p3 = A[1] & B[1];

	assign P[0] = p0;

	half_adder HA1 (.A(p1), .B(p2), .Sum(P[1]), .Carry(c1));
	half_adder HA2 (.A(p3), .B(c1), .Sum(P[2]), .Carry(P[3]));
endmodule