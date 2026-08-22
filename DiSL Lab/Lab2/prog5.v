module prog5(a, b, c, d, f);
	input a, b, c, d;
	output f;
	assign f = a&b&d | a&b&c | b&c&d | a&c&d;

	//Gate Level Assignment
	// and (p, a, b, d);
	// and (q, a, b, c);
	// and (r, b, c, d);
	// and (s, a, c, d);
	// or (f, p, q, r, s);
endmodule