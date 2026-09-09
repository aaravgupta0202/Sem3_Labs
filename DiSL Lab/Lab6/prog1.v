module decoder2to4(A,en,Y);

input [1:0] A;
input en;
output reg [3:0] Y;

always @(*)
begin
    if(en)
    begin
        if(A==2'b00) Y=4'b0001;
        else if(A==2'b01) Y=4'b0010;
        else if(A==2'b10) Y=4'b0100;
        else Y=4'b1000;
    end
    else
        Y=4'b0000;
end

endmodule


module decoder3to8(A,en,Y);

input [2:0] A;
input en;
output [7:0] Y;

decoder2to4 d1(A[1:0],en&~A[2],Y[3:0]);
decoder2to4 d2(A[1:0],en&A[2],Y[7:4]);

endmodule
