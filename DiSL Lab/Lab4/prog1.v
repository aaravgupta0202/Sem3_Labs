//==============================
// HALF ADDER
//==============================
module half_adder(A, B, Sum, Carry);
    input  A, B;
    output Sum, Carry;
    assign Sum   = A ^ B;
    assign Carry = A & B;
endmodule


//==============================
// FULL ADDER
//==============================
module full_adder(A, B, Cin, Cout, Sum);
    input  A, B, Cin;
    output Sum, Cout;
    assign Sum  = A ^ B ^ Cin;
    assign Cout = (A & B) | (B & Cin) | (A & Cin);
endmodule