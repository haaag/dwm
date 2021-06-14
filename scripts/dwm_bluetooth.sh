#!/bin/sh

SEP1="["
SEP2="] "

dwm_bluetooth () {
	STATUS=$(dwm_rofi_bluetooth.sh --status)
        printf "%s" "$SEP1"

	if [ "$STATUS" = "Off" ]; then
		printf " %s" "$STATUS"
	else
		printf "%s" "$STATUS"
	fi
	printf "%s\n" "$SEP2"
}

dwm_bluetooth
