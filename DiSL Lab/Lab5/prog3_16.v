`include "prog3_4.v"

module mux16to1(w0,w1,w2,w3,w4,w5,w6,w7,
w8,w9,w10,w11,w12,w13,w14,w15,
s0,s1,s2,s3,f);

input w0,w1,w2,w3,w4,w5,w6,w7;
input w8,w9,w10,w11,w12,w13,w14,w15;
input s0,s1,s2,s3;
output f;

wire f0,f1,f2,f3;

mux4to1 m1(w0,w1,w2,w3,s0,s1,f0);
mux4to1 m2(w4,w5,w6,w7,s0,s1,f1);
mux4to1 m3(w8,w9,w10,w11,s0,s1,f2);
mux4to1 m4(w12,w13,w14,w15,s0,s1,f3);

mux4to1 m5(f0,f1,f2,f3,s2,s3,f);

endmodule
