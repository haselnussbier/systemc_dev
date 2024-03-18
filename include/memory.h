#ifndef __MEMORY__
#define __MEMORY__

#include<systemc.h>

class memory_if : public sc_interface {
  public:
    virtual int read(int addr) = 0;
    virtual void write(int addr, int data) = 0;
};


class memory_channel : public sc_module, public memory_if{
    public:
        SC_CTOR(memory_channel);
        int read(int addr);
        void write(int addr, int data);

    private:
        int mem [256];
};

void memory_channel::write(int addr, int data){
    if (addr >= 0 && addr <= 255){
        mem[addr] = data;
    }
    else {
        cout << "Address out of range." << endl; 
    }
}

int memory_channel::read(int addr){
    if (addr >= 0 && addr <= 255){
        return mem[addr];
    }
    else {
        cout << "Address out of range." << endl;
        return -1;
    }
}

struct MemoryIFTest : public sc_module {
    sc_in<bool> clk;
    sc_port<memory_if> memory;

    void test_stim();

    SC_CTOR(MemoryIFTest);
};

void MemoryIFTest::test_stim() {
    int addr;
    int data;
    int m_data;
    while(1) {
        addr = std::rand() % 255;
        data = std::rand();
        std::cout <<  "Writing memory address = " << addr << " data = " << data << std::endl;
        memory->write(addr, data);
        m_data = memory->read(addr);
        std::cout <<  "Read memory address = " << addr << " data = " << m_data << std::endl;
        if (m_data != data) {
            std::cout << "Error = incorrect data read from memory" << std::endl;
        }
    wait();
    }
}

#endif