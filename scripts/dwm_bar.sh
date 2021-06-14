#!/bin/sh

# A modular status bar for dwm
# Joe Standring <git@joestandring.com>
# GNU GPLv3

# Dependencies: xorg-xsetroot

# Import functions with "$include /route/to/module"
# It is recommended that you place functions in the subdirectory ./bar-functions and use: . "$DIR/bar-functions/dwm_example.sh"

# Store the directory the script is running from
LOC=$(readlink -f "$0")
DIR=$(dirname "$LOC")

# Change the appearance of the module identifier. if this is set to "unicode", then symbols will be used as identifiers instead of text. E.g. [📪 0] instead of [MAIL 0].
# Requires a font with adequate unicode character support
export IDENTIFIER="unicode"

# Change the charachter(s) used to seperate modules. If two are used, they will be placed at the start and end.
export SEP1="["
export SEP2="] "

# Import the modules
# . "$DIR/bar-functions/dwm_transmission.sh"
# . "$DIR/bar-functions/dwm_mpc.sh"
# . "$DIR/dwm_networkmanager.sh"
# . "$DIR/dwm_alsa.sh"
# . "$DIR/dwm_backlight.sh"
# . "$DIR/dwm_weather.sh"
# . "$DIR/dwm_vpn.sh"
. "$DIR/dwm_battery.sh"
. "$DIR/dwm_mail.sh"
. "$DIR/dwm_pulse.sh"
. "$DIR/dwm_date.sh"
. "$DIR/dwm_bluetooth.sh"
. "$DIR/dwm_temppercore.sh"
. "$DIR/dwm_cpu.sh"
. "$DIR/dwm_weather.sh"
. "$DIR/dwm_nettraf.sh"

parallelize() {
    while true
    do
        printf "Running parallel processes\n"
	dwm_weather.sh &
        sleep 10
    done
}
parallelize &

# Update dwm status bar every second
while true
do
    # Append results of each func one by one to a string
    dispstr=""
    dispstr="$dispstr$(dwm_cpu.sh)"
    dispstr="$dispstr$(dwm_nettraf.sh)"
    dispstr="$dispstr$(dwm_temppercore.sh)"
    dispstr="$dispstr$(dwm_mail)"
    dispstr="$dispstr$(dwm_bluetooth)"
    # dispstr="$dispstr${__DWM_BAR_CPUTEMP__}"
    dispstr="$dispstr$(dwm_battery)"
    dispstr="$dispstr${__DWM_BAR_WEATHER__}"
    dispstr="$dispstr$(dwm_date)"
    dispstr="$dispstr$(dwm_pulse)"
    # dispstr="$dispstr$(dwm_mpc)"
    # dispstr="$dispstr$(dwm_backlight)"
    # dispstr="$dispstr${__DWM_BAR_WEATHER__}"
    # dispstr="$dispstr$(dwm_vpn)"

    xsetroot -name "$dispstr"
    sleep 1
done
