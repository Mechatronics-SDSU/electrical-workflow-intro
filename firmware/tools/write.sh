# Connor Larmer
# 2023-09-04
# Script to write hex file to an
# ATMEGA328p mcu using minipro. Why minipro?
# Because the only programmer I have is a
# TL866II+ and minipro is what works.
# The code will probably compile and flash
# with any other tool, this has just been 
# tailored to what I have to use.
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo "Attempting to write program to ATMEGA328P@DIP28"
echo " Using ICSP (oh boy)"
sudo minipro -p"ATMEGA328P@DIP28" -c config -w minipro_config.cfg -E -i
sudo minipro -p"ATMEGA328P@DIP28" -c code -w $1 -e -i
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
