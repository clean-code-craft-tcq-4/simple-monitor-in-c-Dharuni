#include <stdio.h>
#include <assert.h>
#include "BatteryCheck.h"

#define BREACH_HIGH 2
#define BREACH_LOW  1
#define NO_BREACH   0

#define E_OK 1
#define E_NOT_OK 0

int batteryParamInRange(float param, float param_min, float param_max)
{
 int result = NO_BREACH;
 if (param < param_min)
 {
   result = BREACH_LOW;
 }
 else if (param > param_max)
 {
  result = BREACH_HIGH;
 }
 return result;
}

int chargeRateRangeCheck(float param, float chargeRate_max)
{
  int result = NO_BREACH;
  if (param > chargeRate_max)
  {
    result = BREACH_HIGH;
  }
 return result;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 int tempCheckResult, socCheckResult, chargeRateCheckResult, finalResult;
 tempCheckResult = batteryParamInRange(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX); 
 socCheckResult = batteryParamInRange(soc, SOC_MIN, SOC_MAX); 
 chargeRateCheckResult = chargeRateRangeCheck(chargeRate, CHARGERATE_MAX);
 printf("temp = %d socc = %d  charge = %d\n",tempCheckResult,socCheckResult,chargeRateCheckResult);
 finalResult = tempCheckResult && socCheckResult && chargeRateCheckResult;
 if(finalResult)
 {
  return E_OK;
 }
 else
 {
  printf("Battery was not ok due to above reasons set:");
  return E_NOT_OK;
 }
  
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
