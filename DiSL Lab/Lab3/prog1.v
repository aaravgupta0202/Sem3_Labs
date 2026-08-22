module prog1(a, b, c, d, f);
	input a, b, c, d;
	output f;

	//Gate level primitives
	nand(p, b, b);
	nand(q, d, d);
	nand(x, a, p);
	nand(y, c, q);
	nand(z, x, y);
	nand(f, z, z);
endmodule