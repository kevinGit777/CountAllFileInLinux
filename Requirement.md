# PA02
This program set contain two program, one count all files, directory and size, other display the correspond line to the option argument.

	The count command can take absolute path, relative path, and ~ expansion which lead to home file. Only one argument of the file name is acceptable. 
  It output three line, one shows how many file is under the file given, one shows how many bytes it total occupied, one show how many directory under the file given.
	The display command has three option, -f, -b, -d. -f display line contain word “file”; -b display the line contain “bytes”, -d display line contain “directories”.
	Put filecnt and filedisp under home directory, ./filecut ‘your file’ will run this command, and ./filedisp -option <input. Will run this command.
