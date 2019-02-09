
#ifndef _ADC_H
#define _ADC_H


#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Data Types Definitions
*/

/**
 *  result size of an A/D conversion
 */

typedef uint16_t adc_result_t;

/**
 *  result type of a Double ADC conversion
 */
typedef struct
{
    adc_result_t adcResult1;
    adc_result_t adcResult2;
} adc_sync_double_result_t;

/** ADC Channel Definition
 @Description
   This routine defines the channels that are available for the module to use.
 */

typedef enum
{
    channel_FVR =  0xF
} adc_channel_t;


/**
  @Description
    This routine initializes the Initializes the ADC.
    This routine must be called before any other ADC routine is called.
    This routine should only be called once during system initialization.
*/
void ADC_Initialize(void);

/**
  @Description
    This routine is used to select desired channel for conversion.
    available
*/
void ADC_SelectChannel(adc_channel_t channel);

/**
  @Description
    This routine is used to start conversion of desired channel.
*/
void ADC_StartConversion();

/**
  @Description
    This routine is used to determine if conversion is completed.
    When conversion is complete routine returns true. It returns false otherwise.

 */
bool ADC_IsConversionDone();

/**
  @Description
    This routine is used to get the analog to digital converted value. This
    routine gets converted values from the channel specified.
 */
adc_result_t ADC_GetConversionResult(void);


#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif	//_ADC_H
/**
 End of File
*/

