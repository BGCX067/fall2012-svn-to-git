#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{    
    int iFile, oFile;
    char* text[256];
    char input_filename[] = "in.file";
    char output_filename[] = "out.file";
    
    // open input file
    iFile = open(input_filename, O_RDWR);
    if (iFile == -1) {
        perror("Input file cannot be opened");
        return 0;
    }
    
    
    // open output file
    oFile = open(output_filename, O_CREAT, S_IRWXU);
    oFile = open(output_filename, O_WRONLY);
    if (oFile == -1) {
        perror("Output file cannot be opened");
        return 0;
    }
    
    // read input file and write output file
	ssize_t bytes_read = read(iFile, text, sizeof(text));
	write(oFile, text, bytes_read);
	
	// write output to std out
	write(0, "\nFile text: ", 12);
	write(0, text, bytes_read);
	write(0, "\n", 1);
	
	// close files
	close(input_filename);
	close(output_filename);
}
