/**
  ******************************************************************************
  * @file    eink_nfc.c
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
#include "eink_nfc.h"
#include <string.h>
#include <memory.h>

void EINK_NFC_DATA_EXTRACT(uint8_t* data, uint8_t* outputDataBuff, uint16_t indexSTART, uint16_t indexSTOP){

	memcpy(outputDataBuff, data+indexSTART, indexSTOP-indexSTART);
}
void EINK_NFC_Parser(EINK_NFC_TAGINFO_OBJ* taginfo_obj,uint8_t* data){

	// Init data buffers
	//uint8_t LogoBITMAPBuff[LOGO_BYTE_LENGTH_BITMAP];

	//uint8_t priceEURTXTBuff[PRICE_BYTE_LENGTH];
	//uint8_t priceUSDTXTBuff[PRICE_BYTE_LENGTH];
	//uint8_t pricePLNTXTBuff[PRICE_BYTE_LENGTH];
	//uint8_t priceGBPTXTBuff[PRICE_BYTE_LENGTH];

	uint8_t sizeTemp[SIZE_BYTE_LENGTH];
	uint8_t washingTemp[WASHING_BYTE_LENGTH];
	uint8_t bleachingTemp[BLEACHING_BYTE_LENGTH];
	uint8_t dryingTemp[DRYING_BYTE_LENGTH];
	uint8_t ironingTemp[IRONING_BYTE_LENGTH];
	uint8_t professionalTemp[PROF_BYTE_LENGTH];


	EINK_NFC_SIZE sizeObjBuff;
	EINK_NFC_WASHING washingObjBuff;
	EINK_NFC_BLEACHING bleachingObjBuff;
	EINK_NFC_DRYING dryingObjBuff;
	EINK_NFC_IRONING ironingObjBuff;
	EINK_NFC_PROF professionalObjBuff;

	//Parse Logo
	EINK_NFC_DATA_EXTRACT(data, taginfo_obj->logo_bitmap, LOGO_BYTE_START, LOGO_BYTE_STOP);
	//Parse price EUR
	EINK_NFC_DATA_EXTRACT(data, taginfo_obj->priceEUR_txt, PRICE_EUR_BYTE_START, PRICE_EUR_BYTE_STOP);
	//Parse price USD
	EINK_NFC_DATA_EXTRACT(data, taginfo_obj->priceUSD_txt, PRICE_USD_BYTE_START, PRICE_USD_BYTE_STOP);
	//Parse price PLN
	EINK_NFC_DATA_EXTRACT(data, taginfo_obj->pricePLN_txt, PRICE_PLN_BYTE_START, PRICE_PLN_BYTE_STOP);
	//Parse price GBP
	EINK_NFC_DATA_EXTRACT(data, taginfo_obj->priceGBP_txt, PRICE_GBP_BYTE_START, PRICE_GBP_BYTE_STOP);
	//Parse size
	EINK_NFC_DATA_EXTRACT(data, sizeTemp, SIZE_BYTE_START, SIZE_BYTE_STOP);
	sizeObjBuff=*sizeTemp;
	taginfo_obj->size=sizeObjBuff;
	EINK_NFC_SET_SIZE(sizeObjBuff,taginfo_obj->size_txt);
	//Parse washing
	EINK_NFC_DATA_EXTRACT(data, washingTemp, WASHING_BYTE_START, WASHING_BYTE_STOP);
	washingObjBuff=*washingTemp;
	taginfo_obj->washing=washingObjBuff;
	EINK_NFC_SET_WASHING(washingObjBuff,taginfo_obj->washing_bitmap);
	//Parse bleaching
	EINK_NFC_DATA_EXTRACT(data, bleachingTemp, BLEACHING_BYTE_START, BLEACHING_BYTE_STOP);
	bleachingObjBuff=*bleachingTemp;
	taginfo_obj->bleaching=bleachingObjBuff;
	EINK_NFC_SET_BLEACHING(bleachingObjBuff,taginfo_obj->bleaching_bitmap);
	//Parse drying
	EINK_NFC_DATA_EXTRACT(data, dryingTemp, DRYING_BYTE_START, DRYING_BYTE_STOP);
	dryingObjBuff=*dryingTemp;
	taginfo_obj->drying=dryingObjBuff;
	EINK_NFC_SET_DRYING(dryingObjBuff,taginfo_obj->drying_bitmap);
	//Parse ironing
	EINK_NFC_DATA_EXTRACT(data, ironingTemp, IRONING_BYTE_START, IRONING_BYTE_STOP);
	ironingObjBuff=*ironingTemp;
	taginfo_obj->ironing=ironingObjBuff;
	EINK_NFC_SET_IRONING(ironingObjBuff,taginfo_obj->ironing_bitmap);
	//Parse professional
	EINK_NFC_DATA_EXTRACT(data, professionalTemp, IRONING_BYTE_START, IRONING_BYTE_STOP);
	professionalObjBuff=*professionalTemp;
	taginfo_obj->professional=professionalObjBuff;
	EINK_NFC_SET_PROF(professionalObjBuff,taginfo_obj->professional_bitmap);
	//Parse QR data
	strncpy((char*)taginfo_obj->QR_txt,(char*)data+QR_BYTE_START,QR_BYTE_LENGTH);
	//EINK_NFC_DATA_EXTRACT(data, taginfo_obj->QR_txt, QR_BYTE_START, QR_BYTE_STOP);


}

void EINK_NFC_SET_SIZE(EINK_NFC_SIZE size, uint8_t* outputSizeTXT){

	switch (size)
	{
		case EINK_NFC_SIZE_XS:
			memcpy(outputSizeTXT," XS",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_S:
			memcpy(outputSizeTXT,"  S",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_M:
			memcpy(outputSizeTXT,"  M",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_L:
			memcpy(outputSizeTXT,"  L",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_XL:
			memcpy(outputSizeTXT," XL",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_XXL:
			memcpy(outputSizeTXT,"XXL",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_3XL:
			memcpy(outputSizeTXT,"3XL",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_4XL:
			memcpy(outputSizeTXT,"4XL",SIZE_BYTE_LENGTH_TXT);
			break;
		case EINK_NFC_SIZE_5XL:
			memcpy(outputSizeTXT,"5XL",SIZE_BYTE_LENGTH_TXT);
			break;
		default:
			memcpy(outputSizeTXT,"ERR",SIZE_BYTE_LENGTH_TXT);
			break;
	}

}


void EINK_NFC_GET_BLEACHING(EINK_NFC_BLEACHING bleaching, uint8_t* outputBitmap){
	int length_bitmap=BLEACHING_BYTE_LENGTH_BITMAP;
	switch (bleaching)
	{
		case EINK_NFC_BLEACHING_DO_NOT_BLEACH:
			memcpy(outputBitmap,bleaching_do_not_bleach,length_bitmap);
			break;
		case EINK_NFC_BLEACHING_ANY_BLEACH:
			memcpy(outputBitmap,bleaching_any_bleach,length_bitmap);
			break;
		case EINK_NFC_BLEACHING_ONLY_OXYGEN:
			memcpy(outputBitmap,bleaching_only_oxygen,length_bitmap);
			break;
		default:
			break;
	}

}

void EINK_NFC_GET_DRYING(EINK_NFC_DRYING drying, uint8_t* outputBitmap){
	int length_bitmap=DRYING_BYTE_LENGTH_BITMAP;
	switch (drying)
	{
		case EINK_NFC_DRYING_DO_NOT_TUMBLE_DRY:
			memcpy(outputBitmap,drying_do_not_tuble_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_TUMBLE_DRYING:
			memcpy(outputBitmap,drying_tumble_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_MILD_DRY:
			memcpy(outputBitmap,drying_mild_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_NORMAL_DRYING:
			memcpy(outputBitmap,drying_normal_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_NATURAL_DRYING:
			memcpy(outputBitmap,drying_natural_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_LINE_DRY:
			memcpy(outputBitmap,drying_drip_line_dry, length_bitmap);
			break;
		case EINK_NFC_DRYING_LINE_DRY:
			memcpy(outputBitmap,drying_line_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_FLAT_DRYING:
			memcpy(outputBitmap,drying_flat_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_LINE_DRYING_SHADE:
			memcpy(outputBitmap,drying_line_drying_shade,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_FLAT_DRY:
			memcpy(outputBitmap,drying_drip_flat_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_FLAT_DRY_SHADE:
			memcpy(outputBitmap,drying_flat_dry_shade,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_LINE_DRY_SHADE:
			memcpy(outputBitmap,drying_drip_line_dry_shade,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_FLAT_DRY_SHADE:
			memcpy(outputBitmap,drying_drip_flat_dry_shade,length_bitmap);
			break;
		default:
			break;
	}

}

void EINK_NFC_GET_IRONING(EINK_NFC_IRONING ironing, uint8_t* outputBitmap){
	int length_bitmap=IRONING_BYTE_LENGTH_BITMAP;
	switch (ironing)
	{
		case EINK_NFC_IRONING_DO_NOT_IRON:
			memcpy(outputBitmap,ironing_do_not_iron,length_bitmap);
			break;
		case EINK_NFC_IRONING_LOW_IRON:
			memcpy(outputBitmap,ironing_low_iron,length_bitmap);
			break;
		case EINK_NFC_IRONING_MODE_IRON:
			memcpy(outputBitmap,ironing_mode_iron,length_bitmap);
			break;
		case EINK_NFC_IRONING_HOT_IRON:
			memcpy(outputBitmap,ironing_hot_iron,length_bitmap);
			break;

		default:
			break;
	}

}

void EINK_NFC_GET_PROF(EINK_NFC_PROF prof, uint8_t* outputBitmap){
	int length_bitmap=PROF_BYTE_LENGTH_BITMAP;
	switch (prof)
	{
		case EINK_NFC_PROF_DRY_CLEAN:

			memcpy(outputBitmap,prof_dry_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_NORMAL_PERCHLORO_CLEAN:
			memcpy(outputBitmap,prof_normal_perhloro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_MILD_PERCHLORO_CLEAN:
			memcpy(outputBitmap,prof_mild_perchloro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_NORMAL_HYDRO_CLEAN:
			memcpy(outputBitmap,prof_normal_hydro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_MILD_HYDRO_CLEAN:
			memcpy(outputBitmap,prof_mild_hydro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_NOT_DRY_CLEAN:
			memcpy(outputBitmap,prof_not_dry_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_WETCLEANING:
			memcpy(outputBitmap,prof_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_NORM_WETCLEANING:
			memcpy(outputBitmap,prof_norm_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_MILD_WETCLEANING:
			memcpy(outputBitmap,prof_mild_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_VERY_MILD_WETCLEANING:
			memcpy(outputBitmap,prof_very_mild_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_DO_NOT_WET_CLEAN:
			memcpy(outputBitmap,prof_do_not_wet_clean,length_bitmap);
			break;

		default:
			break;
	}

}



/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

void EINK_NFC_SET_WASHING(EINK_NFC_WASHING washing, uint8_t* outputBitmap){
	int length_bitmap=WASHING_BYTE_LENGTH_BITMAP;
	switch (washing)
	{
		case EINK_NFC_WASHING_DO_NOT_WASH:
			memcpy(outputBitmap,washing_do_not_wash,length_bitmap);
			break;
		case EINK_NFC_WASHING_HAND_WASH:
			memcpy(outputBitmap,washing_wash_by_hand,length_bitmap);
			break;

		case EINK_NFC_WASHING_VERY_MILD_30:
			memcpy(outputBitmap,washing_very_mild_30,length_bitmap);
			break;
		case EINK_NFC_WASHING_MILD_30:
			memcpy(outputBitmap,washing_mild_30,length_bitmap);
			break;
		case EINK_NFC_WASHING_30:
			memcpy(outputBitmap,washing_normal_30,length_bitmap);
			break;

		case EINK_NFC_WASHING_VERY_MILD_40:
			memcpy(outputBitmap,washing_very_mild_40,length_bitmap);
			break;
		case EINK_NFC_WASHING_MILD_40:
			memcpy(outputBitmap,washing_mild_40,length_bitmap);
			break;
		case EINK_NFC_WASHING_40:
			memcpy(outputBitmap,washing_normal_40,length_bitmap);
			break;

		case EINK_NFC_WASHING_MILD_60:
			memcpy(outputBitmap,washing_mild_60,length_bitmap);
			break;
		case EINK_NFC_WASHING_60:
			memcpy(outputBitmap,washing_normal_60,length_bitmap);
			break;

		case EINK_NFC_WASHING_70:
			memcpy(outputBitmap,washing_normal_70,length_bitmap);
			break;
		case EINK_NFC_WASHING_95:
			memcpy(outputBitmap,washing_normal_95,length_bitmap);
			break;

		default:
			break;
	}

}

void EINK_NFC_SET_BLEACHING(EINK_NFC_BLEACHING bleaching, uint8_t* outputBitmap){
	int length_bitmap=BLEACHING_BYTE_LENGTH_BITMAP;
	switch (bleaching)
	{
		case EINK_NFC_BLEACHING_DO_NOT_BLEACH:
			memcpy(outputBitmap,bleaching_do_not_bleach,length_bitmap);
			break;
		case EINK_NFC_BLEACHING_ANY_BLEACH:
			memcpy(outputBitmap,bleaching_any_bleach,length_bitmap);
			break;
		case EINK_NFC_BLEACHING_ONLY_OXYGEN:
			memcpy(outputBitmap,bleaching_only_oxygen,length_bitmap);
			break;
		default:
			break;
	}

}

void EINK_NFC_SET_DRYING(EINK_NFC_DRYING drying, uint8_t* outputBitmap){
	int length_bitmap=DRYING_BYTE_LENGTH_BITMAP;
	switch (drying)
	{
		case EINK_NFC_DRYING_DO_NOT_TUMBLE_DRY:
			memcpy(outputBitmap,drying_do_not_tuble_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_TUMBLE_DRYING:
			memcpy(outputBitmap,drying_tumble_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_MILD_DRY:
			memcpy(outputBitmap,drying_mild_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_NORMAL_DRYING:
			memcpy(outputBitmap,drying_normal_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_NATURAL_DRYING:
			memcpy(outputBitmap,drying_natural_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_LINE_DRY:
			memcpy(outputBitmap,drying_drip_line_dry, length_bitmap);
			break;
		case EINK_NFC_DRYING_LINE_DRY:
			memcpy(outputBitmap,drying_line_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_FLAT_DRYING:
			memcpy(outputBitmap,drying_flat_drying,length_bitmap);
			break;
		case EINK_NFC_DRYING_LINE_DRYING_SHADE:
			memcpy(outputBitmap,drying_line_drying_shade,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_FLAT_DRY:
			memcpy(outputBitmap,drying_drip_flat_dry,length_bitmap);
			break;
		case EINK_NFC_DRYING_FLAT_DRY_SHADE:
			memcpy(outputBitmap,drying_flat_dry_shade,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_LINE_DRY_SHADE:
			memcpy(outputBitmap,drying_drip_line_dry_shade,length_bitmap);
			break;
		case EINK_NFC_DRYING_DRIP_FLAT_DRY_SHADE:
			memcpy(outputBitmap,drying_drip_flat_dry_shade,length_bitmap);
			break;
		default:
			break;
	}

}

void EINK_NFC_SET_IRONING(EINK_NFC_IRONING ironing, uint8_t* outputBitmap){
	int length_bitmap=IRONING_BYTE_LENGTH_BITMAP;
	switch (ironing)
	{
		case EINK_NFC_IRONING_DO_NOT_IRON:
			memcpy(outputBitmap,ironing_do_not_iron,length_bitmap);
			break;
		case EINK_NFC_IRONING_LOW_IRON:
			memcpy(outputBitmap,ironing_low_iron,length_bitmap);
			break;
		case EINK_NFC_IRONING_MODE_IRON:
			memcpy(outputBitmap,ironing_mode_iron,length_bitmap);
			break;
		case EINK_NFC_IRONING_HOT_IRON:
			memcpy(outputBitmap,ironing_hot_iron,length_bitmap);
			break;

		default:
			break;
	}

}

void EINK_NFC_SET_PROF(EINK_NFC_PROF prof, uint8_t* outputBitmap){
	int length_bitmap=PROF_BYTE_LENGTH_BITMAP;
	switch (prof)
	{
		case EINK_NFC_PROF_DRY_CLEAN:

			memcpy(outputBitmap,prof_dry_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_NORMAL_PERCHLORO_CLEAN:
			memcpy(outputBitmap,prof_normal_perhloro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_MILD_PERCHLORO_CLEAN:
			memcpy(outputBitmap,prof_mild_perchloro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_NORMAL_HYDRO_CLEAN:
			memcpy(outputBitmap,prof_normal_hydro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_MILD_HYDRO_CLEAN:
			memcpy(outputBitmap,prof_mild_hydro_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_NOT_DRY_CLEAN:
			memcpy(outputBitmap,prof_not_dry_clean,length_bitmap);
			break;
		case EINK_NFC_PROF_WETCLEANING:
			memcpy(outputBitmap,prof_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_NORM_WETCLEANING:
			memcpy(outputBitmap,prof_norm_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_MILD_WETCLEANING:
			memcpy(outputBitmap,prof_mild_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_VERY_MILD_WETCLEANING:
			memcpy(outputBitmap,prof_very_mild_wetcleaning,length_bitmap);
			break;
		case EINK_NFC_PROF_DO_NOT_WET_CLEAN:
			memcpy(outputBitmap,prof_do_not_wet_clean,length_bitmap);
			break;

		default:
			break;
	}

}


