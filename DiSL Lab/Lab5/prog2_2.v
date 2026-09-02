module mux2to1(w0, w1, s, f);

input w0, w1, s;
output f;
reg f;

always @(w0 or w1 or s)
begin
    if(s == 0)
        f = w0;
    else
        f = w1;
end

endmodule
