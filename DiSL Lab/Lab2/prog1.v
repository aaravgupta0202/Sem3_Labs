module prog1(a, b, c, d, f);
	input a, b, c, d;
	output f;

	//Gate level primitives
	not (h, a);
	not (i, b);
	not (j, c);
	not (k, d);
	and (p, b, j, k);
	and (q, h, b);
	and (r, c, d);
	and (s, i, c);
	or (f, p, q, r, s);
endmodule