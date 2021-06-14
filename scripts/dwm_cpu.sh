#!/bin/sh

dwm_cpu () {
  CPU=$(top -bn1 | grep Cpu | awk '{print $2}')
  printf "%s" "$SEP1"
  printf " %s%%" "$CPU"
  printf "%s\n" "$SEP2"
}

dwm_cpu
