module prog2(a, b, c, d, f);
	input a, b, c, d;
	output f;

	//Gate level primitives
	not (h, b);
	not (i, c);
	not (j, d);
	and (p, b, i, j);
	and (q, h, c);
	and (r, h, d);
	or (f, p, q, r);
endmodule