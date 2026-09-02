`include "prog2_2.v"

module mux4to1(w0,w1,w2,w3,s0,s1,f);

input w0,w1,w2,w3,s0,s1;
output f;
wire f1,f2;

mux2to1 m1(w0,w1,s0,f1);
mux2to1 m2(w2,w3,s0,f2);
mux2to1 m3(f1,f2,s1,f);

endmodule
