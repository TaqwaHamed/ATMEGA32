/*
 * LCD.c
 *
 * Created: 2/10/2023 12:56:26 PM
 *  Author: TAQWA HAMED
 */ 

#include "../../04-LIB/STD_TYPES.h"
#include "../../04-LIB/BIT_MATH.h"
#include "../../04-LIB/DELAY/DELAY.h"
#include "../../00-MCAL/01-DIO/DIO.h"
#include "LCD.h"
#include "LCD_prv.h"
#include "LCD_cfg.h"




void LCD_voidInit(void)
{
	delay(50);
	DIO_enuWritePin_Value(LCD_RW_PIN,DIO_LOW);
	#if LCD_MODE == EIGHT_BIT 
		
		
		LCD_voidSend_Command(LCD_FUNCTION_8BIT_2LINES);
		delay(1);
		LCD_voidSend_Command(LCD_DISP_ON_CURSOR_ON);
		delay(1);
		LCD_voidSend_Command(LCD_CLEAR_SCREEN);
		delay(2);
		LCD_voidSend_Command(LCD_ENTRY_MODE);
		delay(2);
		
		#elif LCD_MODE == FOUR_BIT
		
		LCD_voidSend_Command(LCD_RETURN_HOME);
		delay(15);
		LCD_voidSend_Command(LCD_FUNCTION_4BIT_2LINES);
		delay(1);
		LCD_voidSend_Command(LCD_DISP_ON_CURSOR_ON);
		delay(1);
		LCD_voidSend_Command(LCD_CLEAR_SCREEN);
		delay(15);
		LCD_voidSend_Command(LCD_ENTRY_MODE);
		delay(2);
		
		
		#endif
	
	
	
}


void LCD_voidSend_Command(u8 Copy_u8Command)
{
	
		//* RS ----> LOW " COMMAND"
	DIO_enuWritePin_Value(LCD_RS_PIN,DIO_LOW);
	LCD_voidLatch(Copy_u8Command);
	
	
}

static void LCD_voidSend_Enable_Trigger()
{
	DIO_enuWritePin_Value(LCD_EN_PIN,DIO_HIGH);
	delay(5);
	DIO_enuWritePin_Value(LCD_EN_PIN,DIO_LOW);
}


void LCD_voidSend_Char( u8 Copy_u8Char)
{
	DIO_enuWritePin_Value(LCD_RS_PIN,DIO_HIGH);
	LCD_voidLatch(Copy_u8Char);
}



void LCD_voidSend_Number( u32 Copy_u32num)
{
	
	u32 LOC_u32Reversed = 1 ;

	if( Copy_u32num == 0 ){ LCD_voidSend_Char('0'); }

	else{

		while ( Copy_u32num != 0 ){

			LOC_u32Reversed = ( LOC_u32Reversed * 10 ) + ( Copy_u32num % 10 );
			Copy_u32num /= 10 ;

		}

		while ( LOC_u32Reversed != 1 )
		{
			DIO_enuWritePin_Value(LCD_RS_PIN,DIO_HIGH);
			LCD_voidSend_Char( ( LOC_u32Reversed % 10 ) + 48 );
			LOC_u32Reversed /= 10 ;

		}

	}


	}

		
void LCD_voidSend_Float_Number(f32 Copy_f32num)
{
	u8 str [16];
	
	
	LCD_voidSend_Number((u64)Copy_f32num ); 
	LCD_voidSend_Char('.'); 
	
	u64 Local_u64tempNumber = Copy_f32num*1000000;
	
	if( Local_u64tempNumber%10 >=5 )
	{
		LCD_voidSend_Number((u64)((( Local_u64tempNumber/10)+1) % 100000));
	}
	else
	{
		LCD_voidSend_Number((u64)(( Local_u64tempNumber/10) % 100000)); 
	}
	
	
}


