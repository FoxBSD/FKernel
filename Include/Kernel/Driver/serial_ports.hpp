/*
* Serial_ports.hpp
* SPDX-Identifier-License: BSD-3-Clause
* Copyright (c) 2024 FoxBSD
*/

#pragma once

#include <Lib/LibC/stddef.h>
#include <Lib/LibC/stdint.h>

#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8
#define COM5 0x5F8
#define COM6 0x4F8
#define COM7 0x5E8
#define COM8 0x4E8


#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base) (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)

#define SERIAL_LINE_ENABLE_DLAB 0x80
#define SERIAL_INTERRUPT_ENABLE_PORT(base) (base + 1)
#define SERIAL_DIVISOR_LSB_PORT(base) (base + 0)
#define SERIAL_DIVISOR_MSB_PORT(base) (base + 1)
#define SERIAL_INTERRUPT_FIFO_CONTROL_PORT(base) (base + 2)
#define SERIAL_MODEM_CONTROL_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)
#define SERIAL_MODEM_STATUS_PORT(base) (base + 6)
#define SERIAL_SCRATCH_REGISTER_PORT(base) (base + 7)

#define SERIAL_DATA_LENGTH_5 0x0
#define SERIAL_DATA_LENGTH_6 0x1
#define SERIAL_DATA_LENGTH_7 0x2
#define SERIAL_DATA_LENGTH_8 0x3

#define SERIAL_STOP_BIT_1 0x0
#define SERIAL_STOP_BITS_1_5_OR_2 0x4

#define SERIAL_PARITY_NONE 0x0
#define SERIAL_PARITY_ODD 0x8
#define SERIAL_PARITY_EVEN 0x18
#define SERIAL_PARITY_MARK 0x28
#define SERIAL_PARITY_SPACE 0x38

#define SERIAL_INTERRUPT_DATA_AVAILABLE 0x1
#define SERIAL_INTERRUPT_TRANSMITTER_EMPTY 0x2
#define SERIAL_INTERRUPT_BREAK_ERROR 0x4
#define SERIAL_INTERRUPT_STATUS_CHANGE 0x8

#define SERIAL_DTR_CONTROL 0x1
#define SERIAL_RTS_CONTROL 0x2
#define SERIAL_OUT1_CONTROL 0x4
#define SERIAL_OUT2_CONTROL 0x8
#define SERIAL_LOOPBACK_CONTROL 0x10

#define SERIAL_LINE_STATUS_DR 0x1
#define SERIAL_LINE_STATUS_OE 0x2
#define SERIAL_LINE_STATUS_PE 0x4
#define SERIAL_LINE_STATUS_FE 0x8
#define SERIAL_LINE_STATUS_BI 0x10
#define SERIAL_LINE_STATUS_THRE 0x20
#define SERIAL_LINE_STATUS_TEMT 0x40
#define SERIAL_LINE_STATUS_ERROR 0x80

#define SERIAL_MODEM_STATUS_DCTS 0x1
#define SERIAL_MODEM_STATUS_DDSR 0x2
#define SERIAL_MODEM_STATUS_TERI 0x4
#define SERIAL_MODEM_STATUS_DDCD 0x8
#define SERIAL_MODEM_STATUS_CTS 0x10
#define SERIAL_MODEM_STATUS_DSR 0x20
#define SERIAL_MODEM_STATUS_RI 0x40
#define SERIAL_MODEM_STATUS_DCD 0x80

class serial_port{
    private:
        serial_port(){}
        serial_port(const serial_port&) = delete;
        serial_port& operator=(const serial_port&) = delete;

        uint16_t port;
    public:
        static serial_port& get_instance(){
            static serial_port instance;
            return instance; 
        }

        void init(uint16_t start_port);
        
        bool is_transmit_empty();
        bool is_data_ready();

        void write(char a);
        void write_string(const char* str);
        char read();
};