module prog2(a, b, c, d, f, g);

	//Gate level primitives
	input a, b, c, d;
	output f, g;
	nand (h, a, b);
	xor (f, h, c, d);
	nor (g, b, c, d);

	//Continuous assignment statement
	//assign f = (a ~& b) ^ (d) ^ (c);
	//assign g = (b ~| c ~| d);
endmodule