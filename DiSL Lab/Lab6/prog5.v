module encoder16to4(A,Y);

input [15:0] A;
output reg [3:0] Y;
integer i;

always @(*)
begin
    Y=4'b0000;

    for(i=0;i<16;i=i+1)
        if(A[i])
            Y=i;
end

endmodule
