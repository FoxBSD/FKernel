#include <Kernel/Driver/serial_ports.hpp>
#include <Kernel/Io/io_operations.hpp>

void serial_port::init(uint16_t start_port){
    this->port = start_port; 
    
    outb(SERIAL_LINE_COMMAND_PORT(this->port), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(this->port), 0x01);
    outb(SERIAL_DATA_PORT(this->port), 0x00);
    outb(SERIAL_LINE_COMMAND_PORT(this->port), 0x03);
    outb(SERIAL_FIFO_COMMAND_PORT(this->port), 0xC7);
    outb(SERIAL_MODEM_COMMAND_PORT(this->port), 0x0B);
    
    return;
}

bool serial_port::is_transmit_empty(){
    return inb(SERIAL_LINE_STATUS_PORT(this->port)) & 0x20;
}

void serial_port::write(char a) {
    while (is_transmit_empty() == 0);
    outb(SERIAL_DATA_PORT(this->port), a);

    return; 
}

char serial_port::read() {
    while (inb(SERIAL_LINE_STATUS_PORT(this->port)) & (1 == 0));
    return inb(SERIAL_DATA_PORT(this->port));
}

bool serial_port::is_data_ready() {
    return inb(SERIAL_LINE_STATUS_PORT(this->port)) & 1;
}

void serial_port::write_string(const char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        write(str[i]);
    }
}