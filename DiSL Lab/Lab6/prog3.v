module decoder2to4(A,en,Y);

input [1:0] A;
input en;
output reg [3:0] Y;

always @(*)
begin
    Y=4'b1111;

    if(en)
    begin
        case(A)
            2'b00: Y=4'b1110;
            2'b01: Y=4'b1101;
            2'b10: Y=4'b1011;
            2'b11: Y=4'b0111;
        endcase
    end
end

endmodule


module decoder4to16(A,en,Y);

input [3:0] A;
input en;
output [15:0] Y;
wire [3:0] E;

decoder2to4 d1(A[3:2],en,E);

decoder2to4 d2(A[1:0],~E[0],Y[3:0]);
decoder2to4 d3(A[1:0],~E[1],Y[7:4]);
decoder2to4 d4(A[1:0],~E[2],Y[11:8]);
decoder2to4 d5(A[1:0],~E[3],Y[15:12]);

endmodule
