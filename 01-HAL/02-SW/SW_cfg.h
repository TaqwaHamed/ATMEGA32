/*
 * SW_cfg.h
 *
 * Created: 1/18/2023 1:08:21 PM
 *  Author: totoh
 */ 


#ifndef SW_CFG_H_
#define SW_CFG_H_

typedef enum{

	SW_PULL_UP				,
	SW_PULL_DOWN			,
	SW_INPUT_FLOATING

}SW_tenuSwtype;


typedef struct{
	u8 SW_Pin;
	SW_tenuSwtype Type; 
}SW_tstrSwCfg_t;

//Number of SWs connected to the system
#define MAX_SW_NUMBER		4



#endif /* SW_CFG_H_ */