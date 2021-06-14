#!/bin/sh

# sensors | grep Core | awk '{print substr($3, 2, length($3)-5)}' | tr "\\n" " " | sed 's/ /°C  /g' | sed 's/  $//'
SEP1="["
SEP2="] "

dwm_sensors () {
  # SENSORS=$(sensors | grep Core | awk '{print substr($3, 2, length($3)-5)}' | tr "\\n" " " | sed 's/ /°C  /g' | sed 's/  $//')
  SENSORS=$(sensors | grep Package | awk '{print $4}' )

    printf "%s" "$SEP1"
    printf " %s" "$SENSORS"
    printf "%s\n" "$SEP2"
    export __DWM_BAR_CPUTEMP__="${SEP1} ${SENSORS}${SEP2}"
}

dwm_sensors
