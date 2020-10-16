`timescale 1ns / 1ps


module unsigned_seq_mult_Right_Shift(
    clk,rst,load,a,b,product
    );
input clk,load,rst;
input [5:0] a,b;
output reg [11:0] product;

reg [11:0] M,Q;
reg C, D, E;
integer count;

always @(posedge clk)
begin 
	if(rst)
		begin
			count <= 0;
			product <= 0;
			M <= {6'b000000, b};
			Q <= {a, 6'b000000};
			C <= 0;
		end
		else if(count < 4'b0110)
		begin
			if(M[0] == 1)
			{C, M} = M + Q;

			M = M >> 1;
			M[11] <= C;
			product <= M;
			count <= count + 1;
		end

end

endmodule
