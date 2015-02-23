//****************************************************************************
// MIT Media Lab - Biomechatronics
// Jean-Francois (Jeff) Duval
// jfduval@mit.edu
// 02/2015
//****************************************************************************
// flexsea_cmd_control: Control Commands
//****************************************************************************

#ifndef INC_FLEXSEA_CMD_CONTROL_H
#define INC_FLEXSEA_CMD_CONTROL_H

//****************************************************************************
// Include(s)
//****************************************************************************

#include <stdint.h>	
	
//****************************************************************************
// Prototype(s):
//****************************************************************************

uint32_t tx_cmd_ctrl_i(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, int16_t wanted, int16_t measured);
void rx_cmd_ctrl_i(uint8_t *buf);
void test_cmd_ctrl_i(void);
uint32_t tx_cmd_ctrl_mode(uint8_t receiver, uint8_t cmd_type, uint8_t *buf, uint32_t len, int16_t ctrl);
void rx_cmd_ctrl_mode(uint8_t *buf);

//****************************************************************************
// Definition(s):
//****************************************************************************

//ToDo move to flexsea.h when it's debugged
#define CMD_CTRL_I			55
#define CMD_CTRL_MODE		60

//****************************************************************************
// Structure(s):
//****************************************************************************

#endif
