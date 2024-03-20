#include "../include/fsm_master.h"
#include<string>

void fsm_master::get_next_state(){
    current_state = m_reset;
    while(true){
        wait();

        if (channel->m_read_reset() == true)
        {
            current_state = m_reset;
        }
        else{

            switch (current_state)
            {
            case m_reset:
                channel->m_write_data(0);
                COUNTER = 0;
                channel->m_write_valid(0);
                channel->m_write_last(0);
                current_state = waitForTriggerHigh;
                break;
            
            case waitForTriggerHigh:
                if (channel->m_read_trigger()==true){
                    current_state = waitForTriggerLow;
                }
                break;

            case waitForTriggerLow:
                if (channel->m_read_trigger()==false){
                    current_state = waitForReady;
                }
                break;

            case waitForReady:
                channel->m_write_data(COUNTER);
                channel->m_write_valid(1);

                if(COUNTER < (LENGTH-1)){
                    channel->m_write_last(0);
                }
                else {
                    channel->m_write_last(1);
                }

                current_state = waitForSlave;

                break;

            case waitForSlave:
                if(channel->m_read_ready() == true){
                    channel->m_write_valid(0);
                    channel->m_write_last(0);
                    if(COUNTER < (LENGTH - 1)){
                        COUNTER = COUNTER + 1;
                        current_state = waitForReady;
                    }
                    else {
                        COUNTER = 0;
                        current_state = waitForTriggerHigh;
                    }
                }
                else {
                    current_state = waitForSlave;
                }
                break;

            default:
                break;
            }
        }
    }
}