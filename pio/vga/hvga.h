// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// --------- //
// vga_hsync //
// --------- //

#define vga_hsync_wrap_target 1
#define vga_hsync_wrap 2

static const uint16_t vga_hsync_program_instructions[] = {
    0x6040, //  0: out    y, 32           side 0     
            //     .wrap_target
    0xa522, //  1: mov    x, y            side 0 [5] 
    0x1042, //  2: jmp    x--, 2          side 1     
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program vga_hsync_program = {
    .instructions = vga_hsync_program_instructions,
    .length = 3,
    .origin = -1,
};

static inline pio_sm_config vga_hsync_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + vga_hsync_wrap_target, offset + vga_hsync_wrap);
    sm_config_set_sideset(&c, 1, false, false);
    return c;
}

static inline void vga_hsync_program_init(PIO pio, uint stma, uint offset, uint hsync)
{
    pio_gpio_init(pio, hsync);
    pio_sm_set_consecutive_pindirs(pio, stma, hsync, 1, true);
    pio_sm_config c = vga_hsync_program_get_default_config(offset);
    sm_config_set_sideset_pins(&c, hsync);
    sm_config_set_set_pins(&c, hsync, 1);
    sm_config_set_out_shift(&c,true,true,8);
    // clock
    sm_config_set_clkdiv_int_frac(&c, 178,0);
    pio_sm_init(pio, stma, offset, &c);
}

#endif

