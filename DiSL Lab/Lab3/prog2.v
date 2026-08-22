module prog2(a, b, c, d, f);
	input a, b, c, d;
	output f;

	//Gate level primitives
	nor(p, a, a);
	nor(q, b, b);
	nor(r, c, c);
	nor(s, d, d);
	nor(x, q, d);
	nor(y, p, q);
	nor(z, r, s);
	nor(f, x, y, z);
endmodule