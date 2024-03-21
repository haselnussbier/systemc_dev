# AXI-Stream-Interface

This repository was created within the scope of the HMS self study task and is supposed to simulate an AXI-Stream-Interface with SystemC.

The task contained:
- Understand the AXI-Stream protocol
- Set up SystemC environment
- Implement interfaces to ensure the modules can be easily expanded
- Implement the interface logic
- Add data transfer functionality
- Implement packet transmission

## Components

### Signals

The signals used are:
- **ACLK**:       the clock
- **ARESETn**:    the reset signal
- **TDATA**:      the data 
- **TVALID**:     signalizes valid data by the master
- **TLAST**:      signalizes the last of transmitted data
- **TREADY**:     signalizes the slave is ready
- **TRIGGER**:    used to trigger a transmission

### Top

The Top-Module combines the three underlying modules: AXI, Master, Slave. All three are only connected over a singular channel.

### Channel

The axi_channel is a hierarchical channel with interfaces for the three aformentioned modules. It handles the transmission of all signals between the modules.

### Master

The master is described by a FSM handling the logic of initiating transmission and generating data. Outgoing signals of the master are: TDATA, TVALID, TLAST and incoming: ACLK, ARESETn, TREADY, TRIGGER. The Master-Interface onto the axi_channel has write-functions for all outgoing signals and read functions for all incoming signals (except ACLK). Internal variables of the master are COUNTER and LENGTH. LENGTH is the amount of bytes that are to be transmitted with each process, while COUNTER ticks up with each successful data transmission (handshake) to determine when the last data-packet was transmitted. The TRIGGER signal is used to indicate the start of a transmission.

FSM: 
If ARESETn is 1 the master goes into its m_reset state.

**m_reset:** the master resets all of its outgoing signals and goes into the waitForTriggerHigh state.

**waitForTriggerHigh:** the master stays here until TRIGGER is 1 and then goes into the waitForTriggerLow state.

**waitForTriggerLow:** the master stays here until TRIGGER is 0 and then goes into the waitForReady state.

**waitForRead:** the master generates TDATA, writes it on the channel and sets the TVALid signal on 1. If this is the last data-package it also sets TLAST on 1. The master goes into the waitForSlave state.

**waitForSlave:** the master checks TREADY. If TREADY is 0, the master stays in the waitForSlave state. If TREADY is 1 the handshake is accepted, since TVALID vas set in the last state. Thus the data was read and TVALID and TLAST (in case it was set in the last state) are set to 0. If not all of the data was yet transmitted (COUNTER < LENGTH - 1) the COUNTER is increased by 1 and the next state is waitForReady. If it wast hen the COUNTER is reset and the next state is waitForTriggerHigh. 
### Slave

The slave is also described by a FSM and just like the master its interface consists of write-functions for outgoing signals (TREADY) and read-functions for incoming signals (ARESETn, TDATA, TVALID, TLAST). The slave has an internal array **OUT[OUTLENGTH]** which stores the data received from the master and an associated COUNTER.

FSM:

If ARESETn is 1 the slave goes into its s_reset state.

**s_reset:** the slave resets the contents of OUT and the COUNTER, then goes into the ready state.

**ready:** the slave sets TREADY on 1 and goes into the waitForValid state.

**waitForValid** the slave checks TVALID. If TVALID is 0, the slave stays in the waitForValid state. IF TVALID is 1, the handshake is complete, since TREADY was set to 1 in the previous state. The slave reads the data from the channel, stores it in OUT. If the array OUT is full (COUNTER < OUTLENGTH - 1) or TLAST is 1, the COUNTER is reset to 0, otherwise its incremented by 1. Either way the slave goes into the ready state.

### AXI

The AXI module is essentially the controller of the channel. Therefore its interface only consists of two write-functions for the two signals the controller must posess: write_reset to reset the whole process and write_trigger to initiate the process of data-transmission.





