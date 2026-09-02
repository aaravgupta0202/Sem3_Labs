module comparator4bit(A, B, gt, eq, lt);

input [3:0] A, B;
output gt, eq, lt;

assign gt = (A > B);
assign eq = (A == B);
assign lt = (A < B);

endmodule
