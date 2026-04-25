# 1d) Extra credit: why are the following two lines identical?

# myflags &= ~(option4 | option5); // turn options 4 and 5 off
# myflags &= ~option4 & ~option5; // turn options 4 and 5 off

#  option4 | option5 will yield true for the bit flags. ~ then turns off these true bit values.

# ~option4 turns off the bit value and ~option5 does as well. & then combines the turned off bit flags

# Thus the same outcome is yielded in both cases

# This is De Morgan's law. De Morgan’s laws says that if we distribute a NOT, we need to flip ORs and ANDs to the other. So ~(option4 | option5) becomes ~option4 & ~option5.
