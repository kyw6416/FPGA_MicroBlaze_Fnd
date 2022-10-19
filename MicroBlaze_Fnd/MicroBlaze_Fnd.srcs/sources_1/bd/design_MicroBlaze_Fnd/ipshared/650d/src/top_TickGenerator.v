`timescale 1ns / 1ps

module top_TickGenerator(
    input  i_clk,
    input  i_reset,
    output [31:0] o_tick
    );

    wire w_clk_1kHz;

    clockDivider U0(
    .i_clk(i_clk),
    .i_reset(i_reset),
    .o_clk(w_clk_1kHz)
    );

    counter U1(
    .i_clk(w_clk_1kHz),
    .i_reset(i_reset),
    .o_counter(o_tick)
    );
endmodule
