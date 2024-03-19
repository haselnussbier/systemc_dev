#ifndef __TOP__
#define __TOP__

#include<systemc.h>
#include "fifo.h"
#include "producer.h"
#include "consumer.h"

class top : sc_module {
    public:
        fifo fifo_inst;
        producer *producer_inst;
        consumer *consumer_inst;

        SC_CTOR(top) {
            producer_inst = new producer("Producer1");
            producer_inst->out(fifo_inst);

            consumer_inst = new consumer("Consumer1");
            consumer_inst->in(fifo_inst);
        }
};

#endif