# Connor Larmer 
# 2023-09-04
# Script to quicken compilation process
# for atmega328p fw (if only there was
# an already existing tool to *make* all
# of this a lot easier).
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo "Building and stripping compiled program binary for: " $1
echo "Compiling program..."
avr-gcc -mmcu=atmega328 $1
echo "Building hex file..."
avr-objcopy -O ihex -j.text -j.data a.out out.hex
echo "Cleaning up..."
rm a.out
echo "Done."
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