void LCD_voidDrawSpecialChar(	u8 Copy_u8Row ,u8 Copy_u8Col ,u8 Block, u8 * Copy_u8ArrPatterns)
{
	
	
	/* Get the address of CGRAM */
	u8 Local_Add = Block * LCD_BLOCK_SIZE;

	LCD_voidSend_Command(Local_Add +LCD_SET_CGRAM_ADDRESS);
	u8 counter = 0;
	while(counter<8)
	{
		LCD_voidSend_Char(Copy_u8ArrPatterns[counter]);
		counter++;
	}

	
	LCD_voidGotoxy(Copy_u8Row,Copy_u8Col);
	LCD_voidSend_Char(Block);
}










		
static void LCD_voidLatch(u8 copy_u8Data)
{

	// set RW as  write operation,EN LOW
	DIO_enuWritePin_Value(LCD_RW_PIN,DIO_LOW);
	DIO_enuWritePin_Value(LCD_EN_PIN,DIO_HIGH);

	

	#if LCD_MODE==EIGHT_BIT
 
    DIO_enuWritePin_Value(LCD_D7_PIN, GET_BIT (copy_u8Data,7) );
    DIO_enuWritePin_Value(LCD_D6_PIN, GET_BIT(copy_u8Data,6) );
    DIO_enuWritePin_Value(LCD_D5_PIN, GET_BIT(copy_u8Data,5)  );
    DIO_enuWritePin_Value(LCD_D4_PIN, GET_BIT(copy_u8Data,4)  );
	DIO_enuWritePin_Value(LCD_D3_PIN,GET_BIT (copy_u8Data,3) );
	DIO_enuWritePin_Value(LCD_D2_PIN, GET_BIT(copy_u8Data,2) );
	DIO_enuWritePin_Value(LCD_D1_PIN, GET_BIT(copy_u8Data,1) );
	DIO_enuWritePin_Value(LCD_D0_PIN, GET_BIT(copy_u8Data,0) );
	LCD_voidSend_Enable_Trigger();
	#elif LCD_MODE == FOUR_BIT
        #if NIBBLE==LOW_NIBBLE
	        
		    DIO_enuWritePin_Value(LCD_D3_PIN,GET_BIT (copy_u8Data>>4,3) );
		    DIO_enuWritePin_Value(LCD_D2_PIN, GET_BIT(copy_u8Data>>4,2) );
		    DIO_enuWritePin_Value(LCD_D1_PIN, GET_BIT(copy_u8Data>>4,1) );
		    DIO_enuWritePin_Value(LCD_D0_PIN, GET_BIT(copy_u8Data>>4,0) );
			LCD_voidSend_Enable_Trigger();
			DIO_enuWritePin_Value(LCD_D3_PIN,GET_BIT (copy_u8Data,3) );
			DIO_enuWritePin_Value(LCD_D2_PIN, GET_BIT(copy_u8Data,2) );
			DIO_enuWritePin_Value(LCD_D1_PIN, GET_BIT(copy_u8Data,1) );
			DIO_enuWritePin_Value(LCD_D0_PIN, GET_BIT(copy_u8Data,0) );
		    LCD_voidSend_Enable_Trigger();
			
		#elif NIBBLE==HIGH_NIBBLE
			
			  DIO_enuWritePin_Value(LCD_D7_PIN, GET_BIT (copy_u8Data>>4,7) );
			  DIO_enuWritePin_Value(LCD_D6_PIN, GET_BIT (copy_u8Data>>4,6) );
			  DIO_enuWritePin_Value(LCD_D5_PIN, GET_BIT (copy_u8Data>>4,5)  );
			  DIO_enuWritePin_Value(LCD_D4_PIN, GET_BIT (copy_u8Data>>4,4)  );
			  LCD_voidSend_Enable_Trigger();
			 
			 DIO_enuWritePin_Value(LCD_D7_PIN, GET_BIT (copy_u8Data,7) );
			 DIO_enuWritePin_Value(LCD_D6_PIN, GET_BIT (copy_u8Data,6) );
			 DIO_enuWritePin_Value(LCD_D5_PIN, GET_BIT (copy_u8Data,5)  );
			 DIO_enuWritePin_Value(LCD_D4_PIN, GET_BIT (copy_u8Data,4)  );
			 LCD_voidSend_Enable_Trigger();
			 
         #endif


	#endif

	



}

		

void LCD_voidSend_String(u8 *Copy_u8data)
{
	
	u8 LOC_u8Iterator=0;

	while(Copy_u8data[LOC_u8Iterator]!= '\0')
	{
		LCD_voidSend_Char(Copy_u8data[LOC_u8Iterator]);
		LOC_u8Iterator++;

	}
	
	
}	

void LCD_voidGotoxy(u8 Copy_u8line ,u8 Copy_u8position)
{
	if( Copy_u8line == LCD_ROW_1 )
	{
		LCD_voidSend_Command(LCD_SET_DDRAM_ADDRESS + ( Copy_u8position - 1 ) );
	}
	else if( Copy_u8line == LCD_ROW_2 )
	{
		LCD_voidSend_Command(LCD_SET_DDRAM_ADDRESS + 0x40 + ( Copy_u8position - 1 ) );
	}
}

void LCD_voidCLEAR_SCREEN(void)
{
	
	LCD_voidSend_Command(LCD_CLEAR_SCREEN);
	delay(2);
	
}