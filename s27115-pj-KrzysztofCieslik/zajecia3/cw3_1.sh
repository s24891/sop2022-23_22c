#!/bin/bash

color_text() {
  local color="$1"
  local text="$2"
  case "$color" in
    "black")
      echo -e "\e[30m$text\e[0m"
      ;;
    "red")
      echo -e "\e[31m$text\e[0m"
      ;;
    "green")
      echo -e "\e[32m$text\e[0m"
      ;;
    "yellow")
      echo -e "\e[33m$text\e[0m"
      ;;
    "blue")
      echo -e "\e[34m$text\e[0m"
      ;;
    "magenta")
      echo -e "\e[35m$text\e[0m"
      ;;
    "cyan")
      echo -e "\e[36m$text\e[0m"
      ;;
    "white")
      echo -e "\e[37m$text\e[0m"
      ;;
    *)
      echo "Unknown color: $color"
      ;;
  esac
}
color_text "$1" "$2"
