# Connor Larmer
# 2023-09-04
# Flash fuse bits to ATMEGA328P
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo " Attempting to flash fuse values to ATMEGA328P@DIP28"
sudo minipro -p"ATMEGA328P@DIP28" -c config -w minipro_config.cfg
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
