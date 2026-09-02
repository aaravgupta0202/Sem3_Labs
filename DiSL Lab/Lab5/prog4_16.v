`include "prog4_8.v"
`include "prog2_2.v"

module mux16to1(w0,w1,w2,w3,w4,w5,w6,w7,
w8,w9,w10,w11,w12,w13,w14,w15,
s0,s1,s2,s3,f);

input w0,w1,w2,w3,w4,w5,w6,w7;
input w8,w9,w10,w11,w12,w13,w14,w15;
input s0,s1,s2,s3;
output f;

wire f0,f1;

mux8to1 m1(w0,w1,w2,w3,w4,w5,w6,w7,s0,s1,s2,f0);
mux8to1 m2(w8,w9,w10,w11,w12,w13,w14,w15,s0,s1,s2,f1);

mux2to1 m3(f0,f1,s3,f);

endmodule
