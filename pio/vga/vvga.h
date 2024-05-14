// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// --------- //
// vga_vsync //
// --------- //

#define vga_vsync_wrap_target 1
#define vga_vsync_wrap 8

static const uint16_t vga_vsync_program_instructions[] = {
    0x6040, //  0: out    y, 32           side 0     
            //     .wrap_target
    0xa022, //  1: mov    x, y            side 0     
    0x2006, //  2: wait   0 gpio, 6       side 0     
    0x2086, //  3: wait   1 gpio, 6       side 0     
    0x2006, //  4: wait   0 gpio, 6       side 0     
    0x2086, //  5: wait   1 gpio, 6       side 0     
    0x2006, //  6: wait   0 gpio, 6       side 0     
    0x2086, //  7: wait   1 gpio, 6       side 0     
    0x1048, //  8: jmp    x--, 8          side 1     
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program vga_vsync_program = {
    .instructions = vga_vsync_program_instructions,
    .length = 9,
    .origin = -1,
};

static inline pio_sm_config vga_vsync_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + vga_vsync_wrap_target, offset + vga_vsync_wrap);
    sm_config_set_sideset(&c, 1, false, false);
    return c;
}

static inline void vga_vsync_program_init(PIO pio, uint stma, uint offset, uint vsync)
{
    pio_gpio_init(pio, vsync);
    pio_sm_set_consecutive_pindirs(pio, stma, vsync, 1, true);
    pio_sm_config c = vga_vsync_program_get_default_config(offset);
    sm_config_set_sideset_pins(&c, vsync);
    sm_config_set_set_pins(&c, vsync, 1);
    sm_config_set_out_shift(&c,true,true,8);
    // clock
    sm_config_set_clkdiv_int_frac(&c, 178,0);
    pio_sm_init(pio, stma, offset, &c);
}

#endif

