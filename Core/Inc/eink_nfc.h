/**
  ******************************************************************************
  * @file    eink_nfc.h
  * @author  MMY Application Team
  * @version $Revision: 3308 $
  * @date    $Date: 2017-01-13 11:19:33 +0100 (Fri, 13 Jan 2017) $
  * @brief   This file provides set of driver functions to manage communication
  *          between BSP and ST25DV chip.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under ST MYLIBERTY SOFTWARE LICENSE AGREEMENT (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/myliberty
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,
  * AND SPECIFICALLY DISCLAIMING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
#include "ImageData.h"
#include <stdint.h>

#define LOGO_BYTE_START 			0
#define LOGO_BYTE_STOP 				480
#define LOGO_BYTE_LENGTH_BITMAP		480

#define PRICE_EUR_BYTE_START 		500
#define PRICE_EUR_BYTE_STOP 		508
#define PRICE_BYTE_LENGTH 			8
#define PRICE_BYTE_LENGTH_TXT		8

#define PRICE_USD_BYTE_START 		508
#define PRICE_USD_BYTE_STOP 		516

#define PRICE_PLN_BYTE_START 		516
#define PRICE_PLN_BYTE_STOP 		524

#define PRICE_GBP_BYTE_START 		524
#define PRICE_GBP_BYTE_STOP 		532

#define SIZE_BYTE_START 			540
#define SIZE_BYTE_STOP 				541
#define SIZE_BYTE_LENGTH 			1
#define SIZE_BYTE_LENGTH_TXT 		3

#define WASHING_BYTE_START 			541
#define WASHING_BYTE_STOP 			542
#define WASHING_BYTE_LENGTH 		1
#define WASHING_BYTE_LENGTH_BITMAP 	175

#define BLEACHING_BYTE_START 		542
#define BLEACHING_BYTE_STOP 		543
#define BLEACHING_BYTE_LENGTH		1
#define BLEACHING_BYTE_LENGTH_BITMAP 175

#define DRYING_BYTE_START 			543
#define DRYING_BYTE_STOP 			544
#define DRYING_BYTE_LENGTH 			1
#define DRYING_BYTE_LENGTH_BITMAP	175

#define IRONING_BYTE_START 			544
#define IRONING_BYTE_STOP 			545
#define IRONING_BYTE_LENGTH 		1
#define IRONING_BYTE_LENGTH_BITMAP	175

#define PROF_BYTE_START 			545
#define PROF_BYTE_STOP 				546
#define PROF_BYTE_LENGTH 			1
#define PROF_BYTE_LENGTH_BITMAP		175

#define QR_BYTE_START				550
#define QR_BYTE_STOP				850
#define QR_BYTE_LENGTH 				300

typedef enum {
	EINK_NFC_SIZE_XS 	= 0x01,
	EINK_NFC_SIZE_S 	= 0x02,
	EINK_NFC_SIZE_M 	= 0x03,
	EINK_NFC_SIZE_L 	= 0x04,
	EINK_NFC_SIZE_XL 	= 0x05,
	EINK_NFC_SIZE_XXL 	= 0x06,
	EINK_NFC_SIZE_3XL 	= 0x07,
	EINK_NFC_SIZE_4XL 	= 0x08,
	EINK_NFC_SIZE_5XL 	= 0x09

}EINK_NFC_SIZE;

typedef enum{
	EINK_NFC_WASHING_DO_NOT_WASH 	= 0x01,
	EINK_NFC_WASHING_HAND_WASH 		= 0x02,

	EINK_NFC_WASHING_VERY_MILD_30 	= 0x30,
	EINK_NFC_WASHING_MILD_30 		= 0x31,
	EINK_NFC_WASHING_30 			= 0x32,

	EINK_NFC_WASHING_VERY_MILD_40 	= 0x40,
	EINK_NFC_WASHING_MILD_40 		= 0x41,
	EINK_NFC_WASHING_40				= 0x42,

	EINK_NFC_WASHING_MILD_60 		= 0x61,
	EINK_NFC_WASHING_60				= 0x62,

	EINK_NFC_WASHING_70 			= 0x72,
	EINK_NFC_WASHING_95				= 0x95


}EINK_NFC_WASHING;

typedef enum{
	EINK_NFC_BLEACHING_DO_NOT_BLEACH 	= 0x01,
	EINK_NFC_BLEACHING_ANY_BLEACH		= 0x02,
	EINK_NFC_BLEACHING_ONLY_OXYGEN		= 0x03

}EINK_NFC_BLEACHING;

typedef enum{
	EINK_NFC_DRYING_DO_NOT_TUMBLE_DRY	= 0x01,
	EINK_NFC_DRYING_TUMBLE_DRYING		= 0x02,
	EINK_NFC_DRYING_MILD_DRY 			= 0x03,
	EINK_NFC_DRYING_NORMAL_DRYING		= 0x04,
	EINK_NFC_DRYING_NATURAL_DRYING		= 0x05,
	EINK_NFC_DRYING_DRIP_LINE_DRY		= 0x06,
	EINK_NFC_DRYING_LINE_DRY			= 0x07,
	EINK_NFC_DRYING_FLAT_DRYING			= 0x08,
	EINK_NFC_DRYING_LINE_DRYING_SHADE	= 0x09,
	EINK_NFC_DRYING_DRIP_FLAT_DRY		= 0x0A,
	EINK_NFC_DRYING_FLAT_DRY_SHADE		= 0x0B,
	EINK_NFC_DRYING_DRIP_LINE_DRY_SHADE	= 0x0C,
	EINK_NFC_DRYING_DRIP_FLAT_DRY_SHADE	= 0x0D

}EINK_NFC_DRYING;

typedef enum{
	EINK_NFC_IRONING_DO_NOT_IRON	 		= 0x01,
	EINK_NFC_IRONING_LOW_IRON			 	= 0x02,
	EINK_NFC_IRONING_MODE_IRON	 			= 0x03,
	EINK_NFC_IRONING_HOT_IRON	 			= 0x04

}EINK_NFC_IRONING;

typedef enum{
	EINK_NFC_PROF_DRY_CLEAN					= 0x01,
	EINK_NFC_PROF_NORMAL_PERCHLORO_CLEAN	= 0x02,
	EINK_NFC_PROF_MILD_PERCHLORO_CLEAN		= 0x03,
	EINK_NFC_PROF_NORMAL_HYDRO_CLEAN		= 0x04,
	EINK_NFC_PROF_MILD_HYDRO_CLEAN			= 0x05,
	EINK_NFC_PROF_NOT_DRY_CLEAN				= 0x06,
	EINK_NFC_PROF_WETCLEANING				= 0x07,
	EINK_NFC_PROF_NORM_WETCLEANING			= 0x08,
	EINK_NFC_PROF_MILD_WETCLEANING			= 0x09,
	EINK_NFC_PROF_VERY_MILD_WETCLEANING		= 0x0A,
	EINK_NFC_PROF_DO_NOT_WET_CLEAN			= 0x0B

}EINK_NFC_PROF;

typedef struct{
	uint8_t 			logo_bitmap[LOGO_BYTE_LENGTH_BITMAP];
	uint8_t				priceEUR_txt[PRICE_BYTE_LENGTH_TXT+1];
	uint8_t				priceUSD_txt[PRICE_BYTE_LENGTH_TXT+1];
	uint8_t				pricePLN_txt[PRICE_BYTE_LENGTH_TXT+1];
	uint8_t 			priceGBP_txt[PRICE_BYTE_LENGTH_TXT+1];
	uint8_t 			size_txt[SIZE_BYTE_LENGTH_TXT+1];
	uint8_t				washing_bitmap[WASHING_BYTE_LENGTH_BITMAP];
	uint8_t 			drying_bitmap[DRYING_BYTE_LENGTH_BITMAP];
	uint8_t 			bleaching_bitmap[BLEACHING_BYTE_LENGTH_BITMAP];
	uint8_t				ironing_bitmap[IRONING_BYTE_LENGTH_BITMAP];
	uint8_t				professional_bitmap[PROF_BYTE_LENGTH_BITMAP];
	uint8_t				QR_txt[QR_BYTE_LENGTH];

	EINK_NFC_SIZE 		size;
	EINK_NFC_WASHING	washing;
	EINK_NFC_BLEACHING	bleaching;
	EINK_NFC_DRYING 	drying;
	EINK_NFC_IRONING	ironing;
	EINK_NFC_PROF		professional;

}EINK_NFC_TAGINFO_OBJ;


// function declaration
void EINK_NFC_Parser(EINK_NFC_TAGINFO_OBJ* taginfo_obj,uint8_t* data);
void EINK_NFC_DATA_EXTRACT(uint8_t* data, uint8_t* outputDataBuff, uint16_t indexSTART, uint16_t indexSTOP);
void EINK_NFC_SET_SIZE(EINK_NFC_SIZE size, uint8_t* outputSizeTXT);
void EINK_NFC_SET_WASHING(EINK_NFC_WASHING washing, uint8_t* outputBitmap);
void EINK_NFC_SET_BLEACHING(EINK_NFC_BLEACHING bleaching, uint8_t* outputBitmap);
void EINK_NFC_SET_DRYING(EINK_NFC_DRYING drying, uint8_t* outputBitmap);
void EINK_NFC_SET_IRONING(EINK_NFC_IRONING ironing, uint8_t* outputBitmap);
void EINK_NFC_SET_PROF(EINK_NFC_PROF prof, uint8_t* outputBitmap);
uint8_t* EINK_NFC_GET_WASHING(EINK_NFC_WASHING washing);
