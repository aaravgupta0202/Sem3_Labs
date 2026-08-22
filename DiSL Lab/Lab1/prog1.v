module prog1(a, b, c, d, f);
	input a, b, c, d;
	output f;

	//Gate level primitives
	and (h, a, b);
	nor (i, h, c);
	or (j, h, c);
	and (k, i, d);
	or (l, j, d);
	and (f, k, l);

	//Continuous assignment statement
	//assign f = ((~((a & b) | (c))) & (d)) & (((a & b) | (c)) | (d));
endmodule