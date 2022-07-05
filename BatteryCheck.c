#include <stdio.h>
#include <assert.h>
#include "BatteryCheck.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
 return(!BATTERY_PARAM_NOTINRANGE(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX) && !BATTERY_PARAM_NOTINRANGE(soc, SOC_MIN, SOC_MAX) && !CHARGERATE_NOTINRANGE(chargeRate, CHARGERATE_MAX));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
