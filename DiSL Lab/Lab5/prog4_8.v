module mux8to1(w0,w1,w2,w3,w4,w5,w6,w7,s0,s1,s2,f);

input w0,w1,w2,w3,w4,w5,w6,w7;
input s0,s1,s2;
output f;
reg f;

always @(w0 or w1 or w2 or w3 or w4 or w5 or w6 or w7 or s0 or s1 or s2)
begin
    case({s2,s1,s0})
        3'b000: f=w0;
        3'b001: f=w1;
        3'b010: f=w2;
        3'b011: f=w3;
        3'b100: f=w4;
        3'b101: f=w5;
        3'b110: f=w6;
        3'b111: f=w7;
    endcase
end

endmodule
