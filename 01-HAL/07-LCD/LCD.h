/*
 * LCD.h
 *
 * Created: 2/10/2023 12:56:12 PM
 *  Author: TAQWA HAMED
 */ 


#ifndef LCD_H_
#define LCD_H_

/*****************************************************************************COMANDS*************************************************************************************************************************/
#define LCD_FUNCTION_4BIT_2LINES               0x28
#define LCD_FUNCTION_8BIT_2LINES               0x38
#define LCD_CLEAR_SCREEN                       0x01
#define LCD_RETURN_HOME                        0x02
#define LCD_DISP_OFF_CURSOR_ON				   0x0A
#define LCD_DISP_OFF_CURSOR_OFF                0x08
#define LCD_DISP_ON_CURSOR_ON                  0x0E
#define LCD_DISP_ON_CURSOR_OFF                 0x0C
#define MOVE_DISP_LEFT                         0x18
#define MOVE_DISP_RIGHT                        0x1C
#define MOVE_CURSOR_LEFT                       0x10
#define MOVE_CURSOR_RIGHT                      0x14
#define LCD_DISP_ON_CURSOR_BLINKING            0x0F
#define LCD_ENTRY_DEC                          0x04
#define LCD_ENTRY_INC                          0x06
#define LCD_ENTRY_DEC_SHIFT                    0x05
#define LCD_ENTRY_INC_SHIFT                    0x07
#define LCD_ENTRY_MODE                         0x06
#define LCD_BEGIN_AT_FIRST_RAW                 0x80
#define LCD_BEGIN_AT_SECOND_RAW                0xC0
#define LCD_SET_DDRAM_ADDRESS			       0x80
#define LCD_SET_CGRAM_ADDRESS			       0x40

/*****************************************************************************PARAMS*************************************************************************************************************************/



#define LCD_ROW_1     1
#define LCD_ROW_2     2

#define LCD_COL_1      1
#define LCD_COL_2      2
#define LCD_COL_3      3
#define LCD_COL_4      4
#define LCD_COL_5      5
#define LCD_COL_6      6
#define LCD_COL_7      7
#define LCD_COL_8      8
#define LCD_COL_9      9
#define LCD_COL_10     10
#define LCD_COL_11     11
#define LCD_COL_12     12
#define LCD_COL_13     13
#define LCD_COL_14     14
#define LCD_COL_15     15
#define LCD_COL_16     16














/*****************************************************************************APIS*************************************************************************************************************************/

/************************************************************************/
/**           LCD_voidInit												*/
/**@description   :initialize the LCD either 8-BIT Mode or 4-BIT Mode	*/
/**@param[in]    :void													*/
/**@param[out]   :void													*/
/************************************************************************/

void LCD_voidInit(void);

/************************************************************************************************/
/* Function name :LCD_voidSend_Command															*/
/**@description  :send command to IR REGISTER of the LCD micro controller and saved in DDRAM	*/
/**@param[in]    :u8 Copy_u8LCD_NUM, u8 Copy_u8Command																*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Command(u8 Copy_u8Command);

/************************************************************************************************/
/* Function name :LCD_voidSend_Char																*/
/**@description  :the Function Displays A char on LCD											*/
/**@param[in]    :u8 Copy_u8Char																*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Char( u8 Copy_u8Char);

/************************************************************************************************/
/* Function name :LCD_voidSend_Number															*/
/**@description  :the Function Displays A number on LCD											*/
/**@param[in]    :u32 Copy_u32num 																*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Number( u32 Copy_u32num);

/************************************************************************************************/
/* Function name :LCD_voidSend_Real_Number														*/
/**@description  :the Function Displays A float Number on LCD									*/
/**@param[in]    :f32 Copy_f32num	the number to be displayed									*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_Float_Number(f32 Copy_f32num);



/************************************************************************************************/
/* Function name :LCD_voidSend_String															*/
/**@description  :the Function Displays A string on LCD the string is array of char				*/
/**@param[in]    :Copy_u8data 	the string to be displayed									    */
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidSend_String(u8 *Copy_u8data);

/************************************************************************************************/
/* Function name :LCD_voidCLEAR_SCREEN															*/
/**@description  :the Function clears the screen												*/
/**@param[in]    :void																			*/
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidCLEAR_SCREEN(void);

/************************************************************************************************/
/* Function name :LCD_voidGotoxy																*/
/**@description  :the Function moves the cursor and change its position							*/
/** according to the given data represented by the line number and the position					*/
/**@param[in]    :u8 line  unsigned char line number }											*/
/**@param[in]    :u8 position unsigned char position 									        */
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidGotoxy(u8 Copy_u8line ,u8 Copy_u8position);


/************************************************************************************************/
/* Function name :LCD_voidDrawSpecialChar													    */
/**@description  :the Function Draw special pattern							                    */
/**@param[in]    :u8 Copy_u8Row                                                              	*/
/**@param[in]    :u8 Copy_u8Col 									                            */
/**@param[in]    :u8 * Copy_u8ArrPatterns 									                    */
/**@param[out]   :void																			*/
/************************************************************************************************/
void LCD_voidDrawSpecialChar(	u8 Copy_u8Row ,u8 Copy_u8Col ,u8 Block, u8 * Copy_u8ArrPatterns);






#endif /* LCD_H_ */