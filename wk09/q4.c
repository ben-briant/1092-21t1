fopen(FilePath, "r");
open(FilePath, O_RDONLY);

fopen(FilePath, "a");
open(FilePath, O_WRONLY|O_APPEND|O_CREAT, 0666);

fopen(FilePath, "w");
open(FilePath, O_WRONLY|O_TRUNC|O_CREAT, 0666);

fopen(FilePath, "r+");
open(FilePath, );

fopen(FilePath, "w+");
open(FilePath, );


fopen == FILE *
open == file descriptor (int)
