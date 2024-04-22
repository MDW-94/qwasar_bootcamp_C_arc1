# blah:
# 	cc blah.c -o blah

# Running make in this directory -
# Since there is no target supplied as an argument 
# To the make command, the first target is run
# In this case, there's only one target (blah)
# The first time you run this, blah will be created
# The second time, you'll see make: 'blah' is up to date
# That's because the blah file already exists


# However, if we modify blah.c and then run make, nothing get compiled

# WE SOLVE THIS BY ADDING THE PREREQUISITE:

blah: blah.c
	cc blah.c -o blah