#include <stdio.h>
#include <assert.h>
#include "BatteryCheck.h"

#define BREACH 0
#define NO_BREACH   1

#define E_OK 1
#define E_NOT_OK 0

int batteryParamInRange(float param, float param_min, float param_max)
{
 int result = NO_BREACH;
 if (param < param_min || param > param_max)
 {
  result = BREACH;
 }
 return result;
}

int chargeRateRangeCheck(float param, float chargeRate_max)
{
  int result = NO_BREACH;
  if (param > chargeRate_max)
  {
    result = BREACH;
  }
 return result;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
 int tempCheckResult = 0, socCheckResult = 0, chargeRateCheckResult = 0, finalResult =0;
 tempCheckResult = batteryParamInRange(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX); 
 socCheckResult = batteryParamInRange(soc, SOC_MIN, SOC_MAX); 
 chargeRateCheckResult = chargeRateRangeCheck(chargeRate, CHARGERATE_MAX);
 printf("temp = %d socc = %d  charge = %d\n",tempCheckResult,socCheckResult,chargeRateCheckResult);
 finalResult = tempCheckResult && socCheckResult && chargeRateCheckResult;
 checkFinalResult(finalResult);
 return finalResult;
  
}

checkFinalResult(int result)
{
     if(result)
    {
        assert(result == 1);
        printf("Battery is ok\n\n");
    }
    else
    {
        assert(result == 0);
        printf("Battery was not ok due to above parameters:");
    }
}

int main() {
  batteryIsOk(25, 70, 0.7);
  batteryIsOk(50, 85, 0);
}
