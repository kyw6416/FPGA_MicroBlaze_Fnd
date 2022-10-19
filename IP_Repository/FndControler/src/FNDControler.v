`timescale 1ns / 1ps

module FNDControler(
    input i_clk,
    input i_reset,
    input [13:0] i_value,
    output [3:0] o_fndSelect,
    output [7:0] o_fndFont
    );

    wire w_clk;
    clock_divider_fnd U1(
    .i_clk(i_clk),
    .i_reset(i_reset),
    .o_clk_fnd(w_clk)
    );

    wire [1:0] w_counter;
    counter_fnd U2(
    .i_clk_fnd(w_clk),
    .i_reset(i_reset),
    .o_counter_fnd(w_counter)
    );

    decoder_2x4 U3(
    .i_digitPosion(w_counter),
    .o_digitSelect(o_fndSelect)
    );

    wire [3:0] w_1000, w_100, w_10, w_1; 
    digit_divider U4(
    .i_counter_data(i_value),
    .o_1000(w_1000), 
    .o_100(w_100), 
    .o_10(w_10), 
    .o_1(w_1) 
    );

    wire [3:0] w_muxout;
    mux_4x1 U5(
    .i_1000(w_1000), 
    .i_100(w_100), 
    .i_10(w_10), 
    .i_1(w_1),
    .i_counter_fnd(w_counter),
    .o_muxout(w_muxout)
    );

    BCDtoFND_decoder U6(
    .i_value(w_muxout),
    .o_fndFont(o_fndFont)
    );
endmodule
