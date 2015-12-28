#include <stdio.h>
#include <unistd.h>

main()
{    
	FILE *ifp, *ofp;
    char inputFilename [80];
    char outputFilename[80];
	char line [256]; 
	char linec [256]; // copy of line
    char c;
    
    printf("Enter input filename: ");
    scanf("%s", inputFilename);
    printf("Enter output filename: ");
    scanf("%s", outputFilename);

	
	// open input file
	printf("Opening input file\n");
	ifp = fopen(inputFilename, "r");
	// make sure its valid
	if (ifp == NULL)
	{
		printf("Invalid input file; exiting...\n");
		exit(1);
	}


	// open output file
	printf("Opening output file\n");
	ofp = fopen(outputFilename, "w");
	// make sure its valid
	if (ofp == NULL)
		exit(1);
	
	// copy file content
	printf("Writing to output file\n");
	printf("File text: ");
	while ( fgets ( line, sizeof line, ifp ) != NULL )
	{
		fputs (line, stdout);
		strcpy(linec, line);
		fprintf (ofp, linec);
	}
	
	// delete new file
	printf("Deleting new file\n");
	unlink(outputFilename);
	
	printf("Done\n");
}
