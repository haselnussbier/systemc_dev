#include "../include/fsm_slave.h"

void fsm_slave::get_next_state(){
    current_state = s_reset;
    while(1){
        wait();
        if (channel->s_read_reset() == true){
            current_state = s_reset;
        }
        else {
            switch (current_state)
            {
            case s_reset:
                //reset output
                channel->s_write_ready(0);
                COUNTER = 0;
                current_state = ready;
                break;

            case ready:
                channel->s_write_ready(1);
                current_state = waitForValid;
                break;

            case waitForValid:
                if(channel->s_read_valid()==1){
                    channel->s_write_ready(0);
                    OUT[COUNTER] = channel->s_read_data();
                    if((COUNTER == (OUTLENGTH-1)) || (channel->s_read_last()==true)){
                        COUNTER = 0;
                    }
                    else {
                        COUNTER = COUNTER + 1;
                    }
                    current_state = ready;
                }
                else {
                    current_state = waitForValid;
                }
                break;
            
            default:
                break;
            }
        }
    }
}