// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// --------- //
// vga_video //
// --------- //

#define vga_video_wrap_target 1
#define vga_video_wrap 8

static const uint16_t vga_video_program_instructions[] = {
    0x6040, //  0: out    y, 32                      
            //     .wrap_target
    0xa022, //  1: mov    x, y                       
    0x2006, //  2: wait   0 gpio, 6                  
    0x2f86, //  3: wait   1 gpio, 6              [15]
    0xaf42, //  4: nop                           [15]
    0xaf42, //  5: nop                           [15]
    0x6008, //  6: out    pins, 8                    
    0x0046, //  7: jmp    x--, 6                     
    0xa003, //  8: mov    pins, null                 
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program vga_video_program = {
    .instructions = vga_video_program_instructions,
    .length = 9,
    .origin = -1,
};

static inline pio_sm_config vga_video_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + vga_video_wrap_target, offset + vga_video_wrap);
    return c;
}

static inline void vga_video_program_init(PIO pio, uint stma, uint offset, uint startDataPin)
{
    pio_sm_config c = vga_video_program_get_default_config(offset);
    for (int i = startDataPin; i < startDataPin + 8; i++)
        pio_gpio_init(pio, i);
    pio_sm_set_consecutive_pindirs(pio, stma, startDataPin, 8, true);
    sm_config_set_out_pins(&c, startDataPin, 8);
    sm_config_set_out_shift(&c, true, true, 8);
    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);
    // clock
    sm_config_set_clkdiv_int_frac(&c, 11, 0);
    pio_sm_init(pio, stma, offset, &c);
    printf("data print: \n");
}

#endif
