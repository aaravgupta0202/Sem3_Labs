module prog4(a, b, c, d, f);
	input a, b, c, d;
	output f;
	nand(A, a, a);
	nand(B, b, b);
	nand(D, d, d);
	nand(p, A, B);
	nand(q, B, D);
	nand(r, c, d);
	nand(f, p, q, r);
endmodule