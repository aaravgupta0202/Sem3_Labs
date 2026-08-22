module prog3(a, b, c, d, f);
	input a, b, c, d;
	output f;
	assign f = ~(~(d|d)|~(~(a|a)|~(c|c)));

	//Gate Level
	//nor(x, a, a);
	//nor(y, c, c);
	//nor(z, d, d);
	//nor(p, x, y);
	//nor(f, z, p);
endmodule