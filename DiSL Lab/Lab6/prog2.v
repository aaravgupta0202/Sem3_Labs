module decoder3to8(A,en,Y);

input [2:0] A;
input en;
output reg [7:0] Y;
integer i;

always @(*)
begin
    Y=8'b00000000;

    if(en)
        for(i=0;i<8;i=i+1)
            if(A==i) Y[i]=1'b1;
end

endmodule


module decoder4to16(A,en,Y);

input [3:0] A;
input en;
output [15:0] Y;

decoder3to8 d1(A[2:0],en&~A[3],Y[7:0]);
decoder3to8 d2(A[2:0],en&A[3],Y[15:8]);

endmodule
