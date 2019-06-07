ERROR #1 You picked channel of Oscilloscope, that doesn't exist
ERROR #2 You picked channel of Generator, that doesn't exist
ERROR #3 You picked channel of Oscilloscope, that is already busy
ERROR #4 You picked channel of Generator, that is already busy

Try to pick another channel

ERROR #5 You can't read the Peak to Peak and RMS Voltage, because at least one period of the sinusoid is't visible
ERROR #6 You can't read the Peak to Peak and RMS Voltage, because amplitude of the sinusoid is't visible

Change seconds and voltage scale

ERROR #7 You tried to read signal from channel, that isn't connected to anything

First, you must connect Generator\Oscilloscope to Oscilloscope\Generator with this channel

ERROR #8 You tried to create object from file, that doesn't exist	
ERROR #9 Couldn't open the file ___________________________.txt
ERROR #10 You tried to close file __________________________.txt, that doesn't exist

Check your files, they must be named:
	load_analog_oscilloscope.txt
	load_digital_oscilloscope.txt
	load_generator.txt
	load_researcher.txt

ERROR #11 ____________________.txt is broken

Check you files, they must hve this structure:
	Analog Oscilloscope: amount_of_channels voltage_divisions seconds_divisions manufacturer device_model  year_of_issue    amount_of_beams
			     natural_number>0   natural_number>0  natural_number>0      smth         smth      natural_number>0 natural_number>0

	Digital Oscilloscope: amount_of_channels voltage_divisions seconds_divisions manufacturer device_model  year_of_issue    memory_depth
			     natural_number>0    natural_number>0   natural_number>0    smth          smth     natural_number>0 natural_number>0

	Generator: amount_of_channels manufacturer device_model  year_of_issue    max_output_frequency
		   natural_number>0    smth           smth      natural_number>0    natural_number>0

	Researcher: research_position name surname      age
			smth          smth   smth  natural_number>0 

For working of the program important are only amount_of_channels voltage_divisions seconds_divisions max_output_frequency

ERROR #12 You tried to swap negative element of list, that of course doesnt exist
	  You tried to swap element beyond the list

Element must be from 0 to (size of list - 1)

ERROR #13 Object isn't in a list

Error of metod indexOf. it can't return index, becouse this object isn't in a list