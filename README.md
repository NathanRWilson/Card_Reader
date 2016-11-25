# Card_Reader
Card Reader software for Student Government office

The software is meant to be used with a magnetic strip reader and a U of M Mcard.
Basically the Mcard inputs into the standard input a string of characters like this:
asdllslkdgihi19801329-45--0^SMITH/alsiwheo82390402357023

The code breaks this down into just the name of the user, namely the part between '^' and '/', records the time
and writes the time and name of the user to a CSV file named the current date in the form 'mm-dd-yyyy', if the file already exits
it just appends the data to the end.
