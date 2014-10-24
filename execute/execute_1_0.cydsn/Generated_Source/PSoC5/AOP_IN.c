/*******************************************************************************
* File Name: AOP_IN.c  
* Version 2.0
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "AOP_IN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 AOP_IN__PORT == 15 && ((AOP_IN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: AOP_IN_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void AOP_IN_Write(uint8 value) 
{
    uint8 staticBits = (AOP_IN_DR & (uint8)(~AOP_IN_MASK));
    AOP_IN_DR = staticBits | ((uint8)(value << AOP_IN_SHIFT) & AOP_IN_MASK);
}


/*******************************************************************************
* Function Name: AOP_IN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  AOP_IN_DM_STRONG     Strong Drive 
*  AOP_IN_DM_OD_HI      Open Drain, Drives High 
*  AOP_IN_DM_OD_LO      Open Drain, Drives Low 
*  AOP_IN_DM_RES_UP     Resistive Pull Up 
*  AOP_IN_DM_RES_DWN    Resistive Pull Down 
*  AOP_IN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  AOP_IN_DM_DIG_HIZ    High Impedance Digital 
*  AOP_IN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void AOP_IN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(AOP_IN_0, mode);
}


/*******************************************************************************
* Function Name: AOP_IN_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro AOP_IN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 AOP_IN_Read(void) 
{
    return (AOP_IN_PS & AOP_IN_MASK) >> AOP_IN_SHIFT;
}


/*******************************************************************************
* Function Name: AOP_IN_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 AOP_IN_ReadDataReg(void) 
{
    return (AOP_IN_DR & AOP_IN_MASK) >> AOP_IN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(AOP_IN_INTSTAT) 

    /*******************************************************************************
    * Function Name: AOP_IN_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 AOP_IN_ClearInterrupt(void) 
    {
        return (AOP_IN_INTSTAT & AOP_IN_MASK) >> AOP_IN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
